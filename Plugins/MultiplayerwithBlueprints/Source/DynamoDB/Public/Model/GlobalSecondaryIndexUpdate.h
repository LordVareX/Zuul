/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/GlobalSecondaryIndexUpdate.h"

#endif

#include "Model/UpdateGlobalSecondaryIndexAction.h"
#include "Model/CreateGlobalSecondaryIndexAction.h"
#include "Model/DeleteGlobalSecondaryIndexAction.h"

#include "GlobalSecondaryIndexUpdate.generated.h"

USTRUCT(BlueprintType)
struct FGlobalSecondaryIndexUpdate {
GENERATED_BODY()

    /**
    *  <p>The name of an existing global secondary index, along with new provisioned throughput settings to be applied to that index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FUpdateGlobalSecondaryIndexAction updateGlobalSecondaryIndexAction;

    /**
    *  <p>The parameters required for creating a global secondary index on an existing table:</p> <ul> <li> <p> <code>IndexName </code> </p> </li> <li> <p> <code>KeySchema </code> </p> </li> <li> <p> <code>AttributeDefinitions </code> </p> </li> <li> <p> <code>Projection </code> </p> </li> <li> <p> <code>ProvisionedThroughput </code> </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FCreateGlobalSecondaryIndexAction createGlobalSecondaryIndexAction;

    /**
    *  <p>The name of an existing global secondary index to be removed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDeleteGlobalSecondaryIndexAction deleteGlobalSecondaryIndexAction;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::GlobalSecondaryIndexUpdate toAWS() const {
        Aws::DynamoDB::Model::GlobalSecondaryIndexUpdate awsGlobalSecondaryIndexUpdate;

        if (!(this->updateGlobalSecondaryIndexAction.IsEmpty())) {
            awsGlobalSecondaryIndexUpdate.SetUpdate(this->updateGlobalSecondaryIndexAction.toAWS());
        }

        if (!(this->createGlobalSecondaryIndexAction.IsEmpty())) {
            awsGlobalSecondaryIndexUpdate.SetCreate(this->createGlobalSecondaryIndexAction.toAWS());
        }

        if (!(this->deleteGlobalSecondaryIndexAction.IsEmpty())) {
            awsGlobalSecondaryIndexUpdate.SetDelete(this->deleteGlobalSecondaryIndexAction.toAWS());
        }

        return awsGlobalSecondaryIndexUpdate;
    }

    bool IsEmpty() const {
        return this->updateGlobalSecondaryIndexAction.IsEmpty() && this->createGlobalSecondaryIndexAction.IsEmpty() && this->deleteGlobalSecondaryIndexAction.IsEmpty();
    }
#endif
};
