/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/AutoScalingPolicyDescription.h"

#endif

#include "Model/AutoScalingTargetTrackingScalingPolicyConfigurationDescription.h"

#include "AutoScalingPolicyDescription.generated.h"

USTRUCT(BlueprintType)
struct FAutoScalingPolicyDescription {
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
    FAutoScalingTargetTrackingScalingPolicyConfigurationDescription targetTrackingScalingPolicyConfiguration;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAutoScalingPolicyDescription &fromAWS(const Aws::DynamoDB::Model::AutoScalingPolicyDescription &awsAutoScalingPolicyDescription) {
        this->policyName = UTF8_TO_TCHAR(awsAutoScalingPolicyDescription.GetPolicyName().c_str());

        this->targetTrackingScalingPolicyConfiguration.fromAWS(awsAutoScalingPolicyDescription.GetTargetTrackingScalingPolicyConfiguration());

        return *this;
    }
#endif
};
