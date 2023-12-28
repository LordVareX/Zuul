/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateAuthEventFeedbackResult.h"

#endif

#include "UpdateAuthEventFeedbackResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateAuthEventFeedbackResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUpdateAuthEventFeedbackResult &fromAWS(const Aws::CognitoIdentityProvider::Model::UpdateAuthEventFeedbackResult &awsUpdateAuthEventFeedbackResult) {

        return *this;
    }
#endif
};
