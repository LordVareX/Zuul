/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/CreateGlobalTableResult.h"

#endif

#include "Model/GlobalTableDescription.h"

#include "CreateGlobalTableResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateGlobalTableResult {
GENERATED_BODY()

    /**
    *  <p>Contains the details of the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FGlobalTableDescription globalTableDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FCreateGlobalTableResult &fromAWS(const Aws::DynamoDB::Model::CreateGlobalTableResult &awsCreateGlobalTableResult) {
        this->globalTableDescription.fromAWS(awsCreateGlobalTableResult.GetGlobalTableDescription());

        return *this;
    }
#endif
};
