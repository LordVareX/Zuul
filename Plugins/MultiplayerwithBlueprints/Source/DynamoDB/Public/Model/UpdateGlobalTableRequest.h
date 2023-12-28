/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateGlobalTableRequest.h"

#endif

#include "Model/ReplicaUpdate.h"

#include "UpdateGlobalTableRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGlobalTableRequest {
GENERATED_BODY()

    /**
    *  <p>The global table name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString globalTableName;

    /**
    *  <p>A list of Regions that should be added or removed from the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaUpdate> replicaUpdates;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::UpdateGlobalTableRequest toAWS() const {
        Aws::DynamoDB::Model::UpdateGlobalTableRequest awsUpdateGlobalTableRequest;

		if (!(this->globalTableName.IsEmpty())) {
            awsUpdateGlobalTableRequest.SetGlobalTableName(TCHAR_TO_UTF8(*this->globalTableName));
        }

        for (const FReplicaUpdate& elem : this->replicaUpdates) {
            awsUpdateGlobalTableRequest.AddReplicaUpdates(elem.toAWS());
        }

        return awsUpdateGlobalTableRequest;
    }

    bool IsEmpty() const {
        return this->globalTableName.IsEmpty() && this->replicaUpdates.Num() == 0;
    }
#endif
};
