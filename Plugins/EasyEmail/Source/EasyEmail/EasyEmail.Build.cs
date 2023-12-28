// Copyright Pandores Marketplace 2023. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class EasyEmail : ModuleRules
{
	public EasyEmail(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.Add("Core");
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Sockets",
				"SSL", 
				"OpenSSL"
			}
		);

		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
	}
}
