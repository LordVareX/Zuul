/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateDeviceStatusRequest.h"

#endif

#include "Model/DeviceRememberedStatusType.h"

#include "UpdateDeviceStatusRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateDeviceStatusRequest {
GENERATED_BODY()

    /**
    *  <p>The access token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

    /**
    *  <p>The device key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString deviceKey;

    /**
    *  <p>The status of whether a device is remembered.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EDeviceRememberedStatusType deviceRememberedStatus = EDeviceRememberedStatusType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UpdateDeviceStatusRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::UpdateDeviceStatusRequest awsUpdateDeviceStatusRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsUpdateDeviceStatusRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        if (!(this->deviceKey.IsEmpty())) {
            awsUpdateDeviceStatusRequest.SetDeviceKey(TCHAR_TO_UTF8(*this->deviceKey));
        }

        switch(this->deviceRememberedStatus) {
            case EDeviceRememberedStatusType::remembered:
                awsUpdateDeviceStatusRequest.SetDeviceRememberedStatus(Aws::CognitoIdentityProvider::Model::DeviceRememberedStatusType::remembered);
                break;
            case EDeviceRememberedStatusType::not_remembered:
                awsUpdateDeviceStatusRequest.SetDeviceRememberedStatus(Aws::CognitoIdentityProvider::Model::DeviceRememberedStatusType::not_remembered);
                break;
            default:
                break;
        }

        return awsUpdateDeviceStatusRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty() && this->deviceKey.IsEmpty() && this->deviceRememberedStatus == EDeviceRememberedStatusType::NOT_SET;
    }
#endif
};
