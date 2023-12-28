/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ReplicaGlobalSecondaryIndexDescription.h"

#endif

#include "Model/ProvisionedThroughputOverride.h"

#include "ReplicaGlobalSecondaryIndexDescription.generated.h"

USTRUCT(BlueprintType)
struct FReplicaGlobalSecondaryIndexDescription {
GENERATED_BODY()

    /**
    *  <p>The name of the global secondary index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString indexName;

    /**
    *  <p>If not described, uses the source table GSI's read capacity settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FProvisionedThroughputOverride provisionedThroughputOverride;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FReplicaGlobalSecondaryIndexDescription &fromAWS(const Aws::DynamoDB::Model::ReplicaGlobalSecondaryIndexDescription &awsReplicaGlobalSecondaryIndexDescription) {
        this->indexName = UTF8_TO_TCHAR(awsReplicaGlobalSecondaryIndexDescription.GetIndexName().c_str());

        this->provisionedThroughputOverride.fromAWS(awsReplicaGlobalSecondaryIndexDescription.GetProvisionedThroughputOverride());

        return *this;
    }
#endif
};
