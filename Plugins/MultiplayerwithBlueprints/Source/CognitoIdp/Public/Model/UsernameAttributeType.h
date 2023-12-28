/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "UsernameAttributeType.generated.h"

UENUM(BlueprintType)
enum class EUsernameAttributeType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    phone_number        UMETA(DisplayName = "phone number"),
    email        UMETA(DisplayName = "email")
};
