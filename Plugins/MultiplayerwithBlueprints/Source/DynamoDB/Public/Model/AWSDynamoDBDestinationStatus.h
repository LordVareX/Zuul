/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSDynamoDBDestinationStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSDynamoDBDestinationStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ENABLING        UMETA(DisplayName = "enabling"),
    ACTIVE        UMETA(DisplayName = "active"),
    DISABLING        UMETA(DisplayName = "disabling"),
    DISABLED        UMETA(DisplayName = "disabled"),
    ENABLE_FAILED        UMETA(DisplayName = "enable failed"),
};
