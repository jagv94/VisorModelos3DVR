using static UnrealBuildTool.ModuleRules;
using System.IO;
using UnrealBuildTool;

public class RuntimeFBXLoader : ModuleRules
{
  public RuntimeFBXLoader(ReadOnlyTargetRules Target) : base(Target)
  {
    PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
    bUseRTTI = true;  // Necesario para Assimp

    PublicDependencyModuleNames.AddRange(
    new string[]
    {
        "Core",
        "CoreUObject",
        "Engine",
        "RenderCore",
        "RHI",
        "MeshDescription",
        "StaticMeshDescription"
    }
);

    PrivateDependencyModuleNames.AddRange(
        new string[]
        {
        "Projects",
        "StaticMeshDescriptionOperations",
        "MeshUtilitiesCommon"
        }
    );

    // Configuración de Assimp
    LoadAssimp(Target);
  }

  private void LoadAssimp(ReadOnlyTargetRules Target)
  {
    string AssimpPath = Path.Combine(ModuleDirectory, "../ThirdParty/assimp");
    string IncludePath = Path.Combine(AssimpPath, "include");
    string LibraryPath = Path.Combine(AssimpPath, "lib", "x64");

    PublicIncludePaths.Add(IncludePath);

    if (Target.Platform == UnrealTargetPlatform.Win64)
    {
      PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "assimp-vc143-mt.lib"));
      PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "zlibstatic.lib"));

      string BinaryPath = Path.Combine(AssimpPath, "bin", "x64");
      RuntimeDependencies.Add("$(BinaryOutputDir)/assimp-vc143-mt.dll", Path.Combine(BinaryPath, "assimp-vc143-mt.dll"));
      RuntimeDependencies.Add("$(BinaryOutputDir)/zlib.dll", Path.Combine(BinaryPath, "zlib.dll"));
    }
  }
}
