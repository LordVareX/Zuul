/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaGlobalSecondaryIndexSettingsDescription.h"

#endif

#include "Model/IndexStatus.h"
#include "Model/AutoScalingSettingsDescription.h"
#include "Model/AutoScalingSettingsDescription.h"

#include "ReplicaGlobalSecondaryIndexSettingsDescription.generated.h"

USTRUCT(BlueprintType)
struct FReplicaGlobalSecondaryIndexSettingsDescription {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index. The name must be unique among all other indexes on this table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p> The current status of the global secondary index:</p> <ul> <li> <p> <code>CREATING</code> - The global secondary index is being created.</p> </li> <li> <p> <code>UPDATING</code> - The global secondary index is being updated.</p> </li> <li> <p> <code>DELETING</code> - The global secondary index is being deleted.</p> </li> <li> <p> <code>ACTIVE</code> - The global secondary index is ready for use.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSIndexStatus indexStatus = EAWSIndexStatus::NOT_SET;

    /**
    *  <p>The maximum number of strongly consistent reads consumed per second before DynamoDB returns a <code>ThrottlingException</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 provisionedReadCapacityUnits = 0;

    /**
    *  <p>Autoscaling settings for a global secondary index replica's read capacity units.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsDescription provisionedReadCapacityAutoScalingSettings;

    /**
    *  <p>The maximum number of writes consumed per second before DynamoDB returns a <code>ThrottlingException</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 provisionedWriteCapacityUnits = 0;

    /**
    *  <p>AutoScaling settings for a global secondary index replica's write capacity units.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsDescription provisionedWriteCapacityAutoScalingSettings;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FReplicaGlobalSecondaryIndexSettingsDescription &fromAWS(const Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndexSettingsDescription &awsReplicaGlobalSecondaryIndexSettingsDescription) {
        this->indexName = UTF8_TO_TCHAR(awsReplicaGlobalSecondaryIndexSettingsDescription.GetIndexName().c_str());

        switch(awsReplicaGlobalSecondaryIndexSettingsDescription.GetIndexStatus()) {
            case Aws::DynamoDB::Model::IndexStatus::NOT_SET:
                this->indexStatus = EAWSIndexStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::IndexStatus::CREATING:
                this->indexStatus = EAWSIndexStatus::CREATING;
                break;
            case Aws::DynamoDB::Model::IndexStatus::UPDATING:
                this->indexStatus = EAWSIndexStatus::UPDATING;
                break;
            case Aws::DynamoDB::Model::IndexStatus::DELETING:
                this->indexStatus = EAWSIndexStatus::DELETING;
                break;
            case Aws::DynamoDB::Model::IndexStatus::ACTIVE:
                this->indexStatus = EAWSIndexStatus::ACTIVE;
                break;
            default:
                this->indexStatus = EAWSIndexStatus::NOT_SET;
                break;
        }

        this->provisionedReadCapacityUnits = (int64)awsReplicaGlobalSecondaryIndexSettingsDescription.GetProvisionedReadCapacityUnits();

        this->provisionedReadCapacityAutoScalingSettings.fromAWS(awsReplicaGlobalSecondaryIndexSettingsDescription.GetProvisionedReadCapacityAutoScalingSettings());

        this->provisionedWriteCapacityUnits = (int64)awsReplicaGlobalSecondaryIndexSettingsDescription.GetProvisionedWriteCapacityUnits();

        this->provisionedWriteCapacityAutoScalingSettings.fromAWS(awsReplicaGlobalSecondaryIndexSettingsDescription.GetProvisionedWriteCapacityAutoScalingSettings());

        return *this;
    }
#endif
};
