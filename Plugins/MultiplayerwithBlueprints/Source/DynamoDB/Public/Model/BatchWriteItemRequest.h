/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BatchWriteItemRequest.h"

#endif

#include "DynamoDBGlobals.h"
#include "Model/WriteRequest.h"
#include "Model/ReturnConsumedCapacity.h"
#include "Model/ReturnItemCollectionMetrics.h"

#include "BatchWriteItemRequest.generated.h"

USTRUCT(BlueprintType)
struct FBatchWriteItemRequest {
GENERATED_BODY()

    /**
    *  <p>A map of one or more table names and, for each table, a list of operations to be performed (<code>DeleteRequest</code> or <code>PutRequest</code>). Each element in the map consists of the following:</p> <ul> <li> <p> <code>DeleteRequest</code> - Perform a <code>DeleteItem</code> operation on the specified item. The item to be deleted is identified by a <code>Key</code> subelement:</p> <ul> <li> <p> <code>Key</code> - A map of primary key attribute values that uniquely identify the item. Each entry in this map consists of an attribute name and an attribute value. For each primary key, you must provide <i>all</i> of the key attributes. For example, with a simple primary key, you only need to provide a value for the partition key. For a composite primary key, you must provide values for <i>both</i> the partition key and the sort key.</p> </li> </ul> </li> <li> <p> <code>PutRequest</code> - Perform a <code>PutItem</code> operation on the specified item. The item to be put is identified by an <code>Item</code> subelement:</p> <ul> <li> <p> <code>Item</code> - A map of attributes and their values. Each entry in this map consists of an attribute name and an attribute value. Attribute values must not be null; string and binary type attributes must have lengths greater than zero; and set type attributes must not be empty. Requests that contain empty values are rejected with a <code>ValidationException</code> exception.</p> <p>If you specify any attributes that are part of an index key, then the data types for those attributes must match those of the schema in the table's attribute definition.</p> </li> </ul> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString requestItems;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnConsumedCapacity returnConsumedCapacity = EAWSReturnConsumedCapacity::NOT_SET;

    /**
    *  <p>Determines whether item collection metrics are returned. If set to <code>SIZE</code>, the response includes statistics about item collections, if any, that were modified during the operation are returned in the response. If set to <code>NONE</code> (the default), no statistics are returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnItemCollectionMetrics returnItemCollectionMetrics = EAWSReturnItemCollectionMetrics::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::BatchWriteItemRequest toAWS() const {
        Aws::DynamoDB::Model::BatchWriteItemRequest awsBatchWriteItemRequest;

        Aws::Utils::Json::JsonValue json(TCHAR_TO_UTF8(*this->requestItems));
        if (json.WasParseSuccessful()) {
            Aws::Utils::Json::JsonView view = json.View();
            Aws::Map<Aws::String, Aws::Utils::Json::JsonView> requestItemsJsonMap = view.GetAllObjects();
            for(const auto& requestItemsMapItem : requestItemsJsonMap) {
                Aws::Utils::Array<Aws::Utils::Json::JsonView> requestItemJsonArray = requestItemsMapItem.second.AsArray();
                Aws::Vector<Aws::DynamoDB::Model::WriteRequest> requestItemArray(requestItemJsonArray.GetLength());
                for (int i = 0; i < requestItemJsonArray.GetLength(); i++) {
                    const Aws::Utils::Json::JsonView& requestItem = requestItemJsonArray[i];
                    requestItemArray.push_back(Aws::DynamoDB::Model::WriteRequest(requestItem));
                }
                awsBatchWriteItemRequest.AddRequestItems(requestItemsMapItem.first, requestItemArray);
            }
        } else {
            LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("json parse error. error message is: %s"), json.GetErrorMessage().c_str()));
        }

        switch(this->returnConsumedCapacity) {
            case EAWSReturnConsumedCapacity::INDEXES:
                awsBatchWriteItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::INDEXES);
                break;
            case EAWSReturnConsumedCapacity::TOTAL:
                awsBatchWriteItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::TOTAL);
                break;
            case EAWSReturnConsumedCapacity::NONE:
                awsBatchWriteItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::NONE);
                break;
            default:
                break;
            }

        switch(this->returnItemCollectionMetrics) {
            case EAWSReturnItemCollectionMetrics::SIZE:
                awsBatchWriteItemRequest.SetReturnItemCollectionMetrics(Aws::DynamoDB::Model::ReturnItemCollectionMetrics::SIZE);
                break;
            case EAWSReturnItemCollectionMetrics::NONE:
                awsBatchWriteItemRequest.SetReturnItemCollectionMetrics(Aws::DynamoDB::Model::ReturnItemCollectionMetrics::NONE);
                break;
            default:
                break;
            }

        return awsBatchWriteItemRequest;
    }

    bool IsEmpty() const {
        Aws::Utils::Json::JsonValue json(TCHAR_TO_UTF8(*this->requestItems));
        return !json.WasParseSuccessful() && this->returnConsumedCapacity == EAWSReturnConsumedCapacity::NOT_SET && EAWSReturnItemCollectionMetrics::NOT_SET == EAWSReturnItemCollectionMetrics::NOT_SET;
    }
#endif
};
