/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/ListStreamsResult.h"

#endif

#include "Model/Stream.h"

#include "ListStreamsResult.generated.h"

USTRUCT(BlueprintType)
struct FListStreamsResult {
GENERATED_BODY()

    /**
    *  <p>A list of stream descriptors associated with the current account and endpoint.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    TArray<FStream> streams;

    /**
    *  <p>The stream ARN of the item where the operation stopped, inclusive of the previous result set. Use this value to start a new operation, excluding this value in the new request.</p> <p>If <code>LastEvaluatedStreamArn</code> is empty, then the "last page" of results has been processed and there is no more data to be retrieved.</p> <p>If <code>LastEvaluatedStreamArn</code> is not empty, it does not necessarily mean that there is more data in the result set. The only way to know when you have reached the end of the result set is when <code>LastEvaluatedStreamArn</code> is empty.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString lastEvaluatedStreamArn;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FListStreamsResult &fromAWS(const Aws::DynamoDBStreams::Model::ListStreamsResult &awsListStreamsResult) {
        this->streams.Empty();
        for (const Aws::DynamoDBStreams::Model::Stream& elem : awsListStreamsResult.GetStreams()) {
            this->streams.Add(FStream().fromAWS(elem));
        }

        this->lastEvaluatedStreamArn = UTF8_TO_TCHAR(awsListStreamsResult.GetLastEvaluatedStreamArn().c_str());

        return *this;
    }
#endif
};
