/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListImportsRequest.h"

#endif

#include "AWSDynamoDBListImportsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBListImportsRequest {
GENERATED_BODY()

    /**
    *  <p> The Amazon Resource Name (ARN) associated with the table that was imported to. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableArn;

    /**
    *  <p> The number of <code>ImportSummary </code>objects returned in a single page. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int pageSize = 0;

    /**
    *  <p> An optional string that, if supplied, must be copied from the output of a previous call to <code>ListImports</code>. When provided in this manner, the API fetches the next page of results. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ListImportsRequest toAWS() const {
        Aws::DynamoDB::Model::ListImportsRequest awsListImportsRequest;

        if (!(this->tableArn.IsEmpty())) {
            awsListImportsRequest.SetTableArn(TCHAR_TO_UTF8(*this->tableArn));
        }

        if (!(this->pageSize == 0)) {
            awsListImportsRequest.SetPageSize(this->pageSize);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListImportsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListImportsRequest;
    }

    bool IsEmpty() const {
        return this->tableArn.IsEmpty() && this->pageSize == 0 && this->nextToken.IsEmpty();
    }
#endif
};
