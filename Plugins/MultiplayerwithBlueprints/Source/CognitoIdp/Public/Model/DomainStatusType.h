/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "DomainStatusType.generated.h"

UENUM(BlueprintType)
enum class EDomainStatusType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CREATING        UMETA(DisplayName = "creating"),
    DELETING        UMETA(DisplayName = "deleting"),
    UPDATING        UMETA(DisplayName = "updating"),
    ACTIVE        UMETA(DisplayName = "active"),
    FAILED        UMETA(DisplayName = "failed")
};
