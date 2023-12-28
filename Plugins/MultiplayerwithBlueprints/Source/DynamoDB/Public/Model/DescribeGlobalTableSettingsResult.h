/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeGlobalTableSettingsResult.h"

#endif

#include "Model/ReplicaSettingsDescription.h"

#include "DescribeGlobalTableSettingsResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeGlobalTableSettingsResult {
GENERATED_BODY()

    /**
    *  <p>The name of the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString globalTableName;

    /**
    *  <p>The Region-specific settings for the global table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FReplicaSettingsDescription> replicaSettings;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDescribeGlobalTableSettingsResult &fromAWS(const Aws::DynamoDB::Model::DescribeGlobalTableSettingsResult &awsDescribeGlobalTableSettingsResult) {
        this->globalTableName = UTF8_TO_TCHAR(awsDescribeGlobalTableSettingsResult.GetGlobalTableName().c_str());

        this->replicaSettings.Empty();
        for (const Aws::DynamoDB::Model::ReplicaSettingsDescription& elem : awsDescribeGlobalTableSettingsResult.GetReplicaSettings()) {
            this->replicaSettings.Add(FReplicaSettingsDescription().fromAWS(elem));
        }

        return *this;
    }
#endif
};
