// Copyright Pandores Marketplace 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OneSignalNativeBridge.h"
#include "OneSignalLibrary.generated.h"

UENUM(BlueprintType)
enum class EOneSignalLogLevel : uint8
{
	None,
	Fatal,
	Error,
	Warn,
	Info,
	Debug,
	Verbose
};

/* OneSignal Influence Types */
UENUM(BlueprintType)
enum class EOneSignalInfluenceType : uint8
{
	Direct,
	Indirect,
	Unattributed,
	Disabled
};

/* OneSignal Influence Channels */
UENUM(BlueprintType)
enum class EOneSignalInfluenceChannel : uint8
{
	InAppMessage UMETA(DisplayName = "In-App Message"),
	Notification
};

UENUM(BlueprintType)
enum class EOneSignalNotificationPermission : uint8 
{
	// The user has not yet made a choice regarding whether your app can show notifications.
	NotDetermined = 0,

	// The application is not authorized to post user notifications.
	Denied,

	// The application is authorized to post user notifications.
	Authorized,

	// the application is only authorized to post Provisional notifications (direct to history)
	Provisional,

	// the application is authorized to send notifications for 8 hours. Only used by App Clips.
	Ephemeral
};

/* The action type associated to an UOneSignalNotificationAction object */
UENUM(BlueprintType)
enum class EOneSignalNotificationActionType : uint8
{
	Opened,

	ActionTaken
};

USTRUCT(BlueprintType)
struct ONESIGNAL_API FOneSignalSMSSubscriptionState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|SMS", Meta = (DisplayName = "SMS User ID"))
	FString SMSUserID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|SMS", Meta = (DisplayName = "SMS Number"))
	FString SMSNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|SMS")
	bool bIsSubscribed;
};

USTRUCT(BlueprintType)
struct ONESIGNAL_API FOneSignalSMSSubscriptionStateChanges
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|SMS")
	FOneSignalSMSSubscriptionState From;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|SMS")
	FOneSignalSMSSubscriptionState To;
};

USTRUCT(BlueprintType)
struct ONESIGNAL_API FOneSignalEmailSubscriptionState
{
	GENERATED_BODY()
public:
	// The new Email user ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Email")
	FString EmailUserID; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Email")
	FString EmailAddress;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Email")
	bool bIsSubscribed;
};

USTRUCT(BlueprintType)
struct ONESIGNAL_API FOneSignalEmailSubscriptionStateChanges
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Email")
	FOneSignalEmailSubscriptionState From;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Email")
	FOneSignalEmailSubscriptionState To;
};

USTRUCT(BlueprintType)
struct ONESIGNAL_API FOneSignalSubscriptionState
{
	GENERATED_BODY()
public:
	// (yes only if userId, pushToken, and setSubscription exists / are true)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Subscription")
	bool bIsSubscribed;

	// returns value of disablePush.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Subscription")
	bool bIsPushDisabled;
	
	// AKA OneSignal PlayerId
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Subscription")
	FString UserID;
	
	// AKA Apple Device Token
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Subscription")
	FString PushToken; 
};


USTRUCT(BlueprintType)
struct ONESIGNAL_API FOneSignalSubscriptionStateChanges
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Subscription")
	FOneSignalSubscriptionState From;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Subscription")
	FOneSignalSubscriptionState To;
};

USTRUCT(BlueprintType)
struct ONESIGNAL_API FOneSignalPermissionState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Permission")
	bool bReachable = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Permission")
	bool bHasPrompted = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Permission")
	bool bProvidesAppNotificationSettings = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Permission")
	EOneSignalNotificationPermission Status;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Permission")
	bool bAreNotificationsEnabled = false;
};

USTRUCT(BlueprintType)
struct ONESIGNAL_API FOneSignalPermissionStateChanges
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Permission")
	FOneSignalPermissionState From;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Permission")
	FOneSignalPermissionState To;
};

USTRUCT(BlueprintType)
struct ONESIGNAL_API FOneSignalOutcomeEvent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Outcome")
	EOneSignalInfluenceType Session = EOneSignalInfluenceType::Unattributed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Outcome")
	TArray<FString> NotificationIDs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Outcome")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Outcome")
	int64 Timestamp = 0LL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OneSignal|Outcome")
	float Weight = 0.f;
};

