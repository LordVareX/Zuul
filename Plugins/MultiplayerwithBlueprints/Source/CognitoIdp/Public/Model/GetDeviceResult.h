/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetDeviceResult.h"

#endif

#include "Model/DeviceType.h"

#include "GetDeviceResult.generated.h"

USTRUCT(BlueprintType)
struct FGetDeviceResult {
GENERATED_BODY()

    /**
    *  <p>The device.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDeviceType device;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FGetDeviceResult &fromAWS(const Aws::CognitoIdentityProvider::Model::GetDeviceResult &awsGetDeviceResult) {
        this->device.fromAWS(awsGetDeviceResult.GetDevice());

        return *this;
    }
#endif
};
