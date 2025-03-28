#include "FBXLoader.h"
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"

const aiScene* FBXLoader::LoadFBX(const FString& FilePath)
{
  if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
  {
    UE_LOG(LogTemp, Warning, TEXT("El archivo FBX no existe: %s"), *FilePath);
    return nullptr;
  }

  Assimp::Importer Importer;
  const aiScene* Scene = Importer.ReadFile(TCHAR_TO_UTF8(*FilePath),
    aiProcess_Triangulate |
    aiProcess_ConvertToLeftHanded |
    aiProcess_CalcTangentSpace |
    aiProcess_GenNormals);

  if (!Scene || !Scene->HasMeshes())
  {
    UE_LOG(LogTemp, Error, TEXT("Error al cargar el FBX: %s"), *FilePath);
    return nullptr;
  }

  return Scene;
}
