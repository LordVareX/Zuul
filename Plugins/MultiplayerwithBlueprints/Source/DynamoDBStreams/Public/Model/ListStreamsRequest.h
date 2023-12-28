/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/ListStreamsRequest.h"

#endif

#include "ListStreamsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListStreamsRequest {
GENERATED_BODY()

    /**
    *  <p>If this parameter is provided, then only the streams associated with this table name are returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString tableName;

    /**
    *  <p>The maximum number of streams to return. The upper limit is 100.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    int limit = 0;

    /**
    *  <p>The ARN (Amazon Resource Name) of the first item that this operation will evaluate. Use the value that was returned for <code>LastEvaluatedStreamArn</code> in the previous operation. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString exclusiveStartStreamArn;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDBStreams::Model::ListStreamsRequest toAWS() const {
        Aws::DynamoDBStreams::Model::ListStreamsRequest awsListStreamsRequest;

		if (!(this->tableName.IsEmpty())) {
            awsListStreamsRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        if (this->limit != 0) {
            awsListStreamsRequest.SetLimit(this->limit);
        }

		if (!(this->exclusiveStartStreamArn.IsEmpty())) {
            awsListStreamsRequest.SetExclusiveStartStreamArn(TCHAR_TO_UTF8(*this->exclusiveStartStreamArn));
        }

        return awsListStreamsRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->limit == 0 && this->exclusiveStartStreamArn.IsEmpty();
    }
#endif
};
