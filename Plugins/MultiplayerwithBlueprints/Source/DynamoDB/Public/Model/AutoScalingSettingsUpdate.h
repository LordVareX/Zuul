/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/AutoScalingSettingsUpdate.h"

#endif

#include "Model/AutoScalingPolicyUpdate.h"

#include "AutoScalingSettingsUpdate.generated.h"

USTRUCT(BlueprintType)
struct FAutoScalingSettingsUpdate {
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
    *  <p>Role ARN used for configuring autoscaling policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString autoScalingRoleArn;

    /**
    *  <p>The scaling policy to apply for scaling target global table or global secondary index capacity units.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FAutoScalingPolicyUpdate scalingPolicyUpdate;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::AutoScalingSettingsUpdate toAWS() const {
        Aws::DynamoDB::Model::AutoScalingSettingsUpdate awsAutoScalingSettingsUpdate;

        if (this->minimumUnits != 0) {
            awsAutoScalingSettingsUpdate.SetMinimumUnits(this->minimumUnits);
        }

        if (this->maximumUnits != 0) {
            awsAutoScalingSettingsUpdate.SetMaximumUnits(this->maximumUnits);
        }

        awsAutoScalingSettingsUpdate.SetAutoScalingDisabled(this->autoScalingDisabled);

		if (!(this->autoScalingRoleArn.IsEmpty())) {
            awsAutoScalingSettingsUpdate.SetAutoScalingRoleArn(TCHAR_TO_UTF8(*this->autoScalingRoleArn));
        }

        if (!(this->scalingPolicyUpdate.IsEmpty())) {
            awsAutoScalingSettingsUpdate.SetScalingPolicyUpdate(this->scalingPolicyUpdate.toAWS());
        }

        return awsAutoScalingSettingsUpdate;
    }

    bool IsEmpty() const {
        return this->minimumUnits == 0 && this->maximumUnits == 0 && false && this->autoScalingRoleArn.IsEmpty() && this->scalingPolicyUpdate.IsEmpty();
    }
#endif
};
