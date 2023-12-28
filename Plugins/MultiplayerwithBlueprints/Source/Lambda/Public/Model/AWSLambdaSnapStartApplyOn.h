/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSLambdaSnapStartApplyOn.generated.h"

UENUM(BlueprintType)
enum class EAWSLambdaSnapStartApplyOn : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    PublishedVersions        UMETA(DisplayName = "publishedversions"),
    None        UMETA(DisplayName = "none"),
};
