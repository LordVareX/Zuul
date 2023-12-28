/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSDynamoDBImportStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSDynamoDBImportStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    IN_PROGRESS        UMETA(DisplayName = "in progress"),
    COMPLETED        UMETA(DisplayName = "completed"),
    CANCELLING        UMETA(DisplayName = "cancelling"),
    CANCELLED        UMETA(DisplayName = "cancelled"),
    FAILED        UMETA(DisplayName = "failed"),
};
