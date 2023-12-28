/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DeleteGlobalSecondaryIndexAction.h"

#endif

#include "DeleteGlobalSecondaryIndexAction.generated.h"

USTRUCT(BlueprintType)
struct FDeleteGlobalSecondaryIndexAction {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index to be deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DeleteGlobalSecondaryIndexAction toAWS() const {
        Aws::DynamoDB::Model::DeleteGlobalSecondaryIndexAction awsDeleteGlobalSecondaryIndexAction;

		if (!(this->indexName.IsEmpty())) {
            awsDeleteGlobalSecondaryIndexAction.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        return awsDeleteGlobalSecondaryIndexAction;
    }

    bool IsEmpty() const {
        return this->indexName.IsEmpty();
    }
#endif
};
