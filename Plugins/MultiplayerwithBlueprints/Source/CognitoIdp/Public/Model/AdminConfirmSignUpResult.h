/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminConfirmSignUpResult.h"

#endif

#include "AdminConfirmSignUpResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminConfirmSignUpResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminConfirmSignUpResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminConfirmSignUpResult &awsAdminConfirmSignUpResult) {

        return *this;
    }
#endif
};
