/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaGlobalSecondaryIndexAutoScalingUpdate.h"

#endif

#include "Model/AutoScalingSettingsUpdate.h"

#include "ReplicaGlobalSecondaryIndexAutoScalingUpdate.generated.h"

USTRUCT(BlueprintType)
struct FReplicaGlobalSecondaryIndexAutoScalingUpdate {
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
    FAutoScalingSettingsUpdate provisionedReadCapacityAutoScalingUpdate;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndexAutoScalingUpdate toAWS() const {
        Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndexAutoScalingUpdate awsReplicaGlobalSecondaryIndexAutoScalingUpdate;

		if (!(this->indexName.IsEmpty())) {
            awsReplicaGlobalSecondaryIndexAutoScalingUpdate.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        if (!(this->provisionedReadCapacityAutoScalingUpdate.IsEmpty())) {
            awsReplicaGlobalSecondaryIndexAutoScalingUpdate.SetProvisionedReadCapacityAutoScalingUpdate(this->provisionedReadCapacityAutoScalingUpdate.toAWS());
        }

        return awsReplicaGlobalSecondaryIndexAutoScalingUpdate;
    }

    bool IsEmpty() const {
        return this->indexName.IsEmpty() && this->provisionedReadCapacityAutoScalingUpdate.IsEmpty();
    }
#endif
};
