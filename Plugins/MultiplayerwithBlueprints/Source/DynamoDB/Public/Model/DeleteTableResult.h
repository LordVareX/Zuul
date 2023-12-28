/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DeleteTableResult.h"

#endif

#include "Model/TableDescription.h"

#include "DeleteTableResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteTableResult {
GENERATED_BODY()

    /**
    *  <p>Represents the properties of a table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTableDescription tableDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDeleteTableResult &fromAWS(const Aws::DynamoDB::Model::DeleteTableResult &awsDeleteTableResult) {
        this->tableDescription.fromAWS(awsDeleteTableResult.GetTableDescription());

        return *this;
    }
#endif
};
