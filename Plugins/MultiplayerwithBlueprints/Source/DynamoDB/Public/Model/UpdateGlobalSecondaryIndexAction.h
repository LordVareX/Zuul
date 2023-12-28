/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateGlobalSecondaryIndexAction.h"

#endif

#include "Model/ProvisionedThroughput.h"

#include "UpdateGlobalSecondaryIndexAction.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGlobalSecondaryIndexAction {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index to be updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>Represents the provisioned throughput settings for the specified global secondary index.</p> <p>For current minimum and maximum provisioned throughput values, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Limits.html">Limits</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughput provisionedThroughput;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::UpdateGlobalSecondaryIndexAction toAWS() const {
        Aws::DynamoDB::Model::UpdateGlobalSecondaryIndexAction awsUpdateGlobalSecondaryIndexAction;

		if (!(this->indexName.IsEmpty())) {
            awsUpdateGlobalSecondaryIndexAction.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        if (!(this->provisionedThroughput.IsEmpty())) {
            awsUpdateGlobalSecondaryIndexAction.SetProvisionedThroughput(this->provisionedThroughput.toAWS());
        }

        return awsUpdateGlobalSecondaryIndexAction;
    }

    bool IsEmpty() const {
        return this->indexName.IsEmpty() && this->provisionedThroughput.IsEmpty();
    }
#endif
};
