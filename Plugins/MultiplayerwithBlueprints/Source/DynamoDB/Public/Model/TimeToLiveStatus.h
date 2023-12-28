/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "TimeToLiveStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSTimeToLiveStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ENABLING        UMETA(DisplayName = "enabling"),
    DISABLING        UMETA(DisplayName = "disabling"),
    ENABLED        UMETA(DisplayName = "enabled"),
    DISABLED        UMETA(DisplayName = "disabled"),
};
