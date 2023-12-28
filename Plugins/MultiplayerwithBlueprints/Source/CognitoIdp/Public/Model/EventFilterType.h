/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "EventFilterType.generated.h"

UENUM(BlueprintType)
enum class EEventFilterType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SIGN_IN        UMETA(DisplayName = "sign in"),
    PASSWORD_CHANGE        UMETA(DisplayName = "password change"),
    SIGN_UP        UMETA(DisplayName = "sign up")
};
