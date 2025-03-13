#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ModelLoader.generated.h"

USTRUCT(BlueprintType)
struct FFBXFileInfo
{
  GENERATED_BODY()

  UPROPERTY(BlueprintReadOnly, Category = "Model Info")
  FString FileName;

  UPROPERTY(BlueprintReadOnly, Category = "Model Info")
  int64 FileSize;

  UPROPERTY(BlueprintReadOnly, Category = "Model Info")
  FDateTime LastModified;
};

UCLASS()
class VISORMODELOS3DVR_API UModelLoader : public UObject
{
  GENERATED_BODY()

public:
  // Función para obtener archivos FBX de una carpeta
  UFUNCTION(BlueprintCallable, Category = "Model Loader")
  static TArray<FFBXFileInfo> GetFBXFilesInDirectory(const FString& Directory);
};
