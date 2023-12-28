/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaSettingsDescription.h"

#endif

#include "Model/ReplicaStatus.h"
#include "Model/BillingModeSummary.h"
#include "Model/AutoScalingSettingsDescription.h"
#include "Model/AutoScalingSettingsDescription.h"
#include "Model/ReplicaGlobalSecondaryIndexSettingsDescription.h"
#include "Model/AWSDynamoDBTableClassSummary.h"

#include "ReplicaSettingsDescription.generated.h"

USTRUCT(BlueprintType)
struct FReplicaSettingsDescription {
GENERATED_BODY()

    /**
    *  <p>The region name of the replica.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString regionName;

    /**
    *  <p>The current state of the region:</p> <ul> <li> <p> <code>CREATING</code> - The region is being created.</p> </li> <li> <p> <code>UPDATING</code> - The region is being updated.</p> </li> <li> <p> <code>DELETING</code> - The region is being deleted.</p> </li> <li> <p> <code>ACTIVE</code> - The region is ready for use.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReplicaStatus replicaStatus = EAWSReplicaStatus::NOT_SET;

    /**
    *  <p>The read/write capacity mode of the replica.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FBillingModeSummary replicaBillingModeSummary;

    /**
    *  <p>The maximum number of strongly consistent reads consumed per second before DynamoDB returns a <code>ThrottlingException</code>. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/WorkingWithTables.html#ProvisionedThroughput">Specifying Read and Write Requirements</a> in the <i>Amazon DynamoDB Developer Guide</i>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 replicaProvisionedReadCapacityUnits = 0;

    /**
    *  <p>Autoscaling settings for a global table replica's read capacity units.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsDescription replicaProvisionedReadCapacityAutoScalingSettings;

    /**
    *  <p>The maximum number of writes consumed per second before DynamoDB returns a <code>ThrottlingException</code>. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/WorkingWithTables.html#ProvisionedThroughput">Specifying Read and Write Requirements</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 replicaProvisionedWriteCapacityUnits = 0;

    /**
    *  <p>AutoScaling settings for a global table replica's write capacity units.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsDescription replicaProvisionedWriteCapacityAutoScalingSettings;

    /**
    *  <p>Replica global secondary index settings for the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaGlobalSecondaryIndexSettingsDescription> replicaGlobalSecondaryIndexSettings;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBTableClassSummary replicaTableClassSummary;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FReplicaSettingsDescription &fromAWS(const Aws::DynamoDB::Model::ReplicaSettingsDescription &awsReplicaSettingsDescription) {
        this->regionName = UTF8_TO_TCHAR(awsReplicaSettingsDescription.GetRegionName().c_str());

        switch(awsReplicaSettingsDescription.GetReplicaStatus()) {
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

        this->replicaBillingModeSummary.fromAWS(awsReplicaSettingsDescription.GetReplicaBillingModeSummary());

        this->replicaProvisionedReadCapacityUnits = (int64)awsReplicaSettingsDescription.GetReplicaProvisionedReadCapacityUnits();

        this->replicaProvisionedReadCapacityAutoScalingSettings.fromAWS(awsReplicaSettingsDescription.GetReplicaProvisionedReadCapacityAutoScalingSettings());

        this->replicaProvisionedWriteCapacityUnits = (int64)awsReplicaSettingsDescription.GetReplicaProvisionedWriteCapacityUnits();

        this->replicaProvisionedWriteCapacityAutoScalingSettings.fromAWS(awsReplicaSettingsDescription.GetReplicaProvisionedWriteCapacityAutoScalingSettings());

        this->replicaGlobalSecondaryIndexSettings.Empty();
        for (const Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndexSettingsDescription& elem : awsReplicaSettingsDescription.GetReplicaGlobalSecondaryIndexSettings()) {
            this->replicaGlobalSecondaryIndexSettings.Add(FReplicaGlobalSecondaryIndexSettingsDescription().fromAWS(elem));
        }

        this->replicaTableClassSummary.fromAWS(awsReplicaSettingsDescription.GetReplicaTableClassSummary());

        return *this;
    }
#endif
};
