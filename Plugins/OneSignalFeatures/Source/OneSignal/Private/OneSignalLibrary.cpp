// Copyright Pandores Marketplace 2023. All Rights Reserved.

#include "OneSignal/OneSignalLibrary.h"
#include "Async/Async.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Launch/Resources/Version.h"

#if PLATFORM_IOS
#	import <OneSignal/OneSignal.h>
#	include "IOS/IOSAppDelegate.h"
#	include "IOS/OneSignalObservers.h"
#endif

#if PLATFORM_ANDROID
#	include "Android/AndroidJavaEnv.h"
#	include "Android/AndroidJNI.h"
#	include "Android/AndroidApplication.h"
#endif

DECLARE_LOG_CATEGORY_CLASS(LogOneSignal, Log, All);

ONESIGNAL_DESTRUCTOR(NotificationAction);
ONESIGNAL_DESTRUCTOR(DeviceState);
ONESIGNAL_DESTRUCTOR(Notification);

#if PLATFORM_IOS
static FOneSignalOutcomeEvent ConvertOutcomeEvent(OSOutcomeEvent* outcome)
{
	FOneSignalOutcomeEvent Outcome;

	Outcome.Session = (EOneSignalInfluenceType)outcome.session;
	Outcome.Name = outcome.name;
	Outcome.Timestamp = [outcome.timestamp longLongValue];
	Outcome.Weight = [outcome.weight doubleValue];

	Outcome.NotificationIDs.Reserve([outcome.notificationIds count]);

	for (NSString* notificationId in outcome.notificationIds)
	{
		Outcome.NotificationIDs.Add(notificationId);
	}

	return Outcome;
}
#endif

#if PLATFORM_ANDROID
static bool IsNull(JNIEnv* Env, jobject InObject)
{
	return InObject == NULL || Env->IsSameObject(InObject, NULL);
}

jclass GetGameActivityClass()
{
	static jobject GameActivity = nullptr;
	
	if (GameActivity == nullptr)
	{
		JNIEnv* const Env = AndroidJavaEnv::GetJavaEnv();

		check(Env);

#if ENGINE_MAJOR_VERSION >= 5
		jclass jActivityClass = AndroidJavaEnv::FindJavaClass("com/epicgames/unreal/GameActivity");
#else
		jclass jActivityClass = AndroidJavaEnv::FindJavaClass("com/epicgames/ue4/GameActivity");
#endif
		check(jActivityClass);

		GameActivity = (jclass)Env->NewGlobalRef((jobject)jActivityClass);
		Env->DeleteLocalRef(jActivityClass);
	}
	
	return (jclass)GameActivity;
}

static FScopedJavaObject<jstring> ToJavaString(const FString& InString)
{
	return FJavaHelper::ToJavaString(AndroidJavaEnv::GetJavaEnv(), InString);
}

#define CALL_ACTIVITY_METHOD(Name, Signature, Type, Default, ...)															\
	[&]()																													\
	{																														\
		JNIEnv* const Env = AndroidJavaEnv::GetJavaEnv();																	\
																															\
		if (!Env)																											\
		{																													\
			UE_LOG(LogOneSignal, Error, TEXT("Failed to get Env."));														\
			return Default;																									\
		}																													\
																															\
		static jmethodID jMethod = Env->GetMethodID(GetGameActivityClass(), Name, Signature);								\
																															\
		if (Env->ExceptionCheck())																							\
		{																													\
			UE_LOG(LogOneSignal, Error, TEXT("Failed to get method \"") TEXT(Name) TEXT(Signature) TEXT("\"."));			\
			Env->ExceptionDescribe();																						\
			Env->ExceptionClear();																							\
			return Default;																									\
		}																													\
																															\
		auto Result = Env->Call ## Type ## Method(AndroidJavaEnv::GetGameActivityThis(), jMethod, ## __VA_ARGS__);			\
		if (Env->ExceptionCheck())																							\
		{																													\
			UE_LOG(LogOneSignal, Error, TEXT("Exception thrown while calling method."));									\
			Env->ExceptionDescribe();																						\
			Env->ExceptionClear();																							\
			return Default;																									\
		}																													\
		return Result;																										\
	}()		

