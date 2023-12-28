// Copyright (c) 2022 King Wai Mark



#include "FBPApp.h"



firebase::App* UFBPApp::FBPGet()
{
	if(firebase::App::GetInstance() == nullptr)
	{
		FBPConnectToFirebase();
	}
	return firebase::App::GetInstance();
}


bool UFBPApp::HaveDatabaseInfo(FString Msg)
{
	if(UFBPApp::FBPGet()->options().database_url() == nullptr || std::strlen(UFBPApp::FBPGet()->options().database_url()) < 3) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, Msg);
		return false;
	}

	return true;
}

bool UFBPApp::FBPConnectToFirebase()
{
#if PLATFORM_WINDOWS
	firebase::AppOptions Options = firebase::AppOptions();
	const FString GoogleServicesString = UFBPFileUtilities::ReadGoogleServicesJSONFile("google-services.json");
	if(UFBPFileUtilities::HasGoogleFile)
	{
		const TSharedPtr<FJsonObject> GoogleServicesJSON = UFBPFileUtilities::FStringToJSON(GoogleServicesString);
		const char* APIKey = Options.api_key();
		const char* AppId = Options.app_id();
		const char* DatabaseUrl = Options.database_url();
		const char* ProjectId = Options.project_id();
		const char* StorageBucket = Options.storage_bucket();
		const char* MessagingSenderId = Options.messaging_sender_id();
		const char* ClientId = Options.client_id(); 
		if(APIKey == nullptr || std::strlen(APIKey) <= 0){ Options.set_api_key(TCHAR_TO_ANSI(*GoogleServicesJSON->GetArrayField("client")[0]->AsObject()->GetArrayField("api_key")[0]->AsObject()->GetStringField("current_key"))); }
		if(AppId == nullptr || std::strlen(AppId) <= 0){ Options.set_app_id(TCHAR_TO_ANSI(*GoogleServicesJSON->GetArrayField("client")[0]->AsObject()->GetObjectField("client_info")->GetStringField("mobilesdk_app_id"))); }
		if(DatabaseUrl == nullptr || std::strlen(DatabaseUrl) <= 0){ Options.set_database_url(TCHAR_TO_ANSI(*GoogleServicesJSON->GetObjectField("project_info")->GetStringField("firebase_url"))); }
		if(ProjectId == nullptr || std::strlen(ProjectId) <= 0){ Options.set_project_id(TCHAR_TO_ANSI(*GoogleServicesJSON->GetObjectField("project_info")->GetStringField("project_id"))); }
		if(StorageBucket == nullptr || std::strlen(StorageBucket) <= 0) { Options.set_storage_bucket(TCHAR_TO_ANSI(*GoogleServicesJSON->GetObjectField("project_info")->GetStringField("storage_bucket"))); }
		if(MessagingSenderId == nullptr || std::strlen(MessagingSenderId) <= 0) { Options.set_messaging_sender_id(TCHAR_TO_ANSI(*GoogleServicesJSON->GetObjectField("project_info")->GetStringField("project_number"))); }
		if(ClientId == nullptr || std::strlen(ClientId) <= 0) { 
			if (GoogleServicesJSON->GetArrayField("client")[0]->AsObject().IsValid() && !GoogleServicesJSON->GetArrayField("client")[0]->AsObject()->GetArrayField("oauth_client").IsEmpty()) {
				Options.set_client_id(TCHAR_TO_ANSI(*GoogleServicesJSON->GetArrayField("client")[0]->AsObject()->GetArrayField("oauth_client")[0]->AsObject()->GetStringField("client_id")));
			}
		}		
		firebase::App::Create(Options);
	}

#elif PLATFORM_ANDROID
	firebase::App::Create(firebase::AppOptions(), FAndroidApplication::GetJavaEnv(true), FJavaWrapper::GameActivityThis);
	UFBPFileUtilities::HasGoogleFile = true;

	
#elif PLATFORM_MAC || PLATFORM_IOS
	
	firebase::AppOptions Options = firebase::AppOptions();
	TMap<FString, FString> GoogleServiceInfoPlist = UFBPFileUtilities::ReadGoogleServicesPLISTFile("GoogleService-Info.plist");
	if(UFBPFileUtilities::HasGoogleFile)
	{
		const char* APIKey = Options.api_key();
		const char* AppId = Options.app_id();
		const char* DatabaseUrl = Options.database_url();
		const char* ProjectId = Options.project_id();
		const char* StorageBucket = Options.storage_bucket();
		const char* MessagingSenderId = Options.messaging_sender_id();
		const char* ClientId = Options.client_id();
		const char* BundleId = Options.package_name();
		if(APIKey == nullptr || std::strlen(APIKey) <= 0){ Options.set_api_key(TCHAR_TO_ANSI(*GoogleServiceInfoPlist.FindRef("API_KEY"))); }
		if(AppId == nullptr || std::strlen(AppId) <= 0){ Options.set_app_id(TCHAR_TO_ANSI(*GoogleServiceInfoPlist.FindRef("GOOGLE_APP_ID"))); }
		if(DatabaseUrl == nullptr || std::strlen(DatabaseUrl) <= 0){ Options.set_database_url(TCHAR_TO_ANSI(*GoogleServiceInfoPlist.FindRef("DATABASE_URL"))); }
		if(ProjectId == nullptr || std::strlen(ProjectId) <= 0){ Options.set_project_id(TCHAR_TO_ANSI(*GoogleServiceInfoPlist.FindRef("PROJECT_ID"))); }
		if(StorageBucket == nullptr || std::strlen(StorageBucket) <= 0) { Options.set_storage_bucket(TCHAR_TO_ANSI(*GoogleServiceInfoPlist.FindRef("STORAGE_BUCKET"))); }
		if(MessagingSenderId == nullptr || std::strlen(MessagingSenderId) <= 0) { Options.set_messaging_sender_id(TCHAR_TO_ANSI(*GoogleServiceInfoPlist.FindRef("GCM_SENDER_ID"))); }
		if(ClientId == nullptr || std::strlen(ClientId) <= 0) { Options.set_client_id(TCHAR_TO_ANSI(*GoogleServiceInfoPlist.FindRef("CLIENT_ID"))); }
		if(BundleId == nullptr || std::strlen(BundleId) <= 0) { Options.set_package_name(TCHAR_TO_ANSI(*GoogleServiceInfoPlist.FindRef("BUNDLE_ID"))); }
		firebase::App::Create(Options);
	}

#endif

	
	if(firebase::App::GetInstance() != nullptr)
	{
		return true;
	}
	return false;
}

FBPAppData UFBPApp::FBPGetAppInfo()
{
	FBPAppData Data = FBPAppData();
	firebase::App* App = firebase::App::GetInstance();
	if(App != nullptr)
	{
		Data.ApiKey = App->options().api_key();
		Data.AppId = App->options().app_id();
		Data.DatabaseUrl = App->options().database_url();
		Data.ProjectId = App->options().project_id();
		Data.StorageBucket = App->options().storage_bucket();
		Data.MessagingSenderId = App->options().messaging_sender_id();
		Data.ClientId = App->options().client_id();
	}

	return Data;
}
