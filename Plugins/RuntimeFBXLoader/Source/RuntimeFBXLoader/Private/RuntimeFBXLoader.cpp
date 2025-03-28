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

DEFINE_LOG_CATEGORY(RuntimeFBXLoaderLog);

void FRuntimeFBXLoaderModule::StartupModule()
{
  UE_LOG(RuntimeFBXLoaderLog, Warning, TEXT("RuntimeFBXLoader module starting..."));

  // Cargar DLL de Assimp
  FString AssimpDLLPath = FPaths::Combine(
    FPaths::ProjectPluginsDir(),
    TEXT("RuntimeFBXLoader/ThirdParty/assimp/bin/x64/assimp-vc143-mt.dll")
  );

  if (FPaths::FileExists(AssimpDLLPath))
  {
    void* AssimpDLLHandle = FPlatformProcess::GetDllHandle(*AssimpDLLPath);
    if (!AssimpDLLHandle)
    {
      UE_LOG(RuntimeFBXLoaderLog, Error, TEXT("Failed to load Assimp DLL!"));
    }
  }
}

void FRuntimeFBXLoaderModule::ShutdownModule()
{
  UE_LOG(RuntimeFBXLoaderLog, Warning, TEXT("RuntimeFBXLoader module shutting down..."));
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
    return nullptr;
  }

  UStaticMesh* StaticMesh = CreateStaticMeshFromAssimp(Scene->mMeshes[0], Scene);
  ProcessMaterials(Scene, StaticMesh);

  return StaticMesh;
}

UStaticMesh* UFBXLoader::CreateStaticMeshFromAssimp(aiMesh* Mesh, const aiScene* Scene)
{
  if (!Mesh) return nullptr;

  // Crear objeto StaticMesh
  FName MeshName = MakeUniqueObjectName(GetTransientPackage(), UStaticMesh::StaticClass(), TEXT("RuntimeMesh"));
  UStaticMesh* StaticMesh = NewObject<UStaticMesh>(GetTransientPackage(), MeshName, RF_Transient | RF_Public);

  // Configurar LOD
  StaticMesh->SetNumSourceModels(1);
  FStaticMeshSourceModel& SourceModel = StaticMesh->GetSourceModel(0);

  // Crear y configurar MeshDescription directamente
  FMeshDescription* MeshDescription = StaticMesh->CreateMeshDescription(0);
  if (!MeshDescription)
  {
    UE_LOG(RuntimeFBXLoaderLog, Error, TEXT("Failed to create MeshDescription"));
    return nullptr;
  }

  FStaticMeshAttributes Attributes(*MeshDescription);
  Attributes.Register();

  // Añadir vértices
  TArray<FVertexID> VertexIDs;
  VertexIDs.Reserve(Mesh->mNumVertices);
  for (uint32 i = 0; i < Mesh->mNumVertices; i++)
  {
    FVertexID VertexID = MeshDescription->CreateVertex();
    VertexIDs.Add(VertexID);
    Attributes.GetVertexPositions()[VertexID] = FVector3f(Mesh->mVertices[i].x, Mesh->mVertices[i].y, Mesh->mVertices[i].z);
  }

  // Añadir polígonos
  FPolygonGroupID PolygonGroupID = MeshDescription->CreatePolygonGroup();

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

        // Configurar normales si existen
        if (Mesh->HasNormals())
        {
          Attributes.GetVertexInstanceNormals()[InstanceID] =
            FVector3f(Mesh->mNormals[Face.mIndices[j]].x,
              Mesh->mNormals[Face.mIndices[j]].y,
              Mesh->mNormals[Face.mIndices[j]].z);
        }

        // Configurar UVs si existen
        if (Mesh->HasTextureCoords(0))
        {
          Attributes.GetVertexInstanceUVs().Set(InstanceID, 0,
            FVector2f(
              static_cast<float>(Mesh->mTextureCoords[0][Face.mIndices[j]].x),
              static_cast<float>(Mesh->mTextureCoords[0][Face.mIndices[j]].y)
            ));
        }
      }
      MeshDescription->CreatePolygon(PolygonGroupID, VertexInstanceIDs);
    }
  }

  // Confirmar cambios en el MeshDescription
  StaticMesh->CommitMeshDescription(0);

  // Configurar opciones de construcción
  SourceModel.BuildSettings.bRecomputeNormals = !Mesh->HasNormals();
  SourceModel.BuildSettings.bRecomputeTangents = true;
  SourceModel.BuildSettings.bGenerateLightmapUVs = true;
  SourceModel.BuildSettings.bBuildReversedIndexBuffer = false;

  // Construir la malla estática
  StaticMesh->Build(false);
  StaticMesh->CreateBodySetup();
  StaticMesh->GetBodySetup()->CollisionTraceFlag = ECollisionTraceFlag::CTF_UseDefault;
  StaticMesh->PostEditChange();

  return StaticMesh;
}

void UFBXLoader::ProcessMaterials(const aiScene* Scene, UStaticMesh* StaticMesh)
{
  if (!Scene || !StaticMesh) return;

  // Añadir materiales básicos
  for (uint32 i = 0; i < Scene->mNumMaterials; i++)
  {
    StaticMesh->GetStaticMaterials().Add(FStaticMaterial());
  }
}

UTexture2D* UFBXLoader::LoadTextureFromPath(const FString& Path)
{
  if (Path.IsEmpty()) return nullptr;
  return Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *Path));
}

UMaterialInstanceDynamic* UFBXLoader::CreateMaterial(UTexture2D* Texture)
{
  if (!Texture) return nullptr;

  UMaterial* BaseMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial"));
  if (!BaseMaterial) return nullptr;

  UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(BaseMaterial, nullptr);
  DynamicMaterial->SetTextureParameterValue("BaseColor", Texture);

  return DynamicMaterial;
}
