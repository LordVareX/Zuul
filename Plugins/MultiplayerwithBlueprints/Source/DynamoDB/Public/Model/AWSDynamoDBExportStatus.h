/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSDynamoDBExportStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSDynamoDBExportStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    IN_PROGRESS        UMETA(DisplayName = "in progress"),
    COMPLETED        UMETA(DisplayName = "completed"),
    FAILED        UMETA(DisplayName = "failed"),
};
