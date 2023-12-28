/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BatchStatementResponse.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/AWSDynamoDBBatchStatementError.h"

#include "AWSDynamoDBBatchStatementResponse.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBBatchStatementResponse {
GENERATED_BODY()

    /**
    *  <p> The error associated with a failed PartiQL batch statement. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAWSDynamoDBBatchStatementError error;

    /**
    *  <p> The table name associated with a failed PartiQL batch statement. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p> A DynamoDB item associated with a BatchStatementResponse </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> item;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBBatchStatementResponse &fromAWS(const Aws::DynamoDB::Model::BatchStatementResponse &awsBatchStatementResponse) {
        this->error.fromAWS(awsBatchStatementResponse.GetError());

        this->tableName = UTF8_TO_TCHAR(awsBatchStatementResponse.GetTableName().c_str());

        this->item.Empty();
        for (const auto& elem : awsBatchStatementResponse.GetItem()) {
            this->item.Add(UTF8_TO_TCHAR(elem.first.c_str()), FDynamoDBAttributeValue().fromAWS(elem.second));
        }

        return *this;
    }
#endif
};
