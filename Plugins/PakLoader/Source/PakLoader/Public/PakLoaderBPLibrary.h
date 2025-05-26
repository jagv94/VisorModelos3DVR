#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "PakLoaderBPLibrary.generated.h"

// Forward declaration para evitar incluir todo en header
class AStaticMeshActor;

// Información de archivo .pak encontrado
USTRUCT(BlueprintType)
struct FPakFileData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "Pak File")
    int32 ID;

    UPROPERTY(BlueprintReadOnly, Category = "Pak File")
    FString FileName;

    UPROPERTY(BlueprintReadOnly, Category = "Pak File")
    FString AbsolutePath;

    UPROPERTY(BlueprintReadOnly, Category = "Pak File")
    FDateTime ModificationDate;

    UPROPERTY(BlueprintReadOnly, Category = "Pak File")
    int64 FileSize;
};

UCLASS()
class PAKLOADER_API UPakLoaderBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    // Busca y devuelve todos los archivos .pak en la carpeta (recursivamente)
    UFUNCTION(BlueprintCallable, Category = "Pak Loader")
    static TArray<FPakFileData> GetPakFilesInFolder(const FString& FolderPath);

    // Monta un archivo .pak con un mount point único (/Game/FBX_Imported/NOMBRE/)
    // y registra los assets del pak en el AssetRegistry
    UFUNCTION(BlueprintCallable, Category = "Pak Loader")
    static bool MountPakFile(const FString& PakFilePath);

    // Desmonta un archivo .pak y elimina su carpeta temporal de montaje
    UFUNCTION(BlueprintCallable, Category = "Pak Loader")
    static bool UnmountPakFile(const FString& PakFilePath);

    // Comprueba si un asset ya fue cargado (por su path lógico)
    UFUNCTION(BlueprintCallable, Category = "Pak Loader")
    static bool IsAssetLoaded(const FString& AssetPath);

    // Instancia un StaticMeshActor desde un StaticMesh cargado desde el .pak
    UFUNCTION(BlueprintCallable, Category = "Pak Loader", meta = (WorldContext = "WorldContextObject"))
    static AStaticMeshActor* SpawnStaticMeshFromPak(UObject* WorldContextObject, const FString& AssetPath, const FVector& Location, const FRotator& Rotation);

    // Devuelve automáticamente el asset path lógico del primer StaticMesh encontrado dentro del .pak
    // Ejemplo: "/Game/FBX_Imported/MiPak/Nombre.Nombre"
    UFUNCTION(BlueprintCallable, Category = "Pak Loader")
    static FString GetStaticMeshAssetPathFromPak(const FString& PakFilePath);
};