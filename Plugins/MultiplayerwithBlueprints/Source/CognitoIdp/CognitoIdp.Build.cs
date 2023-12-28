/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

using System.IO;
using UnrealBuildTool;

public class CognitoIdp : ModuleRules
{
    public CognitoIdp(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivatePCHHeaderFile = "Private/CognitoIdpPrivatePCH.h";

        bEnforceIWYU = true;
        bEnableExceptions = true;
        
        AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenSSL");

        PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject", "InputCore", "Projects", "HTTP", "SSL", "Json", "JsonUtilities", "AWSCore", "AWSCoreLibrary", "CognitoIdpClientLibrary" });

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

        if (Target.Type != TargetRules.TargetType.Server)
        {
            if (Target.Platform == UnrealTargetPlatform.Linux || Target.Platform == UnrealTargetPlatform.LinuxArm64 || Target.Platform == UnrealTargetPlatform.Android || Target.Platform == UnrealTargetPlatform.Win64 || Target.Platform == UnrealTargetPlatform.Mac || Target.Platform == UnrealTargetPlatform.IOS)
            {
                PublicDefinitions.Add("WITH_COGNITOIDPCLIENTSDK=1");
            }
            else
            {
                PublicDefinitions.Add("WITH_COGNITOIDPCLIENTSDK=0");
            }
        }
        else
        {
            PublicDefinitions.Add("WITH_COGNITOIDPCLIENTSDK=0");
        }
    }
}
