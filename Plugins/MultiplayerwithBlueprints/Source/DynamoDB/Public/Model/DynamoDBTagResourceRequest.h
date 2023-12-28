/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/TagResourceRequest.h"

#endif

#include "Model/DynamoDBTag.h"

#include "DynamoDBTagResourceRequest.generated.h"

USTRUCT(BlueprintType)
struct FDynamoDBTagResourceRequest {
GENERATED_BODY()

    /**
    *  <p>Identifies the Amazon DynamoDB resource to which tags should be added. This value is an Amazon Resource Name (ARN).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString resourceArn;

    /**
    *  <p>The tags to be assigned to the Amazon DynamoDB resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBTag> tags;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::TagResourceRequest toAWS() const {
        Aws::DynamoDB::Model::TagResourceRequest awsTagResourceRequest;

		if (!(this->resourceArn.IsEmpty())) {
            awsTagResourceRequest.SetResourceArn(TCHAR_TO_UTF8(*this->resourceArn));
        }

        for (const FDynamoDBTag& elem : this->tags) {
            awsTagResourceRequest.AddTags(elem.toAWS());
        }

        return awsTagResourceRequest;
    }

    bool IsEmpty() const {
        return this->resourceArn.IsEmpty() && this->tags.Num() == 0;
    }
#endif
};
