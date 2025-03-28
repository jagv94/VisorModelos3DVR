#include "RuntimeFBXLoader.h"
#include "FBXLoader.h"
#include "Engine/StaticMesh.h"
#include "Modules/ModuleManager.h"
#include "Engine/Texture.h"
#include "Engine/Texture2D.h"
#include "TextureCompiler.h"
#include "TextureResource.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Materials/Material.h"
#include "StaticMeshAttributes.h"
#include "StaticMeshOperations.h"
#include "StaticMeshDescription.h"
#include "PhysicsEngine/BodySetup.h"
#include "Misc/App.h"
#include "Async/Async.h"

DEFINE_LOG_CATEGORY(RuntimeFBXLoaderLog);

void FRuntimeFBXLoaderModule::StartupModule()
{
  UE_LOG(RuntimeFBXLoaderLog, Log, TEXT("RuntimeFBXLoader module started"));
}

void FRuntimeFBXLoaderModule::ShutdownModule()
{
  UE_LOG(RuntimeFBXLoaderLog, Log, TEXT("RuntimeFBXLoader module shutdown"));
}

IMPLEMENT_MODULE(FRuntimeFBXLoaderModule, RuntimeFBXLoader)

UFBXLoader* UFBXLoader::GetFBXLoaderInstance()
{
  return NewObject<UFBXLoader>();
}

UStaticMesh* UFBXLoader::LoadFBX(const FString& FilePath)
{
  const aiScene* Scene = FBXLoader::LoadFBX(FilePath);
  if (!Scene || !Scene->HasMeshes())
  {
    UE_LOG(RuntimeFBXLoaderLog, Error, TEXT("Failed to load FBX file or no meshes found"));
    return nullptr;
  }

  // Create combined static mesh
  FName MeshName = MakeUniqueObjectName(GetTransientPackage(), UStaticMesh::StaticClass(), TEXT("RuntimeMesh"));
  UStaticMesh* StaticMesh = NewObject<UStaticMesh>(GetTransientPackage(), MeshName, RF_Transient | RF_Public);
  StaticMesh->SetNumSourceModels(1);
  FStaticMeshSourceModel& SourceModel = StaticMesh->GetSourceModel(0);

  FMeshDescription* MeshDescription = StaticMesh->CreateMeshDescription(0);
  FStaticMeshAttributes Attributes(*MeshDescription);
  Attributes.Register();

  TArray<FStaticMaterial> StaticMaterials;
  TArray<FPolygonGroupID> PolygonGroups;

  // Process all meshes
  for (uint32 MeshIndex = 0; MeshIndex < Scene->mNumMeshes; MeshIndex++)
  {
    const aiMesh* Mesh = Scene->mMeshes[MeshIndex];
    if (!Mesh) continue;

    // Add vertices
    TArray<FVertexID> VertexIDs;
    VertexIDs.Reserve(Mesh->mNumVertices);
    for (uint32 i = 0; i < Mesh->mNumVertices; i++)
    {
      FVertexID VertexID = MeshDescription->CreateVertex();
      VertexIDs.Add(VertexID);
      Attributes.GetVertexPositions()[VertexID] =
        FVector3f(Mesh->mVertices[i].x, Mesh->mVertices[i].y, Mesh->mVertices[i].z);
    }

    // Create polygon group for this mesh
    FPolygonGroupID PolygonGroupID = MeshDescription->CreatePolygonGroup();
    PolygonGroups.Add(PolygonGroupID);

    // Add faces
    for (uint32 i = 0; i < Mesh->mNumFaces; i++)
    {
      const aiFace& Face = Mesh->mFaces[i];
      if (Face.mNumIndices == 3)
      {
        TArray<FVertexInstanceID> VertexInstanceIDs;
        for (int j = 0; j < 3; j++)
        {
          FVertexInstanceID InstanceID = MeshDescription->CreateVertexInstance(VertexIDs[Face.mIndices[j]]);
          VertexInstanceIDs.Add(InstanceID);

          if (Mesh->HasNormals())
          {
            Attributes.GetVertexInstanceNormals()[InstanceID] =
              FVector3f(Mesh->mNormals[Face.mIndices[j]].x,
                Mesh->mNormals[Face.mIndices[j]].y,
                Mesh->mNormals[Face.mIndices[j]].z);
          }

          if (Mesh->HasTextureCoords(0))
          {
            Attributes.GetVertexInstanceUVs().Set(InstanceID, 0,
              FVector2f(Mesh->mTextureCoords[0][Face.mIndices[j]].x,
                1.0f - Mesh->mTextureCoords[0][Face.mIndices[j]].y)); // Flip V coordinate
          }

          if (Mesh->HasTangentsAndBitangents())
          {
            Attributes.GetVertexInstanceTangents()[InstanceID] =
              FVector3f(Mesh->mTangents[Face.mIndices[j]].x,
                Mesh->mTangents[Face.mIndices[j]].y,
                Mesh->mTangents[Face.mIndices[j]].z);
          }
        }
        MeshDescription->CreatePolygon(PolygonGroupID, VertexInstanceIDs);
      }
    }
  }

  StaticMesh->CommitMeshDescription(0);

  // Configure build settings
  SourceModel.BuildSettings.bRecomputeNormals = false;
  SourceModel.BuildSettings.bRecomputeTangents = false;
  SourceModel.BuildSettings.bGenerateLightmapUVs = true;
  SourceModel.BuildSettings.bBuildReversedIndexBuffer = false;

  // Process materials
  ProcessMaterials(Scene, StaticMesh);

  // Build mesh
  StaticMesh->Build(false);
  StaticMesh->CreateBodySetup();
  StaticMesh->GetBodySetup()->CollisionTraceFlag = ECollisionTraceFlag::CTF_UseDefault;
  StaticMesh->PostEditChange();

  return StaticMesh;
}

