/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "CognitoIdpModule.h"
#include "CognitoIdpGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "HAL/PlatformProcess.h"
#endif

#define LOCTEXT_NAMESPACE "FCognitoIdpModule"

#if WITH_EDITOR
void* FCognitoIdpModule::CognitoIdpLibraryHandle = nullptr;
#endif

void FCognitoIdpModule::StartupModule()
{
    LOG_COGNITOIDP_NORMAL("Starting CognitoIdpClient Module...");
#if WITH_EDITOR
#if PLATFORM_WINDOWS && PLATFORM_64BITS
	const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
	LOG_COGNITOIDP_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

	const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("CognitoIdpClientLibrary"), TEXT("Win64"),  TEXT("Editor"));
	LOG_COGNITOIDP_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

	static const FString CognitoIdpDLLName = "aws-cpp-sdk-cognito-idp";
	const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, CognitoIdpDLLName, CognitoIdpLibraryHandle);
	if (!bDependencyLoaded)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(CognitoIdpDLLName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
		FreeDependency(CognitoIdpLibraryHandle);
	}
#elif PLATFORM_MAC
    const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
    LOG_COGNITOIDP_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

    const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("CognitoIdpClientLibrary"), TEXT("Mac"),  TEXT("Editor"));
    LOG_COGNITOIDP_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

    static const FString CognitoIdpDLLName = "libaws-cpp-sdk-cognito-idp";
    const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, CognitoIdpDLLName, CognitoIdpLibraryHandle);
    if (!bDependencyLoaded)
    {
        FFormatNamedArguments Arguments;
        Arguments.Add(TEXT("Name"), FText::FromString(CognitoIdpDLLName));
        FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
        FreeDependency(CognitoIdpLibraryHandle);
    }
#elif PLATFORM_IOS
#endif
#endif
}

void FCognitoIdpModule::ShutdownModule()
{
#if WITH_EDITOR
	FreeDependency(CognitoIdpLibraryHandle);
#endif
	LOG_COGNITOIDP_NORMAL("Shutting down CognitoIdp Module...");
}

#if WITH_EDITOR
bool FCognitoIdpModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_COGNITOIDP_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_COGNITOIDP_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FCognitoIdpModule::FreeDependency(void*& Handle)
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

IMPLEMENT_MODULE(FCognitoIdpModule, CognitoIdp)
