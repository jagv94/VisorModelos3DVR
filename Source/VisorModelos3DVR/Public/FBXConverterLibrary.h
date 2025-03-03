#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBXConverterLibrary.generated.h"

UCLASS()
class VISORMODELOS3DVR_API UFBXConverterLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    // Función que permite la selección de un archivo
    UFUNCTION(BlueprintCallable, Category = "FBX Converter")
    static FString OpenFileDialog();

    // Función de conversión (ya implementada)
    UFUNCTION(BlueprintCallable, Category = "FBX Converter")
    static bool ConvertToFBX(const FString& InputFile);
};
