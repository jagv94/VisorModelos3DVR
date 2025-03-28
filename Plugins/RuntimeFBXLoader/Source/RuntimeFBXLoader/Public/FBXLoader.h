#pragma once

#include "CoreMinimal.h"
#include "RuntimeFBXLoader.h"  // Incluye el archivo principal del módulo

// Declaración adelantada de Assimp
namespace Assimp
{
  class Importer;
}

struct aiScene;
struct aiMesh;

class RUNTIMEFBXLOADER_API FBXLoader
{
public:
  static const aiScene* LoadFBX(const FString& FilePath);
};
