/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BatchStatementRequest.h"

#endif

#include "Model/DynamoDBAttributeValue.h"

#include "AWSDynamoDBBatchStatementRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBBatchStatementRequest {
GENERATED_BODY()
    /**
    *  <p> A valid PartiQL statement. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString statement;

    /**
    *  <p> The parameters associated with a PartiQL statement in the batch request. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBAttributeValue> parameters;

    /**
    *  <p> The read consistency of the PartiQL batch request. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool consistentRead = false;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::BatchStatementRequest toAWS() const {
        Aws::DynamoDB::Model::BatchStatementRequest awsBatchStatementRequest;

        if (!(this->statement.IsEmpty())) {
            awsBatchStatementRequest.SetStatement(TCHAR_TO_UTF8(*this->statement));
        }

        for (const FDynamoDBAttributeValue& elem : this->parameters) {
            awsBatchStatementRequest.AddParameters(elem.toAWS());
        }

        if (!(false)) {
            awsBatchStatementRequest.SetConsistentRead(this->consistentRead);
        }
        return awsBatchStatementRequest;
    }

    bool IsEmpty() const {
        return this->statement.IsEmpty() && this->parameters.Num() == 0 && false;
    }
#endif
};
