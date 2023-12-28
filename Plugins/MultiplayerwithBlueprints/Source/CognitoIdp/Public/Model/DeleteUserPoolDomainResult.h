/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeleteUserPoolDomainResult.h"

#endif

#include "DeleteUserPoolDomainResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteUserPoolDomainResult {
GENERATED_BODY()

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FDeleteUserPoolDomainResult &fromAWS(const Aws::CognitoIdentityProvider::Model::DeleteUserPoolDomainResult &awsDeleteUserPoolDomainResult) {

        return *this;
    }
#endif
};
