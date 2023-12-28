/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "DynamoDBModule.h"
#include "DynamoDBGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "HAL/PlatformProcess.h"
#endif

#define LOCTEXT_NAMESPACE "FDynamoDBModule"

#if WITH_EDITOR
void* FDynamoDBModule::DynamoDBLibraryHandle = nullptr;
#endif

void FDynamoDBModule::StartupModule()
{
    LOG_DYNAMODB_NORMAL("Starting DynamoDBClient Module...");
#if WITH_EDITOR
#if PLATFORM_WINDOWS && PLATFORM_64BITS
	const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
	LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

	const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("DynamoDBClientLibrary"), TEXT("Win64"),  TEXT("Editor"));
	LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

	static const FString DynamoDBDLLName = "aws-cpp-sdk-dynamodb";
	const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, DynamoDBDLLName, DynamoDBLibraryHandle);
	if (!bDependencyLoaded)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(DynamoDBDLLName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
		FreeDependency(DynamoDBLibraryHandle);
	}
#elif PLATFORM_MAC
    const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
    LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

    const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("DynamoDBClientLibrary"), TEXT("Mac"),  TEXT("Editor"));
    LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

    static const FString DynamoDBDLLName = "libaws-cpp-sdk-dynamodb";
    const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, DynamoDBDLLName, DynamoDBLibraryHandle);
    if (!bDependencyLoaded)
    {
        FFormatNamedArguments Arguments;
        Arguments.Add(TEXT("Name"), FText::FromString(DynamoDBDLLName));
        FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
        FreeDependency(DynamoDBLibraryHandle);
    }
#elif PLATFORM_IOS
#endif
#endif
}

void FDynamoDBModule::ShutdownModule()
{
#if WITH_EDITOR
	FreeDependency(DynamoDBLibraryHandle);
#endif
	LOG_DYNAMODB_NORMAL("Shutting down DynamoDB Module...");
}

#if WITH_EDITOR
bool FDynamoDBModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_DYNAMODB_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FDynamoDBModule::FreeDependency(void*& Handle)
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

IMPLEMENT_MODULE(FDynamoDBModule, DynamoDB)
