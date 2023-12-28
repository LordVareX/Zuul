/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaAutoScalingUpdate.h"

#endif

#include "Model/ReplicaGlobalSecondaryIndexAutoScalingUpdate.h"
#include "Model/AutoScalingSettingsUpdate.h"

#include "ReplicaAutoScalingUpdate.generated.h"

USTRUCT(BlueprintType)
struct FReplicaAutoScalingUpdate {
GENERATED_BODY()

    /**
    *  <p>The Region where the replica exists.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString regionName;

    /**
    *  <p>Represents the auto scaling settings of global secondary indexes that will be modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaGlobalSecondaryIndexAutoScalingUpdate> replicaGlobalSecondaryIndexUpdates;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsUpdate replicaProvisionedReadCapacityAutoScalingUpdate;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ReplicaAutoScalingUpdate toAWS() const {
        Aws::DynamoDB::Model::ReplicaAutoScalingUpdate awsReplicaAutoScalingUpdate;

		if (!(this->regionName.IsEmpty())) {
            awsReplicaAutoScalingUpdate.SetRegionName(TCHAR_TO_UTF8(*this->regionName));
        }

        for (const FReplicaGlobalSecondaryIndexAutoScalingUpdate& elem : this->replicaGlobalSecondaryIndexUpdates) {
            awsReplicaAutoScalingUpdate.AddReplicaGlobalSecondaryIndexUpdates(elem.toAWS());
        }

        if (!(this->replicaProvisionedReadCapacityAutoScalingUpdate.IsEmpty())) {
            awsReplicaAutoScalingUpdate.SetReplicaProvisionedReadCapacityAutoScalingUpdate(this->replicaProvisionedReadCapacityAutoScalingUpdate.toAWS());
        }

        return awsReplicaAutoScalingUpdate;
    }

    bool IsEmpty() const {
        return this->regionName.IsEmpty() && this->replicaGlobalSecondaryIndexUpdates.Num() == 0 && this->replicaProvisionedReadCapacityAutoScalingUpdate.IsEmpty();
    }
#endif
};
