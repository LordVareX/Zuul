/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeTableReplicaAutoScalingRequest.h"

#endif

#include "DescribeTableReplicaAutoScalingRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeTableReplicaAutoScalingRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeTableReplicaAutoScalingRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeTableReplicaAutoScalingRequest awsDescribeTableReplicaAutoScalingRequest;

		if (!(this->tableName.IsEmpty())) {
            awsDescribeTableReplicaAutoScalingRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        return awsDescribeTableReplicaAutoScalingRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty();
    }
#endif
};
