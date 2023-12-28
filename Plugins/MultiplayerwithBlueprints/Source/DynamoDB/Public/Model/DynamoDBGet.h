/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/Get.h"

#endif

#include "Model/DynamoDBAttributeValue.h"

#include "DynamoDBGet.generated.h"

USTRUCT(BlueprintType)
struct FDynamoDBGet {
GENERATED_BODY()

    /**
    *  <p>A map of attribute names to <code>AttributeValue</code> objects that specifies the primary key of the item to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> key;

    /**
    *  <p>The name of the table from which to retrieve the specified item.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>A string that identifies one or more attributes of the specified item to retrieve from the table. The attributes in the expression must be separated by commas. If no attribute names are specified, then all attributes of the specified item are returned. If any of the requested attributes are not found, they do not appear in the result.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString projectionExpression;

    /**
    *  <p>One or more substitution tokens for attribute names in the ProjectionExpression parameter.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FString> expressionAttributeNames;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::Get toAWS() const {
        Aws::DynamoDB::Model::Get awsGet;

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->key) {
            awsGet.AddKey(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

		if (!(this->tableName.IsEmpty())) {
            awsGet.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

		if (!(this->projectionExpression.IsEmpty())) {
            awsGet.SetProjectionExpression(TCHAR_TO_UTF8(*this->projectionExpression));
        }

        for (const TPair<FString, FString>& elem : this->expressionAttributeNames) {
            awsGet.AddExpressionAttributeNames(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGet;
    }

    bool IsEmpty() const {
        return this->key.Num() == 0 && this->tableName.IsEmpty() && this->projectionExpression.IsEmpty() && this->expressionAttributeNames.Num() == 0;
    }
#endif
};
