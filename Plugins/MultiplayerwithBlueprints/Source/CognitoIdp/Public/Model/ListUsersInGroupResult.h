/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListUsersInGroupResult.h"

#endif

#include "Model/UserType.h"

#include "ListUsersInGroupResult.generated.h"

USTRUCT(BlueprintType)
struct FListUsersInGroupResult {
GENERATED_BODY()

    /**
    *  <p>The users returned in the request to list users.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FUserType> users;

    /**
    *  <p>An identifier that was returned from the previous call to this operation, which can be used to return the next set of items in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FListUsersInGroupResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ListUsersInGroupResult &awsListUsersInGroupResult) {
        this->users.Empty();
        for (const Aws::CognitoIdentityProvider::Model::UserType& elem : awsListUsersInGroupResult.GetUsers()) {
            this->users.Add(FUserType().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListUsersInGroupResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
