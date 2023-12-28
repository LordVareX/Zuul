/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "DeliveryMediumType.generated.h"

UENUM(BlueprintType)
enum class EDeliveryMediumType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SMS        UMETA(DisplayName = "sms"),
    EMAIL        UMETA(DisplayName = "email")
};
