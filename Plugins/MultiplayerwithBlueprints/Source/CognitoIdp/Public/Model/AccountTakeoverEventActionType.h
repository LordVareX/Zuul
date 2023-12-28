/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "AccountTakeoverEventActionType.generated.h"

UENUM(BlueprintType)
enum class EAccountTakeoverEventActionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    BLOCK        UMETA(DisplayName = "block"),
    MFA_IF_CONFIGURED        UMETA(DisplayName = "mfa if configured"),
    MFA_REQUIRED        UMETA(DisplayName = "mfa required"),
    NO_ACTION        UMETA(DisplayName = "no action")
};
