/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/AutoScalingSettingsDescription.h"

#endif

#include "Model/AutoScalingPolicyDescription.h"

#include "AutoScalingSettingsDescription.generated.h"

USTRUCT(BlueprintType)
struct FAutoScalingSettingsDescription {
GENERATED_BODY()

    /**
    *  <p>The minimum capacity units that a global table or global secondary index should be scaled down to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 minimumUnits = 0;

    /**
    *  <p>The maximum capacity units that a global table or global secondary index should be scaled up to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 maximumUnits = 0;

    /**
    *  <p>Disabled autoscaling for this global table or global secondary index.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool autoScalingDisabled = false;

    /**
    *  <p>Role ARN used for configuring autoScaling policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString autoScalingRoleArn;

    /**
    *  <p>Information about the scaling policies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAutoScalingPolicyDescription> scalingPolicies;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAutoScalingSettingsDescription &fromAWS(const Aws::DynamoDB::Model::AutoScalingSettingsDescription &awsAutoScalingSettingsDescription) {
        this->minimumUnits = (int64)awsAutoScalingSettingsDescription.GetMinimumUnits();

        this->maximumUnits = (int64)awsAutoScalingSettingsDescription.GetMaximumUnits();

        this->autoScalingDisabled = awsAutoScalingSettingsDescription.GetAutoScalingDisabled();

        this->autoScalingRoleArn = UTF8_TO_TCHAR(awsAutoScalingSettingsDescription.GetAutoScalingRoleArn().c_str());

        this->scalingPolicies.Empty();
        for (const Aws::DynamoDB::Model::AutoScalingPolicyDescription& elem : awsAutoScalingSettingsDescription.GetScalingPolicies()) {
            this->scalingPolicies.Add(FAutoScalingPolicyDescription().fromAWS(elem));
        }

        return *this;
    }
#endif
};
