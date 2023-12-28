/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SetUserSettingsResult.h"

#endif

#include "SetUserSettingsResult.generated.h"

USTRUCT(BlueprintType)
struct FSetUserSettingsResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FSetUserSettingsResult &fromAWS(const Aws::CognitoIdentityProvider::Model::SetUserSettingsResult &awsSetUserSettingsResult) {

        return *this;
    }
#endif
};
