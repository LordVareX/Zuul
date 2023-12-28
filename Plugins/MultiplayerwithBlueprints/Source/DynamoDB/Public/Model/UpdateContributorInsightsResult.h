/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateContributorInsightsResult.h"

#endif

#include "Model/ContributorInsightsStatus.h"

#include "UpdateContributorInsightsResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateContributorInsightsResult {
GENERATED_BODY()

    /**
    *  <p>The name of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The name of the global secondary index, if applicable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>The status of contributor insights</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSContributorInsightsStatus contributorInsightsStatus = EAWSContributorInsightsStatus::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FUpdateContributorInsightsResult &fromAWS(const Aws::DynamoDB::Model::UpdateContributorInsightsResult &awsUpdateContributorInsightsResult) {
        this->tableName = UTF8_TO_TCHAR(awsUpdateContributorInsightsResult.GetTableName().c_str());

        this->indexName = UTF8_TO_TCHAR(awsUpdateContributorInsightsResult.GetIndexName().c_str());

        switch(awsUpdateContributorInsightsResult.GetContributorInsightsStatus()) {
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
                this->contributorInsightsStatus = EAWSContributorInsightsStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
