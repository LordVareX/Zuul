/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ReturnValuesOnConditionCheckFailure.generated.h"

UENUM(BlueprintType)
enum class EAWSReturnValuesOnConditionCheckFailure : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ALL_OLD        UMETA(DisplayName = "all old"),
    NONE        UMETA(DisplayName = "none"),
};
