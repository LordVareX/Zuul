/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListExportsRequest.h"

#endif

#include "AWSDynamoDBListExportsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBListExportsRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) associated with the exported table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableArn;

    /**
    *  <p>Maximum number of results to return per page.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int maxResults = 0;

    /**
    *  <p>An optional string that, if supplied, must be copied from the output of a previous call to <code>ListExports</code>. When provided in this manner, the API fetches the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString nextToken;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ListExportsRequest toAWS() const {
        Aws::DynamoDB::Model::ListExportsRequest awsListExportsRequest;

        if (!(this->tableArn.IsEmpty())) {
            awsListExportsRequest.SetTableArn(TCHAR_TO_UTF8(*this->tableArn));
        }

        if (!(this->maxResults == 0)) {
            awsListExportsRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListExportsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListExportsRequest;
    }

    bool IsEmpty() const {
        return this->tableArn.IsEmpty() && this->maxResults == 0 && this->nextToken.IsEmpty();
    }
#endif
};
