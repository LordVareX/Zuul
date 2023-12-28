/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GetComputeAuthTokenRequest.h"

#endif

#include "AWSGameLiftGetComputeAuthTokenRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftGetComputeAuthTokenRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet that the compute is registered to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The name of the compute resource you are requesting the authorization token for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeName;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::GetComputeAuthTokenRequest toAWS() const {
        Aws::GameLift::Model::GetComputeAuthTokenRequest awsGetComputeAuthTokenRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsGetComputeAuthTokenRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->computeName.IsEmpty())) {
            awsGetComputeAuthTokenRequest.SetComputeName(TCHAR_TO_UTF8(*this->computeName));
        }

        return awsGetComputeAuthTokenRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->computeName.IsEmpty();
    }
#endif
};
