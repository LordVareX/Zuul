/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/AutoScalingTargetTrackingScalingPolicyConfigurationUpdate.h"

#endif

#include "AutoScalingTargetTrackingScalingPolicyConfigurationUpdate.generated.h"

USTRUCT(BlueprintType)
struct FAutoScalingTargetTrackingScalingPolicyConfigurationUpdate {
GENERATED_BODY()

    /**
    *  <p>Indicates whether scale in by the target tracking policy is disabled. If the value is true, scale in is disabled and the target tracking policy won't remove capacity from the scalable resource. Otherwise, scale in is enabled and the target tracking policy can remove capacity from the scalable resource. The default value is false.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool disableScaleIn = false;

    /**
    *  <p>The amount of time, in seconds, after a scale in activity completes before another scale in activity can start. The cooldown period is used to block subsequent scale in requests until it has expired. You should scale in conservatively to protect your application's availability. However, if another alarm triggers a scale out policy during the cooldown period after a scale-in, application autoscaling scales out your scalable target immediately. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int scaleInCooldown = 0;

    /**
    *  <p>The amount of time, in seconds, after a scale out activity completes before another scale out activity can start. While the cooldown period is in effect, the capacity that has been added by the previous scale out event that initiated the cooldown is calculated as part of the desired capacity for the next scale out. You should continuously (but not excessively) scale out.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int scaleOutCooldown = 0;

    /**
    *  <p>The target value for the metric. The range is 8.515920e-109 to 1.174271e+108 (Base 10) or 2e-360 to 2e360 (Base 2).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    float targetValue = 0.0f;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::AutoScalingTargetTrackingScalingPolicyConfigurationUpdate toAWS() const {
        Aws::DynamoDB::Model::AutoScalingTargetTrackingScalingPolicyConfigurationUpdate awsAutoScalingTargetTrackingScalingPolicyConfigurationUpdate;

        awsAutoScalingTargetTrackingScalingPolicyConfigurationUpdate.SetDisableScaleIn(this->disableScaleIn);

        if (this->scaleInCooldown != 0) {
            awsAutoScalingTargetTrackingScalingPolicyConfigurationUpdate.SetScaleInCooldown(this->scaleInCooldown);
        }

        if (this->scaleOutCooldown != 0) {
            awsAutoScalingTargetTrackingScalingPolicyConfigurationUpdate.SetScaleOutCooldown(this->scaleOutCooldown);
        }

        if (this->targetValue >= (2.0 * pow(2.0, -360)) && this->targetValue <= (2.0 * pow(2.0, 360))) {
            awsAutoScalingTargetTrackingScalingPolicyConfigurationUpdate.SetTargetValue(this->targetValue);
        }

        return awsAutoScalingTargetTrackingScalingPolicyConfigurationUpdate;
    }

    bool IsEmpty() const {
        return false && this->scaleInCooldown == 0 && this->scaleOutCooldown == 0 && !(this->targetValue >= (2.0 * pow(2.0, -360)) && this->targetValue <= (2.0 * pow(2.0, 360)));
    }
#endif
};
