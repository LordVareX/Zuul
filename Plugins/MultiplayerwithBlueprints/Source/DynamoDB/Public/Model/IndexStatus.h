/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "IndexStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSIndexStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CREATING        UMETA(DisplayName = "creating"),
    UPDATING        UMETA(DisplayName = "updating"),
    DELETING        UMETA(DisplayName = "deleting"),
    ACTIVE        UMETA(DisplayName = "active"),
};