/**
 * The action the user took on the notification.
 */
UCLASS(BlueprintType)
class ONESIGNAL_API UOneSignalNotificationAction : public UObject
{
	GENERATED_BODY()
public:
	EOneSignalNotificationActionType GetType() const;

	FString GetActionID() const;
	
public:
	ONESIGNAL_NATIVE_OBJECT_DEFAULT_CTOR(NotificationAction);

	~UOneSignalNotificationAction();

private:
	OSNotificationAction* Native = nullptr;
};

UCLASS(BlueprintType)
class ONESIGNAL_API UOneSignalDeviceState : public UObject
{
	GENERATED_BODY()
public:

	/**
	 * Get the app's notification permission
	 * @return false if the user disabled notifications for the app, otherwise true
	 */
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Has Notification Permission"))
	UPARAM(DisplayName = "Has Permission") bool HasNotificationPermission() const;

	/**
	 * Get whether the user is subscribed to OneSignal notifications or not
	 * @return false if the user is not subscribed to OneSignal notifications, otherwise true
	 */
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Is Push Disabled"))
	UPARAM(DisplayName = "Is Disabled") bool IsPushDisabled() const;

	/**
	 * Get whether the user is subscribed
	 * @return true if  isNotificationEnabled,  isUserSubscribed, getUserId and getPushToken are true, otherwise false
	 */
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Is Subscribed"))
	UPARAM(DisplayName = "Is Subscribed") bool IsSubscribed() const;

	/**
	 * Get  the user notification permision status
	 * @return OSNotificationPermission
	*/
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Get Notification Permission Status"))
	UPARAM(DisplayName = "Status") EOneSignalNotificationPermission GetNotificationPermissionStatus() const;

	/**
	 * Get user id from registration (player id)
	 * @return user id if user is registered, otherwise null
	 */
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Get User ID"))
	UPARAM(DisplayName = "User ID") FString GetUserId() const;

	/**
	 * Get apple deice push token
	 * @return push token if available, otherwise null
	 */
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Get Push Token"))
	UPARAM(DisplayName = "Token") FString GetPushToken() const;

	/**
	 * Get the user email id
	 * @return email id if user address was registered, otherwise null
	 */
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Get Email User ID"))
	UPARAM(DisplayName = "ID") FString GetEmailUserId() const;

	/**
	 * Get the user email
	 * @return email address if set, otherwise null
	 */
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Get Email Address"))
	UPARAM(DisplayName = "Address") FString GetEmailAddress() const;

	/**
	 * Checks if this device is subscribed to Emails.
	 * @return If this device is subscribed to Emails.
	*/
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Is Email Subscribed"))
	UPARAM(DisplayName = "Is Subscribed") bool IsEmailSubscribed() const;
	
	/**
	 * Get the user sms id
	 * @return sms id if user sms number was registered, otherwise null
	 */
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Get SMS User ID"))
	UPARAM(DisplayName = "ID") FString GetSmsUserId() const;

	/**
	 * Get the user sms number, number may start with + and continue with numbers or contain only numbers
	 * e.g: +11231231231 or 11231231231
	 * @return sms number if set, otherwise null
	 */
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Get SMS Number"))
	UPARAM(DisplayName = "Number") FString GetSmsNumber() const;

	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "Is SMS Subscribed"))
	UPARAM(DisplayName = "Is Subscribed") bool IsSMSSubscribed() const;

	// Convert the class into a NSDictionary
	UFUNCTION(BlueprintPure, Category = "OneSignal|DeviceState", Meta = (DisplayName = "To JSON"))
	UPARAM(DisplayName = "JSON") FString GetJsonRepresentation() const;

public:
	ONESIGNAL_NATIVE_OBJECT_DEFAULT_CTOR(DeviceState);

	~UOneSignalDeviceState();

private:
	OSDeviceState* Native = nullptr;
};

UCLASS(BlueprintType)
class ONESIGNAL_API UOneSignalNotification : public UObject
{
	GENERATED_BODY()
public:
	/* Unique Message Identifier */
	FString GetNotificationID() const;

