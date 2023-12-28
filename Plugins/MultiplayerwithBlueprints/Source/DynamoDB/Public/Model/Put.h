/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/Put.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/ReturnValuesOnConditionCheckFailure.h"

#include "Put.generated.h"

USTRUCT(BlueprintType)
struct FPut {
GENERATED_BODY()

    /**
    *  <p>A map of attribute name to attribute values, representing the primary key of the item to be written by <code>PutItem</code>. All of the table's primary key attributes must be specified, and their data types must match those of the table's key schema. If any attributes are present in the item that are part of an index key schema for the table, their types must match the index key schema. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> item;

    /**
    *  <p>Name of the table in which to write the item.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>A condition that must be satisfied in order for a conditional update to succeed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString conditionExpression;

    /**
    *  <p>One or more substitution tokens for attribute names in an expression.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FString> expressionAttributeNames;

    /**
    *  <p>One or more values that can be substituted in an expression.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> expressionAttributeValues;

    /**
    *  <p>Use <code>ReturnValuesOnConditionCheckFailure</code> to get the item attributes if the <code>Put</code> condition fails. For <code>ReturnValuesOnConditionCheckFailure</code>, the valid values are: NONE and ALL_OLD.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnValuesOnConditionCheckFailure returnValuesOnConditionCheckFailure = EAWSReturnValuesOnConditionCheckFailure::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::Put toAWS() const {
        Aws::DynamoDB::Model::Put awsPut;

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->item) {
            awsPut.AddItem(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

		if (!(this->tableName.IsEmpty())) {
            awsPut.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

		if (!(this->conditionExpression.IsEmpty())) {
            awsPut.SetConditionExpression(TCHAR_TO_UTF8(*this->conditionExpression));
        }

        for (const TPair<FString, FString>& elem : this->expressionAttributeNames) {
            awsPut.AddExpressionAttributeNames(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->expressionAttributeValues) {
            awsPut.AddExpressionAttributeValues(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        switch(this->returnValuesOnConditionCheckFailure) {
            case EAWSReturnValuesOnConditionCheckFailure::ALL_OLD:
                awsPut.SetReturnValuesOnConditionCheckFailure(Aws::DynamoDB::Model::ReturnValuesOnConditionCheckFailure::ALL_OLD);
                break;
            case EAWSReturnValuesOnConditionCheckFailure::NONE:
                awsPut.SetReturnValuesOnConditionCheckFailure(Aws::DynamoDB::Model::ReturnValuesOnConditionCheckFailure::NONE);
                break;
            default:
                break;
            }

        return awsPut;
    }

    bool IsEmpty() const {
        return this->item.Num() == 0 && this->tableName.IsEmpty() && this->conditionExpression.IsEmpty() && this->expressionAttributeNames.Num() == 0 && this->expressionAttributeValues.Num() == 0 && this->returnValuesOnConditionCheckFailure == EAWSReturnValuesOnConditionCheckFailure::NOT_SET;
    }
#endif
};
