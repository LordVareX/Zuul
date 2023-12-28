/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSGameLiftLocationFilter.generated.h"

UENUM(BlueprintType)
enum class EAWSGameLiftLocationFilter : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AWS        UMETA(DisplayName = "aws"),
    CUSTOM        UMETA(DisplayName = "custom"),
};
