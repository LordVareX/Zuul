/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/RevokeTokenRequest.h"

#endif

#include "AWSCognitoIdentityProviderRevokeTokenRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSCognitoIdentityProviderRevokeTokenRequest {
GENERATED_BODY()

    /**
    *  <p>The refresh token that you want to revoke.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString token;

    /**
    *  <p>The client ID for the token that you want to revoke.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>The secret for the client ID. This is required only if the client ID has a secret.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientSecret;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::RevokeTokenRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::RevokeTokenRequest awsRevokeTokenRequest;

        if (!(this->token.IsEmpty())) {
            awsRevokeTokenRequest.SetToken(TCHAR_TO_UTF8(*this->token));
        }

        if (!(this->clientId.IsEmpty())) {
            awsRevokeTokenRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        if (!(this->clientSecret.IsEmpty())) {
            awsRevokeTokenRequest.SetClientSecret(TCHAR_TO_UTF8(*this->clientSecret));
        }

        return awsRevokeTokenRequest;
    }

    bool IsEmpty() const {
        return this->token.IsEmpty() && this->clientId.IsEmpty() && this->clientSecret.IsEmpty();
    }
#endif
};
