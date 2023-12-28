// Copyright Pandores Marketplace 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OneSignal/OneSignalLibrary.h"
#include "OneSignalBlueprintNodes.generated.h"

UCLASS()
class ONESIGNAL_API UOneSignalBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOSDynMulNoParam);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOSDynMulError, int32, ErrorCode, FString, ErrorMessage);

UCLASS()
class UOneSignalPromptForPushNotificationsProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The user accepted the request.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulNoParam Accepted;

	/**
	 * The user denied the request.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulNoParam Denied;

public:
	virtual void Activate() override;

	/**
	 * Prompts the user with the native push notification UI.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Prompt", meta = (DisplayName = "Prompt for Push Notifications - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalPromptForPushNotificationsProxy* PromptForPushNotifications();

private:
	void OnTaskOver(const bool bResult);
};

UCLASS()
class UOneSignalPostNotificationProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The notification has been posted.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Posted;
	
	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Posts a notification for delivery.
	 * @param JSONString The parameters of the notification.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Notification", meta = (DisplayName = "Post Notification - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalPostNotificationProxy* PostNotification(FString JSONString);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);

	FString Data;
};

UCLASS()
class UOneSignalSendTagProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The tag has been sent.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Sent;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Tags a user based on an app event of your choosing so later you can later create segments to target these users.
	 * Use sendTags over sendTag if you need to add or update more than one tag on a user at a time.
	 * @param Key The key of the tag.
	 * @param Value The value of the tag.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Tags", meta = (DisplayName = "Send Tag - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalSendTagProxy* SendTag(FString Key, FString Value);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);

	FString Key;
	FString Value;
};

UCLASS()
class UOneSignalSendTagsProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The tags have been sent.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Sent;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Tags a user based on an app event of your choosing, so that later you can create segments to target these users.
	 * @param Tags The tags we want to send.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Tags", meta = (DisplayName = "Send Tags - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalSendTagsProxy* SendTags(TMap<FString, FString> Tags);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
	
	TMap<FString, FString> Tags;
};


UCLASS()
class UOneSignalDeleteTagProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The tag has been deleted.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Deleted;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Deletes a single tag that was previously set on a user with sendTag or sendTags. Use deleteTags if you need to delete more than one.
	 * @param Key The key of the tag we want to delete.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Tags", meta = (DisplayName = "Delete Tag - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalDeleteTagProxy* DeleteTag(FString Key);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
	
	FString Key;
};

UCLASS()
class UOneSignalDeleteTagsProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The tags have been deleted.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Deleted;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Deletes one or more tags that were previously set on a user with sendTag or sendTags.
	 * @param Keys The keys of the tags we want to delete.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Tags", meta = (DisplayName = "Delete Tags - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalDeleteTagsProxy* DeleteTags(TArray<FString> Keys);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
	
	TArray<FString> Tags;
};

UCLASS()
class UOneSignalSetEmailWithHashTokenProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The email has been set.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Set;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Allows you to set the user's email address with the OneSignal SDK. We offer several overloaded versions of this method.
	 * It is best to call this when the user provides their email. If SetEmail was called previously and the user changes their email, 
	 * calling SetEmail again will update that record with the new email address.
	 * Email Auth Token is a (recommended) optional parameter that should *NOT* be generated on the client.
	 * For security purposes, the emailAuthToken should be generated by your backend server.
	 * If you do not have a backend server for your application, use the version of thge SetEmail method without an emailAuthToken parameter.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Email", meta = (DisplayName = "Set Email with Hash Token - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalSetEmailWithHashTokenProxy* SetEmailWithHashToken(FString Email, FString HashToken);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
	
	FString Email;
	FString HashToken;
};

UCLASS()
class UOneSignalSetEmailProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The email has been set.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Set;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Allows you to set the user's email address with the OneSignal SDK. We offer several overloaded versions of this method.
	 * It is best to call this when the user provides their email. If setEmail called previously and the user changes their email,
	 * callingsetEmail again will update that record with the new email address.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Email", meta = (DisplayName = "Set Email - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalSetEmailProxy* SetEmail(FString Email);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
	
	FString Email;
};

UCLASS()
class UOneSignalLogOutEmailProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The device was logged out email.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError LoggedOut;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * If your app or website implements logout functionality, you can call LogOutEmail to dissociate the email from the device.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Email", meta = (DisplayName = "Log Out Email - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalLogOutEmailProxy* LogOutEmail();

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
};


UCLASS()
class UOneSignalSetSMSWithHashTokenProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The SMS has been set.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Set;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Allows you to set the SMS for this user. SMS number may start with + and continue with numbers or contain only numbers
	 * e.g: +11231231231 or 11231231231.
	 * @param SMS The SMS to set.
	 * @param HashToken A (recommended) optional parameter that should *NOT* be generated on the client.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|SMS", meta = (DisplayName = "Set SMS with Hash Token - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalSetSMSWithHashTokenProxy* SetSMSWithHashToken(FString SMS, FString HashToken);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
	
	FString SMS;
	FString HashToken;
};

UCLASS()
class UOneSignalSetSMSProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The SMS has been set.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Set;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Allows you to set the SMS for this user. SMS number may start with + and continue with numbers or contain only numbers
	 * e.g: +11231231231 or 11231231231.
	 * @param SMS The SMS to set.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|SMS", meta = (DisplayName = "Set SMS - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalSetSMSProxy* SetSMS(FString SMS);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
	
	FString SMS;
};

UCLASS()
class UOneSignalLogOutSMSProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The device was logged out SMS.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError LoggedOut;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * If your app or website implements logout functionality, you can call LogOutSMS to dissociate the SMS from the device.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|SMS", meta = (DisplayName = "Log Out SMS - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalLogOutSMSProxy* LogOutSMS();

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
};


UCLASS()
class UOneSignalSetExternalUserIDWithHashTokenProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The ExternalUserID has been set.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Set;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Sets the external user ID for the current user.
	 * @param UserID The external user ID.
	 * @param HashToken A (recommended) optional parameter that should *NOT* be generated on the client.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|ExternalUserID", meta = (DisplayName = "Set External User ID with Hash Token - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalSetExternalUserIDWithHashTokenProxy* SetExternalUserIDWithHashToken(FString ExternalUserID, FString HashToken);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
	
	FString ExternalUserID;
	FString HashToken;
};

UCLASS()
class UOneSignalSetExternalUserIDProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The ExternalUserID has been set.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Set;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Sets the external user ID for the current user.
	 * @param UserID The external user ID.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|ExternalUserID", meta = (DisplayName = "Set External User ID - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalSetExternalUserIDProxy* SetExternalUserID(FString ExternalUserID);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
	
	FString ExternalUserID;
};

UCLASS()
class UOneSignalLogOutExternalUserIDProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The device was logged out ExternalUserID.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError LoggedOut;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Removes a previously set external user ID.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|ExternalUserID", meta = (DisplayName = "Remove External User ID - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalLogOutExternalUserIDProxy* RemoveExternalUserID();

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);
};

UCLASS()
class UOneSignalSetLanguageProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The language was set.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Set;

	/**
	 * An error occurred.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSDynMulError Error;

public:
	virtual void Activate() override;

	/**
	 * Language is detected and set automatically through the OneSignal SDK based on the device settings.
	 * This method allows you to change that language by passing in the 2-character, lowercase language code.
	 * @param Language The 2-character code of the new language.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Language", meta = (DisplayName = "Set Language - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalSetLanguageProxy* SetLanguage(FString Language);

private:
	void OnTaskOver();
	void OnError(const int32 ErrorCode, FString Message);

	FString Language;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOSOutcomeDynMult, const FOneSignalOutcomeEvent&, Outcome);

UCLASS()
class USendOutcomeProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	/**
	 * The outcome has been sent.
	*/
	UPROPERTY(BlueprintAssignable)
	FOSOutcomeDynMult Sent;

