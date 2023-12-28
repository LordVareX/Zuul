/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaUpdate.h"

#endif

#include "Model/CreateReplicaAction.h"
#include "Model/DeleteReplicaAction.h"

#include "ReplicaUpdate.generated.h"

USTRUCT(BlueprintType)
struct FReplicaUpdate {
GENERATED_BODY()

    /**
    *  <p>The parameters required for creating a replica on an existing global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FCreateReplicaAction create;

    /**
    *  <p>The name of the existing replica to be removed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDeleteReplicaAction deleteReplicaAction;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ReplicaUpdate toAWS() const {
        Aws::DynamoDB::Model::ReplicaUpdate awsReplicaUpdate;

        if (!(this->create.IsEmpty())) {
            awsReplicaUpdate.SetCreate(this->create.toAWS());
        }

        if (!(this->deleteReplicaAction.IsEmpty())) {
            awsReplicaUpdate.SetDelete(this->deleteReplicaAction.toAWS());
        }

        return awsReplicaUpdate;
    }

    bool IsEmpty() const {
        return this->create.IsEmpty() && this->deleteReplicaAction.IsEmpty();
    }
#endif
};
