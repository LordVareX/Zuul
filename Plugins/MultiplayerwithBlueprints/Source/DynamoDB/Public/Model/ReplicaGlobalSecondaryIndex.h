/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaGlobalSecondaryIndex.h"

#endif

#include "Model/ProvisionedThroughputOverride.h"

#include "ReplicaGlobalSecondaryIndex.generated.h"

USTRUCT(BlueprintType)
struct FReplicaGlobalSecondaryIndex {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>Replica table GSI-specific provisioned throughput. If not specified, uses the source table GSI's read capacity settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughputOverride provisionedThroughputOverride;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndex toAWS() const {
        Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndex awsReplicaGlobalSecondaryIndex;

		if (!(this->indexName.IsEmpty())) {
            awsReplicaGlobalSecondaryIndex.SetIndexName(TCHAR_TO_UTF8(*this->indexName));
        }

        if (!(this->provisionedThroughputOverride.IsEmpty())) {
            awsReplicaGlobalSecondaryIndex.SetProvisionedThroughputOverride(this->provisionedThroughputOverride.toAWS());
        }

        return awsReplicaGlobalSecondaryIndex;
    }

    bool IsEmpty() const {
        return this->indexName.IsEmpty() && this->provisionedThroughputOverride.IsEmpty();
    }
#endif
};
