/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSDynamoDBInputCompressionType.generated.h"

UENUM(BlueprintType)
enum class EAWSDynamoDBInputCompressionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    GZIP        UMETA(DisplayName = "gzip"),
    ZSTD        UMETA(DisplayName = "zstd"),
    NONE        UMETA(DisplayName = "none"),
};
