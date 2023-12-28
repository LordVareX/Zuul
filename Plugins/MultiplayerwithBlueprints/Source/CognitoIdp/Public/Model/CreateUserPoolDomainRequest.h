/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateUserPoolDomainRequest.h"

#endif

#include "Model/CustomDomainConfigType.h"

#include "CreateUserPoolDomainRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateUserPoolDomainRequest {
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

    /**
    *  <p>The configuration for a custom domain that hosts the sign-up and sign-in webpages for your application.</p> <p>Provide this parameter only if you want to use a custom domain for your user pool. Otherwise, you can exclude this parameter and use the Amazon Cognito hosted domain instead.</p> <p>For more information about the hosted domain and custom domains, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-pools-assign-domain.html">Configuring a User Pool Domain</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FCustomDomainConfigType customDomainConfig;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CreateUserPoolDomainRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::CreateUserPoolDomainRequest awsCreateUserPoolDomainRequest;

        if (!(this->domain.IsEmpty())) {
            awsCreateUserPoolDomainRequest.SetDomain(TCHAR_TO_UTF8(*this->domain));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsCreateUserPoolDomainRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->customDomainConfig.IsEmpty())) {
            awsCreateUserPoolDomainRequest.SetCustomDomainConfig(this->customDomainConfig.toAWS());
        }

        return awsCreateUserPoolDomainRequest;
    }

    bool IsEmpty() const {
        return this->domain.IsEmpty() && this->userPoolId.IsEmpty() && this->customDomainConfig.IsEmpty();
    }
#endif
};