	/* Unique Template Identifier */
	FString GetTemplateID() const;

	/* Name of Template */
	FString GetTemplateName() const;

	/* True when the key content-available is set to 1 in the apns payload.
	   content-available is used to wake your app when the payload is received.
	   See Apple's documenation for more details.
	  https://developer.apple.com/documentation/uikit/uiapplicationdelegate/1623013-application
	*/
	bool HasContentAvailable() const;

	/* True when the key mutable-content is set to 1 in the apns payload.
	 mutable-content is used to wake your Notification Service Extension to modify a notification.
	 See Apple's documenation for more details.
	 https://developer.apple.com/documentation/usernotifications/unnotificationserviceextension
	 */
	bool HasMutableContent() const;

	/*
	 Notification category key previously registered to display with.
	 This overrides OneSignal's actionButtons.
	 See Apple's documenation for more details.
	 https://developer.apple.com/library/content/documentation/NetworkingInternet/Conceptual/RemoteNotificationsPG/SupportingNotificationsinYourApp.html#//apple_ref/doc/uid/TP40008194-CH4-SW26
	*/
	FString GetCategory() const;

	/* The badge assigned to the application icon */
	int32 GetBadge();
	int32 GetBadgeIncrement() const;

	/* The sound parameter passed to the notification
	 By default set to UILocalNotificationDefaultSoundName */
	FString GetSound() const;

	/* Main push content */
	FString GetTitle() const;
	FString GetSubtitle() const;
	FString GetBody() const;

	/* Web address to launch within the app via a WKWebView */
	FString GetLaunchURL() const;

	/* Additional key value properties set within the payload */
	TMap<FString, FString> GetAdditionalData() const;

	/* iOS 10+ : Attachments sent as part of the rich notification */
	TMap<FString, FString> GetAttachments() const;

	/* Action buttons passed */
	TArray<FString> GetActionButtons() const;

	/* Holds the original payload received
	 Keep the raw value for users that would like to root the push */
	TMap<FString, FString> GetRawPayload() const;

	/* iOS 10+ : Groups notifications into threads */
	FString GetThreadID() const;

	/* iOS 15+ : Relevance Score for notification summary */
	double GetRelevanceScore() const;

	/* iOS 15+ : Interruption Level */
	FString GetInterruptionLevel() const;

	FString GetCollapseID() const;

	/* Convert object into an NSString that can be convertible into a custom Dictionary / JSON Object */
	FString Stringify() const;

public:
	ONESIGNAL_NATIVE_OBJECT_DEFAULT_CTOR(Notification);

	~UOneSignalNotification();

private:
	OSNotification* Native = nullptr;
};

using FOneSignalTags = TMap<FString, FString>;

DECLARE_DELEGATE_OneParam(FOneSignalUserResponseCallback, const bool /* bAccepted */);

DECLARE_DELEGATE_OneParam(FOneSignalTagsCallback, FOneSignalTags /* Tags */);

DECLARE_DELEGATE(FOneSignalSuccessCallback);

DECLARE_DELEGATE_OneParam(FOneSignalOutcomeSuccessCallback, FOneSignalOutcomeEvent /* Event */);

DECLARE_DELEGATE_TwoParams(FOneSignalFailureCallback, const int32 /* ErrorCode */, FString /* Message */);

DECLARE_MULTICAST_DELEGATE_OneParam(FOneSignalPermissionChanged, FOneSignalPermissionStateChanges /* StateChanges */);

DECLARE_MULTICAST_DELEGATE_OneParam(FOneSignalSubscriptionChanged, FOneSignalSubscriptionStateChanges/* StateChanges */);

DECLARE_MULTICAST_DELEGATE_OneParam(FOneSignalEmailSubscriptionChanged, FOneSignalEmailSubscriptionStateChanges/* StateChanges */);

DECLARE_MULTICAST_DELEGATE_OneParam(FOneSignalSMSSubscriptionChanged, FOneSignalSMSSubscriptionStateChanges/* StateChanges */);

