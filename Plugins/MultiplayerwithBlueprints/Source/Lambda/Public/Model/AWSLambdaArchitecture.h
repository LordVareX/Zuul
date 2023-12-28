/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSLambdaArchitecture.generated.h"

UENUM(BlueprintType)
enum class EAWSLambdaArchitecture : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    x86_64        UMETA(DisplayName = "x86 64"),
    arm64        UMETA(DisplayName = "arm64"),
};
