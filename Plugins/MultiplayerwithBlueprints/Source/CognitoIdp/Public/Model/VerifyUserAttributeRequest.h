/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/VerifyUserAttributeRequest.h"

#endif

#include "VerifyUserAttributeRequest.generated.h"

USTRUCT(BlueprintType)
struct FVerifyUserAttributeRequest {
GENERATED_BODY()

    /**
    *  <p>Represents the access token of the request to verify user attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

    /**
    *  <p>The attribute name in the request to verify user attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString attributeName;

    /**
    *  <p>The verification code in the request to verify user attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString code;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::VerifyUserAttributeRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::VerifyUserAttributeRequest awsVerifyUserAttributeRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsVerifyUserAttributeRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        if (!(this->attributeName.IsEmpty())) {
            awsVerifyUserAttributeRequest.SetAttributeName(TCHAR_TO_UTF8(*this->attributeName));
        }

        if (!(this->code.IsEmpty())) {
            awsVerifyUserAttributeRequest.SetCode(TCHAR_TO_UTF8(*this->code));
        }

        return awsVerifyUserAttributeRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty() && this->attributeName.IsEmpty() && this->code.IsEmpty();
    }
#endif
};
