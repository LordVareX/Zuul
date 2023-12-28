/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TableDescription.h"

#endif

#include "Model/AttributeDefinition.h"
#include "Model/DynamoDBKeySchemaElement.h"
#include "Model/TableStatus.h"
#include "Model/ProvisionedThroughputDescription.h"
#include "Model/BillingModeSummary.h"
#include "Model/LocalSecondaryIndexDescription.h"
#include "Model/GlobalSecondaryIndexDescription.h"
#include "Model/StreamSpecification.h"
#include "Model/ReplicaDescription.h"
#include "Model/RestoreSummary.h"
#include "Model/SSEDescription.h"
#include "Model/ArchivalSummary.h"
#include "Model/AWSDynamoDBTableClassSummary.h"

#include "TableDescription.generated.h"

USTRUCT(BlueprintType)
struct FTableDescription {
GENERATED_BODY()

    /**
    *  <p>An array of <code>AttributeDefinition</code> objects. Each of these objects describes one attribute in the table and index key schema.</p> <p>Each <code>AttributeDefinition</code> object in this array is composed of:</p> <ul> <li> <p> <code>AttributeName</code> - The name of the attribute.</p> </li> <li> <p> <code>AttributeType</code> - The data type for the attribute.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAttributeDefinition> attributeDefinitions;

    /**
    *  <p>The name of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>The primary key structure for the table. Each <code>KeySchemaElement</code> consists of:</p> <ul> <li> <p> <code>AttributeName</code> - The name of the attribute.</p> </li> <li> <p> <code>KeyType</code> - The role of the attribute:</p> <ul> <li> <p> <code>HASH</code> - partition key</p> </li> <li> <p> <code>RANGE</code> - sort key</p> </li> </ul> <note> <p>The partition key of an item is also known as its <i>hash attribute</i>. The term "hash attribute" derives from DynamoDB's usage of an internal hash function to evenly distribute data items across partitions, based on their partition key values.</p> <p>The sort key of an item is also known as its <i>range attribute</i>. The term "range attribute" derives from the way DynamoDB stores items with the same partition key physically close together, in sorted order by the sort key value.</p> </note> </li> </ul> <p>For more information about primary keys, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/DataModel.html#DataModelPrimaryKey">Primary Key</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBKeySchemaElement> keySchema;

    /**
    *  <p>The current state of the table:</p> <ul> <li> <p> <code>CREATING</code> - The table is being created.</p> </li> <li> <p> <code>UPDATING</code> - The table is being updated.</p> </li> <li> <p> <code>DELETING</code> - The table is being deleted.</p> </li> <li> <p> <code>ACTIVE</code> - The table is ready for use.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSTableStatus tableStatus = EAWSTableStatus::NOT_SET;

    /**
    *  <p>The date and time when the table was created, in <a href="http://www.epochconverter.com/">UNIX epoch time</a> format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime creationDateTime;

    /**
    *  <p>The provisioned throughput settings for the table, consisting of read and write capacity units, along with data about increases and decreases.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughputDescription provisionedThroughput;

    /**
    *  <p>The total size of the specified table, in bytes. DynamoDB updates this value approximately every six hours. Recent changes might not be reflected in this value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 tableSizeBytes = 0;

    /**
    *  <p>The number of items in the specified table. DynamoDB updates this value approximately every six hours. Recent changes might not be reflected in this value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 itemCount = 0;

    /**
    *  <p>The Amazon Resource Name (ARN) that uniquely identifies the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableArn;

    /**
    *  <p>Unique identifier for the table for which the backup was created. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableId;

    /**
    *  <p>Contains the details for the read/write capacity mode.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FBillingModeSummary billingModeSummary;

    /**
    *  <p>Represents one or more local secondary indexes on the table. Each index is scoped to a given partition key value. Tables with one or more local secondary indexes are subject to an item collection size limit, where the amount of data within a given item collection cannot exceed 10 GB. Each element is composed of:</p> <ul> <li> <p> <code>IndexName</code> - The name of the local secondary index.</p> </li> <li> <p> <code>KeySchema</code> - Specifies the complete index key schema. The attribute names in the key schema must be between 1 and 255 characters (inclusive). The key schema must begin with the same partition key as the table.</p> </li> <li> <p> <code>Projection</code> - Specifies attributes that are copied (projected) from the table into the index. These are in addition to the primary key attributes and index key attributes, which are automatically projected. Each attribute specification is composed of:</p> <ul> <li> <p> <code>ProjectionType</code> - One of the following:</p> <ul> <li> <p> <code>KEYS_ONLY</code> - Only the index and primary keys are projected into the index.</p> </li> <li> <p> <code>INCLUDE</code> - Only the specified table attributes are projected into the index. The list of projected attributes are in <code>NonKeyAttributes</code>.</p> </li> <li> <p> <code>ALL</code> - All of the table attributes are projected into the index.</p> </li> </ul> </li> <li> <p> <code>NonKeyAttributes</code> - A list of one or more non-key attribute names that are projected into the secondary index. The total count of attributes provided in <code>NonKeyAttributes</code>, summed across all of the secondary indexes, must not exceed 20. If you project the same attribute into two different indexes, this counts as two distinct attributes when determining the total.</p> </li> </ul> </li> <li> <p> <code>IndexSizeBytes</code> - Represents the total size of the index, in bytes. DynamoDB updates this value approximately every six hours. Recent changes might not be reflected in this value.</p> </li> <li> <p> <code>ItemCount</code> - Represents the number of items in the index. DynamoDB updates this value approximately every six hours. Recent changes might not be reflected in this value.</p> </li> </ul> <p>If the table is in the <code>DELETING</code> state, no information about indexes will be returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FLocalSecondaryIndexDescription> localSecondaryIndexes;

    /**
    *  <p>The global secondary indexes, if any, on the table. Each index is scoped to a given partition key value. Each element is composed of:</p> <ul> <li> <p> <code>Backfilling</code> - If true, then the index is currently in the backfilling phase. Backfilling occurs only when a new global secondary index is added to the table; it is the process by which DynamoDB populates the new index with data from the table. (This attribute does not appear for indexes that were created during a <code>CreateTable</code> operation.)</p> </li> <li> <p> <code>IndexName</code> - The name of the global secondary index.</p> </li> <li> <p> <code>IndexSizeBytes</code> - The total size of the global secondary index, in bytes. DynamoDB updates this value approximately every six hours. Recent changes might not be reflected in this value. </p> </li> <li> <p> <code>IndexStatus</code> - The current status of the global secondary index:</p> <ul> <li> <p> <code>CREATING</code> - The index is being created.</p> </li> <li> <p> <code>UPDATING</code> - The index is being updated.</p> </li> <li> <p> <code>DELETING</code> - The index is being deleted.</p> </li> <li> <p> <code>ACTIVE</code> - The index is ready for use.</p> </li> </ul> </li> <li> <p> <code>ItemCount</code> - The number of items in the global secondary index. DynamoDB updates this value approximately every six hours. Recent changes might not be reflected in this value. </p> </li> <li> <p> <code>KeySchema</code> - Specifies the complete index key schema. The attribute names in the key schema must be between 1 and 255 characters (inclusive). The key schema must begin with the same partition key as the table.</p> </li> <li> <p> <code>Projection</code> - Specifies attributes that are copied (projected) from the table into the index. These are in addition to the primary key attributes and index key attributes, which are automatically projected. Each attribute specification is composed of:</p> <ul> <li> <p> <code>ProjectionType</code> - One of the following:</p> <ul> <li> <p> <code>KEYS_ONLY</code> - Only the index and primary keys are projected into the index.</p> </li> <li> <p> <code>INCLUDE</code> - Only the specified table attributes are projected into the index. The list of projected attributes are in <code>NonKeyAttributes</code>.</p> </li> <li> <p> <code>ALL</code> - All of the table attributes are projected into the index.</p> </li> </ul> </li> <li> <p> <code>NonKeyAttributes</code> - A list of one or more non-key attribute names that are projected into the secondary index. The total count of attributes provided in <code>NonKeyAttributes</code>, summed across all of the secondary indexes, must not exceed 20. If you project the same attribute into two different indexes, this counts as two distinct attributes when determining the total.</p> </li> </ul> </li> <li> <p> <code>ProvisionedThroughput</code> - The provisioned throughput settings for the global secondary index, consisting of read and write capacity units, along with data about increases and decreases. </p> </li> </ul> <p>If the table is in the <code>DELETING</code> state, no information about indexes will be returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FGlobalSecondaryIndexDescription> globalSecondaryIndexes;

    /**
    *  <p>The current DynamoDB Streams configuration for the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FStreamSpecification streamSpecification;

    /**
    *  <p>A timestamp, in ISO 8601 format, for this stream.</p> <p>Note that <code>LatestStreamLabel</code> is not a unique identifier for the stream, because it is possible that a stream from another table might have the same timestamp. However, the combination of the following three elements is guaranteed to be unique:</p> <ul> <li> <p>the AWS customer ID.</p> </li> <li> <p>the table name.</p> </li> <li> <p>the <code>StreamLabel</code>.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString latestStreamLabel;

    /**
    *  <p>The Amazon Resource Name (ARN) that uniquely identifies the latest stream for this table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString latestStreamArn;

    /**
    *  <p>Represents the version of <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/GlobalTables.html">global tables</a> in use, if the table is replicated across AWS Regions.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString globalTableVersion;

    /**
    *  <p>Represents replicas of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaDescription> replicas;

    /**
    *  <p>Contains details for the restore.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FRestoreSummary restoreSummary;

    /**
    *  <p>The description of the server-side encryption status on the specified table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FSSEDescription SSEDescription;

    /**
    *  <p>Contains information about the table archive.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FArchivalSummary archivalSummary;

    /**
    *  <p>Contains details of the table class.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBTableClassSummary tableClassSummary;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FTableDescription &fromAWS(const Aws::DynamoDB::Model::TableDescription &awsTableDescription) {
        this->attributeDefinitions.Empty();
        for (const Aws::DynamoDB::Model::AttributeDefinition& elem : awsTableDescription.GetAttributeDefinitions()) {
            this->attributeDefinitions.Add(FAttributeDefinition().fromAWS(elem));
        }

        this->tableName = UTF8_TO_TCHAR(awsTableDescription.GetTableName().c_str());

        this->keySchema.Empty();
        for (const Aws::DynamoDB::Model::KeySchemaElement& elem : awsTableDescription.GetKeySchema()) {
            this->keySchema.Add(FDynamoDBKeySchemaElement().fromAWS(elem));
        }

        switch(awsTableDescription.GetTableStatus()) {
            case Aws::DynamoDB::Model::TableStatus::NOT_SET:
                this->tableStatus = EAWSTableStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::TableStatus::CREATING:
                this->tableStatus = EAWSTableStatus::CREATING;
                break;
            case Aws::DynamoDB::Model::TableStatus::UPDATING:
                this->tableStatus = EAWSTableStatus::UPDATING;
                break;
            case Aws::DynamoDB::Model::TableStatus::DELETING:
                this->tableStatus = EAWSTableStatus::DELETING;
                break;
            case Aws::DynamoDB::Model::TableStatus::ACTIVE:
                this->tableStatus = EAWSTableStatus::ACTIVE;
                break;
            case Aws::DynamoDB::Model::TableStatus::INACCESSIBLE_ENCRYPTION_CREDENTIALS:
                this->tableStatus = EAWSTableStatus::INACCESSIBLE_ENCRYPTION_CREDENTIALS;
                break;
            case Aws::DynamoDB::Model::TableStatus::ARCHIVING:
                this->tableStatus = EAWSTableStatus::ARCHIVING;
                break;
            case Aws::DynamoDB::Model::TableStatus::ARCHIVED:
                this->tableStatus = EAWSTableStatus::ARCHIVED;
                break;
            default:
                this->tableStatus = EAWSTableStatus::NOT_SET;
                break;
        }

        this->creationDateTime = FDateTime(1970, 1, 1) + FTimespan(awsTableDescription.GetCreationDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->provisionedThroughput.fromAWS(awsTableDescription.GetProvisionedThroughput());

        this->tableSizeBytes = (int64)awsTableDescription.GetTableSizeBytes();

        this->itemCount = (int64)awsTableDescription.GetItemCount();

        this->tableArn = UTF8_TO_TCHAR(awsTableDescription.GetTableArn().c_str());

        this->tableId = UTF8_TO_TCHAR(awsTableDescription.GetTableId().c_str());

        this->billingModeSummary.fromAWS(awsTableDescription.GetBillingModeSummary());
        
        this->localSecondaryIndexes.Empty();
        for (const Aws::DynamoDB::Model::LocalSecondaryIndexDescription& elem : awsTableDescription.GetLocalSecondaryIndexes()) {
            this->localSecondaryIndexes.Add(FLocalSecondaryIndexDescription().fromAWS(elem));
        }

        this->globalSecondaryIndexes.Empty();
        for (const Aws::DynamoDB::Model::GlobalSecondaryIndexDescription& elem : awsTableDescription.GetGlobalSecondaryIndexes()) {
            this->globalSecondaryIndexes.Add(FGlobalSecondaryIndexDescription().fromAWS(elem));
        }

        this->streamSpecification.fromAWS(awsTableDescription.GetStreamSpecification());

        this->latestStreamLabel = UTF8_TO_TCHAR(awsTableDescription.GetLatestStreamLabel().c_str());

        this->latestStreamArn = UTF8_TO_TCHAR(awsTableDescription.GetLatestStreamArn().c_str());

        this->globalTableVersion = UTF8_TO_TCHAR(awsTableDescription.GetGlobalTableVersion().c_str());

        this->replicas.Empty();
        for (const Aws::DynamoDB::Model::ReplicaDescription& elem : awsTableDescription.GetReplicas()) {
            this->replicas.Add(FReplicaDescription().fromAWS(elem));
        }

        this->restoreSummary.fromAWS(awsTableDescription.GetRestoreSummary());

        this->SSEDescription.fromAWS(awsTableDescription.GetSSEDescription());

        this->archivalSummary.fromAWS(awsTableDescription.GetArchivalSummary());

        this->tableClassSummary.fromAWS(awsTableDescription.GetTableClassSummary());

        return *this;
    }
#endif
};
