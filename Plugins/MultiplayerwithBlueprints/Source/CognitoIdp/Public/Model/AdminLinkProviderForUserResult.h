/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminLinkProviderForUserResult.h"

#endif

#include "AdminLinkProviderForUserResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminLinkProviderForUserResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminLinkProviderForUserResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminLinkProviderForUserResult &awsAdminLinkProviderForUserResult) {

        return *this;
    }
#endif
};
