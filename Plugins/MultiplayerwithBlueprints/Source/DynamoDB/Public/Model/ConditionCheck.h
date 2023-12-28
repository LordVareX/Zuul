/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ConditionCheck.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/ReturnValuesOnConditionCheckFailure.h"

#include "ConditionCheck.generated.h"

USTRUCT(BlueprintType)
struct FConditionCheck {
GENERATED_BODY()

    /**
    *  <p>The primary key of the item to be checked. Each element consists of an attribute name and a value for that attribute.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> key;

    /**
    *  <p>Name of the table for the check item request.</p>
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
    *  <p>Use <code>ReturnValuesOnConditionCheckFailure</code> to get the item attributes if the <code>ConditionCheck</code> condition fails. For <code>ReturnValuesOnConditionCheckFailure</code>, the valid values are: NONE and ALL_OLD.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnValuesOnConditionCheckFailure returnValuesOnConditionCheckFailure = EAWSReturnValuesOnConditionCheckFailure::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ConditionCheck toAWS() const {
        Aws::DynamoDB::Model::ConditionCheck awsConditionCheck;

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->key) {
            awsConditionCheck.AddKey(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

		if (!(this->tableName.IsEmpty())) {
            awsConditionCheck.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

		if (!(this->conditionExpression.IsEmpty())) {
            awsConditionCheck.SetConditionExpression(TCHAR_TO_UTF8(*this->conditionExpression));
        }

        for (const TPair<FString, FString>& elem : this->expressionAttributeNames) {
            awsConditionCheck.AddExpressionAttributeNames(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->expressionAttributeValues) {
            awsConditionCheck.AddExpressionAttributeValues(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        switch(this->returnValuesOnConditionCheckFailure) {
            case EAWSReturnValuesOnConditionCheckFailure::ALL_OLD:
                awsConditionCheck.SetReturnValuesOnConditionCheckFailure(Aws::DynamoDB::Model::ReturnValuesOnConditionCheckFailure::ALL_OLD);
                break;
            case EAWSReturnValuesOnConditionCheckFailure::NONE:
                awsConditionCheck.SetReturnValuesOnConditionCheckFailure(Aws::DynamoDB::Model::ReturnValuesOnConditionCheckFailure::NONE);
                break;
            default:
                break;
            }

        return awsConditionCheck;
    }

    bool IsEmpty() const {
        return this->key.Num() == 0 && this->tableName.IsEmpty() && this->conditionExpression.IsEmpty() && this->expressionAttributeNames.Num() == 0 && this->expressionAttributeValues.Num() == 0 && this->returnValuesOnConditionCheckFailure == EAWSReturnValuesOnConditionCheckFailure::NOT_SET;
    }
#endif
};
