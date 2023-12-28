/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetDeviceRequest.h"

#endif

#include "GetDeviceRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetDeviceRequest {
GENERATED_BODY()

    /**
    *  <p>The device key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString deviceKey;

    /**
    *  <p>The access token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::GetDeviceRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::GetDeviceRequest awsGetDeviceRequest;

        if (!(this->deviceKey.IsEmpty())) {
            awsGetDeviceRequest.SetDeviceKey(TCHAR_TO_UTF8(*this->deviceKey));
        }

        if (!(this->accessToken.IsEmpty())) {
            awsGetDeviceRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        return awsGetDeviceRequest;
    }

    bool IsEmpty() const {
        return this->deviceKey.IsEmpty() && this->accessToken.IsEmpty();
    }
#endif
};
