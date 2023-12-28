/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DeleteTableRequest.h"

#endif

#include "DeleteTableRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteTableRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DeleteTableRequest toAWS() const {
        Aws::DynamoDB::Model::DeleteTableRequest awsDeleteTableRequest;

		if (!(this->tableName.IsEmpty())) {
            awsDeleteTableRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        return awsDeleteTableRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty();
    }
#endif
};
