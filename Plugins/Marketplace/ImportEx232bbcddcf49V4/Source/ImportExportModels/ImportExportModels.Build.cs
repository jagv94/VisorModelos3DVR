// Copyright 2023 Jack Chen. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class ImportExportModels : ModuleRules
{
	private string ModulePath
	{
		get { return ModuleDirectory; }
	}

	private string ThirdPartyPath
	{
		get { return Path.GetFullPath(Path.Combine(ModulePath, "../ThirdParty/")); }
	}

	public ImportExportModels(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicDefinitions.Add("IMPORTEXPORTLIBRARY_EXPORTS=0");

		// ��ӹ���Ԥ����������  
		//PublicDefinitions.Add("MY_PUBLIC_MACRO=1");

		// ���˽��Ԥ����������  
		//PrivateDefinitions.Add("MY_PRIVATE_MACRO=1");

		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bEnableUndefinedIdentifierWarnings = false;

		PublicIncludePaths.AddRange(
			new string[] {
				Path.Combine(ThirdPartyPath, "assimp/include")
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"RHI",
				"RenderCore",
				"ProceduralMeshComponent",
				"Projects"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"ProceduralMeshComponent"
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

        if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string PlatformString = "Win64";

            // ��ӿ��ļ�������·��  
            PublicSystemLibraryPaths.Add(Path.Combine(ThirdPartyPath, "assimp/lib", PlatformString)); // ������ļ�������

            PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "assimp/lib", PlatformString, "ImportExportModelsLib.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "assimp/lib", PlatformString, "assimp-vc142-mt.lib"));
			
			PublicDelayLoadDLLs.Add("assimp-vc142-mt.dll");

			RuntimeDependencies.Add(Path.Combine(ThirdPartyPath, "assimp/bin", PlatformString, "assimp-vc142-mt.dll"));
		}
	}
}
