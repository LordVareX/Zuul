/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateGroupResult.h"

#endif

#include "Model/GroupType.h"

#include "CreateGroupResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateGroupResult {
GENERATED_BODY()

    /**
    *  <p>The group object for the group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FGroupType group;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCreateGroupResult &fromAWS(const Aws::CognitoIdentityProvider::Model::CreateGroupResult &awsCreateGroupResult) {
        this->group.fromAWS(awsCreateGroupResult.GetGroup());

        return *this;
    }
#endif
};
