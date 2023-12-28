/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "DynamoDBStreamsModule.h"
#include "DynamoDBStreamsGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "HAL/PlatformProcess.h"
#endif

#define LOCTEXT_NAMESPACE "FDynamoDBStreamsModule"

#if WITH_EDITOR
void* FDynamoDBStreamsModule::DynamoDBStreamsLibraryHandle = nullptr;
#endif

void FDynamoDBStreamsModule::StartupModule()
{
    LOG_DYNAMODBSTREAMS_NORMAL("Starting DynamoDBStreamsClient Module...");
#if WITH_EDITOR
#if PLATFORM_WINDOWS && PLATFORM_64BITS
	const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
	LOG_DYNAMODBSTREAMS_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

	const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("DynamoDBStreamsClientLibrary"), TEXT("Win64"),  TEXT("Editor"));
	LOG_DYNAMODBSTREAMS_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

	static const FString DynamoDBStreamsDLLName = "aws-cpp-sdk-dynamodbstreams";
	const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, DynamoDBStreamsDLLName, DynamoDBStreamsLibraryHandle);
	if (!bDependencyLoaded)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(DynamoDBStreamsDLLName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
		FreeDependency(DynamoDBStreamsLibraryHandle);
	}
#elif PLATFORM_MAC
    const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
    LOG_DYNAMODBSTREAMS_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

    const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("DynamoDBStreamsClientLibrary"), TEXT("Mac"),  TEXT("Editor"));
    LOG_DYNAMODBSTREAMS_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

    static const FString DynamoDBStreamsDLLName = "libaws-cpp-sdk-dynamodbstreams";
    const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, DynamoDBStreamsDLLName, DynamoDBStreamsLibraryHandle);
    if (!bDependencyLoaded)
    {
        FFormatNamedArguments Arguments;
        Arguments.Add(TEXT("Name"), FText::FromString(DynamoDBStreamsDLLName));
        FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
        FreeDependency(DynamoDBStreamsLibraryHandle);
    }
#elif PLATFORM_IOS
#endif
#endif
}

void FDynamoDBStreamsModule::ShutdownModule()
{
#if WITH_EDITOR
	FreeDependency(DynamoDBStreamsLibraryHandle);
#endif
	LOG_DYNAMODBSTREAMS_NORMAL("Shutting down DynamoDBStreams Module...");
}

#if WITH_EDITOR
bool FDynamoDBStreamsModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_DYNAMODBSTREAMS_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_DYNAMODBSTREAMS_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FDynamoDBStreamsModule::FreeDependency(void*& Handle)
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

IMPLEMENT_MODULE(FDynamoDBStreamsModule, DynamoDBStreams)
