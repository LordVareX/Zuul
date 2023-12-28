/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateContributorInsightsRequest.h"

#endif

#include "Model/ContributorInsightsAction.h"

#include "UpdateContributorInsightsRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateContributorInsightsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The global secondary index name, if applicable.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>Represents the contributor insights action.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSContributorInsightsAction contributorInsightsAction = EAWSContributorInsightsAction::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::UpdateContributorInsightsRequest toAWS() const {
        Aws::DynamoDB::Model::UpdateContributorInsightsRequest awsUpdateContributorInsightsRequest;

		if (!(this->tableName.IsEmpty())) {
            awsUpdateContributorInsightsRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

		if (!(this->indexName.IsEmpty())) {
            awsUpdateContributorInsightsRequest.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        switch(this->contributorInsightsAction) {
            case EAWSContributorInsightsAction::ENABLE:
                awsUpdateContributorInsightsRequest.SetContributorInsightsAction(Aws::DynamoDB::Model::ContributorInsightsAction::ENABLE);
                break;
            case EAWSContributorInsightsAction::DISABLE:
                awsUpdateContributorInsightsRequest.SetContributorInsightsAction(Aws::DynamoDB::Model::ContributorInsightsAction::DISABLE);
                break;
            default:
                break;
            }

        return awsUpdateContributorInsightsRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->indexName.IsEmpty() && contributorInsightsAction == EAWSContributorInsightsAction::NOT_SET;
    }
#endif
};
