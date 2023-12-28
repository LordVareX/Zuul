/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaAutoScalingDescription.h"

#endif

#include "Model/ReplicaGlobalSecondaryIndexAutoScalingDescription.h"
#include "Model/AutoScalingSettingsDescription.h"
#include "Model/AutoScalingSettingsDescription.h"
#include "Model/ReplicaStatus.h"

#include "ReplicaAutoScalingDescription.generated.h"

USTRUCT(BlueprintType)
struct FReplicaAutoScalingDescription {
GENERATED_BODY()

    /**
    *  <p>The Region where the replica exists.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString regionName;

    /**
    *  <p>Replica-specific global secondary index auto scaling settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaGlobalSecondaryIndexAutoScalingDescription> globalSecondaryIndexes;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsDescription replicaProvisionedReadCapacityAutoScalingSettings;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsDescription replicaProvisionedWriteCapacityAutoScalingSettings;

    /**
    *  <p>The current state of the replica:</p> <ul> <li> <p> <code>CREATING</code> - The replica is being created.</p> </li> <li> <p> <code>UPDATING</code> - The replica is being updated.</p> </li> <li> <p> <code>DELETING</code> - The replica is being deleted.</p> </li> <li> <p> <code>ACTIVE</code> - The replica is ready for use.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReplicaStatus replicaStatus = EAWSReplicaStatus::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FReplicaAutoScalingDescription &fromAWS(const Aws::DynamoDB::Model::ReplicaAutoScalingDescription &awsReplicaAutoScalingDescription) {
        this->regionName = UTF8_TO_TCHAR(awsReplicaAutoScalingDescription.GetRegionName().c_str());

        this->globalSecondaryIndexes.Empty();
        for (const Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndexAutoScalingDescription& elem : awsReplicaAutoScalingDescription.GetGlobalSecondaryIndexes()) {
            this->globalSecondaryIndexes.Add(FReplicaGlobalSecondaryIndexAutoScalingDescription().fromAWS(elem));
        }

        this->replicaProvisionedReadCapacityAutoScalingSettings.fromAWS(awsReplicaAutoScalingDescription.GetReplicaProvisionedReadCapacityAutoScalingSettings());

        this->replicaProvisionedWriteCapacityAutoScalingSettings.fromAWS(awsReplicaAutoScalingDescription.GetReplicaProvisionedWriteCapacityAutoScalingSettings());

        switch(awsReplicaAutoScalingDescription.GetReplicaStatus()) {
            case Aws::DynamoDB::Model::ReplicaStatus::NOT_SET:
                this->replicaStatus = EAWSReplicaStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::ReplicaStatus::CREATING:
                this->replicaStatus = EAWSReplicaStatus::CREATING;
                break;
            case Aws::DynamoDB::Model::ReplicaStatus::CREATION_FAILED:
                this->replicaStatus = EAWSReplicaStatus::CREATION_FAILED;
                break;
            case Aws::DynamoDB::Model::ReplicaStatus::UPDATING:
                this->replicaStatus = EAWSReplicaStatus::UPDATING;
                break;
            case Aws::DynamoDB::Model::ReplicaStatus::DELETING:
                this->replicaStatus = EAWSReplicaStatus::DELETING;
                break;
            case Aws::DynamoDB::Model::ReplicaStatus::ACTIVE:
                this->replicaStatus = EAWSReplicaStatus::ACTIVE;
                break;
            case Aws::DynamoDB::Model::ReplicaStatus::REGION_DISABLED:
                this->replicaStatus = EAWSReplicaStatus::REGION_DISABLED;
                break;
            case Aws::DynamoDB::Model::ReplicaStatus::INACCESSIBLE_ENCRYPTION_CREDENTIALS:
                this->replicaStatus = EAWSReplicaStatus::INACCESSIBLE_ENCRYPTION_CREDENTIALS;
                break;
            default:
                this->replicaStatus = EAWSReplicaStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
