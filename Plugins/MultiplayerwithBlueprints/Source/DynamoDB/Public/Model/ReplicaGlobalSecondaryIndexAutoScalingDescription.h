/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaGlobalSecondaryIndexAutoScalingDescription.h"

#endif

#include "Model/IndexStatus.h"
#include "Model/AutoScalingSettingsDescription.h"
#include "Model/AutoScalingSettingsDescription.h"

#include "ReplicaGlobalSecondaryIndexAutoScalingDescription.generated.h"

USTRUCT(BlueprintType)
struct FReplicaGlobalSecondaryIndexAutoScalingDescription {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>The current state of the replica global secondary index:</p> <ul> <li> <p> <code>CREATING</code> - The index is being created.</p> </li> <li> <p> <code>UPDATING</code> - The index is being updated.</p> </li> <li> <p> <code>DELETING</code> - The index is being deleted.</p> </li> <li> <p> <code>ACTIVE</code> - The index is ready for use.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSIndexStatus indexStatus = EAWSIndexStatus::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsDescription provisionedReadCapacityAutoScalingSettings;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsDescription provisionedWriteCapacityAutoScalingSettings;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FReplicaGlobalSecondaryIndexAutoScalingDescription &fromAWS(const Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndexAutoScalingDescription &awsReplicaGlobalSecondaryIndexAutoScalingDescription) {
        this->indexName = UTF8_TO_TCHAR(awsReplicaGlobalSecondaryIndexAutoScalingDescription.GetIndexName().c_str());

        switch(awsReplicaGlobalSecondaryIndexAutoScalingDescription.GetIndexStatus()) {
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

        this->provisionedReadCapacityAutoScalingSettings.fromAWS(awsReplicaGlobalSecondaryIndexAutoScalingDescription.GetProvisionedReadCapacityAutoScalingSettings());

        this->provisionedWriteCapacityAutoScalingSettings.fromAWS(awsReplicaGlobalSecondaryIndexAutoScalingDescription.GetProvisionedWriteCapacityAutoScalingSettings());

        return *this;
    }
#endif
};