UCLASS()
class ONESIGNAL_API UOneSignalLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// ------------------------------------ Initialization ------------------------------------

	/**
	 * Gets the OneSignal application ID.
	 * @return The OneSignal application ID.
	*/
	UFUNCTION(BlueprintPure, Category = "OneSignal|Initialization", Meta = (DisplayName = "Get Application ID - OneSignal"))
	static UPARAM(DisplayName = "Application ID") FString GetApplicationID();

	/**
	 * Gets the OneSignal SDK's version.
	 * @return The OneSignal SDK's version.
	*/
	UFUNCTION(BlueprintPure, Category = "OneSignal|Initialization", Meta = (DisplayName = "Get SDK Version - OneSignal"))
	static UPARAM(DisplayName = "Version") FString GetSDKVersion();

	UFUNCTION(BlueprintPure, Category = "OneSignal|Initialization", Meta = (DisplayName = "Get SDK Semantic Version - OneSignal"))
	static UPARAM(DisplayName = "Version") FString GetSDKSemanticVersion();

	/**
	 * Sets the OneSignal Application ID.
	 * @param ApplicationID The One Signal Application ID to set.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Initialization", Meta = (DisplayName = "Set Application ID - OneSignal"))
	static void SetAppID(const FString& ApplicationID);

	/**
	 * Sets the OneSignal Application ID.
	 * @param iOSApplicationID The One Signal Application ID to set when running iOS.
	 * @param AndroidApplicationID The One Signal Application ID to set when running Android.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Initialization", Meta = (DisplayName = "Set Platform Application ID - OneSignal"))
	static void SetPlatformAppID(UPARAM(DisplayName = "IOS Application ID") const FString& iOSApplicationID, const FString& AndroidApplicationID);

	/**
	 * Initializes the One Signal SDK.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Initialization", Meta = (DisplayName = "Initialize - OneSignal"))
	static void Initialize();

	/**
	 * Sets if launch URLs should be opened in safari or within the application. Set to true to launch all notifications with a URL 
	 * in the app instead of the default web browser. Make sure to call SetLaunchURLsInApp before the SetAppId call.
	 * @param bLaunchInApp Indicates if launch URLs should be opened in safari or within the application
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Initialization", Meta = (DisplayName = "Set Launches URLs in App (iOS) - OneSignal"))
	static void SetLaunchURLsInApp(const bool bLaunchInApp);

	/**
	 * Sets if OneSignal provides notification settings view.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Initialization", Meta = (DisplayName = "Set Provides Notification Settings View (iOS) - OneSignal"))
	static void SetProvidesNotificationSettingsView(const bool bProvidesView);

public:
	// ------------------------------------       Logging       ------------------------------------

	/**
	 * Sets the log level of the OneSignal SDK.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Logging", Meta = (DisplayName = "Set Log Level - OneSignal"))
	static void SetLogLevel(const EOneSignalLogLevel InLogLevel = EOneSignalLogLevel::Verbose, const EOneSignalLogLevel VisualLogLevel = EOneSignalLogLevel::None);

	/**
	 * Logs a message with OneSignal.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Logging", Meta = (DisplayName = "Log - OneSignal"))
	static void Log(const EOneSignalLogLevel InLogLevel = EOneSignalLogLevel::Verbose, const FString& Message = TEXT(""));

public:
	// ------------------------------------   Prompt For Push   ------------------------------------

	/**
	 * Prompts the user with the native push notification UI.
	 * @param Callback Callback called when the user made a choice.
	*/
	static void PromptForPushNotifications(FOneSignalUserResponseCallback Callback);
	static void PromptForPushNotifications(const bool bFallback, FOneSignalUserResponseCallback Callback);

	static void RegisterForProvisionalAuthorization(FOneSignalUserResponseCallback Callback);

	/**
	 * Returns an OSDeviceState object with the current immediate device state info. 
	 * @return An OSDeviceState object with the current immediate device state info. 
	*/
	UFUNCTION(BlueprintPure, Category = "OneSignal|Prompt For Push", Meta = (DisplayName = "Get Device State - OneSignal"))
	static UPARAM(DisplayName = "Device State") UOneSignalDeviceState* GetDeviceState();

