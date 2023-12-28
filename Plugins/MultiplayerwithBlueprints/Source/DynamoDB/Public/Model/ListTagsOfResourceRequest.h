/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListTagsOfResourceRequest.h"

#endif

#include "ListTagsOfResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FListTagsOfResourceRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon DynamoDB resource with tags to be listed. This value is an Amazon Resource Name (ARN).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString resourceArn;

    /**
    *  <p>An optional string that, if supplied, must be copied from the output of a previous call to ListTagOfResource. When provided in this manner, this API fetches the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ListTagsOfResourceRequest toAWS() const {
        Aws::DynamoDB::Model::ListTagsOfResourceRequest awsListTagsOfResourceRequest;

		if (!(this->resourceArn.IsEmpty())) {
            awsListTagsOfResourceRequest.SetResourceArn(TCHAR_TO_UTF8(*this->resourceArn));
        }

		if (!(this->nextToken.IsEmpty())) {
            awsListTagsOfResourceRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListTagsOfResourceRequest;
    }

    bool IsEmpty() const {
        return this->resourceArn.IsEmpty() && this->nextToken.IsEmpty();
    }
#endif
};
