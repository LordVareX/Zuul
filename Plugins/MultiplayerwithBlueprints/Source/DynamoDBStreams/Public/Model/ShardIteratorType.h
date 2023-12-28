/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ShardIteratorType.generated.h"

UENUM(BlueprintType)
enum class EAWSShardIteratorType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    TRIM_HORIZON        UMETA(DisplayName = "trim horizon"),
    LATEST        UMETA(DisplayName = "latest"),
    AT_SEQUENCE_NUMBER        UMETA(DisplayName = "at sequence number"),
    AFTER_SEQUENCE_NUMBER        UMETA(DisplayName = "after sequence number"),
};
