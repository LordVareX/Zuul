/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/GlobalTableGlobalSecondaryIndexSettingsUpdate.h"

#endif

#include "Model/AutoScalingSettingsUpdate.h"

#include "GlobalTableGlobalSecondaryIndexSettingsUpdate.generated.h"

USTRUCT(BlueprintType)
struct FGlobalTableGlobalSecondaryIndexSettingsUpdate {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index. The name must be unique among all other indexes on this table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>The maximum number of writes consumed per second before DynamoDB returns a <code>ThrottlingException.</code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 provisionedWriteCapacityUnits = 0;

    /**
    *  <p>AutoScaling settings for managing a global secondary index's write capacity units.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsUpdate provisionedWriteCapacityAutoScalingSettingsUpdate;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::GlobalTableGlobalSecondaryIndexSettingsUpdate toAWS() const {
        Aws::DynamoDB::Model::GlobalTableGlobalSecondaryIndexSettingsUpdate awsGlobalTableGlobalSecondaryIndexSettingsUpdate;

		if (!(this->indexName.IsEmpty())) {
            awsGlobalTableGlobalSecondaryIndexSettingsUpdate.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        if (this->provisionedWriteCapacityUnits != 0) {
            awsGlobalTableGlobalSecondaryIndexSettingsUpdate.SetProvisionedWriteCapacityUnits(this->provisionedWriteCapacityUnits);
        }

        if (!(this->provisionedWriteCapacityAutoScalingSettingsUpdate.IsEmpty())) {
            awsGlobalTableGlobalSecondaryIndexSettingsUpdate.SetProvisionedWriteCapacityAutoScalingSettingsUpdate(this->provisionedWriteCapacityAutoScalingSettingsUpdate.toAWS());
        }

        return awsGlobalTableGlobalSecondaryIndexSettingsUpdate;
    }

    bool IsEmpty() const {
        return this->indexName.IsEmpty() && this->provisionedWriteCapacityUnits == 0 && this->provisionedWriteCapacityAutoScalingSettingsUpdate.IsEmpty();
    }
#endif
};
