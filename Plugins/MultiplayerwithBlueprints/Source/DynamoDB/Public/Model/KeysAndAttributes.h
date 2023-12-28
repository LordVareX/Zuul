/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/KeysAndAttributes.h"

#endif

#include "DynamoDBGlobals.h"

#include "KeysAndAttributes.generated.h"

USTRUCT(BlueprintType)
struct FKeysAndAttributes {
GENERATED_BODY()

    /**
    *  <p>The primary key attribute values that define the items and the attributes associated with the items.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FString> keys;

    /**
    *  <p>This is a legacy parameter. Use <code>ProjectionExpression</code> instead. For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/LegacyConditionalParameters.html">Legacy Conditional Parameters</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FString> attributesToGet;*/

    /**
    *  <p>The consistency of a read operation. If set to <code>true</code>, then a strongly consistent read is used; otherwise, an eventually consistent read is used.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool consistentRead = false;

    /**
    *  <p>A string that identifies one or more attributes to retrieve from the table. These attributes can include scalars, sets, or elements of a JSON document. The attributes in the <code>ProjectionExpression</code> must be separated by commas.</p> <p>If no attribute names are specified, then all attributes will be returned. If any of the requested attributes are not found, they will not appear in the result.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.AccessingItemAttributes.html">Accessing Item Attributes</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString projectionExpression;

    /**
    *  <p>One or more substitution tokens for attribute names in an expression. The following are some use cases for using <code>ExpressionAttributeNames</code>:</p> <ul> <li> <p>To access an attribute whose name conflicts with a DynamoDB reserved word.</p> </li> <li> <p>To create a placeholder for repeating occurrences of an attribute name in an expression.</p> </li> <li> <p>To prevent special characters in an attribute name from being misinterpreted in an expression.</p> </li> </ul> <p>Use the <b>#</b> character in an expression to dereference an attribute name. For example, consider the following attribute name:</p> <ul> <li> <p> <code>Percentile</code> </p> </li> </ul> <p>The name of this attribute conflicts with a reserved word, so it cannot be used directly in an expression. (For the complete list of reserved words, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/ReservedWords.html">Reserved Words</a> in the <i>Amazon DynamoDB Developer Guide</i>). To work around this, you could specify the following for <code>ExpressionAttributeNames</code>:</p> <ul> <li> <p> <code>{"#P":"Percentile"}</code> </p> </li> </ul> <p>You could then use this substitution in an expression, as in this example:</p> <ul> <li> <p> <code>#P = :val</code> </p> </li> </ul> <note> <p>Tokens that begin with the <b>:</b> character are <i>expression attribute values</i>, which are placeholders for the actual value at runtime.</p> </note> <p>For more information on expression attribute names, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Expressions.AccessingItemAttributes.html">Accessing Item Attributes</a> in the <i>Amazon DynamoDB Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TMap<FString, FString> expressionAttributeNames;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::KeysAndAttributes toAWS() const {
        Aws::DynamoDB::Model::KeysAndAttributes awsKeysAndAttributes;

        for (const FString& elem : this->keys) {
            Aws::Utils::Json::JsonValue json(TCHAR_TO_UTF8(*elem));
            if (json.WasParseSuccessful()) {
                Aws::Map<Aws::String, Aws::Utils::Json::JsonView> keyJsonMap = json.View().GetAllObjects();
                Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue> keyMap;
                for(auto& keyItem : keyJsonMap) {
                  keyMap[keyItem.first] = keyItem.second.AsObject();
                }
                awsKeysAndAttributes.AddKeys(keyMap);
            } else {
                LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("json parse error. error message is: %s"), json.GetErrorMessage().c_str()));
            }
        }

        /*for (const FString& elem : this->attributesToGet) {
            awsKeysAndAttributes.AddAttributesToGet(TCHAR_TO_UTF8(*elem));
        }*/

        awsKeysAndAttributes.SetConsistentRead(this->consistentRead);

		if (!(this->projectionExpression.IsEmpty())) {
            awsKeysAndAttributes.SetProjectionExpression(TCHAR_TO_UTF8(*this->projectionExpression));
        }

        for (const TPair<FString, FString>& elem : this->expressionAttributeNames) {
            awsKeysAndAttributes.AddExpressionAttributeNames(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsKeysAndAttributes;
    }

    bool IsEmpty() const {
        return this->keys.Num() == 0 && /*this->attributesToGet.Num() == 0 && */false && this->projectionExpression.IsEmpty() && this->expressionAttributeNames.Num() == 0;
    }

    FKeysAndAttributes &fromAWS(const Aws::DynamoDB::Model::KeysAndAttributes &awsKeysAndAttributes) {
        this->keys.Empty();
        for (const Aws::Map<Aws::String, Aws::DynamoDB::Model::AttributeValue>& elem : awsKeysAndAttributes.GetKeys()) {
            Aws::Utils::Json::JsonValue json;
            for (const auto& elem1 : elem) {
                json.WithObject(elem1.first, elem1.second.Jsonize());
            }
            this->keys.Add(UTF8_TO_TCHAR(json.View().WriteReadable().c_str()));
        }

        /*this->attributesToGet.Empty();
        for (const Aws::String& elem : awsKeysAndAttributes.GetAttributesToGet()) {
            this->attributesToGet.Add(elem.c_str());
        }*/

        this->consistentRead = awsKeysAndAttributes.GetConsistentRead();

        this->projectionExpression = UTF8_TO_TCHAR(awsKeysAndAttributes.GetProjectionExpression().c_str());

        this->expressionAttributeNames.Empty();
        for (const auto& elem : awsKeysAndAttributes.GetExpressionAttributeNames()) {
            this->expressionAttributeNames.Add(elem.first.c_str(), elem.second.c_str());
        }

        return *this;
    }
#endif
};
