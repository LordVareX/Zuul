/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/UpdateTableReplicaAutoScalingResult.h"

#endif

#include "Model/TableAutoScalingDescription.h"

#include "UpdateTableReplicaAutoScalingResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateTableReplicaAutoScalingResult {
GENERATED_BODY()

    /**
    *  <p>Returns information about the auto scaling settings of a table with replicas.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTableAutoScalingDescription tableAutoScalingDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:

    FUpdateTableReplicaAutoScalingResult &fromAWS(const Aws::DynamoDB::Model::UpdateTableReplicaAutoScalingResult &awsUpdateTableReplicaAutoScalingResult) {
// @TODO: check
            this->tableAutoScalingDescription.fromAWS(awsUpdateTableReplicaAutoScalingResult.GetTableAutoScalingDescription());
        

        return *this;
    }
#endif
};
