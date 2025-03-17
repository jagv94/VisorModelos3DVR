using UnrealBuildTool;
using System.IO;

public class RuntimeFBXLoader : ModuleRules
{
    public RuntimeFBXLoader(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "RenderCore",
            "RHI",
            "MeshUtilities",
            "NaniteBuilder"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        // Ruta a Assimp
        string AssimpPath = Path.Combine(ModuleDirectory, "../ThirdParty/assimp/");
        string AssimpLibPath = Path.Combine(AssimpPath, "lib", "Win64");
        string AssimpBinPath = Path.Combine(AssimpPath, "bin", "Win64");

        // Incluir cabeceras de Assimp
        PublicIncludePaths.Add(Path.Combine(AssimpPath, "include"));
        PublicIncludePaths.Add(Path.Combine(AssimpPath, "include", "assimp")); // Agregar subcarpeta correcta

        // Agregar librerías de Assimp
        PublicAdditionalLibraries.Add(Path.Combine(AssimpLibPath, "assimp-vc143-mt.lib"));

        // Copiar DLLs necesarias a Binaries
        string AssimpDLL = Path.Combine(AssimpBinPath, "assimp-vc143-mt.dll");

        if (File.Exists(AssimpDLL))
        {
            RuntimeDependencies.Add(AssimpDLL);
            RuntimeDependencies.Add("$(BinaryOutputDir)/assimp-vc143-mt.dll", AssimpDLL);
        }
        else
        {
            throw new BuildException("No se encontró la DLL de Assimp en: " + AssimpDLL);
        }
    }
}