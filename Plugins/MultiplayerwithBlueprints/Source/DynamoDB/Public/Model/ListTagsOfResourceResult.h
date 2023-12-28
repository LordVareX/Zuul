/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListTagsOfResourceResult.h"

#endif

#include "Model/DynamoDBTag.h"

#include "ListTagsOfResourceResult.generated.h"

USTRUCT(BlueprintType)
struct FListTagsOfResourceResult {
GENERATED_BODY()

    /**
    *  <p>The tags currently associated with the Amazon DynamoDB resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FDynamoDBTag> tags;

    /**
    *  <p>If this value is returned, there are additional results to be displayed. To retrieve them, call ListTagsOfResource again, with NextToken set to this value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FListTagsOfResourceResult &fromAWS(const Aws::DynamoDB::Model::ListTagsOfResourceResult &awsListTagsOfResourceResult) {
        this->tags.Empty();
        for (const Aws::DynamoDB::Model::Tag& elem : awsListTagsOfResourceResult.GetTags()) {
            this->tags.Add(FDynamoDBTag().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListTagsOfResourceResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
