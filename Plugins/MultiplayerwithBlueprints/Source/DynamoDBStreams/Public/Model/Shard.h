/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/Shard.h"

#endif

#include "Model/SequenceNumberRange.h"

#include "Shard.generated.h"

USTRUCT(BlueprintType)
struct FShard {
GENERATED_BODY()

    /**
    *  <p>The system-generated identifier for this shard.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString shardId;

    /**
    *  <p>The range of possible sequence numbers for the shard.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FSequenceNumberRange sequenceNumberRange;

    /**
    *  <p>The shard ID of the current shard's parent.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString parentShardId;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FShard &fromAWS(const Aws::DynamoDBStreams::Model::Shard &awsShard) {
        this->shardId = UTF8_TO_TCHAR(awsShard.GetShardId().c_str());

        this->sequenceNumberRange.fromAWS(awsShard.GetSequenceNumberRange());

        this->parentShardId = UTF8_TO_TCHAR(awsShard.GetParentShardId().c_str());

        return *this;
    }
#endif
};
