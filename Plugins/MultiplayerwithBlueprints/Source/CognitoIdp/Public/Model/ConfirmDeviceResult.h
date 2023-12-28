/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ConfirmDeviceResult.h"

#endif

#include "ConfirmDeviceResult.generated.h"

USTRUCT(BlueprintType)
struct FConfirmDeviceResult {
    GENERATED_BODY()

    /**
    *  <p>Indicates whether the user confirmation is necessary to confirm the device response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool userConfirmationNecessary = false;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FConfirmDeviceResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ConfirmDeviceResult &awsConfirmDeviceResult) {
        this->userConfirmationNecessary = awsConfirmDeviceResult.GetUserConfirmationNecessary();

        return *this;
    }
#endif
};
