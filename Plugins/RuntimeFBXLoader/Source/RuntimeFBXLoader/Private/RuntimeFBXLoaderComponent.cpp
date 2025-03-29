#include "RuntimeFBXLoaderComponent.h"
#include "ProceduralMeshComponent.h"
#include "RuntimeMeshLoader.h"
#include "DesktopPlatformModule.h"
#include "IDesktopPlatform.h"

URuntimeFBXLoaderComponent::URuntimeFBXLoaderComponent()
{
  PrimaryComponentTick.bCanEverTick = false;
  TargetMeshComponent = nullptr;
}

URuntimeFBXLoaderComponent* URuntimeFBXLoaderComponent::CreateFBXLoaderComponent(AActor* Owner)
{
  if (!Owner) return nullptr;

  URuntimeFBXLoaderComponent* NewComponent = NewObject<URuntimeFBXLoaderComponent>(Owner);
  NewComponent->RegisterComponent();
  return NewComponent;
}

bool URuntimeFBXLoaderComponent::LoadFBXFile(const FString& FilePath)
{
  if (!TargetMeshComponent)
  {
    TargetMeshComponent = NewObject<UProceduralMeshComponent>(GetOwner());
    TargetMeshComponent->RegisterComponent();
    TargetMeshComponent->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
  }

  FRuntimeMeshLoader Loader;
  return Loader.LoadMeshFromFile(FilePath, TargetMeshComponent);
}

bool URuntimeFBXLoaderComponent::OpenAndLoadFBXFile()
{
  IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
  if (DesktopPlatform)
  {
    TArray<FString> OutFiles;
    const FString DialogTitle = "Select FBX File";
    const FString DefaultPath = FPaths::ProjectContentDir();
    const FString FileTypes = "FBX Files (*.fbx)|*.fbx";

    if (DesktopPlatform->OpenFileDialog(
      FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr),
      DialogTitle,
      DefaultPath,
      "",
      FileTypes,
      EFileDialogFlags::None,
      OutFiles
    ))
    {
      if (OutFiles.Num() > 0)
      {
        return LoadFBXFile(OutFiles[0]);
      }
    }
  }
  return false;
}
