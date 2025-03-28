#pragma once

#include "CoreMinimal.h"
#include "RuntimeFBXLoader.h"
#include <assimp/scene.h>

class RUNTIMEFBXLOADER_API FBXLoader
{
public:
  static const aiScene* LoadFBX(const FString& FilePath);
};
