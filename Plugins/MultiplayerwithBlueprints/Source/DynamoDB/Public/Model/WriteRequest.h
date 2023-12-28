/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/WriteRequest.h"

#endif

#include "Model/PutRequest.h"
#include "Model/DeleteRequest.h"

#include "WriteRequest.generated.h"

USTRUCT(BlueprintType)
struct FWriteRequest {
GENERATED_BODY()

    /**
    *  <p>A request to perform a <code>PutItem</code> operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FPutRequest putRequest;

    /**
    *  <p>A request to perform a <code>DeleteItem</code> operation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDeleteRequest deleteRequest;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::WriteRequest toAWS() const {
        Aws::DynamoDB::Model::WriteRequest awsWriteRequest;

        if (!(this->putRequest.IsEmpty())) {
            awsWriteRequest.SetPutRequest(this->putRequest.toAWS());
        }

        if (!(this->deleteRequest.IsEmpty())) {
            awsWriteRequest.SetDeleteRequest(this->deleteRequest.toAWS());
        }

        return awsWriteRequest;
    }

    bool IsEmpty() const {
        return this->putRequest.IsEmpty() && this->deleteRequest.IsEmpty();
    }

    FWriteRequest &fromAWS(const Aws::DynamoDB::Model::WriteRequest &awsWriteRequest) {
        this->putRequest.fromAWS(awsWriteRequest.GetPutRequest());

        this->deleteRequest.fromAWS(awsWriteRequest.GetDeleteRequest());

        return *this;
    }
#endif
};
