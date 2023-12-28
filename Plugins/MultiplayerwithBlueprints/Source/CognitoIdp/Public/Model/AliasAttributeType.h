/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "AliasAttributeType.generated.h"

UENUM(BlueprintType)
enum class EAliasAttributeType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    phone_number        UMETA(DisplayName = "phone number"),
    email        UMETA(DisplayName = "email"),
    preferred_username        UMETA(DisplayName = "preferred username")
};
