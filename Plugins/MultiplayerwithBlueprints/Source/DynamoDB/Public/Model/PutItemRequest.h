/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/PutItemRequest.h"

#endif

#include "Model/DynamoDBAttributeValue.h"
#include "Model/ExpectedAttributeValue.h"
#include "Model/ReturnValue.h"
#include "Model/ReturnConsumedCapacity.h"
#include "Model/ReturnItemCollectionMetrics.h"
#include "Model/ConditionalOperator.h"

#include "PutItemRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutItemRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table to contain the item.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>A map of attribute name/value pairs, one for each attribute. Only the primary key attributes are required; you can optionally provide other attribute name-value pairs for the item.</p> <p>You must provide all of the attributes for the primary key. For example, with a simple primary key, you only need to provide a value for the partition key. For a composite primary key, you must provide both values for both the partition key and the sort key.</p> <p>If you specify any attributes that are part of an index key, then the data types for those attributes must match those of the schema in the table's attribute definition.</p> <p>For more information about primary keys, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/HowItWorks.CoreComponents.html#HowItWorks.CoreComponents.PrimaryKey">Primary Key</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p> <p>Each element in the <code>Item</code> map is an <code>AttributeValue</code> object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> item;

    /**
    *  <p>This is a legacy parameter. Use <code>ConditionExpression</code> instead. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/LegacyConditionalParameters.Expected.html">Expected</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FExpectedAttributeValue> expected;*/

    /**
    *  <p>Use <code>ReturnValues</code> if you want to get the item attributes as they appeared before they were updated with the <code>PutItem</code> request. For <code>PutItem</code>, the valid values are:</p> <ul> <li> <p> <code>NONE</code> - If <code>ReturnValues</code> is not specified, or if its value is <code>NONE</code>, then nothing is returned. (This setting is the default for <code>ReturnValues</code>.)</p> </li> <li> <p> <code>ALL_OLD</code> - If <code>PutItem</code> overwrote an attribute name-value pair, then the content of the old item is returned.</p> </li> </ul> <note> <p>The <code>ReturnValues</code> parameter is used by several DynamoDB operations; however, <code>PutItem</code> does not recognize any values other than <code>NONE</code> or <code>ALL_OLD</code>.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSReturnValue returnValues = EAWSReturnValue::NOT_SET;

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

    /**
    *  <p>This is a legacy parameter. Use <code>ConditionExpression</code> instead. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/LegacyConditionalParameters.ConditionalOperator.html">ConditionalOperator</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSConditionalOperator conditionalOperator = EAWSConditionalOperator::NOT_SET;*/

    /**
    *  <p>A condition that must be satisfied in order for a conditional <code>PutItem</code> operation to succeed.</p> <p>An expression can contain any of the following:</p> <ul> <li> <p>Functions: <code>attribute_exists | attribute_not_exists | attribute_type | contains | begins_with | size</code> </p> <p>These function names are case-sensitive.</p> </li> <li> <p>Comparison operators: <code>= | &lt;&gt; | &lt; | &gt; | &lt;= | &gt;= | BETWEEN | IN </code> </p> </li> <li> <p> Logical operators: <code>AND | OR | NOT</code> </p> </li> </ul> <p>For more information on condition expressions, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.SpecifyingConditions.html">Condition Expressions</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString conditionExpression;

    /**
    *  <p>One or more substitution tokens for attribute names in an expression. The following are some use cases for using <code>ExpressionAttributeNames</code>:</p> <ul> <li> <p>To access an attribute whose name conflicts with a DynamoDB reserved word.</p> </li> <li> <p>To create a placeholder for repeating occurrences of an attribute name in an expression.</p> </li> <li> <p>To prevent special characters in an attribute name from being misinterpreted in an expression.</p> </li> </ul> <p>Use the <b>#</b> character in an expression to dereference an attribute name. For example, consider the following attribute name:</p> <ul> <li> <p> <code>Percentile</code> </p> </li> </ul> <p>The name of this attribute conflicts with a reserved word, so it cannot be used directly in an expression. (For the complete list of reserved words, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ReservedWords.html">Reserved Words</a> in the <i>Amazon DynamoDB Developer Guide</i>). To work around this, you could specify the following for <code>ExpressionAttributeNames</code>:</p> <ul> <li> <p> <code>{"#P":"Percentile"}</code> </p> </li> </ul> <p>You could then use this substitution in an expression, as in this example:</p> <ul> <li> <p> <code>#P = :val</code> </p> </li> </ul> <note> <p>Tokens that begin with the <b>:</b> character are <i>expression attribute values</i>, which are placeholders for the actual value at runtime.</p> </note> <p>For more information on expression attribute names, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.AccessingItemAttributes.html">Specifying Item Attributes</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FString> expressionAttributeNames;

    /**
    *  <p>One or more values that can be substituted in an expression.</p> <p>Use the <b>:</b> (colon) character in an expression to dereference an attribute value. For example, suppose that you wanted to check whether the value of the <i>ProductStatus</i> attribute was one of the following: </p> <p> <code>Available | Backordered | Discontinued</code> </p> <p>You would first need to specify <code>ExpressionAttributeValues</code> as follows:</p> <p> <code>{ ":avail":{"S":"Available"}, ":back":{"S":"Backordered"}, ":disc":{"S":"Discontinued"} }</code> </p> <p>You could then use these values in an expression, such as this:</p> <p> <code>ProductStatus IN (:avail, :back, :disc)</code> </p> <p>For more information on expression attribute values, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.SpecifyingConditions.html">Condition Expressions</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FDynamoDBAttributeValue> expressionAttributeValues;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::PutItemRequest toAWS() const {
        Aws::DynamoDB::Model::PutItemRequest awsPutItemRequest;

		if (!(this->tableName.IsEmpty())) {
            awsPutItemRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->item) {
            awsPutItemRequest.AddItem(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        /*for (const TPair<FString, FExpectedAttributeValue>& elem : this->expected) {
            awsPutItemRequest.AddExpected(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }*/

        switch(this->returnValues) {
            case EAWSReturnValue::NONE:
                awsPutItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::NONE);
                break;
            case EAWSReturnValue::ALL_OLD:
                awsPutItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::ALL_OLD);
                break;
            case EAWSReturnValue::UPDATED_OLD:
                awsPutItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::UPDATED_OLD);
                break;
            case EAWSReturnValue::ALL_NEW:
                awsPutItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::ALL_NEW);
                break;
            case EAWSReturnValue::UPDATED_NEW:
                awsPutItemRequest.SetReturnValues(Aws::DynamoDB::Model::ReturnValue::UPDATED_NEW);
                break;
            default:
                break;
        }

        switch(this->returnConsumedCapacity) {
            case EAWSReturnConsumedCapacity::INDEXES:
                awsPutItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::INDEXES);
                break;
            case EAWSReturnConsumedCapacity::TOTAL:
                awsPutItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::TOTAL);
                break;
            case EAWSReturnConsumedCapacity::NONE:
                awsPutItemRequest.SetReturnConsumedCapacity(Aws::DynamoDB::Model::ReturnConsumedCapacity::NONE);
                break;
            default:
                break;
        }

        switch(this->returnItemCollectionMetrics) {
            case EAWSReturnItemCollectionMetrics::SIZE:
                awsPutItemRequest.SetReturnItemCollectionMetrics(Aws::DynamoDB::Model::ReturnItemCollectionMetrics::SIZE);
                break;
            case EAWSReturnItemCollectionMetrics::NONE:
                awsPutItemRequest.SetReturnItemCollectionMetrics(Aws::DynamoDB::Model::ReturnItemCollectionMetrics::NONE);
                break;
            default:
                break;
        }

        /*switch(this->conditionalOperator) {
            case EAWSConditionalOperator::AND:
                awsPutItemRequest.SetConditionalOperator(Aws::DynamoDB::Model::ConditionalOperator::AND);
                break;
            case EAWSConditionalOperator::OR:
                awsPutItemRequest.SetConditionalOperator(Aws::DynamoDB::Model::ConditionalOperator::OR);
                break;
            default:
                break;
        }*/

		if (!(this->conditionExpression.IsEmpty())) {
            awsPutItemRequest.SetConditionExpression(TCHAR_TO_UTF8(*this->conditionExpression));
        }

        for (const TPair<FString, FString>& elem : this->expressionAttributeNames) {
            awsPutItemRequest.AddExpressionAttributeNames(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        for (const TPair<FString, FDynamoDBAttributeValue>& elem : this->expressionAttributeValues) {
            awsPutItemRequest.AddExpressionAttributeValues(TCHAR_TO_UTF8(*elem.Key), elem.Value.toAWS());
        }

        return awsPutItemRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->item.Num() == 0 && /*this->expected.Num() == 0 && */this->returnValues == EAWSReturnValue::NOT_SET && this->returnConsumedCapacity == EAWSReturnConsumedCapacity::NOT_SET && this->returnItemCollectionMetrics == EAWSReturnItemCollectionMetrics::NOT_SET && /*this->conditionalOperator == EAWSConditionalOperator::NOT_SET && */this->conditionExpression.IsEmpty() && this->expressionAttributeNames.Num() == 0 && this->expressionAttributeValues.Num() == 0;
    }
#endif
};
