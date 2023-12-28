/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/RestoreTableFromBackupRequest.h"

#endif

#include "Model/BillingMode.h"
#include "Model/GlobalSecondaryIndex.h"
#include "Model/LocalSecondaryIndex.h"
#include "Model/ProvisionedThroughput.h"
#include "Model/SSESpecification.h"

#include "RestoreTableFromBackupRequest.generated.h"

USTRUCT(BlueprintType)
struct FRestoreTableFromBackupRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the new table to which the backup must be restored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString targetTableName;

    /**
    *  <p>The Amazon Resource Name (ARN) associated with the backup.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString backupArn;

    /**
    *  <p>The billing mode of the restored table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBillingMode billingModeOverride = EAWSBillingMode::NOT_SET;

    /**
    *  <p>List of global secondary indexes for the restored table. The indexes provided should match existing secondary indexes. You can choose to exclude some or all of the indexes at the time of restore.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FGlobalSecondaryIndex> globalSecondaryIndexOverride;

    /**
    *  <p>List of local secondary indexes for the restored table. The indexes provided should match existing secondary indexes. You can choose to exclude some or all of the indexes at the time of restore.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FLocalSecondaryIndex> localSecondaryIndexOverride;

    /**
    *  <p>Provisioned throughput settings for the restored table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughput provisionedThroughputOverride;

    /**
    *  <p>The new server-side encryption settings for the restored table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FSSESpecification sSESpecificationOverride;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::RestoreTableFromBackupRequest toAWS() const {
        Aws::DynamoDB::Model::RestoreTableFromBackupRequest awsRestoreTableFromBackupRequest;

		if (!(this->targetTableName.IsEmpty())) {
            awsRestoreTableFromBackupRequest.SetTargetTableName(TCHAR_TO_UTF8(*this->targetTableName));
        }

		if (!(this->backupArn.IsEmpty())) {
            awsRestoreTableFromBackupRequest.SetBackupArn(TCHAR_TO_UTF8(*this->backupArn));
        }

        switch(this->billingModeOverride) {
            case EAWSBillingMode::PROVISIONED:
                awsRestoreTableFromBackupRequest.SetBillingModeOverride(Aws::DynamoDB::Model::BillingMode::PROVISIONED);
                break;
            case EAWSBillingMode::PAY_PER_REQUEST:
                awsRestoreTableFromBackupRequest.SetBillingModeOverride(Aws::DynamoDB::Model::BillingMode::PAY_PER_REQUEST);
                break;
            default:
                break;
		}

        for (const FGlobalSecondaryIndex& elem : this->globalSecondaryIndexOverride) {
            awsRestoreTableFromBackupRequest.AddGlobalSecondaryIndexOverride(elem.toAWS());
        }

        for (const FLocalSecondaryIndex& elem : this->localSecondaryIndexOverride) {
            awsRestoreTableFromBackupRequest.AddLocalSecondaryIndexOverride(elem.toAWS());
        }

        if (!(this->provisionedThroughputOverride.IsEmpty())) {
            awsRestoreTableFromBackupRequest.SetProvisionedThroughputOverride(this->provisionedThroughputOverride.toAWS());
        }

        if (!(this->sSESpecificationOverride.IsEmpty())) {
            awsRestoreTableFromBackupRequest.SetSSESpecificationOverride(this->sSESpecificationOverride.toAWS());
        }

        return awsRestoreTableFromBackupRequest;
    }

    bool IsEmpty() const {
        return this->targetTableName.IsEmpty() && this->backupArn.IsEmpty() && billingModeOverride == EAWSBillingMode::NOT_SET && this->globalSecondaryIndexOverride.Num() == 0 && this->localSecondaryIndexOverride.Num() == 0 && this->provisionedThroughputOverride.IsEmpty() && this->sSESpecificationOverride.IsEmpty();
    }
#endif
};
