/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AssociateSoftwareTokenRequest.h"

#endif

#include "AssociateSoftwareTokenRequest.generated.h"

USTRUCT(BlueprintType)
struct FAssociateSoftwareTokenRequest {
GENERATED_BODY()

    /**
    *  <p>The access token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

    /**
    *  <p>The session which should be passed both ways in challenge-response calls to the service. This allows authentication of the user as part of the MFA setup process.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString session;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AssociateSoftwareTokenRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AssociateSoftwareTokenRequest awsAssociateSoftwareTokenRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsAssociateSoftwareTokenRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        if (!(this->session.IsEmpty())) {
            awsAssociateSoftwareTokenRequest.SetSession(TCHAR_TO_UTF8(*this->session));
        }

        return awsAssociateSoftwareTokenRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty() && this->session.IsEmpty();
    }
#endif
};