void UFBXLoader::ProcessMaterials(const aiScene* Scene, UStaticMesh* StaticMesh)
{
  if (!Scene || !StaticMesh) return;

  StaticMesh->GetStaticMaterials().Empty();

  for (uint32 i = 0; i < Scene->mNumMaterials; i++)
  {
    const aiMaterial* Material = Scene->mMaterials[i];
    UMaterialInstanceDynamic* DynamicMaterial = nullptr;

    // Try to load diffuse texture
    aiString TexturePath;
    if (Material->GetTexture(aiTextureType_DIFFUSE, 0, &TexturePath) == AI_SUCCESS)
    {
      FString TextureFilePath = FPaths::GetCleanFilename(UTF8_TO_TCHAR(TexturePath.C_Str()));
      FString BasePath = FPaths::GetPath(TextureFilePath);

      // Search in common texture paths
      TArray<FString> TextureSearchPaths = {
          FPaths::ProjectContentDir() + "Textures/",
          FPaths::ProjectContentDir() + BasePath + "/",
          FPaths::ProjectContentDir()
      };

      UTexture2D* Texture = nullptr;
      for (const FString& SearchPath : TextureSearchPaths)
      {
        FString FullPath = SearchPath + TextureFilePath;
        Texture = LoadTextureFromPath(FullPath);
        if (Texture) break;
      }

      DynamicMaterial = CreateMaterial(Texture);
    }

    if (!DynamicMaterial)
    {
      // Default material if no texture found
      UMaterial* BaseMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));
      if (BaseMaterial)
      {
        DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, nullptr);
        DynamicMaterial->SetVectorParameterValue("BaseColor", FLinearColor::Gray);
      }
    }

    if (DynamicMaterial)
    {
      FStaticMaterial StaticMaterial(DynamicMaterial);
      StaticMesh->GetStaticMaterials().Add(StaticMaterial);
    }
  }
}

UTexture2D* UFBXLoader::LoadTextureFromPath(const FString& Path)
{
  if (Path.IsEmpty()) return nullptr;

  UTexture2D* Texture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *Path));
  if (!Texture)
  {
    // Try loading with different extensions
    FString BaseFilename = FPaths::GetBaseFilename(Path);
    TArray<FString> Extensions = { ".png", ".jpg", ".jpeg", ".tga", ".bmp" };

    for (const FString& Ext : Extensions)
    {
      Texture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *(BaseFilename + Ext)));
      if (Texture) break;
    }
  }

  return Texture;
}

UMaterialInstanceDynamic* UFBXLoader::CreateMaterial(UTexture2D* Texture)
{
  UMaterial* BaseMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));
  if (!BaseMaterial)
  {
    UE_LOG(RuntimeFBXLoaderLog, Error, TEXT("Failed to load base material"));
    return nullptr;
  }

  UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, nullptr);
  if (Texture)
  {
    DynamicMaterial->SetTextureParameterValue("BaseColor", Texture);
  }
  else
  {
    DynamicMaterial->SetVectorParameterValue("BaseColor", FLinearColor::White);
  }

  return DynamicMaterial;
}
