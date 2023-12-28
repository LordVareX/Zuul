/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeTableReplicaAutoScalingResult.h"

#endif

#include "Model/TableAutoScalingDescription.h"

#include "DescribeTableReplicaAutoScalingResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeTableReplicaAutoScalingResult {
GENERATED_BODY()

    /**
    *  <p>Represents the auto scaling properties of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTableAutoScalingDescription tableAutoScalingDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDescribeTableReplicaAutoScalingResult &fromAWS(const Aws::DynamoDB::Model::DescribeTableReplicaAutoScalingResult &awsDescribeTableReplicaAutoScalingResult) {
        this->tableAutoScalingDescription.fromAWS(awsDescribeTableReplicaAutoScalingResult.GetTableAutoScalingDescription());

        return *this;
    }
#endif
};
