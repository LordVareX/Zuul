/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ConfirmForgotPasswordResult.h"

#endif

#include "ConfirmForgotPasswordResult.generated.h"

USTRUCT(BlueprintType)
struct FConfirmForgotPasswordResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FConfirmForgotPasswordResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ConfirmForgotPasswordResult &awsConfirmForgotPasswordResult) {

        return *this;
    }
#endif
};
