using UnrealBuildTool;
using System.IO;

public class RuntimeFBXLoader : ModuleRules
{
  public RuntimeFBXLoader(ReadOnlyTargetRules Target) : base(Target)
  {
    PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

    // Añadir dependencias públicas y privadas necesarias para este módulo
    PublicDependencyModuleNames.AddRange(
      new string[]
      {
        "Core",
        "CoreUObject",
        "Engine",
        "RenderCore",
        "RHI", // Para renderizado de mallas
        "MeshUtilitiesCommon" // Para trabajar con UStaticMesh
      }
    );

    PrivateDependencyModuleNames.AddRange(
      new string[]
      {
        "Projects", // Para acceso a directorios
        "TextureUtilitiesCommon" // Para acceso a FTextureBuildSettings
      }
    );

    // Añadir Assimp como una librería de terceros
    LoadAssimp(Target);
  }

  private void LoadAssimp(ReadOnlyTargetRules Target)
  {
    string AssimpPath = Path.Combine(ModuleDirectory, "../ThirdParty/assimp");
    string IncludePath = Path.Combine(AssimpPath, "include");
    string LibraryPath = Path.Combine(AssimpPath, "lib", "x64");

    // Incluir directorios de encabezados
    PublicIncludePaths.Add(IncludePath);

    if (Target.Platform == UnrealTargetPlatform.Win64)
    {
      // Cargar las bibliotecas .lib en Windows
      PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "assimp-vc143-mt.lib"));
      PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "zlibstatic.lib"));

      // Incluir las DLLs en el paquete del juego
      string BinaryPath = Path.Combine(AssimpPath, "bin", "x64");

      RuntimeDependencies.Add("$(BinaryOutputDir)/assimp-vc143-mt.dll", Path.Combine(BinaryPath, "assimp-vc143-mt.dll"));
      RuntimeDependencies.Add("$(BinaryOutputDir)/zlib.dll", Path.Combine(BinaryPath, "zlib.dll"));
    }
  }
}
