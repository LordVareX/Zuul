/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#if WITH_GAMELIFT

#include "aws/gamelift/server/model/GameSessionStatus.h"
#include "aws/gamelift/server/model/GameProperty.h"
#include "aws/gamelift/server/model/GameSession.h"
#include "aws/gamelift/server/model/UpdateReason.h"
#include "aws/gamelift/server/model/UpdateGameSession.h"

#include "aws/gamelift/server/LogParameters.h"
#include "aws/gamelift/server/ProcessParameters.h"

#endif

#include "Model/AWSGameSessionServer.h"
#include "Model/UpdateGameSessionServer.h"

#include "ProcessParameters.generated.h"

UCLASS(Blueprintable)
class GAMELIFTSERVERSDK_API UProcessParameters : public UObject {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server", Meta = (ExposeOnSpawn = true))
    int port;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Lift Server", Meta = (ExposeOnSpawn = true))
    TArray<FString> logPaths;

    UFUNCTION(BlueprintNativeEvent, Category = "Game Lift Server")
    void StartGameSession(FAWSGameSessionServer gameSession);

    UFUNCTION(BlueprintNativeEvent, Category = "Game Lift Server")
    void UpdateGameSession(FUpdateGameSessionServer updateGameSession);

    UFUNCTION(BlueprintNativeEvent, Category = "Game Lift Server")
    void ProcessTerminate();

    UFUNCTION(BlueprintNativeEvent, Category = "Game Lift Server")
    bool HealthCheck();

#if WITH_GAMELIFT
    Aws::GameLift::Server::ProcessParameters toAWS() const;

#endif
};
