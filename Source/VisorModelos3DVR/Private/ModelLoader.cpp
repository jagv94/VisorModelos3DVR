#include "ModelLoader.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"

TArray<FFBXFileInfo> UModelLoader::GetFBXFilesInDirectory(const FString& Directory)
{
  TArray<FFBXFileInfo> FoundFiles;

  FString SearchPath = Directory + TEXT("/*.fbx");
  TArray<FString> FileNames;

  // Obtener los nombres de los archivos
  IFileManager& FileManager = IFileManager::Get();
  FileManager.FindFiles(FileNames, *SearchPath, true, false);

  for (const FString& FileName : FileNames)
  {
    FFBXFileInfo FileInfo;
    FileInfo.FileName = FileName;

    FString FullPath = FPaths::Combine(Directory, FileName);
    FFileStatData StatData = FileManager.GetStatData(*FullPath);

    if (StatData.bIsValid)
    {
      FileInfo.FileSize = StatData.FileSize; // Tamaño en bytes
      FileInfo.LastModified = StatData.ModificationTime;
    }

    FoundFiles.Add(FileInfo);
  }

  return FoundFiles;
}
