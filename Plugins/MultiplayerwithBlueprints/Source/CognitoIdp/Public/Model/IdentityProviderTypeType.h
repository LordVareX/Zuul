/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "IdentityProviderTypeType.generated.h"

UENUM(BlueprintType)
enum class EIdentityProviderTypeType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SAML        UMETA(DisplayName = "saml"),
    Facebook        UMETA(DisplayName = "facebook"),
    Google        UMETA(DisplayName = "google"),
    LoginWithAmazon        UMETA(DisplayName = "loginwithamazon"),
    SignInWithApple        UMETA(DisplayName = "signinwithapple"),
    OIDC        UMETA(DisplayName = "oidc")
};
