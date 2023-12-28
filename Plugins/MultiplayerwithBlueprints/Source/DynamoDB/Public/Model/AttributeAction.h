/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "AttributeAction.generated.h"

UENUM(BlueprintType)
enum class EAWSAttributeAction : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ADD        UMETA(DisplayName = "add"),
    PUT        UMETA(DisplayName = "put"),
    DELETE        UMETA(DisplayName = "delete"),
};
