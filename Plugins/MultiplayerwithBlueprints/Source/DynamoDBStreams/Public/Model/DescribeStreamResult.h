/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/DescribeStreamResult.h"

#endif

#include "Model/StreamDescription.h"

#include "DescribeStreamResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeStreamResult {
GENERATED_BODY()

    /**
    *  <p>A complete description of the stream, including its creation date and time, the DynamoDB table associated with the stream, the shard IDs within the stream, and the beginning and ending sequence numbers of stream records within the shards.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FStreamDescription streamDescription;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FDescribeStreamResult &fromAWS(const Aws::DynamoDBStreams::Model::DescribeStreamResult &awsDescribeStreamResult) {
        this->streamDescription.fromAWS(awsDescribeStreamResult.GetStreamDescription());

        return *this;
    }
#endif
};
