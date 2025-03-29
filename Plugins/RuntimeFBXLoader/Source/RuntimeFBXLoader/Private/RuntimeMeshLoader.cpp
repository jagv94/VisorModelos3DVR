#include "RuntimeMeshLoader.h"
#include "Materials/MaterialInstanceDynamic.h"

FRuntimeMeshLoader::FRuntimeMeshLoader() {}
FRuntimeMeshLoader::~FRuntimeMeshLoader() {}

bool FRuntimeMeshLoader::LoadMeshFromFile(const FString& FilePath, UProceduralMeshComponent* MeshComponent, int32 LODIndex)
{
  if (!MeshComponent) return false;

  Assimp::Importer Importer;
  const aiScene* Scene = Importer.ReadFile(TCHAR_TO_UTF8(*FilePath),
    aiProcess_Triangulate |
    aiProcess_CalcTangentSpace |
    aiProcess_GenNormals |
    aiProcess_OptimizeMeshes);

  if (!Scene || Scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !Scene->mRootNode)
  {
    UE_LOG(LogTemp, Error, TEXT("Assimp error: %s"), UTF8_TO_TCHAR(Importer.GetErrorString()));
    return false;
  }

  ProcessNode(Scene->mRootNode, Scene, MeshComponent);
  return true;
}

void FRuntimeMeshLoader::ProcessNode(const aiNode* Node, const aiScene* Scene, UProceduralMeshComponent* MeshComponent)
{
  for (unsigned int i = 0; i < Node->mNumMeshes; i++)
  {
    aiMesh* Mesh = Scene->mMeshes[Node->mMeshes[i]];
    ProcessMesh(Mesh, Scene, MeshComponent);
  }

  for (unsigned int i = 0; i < Node->mNumChildren; i++)
  {
    ProcessNode(Node->mChildren[i], Scene, MeshComponent);
  }
}

void FRuntimeMeshLoader::ProcessMesh(const aiMesh* Mesh, const aiScene* Scene, UProceduralMeshComponent* MeshComponent)
{
  TArray<FVector> Vertices;
  TArray<int32> Triangles;
  TArray<FVector> Normals;
  TArray<FVector2D> UV0;
  TArray<FProcMeshTangent> Tangents;

  // Procesar vértices
  for (unsigned int i = 0; i < Mesh->mNumVertices; i++)
  {
    Vertices.Add(FVector(Mesh->mVertices[i].x, Mesh->mVertices[i].y, Mesh->mVertices[i].z));

    if (Mesh->HasNormals())
    {
      Normals.Add(FVector(Mesh->mNormals[i].x, Mesh->mNormals[i].y, Mesh->mNormals[i].z));
    }

    if (Mesh->mTextureCoords[0])
    {
      UV0.Add(FVector2D(Mesh->mTextureCoords[0][i].x, Mesh->mTextureCoords[0][i].y));
    }

    if (Mesh->HasTangentsAndBitangents())
    {
      Tangents.Add(FProcMeshTangent(
        FVector(Mesh->mTangents[i].x, Mesh->mTangents[i].y, Mesh->mTangents[i].z),
        true
      ));
    }
  }

  // Procesar índices
  for (unsigned int i = 0; i < Mesh->mNumFaces; i++)
  {
    aiFace Face = Mesh->mFaces[i];
    for (unsigned int j = 0; j < Face.mNumIndices; j++)
    {
      Triangles.Add(Face.mIndices[j]);
    }
  }

  // Crear la malla
  MeshComponent->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, TArray<FLinearColor>(), Tangents, true);
}
