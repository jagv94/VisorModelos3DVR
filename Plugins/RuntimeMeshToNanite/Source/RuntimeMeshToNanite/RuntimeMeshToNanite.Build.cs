// Copyright (c) Adrián Guerra 2025. All rights reserved.

using UnrealBuildTool;

public class RuntimeMeshToNanite : ModuleRules
{
  public RuntimeMeshToNanite(ReadOnlyTargetRules Target) : base(Target)
  {
    PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
    bUseUnity = false;

    // Necesario para la generación de código
    PublicIncludePaths.AddRange(
        new string[] {
                ModuleDirectory + "/Public"
        }
    );

    PublicDependencyModuleNames.AddRange(new string[] {
      "Core",
      "CoreUObject",
      "Engine",
      "MeshDescription",
      "StaticMeshDescription",
      "RenderCore",
      "RHI",
      "AssetRegistry",
      "ImportExportModels"
    });

    PrivateDependencyModuleNames.AddRange(new string[] {
      "UnrealEd",
      "NaniteBuilder",
      "Slate",
      "SlateCore",
      "Projects",
      "UMG"
    });

    if (Target.bBuildEditor)
    {
      PrivateDependencyModuleNames.AddRange(new string[] {
        "MeshUtilities",
        "MaterialUtilities",
        "MaterialBaking",
        "UnrealEd"
      });
    }

    // Configuración adicional para generación de código
    bEnableUndefinedIdentifierWarnings = false;
    ShadowVariableWarningLevel = WarningLevel.Off;
  }
}
