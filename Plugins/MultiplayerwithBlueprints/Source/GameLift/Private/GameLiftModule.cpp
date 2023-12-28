/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "GameLiftModule.h"
#include "GameLiftGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "HAL/PlatformProcess.h"
#endif

#define LOCTEXT_NAMESPACE "FGameLiftModule"

#if WITH_EDITOR
void* FGameLiftModule::GameLiftLibraryHandle = nullptr;
#endif

void FGameLiftModule::StartupModule()
{
    LOG_GAMELIFT_NORMAL("Starting GameLiftClient Module...");
#if WITH_EDITOR
#if PLATFORM_WINDOWS && PLATFORM_64BITS
	const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
	LOG_GAMELIFT_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

	const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("GameLiftClientLibrary"), TEXT("Win64"),  TEXT("Editor"));
	LOG_GAMELIFT_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

	static const FString GameLiftDLLName = "aws-cpp-sdk-gamelift";
	const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, GameLiftDLLName, GameLiftLibraryHandle);
	if (!bDependencyLoaded)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(GameLiftDLLName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
		FreeDependency(GameLiftLibraryHandle);
	}
#elif PLATFORM_MAC
    const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
    LOG_GAMELIFT_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

    const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("GameLiftClientLibrary"), TEXT("Mac"),  TEXT("Editor"));
    LOG_GAMELIFT_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

    static const FString GameLiftDLLName = "libaws-cpp-sdk-gamelift";
    const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, GameLiftDLLName, GameLiftLibraryHandle);
    if (!bDependencyLoaded)
    {
        FFormatNamedArguments Arguments;
        Arguments.Add(TEXT("Name"), FText::FromString(GameLiftDLLName));
        FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
        FreeDependency(GameLiftLibraryHandle);
    }
#elif PLATFORM_IOS
#endif
#endif
}

void FGameLiftModule::ShutdownModule()
{
#if WITH_EDITOR
	FreeDependency(GameLiftLibraryHandle);
#endif
	LOG_GAMELIFT_NORMAL("Shutting down GameLift Module...");
}

#if WITH_EDITOR
bool FGameLiftModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_GAMELIFT_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_GAMELIFT_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FGameLiftModule::FreeDependency(void*& Handle)
{
#if !PLATFORM_LINUX && !PLATFORM_ANDROID && !PLATFORM_IOS
	if (Handle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(Handle);
		Handle = nullptr;
	}
#endif
}
#endif

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameLiftModule, GameLift)
