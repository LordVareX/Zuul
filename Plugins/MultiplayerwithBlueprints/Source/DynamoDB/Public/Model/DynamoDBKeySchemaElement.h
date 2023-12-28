/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/KeySchemaElement.h"

#endif

#include "Model/DynamoDBKeyType.h"

#include "DynamoDBKeySchemaElement.generated.h"

USTRUCT(BlueprintType)
struct FDynamoDBKeySchemaElement {
GENERATED_BODY()

    /**
    *  <p>The name of a key attribute.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString attributeName;

    /**
    *  <p>The role that this key attribute will assume:</p> <ul> <li> <p> <code>HASH</code> - partition key</p> </li> <li> <p> <code>RANGE</code> - sort key</p> </li> </ul> <note> <p>The partition key of an item is also known as its <i>hash attribute</i>. The term "hash attribute" derives from DynamoDB' usage of an internal hash function to evenly distribute data items across partitions, based on their partition key values.</p> <p>The sort key of an item is also known as its <i>range attribute</i>. The term "range attribute" derives from the way DynamoDB stores items with the same partition key physically close together, in sorted order by the sort key value.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSDynamoDBKeyType keyType = EAWSDynamoDBKeyType::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::KeySchemaElement toAWS() const {
        Aws::DynamoDB::Model::KeySchemaElement awsKeySchemaElement;

		if (!(this->attributeName.IsEmpty())) {
            awsKeySchemaElement.SetAttributeName(TCHAR_TO_UTF8(*this->attributeName));
        }

        switch(this->keyType) {
            case EAWSDynamoDBKeyType::HASH:
                awsKeySchemaElement.SetKeyType(Aws::DynamoDB::Model::KeyType::HASH);
                break;
            case EAWSDynamoDBKeyType::RANGE:
                awsKeySchemaElement.SetKeyType(Aws::DynamoDB::Model::KeyType::RANGE);
                break;
            default:
                break;
            }

        return awsKeySchemaElement;
    }

    bool IsEmpty() const {
        return this->attributeName.IsEmpty() && this->keyType == EAWSDynamoDBKeyType::NOT_SET;
    }

    FDynamoDBKeySchemaElement &fromAWS(const Aws::DynamoDB::Model::KeySchemaElement &awsKeySchemaElement) {
        this->attributeName = UTF8_TO_TCHAR(awsKeySchemaElement.GetAttributeName().c_str());

        switch(awsKeySchemaElement.GetKeyType()) {
            case Aws::DynamoDB::Model::KeyType::NOT_SET:
                this->keyType = EAWSDynamoDBKeyType::NOT_SET;
                break;
            case Aws::DynamoDB::Model::KeyType::HASH:
                this->keyType = EAWSDynamoDBKeyType::HASH;
                break;
            case Aws::DynamoDB::Model::KeyType::RANGE:
                this->keyType = EAWSDynamoDBKeyType::RANGE;
                break;
            default:
                this->keyType = EAWSDynamoDBKeyType::NOT_SET;
                break;
            }

        return *this;
    }
#endif
};
