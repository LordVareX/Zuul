// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class Metaverse_C : ModuleRules
{
	public Metaverse_C(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Sockets", "Slate", "SlateCore", "RenderCore", "UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		if(Target.Platform == UnrealTargetPlatform.Android)
		{
			var manifestFile = Path.Combine(ModuleDirectory, "AndroidSanitizePermission_UPL.xml");
			AdditionalPropertiesForReceipt.Add(Name: "AndroidPlugin", Value: manifestFile);
		}

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
