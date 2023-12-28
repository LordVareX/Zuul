/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateTableRequest.h"

#endif

#include "Model/AttributeDefinition.h"
#include "Model/BillingMode.h"
#include "Model/ProvisionedThroughput.h"
#include "Model/GlobalSecondaryIndexUpdate.h"
#include "Model/StreamSpecification.h"
#include "Model/SSESpecification.h"
#include "Model/ReplicationGroupUpdate.h"
#include "Model/AWSDynamoDBTableClass.h"

#include "UpdateTableRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateTableRequest {
GENERATED_BODY()

    /**
    *  <p>An array of attributes that describe the key schema for the table and indexes. If you are adding a new global secondary index to the table, <code>AttributeDefinitions</code> must include the key element(s) of the new index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAttributeDefinition> attributeDefinitions;

    /**
    *  <p>The name of the table to be updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>Controls how you are charged for read and write throughput and how you manage capacity. When switching from pay-per-request to provisioned capacity, initial provisioned capacity values must be set. The initial provisioned capacity values are estimated based on the consumed read and write capacity of your table and global secondary indexes over the past 30 minutes.</p> <ul> <li> <p> <code>PROVISIONED</code> - Sets the billing mode to <code>PROVISIONED</code>. We recommend using <code>PROVISIONED</code> for predictable workloads.</p> </li> <li> <p> <code>PAY_PER_REQUEST</code> - Sets the billing mode to <code>PAY_PER_REQUEST</code>. We recommend using <code>PAY_PER_REQUEST</code> for unpredictable workloads. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBillingMode billingMode = EAWSBillingMode::NOT_SET;

    /**
    *  <p>The new provisioned throughput settings for the specified table or index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughput provisionedThroughput;

    /**
    *  <p>An array of one or more global secondary indexes for the table. For each index in the array, you can request one action:</p> <ul> <li> <p> <code>Create</code> - add a new global secondary index to the table.</p> </li> <li> <p> <code>Update</code> - modify the provisioned throughput settings of an existing global secondary index.</p> </li> <li> <p> <code>Delete</code> - remove a global secondary index from the table.</p> </li> </ul> <p>For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/GSI.OnlineOps.html">Managing Global Secondary Indexes</a> in the <i>Amazon DynamoDB Developer Guide</i>. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FGlobalSecondaryIndexUpdate> globalSecondaryIndexUpdates;

    /**
    *  <p>Represents the DynamoDB Streams configuration for the table.</p> <note> <p>You receive a <code>ResourceInUseException</code> if you try to enable a stream on a table that already has a stream, or if you try to disable a stream on a table that doesn't have a stream.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FStreamSpecification streamSpecification;

    /**
    *  <p>The new server-side encryption settings for the specified table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FSSESpecification sSESpecification;

    /**
    *  <p>A list of replica update actions (create, delete, or update) for the table.</p> <note> <p>This property only applies to <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/globaltables.V2.html">Version 2019.11.21</a> of global tables.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicationGroupUpdate> replicaUpdates;

    /**
    *  <p>The table class of the table to be updated. Valid values are <code>STANDARD</code> and <code>STANDARD_INFREQUENT_ACCESS</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBTableClass tableClass = EAWSDynamoDBTableClass::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::UpdateTableRequest toAWS() const {
        Aws::DynamoDB::Model::UpdateTableRequest awsUpdateTableRequest;

        for (const FAttributeDefinition& elem : this->attributeDefinitions) {
            awsUpdateTableRequest.AddAttributeDefinitions(elem.toAWS());
        }

		if (!(this->tableName.IsEmpty())) {
            awsUpdateTableRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        switch(this->billingMode) {
            case EAWSBillingMode::PROVISIONED:
                awsUpdateTableRequest.SetBillingMode(Aws::DynamoDB::Model::BillingMode::PROVISIONED);
                break;
            case EAWSBillingMode::PAY_PER_REQUEST:
                awsUpdateTableRequest.SetBillingMode(Aws::DynamoDB::Model::BillingMode::PAY_PER_REQUEST);
                break;
            default:
                break;
		}

        if (!(this->provisionedThroughput.IsEmpty())) {
            awsUpdateTableRequest.SetProvisionedThroughput(this->provisionedThroughput.toAWS());
        }

        for (const FGlobalSecondaryIndexUpdate& elem : this->globalSecondaryIndexUpdates) {
            awsUpdateTableRequest.AddGlobalSecondaryIndexUpdates(elem.toAWS());
        }

        if (!(this->streamSpecification.IsEmpty())) {
            awsUpdateTableRequest.SetStreamSpecification(this->streamSpecification.toAWS());
        }

        if (!(this->sSESpecification.IsEmpty())) {
            awsUpdateTableRequest.SetSSESpecification(this->sSESpecification.toAWS());
        }

        for (const FReplicationGroupUpdate& elem : this->replicaUpdates) {
            awsUpdateTableRequest.AddReplicaUpdates(elem.toAWS());
        }

        switch(this->tableClass) {
            case EAWSDynamoDBTableClass::STANDARD:
                awsUpdateTableRequest.SetTableClass(Aws::DynamoDB::Model::TableClass::STANDARD);
                break;
            case EAWSDynamoDBTableClass::STANDARD_INFREQUENT_ACCESS:
                awsUpdateTableRequest.SetTableClass(Aws::DynamoDB::Model::TableClass::STANDARD_INFREQUENT_ACCESS);
                break;
            default:
                break;
        }

        return awsUpdateTableRequest;
    }

    bool IsEmpty() const {
        return this->attributeDefinitions.Num() == 0 && this->tableName.IsEmpty() && this->billingMode == EAWSBillingMode::NOT_SET && this->provisionedThroughput.IsEmpty() && this->globalSecondaryIndexUpdates.Num() == 0 && this->streamSpecification.IsEmpty() && this->sSESpecification.IsEmpty() && this->replicaUpdates.Num() == 0 && tableClass == EAWSDynamoDBTableClass::NOT_SET;
    }
#endif
};
