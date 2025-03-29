#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class RUNTIMEFBXLOADER_API FRuntimeMeshLoader
{
public:
  FRuntimeMeshLoader();
  ~FRuntimeMeshLoader();

  bool LoadMeshFromFile(const FString& FilePath, UProceduralMeshComponent* MeshComponent, int32 LODIndex = 0);

private:
  void ProcessNode(const aiNode* Node, const aiScene* Scene, UProceduralMeshComponent* MeshComponent);
  void ProcessMesh(const aiMesh* Mesh, const aiScene* Scene, UProceduralMeshComponent* MeshComponent);
};
