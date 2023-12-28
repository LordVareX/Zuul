/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/VerifySoftwareTokenRequest.h"

#endif

#include "VerifySoftwareTokenRequest.generated.h"

USTRUCT(BlueprintType)
struct FVerifySoftwareTokenRequest {
GENERATED_BODY()

    /**
    *  <p>The access token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

    /**
    *  <p>The session which should be passed both ways in challenge-response calls to the service.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString session;

    /**
    *  <p>The one time password computed using the secret code returned by </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userCode;

    /**
    *  <p>The friendly device name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString friendlyDeviceName;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::VerifySoftwareTokenRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::VerifySoftwareTokenRequest awsVerifySoftwareTokenRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsVerifySoftwareTokenRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        if (!(this->session.IsEmpty())) {
            awsVerifySoftwareTokenRequest.SetSession(TCHAR_TO_UTF8(*this->session));
        }

        if (!(this->userCode.IsEmpty())) {
            awsVerifySoftwareTokenRequest.SetUserCode(TCHAR_TO_UTF8(*this->userCode));
        }

        if (!(this->friendlyDeviceName.IsEmpty())) {
            awsVerifySoftwareTokenRequest.SetFriendlyDeviceName(TCHAR_TO_UTF8(*this->friendlyDeviceName));
        }

        return awsVerifySoftwareTokenRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty() && this->session.IsEmpty() && this->userCode.IsEmpty() && this->friendlyDeviceName.IsEmpty();
    }
#endif
};
