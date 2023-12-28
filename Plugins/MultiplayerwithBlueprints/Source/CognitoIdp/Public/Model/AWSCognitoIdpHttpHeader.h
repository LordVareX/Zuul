/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/HttpHeader.h"

#endif

#include "AWSCognitoIdpHttpHeader.generated.h"

USTRUCT(BlueprintType)
struct FAWSCognitoIdpHttpHeader {
GENERATED_BODY()

    /**
    *  <p>The header name</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString headerName;

    /**
    *  <p>The header value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString headerValue;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::HttpHeader toAWS() const {
        Aws::CognitoIdentityProvider::Model::HttpHeader awsHttpHeader;

        if (!(this->headerName.IsEmpty())) {
            awsHttpHeader.SetHeaderName(TCHAR_TO_UTF8(*this->headerName));
        }

        if (!(this->headerValue.IsEmpty())) {
            awsHttpHeader.SetHeaderValue(TCHAR_TO_UTF8(*this->headerValue));
        }

        return awsHttpHeader;
    }

    bool IsEmpty() const {
        return this->headerName.IsEmpty() && this->headerValue.IsEmpty();
    }
#endif
};
