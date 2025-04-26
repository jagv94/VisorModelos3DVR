// Copyright (c) Adrián Guerra 2025. All rights reserved.

using UnrealBuildTool;

public class RuntimeMeshToNanite : ModuleRules
{
  public RuntimeMeshToNanite(ReadOnlyTargetRules Target) : base(Target)
  {
    PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
    bUseUnity = false;

    PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "MeshDescription",
            "StaticMeshDescription",
            "RenderCore",
            "RHI",
            "AssetRegistry",
            "ImportExportModels" // Añade el módulo del plugin que estás extendiendo
        });

    PrivateDependencyModuleNames.AddRange(new string[] {
            "UnrealEd", // Necesario para algunas operaciones de assets
            "NaniteBuilder" // Para soporte Nanite
        });

    if (Target.bBuildEditor)
    {
      PrivateDependencyModuleNames.AddRange(new string[] {
                "MeshUtilities",
                "MaterialUtilities"
            });
    }
  }
}
