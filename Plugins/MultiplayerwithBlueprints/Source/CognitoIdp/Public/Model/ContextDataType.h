/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ContextDataType.h"

#endif

#include "Model/AWSCognitoIdpHttpHeader.h"

#include "ContextDataType.generated.h"

USTRUCT(BlueprintType)
struct FContextDataType {
GENERATED_BODY()

    /**
    *  <p>Source IP address of your user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString ipAddress;

    /**
    *  <p>Your server endpoint where this API is invoked.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString serverName;

    /**
    *  <p>Your server path where this API is invoked. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString serverPath;

    /**
    *  <p>HttpHeaders received on your server in same order.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FAWSCognitoIdpHttpHeader> httpHeaders;

    /**
    *  <p>Encoded data containing device fingerprinting details, collected using the Amazon Cognito context data collection library.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString encodedData;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ContextDataType toAWS() const {
        Aws::CognitoIdentityProvider::Model::ContextDataType awsContextDataType;

        if (!(this->ipAddress.IsEmpty())) {
            awsContextDataType.SetIpAddress(TCHAR_TO_UTF8(*this->ipAddress));
        }

        if (!(this->serverName.IsEmpty())) {
            awsContextDataType.SetServerName(TCHAR_TO_UTF8(*this->serverName));
        }

        if (!(this->serverPath.IsEmpty())) {
            awsContextDataType.SetServerPath(TCHAR_TO_UTF8(*this->serverPath));
        }

        for (const FAWSCognitoIdpHttpHeader& elem : this->httpHeaders) {
            awsContextDataType.AddHttpHeaders(elem.toAWS());
        }

        if (!(this->encodedData.IsEmpty())) {
            awsContextDataType.SetEncodedData(TCHAR_TO_UTF8(*this->encodedData));
        }

        return awsContextDataType;
    }

    bool IsEmpty() const {
        return this->ipAddress.IsEmpty() && this->serverName.IsEmpty() && this->serverPath.IsEmpty() && this->httpHeaders.Num() == 0 && this->encodedData.IsEmpty();
    }
#endif
};
