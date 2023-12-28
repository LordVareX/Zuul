/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicationGroupUpdate.h"

#endif

#include "Model/CreateReplicationGroupMemberAction.h"
#include "Model/UpdateReplicationGroupMemberAction.h"
#include "Model/DeleteReplicationGroupMemberAction.h"

#include "ReplicationGroupUpdate.generated.h"

USTRUCT(BlueprintType)
struct FReplicationGroupUpdate {
GENERATED_BODY()

    /**
    *  <p>The parameters required for creating a replica for the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FCreateReplicationGroupMemberAction createAction;

    /**
    *  <p>The parameters required for updating a replica for the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FUpdateReplicationGroupMemberAction updateAction;

    /**
    *  <p>The parameters required for deleting a replica for the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDeleteReplicationGroupMemberAction deleteAction;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ReplicationGroupUpdate toAWS() const {
        Aws::DynamoDB::Model::ReplicationGroupUpdate awsReplicationGroupUpdate;

        if (!(this->createAction.IsEmpty())) {
            awsReplicationGroupUpdate.SetCreate(this->createAction.toAWS());
        }

        if (!(this->updateAction.IsEmpty())) {
            awsReplicationGroupUpdate.SetUpdate(this->updateAction.toAWS());
        }

        if (!(this->deleteAction.IsEmpty())) {
            awsReplicationGroupUpdate.SetDelete(this->deleteAction.toAWS());
        }

        return awsReplicationGroupUpdate;
    }

    bool IsEmpty() const {
        return this->createAction.IsEmpty() && this->updateAction.IsEmpty() && this->deleteAction.IsEmpty();
    }
#endif
};
