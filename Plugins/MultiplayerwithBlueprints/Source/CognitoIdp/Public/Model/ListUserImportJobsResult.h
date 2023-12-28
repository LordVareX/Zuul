/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListUserImportJobsResult.h"

#endif

#include "Model/UserImportJobType.h"

#include "ListUserImportJobsResult.generated.h"

USTRUCT(BlueprintType)
struct FListUserImportJobsResult {
GENERATED_BODY()

    /**
    *  <p>The user import jobs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FUserImportJobType> userImportJobs;

    /**
    *  <p>An identifier that can be used to return the next set of user import jobs in the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString paginationToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FListUserImportJobsResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ListUserImportJobsResult &awsListUserImportJobsResult) {
        this->userImportJobs.Empty();
        for (const Aws::CognitoIdentityProvider::Model::UserImportJobType& elem : awsListUserImportJobsResult.GetUserImportJobs()) {
            this->userImportJobs.Add(FUserImportJobType().fromAWS(elem));
        }

        this->paginationToken = UTF8_TO_TCHAR(awsListUserImportJobsResult.GetPaginationToken().c_str());

        return *this;
    }
#endif
};
