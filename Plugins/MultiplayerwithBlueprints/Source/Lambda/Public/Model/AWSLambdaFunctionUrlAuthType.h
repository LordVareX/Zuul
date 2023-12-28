/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSLambdaFunctionUrlAuthType.generated.h"

UENUM(BlueprintType)
enum class EAWSLambdaFunctionUrlAuthType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    NONE        UMETA(DisplayName = "none"),
    AWS_IAM        UMETA(DisplayName = "aws iam"),
};
