#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PakLoaderBPLibrary.generated.h"

USTRUCT(BlueprintType)
struct FPakFileData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    int32 ID;

    UPROPERTY(BlueprintReadOnly)
    FString FileName;

    UPROPERTY(BlueprintReadOnly)
    FString AbsolutePath;

    UPROPERTY(BlueprintReadOnly)
    FDateTime ModificationDate;

    UPROPERTY(BlueprintReadOnly)
    int64 FileSize;
};

UCLASS()
class PAKLOADER_API UPakLoaderBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    // Devuelve todos los archivos .pak de la carpeta indicada (con subcarpetas)
    UFUNCTION(BlueprintCallable, Category = "Pak Loader")
    static TArray<FPakFileData> GetPakFilesInFolder(const FString& FolderPath);

    // Monta un archivo .pak en el directorio de contenido del proyecto
    UFUNCTION(BlueprintCallable, Category = "Pak Loader")
    static bool MountPakFile(const FString& PakFilePath);

    // Desmonta un archivo .pak
    UFUNCTION(BlueprintCallable, Category = "Pak Loader")
    static bool UnmountPakFile(const FString& PakFilePath);

    // Comprueba si un asset (como un StaticMesh) fue cargado
    UFUNCTION(BlueprintCallable, Category = "Pak Loader")
    static bool IsAssetLoaded(const FString& AssetPath);

    // Spawnea un StaticMeshActor desde el asset del .pak cargado
    UFUNCTION(BlueprintCallable, Category = "Pak Loader", meta=(WorldContext="WorldContextObject"))
    static AStaticMeshActor* SpawnStaticMeshFromPak(UObject* WorldContextObject, const FString& AssetPath, const FVector& Location, const FRotator& Rotation);

    // Obtener AssetPath del .pak
    UFUNCTION(BlueprintCallable, Category = "Pak Loader")
    static FString GetStaticMeshAssetPathFromPak(const FString& PakFilePath);

};