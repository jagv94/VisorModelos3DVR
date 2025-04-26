// Copyright 2023 Jack Chen. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FImportExportModelsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void* LibraryHandle;
};
