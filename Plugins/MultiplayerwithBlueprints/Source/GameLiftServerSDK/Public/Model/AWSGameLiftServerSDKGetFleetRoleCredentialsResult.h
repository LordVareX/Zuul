/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFT && WITH_GAMELIFT_5

#include "aws/gamelift/server/model/GetFleetRoleCredentialsResult.h"

#endif

#include "AWSGameLiftServerSDKGetFleetRoleCredentialsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftServerSDKGetFleetRoleCredentialsResult {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString assumedUserRoleArn;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString assumedRoleId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString accessKeyId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString secretAccessKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FString sessionToken;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Game Lift Server")
    FDateTime expiration;

#if WITH_GAMELIFT && WITH_GAMELIFT_5
    public:
    FAWSGameLiftServerSDKGetFleetRoleCredentialsResult& fromAWS(const Aws::GameLift::Server::Model::GetFleetRoleCredentialsResult& awsGetFleetRoleCredentialsResult) {
        this->assumedUserRoleArn = awsGetFleetRoleCredentialsResult.GetAssumedUserRoleArn();

        this->assumedRoleId = awsGetFleetRoleCredentialsResult.GetAssumedRoleId();

        this->accessKeyId = awsGetFleetRoleCredentialsResult.GetAccessKeyId();

        this->secretAccessKey = awsGetFleetRoleCredentialsResult.GetSecretAccessKey();

        this->sessionToken = awsGetFleetRoleCredentialsResult.GetSessionToken();

        this->expiration = FDateTime(1970, 1, 1) + FTimespan(std::difftime(awsGetFleetRoleCredentialsResult.GetExpiration(), 0) * ETimespan::TicksPerSecond);

        return *this;
    };

#endif
};