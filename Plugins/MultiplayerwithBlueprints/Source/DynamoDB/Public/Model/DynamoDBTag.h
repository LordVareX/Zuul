/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/Tag.h"

#endif

#include "DynamoDBTag.generated.h"

USTRUCT(BlueprintType)
struct FDynamoDBTag {
GENERATED_BODY()

    /**
    *  <p>The key of the tag. Tag keys are case sensitive. Each DynamoDB table can only have up to one tag with the same key. If you try to add an existing tag (same key), the existing tag value will be updated to the new value. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString key;

    /**
    *  <p>The value of the tag. Tag values are case-sensitive and can be null.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString value;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::Tag toAWS() const {
        Aws::DynamoDB::Model::Tag awsTag;

		if (!(this->key.IsEmpty())) {
            awsTag.SetKey(TCHAR_TO_UTF8(*this->key));
        }

		if (!(this->value.IsEmpty())) {
            awsTag.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        return awsTag;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty() && this->value.IsEmpty();
    }

    FDynamoDBTag &fromAWS(const Aws::DynamoDB::Model::Tag &awsTag) {
        this->key = UTF8_TO_TCHAR(awsTag.GetKey().c_str());

        this->value = UTF8_TO_TCHAR(awsTag.GetValue().c_str());

        return *this;
    }
#endif
};
