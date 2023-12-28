/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateTableReplicaAutoScalingRequest.h"

#endif

#include "Model/GlobalSecondaryIndexAutoScalingUpdate.h"
#include "Model/AutoScalingSettingsUpdate.h"
#include "Model/ReplicaAutoScalingUpdate.h"

#include "UpdateTableReplicaAutoScalingRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateTableReplicaAutoScalingRequest {
GENERATED_BODY()

    /**
    *  <p>Represents the auto scaling settings of the global secondary indexes of the replica to be updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FGlobalSecondaryIndexAutoScalingUpdate> globalSecondaryIndexUpdates;

    /**
    *  <p>The name of the global table to be updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsUpdate provisionedWriteCapacityAutoScalingUpdate;

    /**
    *  <p>Represents the auto scaling settings of replicas of the table that will be modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaAutoScalingUpdate> replicaUpdates;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::UpdateTableReplicaAutoScalingRequest toAWS() const {
        Aws::DynamoDB::Model::UpdateTableReplicaAutoScalingRequest awsUpdateTableReplicaAutoScalingRequest;

        for (const FGlobalSecondaryIndexAutoScalingUpdate& elem : this->globalSecondaryIndexUpdates) {
            awsUpdateTableReplicaAutoScalingRequest.AddGlobalSecondaryIndexUpdates(elem.toAWS());
        }

		if (!(this->tableName.IsEmpty())) {
            awsUpdateTableReplicaAutoScalingRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        if (!(this->provisionedWriteCapacityAutoScalingUpdate.IsEmpty())) {
            awsUpdateTableReplicaAutoScalingRequest.SetProvisionedWriteCapacityAutoScalingUpdate(this->provisionedWriteCapacityAutoScalingUpdate.toAWS());
        }

        for (const FReplicaAutoScalingUpdate& elem : this->replicaUpdates) {
            awsUpdateTableReplicaAutoScalingRequest.AddReplicaUpdates(elem.toAWS());
        }

        return awsUpdateTableReplicaAutoScalingRequest;
    }

    bool IsEmpty() const {
        return this->globalSecondaryIndexUpdates.Num() == 0 && this->tableName.IsEmpty() && this->provisionedWriteCapacityAutoScalingUpdate.IsEmpty() && this->replicaUpdates.Num() == 0;
    }
#endif
};
