using UnrealBuildTool;
using System.IO;

public class RuntimeFBXLoader : ModuleRules
{
    public RuntimeFBXLoader(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // Definir la macro para exportar la API
        PublicDefinitions.Add("RUNTIMEFBXLOADER_API");

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
                "Projects" // Para acceso a directorios
            }
        );

        // Añadir Assimp como una librería de terceros
        LoadAssimp(Target);
    }

    private void LoadAssimp(ReadOnlyTargetRules Target)
    {
        string AssimpPath = Path.Combine(ModuleDirectory, "../ThirdParty/assimp");
        string IncludePath = Path.Combine(AssimpPath, "include");
        string LibraryPath = Path.Combine(AssimpPath, "lib", Target.Platform.ToString());

        // Incluir directorios de encabezados
        PublicIncludePaths.Add(IncludePath);

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            // Cargar las bibliotecas .lib en Windows
            PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "assimp-vc143-mt.lib"));

            // Incluir las DLLs en el paquete del juego
            string BinaryPath = Path.Combine(AssimpPath, "bin", "x64");

            // Copiar las DLLs al directorio del juego
            string Destination = Path.Combine("$(ProjectDir)/Binaries/Win64/");
            CopyFile(Path.Combine(BinaryPath, "assimp-vc143-mt.dll"), Destination);
        }
    }

    private void CopyFile(string Source, string Destination)
    {
        if (!Directory.Exists(Destination))
        {
            Directory.CreateDirectory(Destination);
        }
        File.Copy(Source, Path.Combine(Destination, Path.GetFileName(Source)), true);
    }
}
