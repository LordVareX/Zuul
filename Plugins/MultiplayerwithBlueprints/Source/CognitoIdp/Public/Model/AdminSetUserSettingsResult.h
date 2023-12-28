/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminSetUserSettingsResult.h"

#endif

#include "AdminSetUserSettingsResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminSetUserSettingsResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminSetUserSettingsResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminSetUserSettingsResult &awsAdminSetUserSettingsResult) {

        return *this;
    }
#endif
};
