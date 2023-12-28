/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "LambdaClientObject.h"
#include "LambdaGlobals.h"
#include "LambdaPrivatePCH.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_LAMBDACLIENTSDK

ELambdaError fromAWS(Aws::Lambda::LambdaErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::Lambda::LambdaErrors::INCOMPLETE_SIGNATURE:
            return ELambdaError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::Lambda::LambdaErrors::INTERNAL_FAILURE:
            return ELambdaError::INTERNAL_FAILURE;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_ACTION:
            return ELambdaError::INVALID_ACTION;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_CLIENT_TOKEN_ID:
            return ELambdaError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_PARAMETER_COMBINATION:
            return ELambdaError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_QUERY_PARAMETER:
            return ELambdaError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_PARAMETER_VALUE:
            return ELambdaError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::Lambda::LambdaErrors::MISSING_ACTION:
            return ELambdaError::MISSING_ACTION;
            break;
        case Aws::Lambda::LambdaErrors::MISSING_AUTHENTICATION_TOKEN:
            return ELambdaError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::Lambda::LambdaErrors::MISSING_PARAMETER:
            return ELambdaError::MISSING_PARAMETER;
            break;
        case Aws::Lambda::LambdaErrors::OPT_IN_REQUIRED:
            return ELambdaError::OPT_IN_REQUIRED;
            break;
        case Aws::Lambda::LambdaErrors::REQUEST_EXPIRED:
            return ELambdaError::REQUEST_EXPIRED;
            break;
        case Aws::Lambda::LambdaErrors::SERVICE_UNAVAILABLE:
            return ELambdaError::SERVICE_UNAVAILABLE;
            break;
        case Aws::Lambda::LambdaErrors::THROTTLING:
            return ELambdaError::THROTTLING;
            break;
        case Aws::Lambda::LambdaErrors::VALIDATION:
            return ELambdaError::VALIDATION;
            break;
        case Aws::Lambda::LambdaErrors::ACCESS_DENIED:
            return ELambdaError::ACCESS_DENIED;
            break;
        case Aws::Lambda::LambdaErrors::RESOURCE_NOT_FOUND:
            return ELambdaError::RESOURCE_NOT_FOUND;
            break;
        case Aws::Lambda::LambdaErrors::UNRECOGNIZED_CLIENT:
            return ELambdaError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::Lambda::LambdaErrors::MALFORMED_QUERY_STRING:
            return ELambdaError::MALFORMED_QUERY_STRING;
            break;
        case Aws::Lambda::LambdaErrors::SLOW_DOWN:
            return ELambdaError::SLOW_DOWN;
            break;
        case Aws::Lambda::LambdaErrors::REQUEST_TIME_TOO_SKEWED:
            return ELambdaError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_SIGNATURE:
            return ELambdaError::INVALID_SIGNATURE;
            break;
        case Aws::Lambda::LambdaErrors::SIGNATURE_DOES_NOT_MATCH:
            return ELambdaError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_ACCESS_KEY_ID:
            return ELambdaError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::Lambda::LambdaErrors::REQUEST_TIMEOUT:
            return ELambdaError::REQUEST_TIMEOUT;
            break;
        case Aws::Lambda::LambdaErrors::NETWORK_CONNECTION:
            return ELambdaError::NETWORK_CONNECTION;
            break;
        case Aws::Lambda::LambdaErrors::UNKNOWN:
            return ELambdaError::UNKNOWN;
            break;
        case Aws::Lambda::LambdaErrors::CODE_SIGNING_CONFIG_NOT_FOUND:
            return ELambdaError::CODE_SIGNING_CONFIG_NOT_FOUND;
            break;
        case Aws::Lambda::LambdaErrors::CODE_STORAGE_EXCEEDED:
            return ELambdaError::CODE_STORAGE_EXCEEDED;
            break;
        case Aws::Lambda::LambdaErrors::CODE_VERIFICATION_FAILED:
            return ELambdaError::CODE_VERIFICATION_FAILED;
            break;
        case Aws::Lambda::LambdaErrors::E_C2_ACCESS_DENIED:
            return ELambdaError::EC2_ACCESS_DENIED;
            break;
        case Aws::Lambda::LambdaErrors::E_C2_THROTTLED:
            return ELambdaError::EC2_THROTTLED;
            break;
        case Aws::Lambda::LambdaErrors::E_C2_UNEXPECTED:
            return ELambdaError::EC2_UNEXPECTED;
            break;
        case Aws::Lambda::LambdaErrors::E_F_S_I_O:
            return ELambdaError::EFS_IO;
            break;
        case Aws::Lambda::LambdaErrors::E_F_S_MOUNT_CONNECTIVITY:
            return ELambdaError::EFS_MOUNT_CONNECTIVITY;
            break;
        case Aws::Lambda::LambdaErrors::E_F_S_MOUNT_FAILURE:
            return ELambdaError::EFS_MOUNT_FAILURE;
            break;
        case Aws::Lambda::LambdaErrors::E_F_S_MOUNT_TIMEOUT:
            return ELambdaError::EFS_MOUNT_TIMEOUT;
            break;
        case Aws::Lambda::LambdaErrors::E_N_I_LIMIT_REACHED:
            return ELambdaError::ENI_LIMIT_REACHED;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_CODE_SIGNATURE:
            return ELambdaError::INVALID_CODE_SIGNATURE;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_REQUEST_CONTENT:
            return ELambdaError::INVALID_REQUEST_CONTENT;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_RUNTIME:
            return ELambdaError::INVALID_RUNTIME;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_SECURITY_GROUP_I_D:
            return ELambdaError::INVALID_SECURITY_GROUP_ID;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_SUBNET_I_D:
            return ELambdaError::INVALID_SUBNET_ID;
            break;
        case Aws::Lambda::LambdaErrors::INVALID_ZIP_FILE:
            return ELambdaError::INVALID_ZIP_FILE;
            break;
        case Aws::Lambda::LambdaErrors::K_M_S_ACCESS_DENIED:
            return ELambdaError::KMS_ACCESS_DENIED;
            break;
        case Aws::Lambda::LambdaErrors::K_M_S_DISABLED:
            return ELambdaError::KMS_DISABLED;
            break;
        case Aws::Lambda::LambdaErrors::K_M_S_INVALID_STATE:
            return ELambdaError::KMS_INVALID_STATE;
            break;
        case Aws::Lambda::LambdaErrors::K_M_S_NOT_FOUND:
            return ELambdaError::KMS_NOT_FOUND;
            break;
        case Aws::Lambda::LambdaErrors::POLICY_LENGTH_EXCEEDED:
            return ELambdaError::POLICY_LENGTH_EXCEEDED;
            break;
        case Aws::Lambda::LambdaErrors::PRECONDITION_FAILED:
            return ELambdaError::PRECONDITION_FAILED;
            break;
        case Aws::Lambda::LambdaErrors::PROVISIONED_CONCURRENCY_CONFIG_NOT_FOUND:
            return ELambdaError::PROVISIONED_CONCURRENCY_CONFIG_NOT_FOUND;
            break;
        case Aws::Lambda::LambdaErrors::REQUEST_TOO_LARGE:
            return ELambdaError::REQUEST_TOO_LARGE;
            break;
        case Aws::Lambda::LambdaErrors::RESOURCE_CONFLICT:
            return ELambdaError::RESOURCE_CONFLICT;
            break;
        case Aws::Lambda::LambdaErrors::RESOURCE_IN_USE:
            return ELambdaError::RESOURCE_IN_USE;
            break;
        case Aws::Lambda::LambdaErrors::RESOURCE_NOT_READY:
            return ELambdaError::RESOURCE_NOT_READY;
            break;
        case Aws::Lambda::LambdaErrors::SERVICE:
            return ELambdaError::SERVICE;
            break;
        case Aws::Lambda::LambdaErrors::SNAP_START:
            return ELambdaError::SNAP_START;
            break;
        case Aws::Lambda::LambdaErrors::SNAP_START_NOT_READY:
            return ELambdaError::SNAP_START_NOT_READY;
            break;
        case Aws::Lambda::LambdaErrors::SNAP_START_TIMEOUT:
            return ELambdaError::SNAP_START_TIMEOUT;
            break;
        case Aws::Lambda::LambdaErrors::SUBNET_I_P_ADDRESS_LIMIT_REACHED:
            return ELambdaError::SUBNET_IP_ADDRESS_LIMIT_REACHED;
            break;
        case Aws::Lambda::LambdaErrors::TOO_MANY_REQUESTS:
            return ELambdaError::TOO_MANY_REQUESTS;
            break;
        case Aws::Lambda::LambdaErrors::UNSUPPORTED_MEDIA_TYPE:
            return ELambdaError::UNSUPPORTED_MEDIA_TYPE;
            break;
        default:
            return ELambdaError::UNKNOWN;
            break;
    }
}

#endif

ULambdaClientObject *ULambdaClientObject::CreateLambdaObject(
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    ULambdaClientObject *LambdaClient = NewObject<ULambdaClientObject>();
    LambdaClient->awsLambdaClient = new Aws::Lambda::LambdaClient(credentials.toAWS(),
    Aws::MakeShared<Aws::Lambda::LambdaEndpointProvider>("unreal"),
    clientConfiguration.toAWS());
    return LambdaClient;
#endif
    return nullptr;
}

#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FAddLayerVersionPermissionAction : public FPendingLatentAction {
private:
    bool &success;
    FAddLayerVersionPermissionResult &addLayerVersionPermissionResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::AddLayerVersionPermissionOutcomeCallable callable;

