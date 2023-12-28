/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "LambdaModule.h"
#include "LambdaGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "HAL/PlatformProcess.h"
#endif

#define LOCTEXT_NAMESPACE "FLambdaModule"

#if WITH_EDITOR
void* FLambdaModule::LambdaLibraryHandle = nullptr;
#endif

void FLambdaModule::StartupModule()
{
    LOG_LAMBDA_NORMAL("Starting LambdaClient Module...");
#if WITH_EDITOR
#if PLATFORM_WINDOWS && PLATFORM_64BITS
	const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
	LOG_LAMBDA_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

	const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("LambdaClientLibrary"), TEXT("Win64"),  TEXT("Editor"));
	LOG_LAMBDA_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

	static const FString LambdaDLLName = "aws-cpp-sdk-lambda";
	const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, LambdaDLLName, LambdaLibraryHandle);
	if (!bDependencyLoaded)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(LambdaDLLName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
		FreeDependency(LambdaLibraryHandle);
	}
#elif PLATFORM_MAC
    const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
    LOG_LAMBDA_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

    const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("LambdaClientLibrary"), TEXT("Mac"),  TEXT("Editor"));
    LOG_LAMBDA_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

    static const FString LambdaDLLName = "libaws-cpp-sdk-lambda";
    const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, LambdaDLLName, LambdaLibraryHandle);
    if (!bDependencyLoaded)
    {
        FFormatNamedArguments Arguments;
        Arguments.Add(TEXT("Name"), FText::FromString(LambdaDLLName));
        FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
        FreeDependency(LambdaLibraryHandle);
    }
#elif PLATFORM_IOS
#endif
#endif
}

void FLambdaModule::ShutdownModule()
{
#if WITH_EDITOR
	FreeDependency(LambdaLibraryHandle);
#endif
	LOG_LAMBDA_NORMAL("Shutting down Lambda Module...");
}

#if WITH_EDITOR
bool FLambdaModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_LAMBDA_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_LAMBDA_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FLambdaModule::FreeDependency(void*& Handle)
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

IMPLEMENT_MODULE(FLambdaModule, Lambda)
