/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminListUserAuthEventsRequest.h"

#endif

#include "AdminListUserAuthEventsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminListUserAuthEventsRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user pool username or an alias.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>The maximum number of authentication events to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int maxResults = 0;

    /**
    *  <p>A pagination token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString nextToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminListUserAuthEventsRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminListUserAuthEventsRequest awsAdminListUserAuthEventsRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminListUserAuthEventsRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminListUserAuthEventsRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (this->maxResults != 0) {
            awsAdminListUserAuthEventsRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsAdminListUserAuthEventsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsAdminListUserAuthEventsRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->maxResults == 0 && this->nextToken.IsEmpty();
    }
#endif
};
