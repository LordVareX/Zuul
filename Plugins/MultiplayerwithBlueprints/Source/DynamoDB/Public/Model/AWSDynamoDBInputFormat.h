/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSDynamoDBInputFormat.generated.h"

UENUM(BlueprintType)
enum class EAWSDynamoDBInputFormat : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    DYNAMODB_JSON        UMETA(DisplayName = "dynamodb json"),
    ION        UMETA(DisplayName = "ion"),
    CSV        UMETA(DisplayName = "csv"),
};
