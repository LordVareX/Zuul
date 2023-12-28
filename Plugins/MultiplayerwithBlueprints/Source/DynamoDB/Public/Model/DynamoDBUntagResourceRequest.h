/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UntagResourceRequest.h"

#endif

#include "DynamoDBUntagResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FDynamoDBUntagResourceRequest {
GENERATED_BODY()

    /**
    *  <p>The DynamoDB resource that the tags will be removed from. This value is an Amazon Resource Name (ARN).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString resourceArn;

    /**
    *  <p>A list of tag keys. Existing tags of the resource whose keys are members of this list will be removed from the DynamoDB resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FString> tagKeys;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::UntagResourceRequest toAWS() const {
        Aws::DynamoDB::Model::UntagResourceRequest awsUntagResourceRequest;

		if (!(this->resourceArn.IsEmpty())) {
            awsUntagResourceRequest.SetResourceArn(TCHAR_TO_UTF8(*this->resourceArn));
        }

        for (const FString& elem : this->tagKeys) {
            awsUntagResourceRequest.AddTagKeys(TCHAR_TO_UTF8(*elem));
        }

        return awsUntagResourceRequest;
    }

    bool IsEmpty() const {
        return this->resourceArn.IsEmpty() && this->tagKeys.Num() == 0;
    }
#endif
};
