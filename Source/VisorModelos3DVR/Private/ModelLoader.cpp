#include "ModelLoader.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"

TArray<FString> UModelLoader::GetFBXFilesInDirectory(const FString& Directory)
{
  TArray<FString> FoundFiles;

  // Forma correcta de especificar el path
  FString SearchPath = Directory + TEXT("/*.fbx");

  // Obtener los archivos FBX en la carpeta
  IFileManager& FileManager = IFileManager::Get();
  FileManager.FindFiles(FoundFiles, *SearchPath, true, false);

  return FoundFiles;
}
