// Copyright Pandores Marketplace 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#import <OneSignal/OneSignal.h>

@interface FOneSignalPermissionObserver : NSObject <OSPermissionObserver>
@end

@interface FOneSignalSubscriptionObserver : NSObject <OSSubscriptionObserver>
@end

@interface FOneSignalEmailSubscriptionObserver : NSObject <OSEmailSubscriptionObserver>
@end

@interface FOneSignalSMSSubscriptionObserver : NSObject <OSSMSSubscriptionObserver>
@end

