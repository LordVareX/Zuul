/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AuthenticationResultType.h"

#endif

#include "Model/NewDeviceMetadataType.h"

#include "AuthenticationResultType.generated.h"

USTRUCT(BlueprintType)
struct FAuthenticationResultType {
GENERATED_BODY()

    /**
    *  <p>The access token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

    /**
    *  <p>The expiration period of the authentication result in seconds.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int expiresIn = 0;

    /**
    *  <p>The token type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString tokenType;

    /**
    *  <p>The refresh token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString refreshToken;

    /**
    *  <p>The ID token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString idToken;

    /**
    *  <p>The new device metadata from an authentication result.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FNewDeviceMetadataType newDeviceMetadata;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAuthenticationResultType &fromAWS(const Aws::CognitoIdentityProvider::Model::AuthenticationResultType &awsAuthenticationResultType) {
        this->accessToken = UTF8_TO_TCHAR(awsAuthenticationResultType.GetAccessToken().c_str());

        this->expiresIn = awsAuthenticationResultType.GetExpiresIn();

        this->tokenType = UTF8_TO_TCHAR(awsAuthenticationResultType.GetTokenType().c_str());

        this->refreshToken = UTF8_TO_TCHAR(awsAuthenticationResultType.GetRefreshToken().c_str());

        this->idToken = UTF8_TO_TCHAR(awsAuthenticationResultType.GetIdToken().c_str());

        this->newDeviceMetadata.fromAWS(awsAuthenticationResultType.GetNewDeviceMetadata());

        return *this;
    }
#endif
};
