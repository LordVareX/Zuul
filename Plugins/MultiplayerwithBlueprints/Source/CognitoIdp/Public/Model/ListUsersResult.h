/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListUsersResult.h"

#endif

#include "Model/UserType.h"

#include "ListUsersResult.generated.h"

USTRUCT(BlueprintType)
struct FListUsersResult {
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
    FString paginationToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FListUsersResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ListUsersResult &awsListUsersResult) {
        this->users.Empty();
        for (const Aws::CognitoIdentityProvider::Model::UserType& elem : awsListUsersResult.GetUsers()) {
            this->users.Add(FUserType().fromAWS(elem));
        }

        this->paginationToken = UTF8_TO_TCHAR(awsListUsersResult.GetPaginationToken().c_str());

        return *this;
    }
#endif
};
