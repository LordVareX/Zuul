/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateGlobalTableSettingsResult.h"

#endif

#include "Model/ReplicaSettingsDescription.h"

#include "UpdateGlobalTableSettingsResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateGlobalTableSettingsResult {
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
    FUpdateGlobalTableSettingsResult &fromAWS(const Aws::DynamoDB::Model::UpdateGlobalTableSettingsResult &awsUpdateGlobalTableSettingsResult) {
        this->globalTableName = UTF8_TO_TCHAR(awsUpdateGlobalTableSettingsResult.GetGlobalTableName().c_str());

        this->replicaSettings.Empty();
        for (const Aws::DynamoDB::Model::ReplicaSettingsDescription& elem : awsUpdateGlobalTableSettingsResult.GetReplicaSettings()) {
            this->replicaSettings.Add(FReplicaSettingsDescription().fromAWS(elem));
        }

        return *this;
    }
#endif
};
