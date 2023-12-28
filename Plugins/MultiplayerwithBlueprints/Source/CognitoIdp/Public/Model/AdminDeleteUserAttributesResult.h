/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminDeleteUserAttributesResult.h"

#endif

#include "AdminDeleteUserAttributesResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminDeleteUserAttributesResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminDeleteUserAttributesResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminDeleteUserAttributesResult &awsAdminDeleteUserAttributesResult) {

        return *this;
    }
#endif
};
