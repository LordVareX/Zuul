/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSDynamoDBS3SseAlgorithm.generated.h"

UENUM(BlueprintType)
enum class EAWSDynamoDBS3SseAlgorithm : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AES256        UMETA(DisplayName = "aes256"),
    KMS        UMETA(DisplayName = "kms"),
};
