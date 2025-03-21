#include "RuntimeFBXLoader.h"
#include "FBXLoader.h"
#include "Engine/StaticMesh.h"
#include "Rendering/NaniteResources.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY_STATIC(RuntimeFBXLoaderLog, Log, All);

void FRuntimeFBXLoaderModule::StartupModule()
{
  UE_LOG(RuntimeFBXLoaderLog, Warning, TEXT("RuntimeFBXLoader module starting..."));

  // Verificar si la DLL de Assimp se carga correctamente
  FString AssimpDLLPath = FPaths::ProjectDir() / TEXT("Binaries/Win64/assimp-vc143-mt.dll");
  if (!FPaths::FileExists(AssimpDLLPath))
  {
    UE_LOG(RuntimeFBXLoaderLog, Error, TEXT("Assimp DLL not found at %s"), *AssimpDLLPath);
  }
  else
  {
    void* AssimpDLLHandle = FPlatformProcess::GetDllHandle(*AssimpDLLPath);
    if (!AssimpDLLHandle)
    {
      UE_LOG(RuntimeFBXLoaderLog, Error, TEXT("Failed to load Assimp DLL!"));
    }
    else
    {
      UE_LOG(RuntimeFBXLoaderLog, Warning, TEXT("Assimp DLL loaded successfully."));
    }
  }

  UE_LOG(RuntimeFBXLoaderLog, Warning, TEXT("RuntimeFBXLoader module initialized successfully."));
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

  return CreateStaticMeshFromAssimp(Scene->mMeshes[0]);
}

UStaticMesh* UFBXLoader::CreateStaticMeshFromAssimp(aiMesh* Mesh)
{
  if (!Mesh)
  {
    UE_LOG(RuntimeFBXLoaderLog, Warning, TEXT("Mesh inválida."));
    return nullptr;
  }

  UStaticMesh* NewMesh = NewObject<UStaticMesh>();
  if (!NewMesh)
  {
    UE_LOG(RuntimeFBXLoaderLog, Error, TEXT("No se pudo crear el StaticMesh."));
    return nullptr;
  }

  // Crear RenderData usando MakeUnique para usar TUniquePtr
  NewMesh->SetRenderData(MakeUnique<FStaticMeshRenderData>());
  FStaticMeshRenderData* RenderData = NewMesh->GetRenderData();

  // Crear nuevo recurso LOD
  FStaticMeshLODResources* LOD = new FStaticMeshLODResources();
  RenderData->LODResources.Add(LOD);

  // Inicializar el buffer de posición de vértices
  LOD->VertexBuffers.PositionVertexBuffer.Init(Mesh->mNumVertices, false);
  FVector3f* VertexData = reinterpret_cast<FVector3f*>(LOD->VertexBuffers.PositionVertexBuffer.GetVertexData());

  for (uint32 i = 0; i < Mesh->mNumVertices; i++)
  {
    VertexData[i] = FVector3f(Mesh->mVertices[i].x, Mesh->mVertices[i].y, Mesh->mVertices[i].z);
  }

  // Inicializar el buffer de índices
  TArray<uint32> Indices;
  for (unsigned int i = 0; i < Mesh->mNumFaces; i++)
  {
    aiFace& Face = Mesh->mFaces[i];
    if (Face.mNumIndices == 3) // Solo triángulos
    {
      Indices.Add(Face.mIndices[0]);
      Indices.Add(Face.mIndices[1]);
      Indices.Add(Face.mIndices[2]);
    }
  }

  LOD->IndexBuffer.SetIndices(Indices, EIndexBufferStride::AutoDetect);

  // Activar Nanite (si es necesario)
  NewMesh->NaniteSettings.bEnabled = true;

  // Inicializar los recursos
  LOD->VertexBuffers.PositionVertexBuffer.InitResource();
  LOD->IndexBuffer.InitResource();

  // Crear el body setup y marcar como modificado
  NewMesh->CreateBodySetup();
  NewMesh->MarkPackageDirty();

  return NewMesh;
}

UTexture2D* UFBXLoader::LoadTextureFromPath(const FString& Path)
{
  return Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), nullptr, *Path));
}

UMaterialInstanceDynamic* UFBXLoader::CreateMaterial(UTexture2D* Texture)
{
  if (!Texture)
  {
    UE_LOG(RuntimeFBXLoaderLog, Warning, TEXT("No se encontró la textura."));
    return nullptr;
  }

  UMaterialInterface* BaseMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/Materials/BaseMaterial"));
  if (!BaseMaterial)
  {
    UE_LOG(RuntimeFBXLoaderLog, Error, TEXT("No se encontró el material base."));
    return nullptr;
  }

  UMaterialInstanceDynamic* MatInstance = UMaterialInstanceDynamic::Create(BaseMaterial, nullptr);
  MatInstance->SetTextureParameterValue("BaseColor", Texture);
  return MatInstance;
}
