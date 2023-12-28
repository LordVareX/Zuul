/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/RestoreTableToPointInTimeRequest.h"

#endif

#include "Model/BillingMode.h"
#include "Model/GlobalSecondaryIndex.h"
#include "Model/LocalSecondaryIndex.h"
#include "Model/ProvisionedThroughput.h"
#include "Model/SSESpecification.h"

#include "RestoreTableToPointInTimeRequest.generated.h"

USTRUCT(BlueprintType)
struct FRestoreTableToPointInTimeRequest {
    GENERATED_BODY()

    /**
    *  <p>The DynamoDB table that will be restored. This value is an Amazon Resource Name (ARN).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString sourceTableArn;

    /**
    *  <p>Name of the source table that is being restored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString sourceTableName;

    /**
    *  <p>The name of the new table to which it must be restored to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString targetTableName;

    /**
    *  <p>Restore the table to the latest possible time. <code>LatestRestorableDateTime</code> is typically 5 minutes before the current time. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool useLatestRestorableTime = false;

    /**
    *  <p>Time in the past to restore the table to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime restoreDateTime;

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
    Aws::DynamoDB::Model::RestoreTableToPointInTimeRequest toAWS() const {
        Aws::DynamoDB::Model::RestoreTableToPointInTimeRequest awsRestoreTableToPointInTimeRequest;

		if (!(this->sourceTableArn.IsEmpty())) {
            awsRestoreTableToPointInTimeRequest.SetSourceTableArn(TCHAR_TO_UTF8(*this->sourceTableArn));
        }

		if (!(this->sourceTableName.IsEmpty())) {
            awsRestoreTableToPointInTimeRequest.SetSourceTableName(TCHAR_TO_UTF8(*this->sourceTableName));
        }

		if (!(this->targetTableName.IsEmpty())) {
            awsRestoreTableToPointInTimeRequest.SetTargetTableName(TCHAR_TO_UTF8(*this->targetTableName));
        }

		awsRestoreTableToPointInTimeRequest.SetUseLatestRestorableTime(this->useLatestRestorableTime);

		awsRestoreTableToPointInTimeRequest.SetRestoreDateTime(Aws::Utils::DateTime((int64_t)((this->restoreDateTime - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));


        switch(this->billingModeOverride) {
            case EAWSBillingMode::PROVISIONED:
                awsRestoreTableToPointInTimeRequest.SetBillingModeOverride(Aws::DynamoDB::Model::BillingMode::PROVISIONED);
                break;
            case EAWSBillingMode::PAY_PER_REQUEST:
                awsRestoreTableToPointInTimeRequest.SetBillingModeOverride(Aws::DynamoDB::Model::BillingMode::PAY_PER_REQUEST);
                break;
            default:
                break;
            }

        for (const FGlobalSecondaryIndex& elem : this->globalSecondaryIndexOverride) {
            awsRestoreTableToPointInTimeRequest.AddGlobalSecondaryIndexOverride(elem.toAWS());
        }

        for (const FLocalSecondaryIndex& elem : this->localSecondaryIndexOverride) {
            awsRestoreTableToPointInTimeRequest.AddLocalSecondaryIndexOverride(elem.toAWS());
        }

        if (!(this->provisionedThroughputOverride.IsEmpty())) {
            awsRestoreTableToPointInTimeRequest.SetProvisionedThroughputOverride(this->provisionedThroughputOverride.toAWS());
        }

        if (!(this->sSESpecificationOverride.IsEmpty())) {
            awsRestoreTableToPointInTimeRequest.SetSSESpecificationOverride(this->sSESpecificationOverride.toAWS());
        }

        return awsRestoreTableToPointInTimeRequest;
    }

    bool IsEmpty() const {
        return this->sourceTableArn.IsEmpty() && this->sourceTableName.IsEmpty() && this->targetTableName.IsEmpty() && false && false && billingModeOverride == EAWSBillingMode::NOT_SET && this->globalSecondaryIndexOverride.Num() == 0 && this->localSecondaryIndexOverride.Num() == 0 && this->provisionedThroughputOverride.IsEmpty() && this->sSESpecificationOverride.IsEmpty();
    }
#endif
};
