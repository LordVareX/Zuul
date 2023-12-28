/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/KeySchemaElement.h"

#endif

#include "Model/DynamoDBStreamsKeyType.h"

#include "DynamoDBStreamsKeySchemaElement.generated.h"

USTRUCT(BlueprintType)
struct FDynamoDBStreamsKeySchemaElement {
GENERATED_BODY()

    /**
    *  <p>The name of a key attribute.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString attributeName;

    /**
    *  <p>The attribute data, consisting of the data type and the attribute value itself.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    EAWSDynamoDBStreamsKeyType keyType = EAWSDynamoDBStreamsKeyType::NOT_SET;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FDynamoDBStreamsKeySchemaElement &fromAWS(const Aws::DynamoDBStreams::Model::KeySchemaElement &awsKeySchemaElement) {
        this->attributeName = UTF8_TO_TCHAR(awsKeySchemaElement.GetAttributeName().c_str());

        switch(awsKeySchemaElement.GetKeyType()) {
            case Aws::DynamoDBStreams::Model::KeyType::NOT_SET:
                this->keyType = EAWSDynamoDBStreamsKeyType::NOT_SET;
                break;
            case Aws::DynamoDBStreams::Model::KeyType::HASH:
                this->keyType = EAWSDynamoDBStreamsKeyType::HASH;
                break;
            case Aws::DynamoDBStreams::Model::KeyType::RANGE:
                this->keyType = EAWSDynamoDBStreamsKeyType::RANGE;
                break;
            default:
                this->keyType = EAWSDynamoDBStreamsKeyType::NOT_SET;
                break;
            }

        return *this;
    }
#endif
};
