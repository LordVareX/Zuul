/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/PutRequest.h"

#endif

#include "Model/DynamoDBAttributeValue.h"

#include "PutRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutRequest {
GENERATED_BODY()

    /**
    *  <p>A map of attribute name to attribute values, representing the primary key of an item to be processed by <code>PutItem</code>. All of the table's primary key attributes must be specified, and their data types must match those of the table's key schema. If any attributes are present in the item which are part of an index key schema for the table, their types must match the index key schema.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> item;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::PutRequest toAWS() const {
        Aws::DynamoDB::Model::PutRequest awsPutRequest;

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->item) {
            awsPutRequest.AddItem(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        return awsPutRequest;
    }

    bool IsEmpty() const {
        return this->item.Num() == 0;
    }

    FPutRequest &fromAWS(const Aws::DynamoDB::Model::PutRequest &awsPutRequest) {
        for (const auto& elem : awsPutRequest.GetItem()) {
            this->item.Add(elem.first.c_str(), FDynamoDBAttributeValue().fromAWS(elem.second));
        }

        return *this;
    }
#endif
};
