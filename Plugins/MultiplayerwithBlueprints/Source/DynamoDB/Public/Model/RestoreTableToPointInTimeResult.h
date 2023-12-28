/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/RestoreTableToPointInTimeResult.h"

#endif

#include "Model/TableDescription.h"

#include "RestoreTableToPointInTimeResult.generated.h"

USTRUCT(BlueprintType)
struct FRestoreTableToPointInTimeResult {
GENERATED_BODY()

    /**
    *  <p>Represents the properties of a table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTableDescription tableDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FRestoreTableToPointInTimeResult &fromAWS(const Aws::DynamoDB::Model::RestoreTableToPointInTimeResult &awsRestoreTableToPointInTimeResult) {
        this->tableDescription.fromAWS(awsRestoreTableToPointInTimeResult.GetTableDescription());

        return *this;
    }
#endif
};
