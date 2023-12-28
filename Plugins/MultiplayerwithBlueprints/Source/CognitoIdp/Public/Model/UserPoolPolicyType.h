/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserPoolPolicyType.h"

#endif

#include "Model/PasswordPolicyType.h"

#include "UserPoolPolicyType.generated.h"

USTRUCT(BlueprintType)
struct FUserPoolPolicyType {
GENERATED_BODY()

    /**
    *  <p>The password policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FPasswordPolicyType passwordPolicy;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UserPoolPolicyType toAWS() const {
        Aws::CognitoIdentityProvider::Model::UserPoolPolicyType awsUserPoolPolicyType;

        if (!(this->passwordPolicy.IsEmpty())) {
            awsUserPoolPolicyType.SetPasswordPolicy(this->passwordPolicy.toAWS());
        }

        return awsUserPoolPolicyType;
    }

    bool IsEmpty() const {
        return this->passwordPolicy.IsEmpty();
    }

    FUserPoolPolicyType &fromAWS(const Aws::CognitoIdentityProvider::Model::UserPoolPolicyType &awsUserPoolPolicyType) {
        this->passwordPolicy.fromAWS(awsUserPoolPolicyType.GetPasswordPolicy());

        return *this;
    }
#endif
};
