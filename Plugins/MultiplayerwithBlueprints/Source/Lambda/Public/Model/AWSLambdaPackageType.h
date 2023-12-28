/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSLambdaPackageType.generated.h"

UENUM(BlueprintType)
enum class EAWSLambdaPackageType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Zip        UMETA(DisplayName = "zip"),
    Image        UMETA(DisplayName = "image"),
};
