/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaDescription.h"

#endif

#include "Model/ReplicaStatus.h"
#include "Model/ProvisionedThroughputOverride.h"
#include "Model/ReplicaGlobalSecondaryIndexDescription.h"
#include "Model/AWSDynamoDBTableClassSummary.h"

#include "ReplicaDescription.generated.h"

USTRUCT(BlueprintType)
struct FReplicaDescription {
GENERATED_BODY()

    /**
    *  <p>The name of the region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString regionName;

    /**
    *  <p>The current state of the replica:</p> <ul> <li> <p> <code>CREATING</code> - The replica is being created.</p> </li> <li> <p> <code>UPDATING</code> - The replica is being updated.</p> </li> <li> <p> <code>DELETING</code> - The replica is being deleted.</p> </li> <li> <p> <code>ACTIVE</code> - The replica is ready for use.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReplicaStatus replicaStatus = EAWSReplicaStatus::NOT_SET;

    /**
    *  <p>Detailed information about the replica status.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString replicaStatusDescription;

    /**
    *  <p>Specifies the progress of a Create, Update, or Delete action on the replica as a percentage.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString replicaStatusPercentProgress;

    /**
    *  <p>The AWS KMS customer master key (CMK) of the replica that will be used for AWS KMS encryption.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString kMSMasterKeyId;

    /**
    *  <p>Replica-specific provisioned throughput. If not described, uses the source table's provisioned throughput settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughputOverride provisionedThroughputOverride;

    /**
    *  <p>Replica-specific global secondary index settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaGlobalSecondaryIndexDescription> globalSecondaryIndexes;

    /**
    *  <p>The time at which the replica was first detected as inaccessible. To determine cause of inaccessibility check the <code>ReplicaStatus</code> property.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime replicaInaccessibleDateTime;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBTableClassSummary replicaTableClassSummary;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FReplicaDescription &fromAWS(const Aws::DynamoDB::Model::ReplicaDescription &awsReplicaDescription) {
        this->regionName = UTF8_TO_TCHAR(awsReplicaDescription.GetRegionName().c_str());

        switch(awsReplicaDescription.GetReplicaStatus()) {
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

        this->replicaStatusDescription = UTF8_TO_TCHAR(awsReplicaDescription.GetReplicaStatusDescription().c_str());

        this->replicaStatusPercentProgress = UTF8_TO_TCHAR(awsReplicaDescription.GetReplicaStatusPercentProgress().c_str());

        this->kMSMasterKeyId = UTF8_TO_TCHAR(awsReplicaDescription.GetKMSMasterKeyId().c_str());

            this->provisionedThroughputOverride.fromAWS(awsReplicaDescription.GetProvisionedThroughputOverride());


        this->globalSecondaryIndexes.Empty();
        for (const Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndexDescription& elem : awsReplicaDescription.GetGlobalSecondaryIndexes()) {
            this->globalSecondaryIndexes.Add(FReplicaGlobalSecondaryIndexDescription().fromAWS(elem));
        }

        this->replicaInaccessibleDateTime = FDateTime(1970, 1, 1) + FTimespan(awsReplicaDescription.GetReplicaInaccessibleDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->replicaTableClassSummary.fromAWS(awsReplicaDescription.GetReplicaTableClassSummary());

        return *this;
    }
#endif
};
