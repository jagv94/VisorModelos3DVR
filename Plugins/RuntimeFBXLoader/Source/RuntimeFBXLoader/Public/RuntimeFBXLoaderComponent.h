#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RuntimeFBXLoaderComponent.generated.h"

class UProceduralMeshComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUNTIMEFBXLOADER_API URuntimeFBXLoaderComponent : public UActorComponent
{
  GENERATED_BODY()

public:
  URuntimeFBXLoaderComponent();

  UFUNCTION(BlueprintCallable, Category = "Runtime FBX Loader")
  bool LoadFBXFile(const FString& FilePath);

  UFUNCTION(BlueprintCallable, Category = "Runtime FBX Loader")
  bool OpenAndLoadFBXFile();

  UFUNCTION(BlueprintCallable, Category = "Runtime FBX Loader", meta = (HidePin = "Owner", DefaultToSelf = "Owner"))
  static URuntimeFBXLoaderComponent* CreateFBXLoaderComponent(AActor* Owner);

protected:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Runtime FBX Loader")
  UProceduralMeshComponent* TargetMeshComponent;
};
