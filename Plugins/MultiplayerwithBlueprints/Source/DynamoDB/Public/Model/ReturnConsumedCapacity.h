/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ReturnConsumedCapacity.generated.h"

UENUM(BlueprintType)
enum class EAWSReturnConsumedCapacity : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    INDEXES        UMETA(DisplayName = "indexes"),
    TOTAL        UMETA(DisplayName = "total"),
    NONE        UMETA(DisplayName = "none"),
};
