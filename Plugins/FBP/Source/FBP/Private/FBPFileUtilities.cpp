// Copyright (c) 2022 King Wai Mark

#include "FBPFileUtilities.h"

bool UFBPFileUtilities::HasGoogleFile = false;

FString UFBPFileUtilities::ReadGoogleServicesJSONFile(FString FileName)
{
#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_IOS
	FString JsonProjectDirFile = FPaths::ProjectDir().Append(FileName);
	FString JsonLaunchDirFile = FPaths::LaunchDir().Append(FileName);
	FString JsonWin64LaunchDirFile = FPaths::LaunchDir().Append(FString(TCHAR_TO_ANSI(FApp::GetProjectName())) + "/Binaries/Win64/" + FileName);
	FString JsonWin32LaunchDirFile = FPaths::LaunchDir().Append(FString(TCHAR_TO_ANSI(FApp::GetProjectName())) + "/Binaries/Win32/" + FileName);
	

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	FString FileContent;
	UFBPFileUtilities::HasGoogleFile = true;

	if(FileManager.FileExists(*JsonProjectDirFile))
	{
		if(FFileHelper::LoadFileToString(FileContent,*JsonProjectDirFile, FFileHelper::EHashOptions::None))
		{
			return FileContent;
		}
	}
	else if(FileManager.FileExists(*JsonLaunchDirFile))
	{
		if(FFileHelper::LoadFileToString(FileContent,*JsonLaunchDirFile, FFileHelper::EHashOptions::None))
		{
			return FileContent;
		}
	}
	else if(FileManager.FileExists(*JsonWin64LaunchDirFile))
	{
		if(FFileHelper::LoadFileToString(FileContent,*JsonWin64LaunchDirFile, FFileHelper::EHashOptions::None))
		{
			return FileContent;
		}
	}
	else if(FileManager.FileExists(*JsonWin32LaunchDirFile))
	{
		if(FFileHelper::LoadFileToString(FileContent,*JsonWin32LaunchDirFile, FFileHelper::EHashOptions::None))
		{
			return FileContent;
		}
	}
	else
	{
		UFBPFileUtilities::HasGoogleFile = false;
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, TEXT("[FBP] Google Services JSON file not found."));
		UE_LOG(LogTemp, Warning, TEXT("[FBP] Google Services JSON file not found."));
	}
#endif
	return "";
}

TMap<FString, FString>  UFBPFileUtilities::ReadGoogleServicesPLISTFile(FString FileName)
{
	TMap<FString, FString> Map = TMap<FString, FString>();
#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_IOS
	FString PlistProjectDirFile = FPaths::ProjectDir().Append(FileName);
	FString PlistLaunchDirFile = FPaths::LaunchDir().Append(FileName);
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	FXmlFile GoogleServicesInfoPlist;
	UFBPFileUtilities::HasGoogleFile = true;
	if(FileManager.FileExists(*PlistProjectDirFile))
	{
		GoogleServicesInfoPlist.LoadFile(PlistProjectDirFile);
	}
	else if(FileManager.FileExists(*PlistLaunchDirFile))
	{
		GoogleServicesInfoPlist.LoadFile(PlistLaunchDirFile);
	} else
	{
		UFBPFileUtilities::HasGoogleFile = false;
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::White, TEXT("[FBP] Google Services Info Plist file not found."));
		UE_LOG(LogTemp, Warning, TEXT("[FBP] Google Services Info Plist file not found."));
	}

	if(GoogleServicesInfoPlist.IsValid())
	{
		const FXmlNode* GoogleServicesInfoPlistRoot = GoogleServicesInfoPlist.GetRootNode();
		const FXmlNode* FirebaseSettingsDictPlistNode = GoogleServicesInfoPlistRoot->GetFirstChildNode();
		const FXmlNode* KeyItemNode = FirebaseSettingsDictPlistNode->GetFirstChildNode();
		while (KeyItemNode)
		{
			FString KeyItemNodeContent = KeyItemNode->GetContent();
			const FXmlNode* ValueItemNode = KeyItemNode->GetNextNode();
			if (ValueItemNode->GetTag() == TEXT("string"))
			{
				FString ValueItemNodeContent = ValueItemNode->GetContent();
				Map.Add(KeyItemNodeContent, ValueItemNodeContent);
			}

			KeyItemNode = ValueItemNode->GetNextNode();
		}
	} else
	{
		UE_LOG(LogTemp, Warning, TEXT("[FBP] Invalid Plist File."));
	}
	
	UE_LOG(LogTemp, Warning, TEXT("FBP %s"), *Map.FindRef("CLIENT_ID"));
	UE_LOG(LogTemp, Warning, TEXT("FBP %s"), *Map.FindRef("REVERSED_CLIENT_ID"));
	UE_LOG(LogTemp, Warning, TEXT("FBP %s"), *Map.FindRef("API_KEY"));
	UE_LOG(LogTemp, Warning, TEXT("FBP %s"), *Map.FindRef("GCM_SENDER_ID"));
	UE_LOG(LogTemp, Warning, TEXT("FBP %s"), *Map.FindRef("BUNDLE_ID"));
	UE_LOG(LogTemp, Warning, TEXT("FBP %s"), *Map.FindRef("PROJECT_ID"));
	UE_LOG(LogTemp, Warning, TEXT("FBP %s"), *Map.FindRef("STORAGE_BUCKET"));
	UE_LOG(LogTemp, Warning, TEXT("FBP %s"), *Map.FindRef("GOOGLE_APP_ID"));
	UE_LOG(LogTemp, Warning, TEXT("FBP %s"), *Map.FindRef("DATABASE_URL"));
#endif
	return Map;
}

TSharedPtr<FJsonObject> UFBPFileUtilities::FStringToJSON(FString Str)
{
	TSharedPtr<FJsonObject> JsonParsed;
#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_IOS
	const TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Str);
	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed)) {
		
		return JsonParsed;
	}
#endif
	return JsonParsed;
}
