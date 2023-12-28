/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateGlobalTableSettingsRequest.h"

#endif

#include "Model/BillingMode.h"
#include "Model/AutoScalingSettingsUpdate.h"
#include "Model/GlobalTableGlobalSecondaryIndexSettingsUpdate.h"
#include "Model/ReplicaSettingsUpdate.h"

#include "UpdateGlobalTableSettingsRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGlobalTableSettingsRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the global table</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString globalTableName;

    /**
    *  <p>The billing mode of the global table. If <code>GlobalTableBillingMode</code> is not specified, the global table defaults to <code>PROVISIONED</code> capacity billing mode.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBillingMode globalTableBillingMode = EAWSBillingMode::NOT_SET;

    /**
    *  <p>The maximum number of writes consumed per second before DynamoDB returns a <code>ThrottlingException.</code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 globalTableProvisionedWriteCapacityUnits = 0;

    /**
    *  <p>Auto scaling settings for managing provisioned write capacity for the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingSettingsUpdate globalTableProvisionedWriteCapacityAutoScalingSettingsUpdate;

    /**
    *  <p>Represents the settings of a global secondary index for a global table that will be modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FGlobalTableGlobalSecondaryIndexSettingsUpdate> globalTableGlobalSecondaryIndexSettingsUpdate;

    /**
    *  <p>Represents the settings for a global table in a Region that will be modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaSettingsUpdate> replicaSettingsUpdate;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::UpdateGlobalTableSettingsRequest toAWS() const {
        Aws::DynamoDB::Model::UpdateGlobalTableSettingsRequest awsUpdateGlobalTableSettingsRequest;

		if (!(this->globalTableName.IsEmpty())) {
            awsUpdateGlobalTableSettingsRequest.SetGlobalTableName(TCHAR_TO_UTF8(*this->globalTableName));
        }

        switch(this->globalTableBillingMode) {
            case EAWSBillingMode::PROVISIONED:
                awsUpdateGlobalTableSettingsRequest.SetGlobalTableBillingMode(Aws::DynamoDB::Model::BillingMode::PROVISIONED);
                break;
            case EAWSBillingMode::PAY_PER_REQUEST:
                awsUpdateGlobalTableSettingsRequest.SetGlobalTableBillingMode(Aws::DynamoDB::Model::BillingMode::PAY_PER_REQUEST);
                break;
            default:
                break;
            }

        if (this->globalTableProvisionedWriteCapacityUnits != 0) {
            awsUpdateGlobalTableSettingsRequest.SetGlobalTableProvisionedWriteCapacityUnits(this->globalTableProvisionedWriteCapacityUnits);
        }

        if (!(this->globalTableProvisionedWriteCapacityAutoScalingSettingsUpdate.IsEmpty())) {
            awsUpdateGlobalTableSettingsRequest.SetGlobalTableProvisionedWriteCapacityAutoScalingSettingsUpdate(this->globalTableProvisionedWriteCapacityAutoScalingSettingsUpdate.toAWS());
        }

        for (const FGlobalTableGlobalSecondaryIndexSettingsUpdate& elem : this->globalTableGlobalSecondaryIndexSettingsUpdate) {
            awsUpdateGlobalTableSettingsRequest.AddGlobalTableGlobalSecondaryIndexSettingsUpdate(elem.toAWS());
        }

        for (const FReplicaSettingsUpdate& elem : this->replicaSettingsUpdate) {
            awsUpdateGlobalTableSettingsRequest.AddReplicaSettingsUpdate(elem.toAWS());
        }

        return awsUpdateGlobalTableSettingsRequest;
    }

    bool IsEmpty() const {
        return this->globalTableName.IsEmpty() && this->globalTableBillingMode == EAWSBillingMode::NOT_SET && this->globalTableProvisionedWriteCapacityUnits == 0 && this->globalTableProvisionedWriteCapacityAutoScalingSettingsUpdate.IsEmpty() && this->globalTableGlobalSecondaryIndexSettingsUpdate.Num() == 0 && this->replicaSettingsUpdate.Num() == 0;
    }
#endif
};
