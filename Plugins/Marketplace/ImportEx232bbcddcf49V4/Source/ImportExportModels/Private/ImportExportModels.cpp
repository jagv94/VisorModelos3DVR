// Copyright 2023 Jack Chen. All Rights Reserved.

#include "ImportExportModels.h"
#include "Core.h"
#include "Modules/ModuleManager.h"

//#include "HAL/Platform.h"

#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/PreWindowsApi.h"

//#include "Windows/WIndowsPlatform.h"

#include "Windows/PostWindowsApi.h"
#include "Windows/HideWindowsPlatformTypes.h"

#define LOCTEXT_NAMESPACE "FImportExportModelsModule"

void FImportExportModelsModule::StartupModule()
{
	FString LibraryPath;

#if PLATFORM_WINDOWS
	/*#if _WIN64
		LibraryPath = FPaths::Combine(*ProjectPluginsDir, TEXT("ImportModelRuntime/Source/ThirdParty/assimp/bin/Win64/assimp-vc140-mt.dll"));
	#elif _WIN32
		LibraryPath = FPaths::Combine(*ProjectPluginsDir, TEXT("ImportModelRuntime/Source/ThirdParty/assimp/bin/Win32/assimp-vc140-mt.dll"));
	#endif*/

	LibraryPath = FPaths::Combine(*(IPluginManager::Get().FindPlugin("ImportExportModels")->GetBaseDir()), TEXT("Source/ThirdParty/assimp/bin/Win64/assimp-vc142-mt.dll"));

#endif // PLATFORM_WINDOWS

	LibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
}

void FImportExportModelsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FImportExportModelsModule, ImportExportModels)