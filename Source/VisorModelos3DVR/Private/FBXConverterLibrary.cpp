#include "FBXConverterLibrary.h"
#include "Misc/Paths.h"
#include "DesktopPlatformModule.h"
#include "HAL/PlatformProcess.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Async/Async.h"
#include "HAL/Thread.h"
#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"
#include "Misc/ScopedSlowTask.h"

// Clase Runnable para manejar la conversión en segundo plano
class FFBXConversionRunnable : public FRunnable
{
public:
  FFBXConversionRunnable(const UFBXConverterLibrary::FConversionTask& InTask)
    : Task(InTask), bRunning(true) {
  }

  virtual uint32 Run() override
  {
    UFBXConverterLibrary::ExecuteConversionTask(Task);
    bRunning = false;
    return 0;
  }

  bool IsRunning() const { return bRunning; }

private:
  UFBXConverterLibrary::FConversionTask Task;
  bool bRunning;
};

FString UFBXConverterLibrary::OpenFileDialog()
{
  FString FilePath;
  const FString FileTypes = TEXT(
    "Archivos soportados (*.las;*.laz;*.e57;*.xyz;*.ply;*.pts;*.obj;*.stl;*.glb;*.gltf;*.dxf)|*.las;*.laz;*.e57;*.xyz;*.ply;*.pts;*.obj;*.stl;*.glb;*.gltf;*.dxf|"
    "Todos los Archivos (*.*)|*.*"
  );

  FString DefaultPath = TEXT("");
  FString DefaultFile = TEXT("");
  TArray<FString> SelectedFiles;

  IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
  if (DesktopPlatform)
  {
    bool bOpened = DesktopPlatform->OpenFileDialog(
      nullptr,
      TEXT("Selecciona un archivo"),
      DefaultPath,
      DefaultFile,
      FileTypes,
      EFileDialogFlags::None,
      SelectedFiles
    );

    if (bOpened && SelectedFiles.Num() > 0)
    {
      FilePath = SelectedFiles[0];
    }
  }

  return FilePath;
}

void UFBXConverterLibrary::ConvertToFBXAsync(
  const FString& InputFile,
  const FOnConversionProgress& OnProgress,
  const FOnConversionComplete& OnComplete)
{
  FConversionTask Task;
  Task.InputFile = InputFile;
  Task.OnProgress = OnProgress;
  Task.OnComplete = OnComplete;

  // Crear y lanzar el hilo
  FFBXConversionRunnable* Runnable = new FFBXConversionRunnable(Task);
  FRunnableThread* Thread = FRunnableThread::Create(
    Runnable,
    TEXT("FBXConversionThread"),
    0,
    TPri_Normal);
}

