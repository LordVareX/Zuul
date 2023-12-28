/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "PointInTimeRecoveryStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSPointInTimeRecoveryStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ENABLED        UMETA(DisplayName = "enabled"),
    DISABLED        UMETA(DisplayName = "disabled"),
};
