// Copyright Pandores Marketplace 2023. All Rights Reserved.

#include "OneSignalBlueprintNodes.h"

UOneSignalPromptForPushNotificationsProxy* UOneSignalPromptForPushNotificationsProxy::PromptForPushNotifications()
{
	return NewObject<ThisClass>();
}

void UOneSignalPromptForPushNotificationsProxy::Activate()
{
	UOneSignalLibrary::PromptForPushNotifications(FOneSignalUserResponseCallback::CreateUObject(this, &ThisClass::OnTaskOver));
}

void UOneSignalPromptForPushNotificationsProxy::OnTaskOver(const bool bResult)
{
	(bResult ? Accepted : Denied).Broadcast();
	SetReadyToDestroy();
}

UOneSignalPostNotificationProxy* UOneSignalPostNotificationProxy::PostNotification(FString JSONString)
{
	ThisClass* Proxy = NewObject<ThisClass>();

	Proxy->Data = MoveTemp(JSONString);

	return Proxy;
}

void UOneSignalPostNotificationProxy::Activate()
{
	UOneSignalLibrary::PostNotification(Data, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalPostNotificationProxy::OnTaskOver()
{
	Posted.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalPostNotificationProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalSendTagProxy* UOneSignalSendTagProxy::SendTag(FString Key, FString Value)
{
	ThisClass* const Proxy = NewObject<ThisClass>();

	Proxy->Key = MoveTemp(Key);
	Proxy->Value = MoveTemp(Value);

	return Proxy;
}

void UOneSignalSendTagProxy::Activate()
{
	UOneSignalLibrary::SendTag(Key, Value, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver), 
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalSendTagProxy::OnTaskOver()
{
	Sent.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalSendTagProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalSendTagsProxy* UOneSignalSendTagsProxy::SendTags(TMap<FString, FString> Tags)
{
	UOneSignalSendTagsProxy* const Proxy = NewObject<UOneSignalSendTagsProxy>();

	Proxy->Tags = MoveTemp(Tags);

	return Proxy;
}

void UOneSignalSendTagsProxy::Activate()
{
	UOneSignalLibrary::SendTags(Tags, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalSendTagsProxy::OnTaskOver()
{
	Sent.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalSendTagsProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalDeleteTagProxy* UOneSignalDeleteTagProxy::DeleteTag(FString Key)
{
	UOneSignalDeleteTagProxy* const Proxy = NewObject<UOneSignalDeleteTagProxy>();

	Proxy->Key = MoveTemp(Key);

	return Proxy;
}

void UOneSignalDeleteTagProxy::Activate()
{
	UOneSignalLibrary::DeleteTag(Key, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalDeleteTagProxy::OnTaskOver()
{
	Deleted.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalDeleteTagProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalDeleteTagsProxy* UOneSignalDeleteTagsProxy::DeleteTags(TArray<FString> Tags)
{
	ThisClass* const Proxy = NewObject<ThisClass>();

	Proxy->Tags = MoveTemp(Tags);

	return Proxy;
}

void UOneSignalDeleteTagsProxy::Activate()
{
	UOneSignalLibrary::DeleteTags(Tags, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalDeleteTagsProxy::OnTaskOver()
{
	Deleted.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalDeleteTagsProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalSetEmailWithHashTokenProxy* UOneSignalSetEmailWithHashTokenProxy::SetEmailWithHashToken(FString Email, FString HashToken)
{
	ThisClass* const Proxy = NewObject<ThisClass>();

	Proxy->Email = MoveTemp(Email);
	Proxy->HashToken = MoveTemp(HashToken);

	return Proxy;
}

void UOneSignalSetEmailWithHashTokenProxy::Activate()
{
	UOneSignalLibrary::SetEmailWithHashToken(Email, HashToken, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalSetEmailWithHashTokenProxy::OnTaskOver()
{
	Set.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalSetEmailWithHashTokenProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalSetEmailProxy* UOneSignalSetEmailProxy::SetEmail(FString Email)
{
	ThisClass* const Proxy = NewObject<ThisClass>();

	Proxy->Email = MoveTemp(Email);

	return Proxy;
}

void UOneSignalSetEmailProxy::Activate()
{
	UOneSignalLibrary::SetEmail(Email, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalSetEmailProxy::OnTaskOver()
{
	Set.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalSetEmailProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalLogOutEmailProxy* UOneSignalLogOutEmailProxy::LogOutEmail()
{
	return NewObject<ThisClass>();
}

void UOneSignalLogOutEmailProxy::Activate()
{
	UOneSignalLibrary::LogOutEmail(FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalLogOutEmailProxy::OnTaskOver()
{
	LoggedOut.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalLogOutEmailProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}


UOneSignalSetSMSWithHashTokenProxy* UOneSignalSetSMSWithHashTokenProxy::SetSMSWithHashToken(FString SMS, FString HashToken)
{
	ThisClass* const Proxy = NewObject<ThisClass>();

	Proxy->SMS = MoveTemp(SMS);
	Proxy->HashToken = MoveTemp(HashToken);

	return Proxy;
}

void UOneSignalSetSMSWithHashTokenProxy::Activate()
{
	UOneSignalLibrary::SetSMSWithHashToken(SMS, HashToken, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalSetSMSWithHashTokenProxy::OnTaskOver()
{
	Set.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalSetSMSWithHashTokenProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalSetSMSProxy* UOneSignalSetSMSProxy::SetSMS(FString SMS)
{
	ThisClass* const Proxy = NewObject<ThisClass>();

	Proxy->SMS = MoveTemp(SMS);

	return Proxy;
}

void UOneSignalSetSMSProxy::Activate()
{
	UOneSignalLibrary::SetSMS(SMS, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalSetSMSProxy::OnTaskOver()
{
	Set.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalSetSMSProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalLogOutSMSProxy* UOneSignalLogOutSMSProxy::LogOutSMS()
{
	return NewObject<ThisClass>();
}

void UOneSignalLogOutSMSProxy::Activate()
{
	UOneSignalLibrary::LogOutSMS(FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalLogOutSMSProxy::OnTaskOver()
{
	LoggedOut.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalLogOutSMSProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}



UOneSignalSetExternalUserIDWithHashTokenProxy* UOneSignalSetExternalUserIDWithHashTokenProxy::SetExternalUserIDWithHashToken(FString ExternalUserID, FString HashToken)
{
	ThisClass* const Proxy = NewObject<ThisClass>();

	Proxy->ExternalUserID = MoveTemp(ExternalUserID);
	Proxy->HashToken = MoveTemp(HashToken);

	return Proxy;
}

void UOneSignalSetExternalUserIDWithHashTokenProxy::Activate()
{
	UOneSignalLibrary::SetExternalUserIDWithAuthHashToken(ExternalUserID, HashToken, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalSetExternalUserIDWithHashTokenProxy::OnTaskOver()
{
	Set.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalSetExternalUserIDWithHashTokenProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalSetExternalUserIDProxy* UOneSignalSetExternalUserIDProxy::SetExternalUserID(FString ExternalUserID)
{
	ThisClass* const Proxy = NewObject<ThisClass>();

	Proxy->ExternalUserID = MoveTemp(ExternalUserID);

	return Proxy;
}

void UOneSignalSetExternalUserIDProxy::Activate()
{
	UOneSignalLibrary::SetExternalUserID(ExternalUserID, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalSetExternalUserIDProxy::OnTaskOver()
{
	Set.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalSetExternalUserIDProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalLogOutExternalUserIDProxy* UOneSignalLogOutExternalUserIDProxy::RemoveExternalUserID()
{
	return NewObject<ThisClass>();
}

void UOneSignalLogOutExternalUserIDProxy::Activate()
{
	UOneSignalLibrary::RemoveExternalUserID(FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalLogOutExternalUserIDProxy::OnTaskOver()
{
	LoggedOut.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalLogOutExternalUserIDProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

UOneSignalSetLanguageProxy* UOneSignalSetLanguageProxy::SetLanguage(FString Language)
{
	ThisClass* const Proxy = NewObject<ThisClass>();

	Proxy->Language = MoveTemp(Language);

	return Proxy;
}

void UOneSignalSetLanguageProxy::Activate()
{
	UOneSignalLibrary::SetLanguage(Language, FOneSignalSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver),
		FOneSignalFailureCallback::CreateUObject(this, &ThisClass::OnError));
}

void UOneSignalSetLanguageProxy::OnTaskOver()
{
	Set.Broadcast(0, {});
	SetReadyToDestroy();
}

void UOneSignalSetLanguageProxy::OnError(const int32 ErrorCode, FString Message)
{
	Error.Broadcast(ErrorCode, Message);
	SetReadyToDestroy();
}

USendOutcomeProxy* USendOutcomeProxy::Create(FString&& Name, EOutcomeType Type)
{
	ThisClass* const Proxy = NewObject<ThisClass>();

	Proxy->OutcomeType = Type;
	Proxy->Name = MoveTemp(Name);

	return Proxy;
}

USendOutcomeProxy* USendOutcomeProxy::SendOutcome(FString Name)
{
	return Create(MoveTemp(Name), NONE);
}

USendOutcomeProxy* USendOutcomeProxy::SendUniqueOutcome(FString Name)
{
	return Create(MoveTemp(Name), UNIQUE);
}

USendOutcomeProxy* USendOutcomeProxy::SendFloatOutcome(FString Name, float Value)
{
	ThisClass* const Proxy = Create(MoveTemp(Name), FLOAT);

	Proxy->FloatValue = Value;

	return Proxy;
}

USendOutcomeProxy* USendOutcomeProxy::SendInt32Outcome(FString Name, int32 Value)
{
	ThisClass* const Proxy = Create(MoveTemp(Name), INT32);

	Proxy->Int32Value = Value;

	return Proxy;
}

USendOutcomeProxy* USendOutcomeProxy::SendInt64Outcome(FString Name, int64 Value)
{
	ThisClass* const Proxy = Create(MoveTemp(Name), INT64);

	Proxy->Int64Value = Value;

	return Proxy;
}

void USendOutcomeProxy::OnTaskOver(FOneSignalOutcomeEvent Event)
{
	Sent.Broadcast(Event);
	SetReadyToDestroy();
}

void USendOutcomeProxy::Activate()
{
	auto Callback = FOneSignalOutcomeSuccessCallback::CreateUObject(this, &ThisClass::OnTaskOver);

	switch (OutcomeType)
	{
	case NONE: UOneSignalLibrary::SendOutcome(Name, MoveTemp(Callback));			  break;
	case FLOAT: UOneSignalLibrary::SendOutcome(Name, FloatValue, MoveTemp(Callback)); break;
	case INT32: UOneSignalLibrary::SendOutcome(Name, Int32Value, MoveTemp(Callback)); break;
	case INT64: UOneSignalLibrary::SendOutcome(Name, Int64Value, MoveTemp(Callback)); break;
	case UNIQUE: UOneSignalLibrary::SendUniqueOutcome(Name, MoveTemp(Callback)); break;
	default:
		check(0);
	}
}

UOneSignalOnPermissionChanged* UOneSignalOnPermissionChanged::OnChanged()
{
	static TWeakObjectPtr<ThisClass> Proxy;

	if (!Proxy.IsValid())
	{
		ThisClass* const RawProxy = NewObject<ThisClass>();

		UOneSignalLibrary::OnPermissionChanged().AddUObject(RawProxy, &ThisClass::OnTaskOver);

		Proxy = RawProxy;
	}

	return Proxy.Get();
}

void UOneSignalOnPermissionChanged::OnTaskOver(FOneSignalPermissionStateChanges State)
{
	OnStateChanged.Broadcast(State);
}


UOneSignalOnEmailSubscriptionChanged* UOneSignalOnEmailSubscriptionChanged::OnChanged()
{
	static TWeakObjectPtr<ThisClass> Proxy;

	if (!Proxy.IsValid())
	{
		ThisClass* const RawProxy = NewObject<ThisClass>();

		UOneSignalLibrary::OnEmailSubscriptionChanged().AddUObject(RawProxy, &ThisClass::OnTaskOver);

		Proxy = RawProxy;
	}

	return Proxy.Get();
}

void UOneSignalOnEmailSubscriptionChanged::OnTaskOver(FOneSignalEmailSubscriptionStateChanges State)
{
	OnStateChanged.Broadcast(State);
}

UOneSignalOnSMSSubscriptionChanged* UOneSignalOnSMSSubscriptionChanged::OnChanged()
{
	static TWeakObjectPtr<ThisClass> Proxy;

	if (!Proxy.IsValid())
	{
		ThisClass* const RawProxy = NewObject<ThisClass>();

		UOneSignalLibrary::OnSMSSubscriptionChanged().AddUObject(RawProxy, &ThisClass::OnTaskOver);

		Proxy = RawProxy;
	}

	return Proxy.Get();
}

void UOneSignalOnSMSSubscriptionChanged::OnTaskOver(FOneSignalSMSSubscriptionStateChanges State)
{
	OnStateChanged.Broadcast(State);
}

UOneSignalOnSubscriptionChanged* UOneSignalOnSubscriptionChanged::OnChanged()
{
	static TWeakObjectPtr<ThisClass> Proxy;

	if (!Proxy.IsValid())
	{
		ThisClass* const RawProxy = NewObject<ThisClass>();

		UOneSignalLibrary::OnSubscriptionChanged().AddUObject(RawProxy, &ThisClass::OnTaskOver);

		Proxy = RawProxy;
	}

	return Proxy.Get();
}

void UOneSignalOnSubscriptionChanged::OnTaskOver(FOneSignalSubscriptionStateChanges State)
{
	OnStateChanged.Broadcast(State);
}


