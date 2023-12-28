/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/GlobalTable.h"

#endif

#include "Model/Replica.h"

#include "GlobalTable.generated.h"

USTRUCT(BlueprintType)
struct FGlobalTable {
GENERATED_BODY()

    /**
    *  <p>The global table name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString globalTableName;

    /**
    *  <p>The regions where the global table has replicas.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplica> replicationGroup;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FGlobalTable &fromAWS(const Aws::DynamoDB::Model::GlobalTable &awsGlobalTable) {
        this->globalTableName = UTF8_TO_TCHAR(awsGlobalTable.GetGlobalTableName().c_str());

        this->replicationGroup.Empty();
        for (const Aws::DynamoDB::Model::Replica& elem : awsGlobalTable.GetReplicationGroup()) {
            this->replicationGroup.Add(FReplica().fromAWS(elem));
        }

        return *this;
    }
#endif
};
