/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/GetShardIteratorResult.h"

#endif

#include "GetShardIteratorResult.generated.h"

USTRUCT(BlueprintType)
struct FGetShardIteratorResult {
GENERATED_BODY()

    /**
    *  <p>The position in the shard from which to start reading stream records sequentially. A shard iterator specifies this position using the sequence number of a stream record in a shard.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString shardIterator;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FGetShardIteratorResult &fromAWS(const Aws::DynamoDBStreams::Model::GetShardIteratorResult &awsGetShardIteratorResult) {
        this->shardIterator = UTF8_TO_TCHAR(awsGetShardIteratorResult.GetShardIterator().c_str());

        return *this;
    }
#endif
};
