/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListUserPoolsResult.h"

#endif

#include "Model/UserPoolDescriptionType.h"

#include "ListUserPoolsResult.generated.h"

USTRUCT(BlueprintType)
struct FListUserPoolsResult {
GENERATED_BODY()

    /**
    *  <p>The user pools from the response to list users.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FUserPoolDescriptionType> userPools;

    /**
    *  <p>An identifier that was returned from the previous call to this operation, which can be used to return the next set of items in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FListUserPoolsResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ListUserPoolsResult &awsListUserPoolsResult) {
        this->userPools.Empty();
        for (const Aws::CognitoIdentityProvider::Model::UserPoolDescriptionType& elem : awsListUserPoolsResult.GetUserPools()) {
            this->userPools.Add(FUserPoolDescriptionType().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListUserPoolsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
