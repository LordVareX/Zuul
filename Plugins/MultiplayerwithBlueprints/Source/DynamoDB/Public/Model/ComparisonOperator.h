/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ComparisonOperator.generated.h"

UENUM(BlueprintType)
enum class EAWSComparisonOperator : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    EQ        UMETA(DisplayName = "equal"),
    NE        UMETA(DisplayName = "not equal"),
    IN_        UMETA(DisplayName = "in"),
    LE        UMETA(DisplayName = "less or equal"),
    LT        UMETA(DisplayName = "less than"),
    GE        UMETA(DisplayName = "greater or equal"),
    GT        UMETA(DisplayName = "greater than"),
    BETWEEN        UMETA(DisplayName = "between"),
    NOT_NULL        UMETA(DisplayName = "not null"),
    NULL_        UMETA(DisplayName = "null"),
    CONTAINS        UMETA(DisplayName = "contains"),
    NOT_CONTAINS        UMETA(DisplayName = "not contains"),
    BEGINS_WITH        UMETA(DisplayName = "begins with"),
};
