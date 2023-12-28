/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "State.generated.h"

UENUM(BlueprintType)
enum class EAWSState : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Pending        UMETA(DisplayName = "pending"),
    Active        UMETA(DisplayName = "active"),
    Inactive        UMETA(DisplayName = "inactive"),
    Failed        UMETA(DisplayName = "failed"),
};
