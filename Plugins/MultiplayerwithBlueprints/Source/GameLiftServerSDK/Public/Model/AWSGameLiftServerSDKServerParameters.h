/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2023
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT && WITH_GAMELIFT_5

#include "aws/gamelift/server/model/ServerParameters.h"

#endif

#include "AWSGameLiftServerSDKServerParameters.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftServerSDKServerParameters {
    GENERATED_BODY()

    //The WebSocket URL (from result of RegisterCompute Compute.GameLiftServiceSdkEndpoint or "http://127.0.0.1:5757" as default).
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString webSocketUrl;

    //The EC2 or Anywhere Fleet ID.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString fleetId;

    //The PID of the running process
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString processId;

    //The Host/Compute ID of the GameLift Anywhere instance. Normally should be same as ComputeName of RegisteredCompute
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString hostId;

    //AuthToken returned from the GameLift "GetComputeAuthToken" API. Note this will expire and require a new call to the API after 15 minutes.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString authToken;

#if WITH_GAMELIFT && WITH_GAMELIFT_5
    public:
    Aws::GameLift::Server::Model::ServerParameters toAWS() const {
        return Aws::GameLift::Server::Model::ServerParameters(this->webSocketUrl.IsEmpty() ? nullptr : TCHAR_TO_UTF8(*this->webSocketUrl), this->authToken.IsEmpty() ? nullptr : TCHAR_TO_UTF8(*this->authToken), this->fleetId.IsEmpty() ? nullptr : TCHAR_TO_UTF8(*this->fleetId), this->hostId.IsEmpty() ? nullptr : TCHAR_TO_UTF8(*this->hostId), this->processId.IsEmpty() ? nullptr : TCHAR_TO_UTF8(*this->processId));
    };

#endif
};