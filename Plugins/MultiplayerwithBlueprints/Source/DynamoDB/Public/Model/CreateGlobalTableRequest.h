/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/CreateGlobalTableRequest.h"

#endif

#include "Model/Replica.h"

#include "CreateGlobalTableRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateGlobalTableRequest {
GENERATED_BODY()

    /**
    *  <p>The global table name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString globalTableName;

    /**
    *  <p>The Regions where the global table needs to be created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplica> replicationGroup;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::CreateGlobalTableRequest toAWS() const {
        Aws::DynamoDB::Model::CreateGlobalTableRequest awsCreateGlobalTableRequest;

		if (!(this->globalTableName.IsEmpty())) {
            awsCreateGlobalTableRequest.SetGlobalTableName(TCHAR_TO_UTF8(*this->globalTableName));
        }

        for (const FReplica& elem : this->replicationGroup) {
            awsCreateGlobalTableRequest.AddReplicationGroup(elem.toAWS());
        }

        return awsCreateGlobalTableRequest;
    }

    bool IsEmpty() const {
        return this->globalTableName.IsEmpty() && this->replicationGroup.Num() == 0;
    }
#endif
};
