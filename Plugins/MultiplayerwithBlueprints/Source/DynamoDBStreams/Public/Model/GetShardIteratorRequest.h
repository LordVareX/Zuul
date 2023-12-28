/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/GetShardIteratorRequest.h"

#endif

#include "Model/ShardIteratorType.h"

#include "GetShardIteratorRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetShardIteratorRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) for the stream.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString streamArn;

    /**
    *  <p>The identifier of the shard. The iterator will be returned for this shard ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString shardId;

    /**
    *  <p>Determines how the shard iterator is used to start reading stream records from the shard:</p> <ul> <li> <p><code>AT_SEQUENCE_NUMBER</code> - Start reading exactly from the position denoted by a specific sequence number.</p> </li> <li> <p><code>AFTER_SEQUENCE_NUMBER</code> - Start reading right after the position denoted by a specific sequence number.</p> </li> <li> <p><code>TRIM_HORIZON</code> - Start reading at the last (untrimmed) stream record, which is the oldest record in the shard. In DynamoDB Streams, there is a 24 hour limit on data retention. Stream records whose age exceeds this limit are subject to removal (trimming) from the stream.</p> </li> <li> <p><code>LATEST</code> - Start reading just after the most recent stream record in the shard, so that you always read the most recent data in the shard.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    EAWSShardIteratorType shardIteratorType = EAWSShardIteratorType::NOT_SET;

    /**
    *  <p>The sequence number of a stream record in the shard from which to start reading.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString sequenceNumber;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDBStreams::Model::GetShardIteratorRequest toAWS() const {
        Aws::DynamoDBStreams::Model::GetShardIteratorRequest awsGetShardIteratorRequest;

		if (!(this->streamArn.IsEmpty())) {
            awsGetShardIteratorRequest.SetStreamArn(TCHAR_TO_UTF8(*this->streamArn));
        }

		if (!(this->shardId.IsEmpty())) {
            awsGetShardIteratorRequest.SetShardId(TCHAR_TO_UTF8(*this->shardId));
        }

        switch(this->shardIteratorType) {
            case EAWSShardIteratorType::TRIM_HORIZON:
                awsGetShardIteratorRequest.SetShardIteratorType(Aws::DynamoDBStreams::Model::ShardIteratorType::TRIM_HORIZON);
                break;
            case EAWSShardIteratorType::LATEST:
                awsGetShardIteratorRequest.SetShardIteratorType(Aws::DynamoDBStreams::Model::ShardIteratorType::LATEST);
                break;
            case EAWSShardIteratorType::AT_SEQUENCE_NUMBER:
                awsGetShardIteratorRequest.SetShardIteratorType(Aws::DynamoDBStreams::Model::ShardIteratorType::AT_SEQUENCE_NUMBER);
                break;
            case EAWSShardIteratorType::AFTER_SEQUENCE_NUMBER:
                awsGetShardIteratorRequest.SetShardIteratorType(Aws::DynamoDBStreams::Model::ShardIteratorType::AFTER_SEQUENCE_NUMBER);
                break;
            default:
                break;
            }

		if (!(this->sequenceNumber.IsEmpty())) {
            awsGetShardIteratorRequest.SetSequenceNumber(TCHAR_TO_UTF8(*this->sequenceNumber));
        }

        return awsGetShardIteratorRequest;
    }

    bool IsEmpty() const {
        return this->streamArn.IsEmpty() && this->shardId.IsEmpty() && this->shardIteratorType == EAWSShardIteratorType::NOT_SET && this->sequenceNumber.IsEmpty();
    }
#endif
};
