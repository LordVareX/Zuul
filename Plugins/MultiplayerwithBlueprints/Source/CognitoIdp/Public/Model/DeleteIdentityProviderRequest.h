/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeleteIdentityProviderRequest.h"

#endif

#include "DeleteIdentityProviderRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteIdentityProviderRequest {
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
    Aws::CognitoIdentityProvider::Model::DeleteIdentityProviderRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DeleteIdentityProviderRequest awsDeleteIdentityProviderRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsDeleteIdentityProviderRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->providerName.IsEmpty())) {
            awsDeleteIdentityProviderRequest.SetProviderName(TCHAR_TO_UTF8(*this->providerName));
        }

        return awsDeleteIdentityProviderRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->providerName.IsEmpty();
    }
#endif
};
