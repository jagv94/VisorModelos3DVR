#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "UObject/Object.h"
#include "Engine/StaticMesh.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "PhysicsEngine/BodySetup.h"
#include "StaticMeshResources.h"
#include "RenderResource.h"
#include "MeshDescription.h"
#include "StaticMeshAttributes.h"
#include "StaticMeshDescription.h"

#include "RuntimeFBXLoader.generated.h"

struct aiScene;
struct aiMesh;
struct aiMaterial;

DECLARE_LOG_CATEGORY_EXTERN(RuntimeFBXLoaderLog, Log, All);

class RUNTIMEFBXLOADER_API FRuntimeFBXLoaderModule : public IModuleInterface
{
public:
  virtual void StartupModule() override;
  virtual void ShutdownModule() override;
};

UCLASS(Blueprintable, BlueprintType)
class RUNTIMEFBXLOADER_API UFBXLoader : public UObject
{
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "FBX Loader")
  static UFBXLoader* GetFBXLoaderInstance();

  UFUNCTION(BlueprintCallable, Category = "FBX Loader")
  UStaticMesh* LoadFBX(const FString& FilePath);

  UFUNCTION(BlueprintCallable, Category = "FBX Loader")
  UTexture2D* LoadTextureFromPath(const FString& Path);

  UFUNCTION(BlueprintCallable, Category = "FBX Loader")
  UMaterialInstanceDynamic* CreateMaterial(UTexture2D* Texture);

private:
  void ProcessMaterials(const aiScene* Scene, UStaticMesh* StaticMesh);
};

USTRUCT(BlueprintType)
struct FImportedMeshData
{
  GENERATED_BODY()

  UPROPERTY(BlueprintReadOnly)
  UStaticMesh* StaticMesh;

  UPROPERTY(BlueprintReadOnly)
  FTransform RelativeTransform;

  UPROPERTY(BlueprintReadOnly)
  FString MeshName;
};
