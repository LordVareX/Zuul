/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListTablesRequest.h"

#endif

#include "ListTablesRequest.generated.h"

USTRUCT(BlueprintType)
struct FListTablesRequest {
GENERATED_BODY()

    /**
    *  <p>The first table name that this operation will evaluate. Use the value that was returned for <code>LastEvaluatedTableName</code> in a previous operation, so that you can obtain the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString exclusiveStartTableName;

    /**
    *  <p>A maximum number of table names to return. If this parameter is not specified, the limit is 100.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int limit = 0;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ListTablesRequest toAWS() const {
        Aws::DynamoDB::Model::ListTablesRequest awsListTablesRequest;

		if (!(this->exclusiveStartTableName.IsEmpty())) {
            awsListTablesRequest.SetExclusiveStartTableName(TCHAR_TO_UTF8(*this->exclusiveStartTableName));
        }

        if (this->limit != 0) {
            awsListTablesRequest.SetLimit(this->limit);
        }

        return awsListTablesRequest;
    }

    bool IsEmpty() const {
        return this->exclusiveStartTableName.IsEmpty() && this->limit == 0;
    }
#endif
};
