/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListContributorInsightsRequest.h"

#endif

#include "ListContributorInsightsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListContributorInsightsRequest {
    GENERATED_BODY()

    /**
    *  <p>The name of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>A token to for the desired page, if there is one.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;

    /**
    *  <p>Maximum number of results to return per page.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int maxResults = 0;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ListContributorInsightsRequest toAWS() const {
        Aws::DynamoDB::Model::ListContributorInsightsRequest awsListContributorInsightsRequest;

		if (!(this->tableName.IsEmpty())) {
            awsListContributorInsightsRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

		if (!(this->nextToken.IsEmpty())) {
            awsListContributorInsightsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        if (!(this->maxResults == 0)) {
            awsListContributorInsightsRequest.SetMaxResults(this->maxResults);
        }

        return awsListContributorInsightsRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->nextToken.IsEmpty() && this->maxResults == 0;
    }
#endif
};
