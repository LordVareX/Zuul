/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeComputeRequest.h"

#endif

#include "AWSGameLiftDescribeComputeRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDescribeComputeRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet the compute is registered to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>A descriptive label that is associated with the compute resource registered to your fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeName;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DescribeComputeRequest toAWS() const {
        Aws::GameLift::Model::DescribeComputeRequest awsDescribeComputeRequest;

		if (!(this->fleetId.IsEmpty())) {
            awsDescribeComputeRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

		if (!(this->computeName.IsEmpty())) {
            awsDescribeComputeRequest.SetComputeName(TCHAR_TO_UTF8(*this->computeName));
        }

        return awsDescribeComputeRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->computeName.IsEmpty();
    }
#endif
};
