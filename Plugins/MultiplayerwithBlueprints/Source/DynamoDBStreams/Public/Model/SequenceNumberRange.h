/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/SequenceNumberRange.h"

#endif

#include "SequenceNumberRange.generated.h"

USTRUCT(BlueprintType)
struct FSequenceNumberRange {
    GENERATED_BODY()

    /**
    *  <p>The first sequence number.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString startingSequenceNumber;

    /**
    *  <p>The last sequence number.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString endingSequenceNumber;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FSequenceNumberRange &fromAWS(const Aws::DynamoDBStreams::Model::SequenceNumberRange &awsSequenceNumberRange) {
        this->startingSequenceNumber = UTF8_TO_TCHAR(awsSequenceNumberRange.GetStartingSequenceNumber().c_str());

        this->endingSequenceNumber = UTF8_TO_TCHAR(awsSequenceNumberRange.GetEndingSequenceNumber().c_str());

        return *this;
    }
#endif
};
