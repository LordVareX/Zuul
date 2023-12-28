/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "CompromisedCredentialsEventActionType.generated.h"

UENUM(BlueprintType)
enum class ECompromisedCredentialsEventActionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    BLOCK        UMETA(DisplayName = "block"),
    NO_ACTION        UMETA(DisplayName = "no action")
};
