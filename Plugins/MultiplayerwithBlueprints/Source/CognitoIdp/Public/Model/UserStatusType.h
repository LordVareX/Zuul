/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "UserStatusType.generated.h"

UENUM(BlueprintType)
enum class EUserStatusType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    UNCONFIRMED        UMETA(DisplayName = "unconfirmed"),
    CONFIRMED        UMETA(DisplayName = "confirmed"),
    ARCHIVED        UMETA(DisplayName = "archived"),
    COMPROMISED        UMETA(DisplayName = "compromised"),
    UNKNOWN        UMETA(DisplayName = "unknown"),
    RESET_REQUIRED        UMETA(DisplayName = "reset required"),
    FORCE_CHANGE_PASSWORD        UMETA(DisplayName = "force change password")
};
