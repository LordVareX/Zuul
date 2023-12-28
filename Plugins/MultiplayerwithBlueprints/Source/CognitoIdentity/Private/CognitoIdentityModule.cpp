/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "CognitoIdentityModule.h"
#include "CognitoIdentityGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "HAL/PlatformProcess.h"
#endif

#define LOCTEXT_NAMESPACE "FCognitoIdentityModule"

#if WITH_EDITOR
void* FCognitoIdentityModule::CognitoIdentityLibraryHandle = nullptr;
#endif

void FCognitoIdentityModule::StartupModule()
{
    LOG_COGNITOIDENTITY_NORMAL("Starting CognitoIdentityClient Module...");
#if WITH_EDITOR
#if PLATFORM_WINDOWS && PLATFORM_64BITS
	const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
	LOG_COGNITOIDENTITY_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

	const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("CognitoIdentityClientLibrary"), TEXT("Win64"),  TEXT("Editor"));
	LOG_COGNITOIDENTITY_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

	static const FString CognitoIdentityDLLName = "aws-cpp-sdk-cognito-identity";
	const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, CognitoIdentityDLLName, CognitoIdentityLibraryHandle);
	if (!bDependencyLoaded)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(CognitoIdentityDLLName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
		FreeDependency(CognitoIdentityLibraryHandle);
	}
#elif PLATFORM_MAC
    const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
    LOG_COGNITOIDENTITY_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

    const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("CognitoIdentityClientLibrary"), TEXT("Mac"),  TEXT("Editor"));
    LOG_COGNITOIDENTITY_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

    static const FString CognitoIdentityDLLName = "libaws-cpp-sdk-cognito-identity";
    const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, CognitoIdentityDLLName, CognitoIdentityLibraryHandle);
    if (!bDependencyLoaded)
    {
        FFormatNamedArguments Arguments;
        Arguments.Add(TEXT("Name"), FText::FromString(CognitoIdentityDLLName));
        FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
        FreeDependency(CognitoIdentityLibraryHandle);
    }
#elif PLATFORM_IOS
#endif
#endif
}

void FCognitoIdentityModule::ShutdownModule()
{
#if WITH_EDITOR
	FreeDependency(CognitoIdentityLibraryHandle);
#endif
	LOG_COGNITOIDENTITY_NORMAL("Shutting down CognitoIdentity Module...");
}

#if WITH_EDITOR
bool FCognitoIdentityModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_COGNITOIDENTITY_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

    LOG_COGNITOIDENTITY_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FCognitoIdentityModule::FreeDependency(void*& Handle)
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

IMPLEMENT_MODULE(FCognitoIdentityModule, CognitoIdentity)
