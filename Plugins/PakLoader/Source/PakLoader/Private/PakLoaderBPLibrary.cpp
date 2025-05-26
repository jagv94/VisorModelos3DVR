#include "PakLoaderBPLibrary.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/Paths.h"
#include "IPlatformFilePak.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Misc/PackageName.h"
#include "Modules/ModuleManager.h"

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

bool UPakLoaderBPLibrary::MountPakFile(const FString& PakFilePath)
{
    if (!FPaths::FileExists(PakFilePath))
    {
        UE_LOG(LogTemp, Error, TEXT("No existe el archivo .pak: %s"), *PakFilePath);
        return false;
    }

    static FPakPlatformFile* PakPlatform = nullptr;
    static bool bInitialized = false;

    if (!bInitialized)
    {
        PakPlatform = new FPakPlatformFile();
        PakPlatform->Initialize(&FPlatformFileManager::Get().GetPlatformFile(), TEXT(""));
        FPlatformFileManager::Get().SetPlatformFile(*PakPlatform);
        bInitialized = true;
    }

    FString PakBaseName = FPaths::GetBaseFilename(PakFilePath);
    // Montamos en carpeta temporal bajo Saved/PaksMounted para evitar conflictos y limpieza sencilla
    FString TempMountFolder = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("PaksMounted"), PakBaseName);
    IFileManager::Get().MakeDirectory(*TempMountFolder, true);

    bool bMounted = PakPlatform->Mount(*PakFilePath, 0, *TempMountFolder);

    if (bMounted)
    {
        // Usar mount point lógico coherente con el contenido del pak y con el sistema Unreal
        FString LogicalMountPoint = FString::Printf(TEXT("/Game/FBX_Imported/%s/"), *PakBaseName);

        // Registrar el mount point apuntando a la carpeta física donde montamos
        FPackageName::RegisterMountPoint(*LogicalMountPoint, TempMountFolder);

        UE_LOG(LogTemp, Log, TEXT("Pak montado correctamente: %s"), *PakFilePath);
        UE_LOG(LogTemp, Log, TEXT("Mount point: físico = %s, lógico = %s"), *TempMountFolder, *LogicalMountPoint);

        // Forzar refresco del AssetRegistry en el mount point lógico
        FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
        AssetRegistryModule.Get().ScanPathsSynchronous({ LogicalMountPoint }, true);

        // Opcional: buscar primer StaticMesh para validar
        TArray<FAssetData> AssetList;
        AssetRegistryModule.Get().GetAssetsByPath(FName(*LogicalMountPoint), AssetList, true);

        for (const FAssetData& Asset : AssetList)
        {
            if (Asset.AssetClassPath == UStaticMesh::StaticClass()->GetClassPathName())
            {
                UE_LOG(LogTemp, Log, TEXT("Primer StaticMesh encontrado en el pak: %s"), *Asset.GetSoftObjectPath().ToString());
                break;
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Fallo al montar el archivo Pak: %s"), *PakFilePath);
    }

    return bMounted;
}

bool UPakLoaderBPLibrary::UnmountPakFile(const FString& PakFilePath)
{
    FPakPlatformFile* PakPlatform = (FPakPlatformFile*)FPlatformFileManager::Get().FindPlatformFile(TEXT("PakFile"));
    if (!PakPlatform)
    {
        UE_LOG(LogTemp, Warning, TEXT("No se encontró FPakPlatformFile al desmontar"));
        return false;
    }

    bool bResult = PakPlatform->Unmount(*PakFilePath);

    if (bResult)
    {
        FString PakBaseName = FPaths::GetBaseFilename(PakFilePath);
        // Usar la misma ruta que en MountPakFile para evitar inconsistencias
        FString PakFolder = FPaths::GetPath(PakFilePath);
        FString TempMountFolder = FPaths::Combine(PakFolder, PakBaseName + TEXT("_Mounted"));

        IFileManager::Get().DeleteDirectory(*TempMountFolder, false, true);

        FString LogicalMountPoint = FString::Printf(TEXT("/Game/FBX_Imported/%s/"), *PakBaseName);
        FPackageName::UnRegisterMountPoint(*LogicalMountPoint, *TempMountFolder);

        UE_LOG(LogTemp, Log, TEXT("Pak desmontado y carpeta eliminada: %s"), *PakFilePath);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No se pudo desmontar el Pak: %s"), *PakFilePath);
    }

    return bResult;
}

bool UPakLoaderBPLibrary::IsAssetLoaded(const FString& AssetPath)
{
    UObject* Asset = StaticLoadObject(UObject::StaticClass(), nullptr, *AssetPath);
    return Asset != nullptr;
}

AStaticMeshActor* UPakLoaderBPLibrary::SpawnStaticMeshFromPak(UObject* WorldContextObject, const FString& AssetPath, const FVector& Location, const FRotator& Rotation)
{
    UStaticMesh* Mesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *AssetPath));
    if (!Mesh)
    {
        UE_LOG(LogTemp, Warning, TEXT("StaticMesh no encontrado: %s"), *AssetPath);
        return nullptr;
    }

    UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
    if (!World)
    {
        UE_LOG(LogTemp, Warning, TEXT("Mundo no encontrado para Spawn"));
        return nullptr;
    }

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
    FString PakBaseName = FPaths::GetBaseFilename(PakFilePath);
    FString LogicalMountPoint = FString::Printf(TEXT("/Game/FBX_Imported/%s/"), *PakBaseName);

    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

    // Escanear la ruta lógica donde montamos el pak para asegurar los assets cargados
    AssetRegistryModule.Get().ScanPathsSynchronous({ LogicalMountPoint }, true);

    TArray<FAssetData> AssetList;
    AssetRegistryModule.Get().GetAssetsByPath(FName(*LogicalMountPoint), AssetList, true);

    for (const FAssetData& Asset : AssetList)
    {
        if (Asset.AssetClassPath == UStaticMesh::StaticClass()->GetClassPathName())
        {
            return Asset.GetSoftObjectPath().ToString();
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("No se encontró StaticMesh en el .pak: %s"), *PakFilePath);
    return FString();
}