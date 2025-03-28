#include "FBXLoader.h"
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"
#include "RuntimeFBXLoader.h"

const aiScene* FBXLoader::LoadFBX(const FString& FilePath)
{
  if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
  {
    UE_LOG(RuntimeFBXLoaderLog, Warning, TEXT("FBX file does not exist: %s"), *FilePath);
    return nullptr;
  }

  Assimp::Importer Importer;

  // Setup import properties
  Importer.SetPropertyFloat(AI_CONFIG_PP_GSN_MAX_SMOOTHING_ANGLE, 80.0f);
  Importer.SetPropertyInteger(AI_CONFIG_PP_SBP_REMOVE, aiPrimitiveType_POINT | aiPrimitiveType_LINE);

  const aiScene* Scene = Importer.ReadFile(TCHAR_TO_UTF8(*FilePath),
    aiProcess_Triangulate |
    aiProcess_ConvertToLeftHanded |
    aiProcess_CalcTangentSpace |
    aiProcess_GenNormals |
    aiProcess_GenUVCoords |
    aiProcess_OptimizeMeshes |
    aiProcess_ImproveCacheLocality |
    aiProcess_SortByPType |
    aiProcess_FindInvalidData |
    aiProcess_ValidateDataStructure);

  if (!Scene)
  {
    UE_LOG(RuntimeFBXLoaderLog, Error, TEXT("Failed to load FBX: %s. Error: %s"),
      *FilePath, UTF8_TO_TCHAR(Importer.GetErrorString()));
    return nullptr;
  }

  if (!Scene->HasMeshes())
  {
    UE_LOG(RuntimeFBXLoaderLog, Warning, TEXT("FBX file has no meshes: %s"), *FilePath);
    return nullptr;
  }

  return Scene;
}
