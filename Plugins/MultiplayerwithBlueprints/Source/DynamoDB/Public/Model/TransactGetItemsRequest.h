/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TransactGetItemsRequest.h"

#endif

#include "Model/TransactGetItem.h"
#include "Model/ReturnConsumedCapacity.h"

#include "TransactGetItemsRequest.generated.h"

USTRUCT(BlueprintType)
struct FTransactGetItemsRequest {
GENERATED_BODY()

    /**
    *  <p>An ordered array of up to 25 <code>TransactGetItem</code> objects, each of which contains a <code>Get</code> structure.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FTransactGetItem> transactItems;

    /**
    *  <p>A value of <code>TOTAL</code> causes consumed capacity information to be returned, and a value of <code>NONE</code> prevents that information from being returned. No other value is valid.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnConsumedCapacity returnConsumedCapacity = EAWSReturnConsumedCapacity::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::TransactGetItemsRequest toAWS() const {
        Aws::DynamoDB::Model::TransactGetItemsRequest awsTransactGetItemsRequest;

        for (const FTransactGetItem& elem : this->transactItems) {
            awsTransactGetItemsRequest.AddTransactItems(elem.toAWS());
        }

        switch(this->returnConsumedCapacity) {
            case EAWSReturnConsumedCapacity::INDEXES:
                awsTransactGetItemsRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::INDEXES);
                break;
            case EAWSReturnConsumedCapacity::TOTAL:
                awsTransactGetItemsRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::TOTAL);
                break;
            case EAWSReturnConsumedCapacity::NONE:
                awsTransactGetItemsRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::NONE);
                break;
            default:
                break;
        }

        return awsTransactGetItemsRequest;
    }

    bool IsEmpty() const {
        return this->transactItems.Num() == 0 && this->returnConsumedCapacity == EAWSReturnConsumedCapacity::NOT_SET;
    }
#endif
};
