/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateGroupResult.h"

#endif

#include "Model/GroupType.h"

#include "UpdateGroupResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGroupResult {
GENERATED_BODY()

    /**
    *  <p>The group object for the group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FGroupType group;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUpdateGroupResult &fromAWS(const Aws::CognitoIdentityProvider::Model::UpdateGroupResult &awsUpdateGroupResult) {
        this->group.fromAWS(awsUpdateGroupResult.GetGroup());

        return *this;
    }
#endif
};
