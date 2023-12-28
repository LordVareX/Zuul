/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GetComputeAccessRequest.h"

#endif

#include "AWSGameLiftGetComputeAccessRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftGetComputeAccessRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet that the compute resource is registered to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The name of the compute resource you are requesting credentials for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeName;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::GetComputeAccessRequest toAWS() const {
        Aws::GameLift::Model::GetComputeAccessRequest awsGetComputeAccessRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsGetComputeAccessRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->computeName.IsEmpty())) {
            awsGetComputeAccessRequest.SetComputeName(TCHAR_TO_UTF8(*this->computeName));
        }

        return awsGetComputeAccessRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->computeName.IsEmpty();
    }
#endif
};
