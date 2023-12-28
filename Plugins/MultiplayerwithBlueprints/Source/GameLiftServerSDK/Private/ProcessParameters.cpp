/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "ProcessParameters.h"
#include "GameLiftServerFunctionLibrary.h"

#include "GenericPlatform/GenericPlatformMemory.h"

void UProcessParameters::StartGameSession_Implementation(FAWSGameSessionServer gameSession) {
    bool success = false;
    EGameLiftServerError errorType;
    FString errorMessage;
    UGameLiftServerFunctionLibrary::ActivateGameSession(success, errorType, errorMessage);
}

void UProcessParameters::UpdateGameSession_Implementation(FUpdateGameSessionServer updateGameSession) {

}

void UProcessParameters::ProcessTerminate_Implementation() {
    bool success = false;
    EGameLiftServerError errorType;
    FString errorMessage;
    UGameLiftServerFunctionLibrary::ProcessEnding(success, errorType, errorMessage);

    FGenericPlatformMisc::RequestExit(false);
}

bool UProcessParameters::HealthCheck_Implementation() {
    return true;
}

#if WITH_GAMELIFT
void OnStartGameSessionInternal(Aws::GameLift::Server::Model::GameSession awsGameSession, void *state) {
	UProcessParameters* processParameters = (UProcessParameters*) state;
	processParameters->StartGameSession(FAWSGameSessionServer().fromAWS(awsGameSession));
};

void OnUpdateGameSessionInternal(Aws::GameLift::Server::Model::UpdateGameSession awsUpdateGameSession, void *state) {
	UProcessParameters* processParameters = (UProcessParameters*) state;
	processParameters->UpdateGameSession(FUpdateGameSessionServer().fromAWS(awsUpdateGameSession));
};

void OnProcessTerminateInternal(void *state) {
	UProcessParameters* processParameters = (UProcessParameters*) state;
	processParameters->ProcessTerminate();
};

bool OnHealthCheckInternal(void *state) {
	UProcessParameters* processParameters = (UProcessParameters*) state;
	return processParameters->HealthCheck();
};

Aws::GameLift::Server::ProcessParameters UProcessParameters::toAWS() const {
		char awsLogPathsBuffer[MAX_LOG_PATHS][MAX_PATH_LENGTH];
		const char* awsLogPaths[MAX_LOG_PATHS];

		memset(awsLogPaths, 0, sizeof(awsLogPaths));
		memset(awsLogPathsBuffer, 0, sizeof(awsLogPathsBuffer));

        for (int i = 0; i < MAX_LOG_PATHS; i++) {
			if (!this->logPaths.IsValidIndex(i)) break;
			const FTCHARToUTF8 Converter(*this->logPaths[i], this->logPaths[i].Len());
			if (Converter.Length() < MAX_PATH_LENGTH) {
				memcpy(awsLogPathsBuffer[i], Converter.Get(), Converter.Length());
			}
			awsLogPaths[i] = awsLogPathsBuffer[i];
        }

        return Aws::GameLift::Server::ProcessParameters(
                OnStartGameSessionInternal,
                (void*)this,
                OnUpdateGameSessionInternal,
                (void*)this,
                OnProcessTerminateInternal,
                (void*)this,
                OnHealthCheckInternal,
                (void*)this,
                this->port,
                Aws::GameLift::Server::LogParameters(awsLogPaths, this->logPaths.Num())
        );
    }
#endif