#define CALL_ACTIVITY_STRING_METHOD(Name, Signature, ...) \
	(FJavaHelper::FStringFromLocalRef(AndroidJavaEnv::GetJavaEnv(), (jstring)CALL_ACTIVITY_METHOD(Name, Signature, Object, (jobject)nullptr, ## __VA_ARGS__)))

#define CALL_ACTIVITY_BOOL_METHOD(Name, Signature, ...) \
	(bool)CALL_ACTIVITY_METHOD(Name, Signature, Boolean, (jboolean)false, ## __VA_ARGS__)

#define CALL_ACTIVITY_VOID_METHOD(Name, Signature, ...)																		\
	[&]()																													\
	{																														\
		JNIEnv* const Env = AndroidJavaEnv::GetJavaEnv();																	\
																															\
		if (!Env)																											\
		{																													\
			UE_LOG(LogOneSignal, Error, TEXT("Failed to get Env."));														\
			return;																											\
		}																													\
																															\
		static jmethodID jMethod = Env->GetMethodID(GetGameActivityClass(), Name, Signature);								\
																															\
		if (Env->ExceptionCheck())																							\
		{																													\
			UE_LOG(LogOneSignal, Error, TEXT("Failed to get method \"") TEXT(Name) TEXT(Signature) TEXT("\"."));			\
			Env->ExceptionDescribe();																						\
			Env->ExceptionClear();																							\
			return;																											\
		}																													\
																															\
		Env->CallVoidMethod(AndroidJavaEnv::GetGameActivityThis(), jMethod, ## __VA_ARGS__);								\
																															\
		if (Env->ExceptionCheck())																							\
		{																													\
			UE_LOG(LogOneSignal, Error, TEXT("Exception thrown while calling method."));									\
			Env->ExceptionDescribe();																						\
			Env->ExceptionClear();																							\
		}																													\
	}()		

#define CALL_ACTIVITY_OBJECT_METHOD(Name, Signature, ...) \
	CALL_ACTIVITY_METHOD(Name, Signature, Object, (jobject)NULL, ## __VA_ARGS__)

#endif

EOneSignalNotificationActionType UOneSignalNotificationAction::GetType() const
{
#if PLATFORM_IOS
	return Native != nil ? (EOneSignalNotificationActionType)Native.type : EOneSignalNotificationActionType::Opened;
#elif PLATFORM_ANDROID
	return Native ?
		(EOneSignalNotificationActionType)CALL_ACTIVITY_METHOD("AndroidThunk_OSNotificationActionType_getType", 
		"(Ljava/lang/Object;)I", Int, 0, Native) : EOneSignalNotificationActionType::Opened;
#else
	return EOneSignalNotificationActionType::Opened;
#endif
}

FString UOneSignalNotificationAction::GetActionID() const
{
#if PLATFORM_IOS
	return Native != nil ? FString(Native.actionId) : FString();
#elif PLATFORM_ANDROID
	return Native ? 
		CALL_ACTIVITY_STRING_METHOD("AndroidThunk_OSNotificationActionType_getActionId", "(Ljava/lang/Object;)Ljava/lang/String;", Native) 
		: FString();
#else
	return FString();
#endif
}

bool UOneSignalDeviceState::HasNotificationPermission() const
{
#if PLATFORM_IOS
	return Native != nil ? Native.hasNotificationPermission : false;
#elif PLATFORM_ANDROID
	return Native ? 
		CALL_ACTIVITY_BOOL_METHOD("AndroidThunk_OSDeviceState_areNotificationsEnabled", "(Ljava/lang/Object;)Z", Native) : false;
#else
	return true;
#endif
}

bool UOneSignalDeviceState::IsPushDisabled() const
{
#if PLATFORM_IOS
	return Native != nil ? Native.isPushDisabled : false;
#elif PLATFORM_ANDROID
	return Native ?
		CALL_ACTIVITY_BOOL_METHOD("AndroidThunk_OSDeviceState_isPushDisabled", "(Ljava/lang/Object;)Z", Native) : false;
#else
	return false;
#endif
}

bool UOneSignalDeviceState::IsSubscribed() const
{
#if PLATFORM_IOS
	return Native != nil ? Native.isSubscribed : false;
#elif PLATFORM_ANDROID
	return Native ?
		CALL_ACTIVITY_BOOL_METHOD("AndroidThunk_OSDeviceState_isSubscribed", "(Ljava/lang/Object;)Z", Native) : false;
#else
	return false;
#endif
}

EOneSignalNotificationPermission UOneSignalDeviceState::GetNotificationPermissionStatus() const
{
#if PLATFORM_IOS
	return Native != nil ? EOneSignalNotificationPermission(Native.notificationPermissionStatus) : 
		EOneSignalNotificationPermission::NotDetermined;
#elif PLATFORM_ANDROID
	return EOneSignalNotificationPermission::Authorized;
#else
	return EOneSignalNotificationPermission::NotDetermined;
#endif
}

FString UOneSignalDeviceState::GetUserId() const
{
#if PLATFORM_IOS
	return FString(Native != nil ? Native.userId : nil);
#elif PLATFORM_ANDROID
	return Native ?
		CALL_ACTIVITY_STRING_METHOD("AndroidThunk_OSDeviceState_getUserId", "(Ljava/lang/Object;)Ljava/lang/String;", Native) : 
		FString();
#else
	return TEXT("");
#endif
}

FString UOneSignalDeviceState::GetPushToken() const
{
#if PLATFORM_IOS
	return FString(Native != nil ? Native.pushToken : nil);
#elif PLATFORM_ANDROID
	return Native ?
		CALL_ACTIVITY_STRING_METHOD("AndroidThunk_OSDeviceState_getPushToken", "(Ljava/lang/Object;)Ljava/lang/String;", Native) 
		: FString();
#else
	return TEXT("");
#endif
}

FString UOneSignalDeviceState::GetEmailUserId() const
{
#if PLATFORM_IOS
	return FString(Native != nil ? Native.emailUserId : nil);
#elif PLATFORM_ANDROID
	return Native ?
		CALL_ACTIVITY_STRING_METHOD("AndroidThunk_OSDeviceState_getEmailUserId", "(Ljava/lang/Object;)Ljava/lang/String;", Native) 
		: FString();
#else
	return TEXT("");
#endif
}

FString UOneSignalDeviceState::GetEmailAddress() const
{
#if PLATFORM_IOS
	return FString(Native != nil ? Native.emailAddress : nil);
#elif PLATFORM_ANDROID
	return Native ? 
		CALL_ACTIVITY_STRING_METHOD("AndroidThunk_OSDeviceState_getEmailAddress", "(Ljava/lang/Object;)Ljava/lang/String;", Native) : FString();
#else
	return TEXT("");
#endif
}

bool UOneSignalDeviceState::IsEmailSubscribed() const
{
#if PLATFORM_IOS
	return Native != nil ? Native.isEmailSubscribed : false;
#elif PLATFORM_ANDROID
	return Native ?
		(bool)CALL_ACTIVITY_BOOL_METHOD("AndroidThunk_OSDeviceState_isEmailSubscribed", "(Ljava/lang/Object;)Z", Native) : false;
#else
	return false;
#endif
}

FString UOneSignalDeviceState::GetSmsUserId() const
{
#if PLATFORM_IOS
	return FString(Native != nil ? Native.smsUserId : nil);
#elif PLATFORM_ANDROID
	return Native ?
		CALL_ACTIVITY_STRING_METHOD("AndroidThunk_OSDeviceState_getSMSUserId", "(Ljava/lang/Object;)Ljava/lang/String;", Native) : FString();
#else
	return TEXT("");
#endif
}

FString UOneSignalDeviceState::GetSmsNumber() const
{
#if PLATFORM_IOS
	return FString(Native != nil ? Native.smsNumber : nil);
#elif PLATFORM_ANDROID
	return Native ?
		CALL_ACTIVITY_STRING_METHOD("AndroidThunk_OSDeviceState_getSmsNumber", "(Ljava/lang/Object;)Ljava/lang/String;", Native) : FString();
#else
	return TEXT("");
#endif
}

bool UOneSignalDeviceState::IsSMSSubscribed() const
{
#if PLATFORM_IOS
	return Native != nil ? Native.isSMSSubscribed : false;
#elif PLATFORM_ANDROID
	return Native && CALL_ACTIVITY_BOOL_METHOD("AndroidThunk_OSDeviceState_isSMSSubscribed", "(Ljava/lang/Object;)Z", Native);
#else
	return false;
#endif
}

FString UOneSignalDeviceState::GetJsonRepresentation() const
{
#if PLATFORM_IOS
	return FString(Native != nil ? [NSString stringWithFormat:@"%@", [Native jsonRepresentation]] : nil);
#elif PLATFORM_ANDROID
	return !IsNull(AndroidJavaEnv::GetJavaEnv(), Native) ? 
		CALL_ACTIVITY_STRING_METHOD("AndroidThunk_OSDeviceState_toJson", "(Ljava/lang/Object;)Ljava/lang/String;", Native) : FString();
#else
	return TEXT("");
#endif
}

FString UOneSignalLibrary::GetApplicationID()
{
#if PLATFORM_IOS
	return [OneSignal appId];
#elif PLATFORM_ANDROID
	return FString();
#else
	return FString();
#endif
}

FString UOneSignalLibrary::GetSDKSemanticVersion()
{
#if PLATFORM_IOS
	return [OneSignal sdkSemanticVersion];
#elif PLATFORM_ANDROID
	FString SdkVersion = GetSDKVersion();

	check(SdkVersion.Len() == 6);

	auto GetSubVersion = [](const TCHAR* From) -> FString
	{
		FString Out;

		if (*From != '0')
		{
			Out.AppendChar(*From);
		}
		Out.AppendChar(*(From + 1));

		return Out;
	};

	return GetSubVersion(*SdkVersion) + TEXT(".") + GetSubVersion(*SdkVersion + 2) + TEXT(".") + GetSubVersion(*SdkVersion + 4);
#else
	return FString();
#endif
}

FString UOneSignalLibrary::GetSDKVersion()
{
#if PLATFORM_IOS
	return [OneSignal sdkVersionRaw];
#elif PLATFORM_ANDROID
	return CALL_ACTIVITY_STRING_METHOD("AndroidThunk_OneSignal_getSDKVersion", "()Ljava/lang/String;");
#else
	return FString();
#endif
}

void UOneSignalLibrary::SetAppID(const FString& ApplicationID)
{
#if !UE_BUILD_SHIPPING
	UE_LOG(LogOneSignal, Log, TEXT("Application ID set to %s."), *ApplicationID);
#endif

#if PLATFORM_IOS
	[OneSignal setAppId: ApplicationID.GetNSString()];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setAppId", "(Ljava/lang/String;)V", *ToJavaString(ApplicationID));
#endif
}

void UOneSignalLibrary::SetPlatformAppID(const FString& iOSApplicationID, const FString& AndroidApplicationID)
{
#if PLATFORM_IOS
	SetAppID(iOSApplicationID);
#else
	SetAppID(AndroidApplicationID);
#endif
}

void UOneSignalLibrary::Initialize()
{
	UE_LOG(LogOneSignal, Log, TEXT("OneSignal SDK initialized."));

#if PLATFORM_IOS
	@autoreleasepool
	{
		[OneSignal addPermissionObserver:        [[[FOneSignalPermissionObserver        alloc] init] autorelease]];
		[OneSignal addSubscriptionObserver:      [[[FOneSignalSubscriptionObserver      alloc] init] autorelease]];
		[OneSignal addEmailSubscriptionObserver: [[[FOneSignalEmailSubscriptionObserver alloc] init] autorelease]];
		[OneSignal addSMSSubscriptionObserver:   [[[FOneSignalSMSSubscriptionObserver   alloc] init] autorelease]];
	}
	
	[OneSignal initWithLaunchOptions: [IOSAppDelegate GetDelegate].launchOptions];
#elif PLATFORM_ANDROID

	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_addPermissionObserver", "()V");
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_addEmailSubscriptionObserver", "()V");
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_addSMSSubscriptionObserver", "()V");
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_addSubscriptionObserver", "()V");

	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_initialize", "()V");
#endif
}

void UOneSignalLibrary::SetLaunchURLsInApp(const bool bLaunchInApp)
{
#if PLATFORM_IOS
	[OneSignal setLaunchURLsInApp: (BOOL)bLaunchInApp];
#endif
}

void UOneSignalLibrary::SetProvidesNotificationSettingsView(const bool bProvidesView)
{
#if PLATFORM_IOS
	[OneSignal setProvidesNotificationSettingsView: (BOOL)bProvidesView];
#endif
}

void UOneSignalLibrary::SetLogLevel(const EOneSignalLogLevel InLogLevel, const EOneSignalLogLevel VisualLogLevel)
{
	UE_LOG(LogOneSignal, Log, TEXT("Log level changed: %d, visual log level: %d."), (int32)InLogLevel, (int32)VisualLogLevel);

#if PLATFORM_IOS
	[OneSignal setLogLevel: (ONE_S_LOG_LEVEL)InLogLevel visualLevel: (ONE_S_LOG_LEVEL)VisualLogLevel];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setLogLevel", "(II)V", (jint)InLogLevel, (jint)VisualLogLevel);
#endif
}

void UOneSignalLibrary::Log(const EOneSignalLogLevel InLogLevel, const FString& Message)
{
#if PLATFORM_IOS
	[OneSignal onesignalLog: (ONE_S_LOG_LEVEL)InLogLevel message: Message.GetNSString()];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_log", "(ILjava/lang/String;)V", (jint)InLogLevel, *ToJavaString(Message));
#endif
}

void UOneSignalLibrary::PromptForPushNotifications(FOneSignalUserResponseCallback Callback)
{
	UE_LOG(LogOneSignal, Log, TEXT("Prompting the user for push notification."));

#if PLATFORM_IOS
	[OneSignal promptForPushNotificationsWithUserResponse: [Callback = MoveTemp(Callback)] (BOOL accepted) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [Callback = MoveTemp(Callback), accepted]() -> void
		{
			Callback.ExecuteIfBound((bool)accepted);
		});
	}];
#else
	Callback.ExecuteIfBound(true);
#endif
}

void UOneSignalLibrary::PromptForPushNotifications(const bool bFallback, FOneSignalUserResponseCallback Callback)
{
	UE_LOG(LogOneSignal, Log, TEXT("Prompting the user for push notification."));

#if PLATFORM_IOS
	[OneSignal promptForPushNotificationsWithUserResponse: [Callback = MoveTemp(Callback)] (BOOL accepted) mutable -> void
	{
		UE_LOG(LogOneSignal, Log, TEXT("Push notification prompt result: %d."), (int32)accepted);

		AsyncTask(ENamedThreads::GameThread, [Callback = MoveTemp(Callback), accepted]() -> void
		{
			Callback.ExecuteIfBound((bool)accepted);
		});
	} fallbackToSettings: (BOOL)bFallback];
#else
	Callback.ExecuteIfBound(true);
#endif
}

void UOneSignalLibrary::RegisterForProvisionalAuthorization(FOneSignalUserResponseCallback Callback)
{
#if PLATFORM_IOS
	[OneSignal registerForProvisionalAuthorization: [Callback = MoveTemp(Callback)] (BOOL accepted) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [Callback = MoveTemp(Callback), accepted]() -> void
		{
			Callback.ExecuteIfBound((bool)accepted);
		});
	}];
#else
	Callback.ExecuteIfBound(true);
#endif
}

UOneSignalDeviceState* UOneSignalLibrary::GetDeviceState()
{
#if PLATFORM_IOS
	return UOneSignalDeviceState::FromNative([OneSignal getDeviceState]);
#elif PLATFORM_ANDROID
	jobject DeviceState = CALL_ACTIVITY_OBJECT_METHOD("AndroidThunk_OneSignal_getDeviceState", "()Ljava/lang/Object;");

	UOneSignalDeviceState* State = UOneSignalDeviceState::FromNative(AndroidJavaEnv::GetJavaEnv(), DeviceState);

	AndroidJavaEnv::GetJavaEnv()->DeleteLocalRef(DeviceState);
	
	return State;
#else
	return NewObject<UOneSignalDeviceState>();
#endif
}

void UOneSignalLibrary::SetConsentGranted(const bool bGranted)
{
#if PLATFORM_IOS
	[OneSignal consentGranted: bGranted];
#endif
}

void UOneSignalLibrary::SetRequiresUserPrivacyConsent(const bool bRequired)
{
#if PLATFORM_IOS
	[OneSignal setRequiresUserPrivacyConsent: bRequired];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setRequiresUserPrivacyConsent", "(Z)V", (jboolean)bRequired);
#endif
}

void UOneSignalLibrary::PostNotification(const FString& JSONString, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
	UE_LOG(LogOneSignal, Log, TEXT("Posting notification."));

#if PLATFORM_IOS
	NSError* Error = nil;

	NSDictionary* Data = [NSJSONSerialization 
						 JSONObjectWithData: [JSONString.GetNSString() dataUsingEncoding: NSUTF8StringEncoding]
									options: kNilOptions
                                      error: &Error];

	if (Error != nil)
	{
		FString ErrorMessage = FString::Printf(TEXT("Failed to parse JSON: %d - %s."), Error.code, * FString(Error.description));
		UE_LOG(LogOneSignal, Error, TEXT("%s"), *ErrorMessage);
		OnFailure.ExecuteIfBound(-1, MoveTemp(ErrorMessage));
		return;
	}

	[OneSignal postNotification: Data
		onSuccess: [OnSuccess = MoveTemp(OnSuccess)](NSDictionary* result) mutable -> void
	{
		UE_LOG(LogOneSignal, Log, TEXT("Notification posted."));

		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		onFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to post notification: %d - %s"), (int32)error.code, *FString(error.description));

		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_postNotification", "(Ljava/lang/String;JJ)V",
		*ToJavaString(JSONString), (jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)), (jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::PromptLocation()
{
	UE_LOG(LogOneSignal, Log, TEXT("Prompting location."));

#if PLATFORM_IOS
	[OneSignal promptLocation];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_promptLocation", "()V");
#endif
}

bool UOneSignalLibrary::IsLocationShared()
{
#if PLATFORM_IOS
	return [OneSignal isLocationShared];
#elif PLATFORM_ANDROID
	return CALL_ACTIVITY_BOOL_METHOD("AndroidThunk_OneSignal_isLocationShared", "()Z");
#else
	return true;
#endif
}

void UOneSignalLibrary::SetLocationShared(const bool bShared)
{
#if PLATFORM_IOS
	[OneSignal setLocationShared: bShared];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setLocationShared", "(Z)V", (jboolean)bShared);
#endif
}

void UOneSignalLibrary::SendTag(const FString& Key, const FString& Value, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
	UE_LOG(LogOneSignal, Log, TEXT("Sending tag { %s: %s }."), *Key, *Value);

#if PLATFORM_IOS
	[OneSignal sendTag: Key.GetNSString()
			     value: Value.GetNSString()
		onSuccess: [OnSuccess = MoveTemp(OnSuccess)](NSDictionary* result) mutable -> void
	{
		UE_LOG(LogOneSignal, Log, TEXT("Tag sent."));

		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		onFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to send tag: %d - %s"), (int32)error.code, *FString(error.description));

		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_sendTag", "(Ljava/lang/String;Ljava/lang/String;)", 
		*ToJavaString(Key), *ToJavaString(Value));
	OnSuccess.ExecuteIfBound();
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::SendTags(const TMap<FString, FString>& Tags, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
	UE_LOG(LogOneSignal, Log, TEXT("Sending %d tags."), Tags.Num());

#if PLATFORM_IOS
	NSMutableDictionary* NativeTags = [[NSMutableDictionary alloc] initWithCapacity: Tags.Num()];

	for (const auto& Tag : Tags)
	{
		[NativeTags setValue: Tag.Value.GetNSString()
					  forKey: Tag.Key  .GetNSString()];
	}

	[OneSignal sendTags: NativeTags
		onSuccess: [OnSuccess = MoveTemp(OnSuccess)](NSDictionary* result) mutable -> void
	{
		UE_LOG(LogOneSignal, Log, TEXT("Tag set."));

		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		onFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to set tag: %d - %s"), (int32)error.code, *FString(error.description));

		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];

	[NativeTags release];
#elif PLATFORM_ANDROID
	auto Root = MakeShared<FJsonObject>();

	Root->Values.Reserve(Tags.Num());
	for (const auto& Tag : Tags)
	{
		Root->SetStringField(Tag.Key, Tag.Value);
	}

	FString Json;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&Json);
	FJsonSerializer::Serialize(Root, Writer);

	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_sendTags", "(Ljava/lang/String;)V", *ToJavaString(*Json));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::GetTags(FOneSignalTagsCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
	TMap<FString, FString> a;
#if PLATFORM_IOS
	[OneSignal getTags:
		[OnSuccess = MoveTemp(OnSuccess)](NSDictionary* result) mutable -> void
	{
		TMap<FString, FString> Tags;
		Tags.Reserve([result count]);

		[result enumerateKeysAndObjectsUsingBlock: [&Tags](id key, id value, BOOL* stop) mutable -> void
		{
			Tags.Emplace(FString((NSString*)key), FString((NSString*)value));
		}];

		AsyncTask(ENamedThreads::GameThread, [Tags = MoveTemp(Tags), OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound(MoveTemp(Tags));
		});
	}
		onFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to get tags: %d - %s"), (int32)error.code, *FString(error.description));

		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_getTags", "(JJ)V", (jlong)new FOneSignalTagsCallback(MoveTemp(OnSuccess)),
		(jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound({});
#endif
}

void UOneSignalLibrary::DeleteTag(const FString& Key, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
#if PLATFORM_IOS
	[OneSignal deleteTag: Key.GetNSString()
		onSuccess: [OnSuccess = MoveTemp(OnSuccess)](NSDictionary* result) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		onFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to delete tags: %d - %s"), (int32)error.code, *FString(error.description));

		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_deleteTag", "(Ljava/lang/String;)V", *ToJavaString(Key));
	OnSuccess.ExecuteIfBound();
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::DeleteTags(const TArray<FString>& Keys, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
#if PLATFORM_IOS
	NSMutableArray* NativeKeys = [NSMutableArray arrayWithCapacity: Keys.Num()];

	for (const auto& Key : Keys)
	{
		[NativeKeys addObject: Key.GetNSString()];
	}

	[OneSignal deleteTags: NativeKeys
		onSuccess: [OnSuccess = MoveTemp(OnSuccess)](NSDictionary* result) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		onFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to delete tags: %d - %s"), (int32)error.code, *FString(error.description));

		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	JNIEnv* const Env = AndroidJavaEnv::GetJavaEnv();
	check(Env);

	jclass StringClass = Env->FindClass("java/lang/String");
	jobjectArray NativeKeys = Env->NewObjectArray(Keys.Num(), StringClass, NULL);

	for (int32 i = 0; i < Keys.Num(); ++i)
	{
		Env->SetObjectArrayElement(NativeKeys, i, *ToJavaString(Keys[i]));
	}

	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_deleteTag", "([Ljava/lang/String;)V", NativeKeys);

	Env->DeleteLocalRef(StringClass);
	Env->DeleteLocalRef(NativeKeys);

	OnSuccess.ExecuteIfBound();
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::SetEmailWithHashToken(const FString& Email, const FString& HashToken, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
	UE_LOG(LogOneSignal, Log, TEXT("Setting email with auth hash token."));

#if PLATFORM_IOS
	[OneSignal setEmail: Email.GetNSString()
 withEmailAuthHashToken: HashToken.GetNSString()
		withSuccess: [OnSuccess = MoveTemp(OnSuccess)] () mutable -> void
	{
		UE_LOG(LogOneSignal, Log, TEXT("Email with auth hash token set."));
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		withFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to set email with auth hash token: %d - %s"), (int32)error.code, *FString(error.description));
	
		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setEmail", "(Ljava/lang/String;Ljava/lang/String;JJ)V",
		*ToJavaString(Email), *ToJavaString(HashToken), (jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)),
		(jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::SetEmail(const FString& Email, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
	UE_LOG(LogOneSignal, Log, TEXT("Setting email."));

#if PLATFORM_IOS
	[OneSignal setEmail: Email.GetNSString()
		withSuccess: [OnSuccess = MoveTemp(OnSuccess)] () mutable -> void
	{
		UE_LOG(LogOneSignal, Log, TEXT("Email set."));
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		withFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to set email: %d - %s"), (int32)error.code, *FString(error.description));
	
		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setEmail", "(Ljava/lang/String;Ljava/lang/String;JJ)V",
		*ToJavaString(Email), (jobject)NULL, (jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)),
		(jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::LogOutEmail(FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
	UE_LOG(LogOneSignal, Log, TEXT("Logging out email."));

#if PLATFORM_IOS
	[OneSignal logoutEmailWithSuccess:
		[OnSuccess = MoveTemp(OnSuccess)] () mutable -> void
	{
		UE_LOG(LogOneSignal, Log, TEXT("Logged out."));
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		withFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to log out email: %d - %s"), (int32)error.code, *FString(error.description));
	
		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_logoutEmail", "(JJ)V",
		(jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)), (jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::SetSMSWithHashToken(const FString& SMS, const FString& HashToken, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
#if PLATFORM_IOS
	[OneSignal setSMSNumber: SMS.GetNSString() withSMSAuthHashToken: HashToken.GetNSString()
		withSuccess: [OnSuccess = MoveTemp(OnSuccess)] (NSDictionary* results) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		withFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to set SMS with auth hash token: %d - %s"), (int32)error.code, *FString(error.description));
	
		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setSMS", "(Ljava/lang/String;Ljava/lang/String;JJ)V",
		*ToJavaString(SMS), *ToJavaString(HashToken),
		(jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)), (jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::SetSMS(const FString& SMS, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
#if PLATFORM_IOS
	[OneSignal setSMSNumber: SMS.GetNSString()
		withSuccess: [OnSuccess = MoveTemp(OnSuccess)] (NSDictionary* results) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		withFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to set SMS with auth hash token: %d - %s"), (int32)error.code, *FString(error.description));
	
		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setSMS", "(Ljava/lang/String;Ljava/lang/String;JJ)V",
		*ToJavaString(SMS), (jobject)NULL,
		(jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)), (jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::LogOutSMS(FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
#if PLATFORM_IOS
	[OneSignal logoutSMSNumberWithSuccess: 
		[OnSuccess = MoveTemp(OnSuccess)] (NSDictionary* results) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		withFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to log out SMS: %d - %s"), (int32)error.code, *FString(error.description));
	
		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_logoutSMS", "(JJ)V",
		(jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)), (jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::SetLanguage(const FString& Language, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
	UE_LOG(LogOneSignal, Log, TEXT("Setting language to %s."), *Language);

#if PLATFORM_IOS
	[OneSignal setLanguage: Language.GetNSString()
		withSuccess: [OnSuccess = MoveTemp(OnSuccess)] () mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		withFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to set language: %d - %s"), (int32)error.code, *FString(error.description));
	
		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setLanguage", "(Ljava/lang/String;JJ)V", *ToJavaString(Language),
		(jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)), (jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

bool UOneSignalLibrary::IsInAppMessagingPaused()
{
#if PLATFORM_IOS
	return [OneSignal isInAppMessagingPaused];
#elif PLATFORM_ANDROID
	return CALL_ACTIVITY_BOOL_METHOD("AndroidThunk_OneSignal_isInAppMessagingPaused", "()Z");
#else
	return false;
#endif
}

void UOneSignalLibrary::PauseInAppMessages(const bool bPaused)
{
#if PLATFORM_IOS
	[OneSignal pauseInAppMessages: bPaused];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_pauseInAppMessage", "(Z)V", (jboolean)bPaused);
#endif
}

void UOneSignalLibrary::AddTrigger(const FString& Key, const FString& Value)
{
#if PLATFORM_IOS
	[OneSignal addTrigger: Key.GetNSString() withValue: Value.GetNSString()];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_addTrigger", "(Ljava/lang/String;Ljava/lang/String;)V", 
		*ToJavaString(Key), *ToJavaString(Value));
#endif
}

void UOneSignalLibrary::AddIntTrigger(const FString& Key, const int64 Value)
{
#if PLATFORM_IOS
	[OneSignal addTrigger: Key.GetNSString() withValue: [NSNumber numberWithInteger: Value]];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_addTrigger", "(Ljava/lang/String;J)V",
		*ToJavaString(Key), (jlong)Value);
#endif
}

void UOneSignalLibrary::AddTriggers(const TMap<FString, FString>& Triggers)
{
#if PLATFORM_IOS
	NSMutableDictionary* NativeTriggers = [NSMutableDictionary dictionaryWithCapacity: Triggers.Num()];

	for (const auto& Trigger : Triggers)
	{
		[NativeTriggers setObject: Trigger.Value.GetNSString() forKey: Trigger.Key.GetNSString()];
	}

	[OneSignal addTriggers: NativeTriggers];
#elif PLATFORM_ANDROID
	JNIEnv* const Env = AndroidJavaEnv::GetJavaEnv();
	check(Env);

	jclass StringClass = Env->FindClass("java/lang/String");

	jobjectArray NativeKeys   = Env->NewObjectArray(Triggers.Num(), StringClass, NULL);
	jobjectArray NativeValues = Env->NewObjectArray(Triggers.Num(), StringClass, NULL);

	{
		int32 i = 0;
		for (const auto& Trigger : Triggers)
		{
			Env->SetObjectArrayElement(NativeKeys,   i, *ToJavaString(Trigger.Key));
			Env->SetObjectArrayElement(NativeValues, i, *ToJavaString(Trigger.Value));

			++i;
		}
	}

	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_addTriggers", "([Ljava/lang/String;[Ljava/lang/String;)V", NativeKeys, NativeValues);

	Env->DeleteLocalRef(StringClass);
	Env->DeleteLocalRef(NativeKeys);
	Env->DeleteLocalRef(NativeValues);
#endif
}

void UOneSignalLibrary::AddIntTriggers(const TMap<FString, int64>& Triggers)
{
#if PLATFORM_IOS
	NSMutableDictionary* NativeTriggers = [NSMutableDictionary dictionaryWithCapacity: Triggers.Num()];

	for (const auto& Trigger : Triggers)
	{
		[NativeTriggers setObject: [NSNumber numberWithInteger: Trigger.Value] forKey: Trigger.Key.GetNSString()];
	}

	[OneSignal addTriggers: NativeTriggers];	
#elif PLATFORM_ANDROID
	JNIEnv* const Env = AndroidJavaEnv::GetJavaEnv();
	check(Env);

	jclass StringClass = Env->FindClass("java/lang/String");

	jobjectArray NativeKeys   = Env->NewObjectArray(Triggers.Num(), StringClass, NULL);
	jlongArray   NativeValues = Env->NewLongArray  (Triggers.Num());

	{
		int32 i = 0;
		for (const auto& Trigger : Triggers)
		{
			Env->SetObjectArrayElement(NativeKeys,   i, *ToJavaString(Trigger.Key));

			// 32-bits platforms cause issues otherwise as sizeof(jlong) != sizeof(int64).
			jlong Value = (jlong)Trigger.Value;
			Env->SetLongArrayRegion(NativeValues, i, 1, &Value);

			++i;
		}
	}

	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_addTriggers", "([Ljava/lang/String;[J)V", NativeKeys, NativeValues);

	Env->DeleteLocalRef(StringClass);
	Env->DeleteLocalRef(NativeKeys);
	Env->DeleteLocalRef(NativeValues);
#endif
}

void UOneSignalLibrary::RemoveTrigger(const FString& Key)
{
#if PLATFORM_IOS
	[OneSignal removeTriggerForKey: Key.GetNSString()];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_removeTrigger", "(Ljava/lang/String;)V", *ToJavaString(Key));
#endif
}

void UOneSignalLibrary::RemoveTriggers(const TArray<FString>& Keys)
{
#if PLATFORM_IOS
	NSMutableArray* NativeKeys = [NSMutableArray arrayWithCapacity: Keys.Num()];

	for (const FString& Key : Keys)
	{
		[NativeKeys addObject: Key.GetNSString()];
	}

	[OneSignal removeTriggersForKeys: NativeKeys];
#elif PLATFORM_ANDROID
	JNIEnv* const Env = AndroidJavaEnv::GetJavaEnv();
	check(Env);

	jclass StringClass = Env->FindClass("java/lang/String");

	jobjectArray NativeKeys = Env->NewObjectArray(Keys.Num(), StringClass, NULL);

	for (int32 i = 0; i < Keys.Num(); ++i)
	{
		Env->SetObjectArrayElement(NativeKeys, i, *ToJavaString(Keys[i]));;
	}

	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_removeTriggers", "([Ljava/lang/String;)V", NativeKeys);

	Env->DeleteLocalRef(StringClass);
	Env->DeleteLocalRef(NativeKeys);
#endif
}

TMap<FString, FString> UOneSignalLibrary::GetTriggers()
{
	TMap<FString, FString> Triggers;

#if PLATFORM_IOS
	NSDictionary<NSString*, id>* NativeTriggers = [OneSignal getTriggers];

	Triggers.Reserve([NativeTriggers count]);
	
	[NativeTriggers enumerateKeysAndObjectsUsingBlock: [&Triggers](id key, id value, BOOL* stop) -> void
	{
		if (value == nil)
		{
			Triggers.Emplace(FString((NSString*)key), FString());
		}
		else if ([value isKindOfClass: [NSString class]])
		{
			Triggers.Emplace(FString((NSString*)key), FString((NSString*)value));
		}
		else if ([value isKindOfClass: [NSNumber class]])
		{
			Triggers.Emplace(FString((NSString*)key), FString::FromInt([(NSNumber*)value longLongValue]));
		}
		else
		{
			Triggers.Emplace(FString((NSString*)key), TEXT("{ invalid object }"));
		}
	}];
#elif PLATFORM_ANDROID
	JNIEnv* const Env = AndroidJavaEnv::GetJavaEnv();
	check(Env);

	jobjectArray triggers = (jobjectArray)CALL_ACTIVITY_OBJECT_METHOD("AndroidThunk_OneSignal_getTriggers", "()[Ljava/lang/String;");

	const int32 ArraySize = Env->GetArrayLength(triggers);
	check(ArraySize % 2 == 0);

	const int32 TriggerCount = ArraySize / 2;

	Triggers.Reserve(TriggerCount);

	for (int32 i = 0; i < TriggerCount; ++i)
	{
		Triggers.Emplace(
			FJavaHelper::FStringFromLocalRef(Env, (jstring)Env->GetObjectArrayElement(triggers, i)), 
			FJavaHelper::FStringFromLocalRef(Env, (jstring)Env->GetObjectArrayElement(triggers, i + TriggerCount)));
	}

	Env->DeleteLocalRef(triggers);

#endif

	return Triggers;
}

FString UOneSignalLibrary::GetTriggerValue(const FString& Key)
{
#if PLATFORM_IOS
	id value = [OneSignal getTriggerValueForKey: Key.GetNSString()];

	if (value == nil)
	{
		UE_LOG(LogOneSignal, Warning, TEXT("No trigger with key %s."), *Key);
		return FString();
	}

	if ([value isKindOfClass: [NSString class]])
	{
		return FString((NSString*)value);
	}

	if ([value isKindOfClass: [NSNumber class]])
	{
		return FString::FromInt([(NSNumber*)value longLongValue]);
	}

	return TEXT("{ invalid object }");
#elif PLATFORM_ANDROID
	return CALL_ACTIVITY_STRING_METHOD("AndroidThunk_OneSignal_getTriggerValue", "(Ljava/lang/String;)Ljava/lang/String;", *ToJavaString(Key));
#else
	return FString();
#endif
}

bool UOneSignalLibrary::HasTriggerValue(const FString& Key)
{
#if PLATFORM_IOS
	return [OneSignal getTriggerValueForKey: Key.GetNSString()] != nil;
#elif PLATFORM_ANDROID
	return CALL_ACTIVITY_BOOL_METHOD("AndroidThunk_OneSignal_hasTriggerValue", "(Ljava/lang/String;)Z", *ToJavaString(Key));
#else
	return false;
#endif
}

void UOneSignalLibrary::SendOutcome(const FString& Name, FOneSignalOutcomeSuccessCallback OnSuccess)
{
#if PLATFORM_IOS
	[OneSignal sendOutcome: Name.GetNSString()
		onSuccess: [OnSuccess = MoveTemp(OnSuccess)] (OSOutcomeEvent* outcome) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [Outcome = ConvertOutcomeEvent(outcome), OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound(Outcome);
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_sendOutcome", "(Ljava/lang/String;J)V", *ToJavaString(Name), 
		(jlong)new FOneSignalOutcomeSuccessCallback(MoveTemp(OnSuccess)));
#else
	OnSuccess.ExecuteIfBound({});
#endif
}

void UOneSignalLibrary::SendUniqueOutcome(const FString& Name, FOneSignalOutcomeSuccessCallback OnSuccess)
{
#if PLATFORM_IOS
	[OneSignal sendOutcome: Name.GetNSString()
		onSuccess: [OnSuccess = MoveTemp(OnSuccess)](OSOutcomeEvent* outcome) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [Outcome = ConvertOutcomeEvent(outcome), OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound(Outcome);
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_sendUniqueOutcome", "(Ljava/lang/String;J)V", *ToJavaString(Name),
		(jlong)new FOneSignalOutcomeSuccessCallback(MoveTemp(OnSuccess)));
#else
	OnSuccess.ExecuteIfBound({});
#endif
}

void UOneSignalLibrary::SendOutcome(const FString& Name, float  Value, FOneSignalOutcomeSuccessCallback OnSuccess)
{
	SendOutcome(Name, (double)Value, MoveTemp(OnSuccess));
}

void UOneSignalLibrary::SendOutcome(const FString& Name, int32  Value, FOneSignalOutcomeSuccessCallback OnSuccess)
{
	SendOutcome(Name, (int64)Value, MoveTemp(OnSuccess));
}

void UOneSignalLibrary::SendOutcome(const FString& Name, int64  Value, FOneSignalOutcomeSuccessCallback OnSuccess)
{
#if PLATFORM_IOS
	[OneSignal sendOutcomeWithValue: Name.GetNSString()
		value: [NSNumber numberWithLongLong: Value]
		onSuccess: [OnSuccess = MoveTemp(OnSuccess)] (OSOutcomeEvent* outcome) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [Outcome = ConvertOutcomeEvent(outcome), OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound(Outcome);
		});
	}];
#elif PLATFORM_ANDROID
	SendOutcome(Name, (double)Value, MoveTemp(OnSuccess));
#else
	OnSuccess.ExecuteIfBound({});
#endif
}

void UOneSignalLibrary::SendOutcome(const FString& Name, double Value, FOneSignalOutcomeSuccessCallback OnSuccess)
{
#if PLATFORM_IOS
	[OneSignal sendOutcomeWithValue: Name.GetNSString()
		value: [NSNumber numberWithDouble: Value]
		onSuccess: [OnSuccess = MoveTemp(OnSuccess)] (OSOutcomeEvent* outcome) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [Outcome = ConvertOutcomeEvent(outcome), OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound(Outcome);
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_sendOutcomeWithValue", "(Ljava/lang/String;FJ)V", *ToJavaString(Name),
		(jfloat)Value, (jlong)new FOneSignalOutcomeSuccessCallback(MoveTemp(OnSuccess)));
#else
	OnSuccess.ExecuteIfBound({});
#endif
}

void UOneSignalLibrary::SetExternalUserID(const FString& UserID, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
#if PLATFORM_IOS
	[OneSignal setExternalUserId: UserID.GetNSString()
		withSuccess: [OnSuccess = MoveTemp(OnSuccess)] (NSDictionary* results) mutable -> void
	{
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		withFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to set external user ID: %d - %s"), (int32)error.code, *FString(error.description));
	
		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setExternalUserId", "(Ljava/lang/String;Ljava/lang/String;JJ)V", 
		*ToJavaString(UserID), (jobject)NULL,
		(jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)), (jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::SetExternalUserIDWithAuthHashToken(const FString& UserID, const FString& AuthHashToken, FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
#if PLATFORM_IOS
	[OneSignal setExternalUserId: UserID.GetNSString()
	 withExternalIdAuthHashToken: AuthHashToken.GetNSString()
		withSuccess: [OnSuccess = MoveTemp(OnSuccess)] (NSDictionary* results) mutable -> void
	{
		UE_LOG(LogOneSignal, Log, TEXT("External user ID with auth hash token set."));
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		withFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to set external user ID with auth hash token: %d - %s"), (int32)error.code, *FString(error.description));
	
		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_setExternalUserId", "(Ljava/lang/String;Ljava/lang/String;JJ)V",
		*ToJavaString(UserID), *ToJavaString(AuthHashToken),
		(jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)), (jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

void UOneSignalLibrary::RemoveExternalUserID(FOneSignalSuccessCallback OnSuccess, FOneSignalFailureCallback OnFailure)
{
#if PLATFORM_IOS
	[OneSignal removeExternalUserId:
		[OnSuccess = MoveTemp(OnSuccess)] (NSDictionary* results) mutable -> void
	{
		UE_LOG(LogOneSignal, Log, TEXT("External user ID removed."));
		AsyncTask(ENamedThreads::GameThread, [OnSuccess = MoveTemp(OnSuccess)]() mutable -> void
		{
			OnSuccess.ExecuteIfBound();
		});
	}
		withFailure: [OnFailure = MoveTemp(OnFailure)] (NSError* error) mutable -> void
	{
		UE_LOG(LogOneSignal, Error, TEXT("Failed to remove external user ID: %d - %s"), (int32)error.code, *FString(error.description));
	
		AsyncTask(ENamedThreads::GameThread, [OnFailure = MoveTemp(OnFailure), Code = int32(error.code), Message = FString(error.description)]() mutable -> void
		{
			OnFailure.ExecuteIfBound(Code, MoveTemp(Message));
		});
	}];
#elif PLATFORM_ANDROID
	CALL_ACTIVITY_VOID_METHOD("AndroidThunk_OneSignal_removeExternalUserId", "(JJ)V",
		(jlong)new FOneSignalSuccessCallback(MoveTemp(OnSuccess)), (jlong)new FOneSignalFailureCallback(MoveTemp(OnFailure)));
#else
	OnSuccess.ExecuteIfBound();
#endif
}

FOneSignalPermissionChanged& UOneSignalLibrary::OnPermissionChanged()
{
	static FOneSignalPermissionChanged Event;
	return Event;
}

FOneSignalSubscriptionChanged& UOneSignalLibrary::OnSubscriptionChanged()
{
	static FOneSignalSubscriptionChanged Event;
	return Event;
}

FOneSignalEmailSubscriptionChanged& UOneSignalLibrary::OnEmailSubscriptionChanged()
{
	static FOneSignalEmailSubscriptionChanged Event;
	return Event;
}

FOneSignalSMSSubscriptionChanged& UOneSignalLibrary::OnSMSSubscriptionChanged()
{
	static FOneSignalSMSSubscriptionChanged Event;
	return Event;
}


