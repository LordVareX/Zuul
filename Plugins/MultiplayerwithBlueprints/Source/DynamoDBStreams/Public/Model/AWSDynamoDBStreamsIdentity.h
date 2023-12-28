/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/Identity.h"

#endif

#include "AWSDynamoDBStreamsIdentity.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBStreamsIdentity {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the entity that made the call. For Time To Live, the principalId is "dynamodb.amazonaws.com".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString principalId;

    /**
    *  <p>The type of the identity. For Time To Live, the type is "Service".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString type;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBStreamsIdentity &fromAWS(const Aws::DynamoDBStreams::Model::Identity &awsIdentity) {
        this->principalId = UTF8_TO_TCHAR(awsIdentity.GetPrincipalId().c_str());

        this->type = UTF8_TO_TCHAR(awsIdentity.GetType().c_str());

        return *this;
    }
#endif
};
