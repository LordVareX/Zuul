/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "OAuthFlowType.generated.h"

UENUM(BlueprintType)
enum class EOAuthFlowType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    code        UMETA(DisplayName = "code"),
    implicit        UMETA(DisplayName = "implicit"),
    client_credentials        UMETA(DisplayName = "client credentials")
};
