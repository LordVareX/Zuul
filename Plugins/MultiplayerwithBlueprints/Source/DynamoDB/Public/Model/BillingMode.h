/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "BillingMode.generated.h"

UENUM(BlueprintType)
enum class EAWSBillingMode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    PROVISIONED        UMETA(DisplayName = "provisioned"),
    PAY_PER_REQUEST        UMETA(DisplayName = "pay per request"),
};
