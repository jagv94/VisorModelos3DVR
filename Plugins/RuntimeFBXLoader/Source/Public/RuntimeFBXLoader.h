#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/StaticMesh.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "FBXLoader.h"

#include "RuntimeFBXLoader.generated.h"

UCLASS()
class RUNTIMEFBXLOADER_API UFBXLoader : public UObject
{
    GENERATED_BODY()

public:
    /** Carga un archivo FBX y lo convierte en un StaticMesh */
    UFUNCTION(BlueprintCallable, Category = "FBX Loader")
    UStaticMesh* LoadFBX(const FString& FilePath);

    /** Carga una textura desde una ruta */
    UFUNCTION(BlueprintCallable, Category = "FBX Loader")
    UTexture2D* LoadTextureFromPath(const FString& Path);

    /** Crea un material dinámico a partir de una textura */
    UFUNCTION(BlueprintCallable, Category = "FBX Loader")
    UMaterialInstanceDynamic* CreateMaterial(UTexture2D* Texture);

private:
    /** Convierte una malla de Assimp (aiMesh) en UStaticMesh */
    UStaticMesh* CreateStaticMeshFromAssimp(aiMesh* Mesh);
};
