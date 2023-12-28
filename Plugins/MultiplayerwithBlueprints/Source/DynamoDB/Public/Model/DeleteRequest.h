/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DeleteRequest.h"

#endif

#include "Model/DynamoDBAttributeValue.h"

#include "DeleteRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteRequest {
GENERATED_BODY()

    /**
    *  <p>A map of attribute name to attribute values, representing the primary key of the item to delete. All of the table's primary key attributes must be specified, and their data types must match those of the table's key schema.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> key;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DeleteRequest toAWS() const {
        Aws::DynamoDB::Model::DeleteRequest awsDeleteRequest;

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->key) {
            awsDeleteRequest.AddKey(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        return awsDeleteRequest;
    }

    bool IsEmpty() const {
        return this->key.Num() == 0;
    }

    FDeleteRequest &fromAWS(const Aws::DynamoDB::Model::DeleteRequest &awsDeleteRequest) {
        this->key.Empty();
        for (const auto& elem : awsDeleteRequest.GetKey()) {
            this->key.Add(elem.first.c_str(), FDynamoDBAttributeValue().fromAWS(elem.second));
        }

        return *this;
    }
#endif
};
