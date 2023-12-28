/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminListUserAuthEventsResult.h"

#endif

#include "Model/AuthEventType.h"

#include "AdminListUserAuthEventsResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminListUserAuthEventsResult {
GENERATED_BODY()

    /**
    *  <p>The response object. It includes the <code>EventID</code>, <code>EventType</code>, <code>CreationDate</code>, <code>EventRisk</code>, and <code>EventResponse</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FAuthEventType> authEvents;

    /**
    *  <p>A pagination token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminListUserAuthEventsResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminListUserAuthEventsResult &awsAdminListUserAuthEventsResult) {
        this->authEvents.Empty();
        for (const Aws::CognitoIdentityProvider::Model::AuthEventType& elem : awsAdminListUserAuthEventsResult.GetAuthEvents()) {
            this->authEvents.Add(FAuthEventType().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsAdminListUserAuthEventsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