public:
    FAddLayerVersionPermissionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAddLayerVersionPermissionRequest addLayerVersionPermissionRequest,
        FAddLayerVersionPermissionResult &addLayerVersionPermissionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), addLayerVersionPermissionResult(addLayerVersionPermissionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->AddLayerVersionPermissionCallable(addLayerVersionPermissionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAddLayerVersionPermissionOutcome = callable.get();

            success = awsAddLayerVersionPermissionOutcome.IsSuccess();
                if (success) {
                    addLayerVersionPermissionResult.fromAWS(awsAddLayerVersionPermissionOutcome.GetResult());
                }

                errorType = fromAWS(awsAddLayerVersionPermissionOutcome.GetError().GetErrorType());
                errorMessage = ("AddLayerVersionPermission error: " + awsAddLayerVersionPermissionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AddLayerVersionPermission Request");
    }

#endif
};

#endif

void
ULambdaClientObject::AddLayerVersionPermission(
        UObject *WorldContextObject,
        bool &success,
        FAddLayerVersionPermissionRequest addLayerVersionPermissionRequest,
        FAddLayerVersionPermissionResult &addLayerVersionPermissionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAddLayerVersionPermissionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAddLayerVersionPermissionAction(this->awsLambdaClient,
                success,
                addLayerVersionPermissionRequest,
                addLayerVersionPermissionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FAddPermissionAction : public FPendingLatentAction {
private:
    bool &success;
    FAddPermissionResult &addPermissionResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::AddPermissionOutcomeCallable callable;

public:
    FAddPermissionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAddPermissionRequest addPermissionRequest,
        FAddPermissionResult &addPermissionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), addPermissionResult(addPermissionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->AddPermissionCallable(addPermissionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAddPermissionOutcome = callable.get();

            success = awsAddPermissionOutcome.IsSuccess();
                if (success) {
                    addPermissionResult.fromAWS(awsAddPermissionOutcome.GetResult());
                }

                errorType = fromAWS(awsAddPermissionOutcome.GetError().GetErrorType());
                errorMessage = ("AddPermission error: " + awsAddPermissionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AddPermission Request");
    }

#endif
};

#endif

void
ULambdaClientObject::AddPermission(
        UObject *WorldContextObject,
        bool &success,
        FAddPermissionRequest addPermissionRequest,
        FAddPermissionResult &addPermissionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAddPermissionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAddPermissionAction(this->awsLambdaClient,
                success,
                addPermissionRequest,
                addPermissionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FCreateAliasAction : public FPendingLatentAction {
private:
    bool &success;
    FLambdaCreateAliasResult &createAliasResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::CreateAliasOutcomeCallable callable;

public:
    FCreateAliasAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaCreateAliasRequest createAliasRequest,
        FLambdaCreateAliasResult &createAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createAliasResult(createAliasResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->CreateAliasCallable(createAliasRequest.toAWS());
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
ULambdaClientObject::CreateAlias(
        UObject *WorldContextObject,
        bool &success,
        FLambdaCreateAliasRequest createAliasRequest,
        FLambdaCreateAliasResult &createAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateAliasAction(this->awsLambdaClient,
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
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FCreateCodeSigningConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaCreateCodeSigningConfigResult &createCodeSigningConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::CreateCodeSigningConfigOutcomeCallable callable;

public:
    FCreateCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaCreateCodeSigningConfigRequest createCodeSigningConfigRequest,
        FAWSLambdaCreateCodeSigningConfigResult &createCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createCodeSigningConfigResult(createCodeSigningConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->CreateCodeSigningConfigCallable(createCodeSigningConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateCodeSigningConfigOutcome = callable.get();

            success = awsCreateCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    createCodeSigningConfigResult.fromAWS(awsCreateCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("CreateCodeSigningConfig error: " + awsCreateCodeSigningConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::CreateCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaCreateCodeSigningConfigRequest createCodeSigningConfigRequest,
    FAWSLambdaCreateCodeSigningConfigResult &createCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateCodeSigningConfigAction(this->awsLambdaClient,
                success,
                createCodeSigningConfigRequest,
                createCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FCreateEventSourceMappingAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateEventSourceMappingResult &createEventSourceMappingResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::CreateEventSourceMappingOutcomeCallable callable;

public:
    FCreateEventSourceMappingAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FCreateEventSourceMappingRequest createEventSourceMappingRequest,
        FCreateEventSourceMappingResult &createEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createEventSourceMappingResult(createEventSourceMappingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->CreateEventSourceMappingCallable(createEventSourceMappingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateEventSourceMappingOutcome = callable.get();

            success = awsCreateEventSourceMappingOutcome.IsSuccess();
                if (success) {
                    createEventSourceMappingResult.fromAWS(awsCreateEventSourceMappingOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateEventSourceMappingOutcome.GetError().GetErrorType());
                errorMessage = ("CreateEventSourceMapping error: " + awsCreateEventSourceMappingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateEventSourceMapping Request");
    }

#endif
};

#endif

void
ULambdaClientObject::CreateEventSourceMapping(
        UObject *WorldContextObject,
        bool &success,
        FCreateEventSourceMappingRequest createEventSourceMappingRequest,
        FCreateEventSourceMappingResult &createEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateEventSourceMappingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateEventSourceMappingAction(this->awsLambdaClient,
                success,
                createEventSourceMappingRequest,
                createEventSourceMappingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FCreateFunctionAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateFunctionResult &createFunctionResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::CreateFunctionOutcomeCallable callable;

public:
    FCreateFunctionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FCreateFunctionRequest createFunctionRequest,
        FCreateFunctionResult &createFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createFunctionResult(createFunctionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->CreateFunctionCallable(createFunctionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateFunctionOutcome = callable.get();

            success = awsCreateFunctionOutcome.IsSuccess();
                if (success) {
                    createFunctionResult.fromAWS(awsCreateFunctionOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateFunctionOutcome.GetError().GetErrorType());
                errorMessage = ("CreateFunction error: " + awsCreateFunctionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateFunction Request");
    }

#endif
};

#endif

void
ULambdaClientObject::CreateFunction(
        UObject *WorldContextObject,
        bool &success,
        FCreateFunctionRequest createFunctionRequest,
        FCreateFunctionResult &createFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateFunctionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateFunctionAction(this->awsLambdaClient,
                success,
                createFunctionRequest,
                createFunctionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FCreateFunctionUrlConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaCreateFunctionUrlConfigResult &createFunctionUrlConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::CreateFunctionUrlConfigOutcomeCallable callable;

public:
    FCreateFunctionUrlConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaCreateFunctionUrlConfigRequest createFunctionUrlConfigRequest,
        FAWSLambdaCreateFunctionUrlConfigResult &createFunctionUrlConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createFunctionUrlConfigResult(createFunctionUrlConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->CreateFunctionUrlConfigCallable(createFunctionUrlConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateFunctionUrlConfigOutcome = callable.get();

            success = awsCreateFunctionUrlConfigOutcome.IsSuccess();
                if (success) {
                    createFunctionUrlConfigResult.fromAWS(awsCreateFunctionUrlConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateFunctionUrlConfigOutcome.GetError().GetErrorType());
                errorMessage = ("CreateFunctionUrlConfig error: " + awsCreateFunctionUrlConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateFunctionUrlConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::CreateFunctionUrlConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaCreateFunctionUrlConfigRequest createFunctionUrlConfigRequest,
    FAWSLambdaCreateFunctionUrlConfigResult &createFunctionUrlConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateFunctionUrlConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateFunctionUrlConfigAction(this->awsLambdaClient,
                success,
                createFunctionUrlConfigRequest,
                createFunctionUrlConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteAliasAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::DeleteAliasOutcomeCallable callable;

public:
    FDeleteAliasAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaDeleteAliasRequest deleteAliasRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->DeleteAliasCallable(deleteAliasRequest.toAWS());
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
ULambdaClientObject::DeleteAlias(
        UObject *WorldContextObject,
        bool &success,
        FLambdaDeleteAliasRequest deleteAliasRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteAliasAction(this->awsLambdaClient,
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
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteCodeSigningConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaDeleteCodeSigningConfigResult &deleteCodeSigningConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::DeleteCodeSigningConfigOutcomeCallable callable;

public:
    FDeleteCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaDeleteCodeSigningConfigRequest deleteCodeSigningConfigRequest,
        FAWSLambdaDeleteCodeSigningConfigResult &deleteCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteCodeSigningConfigResult(deleteCodeSigningConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->DeleteCodeSigningConfigCallable(deleteCodeSigningConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteCodeSigningConfigOutcome = callable.get();

            success = awsDeleteCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    deleteCodeSigningConfigResult.fromAWS(awsDeleteCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteCodeSigningConfig error: " + awsDeleteCodeSigningConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaDeleteCodeSigningConfigRequest deleteCodeSigningConfigRequest,
    FAWSLambdaDeleteCodeSigningConfigResult &deleteCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteCodeSigningConfigAction(this->awsLambdaClient,
                success,
                deleteCodeSigningConfigRequest,
                deleteCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteEventSourceMappingAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteEventSourceMappingResult &deleteEventSourceMappingResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::DeleteEventSourceMappingOutcomeCallable callable;

public:
    FDeleteEventSourceMappingAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteEventSourceMappingRequest deleteEventSourceMappingRequest,
        FDeleteEventSourceMappingResult &deleteEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteEventSourceMappingResult(deleteEventSourceMappingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->DeleteEventSourceMappingCallable(deleteEventSourceMappingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteEventSourceMappingOutcome = callable.get();

            success = awsDeleteEventSourceMappingOutcome.IsSuccess();
                if (success) {
                    deleteEventSourceMappingResult.fromAWS(awsDeleteEventSourceMappingOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteEventSourceMappingOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteEventSourceMapping error: " + awsDeleteEventSourceMappingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteEventSourceMapping Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteEventSourceMapping(
        UObject *WorldContextObject,
        bool &success,
        FDeleteEventSourceMappingRequest deleteEventSourceMappingRequest,
        FDeleteEventSourceMappingResult &deleteEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteEventSourceMappingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteEventSourceMappingAction(this->awsLambdaClient,
                success,
                deleteEventSourceMappingRequest,
                deleteEventSourceMappingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteFunctionAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::DeleteFunctionOutcomeCallable callable;

public:
    FDeleteFunctionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteFunctionRequest deleteFunctionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->DeleteFunctionCallable(deleteFunctionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteFunctionOutcome = callable.get();

            success = awsDeleteFunctionOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteFunctionOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFunction error: " + awsDeleteFunctionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFunction Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteFunction(
        UObject *WorldContextObject,
        bool &success,
        FDeleteFunctionRequest deleteFunctionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFunctionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFunctionAction(this->awsLambdaClient,
                success,
                deleteFunctionRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteFunctionCodeSigningConfigAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::DeleteFunctionCodeSigningConfigOutcomeCallable callable;

public:
    FDeleteFunctionCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaDeleteFunctionCodeSigningConfigRequest deleteFunctionCodeSigningConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->DeleteFunctionCodeSigningConfigCallable(deleteFunctionCodeSigningConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteFunctionCodeSigningConfigOutcome = callable.get();

            success = awsDeleteFunctionCodeSigningConfigOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteFunctionCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFunctionCodeSigningConfig error: " + awsDeleteFunctionCodeSigningConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFunctionCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteFunctionCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaDeleteFunctionCodeSigningConfigRequest deleteFunctionCodeSigningConfigRequest,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFunctionCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFunctionCodeSigningConfigAction(this->awsLambdaClient,
                success,
                deleteFunctionCodeSigningConfigRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteFunctionConcurrencyAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::DeleteFunctionConcurrencyOutcomeCallable callable;

public:
    FDeleteFunctionConcurrencyAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteFunctionConcurrencyRequest deleteFunctionConcurrencyRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->DeleteFunctionConcurrencyCallable(deleteFunctionConcurrencyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteFunctionConcurrencyOutcome = callable.get();

            success = awsDeleteFunctionConcurrencyOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteFunctionConcurrencyOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFunctionConcurrency error: " + awsDeleteFunctionConcurrencyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFunctionConcurrency Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteFunctionConcurrency(
        UObject *WorldContextObject,
        bool &success,
        FDeleteFunctionConcurrencyRequest deleteFunctionConcurrencyRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFunctionConcurrencyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFunctionConcurrencyAction(this->awsLambdaClient,
                success,
                deleteFunctionConcurrencyRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteFunctionEventInvokeConfigAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::DeleteFunctionEventInvokeConfigOutcomeCallable callable;

public:
    FDeleteFunctionEventInvokeConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteFunctionEventInvokeConfigRequest deleteFunctionEventInvokeConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->DeleteFunctionEventInvokeConfigCallable(deleteFunctionEventInvokeConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteFunctionEventInvokeConfigOutcome = callable.get();

            success = awsDeleteFunctionEventInvokeConfigOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteFunctionEventInvokeConfigOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFunctionEventInvokeConfig error: " + awsDeleteFunctionEventInvokeConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFunctionEventInvokeConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteFunctionEventInvokeConfig(
        UObject *WorldContextObject,
        bool &success,
        FDeleteFunctionEventInvokeConfigRequest deleteFunctionEventInvokeConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFunctionEventInvokeConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFunctionEventInvokeConfigAction(this->awsLambdaClient,
                success,
                deleteFunctionEventInvokeConfigRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteFunctionUrlConfigAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::DeleteFunctionUrlConfigOutcomeCallable callable;

public:
    FDeleteFunctionUrlConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaDeleteFunctionUrlConfigRequest deleteFunctionUrlConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->DeleteFunctionUrlConfigCallable(deleteFunctionUrlConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteFunctionUrlConfigOutcome = callable.get();

            success = awsDeleteFunctionUrlConfigOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteFunctionUrlConfigOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteFunctionUrlConfig error: " + awsDeleteFunctionUrlConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteFunctionUrlConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteFunctionUrlConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaDeleteFunctionUrlConfigRequest deleteFunctionUrlConfigRequest,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteFunctionUrlConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteFunctionUrlConfigAction(this->awsLambdaClient,
                success,
                deleteFunctionUrlConfigRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteLayerVersionAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::DeleteLayerVersionOutcomeCallable callable;

public:
    FDeleteLayerVersionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteLayerVersionRequest deleteLayerVersionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->DeleteLayerVersionCallable(deleteLayerVersionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteLayerVersionOutcome = callable.get();

            success = awsDeleteLayerVersionOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteLayerVersionOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteLayerVersion error: " + awsDeleteLayerVersionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteLayerVersion Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteLayerVersion(
        UObject *WorldContextObject,
        bool &success,
        FDeleteLayerVersionRequest deleteLayerVersionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteLayerVersionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteLayerVersionAction(this->awsLambdaClient,
                success,
                deleteLayerVersionRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FDeleteProvisionedConcurrencyConfigAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::DeleteProvisionedConcurrencyConfigOutcomeCallable callable;

public:
    FDeleteProvisionedConcurrencyConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FDeleteProvisionedConcurrencyConfigRequest deleteProvisionedConcurrencyConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->DeleteProvisionedConcurrencyConfigCallable(deleteProvisionedConcurrencyConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteProvisionedConcurrencyConfigOutcome = callable.get();

            success = awsDeleteProvisionedConcurrencyConfigOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteProvisionedConcurrencyConfigOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteProvisionedConcurrencyConfig error: " + awsDeleteProvisionedConcurrencyConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteProvisionedConcurrencyConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::DeleteProvisionedConcurrencyConfig(
        UObject *WorldContextObject,
        bool &success,
        FDeleteProvisionedConcurrencyConfigRequest deleteProvisionedConcurrencyConfigRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteProvisionedConcurrencyConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteProvisionedConcurrencyConfigAction(this->awsLambdaClient,
                success,
                deleteProvisionedConcurrencyConfigRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetAccountSettingsAction : public FPendingLatentAction {
private:
    bool &success;
    FGetAccountSettingsResult &getAccountSettingsResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetAccountSettingsOutcomeCallable callable;

public:
    FGetAccountSettingsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetAccountSettingsRequest getAccountSettingsRequest,
        FGetAccountSettingsResult &getAccountSettingsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getAccountSettingsResult(getAccountSettingsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetAccountSettingsCallable(getAccountSettingsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetAccountSettingsOutcome = callable.get();

            success = awsGetAccountSettingsOutcome.IsSuccess();
                if (success) {
                    getAccountSettingsResult.fromAWS(awsGetAccountSettingsOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAccountSettingsOutcome.GetError().GetErrorType());
                errorMessage = ("GetAccountSettings error: " + awsGetAccountSettingsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAccountSettings Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetAccountSettings(
        UObject *WorldContextObject,
        bool &success,
        FGetAccountSettingsRequest getAccountSettingsRequest,
        FGetAccountSettingsResult &getAccountSettingsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAccountSettingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAccountSettingsAction(this->awsLambdaClient,
                success,
                getAccountSettingsRequest,
                getAccountSettingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetAliasAction : public FPendingLatentAction {
private:
    bool &success;
    FGetAliasResult &getAliasResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetAliasOutcomeCallable callable;

public:
    FGetAliasAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetAliasRequest getAliasRequest,
        FGetAliasResult &getAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getAliasResult(getAliasResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetAliasCallable(getAliasRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetAliasOutcome = callable.get();

            success = awsGetAliasOutcome.IsSuccess();
                if (success) {
                    getAliasResult.fromAWS(awsGetAliasOutcome.GetResult());
                }

                errorType = fromAWS(awsGetAliasOutcome.GetError().GetErrorType());
                errorMessage = ("GetAlias error: " + awsGetAliasOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetAlias Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetAlias(
        UObject *WorldContextObject,
        bool &success,
        FGetAliasRequest getAliasRequest,
        FGetAliasResult &getAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetAliasAction(this->awsLambdaClient,
                success,
                getAliasRequest,
                getAliasResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetCodeSigningConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaGetCodeSigningConfigResult &getCodeSigningConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetCodeSigningConfigOutcomeCallable callable;

public:
    FGetCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaGetCodeSigningConfigRequest getCodeSigningConfigRequest,
        FAWSLambdaGetCodeSigningConfigResult &getCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getCodeSigningConfigResult(getCodeSigningConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetCodeSigningConfigCallable(getCodeSigningConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetCodeSigningConfigOutcome = callable.get();

            success = awsGetCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    getCodeSigningConfigResult.fromAWS(awsGetCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetCodeSigningConfig error: " + awsGetCodeSigningConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaGetCodeSigningConfigRequest getCodeSigningConfigRequest,
    FAWSLambdaGetCodeSigningConfigResult &getCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetCodeSigningConfigAction(this->awsLambdaClient,
                success,
                getCodeSigningConfigRequest,
                getCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetEventSourceMappingAction : public FPendingLatentAction {
private:
    bool &success;
    FGetEventSourceMappingResult &getEventSourceMappingResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetEventSourceMappingOutcomeCallable callable;

public:
    FGetEventSourceMappingAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetEventSourceMappingRequest getEventSourceMappingRequest,
        FGetEventSourceMappingResult &getEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getEventSourceMappingResult(getEventSourceMappingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetEventSourceMappingCallable(getEventSourceMappingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetEventSourceMappingOutcome = callable.get();

            success = awsGetEventSourceMappingOutcome.IsSuccess();
                if (success) {
                    getEventSourceMappingResult.fromAWS(awsGetEventSourceMappingOutcome.GetResult());
                }

                errorType = fromAWS(awsGetEventSourceMappingOutcome.GetError().GetErrorType());
                errorMessage = ("GetEventSourceMapping error: " + awsGetEventSourceMappingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetEventSourceMapping Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetEventSourceMapping(
        UObject *WorldContextObject,
        bool &success,
        FGetEventSourceMappingRequest getEventSourceMappingRequest,
        FGetEventSourceMappingResult &getEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetEventSourceMappingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetEventSourceMappingAction(this->awsLambdaClient,
                success,
                getEventSourceMappingRequest,
                getEventSourceMappingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionAction : public FPendingLatentAction {
private:
    bool &success;
    FGetFunctionResult &getFunctionResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetFunctionOutcomeCallable callable;

public:
    FGetFunctionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetFunctionRequest getFunctionRequest,
        FGetFunctionResult &getFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getFunctionResult(getFunctionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetFunctionCallable(getFunctionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetFunctionOutcome = callable.get();

            success = awsGetFunctionOutcome.IsSuccess();
                if (success) {
                    getFunctionResult.fromAWS(awsGetFunctionOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunction error: " + awsGetFunctionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunction Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunction(
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionRequest getFunctionRequest,
        FGetFunctionResult &getFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionAction(this->awsLambdaClient,
                success,
                getFunctionRequest,
                getFunctionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionCodeSigningConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaGetFunctionCodeSigningConfigResult &getFunctionCodeSigningConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetFunctionCodeSigningConfigOutcomeCallable callable;

public:
    FGetFunctionCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaGetFunctionCodeSigningConfigRequest getFunctionCodeSigningConfigRequest,
        FAWSLambdaGetFunctionCodeSigningConfigResult &getFunctionCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getFunctionCodeSigningConfigResult(getFunctionCodeSigningConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetFunctionCodeSigningConfigCallable(getFunctionCodeSigningConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetFunctionCodeSigningConfigOutcome = callable.get();

            success = awsGetFunctionCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    getFunctionCodeSigningConfigResult.fromAWS(awsGetFunctionCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunctionCodeSigningConfig error: " + awsGetFunctionCodeSigningConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunctionCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunctionCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaGetFunctionCodeSigningConfigRequest getFunctionCodeSigningConfigRequest,
    FAWSLambdaGetFunctionCodeSigningConfigResult &getFunctionCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionCodeSigningConfigAction(this->awsLambdaClient,
                success,
                getFunctionCodeSigningConfigRequest,
                getFunctionCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionConcurrencyAction : public FPendingLatentAction {
private:
    bool &success;
    FGetFunctionConcurrencyResult &getFunctionConcurrencyResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetFunctionConcurrencyOutcomeCallable callable;

public:
    FGetFunctionConcurrencyAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetFunctionConcurrencyRequest getFunctionConcurrencyRequest,
        FGetFunctionConcurrencyResult &getFunctionConcurrencyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getFunctionConcurrencyResult(getFunctionConcurrencyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetFunctionConcurrencyCallable(getFunctionConcurrencyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetFunctionConcurrencyOutcome = callable.get();

            success = awsGetFunctionConcurrencyOutcome.IsSuccess();
                if (success) {
                    getFunctionConcurrencyResult.fromAWS(awsGetFunctionConcurrencyOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionConcurrencyOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunctionConcurrency error: " + awsGetFunctionConcurrencyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunctionConcurrency Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunctionConcurrency(
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionConcurrencyRequest getFunctionConcurrencyRequest,
        FGetFunctionConcurrencyResult &getFunctionConcurrencyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionConcurrencyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionConcurrencyAction(this->awsLambdaClient,
                success,
                getFunctionConcurrencyRequest,
                getFunctionConcurrencyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetFunctionConfigurationResult &getFunctionConfigurationResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetFunctionConfigurationOutcomeCallable callable;

public:
    FGetFunctionConfigurationAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetFunctionConfigurationRequest getFunctionConfigurationRequest,
        FGetFunctionConfigurationResult &getFunctionConfigurationResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getFunctionConfigurationResult(getFunctionConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetFunctionConfigurationCallable(getFunctionConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetFunctionConfigurationOutcome = callable.get();

            success = awsGetFunctionConfigurationOutcome.IsSuccess();
                if (success) {
                    getFunctionConfigurationResult.fromAWS(awsGetFunctionConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunctionConfiguration error: " + awsGetFunctionConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunctionConfiguration Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunctionConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionConfigurationRequest getFunctionConfigurationRequest,
        FGetFunctionConfigurationResult &getFunctionConfigurationResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionConfigurationAction(this->awsLambdaClient,
                success,
                getFunctionConfigurationRequest,
                getFunctionConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionEventInvokeConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FGetFunctionEventInvokeConfigResult &getFunctionEventInvokeConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetFunctionEventInvokeConfigOutcomeCallable callable;

public:
    FGetFunctionEventInvokeConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetFunctionEventInvokeConfigRequest getFunctionEventInvokeConfigRequest,
        FGetFunctionEventInvokeConfigResult &getFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getFunctionEventInvokeConfigResult(getFunctionEventInvokeConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetFunctionEventInvokeConfigCallable(getFunctionEventInvokeConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetFunctionEventInvokeConfigOutcome = callable.get();

            success = awsGetFunctionEventInvokeConfigOutcome.IsSuccess();
                if (success) {
                    getFunctionEventInvokeConfigResult.fromAWS(awsGetFunctionEventInvokeConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionEventInvokeConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunctionEventInvokeConfig error: " + awsGetFunctionEventInvokeConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunctionEventInvokeConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunctionEventInvokeConfig(
        UObject *WorldContextObject,
        bool &success,
        FGetFunctionEventInvokeConfigRequest getFunctionEventInvokeConfigRequest,
        FGetFunctionEventInvokeConfigResult &getFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionEventInvokeConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionEventInvokeConfigAction(this->awsLambdaClient,
                success,
                getFunctionEventInvokeConfigRequest,
                getFunctionEventInvokeConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetFunctionUrlConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaGetFunctionUrlConfigResult &getFunctionUrlConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetFunctionUrlConfigOutcomeCallable callable;

public:
    FGetFunctionUrlConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaGetFunctionUrlConfigRequest getFunctionUrlConfigRequest,
        FAWSLambdaGetFunctionUrlConfigResult &getFunctionUrlConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getFunctionUrlConfigResult(getFunctionUrlConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetFunctionUrlConfigCallable(getFunctionUrlConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetFunctionUrlConfigOutcome = callable.get();

            success = awsGetFunctionUrlConfigOutcome.IsSuccess();
                if (success) {
                    getFunctionUrlConfigResult.fromAWS(awsGetFunctionUrlConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetFunctionUrlConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetFunctionUrlConfig error: " + awsGetFunctionUrlConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetFunctionUrlConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetFunctionUrlConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaGetFunctionUrlConfigRequest getFunctionUrlConfigRequest,
    FAWSLambdaGetFunctionUrlConfigResult &getFunctionUrlConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetFunctionUrlConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetFunctionUrlConfigAction(this->awsLambdaClient,
                success,
                getFunctionUrlConfigRequest,
                getFunctionUrlConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetLayerVersionAction : public FPendingLatentAction {
private:
    bool &success;
    FGetLayerVersionResult &getLayerVersionResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetLayerVersionOutcomeCallable callable;

public:
    FGetLayerVersionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetLayerVersionRequest getLayerVersionRequest,
        FGetLayerVersionResult &getLayerVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getLayerVersionResult(getLayerVersionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetLayerVersionCallable(getLayerVersionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetLayerVersionOutcome = callable.get();

            success = awsGetLayerVersionOutcome.IsSuccess();
                if (success) {
                    getLayerVersionResult.fromAWS(awsGetLayerVersionOutcome.GetResult());
                }

                errorType = fromAWS(awsGetLayerVersionOutcome.GetError().GetErrorType());
                errorMessage = ("GetLayerVersion error: " + awsGetLayerVersionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetLayerVersion Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetLayerVersion(
        UObject *WorldContextObject,
        bool &success,
        FGetLayerVersionRequest getLayerVersionRequest,
        FGetLayerVersionResult &getLayerVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetLayerVersionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetLayerVersionAction(this->awsLambdaClient,
                success,
                getLayerVersionRequest,
                getLayerVersionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetLayerVersionByArnAction : public FPendingLatentAction {
private:
    bool &success;
    FGetLayerVersionByArnResult &getLayerVersionByArnResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetLayerVersionByArnOutcomeCallable callable;

public:
    FGetLayerVersionByArnAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetLayerVersionByArnRequest getLayerVersionByArnRequest,
        FGetLayerVersionByArnResult &getLayerVersionByArnResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getLayerVersionByArnResult(getLayerVersionByArnResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetLayerVersionByArnCallable(getLayerVersionByArnRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetLayerVersionByArnOutcome = callable.get();

            success = awsGetLayerVersionByArnOutcome.IsSuccess();
                if (success) {
                    getLayerVersionByArnResult.fromAWS(awsGetLayerVersionByArnOutcome.GetResult());
                }

                errorType = fromAWS(awsGetLayerVersionByArnOutcome.GetError().GetErrorType());
                errorMessage = ("GetLayerVersionByArn error: " + awsGetLayerVersionByArnOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetLayerVersionByArn Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetLayerVersionByArn(
        UObject *WorldContextObject,
        bool &success,
        FGetLayerVersionByArnRequest getLayerVersionByArnRequest,
        FGetLayerVersionByArnResult &getLayerVersionByArnResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetLayerVersionByArnAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetLayerVersionByArnAction(this->awsLambdaClient,
                success,
                getLayerVersionByArnRequest,
                getLayerVersionByArnResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetLayerVersionPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    FGetLayerVersionPolicyResult &getLayerVersionPolicyResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetLayerVersionPolicyOutcomeCallable callable;

public:
    FGetLayerVersionPolicyAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetLayerVersionPolicyRequest getLayerVersionPolicyRequest,
        FGetLayerVersionPolicyResult &getLayerVersionPolicyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getLayerVersionPolicyResult(getLayerVersionPolicyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetLayerVersionPolicyCallable(getLayerVersionPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetLayerVersionPolicyOutcome = callable.get();

            success = awsGetLayerVersionPolicyOutcome.IsSuccess();
                if (success) {
                    getLayerVersionPolicyResult.fromAWS(awsGetLayerVersionPolicyOutcome.GetResult());
                }

                errorType = fromAWS(awsGetLayerVersionPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("GetLayerVersionPolicy error: " + awsGetLayerVersionPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetLayerVersionPolicy Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetLayerVersionPolicy(
        UObject *WorldContextObject,
        bool &success,
        FGetLayerVersionPolicyRequest getLayerVersionPolicyRequest,
        FGetLayerVersionPolicyResult &getLayerVersionPolicyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetLayerVersionPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetLayerVersionPolicyAction(this->awsLambdaClient,
                success,
                getLayerVersionPolicyRequest,
                getLayerVersionPolicyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetPolicyAction : public FPendingLatentAction {
private:
    bool &success;
    FGetPolicyResult &getPolicyResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetPolicyOutcomeCallable callable;

public:
    FGetPolicyAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetPolicyRequest getPolicyRequest,
        FGetPolicyResult &getPolicyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getPolicyResult(getPolicyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetPolicyCallable(getPolicyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetPolicyOutcome = callable.get();

            success = awsGetPolicyOutcome.IsSuccess();
                if (success) {
                    getPolicyResult.fromAWS(awsGetPolicyOutcome.GetResult());
                }

                errorType = fromAWS(awsGetPolicyOutcome.GetError().GetErrorType());
                errorMessage = ("GetPolicy error: " + awsGetPolicyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetPolicy Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetPolicy(
        UObject *WorldContextObject,
        bool &success,
        FGetPolicyRequest getPolicyRequest,
        FGetPolicyResult &getPolicyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetPolicyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetPolicyAction(this->awsLambdaClient,
                success,
                getPolicyRequest,
                getPolicyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FGetProvisionedConcurrencyConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FGetProvisionedConcurrencyConfigResult &getProvisionedConcurrencyConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::GetProvisionedConcurrencyConfigOutcomeCallable callable;

public:
    FGetProvisionedConcurrencyConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FGetProvisionedConcurrencyConfigRequest getProvisionedConcurrencyConfigRequest,
        FGetProvisionedConcurrencyConfigResult &getProvisionedConcurrencyConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getProvisionedConcurrencyConfigResult(getProvisionedConcurrencyConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->GetProvisionedConcurrencyConfigCallable(getProvisionedConcurrencyConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetProvisionedConcurrencyConfigOutcome = callable.get();

            success = awsGetProvisionedConcurrencyConfigOutcome.IsSuccess();
                if (success) {
                    getProvisionedConcurrencyConfigResult.fromAWS(awsGetProvisionedConcurrencyConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetProvisionedConcurrencyConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetProvisionedConcurrencyConfig error: " + awsGetProvisionedConcurrencyConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetProvisionedConcurrencyConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::GetProvisionedConcurrencyConfig(
        UObject *WorldContextObject,
        bool &success,
        FGetProvisionedConcurrencyConfigRequest getProvisionedConcurrencyConfigRequest,
        FGetProvisionedConcurrencyConfigResult &getProvisionedConcurrencyConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetProvisionedConcurrencyConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetProvisionedConcurrencyConfigAction(this->awsLambdaClient,
                success,
                getProvisionedConcurrencyConfigRequest,
                getProvisionedConcurrencyConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FInvokeAction : public FPendingLatentAction {
private:
    bool &success;
    FInvokeResult &invokeResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::InvokeOutcomeCallable callable;

public:
    FInvokeAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FInvokeRequest invokeRequest,
        FInvokeResult &invokeResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), invokeResult(invokeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->InvokeCallable(invokeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsInvokeOutcome = callable.get();

            success = awsInvokeOutcome.IsSuccess();
                if (success) {
                    invokeResult.fromAWS(awsInvokeOutcome.GetResult());
                }

                errorType = fromAWS(awsInvokeOutcome.GetError().GetErrorType());
                errorMessage = ("Invoke error: " + awsInvokeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("Invoke Request");
    }

#endif
};

#endif

void
ULambdaClientObject::Invoke(
        UObject *WorldContextObject,
        bool &success,
        FInvokeRequest invokeRequest,
        FInvokeResult &invokeResult,
        ELambdaError &errorType,
        FString &errorMessage,
struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
// Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FInvokeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FInvokeAction(this->awsLambdaClient,
                success,
                invokeRequest,
                invokeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListAliasesAction : public FPendingLatentAction {
private:
    bool &success;
    FLambdaListAliasesResult &listAliasesResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListAliasesOutcomeCallable callable;

public:
    FListAliasesAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaListAliasesRequest listAliasesRequest,
        FLambdaListAliasesResult &listAliasesResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listAliasesResult(listAliasesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListAliasesCallable(listAliasesRequest.toAWS());
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
ULambdaClientObject::ListAliases(
        UObject *WorldContextObject,
        bool &success,
        FLambdaListAliasesRequest listAliasesRequest,
        FLambdaListAliasesResult &listAliasesResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListAliasesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListAliasesAction(this->awsLambdaClient,
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
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListCodeSigningConfigsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaListCodeSigningConfigsResult &listCodeSigningConfigsResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListCodeSigningConfigsOutcomeCallable callable;

public:
    FListCodeSigningConfigsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaListCodeSigningConfigsRequest listCodeSigningConfigsRequest,
        FAWSLambdaListCodeSigningConfigsResult &listCodeSigningConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listCodeSigningConfigsResult(listCodeSigningConfigsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListCodeSigningConfigsCallable(listCodeSigningConfigsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListCodeSigningConfigsOutcome = callable.get();

            success = awsListCodeSigningConfigsOutcome.IsSuccess();
                if (success) {
                    listCodeSigningConfigsResult.fromAWS(awsListCodeSigningConfigsOutcome.GetResult());
                }

                errorType = fromAWS(awsListCodeSigningConfigsOutcome.GetError().GetErrorType());
                errorMessage = ("ListCodeSigningConfigs error: " + awsListCodeSigningConfigsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListCodeSigningConfigs Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListCodeSigningConfigs(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaListCodeSigningConfigsRequest listCodeSigningConfigsRequest,
    FAWSLambdaListCodeSigningConfigsResult &listCodeSigningConfigsResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListCodeSigningConfigsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListCodeSigningConfigsAction(this->awsLambdaClient,
                success,
                listCodeSigningConfigsRequest,
                listCodeSigningConfigsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListEventSourceMappingsAction : public FPendingLatentAction {
private:
    bool &success;
    FListEventSourceMappingsResult &listEventSourceMappingsResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListEventSourceMappingsOutcomeCallable callable;

public:
    FListEventSourceMappingsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListEventSourceMappingsRequest listEventSourceMappingsRequest,
        FListEventSourceMappingsResult &listEventSourceMappingsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listEventSourceMappingsResult(listEventSourceMappingsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListEventSourceMappingsCallable(listEventSourceMappingsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListEventSourceMappingsOutcome = callable.get();

            success = awsListEventSourceMappingsOutcome.IsSuccess();
                if (success) {
                    listEventSourceMappingsResult.fromAWS(awsListEventSourceMappingsOutcome.GetResult());
                }

                errorType = fromAWS(awsListEventSourceMappingsOutcome.GetError().GetErrorType());
                errorMessage = ("ListEventSourceMappings error: " + awsListEventSourceMappingsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListEventSourceMappings Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListEventSourceMappings(
        UObject *WorldContextObject,
        bool &success,
        FListEventSourceMappingsRequest listEventSourceMappingsRequest,
        FListEventSourceMappingsResult &listEventSourceMappingsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListEventSourceMappingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListEventSourceMappingsAction(this->awsLambdaClient,
                success,
                listEventSourceMappingsRequest,
                listEventSourceMappingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListFunctionEventInvokeConfigsAction : public FPendingLatentAction {
private:
    bool &success;
    FListFunctionEventInvokeConfigsResult &listFunctionEventInvokeConfigsResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListFunctionEventInvokeConfigsOutcomeCallable callable;

public:
    FListFunctionEventInvokeConfigsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListFunctionEventInvokeConfigsRequest listFunctionEventInvokeConfigsRequest,
        FListFunctionEventInvokeConfigsResult &listFunctionEventInvokeConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listFunctionEventInvokeConfigsResult(listFunctionEventInvokeConfigsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListFunctionEventInvokeConfigsCallable(listFunctionEventInvokeConfigsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListFunctionEventInvokeConfigsOutcome = callable.get();

            success = awsListFunctionEventInvokeConfigsOutcome.IsSuccess();
                if (success) {
                    listFunctionEventInvokeConfigsResult.fromAWS(awsListFunctionEventInvokeConfigsOutcome.GetResult());
                }

                errorType = fromAWS(awsListFunctionEventInvokeConfigsOutcome.GetError().GetErrorType());
                errorMessage = ("ListFunctionEventInvokeConfigs error: " + awsListFunctionEventInvokeConfigsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListFunctionEventInvokeConfigs Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListFunctionEventInvokeConfigs(
        UObject *WorldContextObject,
        bool &success,
        FListFunctionEventInvokeConfigsRequest listFunctionEventInvokeConfigsRequest,
        FListFunctionEventInvokeConfigsResult &listFunctionEventInvokeConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListFunctionEventInvokeConfigsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListFunctionEventInvokeConfigsAction(this->awsLambdaClient,
                success,
                listFunctionEventInvokeConfigsRequest,
                listFunctionEventInvokeConfigsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListFunctionUrlConfigsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaListFunctionUrlConfigsResult &listFunctionUrlConfigsResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListFunctionUrlConfigsOutcomeCallable callable;

public:
    FListFunctionUrlConfigsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaListFunctionUrlConfigsRequest listFunctionUrlConfigsRequest,
        FAWSLambdaListFunctionUrlConfigsResult &listFunctionUrlConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listFunctionUrlConfigsResult(listFunctionUrlConfigsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListFunctionUrlConfigsCallable(listFunctionUrlConfigsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListFunctionUrlConfigsOutcome = callable.get();

            success = awsListFunctionUrlConfigsOutcome.IsSuccess();
                if (success) {
                    listFunctionUrlConfigsResult.fromAWS(awsListFunctionUrlConfigsOutcome.GetResult());
                }

                errorType = fromAWS(awsListFunctionUrlConfigsOutcome.GetError().GetErrorType());
                errorMessage = ("ListFunctionUrlConfigs error: " + awsListFunctionUrlConfigsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListFunctionUrlConfigs Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListFunctionUrlConfigs(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaListFunctionUrlConfigsRequest listFunctionUrlConfigsRequest,
    FAWSLambdaListFunctionUrlConfigsResult &listFunctionUrlConfigsResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListFunctionUrlConfigsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListFunctionUrlConfigsAction(this->awsLambdaClient,
                success,
                listFunctionUrlConfigsRequest,
                listFunctionUrlConfigsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListFunctionsAction : public FPendingLatentAction {
private:
    bool &success;
    FListFunctionsResult &listFunctionsResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListFunctionsOutcomeCallable callable;

public:
    FListFunctionsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListFunctionsRequest listFunctionsRequest,
        FListFunctionsResult &listFunctionsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listFunctionsResult(listFunctionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListFunctionsCallable(listFunctionsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListFunctionsOutcome = callable.get();

            success = awsListFunctionsOutcome.IsSuccess();
                if (success) {
                    listFunctionsResult.fromAWS(awsListFunctionsOutcome.GetResult());
                }

                errorType = fromAWS(awsListFunctionsOutcome.GetError().GetErrorType());
                errorMessage = ("ListFunctions error: " + awsListFunctionsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListFunctions Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListFunctions(
        UObject *WorldContextObject,
        bool &success,
        FListFunctionsRequest listFunctionsRequest,
        FListFunctionsResult &listFunctionsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListFunctionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListFunctionsAction(this->awsLambdaClient,
                success,
                listFunctionsRequest,
                listFunctionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListFunctionsByCodeSigningConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaListFunctionsByCodeSigningConfigResult &listFunctionsByCodeSigningConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListFunctionsByCodeSigningConfigOutcomeCallable callable;

public:
    FListFunctionsByCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaListFunctionsByCodeSigningConfigRequest listFunctionsByCodeSigningConfigRequest,
        FAWSLambdaListFunctionsByCodeSigningConfigResult &listFunctionsByCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listFunctionsByCodeSigningConfigResult(listFunctionsByCodeSigningConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListFunctionsByCodeSigningConfigCallable(listFunctionsByCodeSigningConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListFunctionsByCodeSigningConfigOutcome = callable.get();

            success = awsListFunctionsByCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    listFunctionsByCodeSigningConfigResult.fromAWS(awsListFunctionsByCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsListFunctionsByCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("ListFunctionsByCodeSigningConfig error: " + awsListFunctionsByCodeSigningConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListFunctionsByCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListFunctionsByCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaListFunctionsByCodeSigningConfigRequest listFunctionsByCodeSigningConfigRequest,
    FAWSLambdaListFunctionsByCodeSigningConfigResult &listFunctionsByCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListFunctionsByCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListFunctionsByCodeSigningConfigAction(this->awsLambdaClient,
                success,
                listFunctionsByCodeSigningConfigRequest,
                listFunctionsByCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListLayerVersionsAction : public FPendingLatentAction {
private:
    bool &success;
    FListLayerVersionsResult &listLayerVersionsResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListLayerVersionsOutcomeCallable callable;

public:
    FListLayerVersionsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListLayerVersionsRequest listLayerVersionsRequest,
        FListLayerVersionsResult &listLayerVersionsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listLayerVersionsResult(listLayerVersionsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListLayerVersionsCallable(listLayerVersionsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListLayerVersionsOutcome = callable.get();

            success = awsListLayerVersionsOutcome.IsSuccess();
                if (success) {
                    listLayerVersionsResult.fromAWS(awsListLayerVersionsOutcome.GetResult());
                }

                errorType = fromAWS(awsListLayerVersionsOutcome.GetError().GetErrorType());
                errorMessage = ("ListLayerVersions error: " + awsListLayerVersionsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListLayerVersions Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListLayerVersions(
        UObject *WorldContextObject,
        bool &success,
        FListLayerVersionsRequest listLayerVersionsRequest,
        FListLayerVersionsResult &listLayerVersionsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListLayerVersionsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListLayerVersionsAction(this->awsLambdaClient,
                success,
                listLayerVersionsRequest,
                listLayerVersionsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListLayersAction : public FPendingLatentAction {
private:
    bool &success;
    FListLayersResult &listLayersResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListLayersOutcomeCallable callable;

public:
    FListLayersAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListLayersRequest listLayersRequest,
        FListLayersResult &listLayersResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listLayersResult(listLayersResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListLayersCallable(listLayersRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListLayersOutcome = callable.get();

            success = awsListLayersOutcome.IsSuccess();
                if (success) {
                    listLayersResult.fromAWS(awsListLayersOutcome.GetResult());
                }

                errorType = fromAWS(awsListLayersOutcome.GetError().GetErrorType());
                errorMessage = ("ListLayers error: " + awsListLayersOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListLayers Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListLayers(
        UObject *WorldContextObject,
        bool &success,
        FListLayersRequest listLayersRequest,
        FListLayersResult &listLayersResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListLayersAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListLayersAction(this->awsLambdaClient,
                success,
                listLayersRequest,
                listLayersResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListProvisionedConcurrencyConfigsAction : public FPendingLatentAction {
private:
    bool &success;
    FListProvisionedConcurrencyConfigsResult &listProvisionedConcurrencyConfigsResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListProvisionedConcurrencyConfigsOutcomeCallable callable;

public:
    FListProvisionedConcurrencyConfigsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListProvisionedConcurrencyConfigsRequest listProvisionedConcurrencyConfigsRequest,
        FListProvisionedConcurrencyConfigsResult &listProvisionedConcurrencyConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listProvisionedConcurrencyConfigsResult(listProvisionedConcurrencyConfigsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListProvisionedConcurrencyConfigsCallable(listProvisionedConcurrencyConfigsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListProvisionedConcurrencyConfigsOutcome = callable.get();

            success = awsListProvisionedConcurrencyConfigsOutcome.IsSuccess();
                if (success) {
                    listProvisionedConcurrencyConfigsResult.fromAWS(awsListProvisionedConcurrencyConfigsOutcome.GetResult());
                }

                errorType = fromAWS(awsListProvisionedConcurrencyConfigsOutcome.GetError().GetErrorType());
                errorMessage = ("ListProvisionedConcurrencyConfigs error: " + awsListProvisionedConcurrencyConfigsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListProvisionedConcurrencyConfigs Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListProvisionedConcurrencyConfigs(
        UObject *WorldContextObject,
        bool &success,
        FListProvisionedConcurrencyConfigsRequest listProvisionedConcurrencyConfigsRequest,
        FListProvisionedConcurrencyConfigsResult &listProvisionedConcurrencyConfigsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListProvisionedConcurrencyConfigsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListProvisionedConcurrencyConfigsAction(this->awsLambdaClient,
                success,
                listProvisionedConcurrencyConfigsRequest,
                listProvisionedConcurrencyConfigsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListTagsAction : public FPendingLatentAction {
private:
    bool &success;
    FListTagsResult &listTagsResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListTagsOutcomeCallable callable;

public:
    FListTagsAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListTagsRequest listTagsRequest,
        FListTagsResult &listTagsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listTagsResult(listTagsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListTagsCallable(listTagsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListTagsOutcome = callable.get();

            success = awsListTagsOutcome.IsSuccess();
                if (success) {
                    listTagsResult.fromAWS(awsListTagsOutcome.GetResult());
                }

                errorType = fromAWS(awsListTagsOutcome.GetError().GetErrorType());
                errorMessage = ("ListTags error: " + awsListTagsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListTags Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListTags(
        UObject *WorldContextObject,
        bool &success,
        FListTagsRequest listTagsRequest,
        FListTagsResult &listTagsResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListTagsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListTagsAction(this->awsLambdaClient,
                success,
                listTagsRequest,
                listTagsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FListVersionsByFunctionAction : public FPendingLatentAction {
private:
    bool &success;
    FListVersionsByFunctionResult &listVersionsByFunctionResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::ListVersionsByFunctionOutcomeCallable callable;

public:
    FListVersionsByFunctionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FListVersionsByFunctionRequest listVersionsByFunctionRequest,
        FListVersionsByFunctionResult &listVersionsByFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listVersionsByFunctionResult(listVersionsByFunctionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->ListVersionsByFunctionCallable(listVersionsByFunctionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListVersionsByFunctionOutcome = callable.get();

            success = awsListVersionsByFunctionOutcome.IsSuccess();
                if (success) {
                    listVersionsByFunctionResult.fromAWS(awsListVersionsByFunctionOutcome.GetResult());
                }

                errorType = fromAWS(awsListVersionsByFunctionOutcome.GetError().GetErrorType());
                errorMessage = ("ListVersionsByFunction error: " + awsListVersionsByFunctionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListVersionsByFunction Request");
    }

#endif
};

#endif

void
ULambdaClientObject::ListVersionsByFunction(
        UObject *WorldContextObject,
        bool &success,
        FListVersionsByFunctionRequest listVersionsByFunctionRequest,
        FListVersionsByFunctionResult &listVersionsByFunctionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListVersionsByFunctionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListVersionsByFunctionAction(this->awsLambdaClient,
                success,
                listVersionsByFunctionRequest,
                listVersionsByFunctionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPublishLayerVersionAction : public FPendingLatentAction {
private:
    bool &success;
    FPublishLayerVersionResult &publishLayerVersionResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::PublishLayerVersionOutcomeCallable callable;

public:
    FPublishLayerVersionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FPublishLayerVersionRequest publishLayerVersionRequest,
        FPublishLayerVersionResult &publishLayerVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), publishLayerVersionResult(publishLayerVersionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->PublishLayerVersionCallable(publishLayerVersionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPublishLayerVersionOutcome = callable.get();

            success = awsPublishLayerVersionOutcome.IsSuccess();
                if (success) {
                    publishLayerVersionResult.fromAWS(awsPublishLayerVersionOutcome.GetResult());
                }

                errorType = fromAWS(awsPublishLayerVersionOutcome.GetError().GetErrorType());
                errorMessage = ("PublishLayerVersion error: " + awsPublishLayerVersionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PublishLayerVersion Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PublishLayerVersion(
        UObject *WorldContextObject,
        bool &success,
        FPublishLayerVersionRequest publishLayerVersionRequest,
        FPublishLayerVersionResult &publishLayerVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPublishLayerVersionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPublishLayerVersionAction(this->awsLambdaClient,
                success,
                publishLayerVersionRequest,
                publishLayerVersionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPublishVersionAction : public FPendingLatentAction {
private:
    bool &success;
    FPublishVersionResult &publishVersionResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::PublishVersionOutcomeCallable callable;

public:
    FPublishVersionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FPublishVersionRequest publishVersionRequest,
        FPublishVersionResult &publishVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), publishVersionResult(publishVersionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->PublishVersionCallable(publishVersionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPublishVersionOutcome = callable.get();

            success = awsPublishVersionOutcome.IsSuccess();
                if (success) {
                    publishVersionResult.fromAWS(awsPublishVersionOutcome.GetResult());
                }

                errorType = fromAWS(awsPublishVersionOutcome.GetError().GetErrorType());
                errorMessage = ("PublishVersion error: " + awsPublishVersionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PublishVersion Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PublishVersion(
        UObject *WorldContextObject,
        bool &success,
        FPublishVersionRequest publishVersionRequest,
        FPublishVersionResult &publishVersionResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPublishVersionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPublishVersionAction(this->awsLambdaClient,
                success,
                publishVersionRequest,
                publishVersionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPutFunctionCodeSigningConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaPutFunctionCodeSigningConfigResult &putFunctionCodeSigningConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::PutFunctionCodeSigningConfigOutcomeCallable callable;

public:
    FPutFunctionCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaPutFunctionCodeSigningConfigRequest putFunctionCodeSigningConfigRequest,
        FAWSLambdaPutFunctionCodeSigningConfigResult &putFunctionCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putFunctionCodeSigningConfigResult(putFunctionCodeSigningConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->PutFunctionCodeSigningConfigCallable(putFunctionCodeSigningConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutFunctionCodeSigningConfigOutcome = callable.get();

            success = awsPutFunctionCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    putFunctionCodeSigningConfigResult.fromAWS(awsPutFunctionCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsPutFunctionCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("PutFunctionCodeSigningConfig error: " + awsPutFunctionCodeSigningConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutFunctionCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PutFunctionCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaPutFunctionCodeSigningConfigRequest putFunctionCodeSigningConfigRequest,
    FAWSLambdaPutFunctionCodeSigningConfigResult &putFunctionCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutFunctionCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutFunctionCodeSigningConfigAction(this->awsLambdaClient,
                success,
                putFunctionCodeSigningConfigRequest,
                putFunctionCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPutFunctionConcurrencyAction : public FPendingLatentAction {
private:
    bool &success;
    FPutFunctionConcurrencyResult &putFunctionConcurrencyResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::PutFunctionConcurrencyOutcomeCallable callable;

public:
    FPutFunctionConcurrencyAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FPutFunctionConcurrencyRequest putFunctionConcurrencyRequest,
        FPutFunctionConcurrencyResult &putFunctionConcurrencyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putFunctionConcurrencyResult(putFunctionConcurrencyResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->PutFunctionConcurrencyCallable(putFunctionConcurrencyRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutFunctionConcurrencyOutcome = callable.get();

            success = awsPutFunctionConcurrencyOutcome.IsSuccess();
                if (success) {
                    putFunctionConcurrencyResult.fromAWS(awsPutFunctionConcurrencyOutcome.GetResult());
                }

                errorType = fromAWS(awsPutFunctionConcurrencyOutcome.GetError().GetErrorType());
                errorMessage = ("PutFunctionConcurrency error: " + awsPutFunctionConcurrencyOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutFunctionConcurrency Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PutFunctionConcurrency(
        UObject *WorldContextObject,
        bool &success,
        FPutFunctionConcurrencyRequest putFunctionConcurrencyRequest,
        FPutFunctionConcurrencyResult &putFunctionConcurrencyResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutFunctionConcurrencyAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutFunctionConcurrencyAction(this->awsLambdaClient,
                success,
                putFunctionConcurrencyRequest,
                putFunctionConcurrencyResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPutFunctionEventInvokeConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FPutFunctionEventInvokeConfigResult &putFunctionEventInvokeConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::PutFunctionEventInvokeConfigOutcomeCallable callable;

public:
    FPutFunctionEventInvokeConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FPutFunctionEventInvokeConfigRequest putFunctionEventInvokeConfigRequest,
        FPutFunctionEventInvokeConfigResult &putFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putFunctionEventInvokeConfigResult(putFunctionEventInvokeConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->PutFunctionEventInvokeConfigCallable(putFunctionEventInvokeConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutFunctionEventInvokeConfigOutcome = callable.get();

            success = awsPutFunctionEventInvokeConfigOutcome.IsSuccess();
                if (success) {
                    putFunctionEventInvokeConfigResult.fromAWS(awsPutFunctionEventInvokeConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsPutFunctionEventInvokeConfigOutcome.GetError().GetErrorType());
                errorMessage = ("PutFunctionEventInvokeConfig error: " + awsPutFunctionEventInvokeConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutFunctionEventInvokeConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PutFunctionEventInvokeConfig(
        UObject *WorldContextObject,
        bool &success,
        FPutFunctionEventInvokeConfigRequest putFunctionEventInvokeConfigRequest,
        FPutFunctionEventInvokeConfigResult &putFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutFunctionEventInvokeConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutFunctionEventInvokeConfigAction(this->awsLambdaClient,
                success,
                putFunctionEventInvokeConfigRequest,
                putFunctionEventInvokeConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FPutProvisionedConcurrencyConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FPutProvisionedConcurrencyConfigResult &putProvisionedConcurrencyConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::PutProvisionedConcurrencyConfigOutcomeCallable callable;

public:
    FPutProvisionedConcurrencyConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FPutProvisionedConcurrencyConfigRequest putProvisionedConcurrencyConfigRequest,
        FPutProvisionedConcurrencyConfigResult &putProvisionedConcurrencyConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putProvisionedConcurrencyConfigResult(putProvisionedConcurrencyConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->PutProvisionedConcurrencyConfigCallable(putProvisionedConcurrencyConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutProvisionedConcurrencyConfigOutcome = callable.get();

            success = awsPutProvisionedConcurrencyConfigOutcome.IsSuccess();
                if (success) {
                    putProvisionedConcurrencyConfigResult.fromAWS(awsPutProvisionedConcurrencyConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsPutProvisionedConcurrencyConfigOutcome.GetError().GetErrorType());
                errorMessage = ("PutProvisionedConcurrencyConfig error: " + awsPutProvisionedConcurrencyConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutProvisionedConcurrencyConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::PutProvisionedConcurrencyConfig(
        UObject *WorldContextObject,
        bool &success,
        FPutProvisionedConcurrencyConfigRequest putProvisionedConcurrencyConfigRequest,
        FPutProvisionedConcurrencyConfigResult &putProvisionedConcurrencyConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutProvisionedConcurrencyConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutProvisionedConcurrencyConfigAction(this->awsLambdaClient,
                success,
                putProvisionedConcurrencyConfigRequest,
                putProvisionedConcurrencyConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FRemoveLayerVersionPermissionAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::RemoveLayerVersionPermissionOutcomeCallable callable;

public:
    FRemoveLayerVersionPermissionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FRemoveLayerVersionPermissionRequest removeLayerVersionPermissionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->RemoveLayerVersionPermissionCallable(removeLayerVersionPermissionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsRemoveLayerVersionPermissionOutcome = callable.get();

            success = awsRemoveLayerVersionPermissionOutcome.IsSuccess();

                errorType = fromAWS(awsRemoveLayerVersionPermissionOutcome.GetError().GetErrorType());
                errorMessage = ("RemoveLayerVersionPermission error: " + awsRemoveLayerVersionPermissionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RemoveLayerVersionPermission Request");
    }

#endif
};

#endif

void
ULambdaClientObject::RemoveLayerVersionPermission(
        UObject *WorldContextObject,
        bool &success,
        FRemoveLayerVersionPermissionRequest removeLayerVersionPermissionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRemoveLayerVersionPermissionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRemoveLayerVersionPermissionAction(this->awsLambdaClient,
                success,
                removeLayerVersionPermissionRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FRemovePermissionAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::RemovePermissionOutcomeCallable callable;

public:
    FRemovePermissionAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FRemovePermissionRequest removePermissionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->RemovePermissionCallable(removePermissionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsRemovePermissionOutcome = callable.get();

            success = awsRemovePermissionOutcome.IsSuccess();

                errorType = fromAWS(awsRemovePermissionOutcome.GetError().GetErrorType());
                errorMessage = ("RemovePermission error: " + awsRemovePermissionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RemovePermission Request");
    }

#endif
};

#endif

void
ULambdaClientObject::RemovePermission(
        UObject *WorldContextObject,
        bool &success,
        FRemovePermissionRequest removePermissionRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRemovePermissionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRemovePermissionAction(this->awsLambdaClient,
                success,
                removePermissionRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FTagResourceAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::TagResourceOutcomeCallable callable;

public:
    FTagResourceAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaTagResourceRequest tagResourceRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->TagResourceCallable(tagResourceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsTagResourceOutcome = callable.get();

            success = awsTagResourceOutcome.IsSuccess();

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
ULambdaClientObject::TagResource(
        UObject *WorldContextObject,
        bool &success,
        FLambdaTagResourceRequest tagResourceRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FTagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FTagResourceAction(this->awsLambdaClient,
                success,
                tagResourceRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUntagResourceAction : public FPendingLatentAction {
private:
    bool &success;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::UntagResourceOutcomeCallable callable;

public:
    FUntagResourceAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaUntagResourceRequest untagResourceRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->UntagResourceCallable(untagResourceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUntagResourceOutcome = callable.get();

            success = awsUntagResourceOutcome.IsSuccess();

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
ULambdaClientObject::UntagResource(
        UObject *WorldContextObject,
        bool &success,
        FLambdaUntagResourceRequest untagResourceRequest,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUntagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUntagResourceAction(this->awsLambdaClient,
                success,
                untagResourceRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateAliasAction : public FPendingLatentAction {
private:
    bool &success;
    FLambdaUpdateAliasResult &updateAliasResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::UpdateAliasOutcomeCallable callable;

public:
    FUpdateAliasAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FLambdaUpdateAliasRequest updateAliasRequest,
        FLambdaUpdateAliasResult &updateAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateAliasResult(updateAliasResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->UpdateAliasCallable(updateAliasRequest.toAWS());
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
ULambdaClientObject::UpdateAlias(
        UObject *WorldContextObject,
        bool &success,
        FLambdaUpdateAliasRequest updateAliasRequest,
        FLambdaUpdateAliasResult &updateAliasResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateAliasAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateAliasAction(this->awsLambdaClient,
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
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateCodeSigningConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaUpdateCodeSigningConfigResult &updateCodeSigningConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::UpdateCodeSigningConfigOutcomeCallable callable;

public:
    FUpdateCodeSigningConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaUpdateCodeSigningConfigRequest updateCodeSigningConfigRequest,
        FAWSLambdaUpdateCodeSigningConfigResult &updateCodeSigningConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateCodeSigningConfigResult(updateCodeSigningConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->UpdateCodeSigningConfigCallable(updateCodeSigningConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateCodeSigningConfigOutcome = callable.get();

            success = awsUpdateCodeSigningConfigOutcome.IsSuccess();
                if (success) {
                    updateCodeSigningConfigResult.fromAWS(awsUpdateCodeSigningConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateCodeSigningConfigOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateCodeSigningConfig error: " + awsUpdateCodeSigningConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateCodeSigningConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateCodeSigningConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaUpdateCodeSigningConfigRequest updateCodeSigningConfigRequest,
    FAWSLambdaUpdateCodeSigningConfigResult &updateCodeSigningConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateCodeSigningConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateCodeSigningConfigAction(this->awsLambdaClient,
                success,
                updateCodeSigningConfigRequest,
                updateCodeSigningConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateEventSourceMappingAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateEventSourceMappingResult &updateEventSourceMappingResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::UpdateEventSourceMappingOutcomeCallable callable;

public:
    FUpdateEventSourceMappingAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FUpdateEventSourceMappingRequest updateEventSourceMappingRequest,
        FUpdateEventSourceMappingResult &updateEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateEventSourceMappingResult(updateEventSourceMappingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->UpdateEventSourceMappingCallable(updateEventSourceMappingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateEventSourceMappingOutcome = callable.get();

            success = awsUpdateEventSourceMappingOutcome.IsSuccess();
                if (success) {
                    updateEventSourceMappingResult.fromAWS(awsUpdateEventSourceMappingOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateEventSourceMappingOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateEventSourceMapping error: " + awsUpdateEventSourceMappingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateEventSourceMapping Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateEventSourceMapping(
        UObject *WorldContextObject,
        bool &success,
        FUpdateEventSourceMappingRequest updateEventSourceMappingRequest,
        FUpdateEventSourceMappingResult &updateEventSourceMappingResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateEventSourceMappingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateEventSourceMappingAction(this->awsLambdaClient,
                success,
                updateEventSourceMappingRequest,
                updateEventSourceMappingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateFunctionCodeAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateFunctionCodeResult &updateFunctionCodeResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::UpdateFunctionCodeOutcomeCallable callable;

public:
    FUpdateFunctionCodeAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FUpdateFunctionCodeRequest updateFunctionCodeRequest,
        FUpdateFunctionCodeResult &updateFunctionCodeResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateFunctionCodeResult(updateFunctionCodeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->UpdateFunctionCodeCallable(updateFunctionCodeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateFunctionCodeOutcome = callable.get();

            success = awsUpdateFunctionCodeOutcome.IsSuccess();
                if (success) {
                    updateFunctionCodeResult.fromAWS(awsUpdateFunctionCodeOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateFunctionCodeOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateFunctionCode error: " + awsUpdateFunctionCodeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateFunctionCode Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateFunctionCode(
        UObject *WorldContextObject,
        bool &success,
        FUpdateFunctionCodeRequest updateFunctionCodeRequest,
        FUpdateFunctionCodeResult &updateFunctionCodeResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateFunctionCodeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateFunctionCodeAction(this->awsLambdaClient,
                success,
                updateFunctionCodeRequest,
                updateFunctionCodeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateFunctionConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateFunctionConfigurationResult &updateFunctionConfigurationResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::UpdateFunctionConfigurationOutcomeCallable callable;

public:
    FUpdateFunctionConfigurationAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FUpdateFunctionConfigurationRequest updateFunctionConfigurationRequest,
        FUpdateFunctionConfigurationResult &updateFunctionConfigurationResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateFunctionConfigurationResult(updateFunctionConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->UpdateFunctionConfigurationCallable(updateFunctionConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateFunctionConfigurationOutcome = callable.get();

            success = awsUpdateFunctionConfigurationOutcome.IsSuccess();
                if (success) {
                    updateFunctionConfigurationResult.fromAWS(awsUpdateFunctionConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateFunctionConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateFunctionConfiguration error: " + awsUpdateFunctionConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateFunctionConfiguration Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateFunctionConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FUpdateFunctionConfigurationRequest updateFunctionConfigurationRequest,
        FUpdateFunctionConfigurationResult &updateFunctionConfigurationResult,
        ELambdaError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateFunctionConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateFunctionConfigurationAction(this->awsLambdaClient,
                success,
                updateFunctionConfigurationRequest,
                updateFunctionConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateFunctionEventInvokeConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateFunctionEventInvokeConfigResult &updateFunctionEventInvokeConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::UpdateFunctionEventInvokeConfigOutcomeCallable callable;

public:
    FUpdateFunctionEventInvokeConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FUpdateFunctionEventInvokeConfigRequest updateFunctionEventInvokeConfigRequest,
        FUpdateFunctionEventInvokeConfigResult &updateFunctionEventInvokeConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateFunctionEventInvokeConfigResult(updateFunctionEventInvokeConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->UpdateFunctionEventInvokeConfigCallable(updateFunctionEventInvokeConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateFunctionEventInvokeConfigOutcome = callable.get();

            success = awsUpdateFunctionEventInvokeConfigOutcome.IsSuccess();
                if (success) {
                    updateFunctionEventInvokeConfigResult.fromAWS(awsUpdateFunctionEventInvokeConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateFunctionEventInvokeConfigOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateFunctionEventInvokeConfig error: " + awsUpdateFunctionEventInvokeConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateFunctionEventInvokeConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateFunctionEventInvokeConfig(
    UObject *WorldContextObject,
    bool &success,
    FUpdateFunctionEventInvokeConfigRequest updateFunctionEventInvokeConfigRequest,
    FUpdateFunctionEventInvokeConfigResult &updateFunctionEventInvokeConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateFunctionEventInvokeConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateFunctionEventInvokeConfigAction(this->awsLambdaClient,
                success,
                updateFunctionEventInvokeConfigRequest,
                updateFunctionEventInvokeConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_LAMBDACLIENTSDK && WITH_CORE

class FUpdateFunctionUrlConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSLambdaUpdateFunctionUrlConfigResult &updateFunctionUrlConfigResult;
    ELambdaError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::Lambda::Model::UpdateFunctionUrlConfigOutcomeCallable callable;

public:
    FUpdateFunctionUrlConfigAction(
        Aws::Lambda::LambdaClient *LambdaClient,
        bool &success,
        FAWSLambdaUpdateFunctionUrlConfigRequest updateFunctionUrlConfigRequest,
        FAWSLambdaUpdateFunctionUrlConfigResult &updateFunctionUrlConfigResult,
        ELambdaError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateFunctionUrlConfigResult(updateFunctionUrlConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = LambdaClient->UpdateFunctionUrlConfigCallable(updateFunctionUrlConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateFunctionUrlConfigOutcome = callable.get();

            success = awsUpdateFunctionUrlConfigOutcome.IsSuccess();
                if (success) {
                    updateFunctionUrlConfigResult.fromAWS(awsUpdateFunctionUrlConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateFunctionUrlConfigOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateFunctionUrlConfig error: " + awsUpdateFunctionUrlConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateFunctionUrlConfig Request");
    }

#endif
};

#endif

void
ULambdaClientObject::UpdateFunctionUrlConfig(
    UObject *WorldContextObject,
    bool &success,
    FAWSLambdaUpdateFunctionUrlConfigRequest updateFunctionUrlConfigRequest,
    FAWSLambdaUpdateFunctionUrlConfigResult &updateFunctionUrlConfigResult,
    ELambdaError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_LAMBDACLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateFunctionUrlConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateFunctionUrlConfigAction(this->awsLambdaClient,
                success,
                updateFunctionUrlConfigRequest,
                updateFunctionUrlConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}