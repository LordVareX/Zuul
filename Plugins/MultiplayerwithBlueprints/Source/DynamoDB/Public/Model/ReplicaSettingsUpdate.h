/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaSettingsUpdate.h"

#endif

#include "Model/AutoScalingSettingsUpdate.h"
#include "Model/ReplicaGlobalSecondaryIndexSettingsUpdate.h"
#include "Model/AWSDynamoDBTableClass.h"

#include "ReplicaSettingsUpdate.generated.h"

USTRUCT(BlueprintType)
struct FReplicaSettingsUpdate {
GENERATED_BODY()

    /**
    *  <p>The region of the replica to be added.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString regionName;

    /**
    *  <p>The maximum number of strongly consistent reads consumed per second before DynamoDB returns a <code>ThrottlingException</code>. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/WorkingWithTables.html#ProvisionedThroughput">Specifying Read and Write Requirements</a> in the <i>Amazon DynamoDB Developer Guide</i>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 replicaProvisionedReadCapacityUnits = 0;

    /**
    *  <p>Autoscaling settings for managing a global table replica's read capacity units.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsUpdate replicaProvisionedReadCapacityAutoScalingSettingsUpdate;

    /**
    *  <p>Represents the settings of a global secondary index for a global table that will be modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaGlobalSecondaryIndexSettingsUpdate> replicaGlobalSecondaryIndexSettingsUpdate;

    /**
    *  <p>Replica-specific table class. If not specified, uses the source table's table class.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBTableClass replicaTableClass = EAWSDynamoDBTableClass::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ReplicaSettingsUpdate toAWS() const {
        Aws::DynamoDB::Model::ReplicaSettingsUpdate awsReplicaSettingsUpdate;

		if (!(this->regionName.IsEmpty())) {
            awsReplicaSettingsUpdate.SetRegionName(TCHAR_TO_UTF8(*this->regionName));
        }

        if (this->replicaProvisionedReadCapacityUnits != 0) {
            awsReplicaSettingsUpdate.SetReplicaProvisionedReadCapacityUnits(this->replicaProvisionedReadCapacityUnits);
        }

        if (!(this->replicaProvisionedReadCapacityAutoScalingSettingsUpdate.IsEmpty())) {
            awsReplicaSettingsUpdate.SetReplicaProvisionedReadCapacityAutoScalingSettingsUpdate(this->replicaProvisionedReadCapacityAutoScalingSettingsUpdate.toAWS());
        }

        for (const FReplicaGlobalSecondaryIndexSettingsUpdate& elem : this->replicaGlobalSecondaryIndexSettingsUpdate) {
            awsReplicaSettingsUpdate.AddReplicaGlobalSecondaryIndexSettingsUpdate(elem.toAWS());
        }

        switch(this->replicaTableClass) {
            case EAWSDynamoDBTableClass::STANDARD:
                awsReplicaSettingsUpdate.SetReplicaTableClass(Aws::DynamoDB::Model::TableClass::STANDARD);
                break;
            case EAWSDynamoDBTableClass::STANDARD_INFREQUENT_ACCESS:
                awsReplicaSettingsUpdate.SetReplicaTableClass(Aws::DynamoDB::Model::TableClass::STANDARD_INFREQUENT_ACCESS);
                break;
            default:
                break;
        }

        return awsReplicaSettingsUpdate;
    }

    bool IsEmpty() const {
        return this->regionName.IsEmpty() && this->replicaProvisionedReadCapacityUnits == 0 && this->replicaProvisionedReadCapacityAutoScalingSettingsUpdate.IsEmpty() && this->replicaGlobalSecondaryIndexSettingsUpdate.Num() == 0 && this->replicaTableClass == EAWSDynamoDBTableClass::NOT_SET;
    }
#endif
};
