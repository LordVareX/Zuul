/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TransactWriteItemsRequest.h"

#endif

#include "Model/TransactWriteItem.h"
#include "Model/ReturnConsumedCapacity.h"
#include "Model/ReturnItemCollectionMetrics.h"

#include "TransactWriteItemsRequest.generated.h"

USTRUCT(BlueprintType)
struct FTransactWriteItemsRequest {
GENERATED_BODY()

    /**
    *  <p>An ordered array of up to 25 <code>TransactWriteItem</code> objects, each of which contains a <code>ConditionCheck</code>, <code>Put</code>, <code>Update</code>, or <code>Delete</code> object. These can operate on items in different tables, but the tables must reside in the same AWS account and Region, and no two of them can operate on the same item. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FTransactWriteItem> transactItems;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnConsumedCapacity returnConsumedCapacity = EAWSReturnConsumedCapacity::NOT_SET;

    /**
    *  <p>Determines whether item collection metrics are returned. If set to <code>SIZE</code>, the response includes statistics about item collections (if any), that were modified during the operation and are returned in the response. If set to <code>NONE</code> (the default), no statistics are returned. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnItemCollectionMetrics returnItemCollectionMetrics = EAWSReturnItemCollectionMetrics::NOT_SET;

    /**
    *  <p>Providing a <code>ClientRequestToken</code> makes the call to <code>TransactWriteItems</code> idempotent, meaning that multiple identical calls have the same effect as one single call.</p> <p>Although multiple identical calls using the same client request token produce the same result on the server (no side effects), the responses to the calls might not be the same. If the <code>ReturnConsumedCapacity&gt;</code> parameter is set, then the initial <code>TransactWriteItems</code> call returns the amount of write capacity units consumed in making the changes. Subsequent <code>TransactWriteItems</code> calls with the same client token return the number of read capacity units consumed in reading the item.</p> <p>A client request token is valid for 10 minutes after the first request that uses it is completed. After 10 minutes, any request with the same client token is treated as a new request. Do not resubmit the same request with the same client token for more than 10 minutes, or the result might not be idempotent.</p> <p>If you submit a request with the same client token but a change in other parameters within the 10-minute idempotency window, DynamoDB returns an <code>IdempotentParameterMismatch</code> exception.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString clientRequestToken;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::TransactWriteItemsRequest toAWS() const {
        Aws::DynamoDB::Model::TransactWriteItemsRequest awsTransactWriteItemsRequest;

        for (const FTransactWriteItem& elem : this->transactItems) {
            awsTransactWriteItemsRequest.AddTransactItems(elem.toAWS());
        }

        switch(this->returnConsumedCapacity) {
            case EAWSReturnConsumedCapacity::INDEXES:
                awsTransactWriteItemsRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::INDEXES);
                break;
            case EAWSReturnConsumedCapacity::TOTAL:
                awsTransactWriteItemsRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::TOTAL);
                break;
            case EAWSReturnConsumedCapacity::NONE:
                awsTransactWriteItemsRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::NONE);
                break;
            default:
                break;
            }

        switch(this->returnItemCollectionMetrics) {
            case EAWSReturnItemCollectionMetrics::SIZE:
                awsTransactWriteItemsRequest.SetReturnItemCollectionMetrics(Aws::DynamoDB::Model::ReturnItemCollectionMetrics::SIZE);
                break;
            case EAWSReturnItemCollectionMetrics::NONE:
                awsTransactWriteItemsRequest.SetReturnItemCollectionMetrics(Aws::DynamoDB::Model::ReturnItemCollectionMetrics::NONE);
                break;
            default:
                break;
            }

		if (!(this->clientRequestToken.IsEmpty())) {
            awsTransactWriteItemsRequest.SetClientRequestToken(TCHAR_TO_UTF8(*this->clientRequestToken));
        }

        return awsTransactWriteItemsRequest;
    }

    bool IsEmpty() const {
        return this->transactItems.Num() == 0 && this->returnConsumedCapacity == EAWSReturnConsumedCapacity::NOT_SET && this->returnItemCollectionMetrics == EAWSReturnItemCollectionMetrics::NOT_SET && this->clientRequestToken.IsEmpty();
    }
#endif
};
