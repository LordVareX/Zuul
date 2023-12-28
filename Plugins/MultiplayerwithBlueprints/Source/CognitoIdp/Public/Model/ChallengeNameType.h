/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "ChallengeNameType.generated.h"

UENUM(BlueprintType)
enum class EChallengeNameType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SMS_MFA        UMETA(DisplayName = "sms mfa"),
    SOFTWARE_TOKEN_MFA        UMETA(DisplayName = "software token mfa"),
    SELECT_MFA_TYPE        UMETA(DisplayName = "select mfa type"),
    MFA_SETUP        UMETA(DisplayName = "mfa setup"),
    PASSWORD_VERIFIER        UMETA(DisplayName = "password verifier"),
    CUSTOM_CHALLENGE        UMETA(DisplayName = "custom challenge"),
    DEVICE_SRP_AUTH        UMETA(DisplayName = "device srp auth"),
    DEVICE_PASSWORD_VERIFIER        UMETA(DisplayName = "device password verifier"),
    ADMIN_NO_SRP_AUTH        UMETA(DisplayName = "admin no srp auth"),
    NEW_PASSWORD_REQUIRED        UMETA(DisplayName = "new password required")
};
