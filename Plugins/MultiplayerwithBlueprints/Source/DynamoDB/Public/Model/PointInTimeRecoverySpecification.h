/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/PointInTimeRecoverySpecification.h"

#endif

#include "PointInTimeRecoverySpecification.generated.h"

USTRUCT(BlueprintType)
struct FPointInTimeRecoverySpecification {
GENERATED_BODY()

    /**
    *  <p>Indicates whether point in time recovery is enabled (true) or disabled (false) on the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool pointInTimeRecoveryEnabled = false;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::PointInTimeRecoverySpecification toAWS() const {
        Aws::DynamoDB::Model::PointInTimeRecoverySpecification awsPointInTimeRecoverySpecification;

        awsPointInTimeRecoverySpecification.SetPointInTimeRecoveryEnabled(this->pointInTimeRecoveryEnabled);

        return awsPointInTimeRecoverySpecification;
    }

    bool IsEmpty() const {
        return false;
    }
#endif
};
