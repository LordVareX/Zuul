/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/core/utils/json/JsonSerializer.h"
#include "aws/dynamodbstreams/model/AttributeValue.h"

#endif

#include "DynamoDBStreamsGlobals.h"

#include "DynamoDBStreamsAttributeValue.generated.h"

USTRUCT(BlueprintType)
struct FDynamoDBStreamsAttributeValue {
GENERATED_BODY()

    /**
    *  <p>A json</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString json;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDBStreams::Model::AttributeValue toAWS() const {
        Aws::DynamoDBStreams::Model::AttributeValue awsAttributeValue;

        Aws::Utils::Json::JsonValue jsonValue(TCHAR_TO_UTF8(*this->json));
        if (jsonValue.WasParseSuccessful()) {
            awsAttributeValue = jsonValue.View();
        } else {
            LOG_DYNAMODBSTREAMS_NORMAL(FString::Printf(TEXT("json parse error. error message is: %s"), jsonValue.GetErrorMessage().c_str()));
        }

        return awsAttributeValue;
    }

    bool IsEmpty() const {
        Aws::Utils::Json::JsonValue jsonValue(TCHAR_TO_UTF8(*this->json));
        return !jsonValue.WasParseSuccessful();
    }

    FDynamoDBStreamsAttributeValue &fromAWS(const Aws::DynamoDBStreams::Model::AttributeValue &awsAttributeValue) {
        this->json = UTF8_TO_TCHAR(awsAttributeValue.Jsonize().View().WriteReadable().c_str());

        return *this;
    }
#endif
};