public:
	virtual void Activate() override;

	/**
	 * Sends an outcome through the OneSignal SDK.
	 * @param Name The name of the Outcome.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Outcomes", meta = (DisplayName = "Send Outcome - OneSignal", BlueprintInternalUseOnly = "true"))
	static USendOutcomeProxy* SendOutcome(FString Name);

	/**
	 * Sends an outcome through the OneSignal SDK.
	 * @param Name The name of the Outcome.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Outcomes", meta = (DisplayName = "Send Float Outcome - OneSignal", BlueprintInternalUseOnly = "true"))
	static USendOutcomeProxy* SendFloatOutcome(FString Name, float Value);
	
	/**
	 * Sends an outcome through the OneSignal SDK.
	 * @param Name The name of the Outcome.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Outcomes", meta = (DisplayName = "Send Int32 Outcome - OneSignal", BlueprintInternalUseOnly = "true"))
	static USendOutcomeProxy* SendInt32Outcome(FString Name, int32 Value);
	
	/**
	 * Sends an outcome through the OneSignal SDK.
	 * @param Name The name of the Outcome.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Outcomes", meta = (DisplayName = "Send Int64 Outcome - OneSignal", BlueprintInternalUseOnly = "true"))
	static USendOutcomeProxy* SendInt64Outcome(FString Name, int64 Value);

	/**
	 * Sends a unique outcome through the OneSignal SDK.
	 * @param Name The name of the outcome.
	*/
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Outcomes", meta = (DisplayName = "Send Unique Outcome - OneSignal", BlueprintInternalUseOnly = "true"))
	static USendOutcomeProxy* SendUniqueOutcome(FString Name);

