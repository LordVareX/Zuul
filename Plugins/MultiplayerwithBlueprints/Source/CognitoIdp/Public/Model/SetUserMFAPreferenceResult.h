/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SetUserMFAPreferenceResult.h"

#endif

#include "SetUserMFAPreferenceResult.generated.h"

USTRUCT(BlueprintType)
struct FSetUserMFAPreferenceResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FSetUserMFAPreferenceResult &fromAWS(const Aws::CognitoIdentityProvider::Model::SetUserMFAPreferenceResult &awsSetUserMFAPreferenceResult) {

        return *this;
    }
#endif
};
