/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "AttributeDataType.generated.h"

UENUM(BlueprintType)
enum class EAttributeDataType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    String        UMETA(DisplayName = "string"),
    Number        UMETA(DisplayName = "number"),
    DateTime        UMETA(DisplayName = "datetime"),
    Boolean        UMETA(DisplayName = "boolean")
};
