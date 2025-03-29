#include "RuntimeFBXLoaderModule.h"
#include "Interfaces/IPluginManager.h"

IMPLEMENT_MODULE(FRuntimeFBXLoaderModule, RuntimeFBXLoader)

void FRuntimeFBXLoaderModule::StartupModule()
{
  // Inicialización cuando el módulo se carga
}

void FRuntimeFBXLoaderModule::ShutdownModule()
{
  // Limpieza cuando el módulo se descarga
}
