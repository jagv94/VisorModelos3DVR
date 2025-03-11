#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ModelLoader.generated.h"

UCLASS()
class VISORMODELOS3DVR_API UModelLoader : public UObject
{
  GENERATED_BODY()

public:
  // Función para obtener archivos FBX de una carpeta
  UFUNCTION(BlueprintCallable, Category = "Model Loader")
  static TArray<FString> GetFBXFilesInDirectory(const FString& Directory);
};
