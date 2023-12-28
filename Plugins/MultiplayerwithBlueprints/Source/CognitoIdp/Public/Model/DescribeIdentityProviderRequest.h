/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeIdentityProviderRequest.h"

#endif

#include "DescribeIdentityProviderRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeIdentityProviderRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The identity provider name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString providerName;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DescribeIdentityProviderRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DescribeIdentityProviderRequest awsDescribeIdentityProviderRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsDescribeIdentityProviderRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->providerName.IsEmpty())) {
            awsDescribeIdentityProviderRequest.SetProviderName(TCHAR_TO_UTF8(*this->providerName));
        }

        return awsDescribeIdentityProviderRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->providerName.IsEmpty();
    }
#endif
};
