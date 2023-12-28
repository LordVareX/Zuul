/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSLambdaCodeSigningPolicy.generated.h"

UENUM(BlueprintType)
enum class EAWSLambdaCodeSigningPolicy : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Warn        UMETA(DisplayName = "warn"),
    Enforce        UMETA(DisplayName = "enforce"),
};
