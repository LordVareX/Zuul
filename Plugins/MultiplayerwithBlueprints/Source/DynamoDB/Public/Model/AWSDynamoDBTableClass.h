/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSDynamoDBTableClass.generated.h"

UENUM(BlueprintType)
enum class EAWSDynamoDBTableClass : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    STANDARD        UMETA(DisplayName = "standard"),
    STANDARD_INFREQUENT_ACCESS        UMETA(DisplayName = "standard infrequent access"),
};
