// Copyright Pandores Marketplace 2023. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class OneSignal : ModuleRules
{
	public OneSignal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		// Module includes
		PublicIncludePaths .Add(Path.Combine(ModuleDirectory, "Public"));
		PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

		// Public Engine's dependencies.
		PublicDependencyModuleNames.Add("Core");
			
		// Private Engine's dependencies.
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"CoreUObject",
			"Engine",
			"Json",
		});

		// Android specific build config.
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			// Android's UPL file.
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "UPL/OneSignal.android.upl.xml"));

			// Android Engine's dependencies.
			PrivateDependencyModuleNames.AddRange(new string[] 
			{ 
				"Launch",
			});
		}

		// iOS specific build config.
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			// iOS' UPL file.
			AdditionalPropertiesForReceipt.Add("IOSPlugin", Path.Combine(ModuleDirectory, "OneSignal.ios.upl.xml"));

			// Adds the OneSignal SDK's framework.
			PublicAdditionalFrameworks.Add(new Framework("OneSignal", Path.Combine(PluginDirectory, "Source/ThirdParty/OneSignalSDK/ios/OneSignal.framework.zip")));

			// Adds the OneSignal's includes.
			PrivateIncludePaths.Add(Path.Combine(PluginDirectory, "Source/ThirdParty/OneSignalSDK/ios/inc"));

			// Required system frameworks.
			PublicFrameworks.AddRange(new string[]
			{
				"CoreGraphics",
				"SystemConfiguration",
				"UIKit",
				"UserNotifications",
				"WebKit",
			});
		}
	}
}
