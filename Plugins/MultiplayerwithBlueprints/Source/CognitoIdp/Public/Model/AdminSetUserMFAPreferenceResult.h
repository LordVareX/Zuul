/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminSetUserMFAPreferenceResult.h"

#endif

#include "AdminSetUserMFAPreferenceResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminSetUserMFAPreferenceResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminSetUserMFAPreferenceResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminSetUserMFAPreferenceResult &awsAdminSetUserMFAPreferenceResult) {

        return *this;
    }
#endif
};
