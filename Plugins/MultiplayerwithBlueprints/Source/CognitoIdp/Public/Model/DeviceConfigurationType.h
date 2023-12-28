/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeviceConfigurationType.h"

#endif

#include "DeviceConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FDeviceConfigurationType {
GENERATED_BODY()

    /**
    *  <p>Indicates whether a challenge is required on a new device. Only applicable to a new device.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool challengeRequiredOnNewDevice = false;

    /**
    *  <p>If true, a device is only remembered on user prompt.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool deviceOnlyRememberedOnUserPrompt = false;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DeviceConfigurationType toAWS() const {
        Aws::CognitoIdentityProvider::Model::DeviceConfigurationType awsDeviceConfigurationType;

        if (!(false)) {
            awsDeviceConfigurationType.SetChallengeRequiredOnNewDevice(this->challengeRequiredOnNewDevice);
        }

        if (!(false)) {
            awsDeviceConfigurationType.SetDeviceOnlyRememberedOnUserPrompt(this->deviceOnlyRememberedOnUserPrompt);
        }

        return awsDeviceConfigurationType;
    }

    bool IsEmpty() const {
        return false && false;
    }
    FDeviceConfigurationType &fromAWS(const Aws::CognitoIdentityProvider::Model::DeviceConfigurationType &awsDeviceConfigurationType) {
        this->challengeRequiredOnNewDevice = awsDeviceConfigurationType.GetChallengeRequiredOnNewDevice();

        this->deviceOnlyRememberedOnUserPrompt = awsDeviceConfigurationType.GetDeviceOnlyRememberedOnUserPrompt();

        return *this;
    }
#endif
};
