/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "ProvisionedConcurrencyStatusEnum.generated.h"

UENUM(BlueprintType)
enum class EAWSProvisionedConcurrencyStatusEnum : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    IN_PROGRESS        UMETA(DisplayName = "in progress"),
    READY        UMETA(DisplayName = "ready"),
    FAILED        UMETA(DisplayName = "failed"),
};
