/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateUserPoolDomainRequest.h"

#endif

#include "Model/CustomDomainConfigType.h"

#include "UpdateUserPoolDomainRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateUserPoolDomainRequest {
GENERATED_BODY()

    /**
    *  <p>The domain name for the custom domain that hosts the sign-up and sign-in pages for your application. For example: <code>auth.example.com</code>. </p> <p>This string can include only lowercase letters, numbers, and hyphens. Do not use a hyphen for the first or last character. Use periods to separate subdomain names.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString domain;

    /**
    *  <p>The ID of the user pool that is associated with the custom domain that you are updating the certificate for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The configuration for a custom domain that hosts the sign-up and sign-in pages for your application. Use this object to specify an SSL certificate that is managed by ACM.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FCustomDomainConfigType customDomainConfig;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UpdateUserPoolDomainRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::UpdateUserPoolDomainRequest awsUpdateUserPoolDomainRequest;

        if (!(this->domain.IsEmpty())) {
            awsUpdateUserPoolDomainRequest.SetDomain(TCHAR_TO_UTF8(*this->domain));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsUpdateUserPoolDomainRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->customDomainConfig.IsEmpty())) {
            awsUpdateUserPoolDomainRequest.SetCustomDomainConfig(this->customDomainConfig.toAWS());
        }

        return awsUpdateUserPoolDomainRequest;
    }

    bool IsEmpty() const {
        return this->domain.IsEmpty() && this->userPoolId.IsEmpty() && this->customDomainConfig.IsEmpty();
    }
#endif
};
