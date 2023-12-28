/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ForgetDeviceRequest.h"

#endif

#include "ForgetDeviceRequest.generated.h"

USTRUCT(BlueprintType)
struct FForgetDeviceRequest {
GENERATED_BODY()

    /**
    *  <p>The access token for the forgotten device request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

    /**
    *  <p>The device key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString deviceKey;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ForgetDeviceRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ForgetDeviceRequest awsForgetDeviceRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsForgetDeviceRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        if (!(this->deviceKey.IsEmpty())) {
            awsForgetDeviceRequest.SetDeviceKey(TCHAR_TO_UTF8(*this->deviceKey));
        }

        return awsForgetDeviceRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty() && this->deviceKey.IsEmpty();
    }
#endif
};
