/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "CognitoIdentityClientObject.h"
#include "CognitoIdentityGlobals.h"
#include "CognitoIdentityPrivatePCH.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_COGNITOIDENTITYCLIENTSDK

ECognitoIdentityError fromAWS(Aws::CognitoIdentity::CognitoIdentityErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::CognitoIdentity::CognitoIdentityErrors::INCOMPLETE_SIGNATURE:
            return ECognitoIdentityError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INTERNAL_FAILURE:
            return ECognitoIdentityError::INTERNAL_FAILURE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_ACTION:
            return ECognitoIdentityError::INVALID_ACTION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_CLIENT_TOKEN_ID:
            return ECognitoIdentityError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_PARAMETER_COMBINATION:
            return ECognitoIdentityError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_QUERY_PARAMETER:
            return ECognitoIdentityError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_PARAMETER_VALUE:
            return ECognitoIdentityError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::MISSING_ACTION:
            return ECognitoIdentityError::MISSING_ACTION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::MISSING_AUTHENTICATION_TOKEN:
            return ECognitoIdentityError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::MISSING_PARAMETER:
            return ECognitoIdentityError::MISSING_PARAMETER;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::OPT_IN_REQUIRED:
            return ECognitoIdentityError::OPT_IN_REQUIRED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::REQUEST_EXPIRED:
            return ECognitoIdentityError::REQUEST_EXPIRED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::SERVICE_UNAVAILABLE:
            return ECognitoIdentityError::SERVICE_UNAVAILABLE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::THROTTLING:
            return ECognitoIdentityError::THROTTLING;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::VALIDATION:
            return ECognitoIdentityError::VALIDATION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::ACCESS_DENIED:
            return ECognitoIdentityError::ACCESS_DENIED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::RESOURCE_NOT_FOUND:
            return ECognitoIdentityError::RESOURCE_NOT_FOUND;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::UNRECOGNIZED_CLIENT:
            return ECognitoIdentityError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::MALFORMED_QUERY_STRING:
            return ECognitoIdentityError::MALFORMED_QUERY_STRING;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::SLOW_DOWN:
            return ECognitoIdentityError::SLOW_DOWN;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::REQUEST_TIME_TOO_SKEWED:
            return ECognitoIdentityError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_SIGNATURE:
            return ECognitoIdentityError::INVALID_SIGNATURE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::SIGNATURE_DOES_NOT_MATCH:
            return ECognitoIdentityError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_ACCESS_KEY_ID:
            return ECognitoIdentityError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::REQUEST_TIMEOUT:
            return ECognitoIdentityError::REQUEST_TIMEOUT;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::NETWORK_CONNECTION:
            return ECognitoIdentityError::NETWORK_CONNECTION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::UNKNOWN:
            return ECognitoIdentityError::UNKNOWN;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::CONCURRENT_MODIFICATION:
            return ECognitoIdentityError::CONCURRENT_MODIFICATION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::DEVELOPER_USER_ALREADY_REGISTERED:
            return ECognitoIdentityError::DEVELOPER_USER_ALREADY_REGISTERED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::EXTERNAL_SERVICE:
            return ECognitoIdentityError::EXTERNAL_SERVICE;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INTERNAL_ERROR:
            return ECognitoIdentityError::INTERNAL_ERROR;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_IDENTITY_POOL_CONFIGURATION:
            return ECognitoIdentityError::INVALID_IDENTITY_POOL_CONFIGURATION;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::INVALID_PARAMETER:
            return ECognitoIdentityError::INVALID_PARAMETER;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::LIMIT_EXCEEDED:
            return ECognitoIdentityError::LIMIT_EXCEEDED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::NOT_AUTHORIZED:
            return ECognitoIdentityError::NOT_AUTHORIZED;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::RESOURCE_CONFLICT:
            return ECognitoIdentityError::RESOURCE_CONFLICT;
            break;
        case Aws::CognitoIdentity::CognitoIdentityErrors::TOO_MANY_REQUESTS:
            return ECognitoIdentityError::TOO_MANY_REQUESTS;
            break;
        default:
            return ECognitoIdentityError::UNKNOWN;
            break;
    }
}

