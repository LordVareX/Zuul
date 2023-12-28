/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetAccountSettingsRequest.h"

#endif

#include "GetAccountSettingsRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetAccountSettingsRequest {
GENERATED_BODY()

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::GetAccountSettingsRequest toAWS() const {
        Aws::Lambda::Model::GetAccountSettingsRequest awsGetAccountSettingsRequest;

        return awsGetAccountSettingsRequest;
    }

    bool IsEmpty() const {
        return false;
    }
#endif
};
