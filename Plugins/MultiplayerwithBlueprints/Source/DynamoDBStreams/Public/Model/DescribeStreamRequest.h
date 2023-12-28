/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/DescribeStreamRequest.h"

#endif

#include "DescribeStreamRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeStreamRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) for the stream.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString streamArn;

    /**
    *  <p>The maximum number of shard objects to return. The upper limit is 100.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    int limit = 0;

    /**
    *  <p>The shard ID of the first item that this operation will evaluate. Use the value that was returned for <code>LastEvaluatedShardId</code> in the previous operation. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString exclusiveStartShardId;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDBStreams::Model::DescribeStreamRequest toAWS() const {
        Aws::DynamoDBStreams::Model::DescribeStreamRequest awsDescribeStreamRequest;

		if (!(this->streamArn.IsEmpty())) {
            awsDescribeStreamRequest.SetStreamArn(TCHAR_TO_UTF8(*this->streamArn));
        }

        if (this->limit != 0) {
            awsDescribeStreamRequest.SetLimit(this->limit);
        }

		if (!(this->exclusiveStartShardId.IsEmpty())) {
            awsDescribeStreamRequest.SetExclusiveStartShardId(TCHAR_TO_UTF8(*this->exclusiveStartShardId));
        }

        return awsDescribeStreamRequest;
    }

    bool IsEmpty() const {
        return this->streamArn.IsEmpty() && this->limit == 0 && this->exclusiveStartShardId.IsEmpty();
    }
#endif
};
