/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/AutoScalingPolicyUpdate.h"

#endif

#include "Model/AutoScalingTargetTrackingScalingPolicyConfigurationUpdate.h"

#include "AutoScalingPolicyUpdate.generated.h"

USTRUCT(BlueprintType)
struct FAutoScalingPolicyUpdate {
GENERATED_BODY()

    /**
    *  <p>The name of the scaling policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString policyName;

    /**
    *  <p>Represents a target tracking scaling policy configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingTargetTrackingScalingPolicyConfigurationUpdate targetTrackingScalingPolicyConfiguration;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::AutoScalingPolicyUpdate toAWS() const {
        Aws::DynamoDB::Model::AutoScalingPolicyUpdate awsAutoScalingPolicyUpdate;

		if (!(this->policyName.IsEmpty())) {
            awsAutoScalingPolicyUpdate.SetPolicyName(TCHAR_TO_UTF8(*this->policyName));
        }

        if (!(this->targetTrackingScalingPolicyConfiguration.IsEmpty())) {
            awsAutoScalingPolicyUpdate.SetTargetTrackingScalingPolicyConfiguration(this->targetTrackingScalingPolicyConfiguration.toAWS());
        }

        return awsAutoScalingPolicyUpdate;
    }

    bool IsEmpty() const {
        return this->policyName.IsEmpty() && this->targetTrackingScalingPolicyConfiguration.IsEmpty();
    }
#endif
};
