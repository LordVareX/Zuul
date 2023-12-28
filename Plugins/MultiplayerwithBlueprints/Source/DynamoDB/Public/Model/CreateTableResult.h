/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/CreateTableResult.h"

#endif

#include "Model/TableDescription.h"

#include "CreateTableResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateTableResult {
GENERATED_BODY()

    /**
    *  <p>Represents the properties of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTableDescription tableDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FCreateTableResult &fromAWS(const Aws::DynamoDB::Model::CreateTableResult &awsCreateTableResult) {
        this->tableDescription.fromAWS(awsCreateTableResult.GetTableDescription());

        return *this;
    }
#endif
};
