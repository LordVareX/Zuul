/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ExplicitAuthFlowsType.generated.h"

UENUM(BlueprintType)
enum class EExplicitAuthFlowsType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ADMIN_NO_SRP_AUTH        UMETA(DisplayName = "admin no srp auth"),
    CUSTOM_AUTH_FLOW_ONLY        UMETA(DisplayName = "custom auth flow only"),
    USER_PASSWORD_AUTH        UMETA(DisplayName = "user password auth"),
    ALLOW_ADMIN_USER_PASSWORD_AUTH        UMETA(DisplayName = "allow admin user password auth"),
    ALLOW_CUSTOM_AUTH        UMETA(DisplayName = "allow custom auth"),
    ALLOW_USER_PASSWORD_AUTH        UMETA(DisplayName = "allow user password auth"),
    ALLOW_USER_SRP_AUTH        UMETA(DisplayName = "allow user srp auth"),
    ALLOW_REFRESH_TOKEN_AUTH        UMETA(DisplayName = "allow refresh token auth")
};
