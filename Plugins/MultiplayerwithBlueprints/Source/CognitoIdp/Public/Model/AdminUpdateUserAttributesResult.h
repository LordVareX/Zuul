/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminUpdateUserAttributesResult.h"

#endif

#include "AdminUpdateUserAttributesResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminUpdateUserAttributesResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminUpdateUserAttributesResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminUpdateUserAttributesResult &awsAdminUpdateUserAttributesResult) {

        return *this;
    }
#endif
};
