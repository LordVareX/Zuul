/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminUpdateDeviceStatusResult.h"

#endif

#include "AdminUpdateDeviceStatusResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminUpdateDeviceStatusResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminUpdateDeviceStatusResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminUpdateDeviceStatusResult &awsAdminUpdateDeviceStatusResult) {

        return *this;
    }
#endif
};
