/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "AuthFlowType.generated.h"

UENUM(BlueprintType)
enum class EAuthFlowType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    USER_SRP_AUTH        UMETA(DisplayName = "user srp auth"),
    REFRESH_TOKEN_AUTH        UMETA(DisplayName = "refresh token auth"),
    REFRESH_TOKEN        UMETA(DisplayName = "refresh token"),
    CUSTOM_AUTH        UMETA(DisplayName = "custom auth"),
    ADMIN_NO_SRP_AUTH        UMETA(DisplayName = "admin no srp auth"),
    USER_PASSWORD_AUTH        UMETA(DisplayName = "user password auth"),
    ADMIN_USER_PASSWORD_AUTH        UMETA(DisplayName = "admin user password auth")
};
