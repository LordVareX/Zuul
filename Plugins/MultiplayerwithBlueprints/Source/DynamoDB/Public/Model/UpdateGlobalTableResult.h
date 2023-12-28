/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateGlobalTableResult.h"

#endif

#include "Model/GlobalTableDescription.h"

#include "UpdateGlobalTableResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGlobalTableResult {
GENERATED_BODY()

    /**
    *  <p>Contains the details of the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FGlobalTableDescription globalTableDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FUpdateGlobalTableResult &fromAWS(const Aws::DynamoDB::Model::UpdateGlobalTableResult &awsUpdateGlobalTableResult) {
        this->globalTableDescription.fromAWS(awsUpdateGlobalTableResult.GetGlobalTableDescription());

        return *this;
    }
#endif
};
