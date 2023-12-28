/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/Stream.h"

#endif

#include "Stream.generated.h"

USTRUCT(BlueprintType)
struct FStream {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) for the stream.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString streamArn;

    /**
    *  <p>The DynamoDB table with which the stream is associated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString tableName;

    /**
    *  <p>A timestamp, in ISO 8601 format, for this stream.</p> <p>Note that <i>LatestStreamLabel</i> is not a unique identifier for the stream, because it is possible that a stream from another table might have the same timestamp. However, the combination of the following three elements is guaranteed to be unique:</p> <ul> <li><p>the AWS customer ID.</p></li> <li><p>the table name</p></li> <li><p>the <i>StreamLabel</i></p></li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString streamLabel;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FStream &fromAWS(const Aws::DynamoDBStreams::Model::Stream &awsStream) {
        this->streamArn = UTF8_TO_TCHAR(awsStream.GetStreamArn().c_str());

        this->tableName = UTF8_TO_TCHAR(awsStream.GetTableName().c_str());

        this->streamLabel = UTF8_TO_TCHAR(awsStream.GetStreamLabel().c_str());

        return *this;
    }
#endif
};
