/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "GameLiftClientObject.h"
#include "GameLiftGlobals.h"
#include "GameLiftPrivatePCH.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_GAMELIFTCLIENTSDK

EGameLiftError fromAWS(Aws::GameLift::GameLiftErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::GameLift::GameLiftErrors::INCOMPLETE_SIGNATURE:
            return EGameLiftError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::GameLift::GameLiftErrors::INTERNAL_FAILURE:
            return EGameLiftError::INTERNAL_FAILURE;
            break;
        case Aws::GameLift::GameLiftErrors::INVALID_ACTION:
            return EGameLiftError::INVALID_ACTION;
            break;
        case Aws::GameLift::GameLiftErrors::INVALID_CLIENT_TOKEN_ID:
            return EGameLiftError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::GameLift::GameLiftErrors::INVALID_PARAMETER_COMBINATION:
            return EGameLiftError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::GameLift::GameLiftErrors::INVALID_QUERY_PARAMETER:
            return EGameLiftError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::GameLift::GameLiftErrors::INVALID_PARAMETER_VALUE:
            return EGameLiftError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::GameLift::GameLiftErrors::MISSING_ACTION:
            return EGameLiftError::MISSING_ACTION;
            break;
        case Aws::GameLift::GameLiftErrors::MISSING_AUTHENTICATION_TOKEN:
            return EGameLiftError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::GameLift::GameLiftErrors::MISSING_PARAMETER:
            return EGameLiftError::MISSING_PARAMETER;
            break;
        case Aws::GameLift::GameLiftErrors::OPT_IN_REQUIRED:
            return EGameLiftError::OPT_IN_REQUIRED;
            break;
        case Aws::GameLift::GameLiftErrors::REQUEST_EXPIRED:
            return EGameLiftError::REQUEST_EXPIRED;
            break;
        case Aws::GameLift::GameLiftErrors::SERVICE_UNAVAILABLE:
            return EGameLiftError::SERVICE_UNAVAILABLE;
            break;
        case Aws::GameLift::GameLiftErrors::THROTTLING:
            return EGameLiftError::THROTTLING;
            break;
        case Aws::GameLift::GameLiftErrors::VALIDATION:
            return EGameLiftError::VALIDATION;
            break;
        case Aws::GameLift::GameLiftErrors::ACCESS_DENIED:
            return EGameLiftError::ACCESS_DENIED;
            break;
        case Aws::GameLift::GameLiftErrors::RESOURCE_NOT_FOUND:
            return EGameLiftError::RESOURCE_NOT_FOUND;
            break;
        case Aws::GameLift::GameLiftErrors::UNRECOGNIZED_CLIENT:
            return EGameLiftError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::GameLift::GameLiftErrors::MALFORMED_QUERY_STRING:
            return EGameLiftError::MALFORMED_QUERY_STRING;
            break;
        case Aws::GameLift::GameLiftErrors::SLOW_DOWN:
            return EGameLiftError::SLOW_DOWN;
            break;
        case Aws::GameLift::GameLiftErrors::REQUEST_TIME_TOO_SKEWED:
            return EGameLiftError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::GameLift::GameLiftErrors::INVALID_SIGNATURE:
            return EGameLiftError::INVALID_SIGNATURE;
            break;
        case Aws::GameLift::GameLiftErrors::SIGNATURE_DOES_NOT_MATCH:
            return EGameLiftError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::GameLift::GameLiftErrors::INVALID_ACCESS_KEY_ID:
            return EGameLiftError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::GameLift::GameLiftErrors::REQUEST_TIMEOUT:
            return EGameLiftError::REQUEST_TIMEOUT;
            break;
        case Aws::GameLift::GameLiftErrors::NETWORK_CONNECTION:
            return EGameLiftError::NETWORK_CONNECTION;
            break;
        case Aws::GameLift::GameLiftErrors::UNKNOWN:
            return EGameLiftError::UNKNOWN;
            break;
        case Aws::GameLift::GameLiftErrors::CONFLICT:
            return EGameLiftError::CONFLICT;
            break;
        case Aws::GameLift::GameLiftErrors::FLEET_CAPACITY_EXCEEDED:
            return EGameLiftError::FLEET_CAPACITY_EXCEEDED;
            break;
        case Aws::GameLift::GameLiftErrors::GAME_SESSION_FULL:
            return EGameLiftError::GAME_SESSION_FULL;
            break;
        case Aws::GameLift::GameLiftErrors::IDEMPOTENT_PARAMETER_MISMATCH:
            return EGameLiftError::IDEMPOTENT_PARAMETER_MISMATCH;
            break;
        case Aws::GameLift::GameLiftErrors::INTERNAL_SERVICE:
            return EGameLiftError::INTERNAL_SERVICE;
            break;
        case Aws::GameLift::GameLiftErrors::INVALID_FLEET_STATUS:
            return EGameLiftError::INVALID_FLEET_STATUS;
            break;
        case Aws::GameLift::GameLiftErrors::INVALID_GAME_SESSION_STATUS:
            return EGameLiftError::INVALID_GAME_SESSION_STATUS;
            break;
        case Aws::GameLift::GameLiftErrors::INVALID_REQUEST:
            return EGameLiftError::INVALID_REQUEST;
            break;
        case Aws::GameLift::GameLiftErrors::LIMIT_EXCEEDED:
            return EGameLiftError::LIMIT_EXCEEDED;
            break;
        case Aws::GameLift::GameLiftErrors::NOT_FOUND:
            return EGameLiftError::NOT_FOUND;
            break;
        case Aws::GameLift::GameLiftErrors::OUT_OF_CAPACITY:
            return EGameLiftError::OUT_OF_CAPACITY;
            break;
        case Aws::GameLift::GameLiftErrors::TAGGING_FAILED:
            return EGameLiftError::TAGGING_FAILED;
            break;
        case Aws::GameLift::GameLiftErrors::TERMINAL_ROUTING_STRATEGY:
            return EGameLiftError::TERMINAL_ROUTING_STRATEGY;
            break;
        case Aws::GameLift::GameLiftErrors::UNAUTHORIZED:
            return EGameLiftError::UNAUTHORIZED;
            break;
        case Aws::GameLift::GameLiftErrors::UNSUPPORTED_REGION:
            return EGameLiftError::UNSUPPORTED_REGION;
            break;
        default:
            return EGameLiftError::UNKNOWN;
            break;
    }
}

#endif

