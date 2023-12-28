/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminListGroupsForUserResult.h"

#endif

#include "Model/GroupType.h"

#include "AdminListGroupsForUserResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminListGroupsForUserResult {
GENERATED_BODY()

    /**
    *  <p>The groups that the user belongs to.</p>
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
    FAdminListGroupsForUserResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminListGroupsForUserResult &awsAdminListGroupsForUserResult) {
        this->groups.Empty();
        for (const Aws::CognitoIdentityProvider::Model::GroupType& elem : awsAdminListGroupsForUserResult.GetGroups()) {
            this->groups.Add(FGroupType().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsAdminListGroupsForUserResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
