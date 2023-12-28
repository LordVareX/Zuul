/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListContributorInsightsResult.h"

#endif

#include "Model/ContributorInsightsSummary.h"

#include "ListContributorInsightsResult.generated.h"

USTRUCT(BlueprintType)
struct FListContributorInsightsResult {
GENERATED_BODY()

    /**
    *  <p>A list of ContributorInsightsSummary.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FContributorInsightsSummary> contributorInsightsSummaries;

    /**
    *  <p>A token to go to the next page if there is one.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FListContributorInsightsResult &fromAWS(const Aws::DynamoDB::Model::ListContributorInsightsResult &awsListContributorInsightsResult) {
        this->contributorInsightsSummaries.Empty();
        for (const Aws::DynamoDB::Model::ContributorInsightsSummary& elem : awsListContributorInsightsResult.GetContributorInsightsSummaries()) {
            this->contributorInsightsSummaries.Add(FContributorInsightsSummary().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListContributorInsightsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
