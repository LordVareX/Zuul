/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ReturnItemCollectionMetrics.generated.h"

UENUM(BlueprintType)
enum class EAWSReturnItemCollectionMetrics : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SIZE        UMETA(DisplayName = "size"),
    NONE        UMETA(DisplayName = "none"),
};
