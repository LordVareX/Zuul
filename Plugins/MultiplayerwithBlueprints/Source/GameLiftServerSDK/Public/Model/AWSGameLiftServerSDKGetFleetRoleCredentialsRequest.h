/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT && WITH_GAMELIFT_5

#include "aws/gamelift/server/model/GetFleetRoleCredentialsRequest.h"

#endif

#include "AWSGameLiftServerSDKGetFleetRoleCredentialsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftServerSDKGetFleetRoleCredentialsRequest {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString roleArn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString roleSessionName;

#if WITH_GAMELIFT && WITH_GAMELIFT_5
    public:
    Aws::GameLift::Server::Model::GetFleetRoleCredentialsRequest toAWS() const {
        return Aws::GameLift::Server::Model::GetFleetRoleCredentialsRequest().WithRoleArn(TCHAR_TO_UTF8(*this->roleArn)).WithRoleSessionName(TCHAR_TO_UTF8(*this->roleSessionName));
    };

#endif
};