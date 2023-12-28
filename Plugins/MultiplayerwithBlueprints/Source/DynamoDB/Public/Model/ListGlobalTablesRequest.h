/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListGlobalTablesRequest.h"

#endif

#include "ListGlobalTablesRequest.generated.h"

USTRUCT(BlueprintType)
struct FListGlobalTablesRequest {
GENERATED_BODY()

    /**
    *  <p>The first global table name that this operation will evaluate.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString exclusiveStartGlobalTableName;

    /**
    *  <p>The maximum number of table names to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int limit = 0;

    /**
    *  <p>Lists the global tables in a specific Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString regionName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ListGlobalTablesRequest toAWS() const {
        Aws::DynamoDB::Model::ListGlobalTablesRequest awsListGlobalTablesRequest;

		if (!(this->exclusiveStartGlobalTableName.IsEmpty())) {
            awsListGlobalTablesRequest.SetExclusiveStartGlobalTableName(TCHAR_TO_UTF8(*this->exclusiveStartGlobalTableName));
        }

        if (this->limit != 0) {
            awsListGlobalTablesRequest.SetLimit(this->limit);
        }

		if (!(this->regionName.IsEmpty())) {
            awsListGlobalTablesRequest.SetRegionName(TCHAR_TO_UTF8(*this->regionName));
        }

        return awsListGlobalTablesRequest;
    }

    bool IsEmpty() const {
        return this->exclusiveStartGlobalTableName.IsEmpty() && this->limit == 0 && this->regionName.IsEmpty();
    }
#endif
};
