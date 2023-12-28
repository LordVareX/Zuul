/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetGroupResult.h"

#endif

#include "Model/GroupType.h"

#include "GetGroupResult.generated.h"

USTRUCT(BlueprintType)
struct FGetGroupResult {
GENERATED_BODY()

    /**
    *  <p>The group object for the group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FGroupType group;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FGetGroupResult &fromAWS(const Aws::CognitoIdentityProvider::Model::GetGroupResult &awsGetGroupResult) {
        this->group.fromAWS(awsGetGroupResult.GetGroup());

        return *this;
    }
#endif
};