public:
	// ------------------------------------   Privacy Consent   ------------------------------------

	/**
	 * If your application is set to require the user's privacy consent, you can provide this consent using this method. Until you call 
	 * SetConsentGranted(true), the SDK will not fully initialize, and will not send any data to OneSignal.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Privacy Consent", Meta = (DisplayName = "Set Consent Granted - OneSignal"))
	static void SetConsentGranted(const bool bGranted);
	
	/**
	 * For GDPR users, your application should call this method before initialization of the SDK.
	 *
	 * If you pass in true, your application will need to call provideConsent(true) before the OneSignal SDK gets fully initialized.
	 * Until this happens, you can continue to call methods (such as SendTags()), but nothing will happen.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Privacy Consent", Meta = (DisplayName = "Set Privacy Consent Required - OneSignal", keywords = "privacy consent required requires User Privacy Consent"))
	static void SetRequiresUserPrivacyConsent(const bool bRequired);
	
public:
	// ------------------------------------   Post Notification  ------------------------------------

	/**
	 * Posts a notification for delivery.
	 * @param JSONString The parameters of the notification.
	 * @param OnSuccess Callback called when the notification has been scheduled.
	 * @param OnFailure Callback called when an error occurred.
	*/
	static void PostNotification(const FString& JSONString, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

public:
	// ------------------------------------        Location       ------------------------------------

	/**
	 * Prompts the user for location permissions to allow geotagging from the OneSignal dashboard. 
	 * This lets you send notifications based on the device's location.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Location", Meta = (DisplayName = "Prompt Location - OneSignal"))
	static void PromptLocation();

	/**
	 * Returns a boolean that indicates location shared state (defaults to true if your app has location permission).
	 * @return A boolean that indicates location shared state (defaults to true if your app has location permission).
	*/
	UFUNCTION(BlueprintPure, Category = "OneSignal|Location", Meta = (DisplayName = "Is Location Shared - OneSignal"))
	static UPARAM(DisplayName = "Is Shared") bool IsLocationShared();

	/**
	 * Disables or enable location collection (defaults to enabled if your app has location permission).
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Location", Meta = (DisplayName = "Is Location Shared - OneSignal"))
	static void SetLocationShared(const bool bShared);

public:
	// ------------------------------------         Tags         ------------------------------------

	/**
	 * Tags a user based on an app event of your choosing so later you can later create segments to target these users. 
	 * Use sendTags over sendTag if you need to add or update more than one tag on a user at a time.
	 * @param Key The key of the tag.
	 * @param Value The value of the tag.
	 * @param OnSuccess Called if there were no errors sending the tag.
	 * @param OnFailure Called if there was an error.
	*/
	static void SendTag(const FString& Key, const FString& Value, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

	/**
	 * Tags a user based on an app event of your choosing, so that later you can create segments to target these users.
	 * @param Tags The tags we want to send.
	 * @param OnSuccess Called if there were no errors sending the tag.
	 * @param OnFailure Called if there was an error.
	*/
	static void SendTags(const FOneSignalTags& Tags, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

	/**
	 * Retrieves a list of tags as that have been set on the user from the OneSignal server.
	 * Android will provide a cached copy if there is no network connection.
	 * @param OnSuccess Called when the tags have been fetched.
	 * @param OnFailure Called when an error occurred.
	*/
	static void GetTags(FOneSignalTagsCallback OnSuccess, FOneSignalFailureCallback OnFailure = {});

	/**
	 * Deletes a single tag that was previously set on a user with sendTag or sendTags. Use deleteTags if you need to delete more than one.
	 * @param Key The key of the tag we want to delete.
	 * @param OnSuccess Callback called when the tags have been deleted.
	 * @param OnFailure Callback called when an error occurred.
	*/
	static void DeleteTag(const FString& Key, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});
	
	/**
	 * Deletes one or more tags that were previously set on a user with sendTag or sendTags.
	 * @param Keys The keys of the tags we want to delete.
	 * @param OnSuccess Callback called when the tags have been deleted.
	 * @param OnFailure Callback called when an error occurred.
	*/
	static void DeleteTags(const TArray<FString>& Keys, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

public:
	// ------------------------------------         Email         ------------------------------------

	/**
	 * Allows you to set the user's email address with the OneSignal SDK. We offer several overloaded versions of this method.
	 * It is best to call this when the user provides their email. If SetEmail was called previously and the user changes their email, 
	 * calling SetEmail again will update that record with the new email address.
	 * Email Auth Token is a (recommended) optional parameter that should *NOT* be generated on the client.
	 * For security purposes, the emailAuthToken should be generated by your backend server.
	 * If you do not have a backend server for your application, use the version of thge SetEmail method without an emailAuthToken parameter.
	*/
	static void SetEmailWithHashToken(const FString& Email, const FString& HashToken, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

	/**
	 * Allows you to set the user's email address with the OneSignal SDK. We offer several overloaded versions of this method.
     * It is best to call this when the user provides their email. If setEmail called previously and the user changes their email, 
     * callingsetEmail again will update that record with the new email address.
	*/
	static void SetEmail(const FString& Email, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

	/**
	 * If your app or website implements logout functionality, you can call LogOutEmail to dissociate the email from the device.
	 * @param OnSuccess Callback called when the logged out.
	 * @param OnFailure Callback called when an error occurred.
	*/
	static void LogOutEmail(FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

public:
	// ------------------------------------          SMS          ------------------------------------

	/**
	 * Allows you to set the SMS for this user. SMS number may start with + and continue with numbers or contain only numbers
	 * e.g: +11231231231 or 11231231231.
	 * @param SMS The SMS to set.
	 * @param HashToken A (recommended) optional parameter that should *NOT* be generated on the client.
	 * @param OnSuccess Callback called when the SMS has been set.
	 * @param OnFailure Callback called when an error occurred.
	*/
	static void SetSMSWithHashToken(const FString& SMS, const FString& HashToken, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

	/**
	 * Allows you to set the SMS for this user. SMS number may start with + and continue with numbers or contain only numbers
	 * e.g: +11231231231 or 11231231231.
	 * @param SMS The SMS to set.
	 * @param OnSuccess Callback called when the SMS has been set.
	 * @param OnFailure Callback called when an error occurred.
	*/
	static void SetSMS(const FString& SMS, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

	/**
	 * If your app or website implements logout functionality, you can call LogOutSMS to dissociate the SMS from the device.
	 * @param OnSuccess Callback called when the logged out.
	 * @param OnFailure Callback called when an error occurred.
	*/
	static void LogOutSMS(FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

public:
	// ------------------------------------        Language       ------------------------------------
	
	/**
	 * Language is detected and set automatically through the OneSignal SDK based on the device settings.
	 * This method allows you to change that language by passing in the 2-character, lowercase language code.
	 * @param Language The 2-character code of the new language.
	 * @param OnSuccess Callback called when the language has been set.
	 * @param OnFailure Callback called when an error occurred.
	*/
	static void SetLanguage(const FString& Language, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

public:
	// ------------------------------------    In-App Messaging   ------------------------------------
	
	/**
	 * Checks if in-app messaging is currently paused for the device.
	 * @return If in-app messaging is currently paused for the device.
	*/
	UFUNCTION(BlueprintPure, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Is In-App Messaging Paused - OneSignal"))
	static UPARAM(DisplayName = "Is Paused") bool IsInAppMessagingPaused();

	/**
	 * Allows you to temporarily pause all In-App Messages. You may want to do this while the user is engaged in an 
	 * activity that you don't want a message to interrupt (such as watching a video).
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Pause In-App Messaging - OneSignal"))
	static void PauseInAppMessages(const bool bPaused = true);

	/**
	 * Adds a trigger. May show an In-App Message if its trigger conditions were met.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Add Trigger - OneSignal"))
	static void AddTrigger(const FString& Key, const FString& Value);

	/**
	 * Adds a trigger. May show an In-App Message if its trigger conditions were met.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Add Int Trigger - OneSignal"))
	static void AddIntTrigger(const FString& Key, const int64 Value);

	/**
	 * Adds a map of triggers. May show an In-App Message if its trigger conditions were met.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Add Triggers - OneSignal"))
	static void AddTriggers(const TMap<FString, FString>& Triggers);

	/**
	 * Adds a map of triggers. May show an In-App Message if its trigger conditions were met.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Add Int Triggers - OneSignal"))
	static void AddIntTriggers(const TMap<FString, int64>& Triggers);

	/**
	 * Removes a single trigger for the given key. May show an In-App Message if its trigger conditions were met.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Remove Trigger - OneSignal", Keywords = "remove delete erase trigger"))
	static void RemoveTrigger(const FString& Key);

	/**
	 * Removes a list of triggers based on a collection of keys. May show an In-App Message if its trigger conditions were met.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Remove Triggers - OneSignal"))
	static void RemoveTriggers(const TArray<FString>& Keys);

	/**
	 * Gets all triggers as string.
	 * @return All the triggers, converted to string if needed.
	*/
	UFUNCTION(BlueprintPure, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Get Triggers - OneSignal"))
	static UPARAM(DisplayName = "Triggers") TMap<FString, FString> GetTriggers();

	/**
	 * Gets a trigger value for a provided trigger key. 
	*/
	UFUNCTION(BlueprintPure, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Get Trigger Value - OneSignal"))
	static UPARAM(DisplayName = "Value") FString GetTriggerValue(const FString& Key);

	/**
	 * Checks that a trigger value is set for a provided trigger key.
	*/
	UFUNCTION(BlueprintPure, Category = "OneSignal|In-App Messaging", Meta = (DisplayName = "Has Trigger Value - OneSignal"))
	static UPARAM(DisplayName = "Has Value") bool HasTriggerValue(const FString& Key);
	
public:
	// ------------------------------------    External User ID   ------------------------------------
	
	/**
	 * Sets the external user ID for the current user.
	 * @param UserID The external user ID.
	 * @param OnSuccess Callback called when the external user ID has been set.
	*/
	static void SetExternalUserID(const FString& UserID, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

	/**
	 * 
	 * Sets the external user ID for the current user.
	 * @param UserID The external user ID.
	 * @param OnSuccess Callback called when the external user ID has been set.
	 * @param OnFailure Callback called when an error occurred.
	*/
	static void SetExternalUserIDWithAuthHashToken(const FString& UserID, const FString& AuthHashToken, FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

	/**
	 * Removes a previously set external user ID.
	 * @param OnSuccess Called when the external user ID has been removed.
	 * @param OnFailure Callback called when an error occurred.
	*/
	static void RemoveExternalUserID(FOneSignalSuccessCallback OnSuccess = {}, FOneSignalFailureCallback OnFailure = {});

public:
	// ------------------------------------        Outcomes       ------------------------------------

	/**
	 * Sends an outcome through the OneSignal SDK.
	 * @param Name The name of the Outcome.
	 * @param OnSuccess Callback called when the outcome has been sent.
	*/
	static void SendOutcome(const FString& Name, FOneSignalOutcomeSuccessCallback OnSuccess = {});
	static void SendOutcome(const FString& Name, int32  Value, FOneSignalOutcomeSuccessCallback OnSuccess = {});
	static void SendOutcome(const FString& Name, int64  Value, FOneSignalOutcomeSuccessCallback OnSuccess = {});
	static void SendOutcome(const FString& Name, double Value, FOneSignalOutcomeSuccessCallback OnSuccess = {});
	static void SendOutcome(const FString& Name, float  Value, FOneSignalOutcomeSuccessCallback OnSuccess = {});

	/**
	 * Sends a unique outcome through the OneSignal SDK.
	 * @param Name The name of the outcome.
	 * @param OnSuccess Callback called when the outcome has been sent.
	*/
	static void SendUniqueOutcome(const FString& Name, FOneSignalOutcomeSuccessCallback OnSuccess = {});

public:
	// ----------------------- Permission, Subscription, and Email Observers --------------------------

	/**
	 * Event called when the permission state changed.
	*/
	static FOneSignalPermissionChanged& OnPermissionChanged();

	/**
	 * Event called when the subscription state changed.
	*/
	static FOneSignalSubscriptionChanged& OnSubscriptionChanged();

	/**
	 * Event called when the email subscription changed.
	*/
	static FOneSignalEmailSubscriptionChanged& OnEmailSubscriptionChanged();

	/**
	 * Event called when the SMS subscription changed.
	*/
	static FOneSignalSMSSubscriptionChanged& OnSMSSubscriptionChanged();

};

