/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminUpdateAuthEventFeedbackResult.h"

#endif

#include "AdminUpdateAuthEventFeedbackResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminUpdateAuthEventFeedbackResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminUpdateAuthEventFeedbackResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminUpdateAuthEventFeedbackResult &awsAdminUpdateAuthEventFeedbackResult) {

        return *this;
    }
#endif
};
