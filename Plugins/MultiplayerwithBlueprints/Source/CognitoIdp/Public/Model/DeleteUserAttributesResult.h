/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeleteUserAttributesResult.h"

#endif

#include "DeleteUserAttributesResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteUserAttributesResult {
    GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FDeleteUserAttributesResult &fromAWS(const Aws::CognitoIdentityProvider::Model::DeleteUserAttributesResult &awsDeleteUserAttributesResult) {

        return *this;
    }
#endif
};
