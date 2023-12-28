/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSDynamoDBExportFormat.generated.h"

UENUM(BlueprintType)
enum class EAWSDynamoDBExportFormat : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    DYNAMODB_JSON        UMETA(DisplayName = "dynamodb json"),
    ION        UMETA(DisplayName = "ion"),
};
