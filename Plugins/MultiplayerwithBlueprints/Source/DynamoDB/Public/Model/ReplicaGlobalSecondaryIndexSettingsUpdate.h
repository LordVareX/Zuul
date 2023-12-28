/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaGlobalSecondaryIndexSettingsUpdate.h"

#endif

#include "Model/AutoScalingSettingsUpdate.h"

#include "ReplicaGlobalSecondaryIndexSettingsUpdate.generated.h"

USTRUCT(BlueprintType)
struct FReplicaGlobalSecondaryIndexSettingsUpdate {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index. The name must be unique among all other indexes on this table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>The maximum number of strongly consistent reads consumed per second before DynamoDB returns a <code>ThrottlingException</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 provisionedReadCapacityUnits = 0;

    /**
    *  <p>Autoscaling settings for managing a global secondary index replica's read capacity units.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsUpdate provisionedReadCapacityAutoScalingSettingsUpdate;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndexSettingsUpdate toAWS() const {
        Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndexSettingsUpdate awsReplicaGlobalSecondaryIndexSettingsUpdate;

		if (!(this->indexName.IsEmpty())) {
            awsReplicaGlobalSecondaryIndexSettingsUpdate.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        if (this->provisionedReadCapacityUnits != 0) {
            awsReplicaGlobalSecondaryIndexSettingsUpdate.SetProvisionedReadCapacityUnits(this->provisionedReadCapacityUnits);
        }

        if (!(this->provisionedReadCapacityAutoScalingSettingsUpdate.IsEmpty())) {
            awsReplicaGlobalSecondaryIndexSettingsUpdate.SetProvisionedReadCapacityAutoScalingSettingsUpdate(this->provisionedReadCapacityAutoScalingSettingsUpdate.toAWS());
        }

        return awsReplicaGlobalSecondaryIndexSettingsUpdate;
    }

    bool IsEmpty() const {
        return this->indexName.IsEmpty() && this->provisionedReadCapacityUnits == 0 && this->provisionedReadCapacityAutoScalingSettingsUpdate.IsEmpty();
    }
#endif
};
