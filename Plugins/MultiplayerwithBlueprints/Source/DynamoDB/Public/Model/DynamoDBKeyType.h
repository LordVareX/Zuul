/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "DynamoDBKeyType.generated.h"

UENUM(BlueprintType)
enum class EAWSDynamoDBKeyType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    HASH        UMETA(DisplayName = "hash"),
    RANGE        UMETA(DisplayName = "range"),
};