UGameLiftClientObject *UGameLiftClientObject::CreateGameLiftObject(
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    UGameLiftClientObject *GameLiftClient = NewObject<UGameLiftClientObject>();
    GameLiftClient->awsGameLiftClient = new Aws::GameLift::GameLiftClient(credentials.toAWS(),
    Aws::MakeShared<Aws::GameLift::GameLiftEndpointProvider>("unreal"),
    clientConfiguration.toAWS());
    return GameLiftClient;
#endif
    return nullptr;
}

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FAcceptMatchAction : public FPendingLatentAction {
private:
    bool &success;
    FAcceptMatchResult &acceptMatchResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::AcceptMatchOutcomeCallable callable;

public:
    FAcceptMatchAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAcceptMatchRequest acceptMatchRequest,
        FAcceptMatchResult &acceptMatchResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), acceptMatchResult(acceptMatchResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->AcceptMatchCallable(acceptMatchRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAcceptMatchOutcome = callable.get();

            success = awsAcceptMatchOutcome.IsSuccess();
                if (success) {
                    acceptMatchResult.fromAWS(awsAcceptMatchOutcome.GetResult());
                }

                errorType = fromAWS(awsAcceptMatchOutcome.GetError().GetErrorType());
                errorMessage = ("AcceptMatch error: " + awsAcceptMatchOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AcceptMatch Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::AcceptMatch(
        UObject *WorldContextObject,
        bool &success,
        FAcceptMatchRequest acceptMatchRequest,
        FAcceptMatchResult &acceptMatchResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAcceptMatchAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAcceptMatchAction(this->awsGameLiftClient,
                success,
                acceptMatchRequest,
                acceptMatchResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FClaimGameServerAction : public FPendingLatentAction {
private:
    bool &success;
    FClaimGameServerResult &claimGameServerResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ClaimGameServerOutcomeCallable callable;

public:
    FClaimGameServerAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FClaimGameServerRequest claimGameServerRequest,
        FClaimGameServerResult &claimGameServerResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), claimGameServerResult(claimGameServerResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ClaimGameServerCallable(claimGameServerRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsClaimGameServerOutcome = callable.get();

            success = awsClaimGameServerOutcome.IsSuccess();
                if (success) {
                    claimGameServerResult.fromAWS(awsClaimGameServerOutcome.GetResult());
                }

                errorType = fromAWS(awsClaimGameServerOutcome.GetError().GetErrorType());
                errorMessage = ("ClaimGameServer error: " + awsClaimGameServerOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ClaimGameServer Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ClaimGameServer(
        UObject *WorldContextObject,
        bool &success,
        FClaimGameServerRequest claimGameServerRequest,
        FClaimGameServerResult &claimGameServerResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FClaimGameServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FClaimGameServerAction(this->awsGameLiftClient,
                success,
                claimGameServerRequest,
                claimGameServerResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateAliasAction : public FPendingLatentAction {
private:
    bool &success;
    FGameLiftCreateAliasResult &createAliasResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateAliasOutcomeCallable callable;

public:
    FCreateAliasAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FGameLiftCreateAliasRequest createAliasRequest,
        FGameLiftCreateAliasResult &createAliasResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createAliasResult(createAliasResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateAliasCallable(createAliasRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateAliasOutcome = callable.get();

            success = awsCreateAliasOutcome.IsSuccess();
                if (success) {
                    createAliasResult.fromAWS(awsCreateAliasOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateAliasOutcome.GetError().GetErrorType());
                errorMessage = ("CreateAlias error: " + awsCreateAliasOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateAlias Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateAlias(
        UObject *WorldContextObject,
        bool &success,
        FGameLiftCreateAliasRequest createAliasRequest,
        FGameLiftCreateAliasResult &createAliasResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateAliasAction(this->awsGameLiftClient,
                success,
                createAliasRequest,
                createAliasResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateBuildAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateBuildResult &createBuildResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateBuildOutcomeCallable callable;

public:
    FCreateBuildAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreateBuildRequest createBuildRequest,
        FCreateBuildResult &createBuildResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createBuildResult(createBuildResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateBuildCallable(createBuildRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateBuildOutcome = callable.get();

            success = awsCreateBuildOutcome.IsSuccess();
                if (success) {
                    createBuildResult.fromAWS(awsCreateBuildOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateBuildOutcome.GetError().GetErrorType());
                errorMessage = ("CreateBuild error: " + awsCreateBuildOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateBuild Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateBuild(
        UObject *WorldContextObject,
        bool &success,
        FCreateBuildRequest createBuildRequest,
        FCreateBuildResult &createBuildResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateBuildAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateBuildAction(this->awsGameLiftClient,
                success,
                createBuildRequest,
                createBuildResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateFleetAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateFleetResult &createFleetResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateFleetOutcomeCallable callable;

public:
    FCreateFleetAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreateFleetRequest createFleetRequest,
        FCreateFleetResult &createFleetResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createFleetResult(createFleetResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateFleetCallable(createFleetRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateFleetOutcome = callable.get();

            success = awsCreateFleetOutcome.IsSuccess();
                if (success) {
                    createFleetResult.fromAWS(awsCreateFleetOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateFleetOutcome.GetError().GetErrorType());
                errorMessage = ("CreateFleet error: " + awsCreateFleetOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateFleet Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateFleet(
        UObject *WorldContextObject,
        bool &success,
        FCreateFleetRequest createFleetRequest,
        FCreateFleetResult &createFleetResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateFleetAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateFleetAction(this->awsGameLiftClient,
                success,
                createFleetRequest,
                createFleetResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateFleetLocationsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftCreateFleetLocationsResult &createFleetLocationsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateFleetLocationsOutcomeCallable callable;

public:
    FCreateFleetLocationsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftCreateFleetLocationsRequest createFleetLocationsRequest,
        FAWSGameLiftCreateFleetLocationsResult &createFleetLocationsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createFleetLocationsResult(createFleetLocationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateFleetLocationsCallable(createFleetLocationsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateFleetLocationsOutcome = callable.get();

            success = awsCreateFleetLocationsOutcome.IsSuccess();
                if (success) {
                    createFleetLocationsResult.fromAWS(awsCreateFleetLocationsOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateFleetLocationsOutcome.GetError().GetErrorType());
                errorMessage = ("CreateFleetLocations error: " + awsCreateFleetLocationsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateFleetLocations Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateFleetLocations(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftCreateFleetLocationsRequest createFleetLocationsRequest,
    FAWSGameLiftCreateFleetLocationsResult &createFleetLocationsResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateFleetLocationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateFleetLocationsAction(this->awsGameLiftClient,
                success,
                createFleetLocationsRequest,
                createFleetLocationsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateGameServerGroupAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateGameServerGroupResult &createGameServerGroupResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateGameServerGroupOutcomeCallable callable;

public:
    FCreateGameServerGroupAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreateGameServerGroupRequest createGameServerGroupRequest,
        FCreateGameServerGroupResult &createGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createGameServerGroupResult(createGameServerGroupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateGameServerGroupCallable(createGameServerGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateGameServerGroupOutcome = callable.get();

            success = awsCreateGameServerGroupOutcome.IsSuccess();
                if (success) {
                    createGameServerGroupResult.fromAWS(awsCreateGameServerGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateGameServerGroupOutcome.GetError().GetErrorType());
                errorMessage = ("CreateGameServerGroup error: " + awsCreateGameServerGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateGameServerGroup Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateGameServerGroup(
        UObject *WorldContextObject,
        bool &success,
        FCreateGameServerGroupRequest createGameServerGroupRequest,
        FCreateGameServerGroupResult &createGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateGameServerGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateGameServerGroupAction(this->awsGameLiftClient,
                success,
                createGameServerGroupRequest,
                createGameServerGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateGameSessionAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateGameSessionResult &createGameSessionResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateGameSessionOutcomeCallable callable;

public:
    FCreateGameSessionAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreateGameSessionRequest createGameSessionRequest,
        FCreateGameSessionResult &createGameSessionResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createGameSessionResult(createGameSessionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateGameSessionCallable(createGameSessionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateGameSessionOutcome = callable.get();

            success = awsCreateGameSessionOutcome.IsSuccess();
                if (success) {
                    createGameSessionResult.fromAWS(awsCreateGameSessionOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateGameSessionOutcome.GetError().GetErrorType());
                errorMessage = ("CreateGameSession error: " + awsCreateGameSessionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateGameSession Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateGameSession(
        UObject *WorldContextObject,
        bool &success,
        FCreateGameSessionRequest createGameSessionRequest,
        FCreateGameSessionResult &createGameSessionResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateGameSessionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateGameSessionAction(this->awsGameLiftClient,
                success,
                createGameSessionRequest,
                createGameSessionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateGameSessionQueueAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateGameSessionQueueResult &createGameSessionQueueResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateGameSessionQueueOutcomeCallable callable;

public:
    FCreateGameSessionQueueAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreateGameSessionQueueRequest createGameSessionQueueRequest,
        FCreateGameSessionQueueResult &createGameSessionQueueResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createGameSessionQueueResult(createGameSessionQueueResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateGameSessionQueueCallable(createGameSessionQueueRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateGameSessionQueueOutcome = callable.get();

            success = awsCreateGameSessionQueueOutcome.IsSuccess();
                if (success) {
                    createGameSessionQueueResult.fromAWS(awsCreateGameSessionQueueOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateGameSessionQueueOutcome.GetError().GetErrorType());
                errorMessage = ("CreateGameSessionQueue error: " + awsCreateGameSessionQueueOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateGameSessionQueue Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateGameSessionQueue(
        UObject *WorldContextObject,
        bool &success,
        FCreateGameSessionQueueRequest createGameSessionQueueRequest,
        FCreateGameSessionQueueResult &createGameSessionQueueResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateGameSessionQueueAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateGameSessionQueueAction(this->awsGameLiftClient,
                success,
                createGameSessionQueueRequest,
                createGameSessionQueueResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateLocationAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftCreateLocationResult &createLocationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateLocationOutcomeCallable callable;

public:
    FCreateLocationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftCreateLocationRequest createLocationRequest,
        FAWSGameLiftCreateLocationResult &createLocationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createLocationResult(createLocationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateLocationCallable(createLocationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateLocationOutcome = callable.get();

            success = awsCreateLocationOutcome.IsSuccess();
                if (success) {
                    createLocationResult.fromAWS(awsCreateLocationOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateLocationOutcome.GetError().GetErrorType());
                errorMessage = ("CreateLocation error: " + awsCreateLocationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateLocation Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateLocation(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftCreateLocationRequest createLocationRequest,
    FAWSGameLiftCreateLocationResult &createLocationResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateLocationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateLocationAction(this->awsGameLiftClient,
                success,
                createLocationRequest,
                createLocationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateMatchmakingConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateMatchmakingConfigurationResult &createMatchmakingConfigurationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateMatchmakingConfigurationOutcomeCallable callable;

public:
    FCreateMatchmakingConfigurationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreateMatchmakingConfigurationRequest createMatchmakingConfigurationRequest,
        FCreateMatchmakingConfigurationResult &createMatchmakingConfigurationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createMatchmakingConfigurationResult(createMatchmakingConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateMatchmakingConfigurationCallable(createMatchmakingConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateMatchmakingConfigurationOutcome = callable.get();

            success = awsCreateMatchmakingConfigurationOutcome.IsSuccess();
                if (success) {
                    createMatchmakingConfigurationResult.fromAWS(awsCreateMatchmakingConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateMatchmakingConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("CreateMatchmakingConfiguration error: " + awsCreateMatchmakingConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateMatchmakingConfiguration Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateMatchmakingConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FCreateMatchmakingConfigurationRequest createMatchmakingConfigurationRequest,
        FCreateMatchmakingConfigurationResult &createMatchmakingConfigurationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateMatchmakingConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateMatchmakingConfigurationAction(this->awsGameLiftClient,
                success,
                createMatchmakingConfigurationRequest,
                createMatchmakingConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateMatchmakingRuleSetAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateMatchmakingRuleSetResult &createMatchmakingRuleSetResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateMatchmakingRuleSetOutcomeCallable callable;

public:
    FCreateMatchmakingRuleSetAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreateMatchmakingRuleSetRequest createMatchmakingRuleSetRequest,
        FCreateMatchmakingRuleSetResult &createMatchmakingRuleSetResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createMatchmakingRuleSetResult(createMatchmakingRuleSetResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateMatchmakingRuleSetCallable(createMatchmakingRuleSetRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateMatchmakingRuleSetOutcome = callable.get();

            success = awsCreateMatchmakingRuleSetOutcome.IsSuccess();
                if (success) {
                    createMatchmakingRuleSetResult.fromAWS(awsCreateMatchmakingRuleSetOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateMatchmakingRuleSetOutcome.GetError().GetErrorType());
                errorMessage = ("CreateMatchmakingRuleSet error: " + awsCreateMatchmakingRuleSetOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateMatchmakingRuleSet Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateMatchmakingRuleSet(
        UObject *WorldContextObject,
        bool &success,
        FCreateMatchmakingRuleSetRequest createMatchmakingRuleSetRequest,
        FCreateMatchmakingRuleSetResult &createMatchmakingRuleSetResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateMatchmakingRuleSetAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateMatchmakingRuleSetAction(this->awsGameLiftClient,
                success,
                createMatchmakingRuleSetRequest,
                createMatchmakingRuleSetResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreatePlayerSessionAction : public FPendingLatentAction {
private:
    bool &success;
    FCreatePlayerSessionResult &createPlayerSessionResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreatePlayerSessionOutcomeCallable callable;

public:
    FCreatePlayerSessionAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreatePlayerSessionRequest createPlayerSessionRequest,
        FCreatePlayerSessionResult &createPlayerSessionResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createPlayerSessionResult(createPlayerSessionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreatePlayerSessionCallable(createPlayerSessionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreatePlayerSessionOutcome = callable.get();

            success = awsCreatePlayerSessionOutcome.IsSuccess();
                if (success) {
                    createPlayerSessionResult.fromAWS(awsCreatePlayerSessionOutcome.GetResult());
                }

                errorType = fromAWS(awsCreatePlayerSessionOutcome.GetError().GetErrorType());
                errorMessage = ("CreatePlayerSession error: " + awsCreatePlayerSessionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreatePlayerSession Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreatePlayerSession(
        UObject *WorldContextObject,
        bool &success,
        FCreatePlayerSessionRequest createPlayerSessionRequest,
        FCreatePlayerSessionResult &createPlayerSessionResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreatePlayerSessionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreatePlayerSessionAction(this->awsGameLiftClient,
                success,
                createPlayerSessionRequest,
                createPlayerSessionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreatePlayerSessionsAction : public FPendingLatentAction {
private:
    bool &success;
    FCreatePlayerSessionsResult &createPlayerSessionsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreatePlayerSessionsOutcomeCallable callable;

public:
    FCreatePlayerSessionsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreatePlayerSessionsRequest createPlayerSessionsRequest,
        FCreatePlayerSessionsResult &createPlayerSessionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createPlayerSessionsResult(createPlayerSessionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreatePlayerSessionsCallable(createPlayerSessionsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreatePlayerSessionsOutcome = callable.get();

            success = awsCreatePlayerSessionsOutcome.IsSuccess();
                if (success) {
                    createPlayerSessionsResult.fromAWS(awsCreatePlayerSessionsOutcome.GetResult());
                }

                errorType = fromAWS(awsCreatePlayerSessionsOutcome.GetError().GetErrorType());
                errorMessage = ("CreatePlayerSessions error: " + awsCreatePlayerSessionsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreatePlayerSessions Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreatePlayerSessions(
        UObject *WorldContextObject,
        bool &success,
        FCreatePlayerSessionsRequest createPlayerSessionsRequest,
        FCreatePlayerSessionsResult &createPlayerSessionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreatePlayerSessionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreatePlayerSessionsAction(this->awsGameLiftClient,
                success,
                createPlayerSessionsRequest,
                createPlayerSessionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateScriptAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateScriptResult &createScriptResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateScriptOutcomeCallable callable;

public:
    FCreateScriptAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreateScriptRequest createScriptRequest,
        FCreateScriptResult &createScriptResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createScriptResult(createScriptResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateScriptCallable(createScriptRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateScriptOutcome = callable.get();

            success = awsCreateScriptOutcome.IsSuccess();
                if (success) {
                    createScriptResult.fromAWS(awsCreateScriptOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateScriptOutcome.GetError().GetErrorType());
                errorMessage = ("CreateScript error: " + awsCreateScriptOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateScript Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateScript(
        UObject *WorldContextObject,
        bool &success,
        FCreateScriptRequest createScriptRequest,
        FCreateScriptResult &createScriptResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateScriptAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateScriptAction(this->awsGameLiftClient,
                success,
                createScriptRequest,
                createScriptResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateVpcPeeringAuthorizationAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateVpcPeeringAuthorizationResult &createVpcPeeringAuthorizationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateVpcPeeringAuthorizationOutcomeCallable callable;

public:
    FCreateVpcPeeringAuthorizationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreateVpcPeeringAuthorizationRequest createVpcPeeringAuthorizationRequest,
        FCreateVpcPeeringAuthorizationResult &createVpcPeeringAuthorizationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createVpcPeeringAuthorizationResult(createVpcPeeringAuthorizationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateVpcPeeringAuthorizationCallable(createVpcPeeringAuthorizationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateVpcPeeringAuthorizationOutcome = callable.get();

            success = awsCreateVpcPeeringAuthorizationOutcome.IsSuccess();
                if (success) {
                    createVpcPeeringAuthorizationResult.fromAWS(awsCreateVpcPeeringAuthorizationOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateVpcPeeringAuthorizationOutcome.GetError().GetErrorType());
                errorMessage = ("CreateVpcPeeringAuthorization error: " + awsCreateVpcPeeringAuthorizationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateVpcPeeringAuthorization Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateVpcPeeringAuthorization(
        UObject *WorldContextObject,
        bool &success,
        FCreateVpcPeeringAuthorizationRequest createVpcPeeringAuthorizationRequest,
        FCreateVpcPeeringAuthorizationResult &createVpcPeeringAuthorizationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateVpcPeeringAuthorizationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateVpcPeeringAuthorizationAction(this->awsGameLiftClient,
                success,
                createVpcPeeringAuthorizationRequest,
                createVpcPeeringAuthorizationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FCreateVpcPeeringConnectionAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateVpcPeeringConnectionResult &createVpcPeeringConnectionResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::CreateVpcPeeringConnectionOutcomeCallable callable;

public:
    FCreateVpcPeeringConnectionAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FCreateVpcPeeringConnectionRequest createVpcPeeringConnectionRequest,
        FCreateVpcPeeringConnectionResult &createVpcPeeringConnectionResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createVpcPeeringConnectionResult(createVpcPeeringConnectionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->CreateVpcPeeringConnectionCallable(createVpcPeeringConnectionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateVpcPeeringConnectionOutcome = callable.get();

            success = awsCreateVpcPeeringConnectionOutcome.IsSuccess();
                if (success) {
                    createVpcPeeringConnectionResult.fromAWS(awsCreateVpcPeeringConnectionOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateVpcPeeringConnectionOutcome.GetError().GetErrorType());
                errorMessage = ("CreateVpcPeeringConnection error: " + awsCreateVpcPeeringConnectionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateVpcPeeringConnection Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::CreateVpcPeeringConnection(
        UObject *WorldContextObject,
        bool &success,
        FCreateVpcPeeringConnectionRequest createVpcPeeringConnectionRequest,
        FCreateVpcPeeringConnectionResult &createVpcPeeringConnectionResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateVpcPeeringConnectionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateVpcPeeringConnectionAction(this->awsGameLiftClient,
                success,
                createVpcPeeringConnectionRequest,
                createVpcPeeringConnectionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteAliasAction : public FPendingLatentAction {
private:
    bool &success;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteAliasOutcomeCallable callable;

public:
    FDeleteAliasAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FGameLiftDeleteAliasRequest deleteAliasRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteAliasCallable(deleteAliasRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteAliasOutcome = callable.get();

            success = awsDeleteAliasOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteAliasOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteAlias error: " + awsDeleteAliasOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteAlias Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteAlias(
        UObject *WorldContextObject,
        bool &success,
        FGameLiftDeleteAliasRequest deleteAliasRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteAliasAction(this->awsGameLiftClient,
                success,
                deleteAliasRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteBuildAction : public FPendingLatentAction {
private:
    bool &success;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteBuildOutcomeCallable callable;

public:
    FDeleteBuildAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeleteBuildRequest deleteBuildRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteBuildCallable(deleteBuildRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBuildOutcome = callable.get();

            success = awsDeleteBuildOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteBuildOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBuild error: " + awsDeleteBuildOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBuild Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteBuild(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBuildRequest deleteBuildRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBuildAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBuildAction(this->awsGameLiftClient,
                success,
                deleteBuildRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteFleetAction : public FPendingLatentAction {
private:
    bool &success;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteFleetOutcomeCallable callable;

public:
    FDeleteFleetAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeleteFleetRequest deleteFleetRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteFleetCallable(deleteFleetRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteFleetOutcome = callable.get();

            success = awsDeleteFleetOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteFleetOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFleet error: " + awsDeleteFleetOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFleet Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteFleet(
        UObject *WorldContextObject,
        bool &success,
        FDeleteFleetRequest deleteFleetRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFleetAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFleetAction(this->awsGameLiftClient,
                success,
                deleteFleetRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteFleetLocationsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftDeleteFleetLocationsResult &deleteFleetLocationsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteFleetLocationsOutcomeCallable callable;

public:
    FDeleteFleetLocationsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftDeleteFleetLocationsRequest deleteFleetLocationsRequest,
        FAWSGameLiftDeleteFleetLocationsResult &deleteFleetLocationsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteFleetLocationsResult(deleteFleetLocationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteFleetLocationsCallable(deleteFleetLocationsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteFleetLocationsOutcome = callable.get();

            success = awsDeleteFleetLocationsOutcome.IsSuccess();
                if (success) {
                    deleteFleetLocationsResult.fromAWS(awsDeleteFleetLocationsOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteFleetLocationsOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFleetLocations error: " + awsDeleteFleetLocationsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFleetLocations Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteFleetLocations(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftDeleteFleetLocationsRequest deleteFleetLocationsRequest,
    FAWSGameLiftDeleteFleetLocationsResult &deleteFleetLocationsResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFleetLocationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFleetLocationsAction(this->awsGameLiftClient,
                success,
                deleteFleetLocationsRequest,
                deleteFleetLocationsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteGameServerGroupAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteGameServerGroupResult &deleteGameServerGroupResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteGameServerGroupOutcomeCallable callable;

public:
    FDeleteGameServerGroupAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeleteGameServerGroupRequest deleteGameServerGroupRequest,
        FDeleteGameServerGroupResult &deleteGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteGameServerGroupResult(deleteGameServerGroupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteGameServerGroupCallable(deleteGameServerGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteGameServerGroupOutcome = callable.get();

            success = awsDeleteGameServerGroupOutcome.IsSuccess();
                if (success) {
                    deleteGameServerGroupResult.fromAWS(awsDeleteGameServerGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteGameServerGroupOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteGameServerGroup error: " + awsDeleteGameServerGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteGameServerGroup Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteGameServerGroup(
        UObject *WorldContextObject,
        bool &success,
        FDeleteGameServerGroupRequest deleteGameServerGroupRequest,
        FDeleteGameServerGroupResult &deleteGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteGameServerGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteGameServerGroupAction(this->awsGameLiftClient,
                success,
                deleteGameServerGroupRequest,
                deleteGameServerGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteGameSessionQueueAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteGameSessionQueueResult &deleteGameSessionQueueResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteGameSessionQueueOutcomeCallable callable;

public:
    FDeleteGameSessionQueueAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeleteGameSessionQueueRequest deleteGameSessionQueueRequest,
        FDeleteGameSessionQueueResult &deleteGameSessionQueueResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteGameSessionQueueResult(deleteGameSessionQueueResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteGameSessionQueueCallable(deleteGameSessionQueueRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteGameSessionQueueOutcome = callable.get();

            success = awsDeleteGameSessionQueueOutcome.IsSuccess();
                if (success) {
                    deleteGameSessionQueueResult.fromAWS(awsDeleteGameSessionQueueOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteGameSessionQueueOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteGameSessionQueue error: " + awsDeleteGameSessionQueueOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteGameSessionQueue Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteGameSessionQueue(
        UObject *WorldContextObject,
        bool &success,
        FDeleteGameSessionQueueRequest deleteGameSessionQueueRequest,
        FDeleteGameSessionQueueResult &deleteGameSessionQueueResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteGameSessionQueueAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteGameSessionQueueAction(this->awsGameLiftClient,
                success,
                deleteGameSessionQueueRequest,
                deleteGameSessionQueueResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteLocationAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftDeleteLocationResult &deleteLocationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteLocationOutcomeCallable callable;

public:
    FDeleteLocationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftDeleteLocationRequest deleteLocationRequest,
        FAWSGameLiftDeleteLocationResult &deleteLocationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteLocationResult(deleteLocationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteLocationCallable(deleteLocationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteLocationOutcome = callable.get();

            success = awsDeleteLocationOutcome.IsSuccess();
                if (success) {
                    deleteLocationResult.fromAWS(awsDeleteLocationOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteLocationOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteLocation error: " + awsDeleteLocationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteLocation Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteLocation(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftDeleteLocationRequest deleteLocationRequest,
    FAWSGameLiftDeleteLocationResult &deleteLocationResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteLocationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteLocationAction(this->awsGameLiftClient,
                success,
                deleteLocationRequest,
                deleteLocationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteMatchmakingConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteMatchmakingConfigurationResult &deleteMatchmakingConfigurationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteMatchmakingConfigurationOutcomeCallable callable;

public:
    FDeleteMatchmakingConfigurationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeleteMatchmakingConfigurationRequest deleteMatchmakingConfigurationRequest,
        FDeleteMatchmakingConfigurationResult &deleteMatchmakingConfigurationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteMatchmakingConfigurationResult(deleteMatchmakingConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteMatchmakingConfigurationCallable(deleteMatchmakingConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteMatchmakingConfigurationOutcome = callable.get();

            success = awsDeleteMatchmakingConfigurationOutcome.IsSuccess();
                if (success) {
                    deleteMatchmakingConfigurationResult.fromAWS(awsDeleteMatchmakingConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteMatchmakingConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteMatchmakingConfiguration error: " + awsDeleteMatchmakingConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteMatchmakingConfiguration Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteMatchmakingConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FDeleteMatchmakingConfigurationRequest deleteMatchmakingConfigurationRequest,
        FDeleteMatchmakingConfigurationResult &deleteMatchmakingConfigurationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteMatchmakingConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteMatchmakingConfigurationAction(this->awsGameLiftClient,
                success,
                deleteMatchmakingConfigurationRequest,
                deleteMatchmakingConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteMatchmakingRuleSetAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteMatchmakingRuleSetResult &deleteMatchmakingRuleSetResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteMatchmakingRuleSetOutcomeCallable callable;

public:
    FDeleteMatchmakingRuleSetAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeleteMatchmakingRuleSetRequest deleteMatchmakingRuleSetRequest,
        FDeleteMatchmakingRuleSetResult &deleteMatchmakingRuleSetResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteMatchmakingRuleSetResult(deleteMatchmakingRuleSetResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteMatchmakingRuleSetCallable(deleteMatchmakingRuleSetRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteMatchmakingRuleSetOutcome = callable.get();

            success = awsDeleteMatchmakingRuleSetOutcome.IsSuccess();
                if (success) {
                    deleteMatchmakingRuleSetResult.fromAWS(awsDeleteMatchmakingRuleSetOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteMatchmakingRuleSetOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteMatchmakingRuleSet error: " + awsDeleteMatchmakingRuleSetOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteMatchmakingRuleSet Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteMatchmakingRuleSet(
        UObject *WorldContextObject,
        bool &success,
        FDeleteMatchmakingRuleSetRequest deleteMatchmakingRuleSetRequest,
        FDeleteMatchmakingRuleSetResult &deleteMatchmakingRuleSetResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteMatchmakingRuleSetAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteMatchmakingRuleSetAction(this->awsGameLiftClient,
                success,
                deleteMatchmakingRuleSetRequest,
                deleteMatchmakingRuleSetResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteScalingPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteScalingPolicyOutcomeCallable callable;

public:
    FDeleteScalingPolicyAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeleteScalingPolicyRequest deleteScalingPolicyRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteScalingPolicyCallable(deleteScalingPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteScalingPolicyOutcome = callable.get();

            success = awsDeleteScalingPolicyOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteScalingPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteScalingPolicy error: " + awsDeleteScalingPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteScalingPolicy Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteScalingPolicy(
        UObject *WorldContextObject,
        bool &success,
        FDeleteScalingPolicyRequest deleteScalingPolicyRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteScalingPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteScalingPolicyAction(this->awsGameLiftClient,
                success,
                deleteScalingPolicyRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteScriptAction : public FPendingLatentAction {
private:
    bool &success;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteScriptOutcomeCallable callable;

public:
    FDeleteScriptAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeleteScriptRequest deleteScriptRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteScriptCallable(deleteScriptRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteScriptOutcome = callable.get();

            success = awsDeleteScriptOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteScriptOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteScript error: " + awsDeleteScriptOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteScript Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteScript(
        UObject *WorldContextObject,
        bool &success,
        FDeleteScriptRequest deleteScriptRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteScriptAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteScriptAction(this->awsGameLiftClient,
                success,
                deleteScriptRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteVpcPeeringAuthorizationAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteVpcPeeringAuthorizationResult &deleteVpcPeeringAuthorizationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteVpcPeeringAuthorizationOutcomeCallable callable;

public:
    FDeleteVpcPeeringAuthorizationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeleteVpcPeeringAuthorizationRequest deleteVpcPeeringAuthorizationRequest,
        FDeleteVpcPeeringAuthorizationResult &deleteVpcPeeringAuthorizationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteVpcPeeringAuthorizationResult(deleteVpcPeeringAuthorizationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteVpcPeeringAuthorizationCallable(deleteVpcPeeringAuthorizationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteVpcPeeringAuthorizationOutcome = callable.get();

            success = awsDeleteVpcPeeringAuthorizationOutcome.IsSuccess();
                if (success) {
                    deleteVpcPeeringAuthorizationResult.fromAWS(awsDeleteVpcPeeringAuthorizationOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteVpcPeeringAuthorizationOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteVpcPeeringAuthorization error: " + awsDeleteVpcPeeringAuthorizationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteVpcPeeringAuthorization Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteVpcPeeringAuthorization(
        UObject *WorldContextObject,
        bool &success,
        FDeleteVpcPeeringAuthorizationRequest deleteVpcPeeringAuthorizationRequest,
        FDeleteVpcPeeringAuthorizationResult &deleteVpcPeeringAuthorizationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteVpcPeeringAuthorizationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteVpcPeeringAuthorizationAction(this->awsGameLiftClient,
                success,
                deleteVpcPeeringAuthorizationRequest,
                deleteVpcPeeringAuthorizationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeleteVpcPeeringConnectionAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteVpcPeeringConnectionResult &deleteVpcPeeringConnectionResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeleteVpcPeeringConnectionOutcomeCallable callable;

public:
    FDeleteVpcPeeringConnectionAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeleteVpcPeeringConnectionRequest deleteVpcPeeringConnectionRequest,
        FDeleteVpcPeeringConnectionResult &deleteVpcPeeringConnectionResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteVpcPeeringConnectionResult(deleteVpcPeeringConnectionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeleteVpcPeeringConnectionCallable(deleteVpcPeeringConnectionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteVpcPeeringConnectionOutcome = callable.get();

            success = awsDeleteVpcPeeringConnectionOutcome.IsSuccess();
                if (success) {
                    deleteVpcPeeringConnectionResult.fromAWS(awsDeleteVpcPeeringConnectionOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteVpcPeeringConnectionOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteVpcPeeringConnection error: " + awsDeleteVpcPeeringConnectionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteVpcPeeringConnection Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeleteVpcPeeringConnection(
        UObject *WorldContextObject,
        bool &success,
        FDeleteVpcPeeringConnectionRequest deleteVpcPeeringConnectionRequest,
        FDeleteVpcPeeringConnectionResult &deleteVpcPeeringConnectionResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteVpcPeeringConnectionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteVpcPeeringConnectionAction(this->awsGameLiftClient,
                success,
                deleteVpcPeeringConnectionRequest,
                deleteVpcPeeringConnectionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeregisterComputeAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftDeregisterComputeResult &deregisterComputeResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeregisterComputeOutcomeCallable callable;

public:
    FDeregisterComputeAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftDeregisterComputeRequest deregisterComputeRequest,
        FAWSGameLiftDeregisterComputeResult &deregisterComputeResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deregisterComputeResult(deregisterComputeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeregisterComputeCallable(deregisterComputeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeregisterComputeOutcome = callable.get();

            success = awsDeregisterComputeOutcome.IsSuccess();
                if (success) {
                    deregisterComputeResult.fromAWS(awsDeregisterComputeOutcome.GetResult());
                }

                errorType = fromAWS(awsDeregisterComputeOutcome.GetError().GetErrorType());
                errorMessage = ("DeregisterCompute error: " + awsDeregisterComputeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeregisterCompute Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeregisterCompute(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftDeregisterComputeRequest deregisterComputeRequest,
    FAWSGameLiftDeregisterComputeResult &deregisterComputeResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeregisterComputeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeregisterComputeAction(this->awsGameLiftClient,
                success,
                deregisterComputeRequest,
                deregisterComputeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDeregisterGameServerAction : public FPendingLatentAction {
private:
    bool &success;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DeregisterGameServerOutcomeCallable callable;

public:
    FDeregisterGameServerAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDeregisterGameServerRequest deregisterGameServerRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DeregisterGameServerCallable(deregisterGameServerRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeregisterGameServerOutcome = callable.get();

            success = awsDeregisterGameServerOutcome.IsSuccess();

                errorType = fromAWS(awsDeregisterGameServerOutcome.GetError().GetErrorType());
                errorMessage = ("DeregisterGameServer error: " + awsDeregisterGameServerOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeregisterGameServer Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DeregisterGameServer(
        UObject *WorldContextObject,
        bool &success,
        FDeregisterGameServerRequest deregisterGameServerRequest,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeregisterGameServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeregisterGameServerAction(this->awsGameLiftClient,
                success,
                deregisterGameServerRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeAliasAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeAliasResult &describeAliasResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeAliasOutcomeCallable callable;

public:
    FDescribeAliasAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeAliasRequest describeAliasRequest,
        FDescribeAliasResult &describeAliasResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeAliasResult(describeAliasResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeAliasCallable(describeAliasRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeAliasOutcome = callable.get();

            success = awsDescribeAliasOutcome.IsSuccess();
                if (success) {
                    describeAliasResult.fromAWS(awsDescribeAliasOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeAliasOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeAlias error: " + awsDescribeAliasOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeAlias Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeAlias(
        UObject *WorldContextObject,
        bool &success,
        FDescribeAliasRequest describeAliasRequest,
        FDescribeAliasResult &describeAliasResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeAliasAction(this->awsGameLiftClient,
                success,
                describeAliasRequest,
                describeAliasResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeBuildAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeBuildResult &describeBuildResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeBuildOutcomeCallable callable;

public:
    FDescribeBuildAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeBuildRequest describeBuildRequest,
        FDescribeBuildResult &describeBuildResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeBuildResult(describeBuildResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeBuildCallable(describeBuildRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeBuildOutcome = callable.get();

            success = awsDescribeBuildOutcome.IsSuccess();
                if (success) {
                    describeBuildResult.fromAWS(awsDescribeBuildOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeBuildOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeBuild error: " + awsDescribeBuildOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeBuild Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeBuild(
        UObject *WorldContextObject,
        bool &success,
        FDescribeBuildRequest describeBuildRequest,
        FDescribeBuildResult &describeBuildResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeBuildAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeBuildAction(this->awsGameLiftClient,
                success,
                describeBuildRequest,
                describeBuildResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeComputeAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftDescribeComputeResult &describeComputeResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeComputeOutcomeCallable callable;

public:
    FDescribeComputeAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftDescribeComputeRequest describeComputeRequest,
        FAWSGameLiftDescribeComputeResult &describeComputeResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeComputeResult(describeComputeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeComputeCallable(describeComputeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeComputeOutcome = callable.get();

            success = awsDescribeComputeOutcome.IsSuccess();
                if (success) {
                    describeComputeResult.fromAWS(awsDescribeComputeOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeComputeOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeCompute error: " + awsDescribeComputeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeCompute Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeCompute(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftDescribeComputeRequest describeComputeRequest,
    FAWSGameLiftDescribeComputeResult &describeComputeResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeComputeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeComputeAction(this->awsGameLiftClient,
                success,
                describeComputeRequest,
                describeComputeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeEC2InstanceLimitsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeEC2InstanceLimitsResult &describeEC2InstanceLimitsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeEC2InstanceLimitsOutcomeCallable callable;

public:
    FDescribeEC2InstanceLimitsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeEC2InstanceLimitsRequest describeEC2InstanceLimitsRequest,
        FDescribeEC2InstanceLimitsResult &describeEC2InstanceLimitsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeEC2InstanceLimitsResult(describeEC2InstanceLimitsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeEC2InstanceLimitsCallable(describeEC2InstanceLimitsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeEC2InstanceLimitsOutcome = callable.get();

            success = awsDescribeEC2InstanceLimitsOutcome.IsSuccess();
                if (success) {
                    describeEC2InstanceLimitsResult.fromAWS(awsDescribeEC2InstanceLimitsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeEC2InstanceLimitsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeEC2InstanceLimits error: " + awsDescribeEC2InstanceLimitsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeEC2InstanceLimits Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeEC2InstanceLimits(
        UObject *WorldContextObject,
        bool &success,
        FDescribeEC2InstanceLimitsRequest describeEC2InstanceLimitsRequest,
        FDescribeEC2InstanceLimitsResult &describeEC2InstanceLimitsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeEC2InstanceLimitsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeEC2InstanceLimitsAction(this->awsGameLiftClient,
                success,
                describeEC2InstanceLimitsRequest,
                describeEC2InstanceLimitsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeFleetAttributesAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeFleetAttributesResult &describeFleetAttributesResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeFleetAttributesOutcomeCallable callable;

public:
    FDescribeFleetAttributesAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeFleetAttributesRequest describeFleetAttributesRequest,
        FDescribeFleetAttributesResult &describeFleetAttributesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeFleetAttributesResult(describeFleetAttributesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeFleetAttributesCallable(describeFleetAttributesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeFleetAttributesOutcome = callable.get();

            success = awsDescribeFleetAttributesOutcome.IsSuccess();
                if (success) {
                    describeFleetAttributesResult.fromAWS(awsDescribeFleetAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeFleetAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeFleetAttributes error: " + awsDescribeFleetAttributesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeFleetAttributes Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeFleetAttributes(
        UObject *WorldContextObject,
        bool &success,
        FDescribeFleetAttributesRequest describeFleetAttributesRequest,
        FDescribeFleetAttributesResult &describeFleetAttributesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeFleetAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeFleetAttributesAction(this->awsGameLiftClient,
                success,
                describeFleetAttributesRequest,
                describeFleetAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeFleetCapacityAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeFleetCapacityResult &describeFleetCapacityResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeFleetCapacityOutcomeCallable callable;

public:
    FDescribeFleetCapacityAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeFleetCapacityRequest describeFleetCapacityRequest,
        FDescribeFleetCapacityResult &describeFleetCapacityResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeFleetCapacityResult(describeFleetCapacityResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeFleetCapacityCallable(describeFleetCapacityRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeFleetCapacityOutcome = callable.get();

            success = awsDescribeFleetCapacityOutcome.IsSuccess();
                if (success) {
                    describeFleetCapacityResult.fromAWS(awsDescribeFleetCapacityOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeFleetCapacityOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeFleetCapacity error: " + awsDescribeFleetCapacityOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeFleetCapacity Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeFleetCapacity(
        UObject *WorldContextObject,
        bool &success,
        FDescribeFleetCapacityRequest describeFleetCapacityRequest,
        FDescribeFleetCapacityResult &describeFleetCapacityResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeFleetCapacityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeFleetCapacityAction(this->awsGameLiftClient,
                success,
                describeFleetCapacityRequest,
                describeFleetCapacityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeFleetEventsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeFleetEventsResult &describeFleetEventsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeFleetEventsOutcomeCallable callable;

public:
    FDescribeFleetEventsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeFleetEventsRequest describeFleetEventsRequest,
        FDescribeFleetEventsResult &describeFleetEventsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeFleetEventsResult(describeFleetEventsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeFleetEventsCallable(describeFleetEventsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeFleetEventsOutcome = callable.get();

            success = awsDescribeFleetEventsOutcome.IsSuccess();
                if (success) {
                    describeFleetEventsResult.fromAWS(awsDescribeFleetEventsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeFleetEventsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeFleetEvents error: " + awsDescribeFleetEventsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeFleetEvents Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeFleetEvents(
        UObject *WorldContextObject,
        bool &success,
        FDescribeFleetEventsRequest describeFleetEventsRequest,
        FDescribeFleetEventsResult &describeFleetEventsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeFleetEventsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeFleetEventsAction(this->awsGameLiftClient,
                success,
                describeFleetEventsRequest,
                describeFleetEventsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeFleetLocationAttributesAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftDescribeFleetLocationAttributesResult &describeFleetLocationAttributesResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeFleetLocationAttributesOutcomeCallable callable;

public:
    FDescribeFleetLocationAttributesAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftDescribeFleetLocationAttributesRequest describeFleetLocationAttributesRequest,
        FAWSGameLiftDescribeFleetLocationAttributesResult &describeFleetLocationAttributesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeFleetLocationAttributesResult(describeFleetLocationAttributesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeFleetLocationAttributesCallable(describeFleetLocationAttributesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeFleetLocationAttributesOutcome = callable.get();

            success = awsDescribeFleetLocationAttributesOutcome.IsSuccess();
                if (success) {
                    describeFleetLocationAttributesResult.fromAWS(awsDescribeFleetLocationAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeFleetLocationAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeFleetLocationAttributes error: " + awsDescribeFleetLocationAttributesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeFleetLocationAttributes Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeFleetLocationAttributes(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftDescribeFleetLocationAttributesRequest describeFleetLocationAttributesRequest,
    FAWSGameLiftDescribeFleetLocationAttributesResult &describeFleetLocationAttributesResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeFleetLocationAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeFleetLocationAttributesAction(this->awsGameLiftClient,
                success,
                describeFleetLocationAttributesRequest,
                describeFleetLocationAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeFleetLocationCapacityAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftDescribeFleetLocationCapacityResult &describeFleetLocationCapacityResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeFleetLocationCapacityOutcomeCallable callable;

public:
    FDescribeFleetLocationCapacityAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftDescribeFleetLocationCapacityRequest describeFleetLocationCapacityRequest,
        FAWSGameLiftDescribeFleetLocationCapacityResult &describeFleetLocationCapacityResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeFleetLocationCapacityResult(describeFleetLocationCapacityResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeFleetLocationCapacityCallable(describeFleetLocationCapacityRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeFleetLocationCapacityOutcome = callable.get();

            success = awsDescribeFleetLocationCapacityOutcome.IsSuccess();
                if (success) {
                    describeFleetLocationCapacityResult.fromAWS(awsDescribeFleetLocationCapacityOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeFleetLocationCapacityOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeFleetLocationCapacity error: " + awsDescribeFleetLocationCapacityOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeFleetLocationCapacity Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeFleetLocationCapacity(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftDescribeFleetLocationCapacityRequest describeFleetLocationCapacityRequest,
    FAWSGameLiftDescribeFleetLocationCapacityResult &describeFleetLocationCapacityResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeFleetLocationCapacityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeFleetLocationCapacityAction(this->awsGameLiftClient,
                success,
                describeFleetLocationCapacityRequest,
                describeFleetLocationCapacityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeFleetLocationUtilizationAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftDescribeFleetLocationUtilizationResult &describeFleetLocationUtilizationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeFleetLocationUtilizationOutcomeCallable callable;

public:
    FDescribeFleetLocationUtilizationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftDescribeFleetLocationUtilizationRequest describeFleetLocationUtilizationRequest,
        FAWSGameLiftDescribeFleetLocationUtilizationResult &describeFleetLocationUtilizationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeFleetLocationUtilizationResult(describeFleetLocationUtilizationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeFleetLocationUtilizationCallable(describeFleetLocationUtilizationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeFleetLocationUtilizationOutcome = callable.get();

            success = awsDescribeFleetLocationUtilizationOutcome.IsSuccess();
                if (success) {
                    describeFleetLocationUtilizationResult.fromAWS(awsDescribeFleetLocationUtilizationOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeFleetLocationUtilizationOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeFleetLocationUtilization error: " + awsDescribeFleetLocationUtilizationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeFleetLocationUtilization Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeFleetLocationUtilization(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftDescribeFleetLocationUtilizationRequest describeFleetLocationUtilizationRequest,
    FAWSGameLiftDescribeFleetLocationUtilizationResult &describeFleetLocationUtilizationResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeFleetLocationUtilizationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeFleetLocationUtilizationAction(this->awsGameLiftClient,
                success,
                describeFleetLocationUtilizationRequest,
                describeFleetLocationUtilizationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeFleetPortSettingsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeFleetPortSettingsResult &describeFleetPortSettingsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeFleetPortSettingsOutcomeCallable callable;

public:
    FDescribeFleetPortSettingsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeFleetPortSettingsRequest describeFleetPortSettingsRequest,
        FDescribeFleetPortSettingsResult &describeFleetPortSettingsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeFleetPortSettingsResult(describeFleetPortSettingsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeFleetPortSettingsCallable(describeFleetPortSettingsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeFleetPortSettingsOutcome = callable.get();

            success = awsDescribeFleetPortSettingsOutcome.IsSuccess();
                if (success) {
                    describeFleetPortSettingsResult.fromAWS(awsDescribeFleetPortSettingsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeFleetPortSettingsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeFleetPortSettings error: " + awsDescribeFleetPortSettingsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeFleetPortSettings Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeFleetPortSettings(
        UObject *WorldContextObject,
        bool &success,
        FDescribeFleetPortSettingsRequest describeFleetPortSettingsRequest,
        FDescribeFleetPortSettingsResult &describeFleetPortSettingsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeFleetPortSettingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeFleetPortSettingsAction(this->awsGameLiftClient,
                success,
                describeFleetPortSettingsRequest,
                describeFleetPortSettingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeFleetUtilizationAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeFleetUtilizationResult &describeFleetUtilizationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeFleetUtilizationOutcomeCallable callable;

public:
    FDescribeFleetUtilizationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeFleetUtilizationRequest describeFleetUtilizationRequest,
        FDescribeFleetUtilizationResult &describeFleetUtilizationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeFleetUtilizationResult(describeFleetUtilizationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeFleetUtilizationCallable(describeFleetUtilizationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeFleetUtilizationOutcome = callable.get();

            success = awsDescribeFleetUtilizationOutcome.IsSuccess();
                if (success) {
                    describeFleetUtilizationResult.fromAWS(awsDescribeFleetUtilizationOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeFleetUtilizationOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeFleetUtilization error: " + awsDescribeFleetUtilizationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeFleetUtilization Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeFleetUtilization(
        UObject *WorldContextObject,
        bool &success,
        FDescribeFleetUtilizationRequest describeFleetUtilizationRequest,
        FDescribeFleetUtilizationResult &describeFleetUtilizationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeFleetUtilizationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeFleetUtilizationAction(this->awsGameLiftClient,
                success,
                describeFleetUtilizationRequest,
                describeFleetUtilizationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeGameServerAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeGameServerResult &describeGameServerResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeGameServerOutcomeCallable callable;

public:
    FDescribeGameServerAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeGameServerRequest describeGameServerRequest,
        FDescribeGameServerResult &describeGameServerResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeGameServerResult(describeGameServerResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeGameServerCallable(describeGameServerRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeGameServerOutcome = callable.get();

            success = awsDescribeGameServerOutcome.IsSuccess();
                if (success) {
                    describeGameServerResult.fromAWS(awsDescribeGameServerOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeGameServerOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeGameServer error: " + awsDescribeGameServerOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeGameServer Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeGameServer(
        UObject *WorldContextObject,
        bool &success,
        FDescribeGameServerRequest describeGameServerRequest,
        FDescribeGameServerResult &describeGameServerResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeGameServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeGameServerAction(this->awsGameLiftClient,
                success,
                describeGameServerRequest,
                describeGameServerResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeGameServerGroupAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeGameServerGroupResult &describeGameServerGroupResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeGameServerGroupOutcomeCallable callable;

public:
    FDescribeGameServerGroupAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeGameServerGroupRequest describeGameServerGroupRequest,
        FDescribeGameServerGroupResult &describeGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeGameServerGroupResult(describeGameServerGroupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeGameServerGroupCallable(describeGameServerGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeGameServerGroupOutcome = callable.get();

            success = awsDescribeGameServerGroupOutcome.IsSuccess();
                if (success) {
                    describeGameServerGroupResult.fromAWS(awsDescribeGameServerGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeGameServerGroupOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeGameServerGroup error: " + awsDescribeGameServerGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeGameServerGroup Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeGameServerGroup(
        UObject *WorldContextObject,
        bool &success,
        FDescribeGameServerGroupRequest describeGameServerGroupRequest,
        FDescribeGameServerGroupResult &describeGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeGameServerGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeGameServerGroupAction(this->awsGameLiftClient,
                success,
                describeGameServerGroupRequest,
                describeGameServerGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeGameServerInstancesAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeGameServerInstancesResult &describeGameServerInstancesResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeGameServerInstancesOutcomeCallable callable;

public:
    FDescribeGameServerInstancesAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeGameServerInstancesRequest describeGameServerInstancesRequest,
        FDescribeGameServerInstancesResult &describeGameServerInstancesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeGameServerInstancesResult(describeGameServerInstancesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeGameServerInstancesCallable(describeGameServerInstancesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeGameServerInstancesOutcome = callable.get();

            success = awsDescribeGameServerInstancesOutcome.IsSuccess();
                if (success) {
                    describeGameServerInstancesResult.fromAWS(awsDescribeGameServerInstancesOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeGameServerInstancesOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeGameServerInstances error: " + awsDescribeGameServerInstancesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeGameServerInstances Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeGameServerInstances(
        UObject *WorldContextObject,
        bool &success,
        FDescribeGameServerInstancesRequest describeGameServerInstancesRequest,
        FDescribeGameServerInstancesResult &describeGameServerInstancesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeGameServerInstancesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeGameServerInstancesAction(this->awsGameLiftClient,
                success,
                describeGameServerInstancesRequest,
                describeGameServerInstancesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeGameSessionDetailsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeGameSessionDetailsResult &describeGameSessionDetailsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeGameSessionDetailsOutcomeCallable callable;

public:
    FDescribeGameSessionDetailsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeGameSessionDetailsRequest describeGameSessionDetailsRequest,
        FDescribeGameSessionDetailsResult &describeGameSessionDetailsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeGameSessionDetailsResult(describeGameSessionDetailsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeGameSessionDetailsCallable(describeGameSessionDetailsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeGameSessionDetailsOutcome = callable.get();

            success = awsDescribeGameSessionDetailsOutcome.IsSuccess();
                if (success) {
                    describeGameSessionDetailsResult.fromAWS(awsDescribeGameSessionDetailsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeGameSessionDetailsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeGameSessionDetails error: " + awsDescribeGameSessionDetailsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeGameSessionDetails Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeGameSessionDetails(
        UObject *WorldContextObject,
        bool &success,
        FDescribeGameSessionDetailsRequest describeGameSessionDetailsRequest,
        FDescribeGameSessionDetailsResult &describeGameSessionDetailsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeGameSessionDetailsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeGameSessionDetailsAction(this->awsGameLiftClient,
                success,
                describeGameSessionDetailsRequest,
                describeGameSessionDetailsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeGameSessionPlacementAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeGameSessionPlacementResult &describeGameSessionPlacementResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeGameSessionPlacementOutcomeCallable callable;

public:
    FDescribeGameSessionPlacementAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeGameSessionPlacementRequest describeGameSessionPlacementRequest,
        FDescribeGameSessionPlacementResult &describeGameSessionPlacementResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeGameSessionPlacementResult(describeGameSessionPlacementResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeGameSessionPlacementCallable(describeGameSessionPlacementRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeGameSessionPlacementOutcome = callable.get();

            success = awsDescribeGameSessionPlacementOutcome.IsSuccess();
                if (success) {
                    describeGameSessionPlacementResult.fromAWS(awsDescribeGameSessionPlacementOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeGameSessionPlacementOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeGameSessionPlacement error: " + awsDescribeGameSessionPlacementOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeGameSessionPlacement Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeGameSessionPlacement(
        UObject *WorldContextObject,
        bool &success,
        FDescribeGameSessionPlacementRequest describeGameSessionPlacementRequest,
        FDescribeGameSessionPlacementResult &describeGameSessionPlacementResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeGameSessionPlacementAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeGameSessionPlacementAction(this->awsGameLiftClient,
                success,
                describeGameSessionPlacementRequest,
                describeGameSessionPlacementResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeGameSessionQueuesAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeGameSessionQueuesResult &describeGameSessionQueuesResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeGameSessionQueuesOutcomeCallable callable;

public:
    FDescribeGameSessionQueuesAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeGameSessionQueuesRequest describeGameSessionQueuesRequest,
        FDescribeGameSessionQueuesResult &describeGameSessionQueuesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeGameSessionQueuesResult(describeGameSessionQueuesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeGameSessionQueuesCallable(describeGameSessionQueuesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeGameSessionQueuesOutcome = callable.get();

            success = awsDescribeGameSessionQueuesOutcome.IsSuccess();
                if (success) {
                    describeGameSessionQueuesResult.fromAWS(awsDescribeGameSessionQueuesOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeGameSessionQueuesOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeGameSessionQueues error: " + awsDescribeGameSessionQueuesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeGameSessionQueues Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeGameSessionQueues(
        UObject *WorldContextObject,
        bool &success,
        FDescribeGameSessionQueuesRequest describeGameSessionQueuesRequest,
        FDescribeGameSessionQueuesResult &describeGameSessionQueuesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeGameSessionQueuesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeGameSessionQueuesAction(this->awsGameLiftClient,
                success,
                describeGameSessionQueuesRequest,
                describeGameSessionQueuesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeGameSessionsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeGameSessionsResult &describeGameSessionsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeGameSessionsOutcomeCallable callable;

public:
    FDescribeGameSessionsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeGameSessionsRequest describeGameSessionsRequest,
        FDescribeGameSessionsResult &describeGameSessionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeGameSessionsResult(describeGameSessionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeGameSessionsCallable(describeGameSessionsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeGameSessionsOutcome = callable.get();

            success = awsDescribeGameSessionsOutcome.IsSuccess();
                if (success) {
                    describeGameSessionsResult.fromAWS(awsDescribeGameSessionsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeGameSessionsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeGameSessions error: " + awsDescribeGameSessionsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeGameSessions Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeGameSessions(
        UObject *WorldContextObject,
        bool &success,
        FDescribeGameSessionsRequest describeGameSessionsRequest,
        FDescribeGameSessionsResult &describeGameSessionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeGameSessionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeGameSessionsAction(this->awsGameLiftClient,
                success,
                describeGameSessionsRequest,
                describeGameSessionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeInstancesAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeInstancesResult &describeInstancesResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeInstancesOutcomeCallable callable;

public:
    FDescribeInstancesAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeInstancesRequest describeInstancesRequest,
        FDescribeInstancesResult &describeInstancesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeInstancesResult(describeInstancesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeInstancesCallable(describeInstancesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeInstancesOutcome = callable.get();

            success = awsDescribeInstancesOutcome.IsSuccess();
                if (success) {
                    describeInstancesResult.fromAWS(awsDescribeInstancesOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeInstancesOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeInstances error: " + awsDescribeInstancesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeInstances Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeInstances(
        UObject *WorldContextObject,
        bool &success,
        FDescribeInstancesRequest describeInstancesRequest,
        FDescribeInstancesResult &describeInstancesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeInstancesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeInstancesAction(this->awsGameLiftClient,
                success,
                describeInstancesRequest,
                describeInstancesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeMatchmakingAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeMatchmakingResult &describeMatchmakingResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeMatchmakingOutcomeCallable callable;

public:
    FDescribeMatchmakingAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeMatchmakingRequest describeMatchmakingRequest,
        FDescribeMatchmakingResult &describeMatchmakingResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeMatchmakingResult(describeMatchmakingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeMatchmakingCallable(describeMatchmakingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeMatchmakingOutcome = callable.get();

            success = awsDescribeMatchmakingOutcome.IsSuccess();
                if (success) {
                    describeMatchmakingResult.fromAWS(awsDescribeMatchmakingOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeMatchmakingOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeMatchmaking error: " + awsDescribeMatchmakingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeMatchmaking Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeMatchmaking(
        UObject *WorldContextObject,
        bool &success,
        FDescribeMatchmakingRequest describeMatchmakingRequest,
        FDescribeMatchmakingResult &describeMatchmakingResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeMatchmakingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeMatchmakingAction(this->awsGameLiftClient,
                success,
                describeMatchmakingRequest,
                describeMatchmakingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeMatchmakingConfigurationsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeMatchmakingConfigurationsResult &describeMatchmakingConfigurationsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeMatchmakingConfigurationsOutcomeCallable callable;

public:
    FDescribeMatchmakingConfigurationsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeMatchmakingConfigurationsRequest describeMatchmakingConfigurationsRequest,
        FDescribeMatchmakingConfigurationsResult &describeMatchmakingConfigurationsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeMatchmakingConfigurationsResult(describeMatchmakingConfigurationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeMatchmakingConfigurationsCallable(describeMatchmakingConfigurationsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeMatchmakingConfigurationsOutcome = callable.get();

            success = awsDescribeMatchmakingConfigurationsOutcome.IsSuccess();
                if (success) {
                    describeMatchmakingConfigurationsResult.fromAWS(awsDescribeMatchmakingConfigurationsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeMatchmakingConfigurationsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeMatchmakingConfigurations error: " + awsDescribeMatchmakingConfigurationsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeMatchmakingConfigurations Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeMatchmakingConfigurations(
        UObject *WorldContextObject,
        bool &success,
        FDescribeMatchmakingConfigurationsRequest describeMatchmakingConfigurationsRequest,
        FDescribeMatchmakingConfigurationsResult &describeMatchmakingConfigurationsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeMatchmakingConfigurationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeMatchmakingConfigurationsAction(this->awsGameLiftClient,
                success,
                describeMatchmakingConfigurationsRequest,
                describeMatchmakingConfigurationsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeMatchmakingRuleSetsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeMatchmakingRuleSetsResult &describeMatchmakingRuleSetsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeMatchmakingRuleSetsOutcomeCallable callable;

public:
    FDescribeMatchmakingRuleSetsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeMatchmakingRuleSetsRequest describeMatchmakingRuleSetsRequest,
        FDescribeMatchmakingRuleSetsResult &describeMatchmakingRuleSetsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeMatchmakingRuleSetsResult(describeMatchmakingRuleSetsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeMatchmakingRuleSetsCallable(describeMatchmakingRuleSetsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeMatchmakingRuleSetsOutcome = callable.get();

            success = awsDescribeMatchmakingRuleSetsOutcome.IsSuccess();
                if (success) {
                    describeMatchmakingRuleSetsResult.fromAWS(awsDescribeMatchmakingRuleSetsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeMatchmakingRuleSetsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeMatchmakingRuleSets error: " + awsDescribeMatchmakingRuleSetsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeMatchmakingRuleSets Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeMatchmakingRuleSets(
        UObject *WorldContextObject,
        bool &success,
        FDescribeMatchmakingRuleSetsRequest describeMatchmakingRuleSetsRequest,
        FDescribeMatchmakingRuleSetsResult &describeMatchmakingRuleSetsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeMatchmakingRuleSetsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeMatchmakingRuleSetsAction(this->awsGameLiftClient,
                success,
                describeMatchmakingRuleSetsRequest,
                describeMatchmakingRuleSetsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribePlayerSessionsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribePlayerSessionsResult &describePlayerSessionsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribePlayerSessionsOutcomeCallable callable;

public:
    FDescribePlayerSessionsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribePlayerSessionsRequest describePlayerSessionsRequest,
        FDescribePlayerSessionsResult &describePlayerSessionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describePlayerSessionsResult(describePlayerSessionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribePlayerSessionsCallable(describePlayerSessionsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribePlayerSessionsOutcome = callable.get();

            success = awsDescribePlayerSessionsOutcome.IsSuccess();
                if (success) {
                    describePlayerSessionsResult.fromAWS(awsDescribePlayerSessionsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribePlayerSessionsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribePlayerSessions error: " + awsDescribePlayerSessionsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribePlayerSessions Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribePlayerSessions(
        UObject *WorldContextObject,
        bool &success,
        FDescribePlayerSessionsRequest describePlayerSessionsRequest,
        FDescribePlayerSessionsResult &describePlayerSessionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribePlayerSessionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribePlayerSessionsAction(this->awsGameLiftClient,
                success,
                describePlayerSessionsRequest,
                describePlayerSessionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeRuntimeConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeRuntimeConfigurationResult &describeRuntimeConfigurationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeRuntimeConfigurationOutcomeCallable callable;

public:
    FDescribeRuntimeConfigurationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeRuntimeConfigurationRequest describeRuntimeConfigurationRequest,
        FDescribeRuntimeConfigurationResult &describeRuntimeConfigurationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeRuntimeConfigurationResult(describeRuntimeConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeRuntimeConfigurationCallable(describeRuntimeConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeRuntimeConfigurationOutcome = callable.get();

            success = awsDescribeRuntimeConfigurationOutcome.IsSuccess();
                if (success) {
                    describeRuntimeConfigurationResult.fromAWS(awsDescribeRuntimeConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeRuntimeConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeRuntimeConfiguration error: " + awsDescribeRuntimeConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeRuntimeConfiguration Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeRuntimeConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FDescribeRuntimeConfigurationRequest describeRuntimeConfigurationRequest,
        FDescribeRuntimeConfigurationResult &describeRuntimeConfigurationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeRuntimeConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeRuntimeConfigurationAction(this->awsGameLiftClient,
                success,
                describeRuntimeConfigurationRequest,
                describeRuntimeConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeScalingPoliciesAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeScalingPoliciesResult &describeScalingPoliciesResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeScalingPoliciesOutcomeCallable callable;

public:
    FDescribeScalingPoliciesAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeScalingPoliciesRequest describeScalingPoliciesRequest,
        FDescribeScalingPoliciesResult &describeScalingPoliciesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeScalingPoliciesResult(describeScalingPoliciesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeScalingPoliciesCallable(describeScalingPoliciesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeScalingPoliciesOutcome = callable.get();

            success = awsDescribeScalingPoliciesOutcome.IsSuccess();
                if (success) {
                    describeScalingPoliciesResult.fromAWS(awsDescribeScalingPoliciesOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeScalingPoliciesOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeScalingPolicies error: " + awsDescribeScalingPoliciesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeScalingPolicies Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeScalingPolicies(
        UObject *WorldContextObject,
        bool &success,
        FDescribeScalingPoliciesRequest describeScalingPoliciesRequest,
        FDescribeScalingPoliciesResult &describeScalingPoliciesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeScalingPoliciesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeScalingPoliciesAction(this->awsGameLiftClient,
                success,
                describeScalingPoliciesRequest,
                describeScalingPoliciesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeScriptAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeScriptResult &describeScriptResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeScriptOutcomeCallable callable;

public:
    FDescribeScriptAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeScriptRequest describeScriptRequest,
        FDescribeScriptResult &describeScriptResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeScriptResult(describeScriptResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeScriptCallable(describeScriptRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeScriptOutcome = callable.get();

            success = awsDescribeScriptOutcome.IsSuccess();
                if (success) {
                    describeScriptResult.fromAWS(awsDescribeScriptOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeScriptOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeScript error: " + awsDescribeScriptOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeScript Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeScript(
        UObject *WorldContextObject,
        bool &success,
        FDescribeScriptRequest describeScriptRequest,
        FDescribeScriptResult &describeScriptResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeScriptAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeScriptAction(this->awsGameLiftClient,
                success,
                describeScriptRequest,
                describeScriptResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeVpcPeeringAuthorizationsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeVpcPeeringAuthorizationsResult &describeVpcPeeringAuthorizationsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeVpcPeeringAuthorizationsOutcomeCallable callable;

public:
    FDescribeVpcPeeringAuthorizationsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeVpcPeeringAuthorizationsRequest describeVpcPeeringAuthorizationsRequest,
        FDescribeVpcPeeringAuthorizationsResult &describeVpcPeeringAuthorizationsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeVpcPeeringAuthorizationsResult(describeVpcPeeringAuthorizationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeVpcPeeringAuthorizationsCallable(describeVpcPeeringAuthorizationsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeVpcPeeringAuthorizationsOutcome = callable.get();

            success = awsDescribeVpcPeeringAuthorizationsOutcome.IsSuccess();
                if (success) {
                    describeVpcPeeringAuthorizationsResult.fromAWS(awsDescribeVpcPeeringAuthorizationsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeVpcPeeringAuthorizationsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeVpcPeeringAuthorizations error: " + awsDescribeVpcPeeringAuthorizationsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeVpcPeeringAuthorizations Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeVpcPeeringAuthorizations(
        UObject *WorldContextObject,
        bool &success,
        FDescribeVpcPeeringAuthorizationsRequest describeVpcPeeringAuthorizationsRequest,
        FDescribeVpcPeeringAuthorizationsResult &describeVpcPeeringAuthorizationsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeVpcPeeringAuthorizationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeVpcPeeringAuthorizationsAction(this->awsGameLiftClient,
                success,
                describeVpcPeeringAuthorizationsRequest,
                describeVpcPeeringAuthorizationsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FDescribeVpcPeeringConnectionsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeVpcPeeringConnectionsResult &describeVpcPeeringConnectionsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::DescribeVpcPeeringConnectionsOutcomeCallable callable;

public:
    FDescribeVpcPeeringConnectionsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FDescribeVpcPeeringConnectionsRequest describeVpcPeeringConnectionsRequest,
        FDescribeVpcPeeringConnectionsResult &describeVpcPeeringConnectionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeVpcPeeringConnectionsResult(describeVpcPeeringConnectionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->DescribeVpcPeeringConnectionsCallable(describeVpcPeeringConnectionsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeVpcPeeringConnectionsOutcome = callable.get();

            success = awsDescribeVpcPeeringConnectionsOutcome.IsSuccess();
                if (success) {
                    describeVpcPeeringConnectionsResult.fromAWS(awsDescribeVpcPeeringConnectionsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeVpcPeeringConnectionsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeVpcPeeringConnections error: " + awsDescribeVpcPeeringConnectionsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeVpcPeeringConnections Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::DescribeVpcPeeringConnections(
        UObject *WorldContextObject,
        bool &success,
        FDescribeVpcPeeringConnectionsRequest describeVpcPeeringConnectionsRequest,
        FDescribeVpcPeeringConnectionsResult &describeVpcPeeringConnectionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeVpcPeeringConnectionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeVpcPeeringConnectionsAction(this->awsGameLiftClient,
                success,
                describeVpcPeeringConnectionsRequest,
                describeVpcPeeringConnectionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FGetComputeAccessAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftGetComputeAccessResult &getComputeAccessResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::GetComputeAccessOutcomeCallable callable;

public:
    FGetComputeAccessAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftGetComputeAccessRequest getComputeAccessRequest,
        FAWSGameLiftGetComputeAccessResult &getComputeAccessResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getComputeAccessResult(getComputeAccessResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->GetComputeAccessCallable(getComputeAccessRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetComputeAccessOutcome = callable.get();

            success = awsGetComputeAccessOutcome.IsSuccess();
                if (success) {
                    getComputeAccessResult.fromAWS(awsGetComputeAccessOutcome.GetResult());
                }

                errorType = fromAWS(awsGetComputeAccessOutcome.GetError().GetErrorType());
                errorMessage = ("GetComputeAccess error: " + awsGetComputeAccessOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetComputeAccess Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::GetComputeAccess(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftGetComputeAccessRequest getComputeAccessRequest,
    FAWSGameLiftGetComputeAccessResult &getComputeAccessResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetComputeAccessAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetComputeAccessAction(this->awsGameLiftClient,
                success,
                getComputeAccessRequest,
                getComputeAccessResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FGetComputeAuthTokenAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftGetComputeAuthTokenResult &getComputeAuthTokenResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::GetComputeAuthTokenOutcomeCallable callable;

public:
    FGetComputeAuthTokenAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftGetComputeAuthTokenRequest getComputeAuthTokenRequest,
        FAWSGameLiftGetComputeAuthTokenResult &getComputeAuthTokenResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getComputeAuthTokenResult(getComputeAuthTokenResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->GetComputeAuthTokenCallable(getComputeAuthTokenRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetComputeAuthTokenOutcome = callable.get();

            success = awsGetComputeAuthTokenOutcome.IsSuccess();
                if (success) {
                    getComputeAuthTokenResult.fromAWS(awsGetComputeAuthTokenOutcome.GetResult());
                }

                errorType = fromAWS(awsGetComputeAuthTokenOutcome.GetError().GetErrorType());
                errorMessage = ("GetComputeAuthToken error: " + awsGetComputeAuthTokenOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetComputeAuthToken Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::GetComputeAuthToken(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftGetComputeAuthTokenRequest getComputeAuthTokenRequest,
    FAWSGameLiftGetComputeAuthTokenResult &getComputeAuthTokenResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetComputeAuthTokenAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetComputeAuthTokenAction(this->awsGameLiftClient,
                success,
                getComputeAuthTokenRequest,
                getComputeAuthTokenResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FGetGameSessionLogUrlAction : public FPendingLatentAction {
private:
    bool &success;
    FGetGameSessionLogUrlResult &getGameSessionLogUrlResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::GetGameSessionLogUrlOutcomeCallable callable;

public:
    FGetGameSessionLogUrlAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FGetGameSessionLogUrlRequest getGameSessionLogUrlRequest,
        FGetGameSessionLogUrlResult &getGameSessionLogUrlResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getGameSessionLogUrlResult(getGameSessionLogUrlResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->GetGameSessionLogUrlCallable(getGameSessionLogUrlRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetGameSessionLogUrlOutcome = callable.get();

            success = awsGetGameSessionLogUrlOutcome.IsSuccess();
                if (success) {
                    getGameSessionLogUrlResult.fromAWS(awsGetGameSessionLogUrlOutcome.GetResult());
                }

                errorType = fromAWS(awsGetGameSessionLogUrlOutcome.GetError().GetErrorType());
                errorMessage = ("GetGameSessionLogUrl error: " + awsGetGameSessionLogUrlOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetGameSessionLogUrl Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::GetGameSessionLogUrl(
        UObject *WorldContextObject,
        bool &success,
        FGetGameSessionLogUrlRequest getGameSessionLogUrlRequest,
        FGetGameSessionLogUrlResult &getGameSessionLogUrlResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetGameSessionLogUrlAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetGameSessionLogUrlAction(this->awsGameLiftClient,
                success,
                getGameSessionLogUrlRequest,
                getGameSessionLogUrlResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FGetInstanceAccessAction : public FPendingLatentAction {
private:
    bool &success;
    FGetInstanceAccessResult &getInstanceAccessResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::GetInstanceAccessOutcomeCallable callable;

public:
    FGetInstanceAccessAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FGetInstanceAccessRequest getInstanceAccessRequest,
        FGetInstanceAccessResult &getInstanceAccessResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getInstanceAccessResult(getInstanceAccessResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->GetInstanceAccessCallable(getInstanceAccessRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetInstanceAccessOutcome = callable.get();

            success = awsGetInstanceAccessOutcome.IsSuccess();
                if (success) {
                    getInstanceAccessResult.fromAWS(awsGetInstanceAccessOutcome.GetResult());
                }

                errorType = fromAWS(awsGetInstanceAccessOutcome.GetError().GetErrorType());
                errorMessage = ("GetInstanceAccess error: " + awsGetInstanceAccessOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetInstanceAccess Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::GetInstanceAccess(
        UObject *WorldContextObject,
        bool &success,
        FGetInstanceAccessRequest getInstanceAccessRequest,
        FGetInstanceAccessResult &getInstanceAccessResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetInstanceAccessAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetInstanceAccessAction(this->awsGameLiftClient,
                success,
                getInstanceAccessRequest,
                getInstanceAccessResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FListAliasesAction : public FPendingLatentAction {
private:
    bool &success;
    FGameLiftListAliasesResult &listAliasesResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ListAliasesOutcomeCallable callable;

public:
    FListAliasesAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FGameLiftListAliasesRequest listAliasesRequest,
        FGameLiftListAliasesResult &listAliasesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listAliasesResult(listAliasesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ListAliasesCallable(listAliasesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListAliasesOutcome = callable.get();

            success = awsListAliasesOutcome.IsSuccess();
                if (success) {
                    listAliasesResult.fromAWS(awsListAliasesOutcome.GetResult());
                }

                errorType = fromAWS(awsListAliasesOutcome.GetError().GetErrorType());
                errorMessage = ("ListAliases error: " + awsListAliasesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListAliases Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ListAliases(
        UObject *WorldContextObject,
        bool &success,
        FGameLiftListAliasesRequest listAliasesRequest,
        FGameLiftListAliasesResult &listAliasesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListAliasesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListAliasesAction(this->awsGameLiftClient,
                success,
                listAliasesRequest,
                listAliasesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FListBuildsAction : public FPendingLatentAction {
private:
    bool &success;
    FListBuildsResult &listBuildsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ListBuildsOutcomeCallable callable;

public:
    FListBuildsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FListBuildsRequest listBuildsRequest,
        FListBuildsResult &listBuildsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBuildsResult(listBuildsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ListBuildsCallable(listBuildsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListBuildsOutcome = callable.get();

            success = awsListBuildsOutcome.IsSuccess();
                if (success) {
                    listBuildsResult.fromAWS(awsListBuildsOutcome.GetResult());
                }

                errorType = fromAWS(awsListBuildsOutcome.GetError().GetErrorType());
                errorMessage = ("ListBuilds error: " + awsListBuildsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListBuilds Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ListBuilds(
        UObject *WorldContextObject,
        bool &success,
        FListBuildsRequest listBuildsRequest,
        FListBuildsResult &listBuildsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBuildsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBuildsAction(this->awsGameLiftClient,
                success,
                listBuildsRequest,
                listBuildsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FListComputeAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftListComputeResult &listComputeResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ListComputeOutcomeCallable callable;

public:
    FListComputeAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftListComputeRequest listComputeRequest,
        FAWSGameLiftListComputeResult &listComputeResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listComputeResult(listComputeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ListComputeCallable(listComputeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListComputeOutcome = callable.get();

            success = awsListComputeOutcome.IsSuccess();
                if (success) {
                    listComputeResult.fromAWS(awsListComputeOutcome.GetResult());
                }

                errorType = fromAWS(awsListComputeOutcome.GetError().GetErrorType());
                errorMessage = ("ListCompute error: " + awsListComputeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListCompute Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ListCompute(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftListComputeRequest listComputeRequest,
    FAWSGameLiftListComputeResult &listComputeResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListComputeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListComputeAction(this->awsGameLiftClient,
                success,
                listComputeRequest,
                listComputeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FListFleetsAction : public FPendingLatentAction {
private:
    bool &success;
    FListFleetsResult &listFleetsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ListFleetsOutcomeCallable callable;

public:
    FListFleetsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FListFleetsRequest listFleetsRequest,
        FListFleetsResult &listFleetsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listFleetsResult(listFleetsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ListFleetsCallable(listFleetsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListFleetsOutcome = callable.get();

            success = awsListFleetsOutcome.IsSuccess();
                if (success) {
                    listFleetsResult.fromAWS(awsListFleetsOutcome.GetResult());
                }

                errorType = fromAWS(awsListFleetsOutcome.GetError().GetErrorType());
                errorMessage = ("ListFleets error: " + awsListFleetsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListFleets Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ListFleets(
        UObject *WorldContextObject,
        bool &success,
        FListFleetsRequest listFleetsRequest,
        FListFleetsResult &listFleetsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListFleetsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListFleetsAction(this->awsGameLiftClient,
                success,
                listFleetsRequest,
                listFleetsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FListGameServerGroupsAction : public FPendingLatentAction {
private:
    bool &success;
    FListGameServerGroupsResult &listGameServerGroupsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ListGameServerGroupsOutcomeCallable callable;

public:
    FListGameServerGroupsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FListGameServerGroupsRequest listGameServerGroupsRequest,
        FListGameServerGroupsResult &listGameServerGroupsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listGameServerGroupsResult(listGameServerGroupsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ListGameServerGroupsCallable(listGameServerGroupsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListGameServerGroupsOutcome = callable.get();

            success = awsListGameServerGroupsOutcome.IsSuccess();
                if (success) {
                    listGameServerGroupsResult.fromAWS(awsListGameServerGroupsOutcome.GetResult());
                }

                errorType = fromAWS(awsListGameServerGroupsOutcome.GetError().GetErrorType());
                errorMessage = ("ListGameServerGroups error: " + awsListGameServerGroupsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListGameServerGroups Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ListGameServerGroups(
        UObject *WorldContextObject,
        bool &success,
        FListGameServerGroupsRequest listGameServerGroupsRequest,
        FListGameServerGroupsResult &listGameServerGroupsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListGameServerGroupsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListGameServerGroupsAction(this->awsGameLiftClient,
                success,
                listGameServerGroupsRequest,
                listGameServerGroupsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FListGameServersAction : public FPendingLatentAction {
private:
    bool &success;
    FListGameServersResult &listGameServersResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ListGameServersOutcomeCallable callable;

public:
    FListGameServersAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FListGameServersRequest listGameServersRequest,
        FListGameServersResult &listGameServersResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listGameServersResult(listGameServersResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ListGameServersCallable(listGameServersRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListGameServersOutcome = callable.get();

            success = awsListGameServersOutcome.IsSuccess();
                if (success) {
                    listGameServersResult.fromAWS(awsListGameServersOutcome.GetResult());
                }

                errorType = fromAWS(awsListGameServersOutcome.GetError().GetErrorType());
                errorMessage = ("ListGameServers error: " + awsListGameServersOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListGameServers Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ListGameServers(
        UObject *WorldContextObject,
        bool &success,
        FListGameServersRequest listGameServersRequest,
        FListGameServersResult &listGameServersResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListGameServersAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListGameServersAction(this->awsGameLiftClient,
                success,
                listGameServersRequest,
                listGameServersResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FListLocationsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftListLocationsResult &listLocationsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ListLocationsOutcomeCallable callable;

public:
    FListLocationsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftListLocationsRequest listLocationsRequest,
        FAWSGameLiftListLocationsResult &listLocationsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listLocationsResult(listLocationsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ListLocationsCallable(listLocationsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListLocationsOutcome = callable.get();

            success = awsListLocationsOutcome.IsSuccess();
                if (success) {
                    listLocationsResult.fromAWS(awsListLocationsOutcome.GetResult());
                }

                errorType = fromAWS(awsListLocationsOutcome.GetError().GetErrorType());
                errorMessage = ("ListLocations error: " + awsListLocationsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListLocations Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ListLocations(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftListLocationsRequest listLocationsRequest,
    FAWSGameLiftListLocationsResult &listLocationsResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListLocationsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListLocationsAction(this->awsGameLiftClient,
                success,
                listLocationsRequest,
                listLocationsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FListScriptsAction : public FPendingLatentAction {
private:
    bool &success;
    FListScriptsResult &listScriptsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ListScriptsOutcomeCallable callable;

public:
    FListScriptsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FListScriptsRequest listScriptsRequest,
        FListScriptsResult &listScriptsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listScriptsResult(listScriptsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ListScriptsCallable(listScriptsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListScriptsOutcome = callable.get();

            success = awsListScriptsOutcome.IsSuccess();
                if (success) {
                    listScriptsResult.fromAWS(awsListScriptsOutcome.GetResult());
                }

                errorType = fromAWS(awsListScriptsOutcome.GetError().GetErrorType());
                errorMessage = ("ListScripts error: " + awsListScriptsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListScripts Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ListScripts(
        UObject *WorldContextObject,
        bool &success,
        FListScriptsRequest listScriptsRequest,
        FListScriptsResult &listScriptsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListScriptsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListScriptsAction(this->awsGameLiftClient,
                success,
                listScriptsRequest,
                listScriptsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FListTagsForResourceAction : public FPendingLatentAction {
private:
    bool &success;
    FGameLiftListTagsForResourceResult &listTagsForResourceResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ListTagsForResourceOutcomeCallable callable;

public:
    FListTagsForResourceAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FGameLiftListTagsForResourceRequest listTagsForResourceRequest,
        FGameLiftListTagsForResourceResult &listTagsForResourceResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listTagsForResourceResult(listTagsForResourceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ListTagsForResourceCallable(listTagsForResourceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListTagsForResourceOutcome = callable.get();

            success = awsListTagsForResourceOutcome.IsSuccess();
                if (success) {
                    listTagsForResourceResult.fromAWS(awsListTagsForResourceOutcome.GetResult());
                }

                errorType = fromAWS(awsListTagsForResourceOutcome.GetError().GetErrorType());
                errorMessage = ("ListTagsForResource error: " + awsListTagsForResourceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListTagsForResource Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ListTagsForResource(
        UObject *WorldContextObject,
        bool &success,
        FGameLiftListTagsForResourceRequest listTagsForResourceRequest,
        FGameLiftListTagsForResourceResult &listTagsForResourceResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListTagsForResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListTagsForResourceAction(this->awsGameLiftClient,
                success,
                listTagsForResourceRequest,
                listTagsForResourceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FPutScalingPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    FPutScalingPolicyResult &putScalingPolicyResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::PutScalingPolicyOutcomeCallable callable;

public:
    FPutScalingPolicyAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FPutScalingPolicyRequest putScalingPolicyRequest,
        FPutScalingPolicyResult &putScalingPolicyResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putScalingPolicyResult(putScalingPolicyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->PutScalingPolicyCallable(putScalingPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutScalingPolicyOutcome = callable.get();

            success = awsPutScalingPolicyOutcome.IsSuccess();
                if (success) {
                    putScalingPolicyResult.fromAWS(awsPutScalingPolicyOutcome.GetResult());
                }

                errorType = fromAWS(awsPutScalingPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("PutScalingPolicy error: " + awsPutScalingPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutScalingPolicy Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::PutScalingPolicy(
        UObject *WorldContextObject,
        bool &success,
        FPutScalingPolicyRequest putScalingPolicyRequest,
        FPutScalingPolicyResult &putScalingPolicyResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutScalingPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutScalingPolicyAction(this->awsGameLiftClient,
                success,
                putScalingPolicyRequest,
                putScalingPolicyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FRegisterComputeAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSGameLiftRegisterComputeResult &registerComputeResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::RegisterComputeOutcomeCallable callable;

public:
    FRegisterComputeAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FAWSGameLiftRegisterComputeRequest registerComputeRequest,
        FAWSGameLiftRegisterComputeResult &registerComputeResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), registerComputeResult(registerComputeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->RegisterComputeCallable(registerComputeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsRegisterComputeOutcome = callable.get();

            success = awsRegisterComputeOutcome.IsSuccess();
                if (success) {
                    registerComputeResult.fromAWS(awsRegisterComputeOutcome.GetResult());
                }

                errorType = fromAWS(awsRegisterComputeOutcome.GetError().GetErrorType());
                errorMessage = ("RegisterCompute error: " + awsRegisterComputeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RegisterCompute Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::RegisterCompute(
    UObject *WorldContextObject,
    bool &success,
    FAWSGameLiftRegisterComputeRequest registerComputeRequest,
    FAWSGameLiftRegisterComputeResult &registerComputeResult,
    EGameLiftError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRegisterComputeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRegisterComputeAction(this->awsGameLiftClient,
                success,
                registerComputeRequest,
                registerComputeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FRegisterGameServerAction : public FPendingLatentAction {
private:
    bool &success;
    FRegisterGameServerResult &registerGameServerResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::RegisterGameServerOutcomeCallable callable;

public:
    FRegisterGameServerAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FRegisterGameServerRequest registerGameServerRequest,
        FRegisterGameServerResult &registerGameServerResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), registerGameServerResult(registerGameServerResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->RegisterGameServerCallable(registerGameServerRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsRegisterGameServerOutcome = callable.get();

            success = awsRegisterGameServerOutcome.IsSuccess();
                if (success) {
                    registerGameServerResult.fromAWS(awsRegisterGameServerOutcome.GetResult());
                }

                errorType = fromAWS(awsRegisterGameServerOutcome.GetError().GetErrorType());
                errorMessage = ("RegisterGameServer error: " + awsRegisterGameServerOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RegisterGameServer Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::RegisterGameServer(
        UObject *WorldContextObject,
        bool &success,
        FRegisterGameServerRequest registerGameServerRequest,
        FRegisterGameServerResult &registerGameServerResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRegisterGameServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRegisterGameServerAction(this->awsGameLiftClient,
                success,
                registerGameServerRequest,
                registerGameServerResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FRequestUploadCredentialsAction : public FPendingLatentAction {
private:
    bool &success;
    FRequestUploadCredentialsResult &requestUploadCredentialsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::RequestUploadCredentialsOutcomeCallable callable;

public:
    FRequestUploadCredentialsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FRequestUploadCredentialsRequest requestUploadCredentialsRequest,
        FRequestUploadCredentialsResult &requestUploadCredentialsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), requestUploadCredentialsResult(requestUploadCredentialsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->RequestUploadCredentialsCallable(requestUploadCredentialsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsRequestUploadCredentialsOutcome = callable.get();

            success = awsRequestUploadCredentialsOutcome.IsSuccess();
                if (success) {
                    requestUploadCredentialsResult.fromAWS(awsRequestUploadCredentialsOutcome.GetResult());
                }

                errorType = fromAWS(awsRequestUploadCredentialsOutcome.GetError().GetErrorType());
                errorMessage = ("RequestUploadCredentials error: " + awsRequestUploadCredentialsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RequestUploadCredentials Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::RequestUploadCredentials(
        UObject *WorldContextObject,
        bool &success,
        FRequestUploadCredentialsRequest requestUploadCredentialsRequest,
        FRequestUploadCredentialsResult &requestUploadCredentialsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRequestUploadCredentialsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRequestUploadCredentialsAction(this->awsGameLiftClient,
                success,
                requestUploadCredentialsRequest,
                requestUploadCredentialsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FResolveAliasAction : public FPendingLatentAction {
private:
    bool &success;
    FResolveAliasResult &resolveAliasResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ResolveAliasOutcomeCallable callable;

public:
    FResolveAliasAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FResolveAliasRequest resolveAliasRequest,
        FResolveAliasResult &resolveAliasResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), resolveAliasResult(resolveAliasResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ResolveAliasCallable(resolveAliasRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsResolveAliasOutcome = callable.get();

            success = awsResolveAliasOutcome.IsSuccess();
                if (success) {
                    resolveAliasResult.fromAWS(awsResolveAliasOutcome.GetResult());
                }

                errorType = fromAWS(awsResolveAliasOutcome.GetError().GetErrorType());
                errorMessage = ("ResolveAlias error: " + awsResolveAliasOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ResolveAlias Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ResolveAlias(
        UObject *WorldContextObject,
        bool &success,
        FResolveAliasRequest resolveAliasRequest,
        FResolveAliasResult &resolveAliasResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FResolveAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FResolveAliasAction(this->awsGameLiftClient,
                success,
                resolveAliasRequest,
                resolveAliasResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FResumeGameServerGroupAction : public FPendingLatentAction {
private:
    bool &success;
    FResumeGameServerGroupResult &resumeGameServerGroupResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ResumeGameServerGroupOutcomeCallable callable;

public:
    FResumeGameServerGroupAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FResumeGameServerGroupRequest resumeGameServerGroupRequest,
        FResumeGameServerGroupResult &resumeGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), resumeGameServerGroupResult(resumeGameServerGroupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ResumeGameServerGroupCallable(resumeGameServerGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsResumeGameServerGroupOutcome = callable.get();

            success = awsResumeGameServerGroupOutcome.IsSuccess();
                if (success) {
                    resumeGameServerGroupResult.fromAWS(awsResumeGameServerGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsResumeGameServerGroupOutcome.GetError().GetErrorType());
                errorMessage = ("ResumeGameServerGroup error: " + awsResumeGameServerGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ResumeGameServerGroup Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ResumeGameServerGroup(
        UObject *WorldContextObject,
        bool &success,
        FResumeGameServerGroupRequest resumeGameServerGroupRequest,
        FResumeGameServerGroupResult &resumeGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FResumeGameServerGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FResumeGameServerGroupAction(this->awsGameLiftClient,
                success,
                resumeGameServerGroupRequest,
                resumeGameServerGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FSearchGameSessionsAction : public FPendingLatentAction {
private:
    bool &success;
    FSearchGameSessionsResult &searchGameSessionsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::SearchGameSessionsOutcomeCallable callable;

public:
    FSearchGameSessionsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FSearchGameSessionsRequest searchGameSessionsRequest,
        FSearchGameSessionsResult &searchGameSessionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), searchGameSessionsResult(searchGameSessionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->SearchGameSessionsCallable(searchGameSessionsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSearchGameSessionsOutcome = callable.get();

            success = awsSearchGameSessionsOutcome.IsSuccess();
                if (success) {
                    searchGameSessionsResult.fromAWS(awsSearchGameSessionsOutcome.GetResult());
                }

                errorType = fromAWS(awsSearchGameSessionsOutcome.GetError().GetErrorType());
                errorMessage = ("SearchGameSessions error: " + awsSearchGameSessionsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SearchGameSessions Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::SearchGameSessions(
        UObject *WorldContextObject,
        bool &success,
        FSearchGameSessionsRequest searchGameSessionsRequest,
        FSearchGameSessionsResult &searchGameSessionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSearchGameSessionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSearchGameSessionsAction(this->awsGameLiftClient,
                success,
                searchGameSessionsRequest,
                searchGameSessionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FStartFleetActionsAction : public FPendingLatentAction {
private:
    bool &success;
    FStartFleetActionsResult &startFleetActionsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::StartFleetActionsOutcomeCallable callable;

public:
    FStartFleetActionsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FStartFleetActionsRequest startFleetActionsRequest,
        FStartFleetActionsResult &startFleetActionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), startFleetActionsResult(startFleetActionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->StartFleetActionsCallable(startFleetActionsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsStartFleetActionsOutcome = callable.get();

            success = awsStartFleetActionsOutcome.IsSuccess();
                if (success) {
                    startFleetActionsResult.fromAWS(awsStartFleetActionsOutcome.GetResult());
                }

                errorType = fromAWS(awsStartFleetActionsOutcome.GetError().GetErrorType());
                errorMessage = ("StartFleetActions error: " + awsStartFleetActionsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StartFleetActions Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::StartFleetActions(
        UObject *WorldContextObject,
        bool &success,
        FStartFleetActionsRequest startFleetActionsRequest,
        FStartFleetActionsResult &startFleetActionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStartFleetActionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStartFleetActionsAction(this->awsGameLiftClient,
                success,
                startFleetActionsRequest,
                startFleetActionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FStartGameSessionPlacementAction : public FPendingLatentAction {
private:
    bool &success;
    FStartGameSessionPlacementResult &startGameSessionPlacementResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::StartGameSessionPlacementOutcomeCallable callable;

public:
    FStartGameSessionPlacementAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FStartGameSessionPlacementRequest startGameSessionPlacementRequest,
        FStartGameSessionPlacementResult &startGameSessionPlacementResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), startGameSessionPlacementResult(startGameSessionPlacementResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->StartGameSessionPlacementCallable(startGameSessionPlacementRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsStartGameSessionPlacementOutcome = callable.get();

            success = awsStartGameSessionPlacementOutcome.IsSuccess();
                if (success) {
                    startGameSessionPlacementResult.fromAWS(awsStartGameSessionPlacementOutcome.GetResult());
                }

                errorType = fromAWS(awsStartGameSessionPlacementOutcome.GetError().GetErrorType());
                errorMessage = ("StartGameSessionPlacement error: " + awsStartGameSessionPlacementOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StartGameSessionPlacement Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::StartGameSessionPlacement(
        UObject *WorldContextObject,
        bool &success,
        FStartGameSessionPlacementRequest startGameSessionPlacementRequest,
        FStartGameSessionPlacementResult &startGameSessionPlacementResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStartGameSessionPlacementAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStartGameSessionPlacementAction(this->awsGameLiftClient,
                success,
                startGameSessionPlacementRequest,
                startGameSessionPlacementResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FStartMatchBackfillAction : public FPendingLatentAction {
private:
    bool &success;
    FStartMatchBackfillResult &startMatchBackfillResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::StartMatchBackfillOutcomeCallable callable;

public:
    FStartMatchBackfillAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FStartMatchBackfillRequest startMatchBackfillRequest,
        FStartMatchBackfillResult &startMatchBackfillResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), startMatchBackfillResult(startMatchBackfillResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->StartMatchBackfillCallable(startMatchBackfillRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsStartMatchBackfillOutcome = callable.get();

            success = awsStartMatchBackfillOutcome.IsSuccess();
                if (success) {
                    startMatchBackfillResult.fromAWS(awsStartMatchBackfillOutcome.GetResult());
                }

                errorType = fromAWS(awsStartMatchBackfillOutcome.GetError().GetErrorType());
                errorMessage = ("StartMatchBackfill error: " + awsStartMatchBackfillOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StartMatchBackfill Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::StartMatchBackfill(
        UObject *WorldContextObject,
        bool &success,
        FStartMatchBackfillRequest startMatchBackfillRequest,
        FStartMatchBackfillResult &startMatchBackfillResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStartMatchBackfillAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStartMatchBackfillAction(this->awsGameLiftClient,
                success,
                startMatchBackfillRequest,
                startMatchBackfillResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FStartMatchmakingAction : public FPendingLatentAction {
private:
    bool &success;
    FStartMatchmakingResult &startMatchmakingResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::StartMatchmakingOutcomeCallable callable;

public:
    FStartMatchmakingAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FStartMatchmakingRequest startMatchmakingRequest,
        FStartMatchmakingResult &startMatchmakingResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), startMatchmakingResult(startMatchmakingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->StartMatchmakingCallable(startMatchmakingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsStartMatchmakingOutcome = callable.get();

            success = awsStartMatchmakingOutcome.IsSuccess();
                if (success) {
                    startMatchmakingResult.fromAWS(awsStartMatchmakingOutcome.GetResult());
                }

                errorType = fromAWS(awsStartMatchmakingOutcome.GetError().GetErrorType());
                errorMessage = ("StartMatchmaking error: " + awsStartMatchmakingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StartMatchmaking Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::StartMatchmaking(
        UObject *WorldContextObject,
        bool &success,
        FStartMatchmakingRequest startMatchmakingRequest,
        FStartMatchmakingResult &startMatchmakingResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStartMatchmakingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStartMatchmakingAction(this->awsGameLiftClient,
                success,
                startMatchmakingRequest,
                startMatchmakingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FStopFleetActionsAction : public FPendingLatentAction {
private:
    bool &success;
    FStopFleetActionsResult &stopFleetActionsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::StopFleetActionsOutcomeCallable callable;

public:
    FStopFleetActionsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FStopFleetActionsRequest stopFleetActionsRequest,
        FStopFleetActionsResult &stopFleetActionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), stopFleetActionsResult(stopFleetActionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->StopFleetActionsCallable(stopFleetActionsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsStopFleetActionsOutcome = callable.get();

            success = awsStopFleetActionsOutcome.IsSuccess();
                if (success) {
                    stopFleetActionsResult.fromAWS(awsStopFleetActionsOutcome.GetResult());
                }

                errorType = fromAWS(awsStopFleetActionsOutcome.GetError().GetErrorType());
                errorMessage = ("StopFleetActions error: " + awsStopFleetActionsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StopFleetActions Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::StopFleetActions(
        UObject *WorldContextObject,
        bool &success,
        FStopFleetActionsRequest stopFleetActionsRequest,
        FStopFleetActionsResult &stopFleetActionsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStopFleetActionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStopFleetActionsAction(this->awsGameLiftClient,
                success,
                stopFleetActionsRequest,
                stopFleetActionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FStopGameSessionPlacementAction : public FPendingLatentAction {
private:
    bool &success;
    FStopGameSessionPlacementResult &stopGameSessionPlacementResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::StopGameSessionPlacementOutcomeCallable callable;

public:
    FStopGameSessionPlacementAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FStopGameSessionPlacementRequest stopGameSessionPlacementRequest,
        FStopGameSessionPlacementResult &stopGameSessionPlacementResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), stopGameSessionPlacementResult(stopGameSessionPlacementResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->StopGameSessionPlacementCallable(stopGameSessionPlacementRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsStopGameSessionPlacementOutcome = callable.get();

            success = awsStopGameSessionPlacementOutcome.IsSuccess();
                if (success) {
                    stopGameSessionPlacementResult.fromAWS(awsStopGameSessionPlacementOutcome.GetResult());
                }

                errorType = fromAWS(awsStopGameSessionPlacementOutcome.GetError().GetErrorType());
                errorMessage = ("StopGameSessionPlacement error: " + awsStopGameSessionPlacementOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StopGameSessionPlacement Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::StopGameSessionPlacement(
        UObject *WorldContextObject,
        bool &success,
        FStopGameSessionPlacementRequest stopGameSessionPlacementRequest,
        FStopGameSessionPlacementResult &stopGameSessionPlacementResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStopGameSessionPlacementAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStopGameSessionPlacementAction(this->awsGameLiftClient,
                success,
                stopGameSessionPlacementRequest,
                stopGameSessionPlacementResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FStopMatchmakingAction : public FPendingLatentAction {
private:
    bool &success;
    FStopMatchmakingResult &stopMatchmakingResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::StopMatchmakingOutcomeCallable callable;

public:
    FStopMatchmakingAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FStopMatchmakingRequest stopMatchmakingRequest,
        FStopMatchmakingResult &stopMatchmakingResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), stopMatchmakingResult(stopMatchmakingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->StopMatchmakingCallable(stopMatchmakingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsStopMatchmakingOutcome = callable.get();

            success = awsStopMatchmakingOutcome.IsSuccess();
                if (success) {
                    stopMatchmakingResult.fromAWS(awsStopMatchmakingOutcome.GetResult());
                }

                errorType = fromAWS(awsStopMatchmakingOutcome.GetError().GetErrorType());
                errorMessage = ("StopMatchmaking error: " + awsStopMatchmakingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StopMatchmaking Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::StopMatchmaking(
        UObject *WorldContextObject,
        bool &success,
        FStopMatchmakingRequest stopMatchmakingRequest,
        FStopMatchmakingResult &stopMatchmakingResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStopMatchmakingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStopMatchmakingAction(this->awsGameLiftClient,
                success,
                stopMatchmakingRequest,
                stopMatchmakingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FSuspendGameServerGroupAction : public FPendingLatentAction {
private:
    bool &success;
    FSuspendGameServerGroupResult &suspendGameServerGroupResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::SuspendGameServerGroupOutcomeCallable callable;

public:
    FSuspendGameServerGroupAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FSuspendGameServerGroupRequest suspendGameServerGroupRequest,
        FSuspendGameServerGroupResult &suspendGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), suspendGameServerGroupResult(suspendGameServerGroupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->SuspendGameServerGroupCallable(suspendGameServerGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSuspendGameServerGroupOutcome = callable.get();

            success = awsSuspendGameServerGroupOutcome.IsSuccess();
                if (success) {
                    suspendGameServerGroupResult.fromAWS(awsSuspendGameServerGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsSuspendGameServerGroupOutcome.GetError().GetErrorType());
                errorMessage = ("SuspendGameServerGroup error: " + awsSuspendGameServerGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SuspendGameServerGroup Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::SuspendGameServerGroup(
        UObject *WorldContextObject,
        bool &success,
        FSuspendGameServerGroupRequest suspendGameServerGroupRequest,
        FSuspendGameServerGroupResult &suspendGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSuspendGameServerGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSuspendGameServerGroupAction(this->awsGameLiftClient,
                success,
                suspendGameServerGroupRequest,
                suspendGameServerGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FTagResourceAction : public FPendingLatentAction {
private:
    bool &success;
    FGameLiftTagResourceResult &tagResourceResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::TagResourceOutcomeCallable callable;

public:
    FTagResourceAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FGameLiftTagResourceRequest tagResourceRequest,
        FGameLiftTagResourceResult &tagResourceResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), tagResourceResult(tagResourceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->TagResourceCallable(tagResourceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsTagResourceOutcome = callable.get();

            success = awsTagResourceOutcome.IsSuccess();
                if (success) {
                    tagResourceResult.fromAWS(awsTagResourceOutcome.GetResult());
                }

                errorType = fromAWS(awsTagResourceOutcome.GetError().GetErrorType());
                errorMessage = ("TagResource error: " + awsTagResourceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("TagResource Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::TagResource(
        UObject *WorldContextObject,
        bool &success,
        FGameLiftTagResourceRequest tagResourceRequest,
        FGameLiftTagResourceResult &tagResourceResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FTagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FTagResourceAction(this->awsGameLiftClient,
                success,
                tagResourceRequest,
                tagResourceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUntagResourceAction : public FPendingLatentAction {
private:
    bool &success;
    FUntagResourceResult &untagResourceResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UntagResourceOutcomeCallable callable;

public:
    FUntagResourceAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FGameLiftUntagResourceRequest untagResourceRequest,
        FUntagResourceResult &untagResourceResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), untagResourceResult(untagResourceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UntagResourceCallable(untagResourceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUntagResourceOutcome = callable.get();

            success = awsUntagResourceOutcome.IsSuccess();
                if (success) {
                    untagResourceResult.fromAWS(awsUntagResourceOutcome.GetResult());
                }

                errorType = fromAWS(awsUntagResourceOutcome.GetError().GetErrorType());
                errorMessage = ("UntagResource error: " + awsUntagResourceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UntagResource Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UntagResource(
        UObject *WorldContextObject,
        bool &success,
        FGameLiftUntagResourceRequest untagResourceRequest,
        FUntagResourceResult &untagResourceResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUntagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUntagResourceAction(this->awsGameLiftClient,
                success,
                untagResourceRequest,
                untagResourceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateAliasAction : public FPendingLatentAction {
private:
    bool &success;
    FGameLiftUpdateAliasResult &updateAliasResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateAliasOutcomeCallable callable;

public:
    FUpdateAliasAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FGameLiftUpdateAliasRequest updateAliasRequest,
        FGameLiftUpdateAliasResult &updateAliasResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateAliasResult(updateAliasResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateAliasCallable(updateAliasRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateAliasOutcome = callable.get();

            success = awsUpdateAliasOutcome.IsSuccess();
                if (success) {
                    updateAliasResult.fromAWS(awsUpdateAliasOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateAliasOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateAlias error: " + awsUpdateAliasOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateAlias Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateAlias(
        UObject *WorldContextObject,
        bool &success,
        FGameLiftUpdateAliasRequest updateAliasRequest,
        FGameLiftUpdateAliasResult &updateAliasResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateAliasAction(this->awsGameLiftClient,
                success,
                updateAliasRequest,
                updateAliasResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateBuildAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateBuildResult &updateBuildResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateBuildOutcomeCallable callable;

public:
    FUpdateBuildAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateBuildRequest updateBuildRequest,
        FUpdateBuildResult &updateBuildResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateBuildResult(updateBuildResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateBuildCallable(updateBuildRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateBuildOutcome = callable.get();

            success = awsUpdateBuildOutcome.IsSuccess();
                if (success) {
                    updateBuildResult.fromAWS(awsUpdateBuildOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateBuildOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateBuild error: " + awsUpdateBuildOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateBuild Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateBuild(
        UObject *WorldContextObject,
        bool &success,
        FUpdateBuildRequest updateBuildRequest,
        FUpdateBuildResult &updateBuildResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateBuildAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateBuildAction(this->awsGameLiftClient,
                success,
                updateBuildRequest,
                updateBuildResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateFleetAttributesAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateFleetAttributesResult &updateFleetAttributesResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateFleetAttributesOutcomeCallable callable;

public:
    FUpdateFleetAttributesAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateFleetAttributesRequest updateFleetAttributesRequest,
        FUpdateFleetAttributesResult &updateFleetAttributesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateFleetAttributesResult(updateFleetAttributesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateFleetAttributesCallable(updateFleetAttributesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateFleetAttributesOutcome = callable.get();

            success = awsUpdateFleetAttributesOutcome.IsSuccess();
                if (success) {
                    updateFleetAttributesResult.fromAWS(awsUpdateFleetAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateFleetAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateFleetAttributes error: " + awsUpdateFleetAttributesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateFleetAttributes Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateFleetAttributes(
        UObject *WorldContextObject,
        bool &success,
        FUpdateFleetAttributesRequest updateFleetAttributesRequest,
        FUpdateFleetAttributesResult &updateFleetAttributesResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateFleetAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateFleetAttributesAction(this->awsGameLiftClient,
                success,
                updateFleetAttributesRequest,
                updateFleetAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateFleetCapacityAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateFleetCapacityResult &updateFleetCapacityResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateFleetCapacityOutcomeCallable callable;

public:
    FUpdateFleetCapacityAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateFleetCapacityRequest updateFleetCapacityRequest,
        FUpdateFleetCapacityResult &updateFleetCapacityResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateFleetCapacityResult(updateFleetCapacityResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateFleetCapacityCallable(updateFleetCapacityRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateFleetCapacityOutcome = callable.get();

            success = awsUpdateFleetCapacityOutcome.IsSuccess();
                if (success) {
                    updateFleetCapacityResult.fromAWS(awsUpdateFleetCapacityOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateFleetCapacityOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateFleetCapacity error: " + awsUpdateFleetCapacityOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateFleetCapacity Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateFleetCapacity(
        UObject *WorldContextObject,
        bool &success,
        FUpdateFleetCapacityRequest updateFleetCapacityRequest,
        FUpdateFleetCapacityResult &updateFleetCapacityResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateFleetCapacityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateFleetCapacityAction(this->awsGameLiftClient,
                success,
                updateFleetCapacityRequest,
                updateFleetCapacityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateFleetPortSettingsAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateFleetPortSettingsResult &updateFleetPortSettingsResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateFleetPortSettingsOutcomeCallable callable;

public:
    FUpdateFleetPortSettingsAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateFleetPortSettingsRequest updateFleetPortSettingsRequest,
        FUpdateFleetPortSettingsResult &updateFleetPortSettingsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateFleetPortSettingsResult(updateFleetPortSettingsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateFleetPortSettingsCallable(updateFleetPortSettingsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateFleetPortSettingsOutcome = callable.get();

            success = awsUpdateFleetPortSettingsOutcome.IsSuccess();
                if (success) {
                    updateFleetPortSettingsResult.fromAWS(awsUpdateFleetPortSettingsOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateFleetPortSettingsOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateFleetPortSettings error: " + awsUpdateFleetPortSettingsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateFleetPortSettings Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateFleetPortSettings(
        UObject *WorldContextObject,
        bool &success,
        FUpdateFleetPortSettingsRequest updateFleetPortSettingsRequest,
        FUpdateFleetPortSettingsResult &updateFleetPortSettingsResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateFleetPortSettingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateFleetPortSettingsAction(this->awsGameLiftClient,
                success,
                updateFleetPortSettingsRequest,
                updateFleetPortSettingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateGameServerAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateGameServerResult &updateGameServerResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateGameServerOutcomeCallable callable;

public:
    FUpdateGameServerAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateGameServerRequest updateGameServerRequest,
        FUpdateGameServerResult &updateGameServerResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateGameServerResult(updateGameServerResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateGameServerCallable(updateGameServerRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateGameServerOutcome = callable.get();

            success = awsUpdateGameServerOutcome.IsSuccess();
                if (success) {
                    updateGameServerResult.fromAWS(awsUpdateGameServerOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateGameServerOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateGameServer error: " + awsUpdateGameServerOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateGameServer Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateGameServer(
        UObject *WorldContextObject,
        bool &success,
        FUpdateGameServerRequest updateGameServerRequest,
        FUpdateGameServerResult &updateGameServerResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateGameServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateGameServerAction(this->awsGameLiftClient,
                success,
                updateGameServerRequest,
                updateGameServerResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateGameServerGroupAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateGameServerGroupResult &updateGameServerGroupResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateGameServerGroupOutcomeCallable callable;

public:
    FUpdateGameServerGroupAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateGameServerGroupRequest updateGameServerGroupRequest,
        FUpdateGameServerGroupResult &updateGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateGameServerGroupResult(updateGameServerGroupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateGameServerGroupCallable(updateGameServerGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateGameServerGroupOutcome = callable.get();

            success = awsUpdateGameServerGroupOutcome.IsSuccess();
                if (success) {
                    updateGameServerGroupResult.fromAWS(awsUpdateGameServerGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateGameServerGroupOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateGameServerGroup error: " + awsUpdateGameServerGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateGameServerGroup Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateGameServerGroup(
        UObject *WorldContextObject,
        bool &success,
        FUpdateGameServerGroupRequest updateGameServerGroupRequest,
        FUpdateGameServerGroupResult &updateGameServerGroupResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateGameServerGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateGameServerGroupAction(this->awsGameLiftClient,
                success,
                updateGameServerGroupRequest,
                updateGameServerGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateGameSessionAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateGameSessionResult &updateGameSessionResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateGameSessionOutcomeCallable callable;

public:
    FUpdateGameSessionAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateGameSessionRequest updateGameSessionRequest,
        FUpdateGameSessionResult &updateGameSessionResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateGameSessionResult(updateGameSessionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateGameSessionCallable(updateGameSessionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateGameSessionOutcome = callable.get();

            success = awsUpdateGameSessionOutcome.IsSuccess();
                if (success) {
                    updateGameSessionResult.fromAWS(awsUpdateGameSessionOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateGameSessionOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateGameSession error: " + awsUpdateGameSessionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateGameSession Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateGameSession(
        UObject *WorldContextObject,
        bool &success,
        FUpdateGameSessionRequest updateGameSessionRequest,
        FUpdateGameSessionResult &updateGameSessionResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateGameSessionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateGameSessionAction(this->awsGameLiftClient,
                success,
                updateGameSessionRequest,
                updateGameSessionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateGameSessionQueueAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateGameSessionQueueResult &updateGameSessionQueueResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateGameSessionQueueOutcomeCallable callable;

public:
    FUpdateGameSessionQueueAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateGameSessionQueueRequest updateGameSessionQueueRequest,
        FUpdateGameSessionQueueResult &updateGameSessionQueueResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateGameSessionQueueResult(updateGameSessionQueueResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateGameSessionQueueCallable(updateGameSessionQueueRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateGameSessionQueueOutcome = callable.get();

            success = awsUpdateGameSessionQueueOutcome.IsSuccess();
                if (success) {
                    updateGameSessionQueueResult.fromAWS(awsUpdateGameSessionQueueOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateGameSessionQueueOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateGameSessionQueue error: " + awsUpdateGameSessionQueueOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateGameSessionQueue Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateGameSessionQueue(
        UObject *WorldContextObject,
        bool &success,
        FUpdateGameSessionQueueRequest updateGameSessionQueueRequest,
        FUpdateGameSessionQueueResult &updateGameSessionQueueResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateGameSessionQueueAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateGameSessionQueueAction(this->awsGameLiftClient,
                success,
                updateGameSessionQueueRequest,
                updateGameSessionQueueResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateMatchmakingConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateMatchmakingConfigurationResult &updateMatchmakingConfigurationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateMatchmakingConfigurationOutcomeCallable callable;

public:
    FUpdateMatchmakingConfigurationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateMatchmakingConfigurationRequest updateMatchmakingConfigurationRequest,
        FUpdateMatchmakingConfigurationResult &updateMatchmakingConfigurationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateMatchmakingConfigurationResult(updateMatchmakingConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateMatchmakingConfigurationCallable(updateMatchmakingConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateMatchmakingConfigurationOutcome = callable.get();

            success = awsUpdateMatchmakingConfigurationOutcome.IsSuccess();
                if (success) {
                    updateMatchmakingConfigurationResult.fromAWS(awsUpdateMatchmakingConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateMatchmakingConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateMatchmakingConfiguration error: " + awsUpdateMatchmakingConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateMatchmakingConfiguration Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateMatchmakingConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FUpdateMatchmakingConfigurationRequest updateMatchmakingConfigurationRequest,
        FUpdateMatchmakingConfigurationResult &updateMatchmakingConfigurationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateMatchmakingConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateMatchmakingConfigurationAction(this->awsGameLiftClient,
                success,
                updateMatchmakingConfigurationRequest,
                updateMatchmakingConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateRuntimeConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateRuntimeConfigurationResult &updateRuntimeConfigurationResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateRuntimeConfigurationOutcomeCallable callable;

public:
    FUpdateRuntimeConfigurationAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateRuntimeConfigurationRequest updateRuntimeConfigurationRequest,
        FUpdateRuntimeConfigurationResult &updateRuntimeConfigurationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateRuntimeConfigurationResult(updateRuntimeConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateRuntimeConfigurationCallable(updateRuntimeConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateRuntimeConfigurationOutcome = callable.get();

            success = awsUpdateRuntimeConfigurationOutcome.IsSuccess();
                if (success) {
                    updateRuntimeConfigurationResult.fromAWS(awsUpdateRuntimeConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateRuntimeConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateRuntimeConfiguration error: " + awsUpdateRuntimeConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateRuntimeConfiguration Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateRuntimeConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FUpdateRuntimeConfigurationRequest updateRuntimeConfigurationRequest,
        FUpdateRuntimeConfigurationResult &updateRuntimeConfigurationResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateRuntimeConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateRuntimeConfigurationAction(this->awsGameLiftClient,
                success,
                updateRuntimeConfigurationRequest,
                updateRuntimeConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FUpdateScriptAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateScriptResult &updateScriptResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::UpdateScriptOutcomeCallable callable;

public:
    FUpdateScriptAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FUpdateScriptRequest updateScriptRequest,
        FUpdateScriptResult &updateScriptResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateScriptResult(updateScriptResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->UpdateScriptCallable(updateScriptRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateScriptOutcome = callable.get();

            success = awsUpdateScriptOutcome.IsSuccess();
                if (success) {
                    updateScriptResult.fromAWS(awsUpdateScriptOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateScriptOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateScript error: " + awsUpdateScriptOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateScript Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::UpdateScript(
        UObject *WorldContextObject,
        bool &success,
        FUpdateScriptRequest updateScriptRequest,
        FUpdateScriptResult &updateScriptResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateScriptAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateScriptAction(this->awsGameLiftClient,
                success,
                updateScriptRequest,
                updateScriptResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

class FValidateMatchmakingRuleSetAction : public FPendingLatentAction {
private:
    bool &success;
    FValidateMatchmakingRuleSetResult &validateMatchmakingRuleSetResult;
    EGameLiftError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::GameLift::Model::ValidateMatchmakingRuleSetOutcomeCallable callable;

public:
    FValidateMatchmakingRuleSetAction(
        Aws::GameLift::GameLiftClient *GameLiftClient,
        bool &success,
        FValidateMatchmakingRuleSetRequest validateMatchmakingRuleSetRequest,
        FValidateMatchmakingRuleSetResult &validateMatchmakingRuleSetResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), validateMatchmakingRuleSetResult(validateMatchmakingRuleSetResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = GameLiftClient->ValidateMatchmakingRuleSetCallable(validateMatchmakingRuleSetRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsValidateMatchmakingRuleSetOutcome = callable.get();

            success = awsValidateMatchmakingRuleSetOutcome.IsSuccess();
                if (success) {
                    validateMatchmakingRuleSetResult.fromAWS(awsValidateMatchmakingRuleSetOutcome.GetResult());
                }

                errorType = fromAWS(awsValidateMatchmakingRuleSetOutcome.GetError().GetErrorType());
                errorMessage = ("ValidateMatchmakingRuleSet error: " + awsValidateMatchmakingRuleSetOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ValidateMatchmakingRuleSet Request");
    }

#endif
};

#endif

void
UGameLiftClientObject::ValidateMatchmakingRuleSet(
        UObject *WorldContextObject,
        bool &success,
        FValidateMatchmakingRuleSetRequest validateMatchmakingRuleSetRequest,
        FValidateMatchmakingRuleSetResult &validateMatchmakingRuleSetResult,
        EGameLiftError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FValidateMatchmakingRuleSetAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FValidateMatchmakingRuleSetAction(this->awsGameLiftClient,
                success,
                validateMatchmakingRuleSetRequest,
                validateMatchmakingRuleSetResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}