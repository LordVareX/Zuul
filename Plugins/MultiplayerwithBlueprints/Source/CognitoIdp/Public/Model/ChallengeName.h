/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ChallengeName.generated.h"

UENUM(BlueprintType)
enum class EChallengeName : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Password        UMETA(DisplayName = "password"),
    Mfa        UMETA(DisplayName = "mfa")
};
