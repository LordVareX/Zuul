/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ConfirmDeviceRequest.h"

#endif

#include "Model/DeviceSecretVerifierConfigType.h"

#include "ConfirmDeviceRequest.generated.h"

USTRUCT(BlueprintType)
struct FConfirmDeviceRequest {
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
    *  <p>The configuration of the device secret verifier.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDeviceSecretVerifierConfigType deviceSecretVerifierConfig;

    /**
    *  <p>The device name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString deviceName;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ConfirmDeviceRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ConfirmDeviceRequest awsConfirmDeviceRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsConfirmDeviceRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        if (!(this->deviceKey.IsEmpty())) {
            awsConfirmDeviceRequest.SetDeviceKey(TCHAR_TO_UTF8(*this->deviceKey));
        }

        if (!(this->deviceSecretVerifierConfig.IsEmpty())) {
            awsConfirmDeviceRequest.SetDeviceSecretVerifierConfig(this->deviceSecretVerifierConfig.toAWS());
        }

        if (!(this->deviceName.IsEmpty())) {
            awsConfirmDeviceRequest.SetDeviceName(TCHAR_TO_UTF8(*this->deviceName));
        }

        return awsConfirmDeviceRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty() && this->deviceKey.IsEmpty() && this->deviceSecretVerifierConfig.IsEmpty() && this->deviceName.IsEmpty();
    }
#endif
};
