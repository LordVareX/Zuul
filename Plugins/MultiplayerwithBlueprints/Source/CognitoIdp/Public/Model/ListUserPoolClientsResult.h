/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListUserPoolClientsResult.h"

#endif

#include "Model/UserPoolClientDescription.h"

#include "ListUserPoolClientsResult.generated.h"

USTRUCT(BlueprintType)
struct FListUserPoolClientsResult {
GENERATED_BODY()

    /**
    *  <p>The user pool clients in the response that lists user pool clients.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FUserPoolClientDescription> userPoolClients;

    /**
    *  <p>An identifier that was returned from the previous call to this operation, which can be used to return the next set of items in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FListUserPoolClientsResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ListUserPoolClientsResult &awsListUserPoolClientsResult) {
        this->userPoolClients.Empty();
        for (const Aws::CognitoIdentityProvider::Model::UserPoolClientDescription& elem : awsListUserPoolClientsResult.GetUserPoolClients()) {
            this->userPoolClients.Add(FUserPoolClientDescription().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListUserPoolClientsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
