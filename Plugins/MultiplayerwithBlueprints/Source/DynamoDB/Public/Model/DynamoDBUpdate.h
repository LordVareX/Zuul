/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/Update.h"

#endif

#include "Model/ReturnValuesOnConditionCheckFailure.h"

#include "DynamoDBUpdate.generated.h"

USTRUCT(BlueprintType)
struct FDynamoDBUpdate {
GENERATED_BODY()

    /**
    *  <p>The primary key of the item to be updated. Each element consists of an attribute name and a value for that attribute.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> key;

    /**
    *  <p>An expression that defines one or more attributes to be updated, the action to be performed on them, and new value(s) for them.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString updateExpression;

    /**
    *  <p>Name of the table for the <code>UpdateItem</code> request.</p>
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
    *  <p>Use <code>ReturnValuesOnConditionCheckFailure</code> to get the item attributes if the <code>Update</code> condition fails. For <code>ReturnValuesOnConditionCheckFailure</code>, the valid values are: NONE, ALL_OLD, UPDATED_OLD, ALL_NEW, UPDATED_NEW.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnValuesOnConditionCheckFailure returnValuesOnConditionCheckFailure = EAWSReturnValuesOnConditionCheckFailure::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::Update toAWS() const {
        Aws::DynamoDB::Model::Update awsUpdate;

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->key) {
            awsUpdate.AddKey(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

		if (!(this->updateExpression.IsEmpty())) {
            awsUpdate.SetUpdateExpression(TCHAR_TO_UTF8(*this->updateExpression));
        }

		if (!(this->tableName.IsEmpty())) {
            awsUpdate.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

		if (!(this->conditionExpression.IsEmpty())) {
            awsUpdate.SetConditionExpression(TCHAR_TO_UTF8(*this->conditionExpression));
        }

        for (const TPair<FString, FString>& elem : this->expressionAttributeNames) {
            awsUpdate.AddExpressionAttributeNames(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->expressionAttributeValues) {
            awsUpdate.AddExpressionAttributeValues(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        switch(this->returnValuesOnConditionCheckFailure) {
            case EAWSReturnValuesOnConditionCheckFailure::ALL_OLD:
                awsUpdate.SetReturnValuesOnConditionCheckFailure(Aws::DynamoDB::Model::ReturnValuesOnConditionCheckFailure::ALL_OLD);
                break;
            case EAWSReturnValuesOnConditionCheckFailure::NONE:
                awsUpdate.SetReturnValuesOnConditionCheckFailure(Aws::DynamoDB::Model::ReturnValuesOnConditionCheckFailure::NONE);
                break;
            default:
                break;
            }

        return awsUpdate;
    }

    bool IsEmpty() const {
        return this->key.Num() == 0 && this->updateExpression.IsEmpty() && this->tableName.IsEmpty() && this->conditionExpression.IsEmpty() && this->expressionAttributeNames.Num() == 0 && this->expressionAttributeValues.Num() == 0 && this->returnValuesOnConditionCheckFailure == EAWSReturnValuesOnConditionCheckFailure::NOT_SET;
    }
#endif
};
