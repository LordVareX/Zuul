/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListGroupsResult.h"

#endif

#include "Model/GroupType.h"

#include "ListGroupsResult.generated.h"

USTRUCT(BlueprintType)
struct FListGroupsResult {
GENERATED_BODY()

    /**
    *  <p>The group objects for the groups.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FGroupType> groups;

    /**
    *  <p>An identifier that was returned from the previous call to this operation, which can be used to return the next set of items in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FListGroupsResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ListGroupsResult &awsListGroupsResult) {
        this->groups.Empty();
        for (const Aws::CognitoIdentityProvider::Model::GroupType& elem : awsListGroupsResult.GetGroups()) {
            this->groups.Add(FGroupType().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListGroupsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
