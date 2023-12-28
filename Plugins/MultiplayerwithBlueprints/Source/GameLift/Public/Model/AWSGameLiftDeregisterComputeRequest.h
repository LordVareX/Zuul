/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeregisterComputeRequest.h"

#endif

#include "AWSGameLiftDeregisterComputeRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDeregisterComputeRequest {
GENERATED_BODY()

    /**
    *  <p>&gt;A unique identifier for the fleet the compute resource is registered to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The name of the compute resource you want to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeName;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeregisterComputeRequest toAWS() const {
        Aws::GameLift::Model::DeregisterComputeRequest awsDeregisterComputeRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsDeregisterComputeRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->computeName.IsEmpty())) {
            awsDeregisterComputeRequest.SetComputeName(TCHAR_TO_UTF8(*this->computeName));
        }

        return awsDeregisterComputeRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->computeName.IsEmpty();
    }
#endif
};
