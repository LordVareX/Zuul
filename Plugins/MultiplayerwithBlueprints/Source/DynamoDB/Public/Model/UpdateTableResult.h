/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateTableResult.h"

#endif

#include "Model/TableDescription.h"

#include "UpdateTableResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateTableResult {
GENERATED_BODY()

    /**
    *  <p>Represents the properties of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTableDescription tableDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FUpdateTableResult &fromAWS(const Aws::DynamoDB::Model::UpdateTableResult &awsUpdateTableResult) {
        this->tableDescription.fromAWS(awsUpdateTableResult.GetTableDescription());

        return *this;
    }
#endif
};
