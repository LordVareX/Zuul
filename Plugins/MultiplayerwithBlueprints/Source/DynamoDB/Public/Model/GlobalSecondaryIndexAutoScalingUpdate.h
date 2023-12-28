/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/GlobalSecondaryIndexAutoScalingUpdate.h"

#endif

#include "Model/AutoScalingSettingsUpdate.h"

#include "GlobalSecondaryIndexAutoScalingUpdate.generated.h"

USTRUCT(BlueprintType)
struct FGlobalSecondaryIndexAutoScalingUpdate {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsUpdate provisionedWriteCapacityAutoScalingUpdate;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::GlobalSecondaryIndexAutoScalingUpdate toAWS() const {
        Aws::DynamoDB::Model::GlobalSecondaryIndexAutoScalingUpdate awsGlobalSecondaryIndexAutoScalingUpdate;

		if (!(this->indexName.IsEmpty())) {
            awsGlobalSecondaryIndexAutoScalingUpdate.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        if (!(this->provisionedWriteCapacityAutoScalingUpdate.IsEmpty())) {
            awsGlobalSecondaryIndexAutoScalingUpdate.SetProvisionedWriteCapacityAutoScalingUpdate(this->provisionedWriteCapacityAutoScalingUpdate.toAWS());
        }

        return awsGlobalSecondaryIndexAutoScalingUpdate;
    }

    bool IsEmpty() const {
        return this->indexName.IsEmpty() && this->provisionedWriteCapacityAutoScalingUpdate.IsEmpty();
    }
#endif
};
