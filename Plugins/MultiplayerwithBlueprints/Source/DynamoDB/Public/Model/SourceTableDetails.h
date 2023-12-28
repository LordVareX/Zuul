/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/SourceTableDetails.h"

#endif

#include "Model/DynamoDBKeySchemaElement.h"
#include "Model/ProvisionedThroughput.h"
#include "Model/BillingMode.h"

#include "SourceTableDetails.generated.h"

USTRUCT(BlueprintType)
struct FSourceTableDetails {
GENERATED_BODY()

    /**
    *  <p>The name of the table for which the backup was created. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>Unique identifier for the table for which the backup was created. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableId;

    /**
    *  <p>ARN of the table for which backup was created. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableArn;

    /**
    *  <p>Size of the table in bytes. Please note this is an approximate value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 tableSizeBytes = 0;

    /**
    *  <p>Schema of the table. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBKeySchemaElement> keySchema;

    /**
    *  <p>Time when the source table was created. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime tableCreationDateTime;

    /**
    *  <p>Read IOPs and Write IOPS on the table when the backup was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughput provisionedThroughput;

    /**
    *  <p>Number of items in the table. Please note this is an approximate value. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 itemCount = 0;

    /**
    *  <p>Controls how you are charged for read and write throughput and how you manage capacity. This setting can be changed later.</p> <ul> <li> <p> <code>PROVISIONED</code> - Sets the read/write capacity mode to <code>PROVISIONED</code>. We recommend using <code>PROVISIONED</code> for predictable workloads.</p> </li> <li> <p> <code>PAY_PER_REQUEST</code> - Sets the read/write capacity mode to <code>PAY_PER_REQUEST</code>. We recommend using <code>PAY_PER_REQUEST</code> for unpredictable workloads. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBillingMode billingMode = EAWSBillingMode::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FSourceTableDetails &fromAWS(const Aws::DynamoDB::Model::SourceTableDetails &awsSourceTableDetails) {
        this->tableName = UTF8_TO_TCHAR(awsSourceTableDetails.GetTableName().c_str());

        this->tableId = UTF8_TO_TCHAR(awsSourceTableDetails.GetTableId().c_str());

        this->tableArn = UTF8_TO_TCHAR(awsSourceTableDetails.GetTableArn().c_str());

        this->tableSizeBytes = (int64)awsSourceTableDetails.GetTableSizeBytes();

        this->keySchema.Empty();
        for (const Aws::DynamoDB::Model::KeySchemaElement& elem : awsSourceTableDetails.GetKeySchema()) {
            this->keySchema.Add(FDynamoDBKeySchemaElement().fromAWS(elem));
        }

        this->tableCreationDateTime = FDateTime(1970, 1, 1) + FTimespan(awsSourceTableDetails.GetTableCreationDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->provisionedThroughput.fromAWS(awsSourceTableDetails.GetProvisionedThroughput());

        this->itemCount = (int64)awsSourceTableDetails.GetItemCount();

        switch(awsSourceTableDetails.GetBillingMode()) {
            case Aws::DynamoDB::Model::BillingMode::NOT_SET:
                this->billingMode = EAWSBillingMode::NOT_SET;
                break;
            case Aws::DynamoDB::Model::BillingMode::PROVISIONED:
                this->billingMode = EAWSBillingMode::PROVISIONED;
                break;
            case Aws::DynamoDB::Model::BillingMode::PAY_PER_REQUEST:
                this->billingMode = EAWSBillingMode::PAY_PER_REQUEST;
                break;
            default:
                this->billingMode = EAWSBillingMode::NOT_SET;
                break;
            }

        return *this;
    }
#endif
};