#endif

UCognitoIdentityClientObject *UCognitoIdentityClientObject::CreateCognitoIdentityObject(
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    UCognitoIdentityClientObject *CognitoIdentityClient = NewObject<UCognitoIdentityClientObject>();
    CognitoIdentityClient->awsCognitoIdentityClient = new Aws::CognitoIdentity::CognitoIdentityClient(credentials.toAWS(),
    Aws::MakeShared<Aws::CognitoIdentity::CognitoIdentityEndpointProvider>("unreal"),
    clientConfiguration.toAWS());
    return CognitoIdentityClient;
#endif
    return nullptr;
}

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FCreateIdentityPoolAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateIdentityPoolResult &createIdentityPoolResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::CreateIdentityPoolOutcomeCallable callable;

public:
    FCreateIdentityPoolAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FCreateIdentityPoolRequest createIdentityPoolRequest,
        FCreateIdentityPoolResult &createIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createIdentityPoolResult(createIdentityPoolResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->CreateIdentityPoolCallable(createIdentityPoolRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateIdentityPoolOutcome = callable.get();

            success = awsCreateIdentityPoolOutcome.IsSuccess();
                if (success) {
                    createIdentityPoolResult.fromAWS(awsCreateIdentityPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateIdentityPoolOutcome.GetError().GetErrorType());
                errorMessage = ("CreateIdentityPool error: " + awsCreateIdentityPoolOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateIdentityPool Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::CreateIdentityPool(
        UObject *WorldContextObject,
        bool &success,
        FCreateIdentityPoolRequest createIdentityPoolRequest,
        FCreateIdentityPoolResult &createIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateIdentityPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateIdentityPoolAction(this->awsCognitoIdentityClient,
                success,
                createIdentityPoolRequest,
                createIdentityPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FDeleteIdentitiesAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteIdentitiesResult &deleteIdentitiesResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::DeleteIdentitiesOutcomeCallable callable;

public:
    FDeleteIdentitiesAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FDeleteIdentitiesRequest deleteIdentitiesRequest,
        FDeleteIdentitiesResult &deleteIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteIdentitiesResult(deleteIdentitiesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->DeleteIdentitiesCallable(deleteIdentitiesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteIdentitiesOutcome = callable.get();

            success = awsDeleteIdentitiesOutcome.IsSuccess();
                if (success) {
                    deleteIdentitiesResult.fromAWS(awsDeleteIdentitiesOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteIdentitiesOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteIdentities error: " + awsDeleteIdentitiesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteIdentities Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::DeleteIdentities(
        UObject *WorldContextObject,
        bool &success,
        FDeleteIdentitiesRequest deleteIdentitiesRequest,
        FDeleteIdentitiesResult &deleteIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteIdentitiesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteIdentitiesAction(this->awsCognitoIdentityClient,
                success,
                deleteIdentitiesRequest,
                deleteIdentitiesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FDeleteIdentityPoolAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::DeleteIdentityPoolOutcomeCallable callable;

public:
    FDeleteIdentityPoolAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FDeleteIdentityPoolRequest deleteIdentityPoolRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->DeleteIdentityPoolCallable(deleteIdentityPoolRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteIdentityPoolOutcome = callable.get();

            success = awsDeleteIdentityPoolOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteIdentityPoolOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteIdentityPool error: " + awsDeleteIdentityPoolOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteIdentityPool Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::DeleteIdentityPool(
        UObject *WorldContextObject,
        bool &success,
        FDeleteIdentityPoolRequest deleteIdentityPoolRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteIdentityPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteIdentityPoolAction(this->awsCognitoIdentityClient,
                success,
                deleteIdentityPoolRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FDescribeIdentityAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeIdentityResult &describeIdentityResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::DescribeIdentityOutcomeCallable callable;

public:
    FDescribeIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FDescribeIdentityRequest describeIdentityRequest,
        FDescribeIdentityResult &describeIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeIdentityResult(describeIdentityResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->DescribeIdentityCallable(describeIdentityRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeIdentityOutcome = callable.get();

            success = awsDescribeIdentityOutcome.IsSuccess();
                if (success) {
                    describeIdentityResult.fromAWS(awsDescribeIdentityOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeIdentity error: " + awsDescribeIdentityOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::DescribeIdentity(
        UObject *WorldContextObject,
        bool &success,
        FDescribeIdentityRequest describeIdentityRequest,
        FDescribeIdentityResult &describeIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeIdentityAction(this->awsCognitoIdentityClient,
                success,
                describeIdentityRequest,
                describeIdentityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FDescribeIdentityPoolAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeIdentityPoolResult &describeIdentityPoolResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::DescribeIdentityPoolOutcomeCallable callable;

public:
    FDescribeIdentityPoolAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FDescribeIdentityPoolRequest describeIdentityPoolRequest,
        FDescribeIdentityPoolResult &describeIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeIdentityPoolResult(describeIdentityPoolResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->DescribeIdentityPoolCallable(describeIdentityPoolRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeIdentityPoolOutcome = callable.get();

            success = awsDescribeIdentityPoolOutcome.IsSuccess();
                if (success) {
                    describeIdentityPoolResult.fromAWS(awsDescribeIdentityPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeIdentityPoolOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeIdentityPool error: " + awsDescribeIdentityPoolOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeIdentityPool Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::DescribeIdentityPool(
        UObject *WorldContextObject,
        bool &success,
        FDescribeIdentityPoolRequest describeIdentityPoolRequest,
        FDescribeIdentityPoolResult &describeIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeIdentityPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeIdentityPoolAction(this->awsCognitoIdentityClient,
                success,
                describeIdentityPoolRequest,
                describeIdentityPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetCredentialsForIdentityAction : public FPendingLatentAction {
private:
    bool &success;
    FGetCredentialsForIdentityResult &getCredentialsForIdentityResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::GetCredentialsForIdentityOutcomeCallable callable;

public:
    FGetCredentialsForIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FGetCredentialsForIdentityRequest getCredentialsForIdentityRequest,
        FGetCredentialsForIdentityResult &getCredentialsForIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getCredentialsForIdentityResult(getCredentialsForIdentityResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->GetCredentialsForIdentityCallable(getCredentialsForIdentityRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetCredentialsForIdentityOutcome = callable.get();

            success = awsGetCredentialsForIdentityOutcome.IsSuccess();
                if (success) {
                    getCredentialsForIdentityResult.fromAWS(awsGetCredentialsForIdentityOutcome.GetResult());
                }

                errorType = fromAWS(awsGetCredentialsForIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("GetCredentialsForIdentity error: " + awsGetCredentialsForIdentityOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetCredentialsForIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetCredentialsForIdentity(
        UObject *WorldContextObject,
        bool &success,
        FGetCredentialsForIdentityRequest getCredentialsForIdentityRequest,
        FGetCredentialsForIdentityResult &getCredentialsForIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetCredentialsForIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetCredentialsForIdentityAction(this->awsCognitoIdentityClient,
                success,
                getCredentialsForIdentityRequest,
                getCredentialsForIdentityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetIdAction : public FPendingLatentAction {
private:
    bool &success;
    FGetIdResult &getIdResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::GetIdOutcomeCallable callable;

public:
    FGetIdAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FGetIdRequest getIdRequest,
        FGetIdResult &getIdResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getIdResult(getIdResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->GetIdCallable(getIdRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetIdOutcome = callable.get();

            success = awsGetIdOutcome.IsSuccess();
                if (success) {
                    getIdResult.fromAWS(awsGetIdOutcome.GetResult());
                }

                errorType = fromAWS(awsGetIdOutcome.GetError().GetErrorType());
                errorMessage = ("GetId error: " + awsGetIdOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetId Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetId(
        UObject *WorldContextObject,
        bool &success,
        FGetIdRequest getIdRequest,
        FGetIdResult &getIdResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetIdAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetIdAction(this->awsCognitoIdentityClient,
                success,
                getIdRequest,
                getIdResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetIdentityPoolRolesAction : public FPendingLatentAction {
private:
    bool &success;
    FGetIdentityPoolRolesResult &getIdentityPoolRolesResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::GetIdentityPoolRolesOutcomeCallable callable;

public:
    FGetIdentityPoolRolesAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FGetIdentityPoolRolesRequest getIdentityPoolRolesRequest,
        FGetIdentityPoolRolesResult &getIdentityPoolRolesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getIdentityPoolRolesResult(getIdentityPoolRolesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->GetIdentityPoolRolesCallable(getIdentityPoolRolesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetIdentityPoolRolesOutcome = callable.get();

            success = awsGetIdentityPoolRolesOutcome.IsSuccess();
                if (success) {
                    getIdentityPoolRolesResult.fromAWS(awsGetIdentityPoolRolesOutcome.GetResult());
                }

                errorType = fromAWS(awsGetIdentityPoolRolesOutcome.GetError().GetErrorType());
                errorMessage = ("GetIdentityPoolRoles error: " + awsGetIdentityPoolRolesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetIdentityPoolRoles Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetIdentityPoolRoles(
        UObject *WorldContextObject,
        bool &success,
        FGetIdentityPoolRolesRequest getIdentityPoolRolesRequest,
        FGetIdentityPoolRolesResult &getIdentityPoolRolesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetIdentityPoolRolesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetIdentityPoolRolesAction(this->awsCognitoIdentityClient,
                success,
                getIdentityPoolRolesRequest,
                getIdentityPoolRolesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetOpenIdTokenAction : public FPendingLatentAction {
private:
    bool &success;
    FGetOpenIdTokenResult &getOpenIdTokenResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::GetOpenIdTokenOutcomeCallable callable;

public:
    FGetOpenIdTokenAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FGetOpenIdTokenRequest getOpenIdTokenRequest,
        FGetOpenIdTokenResult &getOpenIdTokenResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getOpenIdTokenResult(getOpenIdTokenResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->GetOpenIdTokenCallable(getOpenIdTokenRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetOpenIdTokenOutcome = callable.get();

            success = awsGetOpenIdTokenOutcome.IsSuccess();
                if (success) {
                    getOpenIdTokenResult.fromAWS(awsGetOpenIdTokenOutcome.GetResult());
                }

                errorType = fromAWS(awsGetOpenIdTokenOutcome.GetError().GetErrorType());
                errorMessage = ("GetOpenIdToken error: " + awsGetOpenIdTokenOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetOpenIdToken Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetOpenIdToken(
        UObject *WorldContextObject,
        bool &success,
        FGetOpenIdTokenRequest getOpenIdTokenRequest,
        FGetOpenIdTokenResult &getOpenIdTokenResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetOpenIdTokenAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetOpenIdTokenAction(this->awsCognitoIdentityClient,
                success,
                getOpenIdTokenRequest,
                getOpenIdTokenResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetOpenIdTokenForDeveloperIdentityAction : public FPendingLatentAction {
private:
    bool &success;
    FGetOpenIdTokenForDeveloperIdentityResult &getOpenIdTokenForDeveloperIdentityResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::GetOpenIdTokenForDeveloperIdentityOutcomeCallable callable;

public:
    FGetOpenIdTokenForDeveloperIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FGetOpenIdTokenForDeveloperIdentityRequest getOpenIdTokenForDeveloperIdentityRequest,
        FGetOpenIdTokenForDeveloperIdentityResult &getOpenIdTokenForDeveloperIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getOpenIdTokenForDeveloperIdentityResult(getOpenIdTokenForDeveloperIdentityResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->GetOpenIdTokenForDeveloperIdentityCallable(getOpenIdTokenForDeveloperIdentityRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetOpenIdTokenForDeveloperIdentityOutcome = callable.get();

            success = awsGetOpenIdTokenForDeveloperIdentityOutcome.IsSuccess();
                if (success) {
                    getOpenIdTokenForDeveloperIdentityResult.fromAWS(awsGetOpenIdTokenForDeveloperIdentityOutcome.GetResult());
                }

                errorType = fromAWS(awsGetOpenIdTokenForDeveloperIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("GetOpenIdTokenForDeveloperIdentity error: " + awsGetOpenIdTokenForDeveloperIdentityOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetOpenIdTokenForDeveloperIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetOpenIdTokenForDeveloperIdentity(
        UObject *WorldContextObject,
        bool &success,
        FGetOpenIdTokenForDeveloperIdentityRequest getOpenIdTokenForDeveloperIdentityRequest,
        FGetOpenIdTokenForDeveloperIdentityResult &getOpenIdTokenForDeveloperIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetOpenIdTokenForDeveloperIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetOpenIdTokenForDeveloperIdentityAction(this->awsCognitoIdentityClient,
                success,
                getOpenIdTokenForDeveloperIdentityRequest,
                getOpenIdTokenForDeveloperIdentityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FGetPrincipalTagAttributeMapAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSCognitoIdentityGetPrincipalTagAttributeMapResult &getPrincipalTagAttributeMapResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::GetPrincipalTagAttributeMapOutcomeCallable callable;

public:
    FGetPrincipalTagAttributeMapAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FAWSCognitoIdentityGetPrincipalTagAttributeMapRequest getPrincipalTagAttributeMapRequest,
        FAWSCognitoIdentityGetPrincipalTagAttributeMapResult &getPrincipalTagAttributeMapResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getPrincipalTagAttributeMapResult(getPrincipalTagAttributeMapResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->GetPrincipalTagAttributeMapCallable(getPrincipalTagAttributeMapRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetPrincipalTagAttributeMapOutcome = callable.get();

            success = awsGetPrincipalTagAttributeMapOutcome.IsSuccess();
                if (success) {
                    getPrincipalTagAttributeMapResult.fromAWS(awsGetPrincipalTagAttributeMapOutcome.GetResult());
                }

                errorType = fromAWS(awsGetPrincipalTagAttributeMapOutcome.GetError().GetErrorType());
                errorMessage = ("GetPrincipalTagAttributeMap error: " + awsGetPrincipalTagAttributeMapOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetPrincipalTagAttributeMap Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::GetPrincipalTagAttributeMap(
    UObject *WorldContextObject,
    bool &success,
    FAWSCognitoIdentityGetPrincipalTagAttributeMapRequest getPrincipalTagAttributeMapRequest,
    FAWSCognitoIdentityGetPrincipalTagAttributeMapResult &getPrincipalTagAttributeMapResult,
    ECognitoIdentityError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetPrincipalTagAttributeMapAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetPrincipalTagAttributeMapAction(this->awsCognitoIdentityClient,
                success,
                getPrincipalTagAttributeMapRequest,
                getPrincipalTagAttributeMapResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FListIdentitiesAction : public FPendingLatentAction {
private:
    bool &success;
    FListIdentitiesResult &listIdentitiesResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::ListIdentitiesOutcomeCallable callable;

public:
    FListIdentitiesAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FListIdentitiesRequest listIdentitiesRequest,
        FListIdentitiesResult &listIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listIdentitiesResult(listIdentitiesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->ListIdentitiesCallable(listIdentitiesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListIdentitiesOutcome = callable.get();

            success = awsListIdentitiesOutcome.IsSuccess();
                if (success) {
                    listIdentitiesResult.fromAWS(awsListIdentitiesOutcome.GetResult());
                }

                errorType = fromAWS(awsListIdentitiesOutcome.GetError().GetErrorType());
                errorMessage = ("ListIdentities error: " + awsListIdentitiesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListIdentities Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::ListIdentities(
        UObject *WorldContextObject,
        bool &success,
        FListIdentitiesRequest listIdentitiesRequest,
        FListIdentitiesResult &listIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListIdentitiesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListIdentitiesAction(this->awsCognitoIdentityClient,
                success,
                listIdentitiesRequest,
                listIdentitiesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FListIdentityPoolsAction : public FPendingLatentAction {
private:
    bool &success;
    FListIdentityPoolsResult &listIdentityPoolsResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::ListIdentityPoolsOutcomeCallable callable;

public:
    FListIdentityPoolsAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FListIdentityPoolsRequest listIdentityPoolsRequest,
        FListIdentityPoolsResult &listIdentityPoolsResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listIdentityPoolsResult(listIdentityPoolsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->ListIdentityPoolsCallable(listIdentityPoolsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListIdentityPoolsOutcome = callable.get();

            success = awsListIdentityPoolsOutcome.IsSuccess();
                if (success) {
                    listIdentityPoolsResult.fromAWS(awsListIdentityPoolsOutcome.GetResult());
                }

                errorType = fromAWS(awsListIdentityPoolsOutcome.GetError().GetErrorType());
                errorMessage = ("ListIdentityPools error: " + awsListIdentityPoolsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListIdentityPools Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::ListIdentityPools(
        UObject *WorldContextObject,
        bool &success,
        FListIdentityPoolsRequest listIdentityPoolsRequest,
        FListIdentityPoolsResult &listIdentityPoolsResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListIdentityPoolsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListIdentityPoolsAction(this->awsCognitoIdentityClient,
                success,
                listIdentityPoolsRequest,
                listIdentityPoolsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FListTagsForResourceAction : public FPendingLatentAction {
private:
    bool &success;
    FCognitoIdentityListTagsForResourceResult &listTagsForResourceResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::ListTagsForResourceOutcomeCallable callable;

public:
    FListTagsForResourceAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FCognitoIdentityListTagsForResourceRequest listTagsForResourceRequest,
        FCognitoIdentityListTagsForResourceResult &listTagsForResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listTagsForResourceResult(listTagsForResourceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->ListTagsForResourceCallable(listTagsForResourceRequest.toAWS());
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
UCognitoIdentityClientObject::ListTagsForResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdentityListTagsForResourceRequest listTagsForResourceRequest,
        FCognitoIdentityListTagsForResourceResult &listTagsForResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListTagsForResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListTagsForResourceAction(this->awsCognitoIdentityClient,
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
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FLookupDeveloperIdentityAction : public FPendingLatentAction {
private:
    bool &success;
    FLookupDeveloperIdentityResult &lookupDeveloperIdentityResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::LookupDeveloperIdentityOutcomeCallable callable;

public:
    FLookupDeveloperIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FLookupDeveloperIdentityRequest lookupDeveloperIdentityRequest,
        FLookupDeveloperIdentityResult &lookupDeveloperIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), lookupDeveloperIdentityResult(lookupDeveloperIdentityResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->LookupDeveloperIdentityCallable(lookupDeveloperIdentityRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsLookupDeveloperIdentityOutcome = callable.get();

            success = awsLookupDeveloperIdentityOutcome.IsSuccess();
                if (success) {
                    lookupDeveloperIdentityResult.fromAWS(awsLookupDeveloperIdentityOutcome.GetResult());
                }

                errorType = fromAWS(awsLookupDeveloperIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("LookupDeveloperIdentity error: " + awsLookupDeveloperIdentityOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("LookupDeveloperIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::LookupDeveloperIdentity(
        UObject *WorldContextObject,
        bool &success,
        FLookupDeveloperIdentityRequest lookupDeveloperIdentityRequest,
        FLookupDeveloperIdentityResult &lookupDeveloperIdentityResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FLookupDeveloperIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FLookupDeveloperIdentityAction(this->awsCognitoIdentityClient,
                success,
                lookupDeveloperIdentityRequest,
                lookupDeveloperIdentityResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FMergeDeveloperIdentitiesAction : public FPendingLatentAction {
private:
    bool &success;
    FMergeDeveloperIdentitiesResult &mergeDeveloperIdentitiesResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::MergeDeveloperIdentitiesOutcomeCallable callable;

public:
    FMergeDeveloperIdentitiesAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FMergeDeveloperIdentitiesRequest mergeDeveloperIdentitiesRequest,
        FMergeDeveloperIdentitiesResult &mergeDeveloperIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), mergeDeveloperIdentitiesResult(mergeDeveloperIdentitiesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->MergeDeveloperIdentitiesCallable(mergeDeveloperIdentitiesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsMergeDeveloperIdentitiesOutcome = callable.get();

            success = awsMergeDeveloperIdentitiesOutcome.IsSuccess();
                if (success) {
                    mergeDeveloperIdentitiesResult.fromAWS(awsMergeDeveloperIdentitiesOutcome.GetResult());
                }

                errorType = fromAWS(awsMergeDeveloperIdentitiesOutcome.GetError().GetErrorType());
                errorMessage = ("MergeDeveloperIdentities error: " + awsMergeDeveloperIdentitiesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("MergeDeveloperIdentities Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::MergeDeveloperIdentities(
        UObject *WorldContextObject,
        bool &success,
        FMergeDeveloperIdentitiesRequest mergeDeveloperIdentitiesRequest,
        FMergeDeveloperIdentitiesResult &mergeDeveloperIdentitiesResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FMergeDeveloperIdentitiesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FMergeDeveloperIdentitiesAction(this->awsCognitoIdentityClient,
                success,
                mergeDeveloperIdentitiesRequest,
                mergeDeveloperIdentitiesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FSetIdentityPoolRolesAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::SetIdentityPoolRolesOutcomeCallable callable;

public:
    FSetIdentityPoolRolesAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FSetIdentityPoolRolesRequest setIdentityPoolRolesRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->SetIdentityPoolRolesCallable(setIdentityPoolRolesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSetIdentityPoolRolesOutcome = callable.get();

            success = awsSetIdentityPoolRolesOutcome.IsSuccess();

                errorType = fromAWS(awsSetIdentityPoolRolesOutcome.GetError().GetErrorType());
                errorMessage = ("SetIdentityPoolRoles error: " + awsSetIdentityPoolRolesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetIdentityPoolRoles Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::SetIdentityPoolRoles(
        UObject *WorldContextObject,
        bool &success,
        FSetIdentityPoolRolesRequest setIdentityPoolRolesRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetIdentityPoolRolesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetIdentityPoolRolesAction(this->awsCognitoIdentityClient,
                success,
                setIdentityPoolRolesRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FSetPrincipalTagAttributeMapAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSCognitoIdentitySetPrincipalTagAttributeMapResult &setPrincipalTagAttributeMapResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::SetPrincipalTagAttributeMapOutcomeCallable callable;

public:
    FSetPrincipalTagAttributeMapAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FAWSCognitoIdentitySetPrincipalTagAttributeMapRequest setPrincipalTagAttributeMapRequest,
        FAWSCognitoIdentitySetPrincipalTagAttributeMapResult &setPrincipalTagAttributeMapResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), setPrincipalTagAttributeMapResult(setPrincipalTagAttributeMapResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->SetPrincipalTagAttributeMapCallable(setPrincipalTagAttributeMapRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSetPrincipalTagAttributeMapOutcome = callable.get();

            success = awsSetPrincipalTagAttributeMapOutcome.IsSuccess();
                if (success) {
                    setPrincipalTagAttributeMapResult.fromAWS(awsSetPrincipalTagAttributeMapOutcome.GetResult());
                }

                errorType = fromAWS(awsSetPrincipalTagAttributeMapOutcome.GetError().GetErrorType());
                errorMessage = ("SetPrincipalTagAttributeMap error: " + awsSetPrincipalTagAttributeMapOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetPrincipalTagAttributeMap Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::SetPrincipalTagAttributeMap(
    UObject *WorldContextObject,
    bool &success,
    FAWSCognitoIdentitySetPrincipalTagAttributeMapRequest setPrincipalTagAttributeMapRequest,
    FAWSCognitoIdentitySetPrincipalTagAttributeMapResult &setPrincipalTagAttributeMapResult,
    ECognitoIdentityError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetPrincipalTagAttributeMapAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetPrincipalTagAttributeMapAction(this->awsCognitoIdentityClient,
                success,
                setPrincipalTagAttributeMapRequest,
                setPrincipalTagAttributeMapResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FTagResourceAction : public FPendingLatentAction {
private:
    bool &success;
    FCognitoIdentityTagResourceResult &tagResourceResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::TagResourceOutcomeCallable callable;

public:
    FTagResourceAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FCognitoIdentityTagResourceRequest tagResourceRequest,
        FCognitoIdentityTagResourceResult &tagResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), tagResourceResult(tagResourceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->TagResourceCallable(tagResourceRequest.toAWS());
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
UCognitoIdentityClientObject::TagResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdentityTagResourceRequest tagResourceRequest,
        FCognitoIdentityTagResourceResult &tagResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FTagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FTagResourceAction(this->awsCognitoIdentityClient,
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
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FUnlinkDeveloperIdentityAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::UnlinkDeveloperIdentityOutcomeCallable callable;

public:
    FUnlinkDeveloperIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FUnlinkDeveloperIdentityRequest unlinkDeveloperIdentityRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->UnlinkDeveloperIdentityCallable(unlinkDeveloperIdentityRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUnlinkDeveloperIdentityOutcome = callable.get();

            success = awsUnlinkDeveloperIdentityOutcome.IsSuccess();

                errorType = fromAWS(awsUnlinkDeveloperIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("UnlinkDeveloperIdentity error: " + awsUnlinkDeveloperIdentityOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UnlinkDeveloperIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::UnlinkDeveloperIdentity(
        UObject *WorldContextObject,
        bool &success,
        FUnlinkDeveloperIdentityRequest unlinkDeveloperIdentityRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUnlinkDeveloperIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUnlinkDeveloperIdentityAction(this->awsCognitoIdentityClient,
                success,
                unlinkDeveloperIdentityRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FUnlinkIdentityAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::UnlinkIdentityOutcomeCallable callable;

public:
    FUnlinkIdentityAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FUnlinkIdentityRequest unlinkIdentityRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->UnlinkIdentityCallable(unlinkIdentityRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUnlinkIdentityOutcome = callable.get();

            success = awsUnlinkIdentityOutcome.IsSuccess();

                errorType = fromAWS(awsUnlinkIdentityOutcome.GetError().GetErrorType());
                errorMessage = ("UnlinkIdentity error: " + awsUnlinkIdentityOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UnlinkIdentity Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::UnlinkIdentity(
        UObject *WorldContextObject,
        bool &success,
        FUnlinkIdentityRequest unlinkIdentityRequest,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUnlinkIdentityAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUnlinkIdentityAction(this->awsCognitoIdentityClient,
                success,
                unlinkIdentityRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FUntagResourceAction : public FPendingLatentAction {
private:
    bool &success;
    FCognitoIdentityUntagResourceResult &untagResourceResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::UntagResourceOutcomeCallable callable;

public:
    FUntagResourceAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FCognitoIdentityUntagResourceRequest untagResourceRequest,
        FCognitoIdentityUntagResourceResult &untagResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), untagResourceResult(untagResourceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->UntagResourceCallable(untagResourceRequest.toAWS());
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
UCognitoIdentityClientObject::UntagResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdentityUntagResourceRequest untagResourceRequest,
        FCognitoIdentityUntagResourceResult &untagResourceResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUntagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUntagResourceAction(this->awsCognitoIdentityClient,
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
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

class FUpdateIdentityPoolAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateIdentityPoolResult &updateIdentityPoolResult;
    ECognitoIdentityError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentity::Model::UpdateIdentityPoolOutcomeCallable callable;

public:
    FUpdateIdentityPoolAction(
        Aws::CognitoIdentity::CognitoIdentityClient *CognitoIdentityClient,
        bool &success,
        FUpdateIdentityPoolRequest updateIdentityPoolRequest,
        FUpdateIdentityPoolResult &updateIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateIdentityPoolResult(updateIdentityPoolResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdentityClient->UpdateIdentityPoolCallable(updateIdentityPoolRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateIdentityPoolOutcome = callable.get();

            success = awsUpdateIdentityPoolOutcome.IsSuccess();
                if (success) {
                    updateIdentityPoolResult.fromAWS(awsUpdateIdentityPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateIdentityPoolOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateIdentityPool error: " + awsUpdateIdentityPoolOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateIdentityPool Request");
    }

#endif
};

#endif

void
UCognitoIdentityClientObject::UpdateIdentityPool(
        UObject *WorldContextObject,
        bool &success,
        FUpdateIdentityPoolRequest updateIdentityPoolRequest,
        FUpdateIdentityPoolResult &updateIdentityPoolResult,
        ECognitoIdentityError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateIdentityPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateIdentityPoolAction(this->awsCognitoIdentityClient,
                success,
                updateIdentityPoolRequest,
                updateIdentityPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}