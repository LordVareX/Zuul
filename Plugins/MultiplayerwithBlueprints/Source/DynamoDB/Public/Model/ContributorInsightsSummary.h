/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ContributorInsightsSummary.h"

#endif

#include "Model/ContributorInsightsStatus.h"

#include "ContributorInsightsSummary.generated.h"

USTRUCT(BlueprintType)
struct FContributorInsightsSummary {
GENERATED_BODY()

    /**
    *  <p>Name of the table associated with the summary.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>Name of the index associated with the summary, if any.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>Describes the current status for contributor insights for the given table and index, if applicable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSContributorInsightsStatus contributorInsightsStatus = EAWSContributorInsightsStatus::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:

    FContributorInsightsSummary &fromAWS(const Aws::DynamoDB::Model::ContributorInsightsSummary &awsContributorInsightsSummary) {
// @TODO: check
        this->tableName = UTF8_TO_TCHAR(awsContributorInsightsSummary.GetTableName().c_str());

// @TODO: check
        this->indexName = UTF8_TO_TCHAR(awsContributorInsightsSummary.GetIndexName().c_str());

// @TODO: check
        switch(awsContributorInsightsSummary.GetContributorInsightsStatus()) {
            case Aws::DynamoDB::Model::ContributorInsightsStatus::NOT_SET:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::ContributorInsightsStatus::ENABLING:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::ENABLING;
                break;
            case Aws::DynamoDB::Model::ContributorInsightsStatus::ENABLED:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::ENABLED;
                break;
            case Aws::DynamoDB::Model::ContributorInsightsStatus::DISABLING:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::DISABLING;
                break;
            case Aws::DynamoDB::Model::ContributorInsightsStatus::DISABLED:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::DISABLED;
                break;
            case Aws::DynamoDB::Model::ContributorInsightsStatus::FAILED:
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::FAILED;
                break;
            default:
                // @TODO: unimplemented
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::NOT_SET;
                break;
            }

        return *this;
    }
#endif
};
