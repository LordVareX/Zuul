/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/GetRecordsRequest.h"

#endif

#include "GetRecordsRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetRecordsRequest {
GENERATED_BODY()

    /**
    *  <p>A shard iterator that was retrieved from a previous GetShardIterator operation. This iterator can be used to access the stream records in this shard.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString shardIterator;

    /**
    *  <p>The maximum number of records to return from the shard. The upper limit is 1000.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    int limit = 0;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDBStreams::Model::GetRecordsRequest toAWS() const {
        Aws::DynamoDBStreams::Model::GetRecordsRequest awsGetRecordsRequest;

		if (!(this->shardIterator.IsEmpty())) {
            awsGetRecordsRequest.SetShardIterator(TCHAR_TO_UTF8(*this->shardIterator));
        }

        if (this->limit != 0) {
            awsGetRecordsRequest.SetLimit(this->limit);
        }

        return awsGetRecordsRequest;
    }

    bool IsEmpty() const {
        return this->shardIterator.IsEmpty() && this->limit == 0;
    }
#endif
};
