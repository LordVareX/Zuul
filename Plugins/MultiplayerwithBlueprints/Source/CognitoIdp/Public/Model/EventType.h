/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "EventType.generated.h"

UENUM(BlueprintType)
enum class EEventType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SignIn        UMETA(DisplayName = "signin"),
    SignUp        UMETA(DisplayName = "signup"),
    ForgotPassword        UMETA(DisplayName = "forgot password"),
    PasswordChange        UMETA(DisplayName = "password change"),
    ResendCode  UMETA(DisplayName = "resend code")
};
