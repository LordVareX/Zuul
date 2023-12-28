/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "SSEType.generated.h"

UENUM(BlueprintType)
enum class EAWSSSEType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AES256        UMETA(DisplayName = "aes256"),
    KMS        UMETA(DisplayName = "kms"),
};
