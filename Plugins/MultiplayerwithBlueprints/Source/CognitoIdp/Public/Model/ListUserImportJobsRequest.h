/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListUserImportJobsRequest.h"

#endif

#include "ListUserImportJobsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListUserImportJobsRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool that the users are being imported into.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The maximum number of import jobs you want the request to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int maxResults = 0;

    /**
    *  <p>An identifier that was returned from the previous call to <code>ListUserImportJobs</code>, which can be used to return the next set of import jobs in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString paginationToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ListUserImportJobsRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ListUserImportJobsRequest awsListUserImportJobsRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsListUserImportJobsRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->maxResults == 0)) {
            awsListUserImportJobsRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->paginationToken.IsEmpty())) {
            awsListUserImportJobsRequest.SetPaginationToken(TCHAR_TO_UTF8(*this->paginationToken));
        }

        return awsListUserImportJobsRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->maxResults == 0 && this->paginationToken.IsEmpty();
    }
#endif
};
