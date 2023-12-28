/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateDeviceStatusResult.h"

#endif

#include "UpdateDeviceStatusResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateDeviceStatusResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUpdateDeviceStatusResult &fromAWS(const Aws::CognitoIdentityProvider::Model::UpdateDeviceStatusResult &awsUpdateDeviceStatusResult) {

        return *this;
    }
#endif
};
