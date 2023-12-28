/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/CreateGlobalSecondaryIndexAction.h"

#endif

#include "Model/DynamoDBKeySchemaElement.h"
#include "Model/Projection.h"
#include "Model/ProvisionedThroughput.h"

#include "CreateGlobalSecondaryIndexAction.generated.h"

USTRUCT(BlueprintType)
struct FCreateGlobalSecondaryIndexAction {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index to be created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>The key schema for the global secondary index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBKeySchemaElement> keySchema;

    /**
    *  <p>Represents attributes that are copied (projected) from the table into an index. These are in addition to the primary key attributes and index key attributes, which are automatically projected.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProjection projection;

    /**
    *  <p>Represents the provisioned throughput settings for the specified global secondary index.</p> <p>For current minimum and maximum provisioned throughput values, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Limits.html">Limits</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughput provisionedThroughput;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::CreateGlobalSecondaryIndexAction toAWS() const {
        Aws::DynamoDB::Model::CreateGlobalSecondaryIndexAction awsCreateGlobalSecondaryIndexAction;

		if (!(this->indexName.IsEmpty())) {
            awsCreateGlobalSecondaryIndexAction.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        for (const FDynamoDBKeySchemaElement& elem : this->keySchema) {
            awsCreateGlobalSecondaryIndexAction.AddKeySchema(elem.toAWS());
        }

        if (!(this->projection.IsEmpty())) {
            awsCreateGlobalSecondaryIndexAction.SetProjection(this->projection.toAWS());
        }

        if (!(this->provisionedThroughput.IsEmpty())) {
            awsCreateGlobalSecondaryIndexAction.SetProvisionedThroughput(this->provisionedThroughput.toAWS());
        }

        return awsCreateGlobalSecondaryIndexAction;
    }

    bool IsEmpty() const {
        return this->indexName.IsEmpty() && this->keySchema.Num() == 0 && this->projection.IsEmpty() && this->provisionedThroughput.IsEmpty();
    }
#endif
};
