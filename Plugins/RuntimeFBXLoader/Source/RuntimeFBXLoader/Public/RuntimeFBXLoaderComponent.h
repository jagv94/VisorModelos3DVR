#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProceduralMeshComponent.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "RuntimeFBXLoaderComponent.generated.h"

USTRUCT(BlueprintType)
struct FFBXFileInfo
{
  GENERATED_BODY()

  UPROPERTY(BlueprintReadOnly, Category = "FBX Info")
  FString FileName;

  UPROPERTY(BlueprintReadOnly, Category = "FBX Info")
  int64 FileSize;

  UPROPERTY(BlueprintReadOnly, Category = "FBX Info")
  FDateTime LastModified;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RUNTIMEFBXLOADER_API URuntimeFBXLoaderComponent : public UActorComponent
{
  GENERATED_BODY()

public:
  URuntimeFBXLoaderComponent();

protected:
  virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

  // Sistema de archivos
  UFUNCTION(BlueprintCallable, Category = "FBX Loader|File System")
  bool LoadFBXFile(const FString& FilePath);

  UFUNCTION(BlueprintCallable, Category = "FBX Loader|File System")
  bool OpenAndLoadFBXFile();

  UFUNCTION(BlueprintCallable, Category = "FBX Loader|File System")
  bool SetActiveDirectory(const FString& DirectoryPath);

  UFUNCTION(BlueprintCallable, Category = "FBX Loader|File System")
  TArray<FFBXFileInfo> GetFilesInActiveDirectory() const;

  UFUNCTION(BlueprintCallable, Category = "FBX Loader|File System")
  bool OpenDirectoryDialog();

  // Manipulación del modelo
  UFUNCTION(BlueprintCallable, Category = "FBX Loader|Manipulation")
  void SetModelTransform(const FTransform& NewTransform);

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FBX Loader")
  FString ActiveDirectory;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FBX Loader")
  UProceduralMeshComponent* TargetMeshComponent;
  FString LastLoadedFile;
};
