/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeleteUserPoolDomainRequest.h"

#endif

#include "DeleteUserPoolDomainRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteUserPoolDomainRequest {
GENERATED_BODY()

    /**
    *  <p>The domain string.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString domain;

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DeleteUserPoolDomainRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DeleteUserPoolDomainRequest awsDeleteUserPoolDomainRequest;

        if (!(this->domain.IsEmpty())) {
            awsDeleteUserPoolDomainRequest.SetDomain(TCHAR_TO_UTF8(*this->domain));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsDeleteUserPoolDomainRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        return awsDeleteUserPoolDomainRequest;
    }

    bool IsEmpty() const {
        return this->domain.IsEmpty() && this->userPoolId.IsEmpty();
    }
#endif
};
