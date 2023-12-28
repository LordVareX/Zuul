/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/EventContextDataType.h"

#endif

#include "EventContextDataType.generated.h"

USTRUCT(BlueprintType)
struct FEventContextDataType {
GENERATED_BODY()

    /**
    *  <p>The user's IP address.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString ipAddress;

    /**
    *  <p>The user's device name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString deviceName;

    /**
    *  <p>The user's time zone.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString timezone;

    /**
    *  <p>The user's city.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString city;

    /**
    *  <p>The user's country.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString country;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FEventContextDataType &fromAWS(const Aws::CognitoIdentityProvider::Model::EventContextDataType &awsEventContextDataType) {
        this->ipAddress = UTF8_TO_TCHAR(awsEventContextDataType.GetIpAddress().c_str());

        this->deviceName = UTF8_TO_TCHAR(awsEventContextDataType.GetDeviceName().c_str());

        this->timezone = UTF8_TO_TCHAR(awsEventContextDataType.GetTimezone().c_str());

        this->city = UTF8_TO_TCHAR(awsEventContextDataType.GetCity().c_str());

        this->country = UTF8_TO_TCHAR(awsEventContextDataType.GetCountry().c_str());

        return *this;
    }
#endif
};
