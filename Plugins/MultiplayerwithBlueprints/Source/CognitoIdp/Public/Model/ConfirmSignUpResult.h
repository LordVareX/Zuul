/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ConfirmSignUpResult.h"

#endif

#include "ConfirmSignUpResult.generated.h"

USTRUCT(BlueprintType)
struct FConfirmSignUpResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FConfirmSignUpResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ConfirmSignUpResult &awsConfirmSignUpResult) {

        return *this;
    }
#endif
};