private:

	enum EOutcomeType
	{
		UNIQUE,
		NONE,
		FLOAT,
		INT32,
		INT64
	} OutcomeType;

	static USendOutcomeProxy* Create(FString&& Name, EOutcomeType Type);

	void OnTaskOver(FOneSignalOutcomeEvent);

	FString Name;
	float FloatValue;
	int32 Int32Value;
	int64 Int64Value;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneSignalPermissionStateChangesEvent, const FOneSignalPermissionStateChanges&, PermissionState);

UCLASS()
class UOneSignalOnPermissionChanged : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	/**
	 * The state has changed.
	*/
	UPROPERTY(BlueprintAssignable)
	FOneSignalPermissionStateChangesEvent OnStateChanged;

public:
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Observers", meta = (DisplayName = "On Permission Changed - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalOnPermissionChanged* OnChanged();

private:
	void OnTaskOver(FOneSignalPermissionStateChanges State);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneSignalEmailStateChangesEvent, const FOneSignalEmailSubscriptionStateChanges&, EmailSubscriptionState);

UCLASS()
class UOneSignalOnEmailSubscriptionChanged: public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	/**
	 * The state has changed.
	*/
	UPROPERTY(BlueprintAssignable)
	FOneSignalEmailStateChangesEvent OnStateChanged;

public:
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Observers", meta = (DisplayName = "On Email Subscription Changed - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalOnEmailSubscriptionChanged* OnChanged();

private:
	void OnTaskOver(FOneSignalEmailSubscriptionStateChanges State);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneSignalSMSStateChangesEvent, const FOneSignalSMSSubscriptionStateChanges&, SMSSubscriptionState);

UCLASS()
class UOneSignalOnSMSSubscriptionChanged: public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	/**
	 * The state has changed.
	*/
	UPROPERTY(BlueprintAssignable)
	FOneSignalSMSStateChangesEvent OnStateChanged;

public:
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Observers", meta = (DisplayName = "On SMS Subscription Changed - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalOnSMSSubscriptionChanged* OnChanged();

private:
	void OnTaskOver(FOneSignalSMSSubscriptionStateChanges State);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneSignalStateChangesEvent, const FOneSignalSubscriptionStateChanges&, SubscriptionState);

UCLASS()
class UOneSignalOnSubscriptionChanged: public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:

	/**
	 * The state has changed.
	*/
	UPROPERTY(BlueprintAssignable)
	FOneSignalStateChangesEvent OnStateChanged;

public:
	UFUNCTION(BlueprintCallable, Category = "OneSignal|Observers", meta = (DisplayName = "On  Subscription Changed - OneSignal", BlueprintInternalUseOnly = "true"))
	static UOneSignalOnSubscriptionChanged* OnChanged();

private:
	void OnTaskOver(FOneSignalSubscriptionStateChanges State);
};






