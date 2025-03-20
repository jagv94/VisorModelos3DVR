#pragma once

#include "CoreMinimal.h"
#include "assimp/scene.h"

/**
 * FBXLoader - Clase para cargar archivos FBX usando Assimp
 */
class RUNTIMEFBXLOADER_API FBXLoader
{
public:
    /** Carga un archivo FBX y devuelve el aiScene de Assimp */
    static const aiScene* LoadFBX(const FString& FilePath);
};
