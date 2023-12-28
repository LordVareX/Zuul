/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminGetDeviceResult.h"

#endif

#include "Model/DeviceType.h"

#include "AdminGetDeviceResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminGetDeviceResult {
GENERATED_BODY()

    /**
    *  <p>The device.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDeviceType device;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminGetDeviceResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminGetDeviceResult &awsAdminGetDeviceResult) {
        this->device.fromAWS(awsAdminGetDeviceResult.GetDevice());

        return *this;
    }
#endif
};