void UFBXConverterLibrary::ExecuteConversionTask(const FConversionTask& Task)
{
  IFileManager& FileManager = IFileManager::Get();
  bool bSuccess = true;

  // Notificar inicio (0%)
  AsyncTask(ENamedThreads::GameThread, [Task]() {
    Task.OnProgress.ExecuteIfBound(0.0f);
    });

  // 1. Validaciones iniciales (10%)
  if (!FPaths::FileExists(Task.InputFile))
  {
    UE_LOG(LogTemp, Error, TEXT("El archivo %s no existe."), *Task.InputFile);
    AsyncTask(ENamedThreads::GameThread, [Task]() {
      Task.OnComplete.ExecuteIfBound(false);
      });
    return;
  }

  AsyncTask(ENamedThreads::GameThread, [Task]() {
    Task.OnProgress.ExecuteIfBound(0.1f);
    });

  // 2. Configurar directorios (20%)
  FString UserFolder = FPaths::Combine(FPlatformProcess::UserDir(), TEXT("VisorModelos3DVR/"));
  if (!FPaths::DirectoryExists(UserFolder))
  {
    FileManager.MakeDirectory(*UserFolder, true);
  }

  AsyncTask(ENamedThreads::GameThread, [Task]() {
    Task.OnProgress.ExecuteIfBound(0.2f);
    });

  // 3. Verificar CloudCompare (30%)
  FString CloudComparePath = FPaths::Combine(FPaths::ProjectDir(), TEXT("Tools/CloudCompare/CloudCompare.exe"));
  if (!FPaths::FileExists(CloudComparePath))
  {
    UE_LOG(LogTemp, Error, TEXT("CloudCompare no encontrado en %s"), *CloudComparePath);
    AsyncTask(ENamedThreads::GameThread, [Task]() {
      Task.OnComplete.ExecuteIfBound(false);
      });
    return;
  }

  AsyncTask(ENamedThreads::GameThread, [Task]() {
    Task.OnProgress.ExecuteIfBound(0.3f);
    });

  // 4. Crear matriz identidad (40%)
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
    AsyncTask(ENamedThreads::GameThread, [Task]() {
      Task.OnComplete.ExecuteIfBound(false);
      });
    return;
  }

  AsyncTask(ENamedThreads::GameThread, [Task]() {
    Task.OnProgress.ExecuteIfBound(0.4f);
    });

  // 5. Ejecutar CloudCompare (50%)
  FString Command = FString::Printf(TEXT("-SILENT -AUTO_SAVE OFF -M_EXPORT_FMT FBX -FBX -EXPORT_FMT FBX_binary -O -GLOBAL_SHIFT AUTO \"%s\" -APPLY_TRANS -APPLY_TO_GLOBAL FORCE \"%s\" -NO_TIMESTAMP -SAVE_MESHES"),
    *Task.InputFile, *MatrixFile);

  FProcHandle ProcessHandle = FPlatformProcess::CreateProc(*CloudComparePath, *Command, true, false, false, nullptr, 0, nullptr, nullptr);

  if (!ProcessHandle.IsValid())
  {
    UE_LOG(LogTemp, Error, TEXT("No se pudo iniciar CloudCompare."));
    AsyncTask(ENamedThreads::GameThread, [Task]() {
      Task.OnComplete.ExecuteIfBound(false);
      });
    return;
  }

  FPlatformProcess::WaitForProc(ProcessHandle);
  FPlatformProcess::CloseProc(ProcessHandle);
  FileManager.Delete(*MatrixFile);

  AsyncTask(ENamedThreads::GameThread, [Task]() {
    Task.OnProgress.ExecuteIfBound(0.5f);
    });

  // 6. Procesar archivos resultantes
  FString FileName = FPaths::GetBaseFilename(Task.InputFile);
  FString TransformedFBX = FPaths::Combine(FPaths::GetPath(Task.InputFile), FileName + TEXT("_TRANSFORMED.fbx"));
  FString DestinationFBX = FPaths::Combine(UserFolder, FileName + TEXT(".fbx"));

  FString TransformedFBM = FPaths::Combine(FPaths::GetPath(Task.InputFile), FileName + TEXT("_TRANSFORMED.fbm"));
  FString DestinationFBM = FPaths::Combine(UserFolder, FileName + TEXT(".fbm"));

  // Mover FBX (60%)
  if (FPaths::FileExists(TransformedFBX))
  {
    if (FileManager.Move(*DestinationFBX, *TransformedFBX))
    {
      UE_LOG(LogTemp, Log, TEXT("Archivo FBX movido a: %s"), *DestinationFBX);
    }
    else
    {
      UE_LOG(LogTemp, Error, TEXT("Error moviendo FBX"));
      bSuccess = false;
    }
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("Archivo FBX no encontrado: %s"), *TransformedFBX);
    bSuccess = false;
  }

  AsyncTask(ENamedThreads::GameThread, [Task]() {
    Task.OnProgress.ExecuteIfBound(0.6f);
    });

  // Mover FBM con progreso (60-90%)
  if (FPaths::DirectoryExists(TransformedFBM))
  {
    TArray<FString> Files;
    FileManager.FindFilesRecursive(Files, *TransformedFBM, TEXT("*.*"), true, false);

    if (Files.Num() > 0)
    {
      if (!FPaths::DirectoryExists(DestinationFBM))
      {
        FileManager.MakeDirectory(*DestinationFBM, true);
      }

      float Progress = 0.0f;
      const float ProgressStep = 0.3f / Files.Num();

      for (const FString& SourceFile : Files)
      {
        FString RelativePath = SourceFile;
        FPaths::MakePathRelativeTo(RelativePath, *TransformedFBM);
        FString DestFile = FPaths::Combine(DestinationFBM, RelativePath);

        FString DestDirPath = FPaths::GetPath(DestFile);
        if (!FPaths::DirectoryExists(DestDirPath))
        {
          FileManager.MakeDirectory(*DestDirPath, true);
        }

        if (!FileManager.Copy(*DestFile, *SourceFile, true, true))
        {
          UE_LOG(LogTemp, Error, TEXT("Error copiando %s"), *SourceFile);
          bSuccess = false;
        }

        Progress += ProgressStep;
        AsyncTask(ENamedThreads::GameThread, [Task, Progress]() {
          Task.OnProgress.ExecuteIfBound(0.6f + Progress);
          });
      }

      if (bSuccess)
      {
        FileManager.DeleteDirectory(*TransformedFBM, false, true);
      }
    }
  }

  // Notificar finalización (100%)
  AsyncTask(ENamedThreads::GameThread, [Task, bSuccess]() {
    Task.OnProgress.ExecuteIfBound(1.0f);
    Task.OnComplete.ExecuteIfBound(bSuccess);
    });
}
