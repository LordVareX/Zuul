/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSGameLiftComputeStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSGameLiftComputeStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    PENDING        UMETA(DisplayName = "pending"),
    ACTIVE        UMETA(DisplayName = "active"),
    TERMINATING        UMETA(DisplayName = "terminating"),
};
