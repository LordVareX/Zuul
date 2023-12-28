/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TransactWriteItem.h"

#endif

#include "Model/ConditionCheck.h"
#include "Model/Put.h"
#include "Model/DynamoDBDelete.h"
#include "Model/DynamoDBUpdate.h"

#include "TransactWriteItem.generated.h"

USTRUCT(BlueprintType)
struct FTransactWriteItem {
GENERATED_BODY()

    /**
    *  <p>A request to perform a check item operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FConditionCheck conditionCheck;

    /**
    *  <p>A request to perform a <code>PutItem</code> operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FPut putItem;

    /**
    *  <p>A request to perform a <code>DeleteItem</code> operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDynamoDBDelete deleteItem;

    /**
    *  <p>A request to perform an <code>UpdateItem</code> operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDynamoDBUpdate updateItem;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::TransactWriteItem toAWS() const {
        Aws::DynamoDB::Model::TransactWriteItem awsTransactWriteItem;

        if (!(this->conditionCheck.IsEmpty())) {
            awsTransactWriteItem.SetConditionCheck(this->conditionCheck.toAWS());
        }

        if (!(this->putItem.IsEmpty())) {
            awsTransactWriteItem.SetPut(this->putItem.toAWS());
        }

        if (!(this->deleteItem.IsEmpty())) {
            awsTransactWriteItem.SetDelete(this->deleteItem.toAWS());
        }

        if (!(this->updateItem.IsEmpty())) {
            awsTransactWriteItem.SetUpdate(this->updateItem.toAWS());
        }

        return awsTransactWriteItem;
    }

    bool IsEmpty() const {
        return this->conditionCheck.IsEmpty() && this->putItem.IsEmpty() && this->deleteItem.IsEmpty() && this->updateItem.IsEmpty();
    }
#endif
};
