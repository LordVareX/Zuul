/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TransactGetItem.h"

#endif

#include "Model/DynamoDBGet.h"

#include "TransactGetItem.generated.h"

USTRUCT(BlueprintType)
struct FTransactGetItem {
GENERATED_BODY()

    /**
    *  <p>Contains the primary key that identifies the item to get, together with the name of the table that contains the item, and optionally the specific attributes of the item to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDynamoDBGet get;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::TransactGetItem toAWS() const {
        Aws::DynamoDB::Model::TransactGetItem awsTransactGetItem;

        if (!(this->get.IsEmpty())) {
            awsTransactGetItem.SetGet(this->get.toAWS());
        }

        return awsTransactGetItem;
    }

    bool IsEmpty() const {
        return this->get.IsEmpty();
    }
#endif
};
