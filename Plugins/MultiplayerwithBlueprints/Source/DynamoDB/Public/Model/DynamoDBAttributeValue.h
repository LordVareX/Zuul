/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/core/utils/json/JsonSerializer.h"
#include "aws/dynamodb/model/AttributeValue.h"

#endif

#include "DynamoDBGlobals.h"

#include "DynamoDBAttributeValue.generated.h"

USTRUCT(BlueprintType)
struct FDynamoDBAttributeValue {
GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString json;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::AttributeValue toAWS() const {
        Aws::DynamoDB::Model::AttributeValue awsAttributeValue;

        Aws::Utils::Json::JsonValue jsonValue(TCHAR_TO_UTF8(*this->json));
        if (jsonValue.WasParseSuccessful()) {
            awsAttributeValue = jsonValue.View();
        } else {
            LOG_DYNAMODB_NORMAL(FString::Printf(TEXT("json parse error. error message is: %s"), jsonValue.GetErrorMessage().c_str()));
        }

        return awsAttributeValue;
    }

    bool IsEmpty() const {
        Aws::Utils::Json::JsonValue jsonValue(TCHAR_TO_UTF8(*this->json));
        return !jsonValue.WasParseSuccessful();
    }

    FDynamoDBAttributeValue &fromAWS(const Aws::DynamoDB::Model::AttributeValue &awsAttributeValue) {
        this->json = UTF8_TO_TCHAR(awsAttributeValue.Jsonize().View().WriteReadable().c_str());

        return *this;
    }
#endif
};
