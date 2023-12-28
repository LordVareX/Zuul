/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSGameLiftComputeType.generated.h"

UENUM(BlueprintType)
enum class EAWSGameLiftComputeType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    EC2        UMETA(DisplayName = "ec2"),
    ANYWHERE        UMETA(DisplayName = "anywhere"),
};
