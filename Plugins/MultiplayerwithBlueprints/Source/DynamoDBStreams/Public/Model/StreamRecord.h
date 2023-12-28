/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/StreamRecord.h"

#endif

#include "Model/DynamoDBStreamsAttributeValue.h"
#include "Model/DynamoDBStreamsStreamViewType.h"

#include "StreamRecord.generated.h"

USTRUCT(BlueprintType)
struct FStreamRecord {
GENERATED_BODY()

    /**
    *  <p>The approximate date and time when the stream record was created, in <a href="http://www.epochconverter.com/">UNIX epoch time</a> format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FDateTime approximateCreationDateTime;

    /**
    *  <p>The primary key attribute(s) for the DynamoDB item that was modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    TMap<FString, FDynamoDBStreamsAttributeValue> keys;

    /**
    *  <p>The item in the DynamoDB table as it appeared after it was modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    TMap<FString, FDynamoDBStreamsAttributeValue> newImage;

    /**
    *  <p>The item in the DynamoDB table as it appeared before it was modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    TMap<FString, FDynamoDBStreamsAttributeValue> oldImage;

    /**
    *  <p>The sequence number of the stream record.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString sequenceNumber;

    /**
    *  <p>The size of the stream record, in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    int64 sizeBytes = 0;

    /**
    *  <p>The type of data from the modified DynamoDB item that was captured in this stream record:</p> <ul> <li><p><code>KEYS_ONLY</code> - only the key attributes of the modified item.</p></li> <li><p><code>NEW_IMAGE</code> - the entire item, as it appears after it was modified.</p></li> <li><p><code>OLD_IMAGE</code> - the entire item, as it appeared before it was modified.</p></li> <li><p><code>NEW_AND_OLD_IMAGES</code> — both the new and the old item images of the item.</p></li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    EAWSDynamoDBStreamsStreamViewType streamViewType = EAWSDynamoDBStreamsStreamViewType::NOT_SET;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FStreamRecord &fromAWS(const Aws::DynamoDBStreams::Model::StreamRecord &awsStreamRecord) {
        this->approximateCreationDateTime = FDateTime(1970, 1, 1) + FTimespan(awsStreamRecord.GetApproximateCreationDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->keys.Empty();
        for (const auto& elem : awsStreamRecord.GetKeys()) {
            this->keys.Add(elem.first.c_str(), FDynamoDBStreamsAttributeValue().fromAWS(elem.second));
        }

        this->newImage.Empty();
        for (const auto& elem : awsStreamRecord.GetNewImage()) {
            this->newImage.Add(elem.first.c_str(), FDynamoDBStreamsAttributeValue().fromAWS(elem.second));
        }

        this->oldImage.Empty();
        for (const auto& elem : awsStreamRecord.GetOldImage()) {
            this->oldImage.Add(elem.first.c_str(), FDynamoDBStreamsAttributeValue().fromAWS(elem.second));
        }

        this->sequenceNumber = UTF8_TO_TCHAR(awsStreamRecord.GetSequenceNumber().c_str());

        this->sizeBytes = (int64)awsStreamRecord.GetSizeBytes();

        switch(awsStreamRecord.GetStreamViewType()) {
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

        return *this;
    }
#endif
};
