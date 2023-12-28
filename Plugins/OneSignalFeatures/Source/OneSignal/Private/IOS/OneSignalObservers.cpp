// Copyright Pandores Marketplace 2023. All Rights Reserved.

#include "OneSignalObservers.h"
#include "OneSignal/OneSignalLibrary.h"
#include "Async/Async.h"

DECLARE_LOG_CATEGORY_CLASS(LogOneSignalObserver, Log, All);

@implementation FOneSignalPermissionObserver
- (void)onOSPermissionChanged:(OSPermissionStateChanges * _Nonnull)stateChanges
{
	FOneSignalPermissionStateChanges State;

	State.From.bReachable						= stateChanges.from.reachable;
	State.To  .bReachable						= stateChanges.to.reachable;
	State.From.bHasPrompted						= stateChanges.from.hasPrompted;
	State.To  .bHasPrompted						= stateChanges.to.hasPrompted;
	State.From.bProvidesAppNotificationSettings = stateChanges.from.providesAppNotificationSettings;
	State.To  .bProvidesAppNotificationSettings = stateChanges.to.providesAppNotificationSettings;
	State.From.Status							= (EOneSignalNotificationPermission)stateChanges.from.status;
	State.To  .Status							= (EOneSignalNotificationPermission)stateChanges.to.status;

	UE_LOG(LogOneSignalObserver, Log, TEXT("OneSignal permission changed."));

	AsyncTask(ENamedThreads::GameThread, [State]() -> void
	{
		UOneSignalLibrary::OnPermissionChanged().Broadcast(State);
	});
}
@end

@implementation FOneSignalSubscriptionObserver
- (void)onOSSubscriptionChanged:(OSSubscriptionStateChanges * _Nonnull)stateChanges
{
	FOneSignalSubscriptionStateChanges State;

	State.From.bIsSubscribed	= stateChanges.from.isSubscribed;
	State.To  .bIsSubscribed	= stateChanges.to  .isSubscribed;
	State.From.bIsPushDisabled	= stateChanges.from.isPushDisabled;
	State.To  .bIsPushDisabled	= stateChanges.to  .isPushDisabled;
	State.From.UserID			= stateChanges.from.userId;
	State.To  .UserID			= stateChanges.to  .userId;
	State.From.PushToken		= stateChanges.from.pushToken;
	State.To  .PushToken		= stateChanges.to  .pushToken;

	UE_LOG(LogOneSignalObserver, Log, TEXT("OneSignal subscription changed."));

	AsyncTask(ENamedThreads::GameThread, [State]() -> void
	{
		UOneSignalLibrary::OnSubscriptionChanged().Broadcast(State);
	});
}
@end

@implementation FOneSignalEmailSubscriptionObserver
- (void)onOSEmailSubscriptionChanged:(OSEmailSubscriptionStateChanges * _Nonnull)stateChanges
{
	FOneSignalEmailSubscriptionStateChanges State;

	State.From.EmailUserID   = stateChanges.from.emailUserId;
	State.To  .EmailUserID   = stateChanges.to  .emailUserId;
	State.From.EmailAddress  = stateChanges.from.emailAddress;
	State.To  .EmailAddress  = stateChanges.to  .emailAddress;
	State.From.bIsSubscribed = stateChanges.from.isSubscribed;
	State.To  .bIsSubscribed = stateChanges.to  .isSubscribed;
	
	UE_LOG(LogOneSignalObserver, Log, TEXT("OneSignal email subscription changed."));

	AsyncTask(ENamedThreads::GameThread, [State]() -> void
	{
		UOneSignalLibrary::OnEmailSubscriptionChanged().Broadcast(State);
	});
}
@end

@implementation FOneSignalSMSSubscriptionObserver
- (void)onOSSMSSubscriptionChanged:(OSSMSSubscriptionStateChanges* _Nonnull)stateChanges
{
	FOneSignalSMSSubscriptionStateChanges State;

	State.From.SMSUserID = stateChanges.from.smsUserId;
	State.To  .SMSUserID = stateChanges.to  .smsUserId;
	State.From.SMSNumber = stateChanges.from.smsNumber;
	State.To  .SMSNumber = stateChanges.to  .smsNumber;
	State.From.bIsSubscribed = stateChanges.from.isSubscribed;
	State.To  .bIsSubscribed = stateChanges.to  .isSubscribed;

	UE_LOG(LogOneSignalObserver, Log, TEXT("OneSignal SMS subscription changed."));

	AsyncTask(ENamedThreads::GameThread, [State]() -> void
	{
		UOneSignalLibrary::OnSMSSubscriptionChanged().Broadcast(State);
	});
}
@end
