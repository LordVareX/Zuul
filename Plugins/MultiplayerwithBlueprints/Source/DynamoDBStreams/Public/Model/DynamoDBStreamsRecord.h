/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/Record.h"

#endif

#include "Model/OperationType.h"
#include "Model/StreamRecord.h"
#include "Model/AWSDynamoDBStreamsIdentity.h"

#include "DynamoDBStreamsRecord.generated.h"

USTRUCT(BlueprintType)
struct FDynamoDBStreamsRecord {
GENERATED_BODY()

    /**
    *  <p>A globally unique identifier for the event that was recorded in this stream record.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString eventID;

    /**
    *  <p>The type of data modification that was performed on the DynamoDB table:</p> <ul> <li><p><code>INSERT</code> - a new item was added to the table.</p></li> <li><p><code>MODIFY</code> - one or more of the item's attributes were updated.</p></li> <li><p><code>REMOVE</code> - the item was deleted from the table</p></li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    EAWSOperationType eventName = EAWSOperationType::NOT_SET;

    /**
    *  <p>The version number of the stream record format. Currently, this is <i>1.0</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString eventVersion;

    /**
    *  <p>The AWS service from which the stream record originated. For DynamoDB Streams, this is <i>aws:dynamodb</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString eventSource;

    /**
    *  <p>The region in which the <i>GetRecords</i> request was received.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString awsRegion;

    /**
    *  <p>The main body of the stream record, containing all of the DynamoDB-specific fields.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FStreamRecord dynamodb;

    /**
    *  <p>Items that are deleted by the Time to Live process after expiration have the following fields: </p> <ul> <li> <p>Records[].userIdentity.type</p> <p>"Service"</p> </li> <li> <p>Records[].userIdentity.principalId</p> <p>"dynamodb.amazonaws.com"</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FAWSDynamoDBStreamsIdentity userIdentity;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FDynamoDBStreamsRecord &fromAWS(const Aws::DynamoDBStreams::Model::Record &awsRecord) {
        this->eventID = UTF8_TO_TCHAR(awsRecord.GetEventID().c_str());

        switch(awsRecord.GetEventName()) {
            case Aws::DynamoDBStreams::Model::OperationType::NOT_SET:
                this->eventName = EAWSOperationType::NOT_SET;
                break;
            case Aws::DynamoDBStreams::Model::OperationType::INSERT:
                this->eventName = EAWSOperationType::INSERT;
                break;
            case Aws::DynamoDBStreams::Model::OperationType::MODIFY:
                this->eventName = EAWSOperationType::MODIFY;
                break;
            case Aws::DynamoDBStreams::Model::OperationType::REMOVE:
                this->eventName = EAWSOperationType::REMOVE;
                break;
            default:
                this->eventName = EAWSOperationType::NOT_SET;
                break;
            }

        this->eventVersion = UTF8_TO_TCHAR(awsRecord.GetEventVersion().c_str());

        this->eventSource = UTF8_TO_TCHAR(awsRecord.GetEventSource().c_str());

        this->awsRegion = UTF8_TO_TCHAR(awsRecord.GetAwsRegion().c_str());

        this->dynamodb.fromAWS(awsRecord.GetDynamodb());

        this->userIdentity.fromAWS(awsRecord.GetUserIdentity());

        return *this;
    }
#endif
};
