#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBXConverterLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnConversionProgress, float, Progress);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnConversionComplete, bool, bSuccess);

// Declaración adelantada de la clase auxiliar
class FFBXConversionRunnable;

UCLASS()
class VISORMODELOS3DVR_API UFBXConverterLibrary : public UBlueprintFunctionLibrary
{
  GENERATED_BODY()

public:
  // Estructura para los datos de la tarea
  struct FConversionTask
  {
    FString InputFile;
    FOnConversionProgress OnProgress;
    FOnConversionComplete OnComplete;
  };

  UFUNCTION(BlueprintCallable, Category = "FBX Converter")
  static FString OpenFileDialog();

  UFUNCTION(BlueprintCallable, Category = "FBX Converter", meta = (DisplayName = "Convertir a FBX (Async)"))
  static void ConvertToFBXAsync(
    const FString& InputFile,
    const FOnConversionProgress& OnProgress,
    const FOnConversionComplete& OnComplete);

  // Función estática accesible para la clase Runnable
  static void ExecuteConversionTask(const FConversionTask& Task);
};
