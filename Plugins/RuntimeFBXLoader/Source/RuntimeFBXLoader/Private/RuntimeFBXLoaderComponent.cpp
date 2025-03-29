#include "RuntimeFBXLoaderComponent.h"
#include "RuntimeMeshLoader.h"
#include "DesktopPlatformModule.h"

URuntimeFBXLoaderComponent::URuntimeFBXLoaderComponent()
{
  PrimaryComponentTick.bCanEverTick = true;
  bWantsInitializeComponent = true;
  TargetMeshComponent = nullptr;
  ActiveDirectory = FPaths::ProjectContentDir();
  LastLoadedFile = TEXT("");
}

void URuntimeFBXLoaderComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool URuntimeFBXLoaderComponent::LoadFBXFile(const FString& FilePath)
{
  if (!FPaths::FileExists(FilePath)) return false;

  if (!TargetMeshComponent)
  {
    UE_LOG(LogTemp, Error, TEXT("TargetMeshComponent no está asignado"));
    return false;
  }

  FRuntimeMeshLoader Loader;
  if (Loader.LoadMeshFromFile(FilePath, TargetMeshComponent))
  {
    LastLoadedFile = FilePath;
    ActiveDirectory = FPaths::GetPath(FilePath);
    return true;
  }
  return false;
}

bool URuntimeFBXLoaderComponent::OpenAndLoadFBXFile()
{
  if (IDesktopPlatform* Platform = FDesktopPlatformModule::Get())
  {
    TArray<FString> SelectedFiles;
    if (Platform->OpenFileDialog(nullptr, "Seleccionar FBX", ActiveDirectory, "", "FBX Files (*.fbx)|*.fbx", 0, SelectedFiles))
    {
      return LoadFBXFile(SelectedFiles[0]);
    }
  }
  return false;
}

bool URuntimeFBXLoaderComponent::SetActiveDirectory(const FString& DirectoryPath)
{
  if (FPaths::DirectoryExists(DirectoryPath))
  {
    ActiveDirectory = DirectoryPath;
    return true;
  }
  return false;
}

TArray<FFBXFileInfo> URuntimeFBXLoaderComponent::GetFilesInActiveDirectory() const
{
  TArray<FFBXFileInfo> Files;
  if (!FPaths::DirectoryExists(ActiveDirectory)) return Files;

  TArray<FString> FileNames;
  IFileManager::Get().FindFiles(FileNames, *(ActiveDirectory / "*.fbx"), true, false);

  for (const FString& FileName : FileNames)
  {
    const FString FullPath = ActiveDirectory / FileName;
    if (FFileStatData Stats = IFileManager::Get().GetStatData(*FullPath); Stats.bIsValid)
    {
      Files.Add({ FileName, Stats.FileSize, Stats.ModificationTime });
    }
  }
  return Files;
}

bool URuntimeFBXLoaderComponent::OpenDirectoryDialog()
{
  if (IDesktopPlatform* Platform = FDesktopPlatformModule::Get())
  {
    FString SelectedPath;
    if (Platform->OpenDirectoryDialog(nullptr, "Seleccionar Carpeta", ActiveDirectory, SelectedPath))
    {
      return SetActiveDirectory(SelectedPath);
    }
  }
  return false;
}

void URuntimeFBXLoaderComponent::SetModelTransform(const FTransform& NewTransform)
{
  if (TargetMeshComponent)
  {
    TargetMeshComponent->SetWorldTransform(NewTransform);
  }
}
