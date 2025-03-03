#include "FBXConverterLibrary.h"
#include "Misc/Paths.h"
#include "DesktopPlatformModule.h"
#include "HAL/PlatformProcess.h"
#include "HAL/FileManager.h"

FString UFBXConverterLibrary::OpenFileDialog()
{
    FString FilePath;
    const FString FileTypes = TEXT(
      "Archivos soportados (*.las;*.laz;*.e57;*.xyz;*.ply;*.pts;*.obj;*.stl;*.glb;*.gltf;*.dxf)|*.las;*.laz;*.e57;*.xyz;*.ply;*.pts;*.obj;*.stl;*.glb;*.gltf;*.dxf|"
      "Todos los Archivos (*.*)|*.*"
    );

    // Ruta predeterminada (vacío para que se abra en la carpeta predeterminada del sistema)
    FString DefaultPath = TEXT("");

    // Si no se proporciona un archivo predeterminado, lo dejamos en vacío.
    FString DefaultFile = TEXT("");

    // Lista donde se guardarán los archivos seleccionados
    TArray<FString> SelectedFiles;

    // Usamos el DesktopPlatformModule para abrir el cuadro de diálogo
    IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
    if (DesktopPlatform)
    {
        // Abrimos el cuadro de diálogo de selección de archivo para un solo archivo
        bool bOpened = DesktopPlatform->OpenFileDialog(
            nullptr,                  // Ventana principal (no necesitamos una ventana principal)
            TEXT("Selecciona un archivo"),  // Título del cuadro de diálogo
            DefaultPath,              // Ruta predeterminada
            DefaultFile,              // Archivo predeterminado
            FileTypes,                // Filtros de tipo de archivo
            EFileDialogFlags::None,   // Ninguna bandera especial, esto asegura que solo se seleccione un archivo
            SelectedFiles             // Guardamos los archivos seleccionados en esta variable
        );

        // Si se seleccionó al menos un archivo, obtenemos la ruta del primer archivo
        if (bOpened && SelectedFiles.Num() > 0)
        {
            FilePath = SelectedFiles[0];  // Tomamos el primer archivo seleccionado
        }
    }

    return FilePath;
}

bool UFBXConverterLibrary::ConvertToFBX(const FString& InputFile)
{
  // Instancia de FileManager
  IFileManager& FileManager = IFileManager::Get();

  // Verificar si el archivo existe
  if (!FPaths::FileExists(InputFile))
  {
    UE_LOG(LogTemp, Error, TEXT("El archivo %s no existe."), *InputFile);
    return false;
  }

  // Obtener la carpeta del usuario
  FString UserFolder = FPaths::Combine(FPlatformProcess::UserDir(), TEXT("VisorModelos3DVR/"));
  if (!FPaths::DirectoryExists(UserFolder))
  {
    FileManager.MakeDirectory(*UserFolder, true);
  }

  // Ruta de CloudCompare
  FString CloudComparePath = FPaths::Combine(FPaths::ProjectDir(), TEXT("Tools/CloudCompare/CloudCompare.exe"));

  if (!FPaths::FileExists(CloudComparePath))
  {
    UE_LOG(LogTemp, Error, TEXT("CloudCompare no encontrado en %s"), *CloudComparePath);
    return false;
  }

  // Crear archivo temporal de matriz identidad
  FString MatrixFile = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("identity_matrix.txt"));
  FString MatrixContent = TEXT(
    "1.0 0.0 0.0 0.0\n"
    "0.0 1.0 0.0 0.0\n"
    "0.0 0.0 1.0 0.0\n"
    "0.0 0.0 0.0 1.0\n"
  );

  if (!FFileHelper::SaveStringToFile(MatrixContent, *MatrixFile))
  {
    UE_LOG(LogTemp, Error, TEXT("No se pudo crear el archivo de matriz identidad."));
    return false;
  }

  // Construir comando para CloudCompare
  FString Command = FString::Printf(TEXT("-SILENT -AUTO_SAVE OFF -M_EXPORT_FMT FBX -FBX -EXPORT_FMT FBX_binary -O -GLOBAL_SHIFT AUTO \"%s\" -APPLY_TRANS -APPLY_TO_GLOBAL FORCE \"%s\" -NO_TIMESTAMP -SAVE_MESHES"),
    *InputFile, *MatrixFile);

  FProcHandle ProcessHandle = FPlatformProcess::CreateProc(*CloudComparePath, *Command, true, false, false, nullptr, 0, nullptr, nullptr);

  if (!ProcessHandle.IsValid())
  {
    UE_LOG(LogTemp, Error, TEXT("No se pudo iniciar CloudCompare."));
    return false;
  }

  // Esperar a que termine el proceso
  FPlatformProcess::WaitForProc(ProcessHandle);
  FPlatformProcess::CloseProc(ProcessHandle);

  // Eliminar el archivo de la matriz identidad
  FileManager.Delete(*MatrixFile);

  // Mover archivo convertido
  FString FileName = FPaths::GetBaseFilename(InputFile);
  FString TransformedFBX = FPaths::Combine(FPaths::GetPath(InputFile), FileName + TEXT("_TRANSFORMED.fbx"));
  FString DestinationFBX = FPaths::Combine(UserFolder, FileName + TEXT("_TRANSFORMED.fbx"));

  FString TransformedFBM = FPaths::Combine(FPaths::GetPath(InputFile), FileName + TEXT("_TRANSFORMED.fbm"));
  FString DestinationFBM = FPaths::Combine(UserFolder, FileName + TEXT("_TRANSFORMED.fbm"));

  bool bSuccess = false;

  if (FPaths::FileExists(TransformedFBX))
  {
    FileManager.Move(*DestinationFBX, *TransformedFBX);
    UE_LOG(LogTemp, Log, TEXT("Archivo FBX movido a: %s"), *DestinationFBX);
    bSuccess = true;
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("El archivo FBX convertido no se encontró: %s"), *TransformedFBX);
  }

  // Comando ROBOCOPY para mover la carpeta y su contenido
  FString RobocopyCommand = FString::Printf(TEXT("/C robocopy \"%s\" \"%s\" /E /MOVE"), *TransformedFBM, *DestinationFBM);

  UE_LOG(LogTemp, Log, TEXT("Ejecutando comando: cmd.exe %s"), *RobocopyCommand);

  // Ejecutar el comando en una terminal de Windows
  FProcHandle ProcessHandle2 = FPlatformProcess::CreateProc(TEXT("cmd.exe"), *RobocopyCommand, true, false, false, nullptr, 0, nullptr, nullptr);

  if (!ProcessHandle.IsValid())
  {
    UE_LOG(LogTemp, Error, TEXT("No se pudo ejecutar ROBOCOPY."));
    return false;
  }

  // Esperar a que termine la ejecución del comando
  FPlatformProcess::WaitForProc(ProcessHandle);
  FPlatformProcess::CloseProc(ProcessHandle);

  // Verificar si la carpeta fue movida correctamente
  if (FPaths::DirectoryExists(*DestinationFBM))
  {
    UE_LOG(LogTemp, Log, TEXT("Carpeta .fbm movida correctamente a: %s"), *DestinationFBM);
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("La carpeta .fbm no se movió correctamente a: %s"), *DestinationFBM);
  }

  return bSuccess;
}
