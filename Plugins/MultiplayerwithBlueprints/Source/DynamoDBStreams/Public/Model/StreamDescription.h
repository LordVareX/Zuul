/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/StreamDescription.h"

#endif

#include "Model/StreamStatus.h"
#include "Model/DynamoDBStreamsStreamViewType.h"
#include "Model/DynamoDBStreamsKeySchemaElement.h"
#include "Model/Shard.h"

#include "StreamDescription.generated.h"

USTRUCT(BlueprintType)
struct FStreamDescription {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) for the stream.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString streamArn;

    /**
    *  <p>A timestamp, in ISO 8601 format, for this stream.</p> <p>Note that <i>LatestStreamLabel</i> is not a unique identifier for the stream, because it is possible that a stream from another table might have the same timestamp. However, the combination of the following three elements is guaranteed to be unique:</p> <ul> <li><p>the AWS customer ID.</p></li> <li><p>the table name</p></li> <li><p>the <i>StreamLabel</i></p></li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString streamLabel;

    /**
    *  <p>Indicates the current status of the stream:</p> <ul> <li><p><code>ENABLING</code> - Streams is currently being enabled on the DynamoDB table.</p></li> <li><p><code>ENABLING</code> - the stream is enabled.</p></li> <li><p><code>DISABLING</code> - Streams is currently being disabled on the DynamoDB table.</p></li> <li><p><code>DISABLED</code> - the stream is disabled.</p></li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    EAWSStreamStatus streamStatus = EAWSStreamStatus::NOT_SET;

    /**
    *  <p>Indicates the format of the records within this stream:</p> <ul> <li><p><code>KEYS_ONLY</code> - only the key attributes of items that were modified in the DynamoDB table.</p></li> <li><p><code>NEW_IMAGE</code> - entire item from the table, as it appeared after they were modified.</p></li> <li><p><code>OLD_IMAGE</code> - entire item from the table, as it appeared before they were modified.</p></li> <li><p><code>NEW_AND_OLD_IMAGES</code> - both the new and the old images of the items from the table.</p></li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    EAWSDynamoDBStreamsStreamViewType streamViewType = EAWSDynamoDBStreamsStreamViewType::NOT_SET;

    /**
    *  <p>The date and time when the request to create this stream was issued.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FDateTime creationRequestDateTime;

    /**
    *  <p>The DynamoDB table with which the stream is associated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString tableName;

    /**
    *  <p>The key attribute(s) of the stream's DynamoDB table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    TArray<FDynamoDBStreamsKeySchemaElement> keySchema;

    /**
    *  <p>The shards that comprise the stream.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    TArray<FShard> shards;

    /**
    *  <p>The shard ID of the item where the operation stopped, inclusive of the previous result set. Use this value to start a new operation, excluding this value in the new request.</p> <p>If <code>LastEvaluatedShardId</code> is empty, then the "last page" of results has been processed and there is currently no more data to be retrieved.</p> <p>If <code>LastEvaluatedShardId</code> is not empty, it does not necessarily mean that there is more data in the result set. The only way to know when you have reached the end of the result set is when <code>LastEvaluatedShardId</code> is empty.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString lastEvaluatedShardId;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FStreamDescription &fromAWS(const Aws::DynamoDBStreams::Model::StreamDescription &awsStreamDescription) {
        this->streamArn = UTF8_TO_TCHAR(awsStreamDescription.GetStreamArn().c_str());

        this->streamLabel = UTF8_TO_TCHAR(awsStreamDescription.GetStreamLabel().c_str());

        switch(awsStreamDescription.GetStreamStatus()) {
            case Aws::DynamoDBStreams::Model::StreamStatus::NOT_SET:
                this->streamStatus = EAWSStreamStatus::NOT_SET;
                break;
            case Aws::DynamoDBStreams::Model::StreamStatus::ENABLING:
                this->streamStatus = EAWSStreamStatus::ENABLING;
                break;
            case Aws::DynamoDBStreams::Model::StreamStatus::ENABLED:
                this->streamStatus = EAWSStreamStatus::ENABLED;
                break;
            case Aws::DynamoDBStreams::Model::StreamStatus::DISABLING:
                this->streamStatus = EAWSStreamStatus::DISABLING;
                break;
            case Aws::DynamoDBStreams::Model::StreamStatus::DISABLED:
                this->streamStatus = EAWSStreamStatus::DISABLED;
                break;
            default:
                this->streamStatus = EAWSStreamStatus::NOT_SET;
                break;
            }

        switch(awsStreamDescription.GetStreamViewType()) {
            case Aws::DynamoDBStreams::Model::StreamViewType::NOT_SET:
                this->streamViewType = EAWSDynamoDBStreamsStreamViewType::NOT_SET;
                break;
            case Aws::DynamoDBStreams::Model::StreamViewType::NEW_IMAGE:
                this->streamViewType = EAWSDynamoDBStreamsStreamViewType::NEW_IMAGE;
                break;
            case Aws::DynamoDBStreams::Model::StreamViewType::OLD_IMAGE:
                this->streamViewType = EAWSDynamoDBStreamsStreamViewType::OLD_IMAGE;
                break;
            case Aws::DynamoDBStreams::Model::StreamViewType::NEW_AND_OLD_IMAGES:
                this->streamViewType = EAWSDynamoDBStreamsStreamViewType::NEW_AND_OLD_IMAGES;
                break;
            case Aws::DynamoDBStreams::Model::StreamViewType::KEYS_ONLY:
                this->streamViewType = EAWSDynamoDBStreamsStreamViewType::KEYS_ONLY;
                break;
            default:
                this->streamViewType = EAWSDynamoDBStreamsStreamViewType::NOT_SET;
                break;
            }

        this->creationRequestDateTime = FDateTime(1970, 1, 1) + FTimespan(awsStreamDescription.GetCreationRequestDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->tableName = UTF8_TO_TCHAR(awsStreamDescription.GetTableName().c_str());

        this->keySchema.Empty();
        for (const Aws::DynamoDBStreams::Model::KeySchemaElement& elem : awsStreamDescription.GetKeySchema()) {
            this->keySchema.Add(FDynamoDBStreamsKeySchemaElement().fromAWS(elem));
        }

        this->shards.Empty();
        for (const Aws::DynamoDBStreams::Model::Shard& elem : awsStreamDescription.GetShards()) {
            this->shards.Add(FShard().fromAWS(elem));
        }

        this->lastEvaluatedShardId = UTF8_TO_TCHAR(awsStreamDescription.GetLastEvaluatedShardId().c_str());

        return *this;
    }
#endif
};
