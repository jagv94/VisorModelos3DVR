#include "PakLoaderBPLibrary.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/Paths.h"
#include "IPlatformFilePak.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Obtener todos los .pak en una carpeta
TArray<FPakFileData> UPakLoaderBPLibrary::GetPakFilesInFolder(const FString& FolderPath)
{
    TArray<FPakFileData> PakFiles;
    IFileManager& FileManager = IFileManager::Get();

    TArray<FString> FoundFiles;
    FileManager.FindFilesRecursive(FoundFiles, *FolderPath, TEXT("*.pak"), true, false);

    for (int32 i = 0; i < FoundFiles.Num(); ++i)
    {
        const FString& File = FoundFiles[i];

        FPakFileData Data;
        Data.ID = i;
        Data.FileName = FPaths::GetCleanFilename(File);
        Data.AbsolutePath = File;
        Data.ModificationDate = FileManager.GetTimeStamp(*File);
        Data.FileSize = FileManager.FileSize(*File);

        PakFiles.Add(Data);
    }

    return PakFiles;
}

// Montar .pak (sin MountPoint lógico, los assets ya usan /Game/ en la ruta virtual)
bool UPakLoaderBPLibrary::MountPakFile(const FString& PakFilePath)
{
    if (!FPaths::FileExists(PakFilePath))
        return false;

    // Asegurar que el sistema Pak está registrado
    FPakPlatformFile* PakPlatform = (FPakPlatformFile*)(FPlatformFileManager::Get().FindPlatformFile(TEXT("PakFile")));
    if (!PakPlatform)
    {
        static FPakPlatformFile StaticPakPlatformFile;
        PakPlatform = &StaticPakPlatformFile;
        PakPlatform->Initialize(&FPlatformFileManager::Get().GetPlatformFile(), TEXT(""));
        FPlatformFileManager::Get().SetPlatformFile(*PakPlatform);
    }

    // Montamos el .pak en la raíz de Content (/Game/)
    FString MountPoint = FPaths::ProjectContentDir();
    return PakPlatform->Mount(*PakFilePath, 0, *MountPoint);
}

// Desmontar .pak
bool UPakLoaderBPLibrary::UnmountPakFile(const FString& PakFilePath)
{
    FPakPlatformFile* PakPlatform = (FPakPlatformFile*)(FPlatformFileManager::Get().FindPlatformFile(TEXT("PakFile")));
    if (!PakPlatform)
        return false;

    return PakPlatform->Unmount(*PakFilePath);
}

// Comprobar si el asset existe o está cargado
bool UPakLoaderBPLibrary::IsAssetLoaded(const FString& AssetPath)
{
    UObject* Asset = StaticLoadObject(UObject::StaticClass(), nullptr, *AssetPath);
    return Asset != nullptr;
}

// Instanciar un StaticMeshActor desde un asset en el .pak
AStaticMeshActor* UPakLoaderBPLibrary::SpawnStaticMeshFromPak(UObject* WorldContextObject, const FString& AssetPath, const FVector& Location, const FRotator& Rotation)
{
    UStaticMesh* Mesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *AssetPath));
    if (!Mesh)
    {
        UE_LOG(LogTemp, Warning, TEXT("StaticMesh no cargado desde ruta: %s"), *AssetPath);
        return nullptr;
    }

    UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
    if (!World)
        return nullptr;

    FActorSpawnParameters SpawnParams;
    AStaticMeshActor* MeshActor = World->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(), Location, Rotation, SpawnParams);

    if (MeshActor && MeshActor->GetStaticMeshComponent())
    {
        MeshActor->GetStaticMeshComponent()->SetStaticMesh(Mesh);
        MeshActor->SetMobility(EComponentMobility::Movable);
        MeshActor->GetStaticMeshComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    }

    return MeshActor;
}

FString UPakLoaderBPLibrary::GetStaticMeshAssetPathFromPak(const FString& PakFilePath)
{
    // Obtener el nombre base sin extensión
    FString PakFileName = FPaths::GetBaseFilename(PakFilePath); // e.g., "Casa"

    // Construir la ruta lógica del asset
    // Resultado: "/Game/FBX_Imported/Casa/Casa.Casa"
    FString AssetPath = FString::Printf(TEXT("/Game/FBX_Imported/%s/%s.%s"), *PakFileName, *PakFileName, *PakFileName);

    return AssetPath;
}