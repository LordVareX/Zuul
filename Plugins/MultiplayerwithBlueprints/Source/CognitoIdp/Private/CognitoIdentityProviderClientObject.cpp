/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "CognitoIdentityProviderClientObject.h"
#include "CognitoIdpGlobals.h"
#include "CognitoIdpPrivatePCH.h"

#include "Misc/Paths.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_COGNITOIDPCLIENTSDK

ECognitoIdpError fromAWS(Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INCOMPLETE_SIGNATURE:
            return ECognitoIdpError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INTERNAL_FAILURE:
            return ECognitoIdpError::INTERNAL_FAILURE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_ACTION:
            return ECognitoIdpError::INVALID_ACTION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_CLIENT_TOKEN_ID:
            return ECognitoIdpError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_PARAMETER_COMBINATION:
            return ECognitoIdpError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_QUERY_PARAMETER:
            return ECognitoIdpError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_PARAMETER_VALUE:
            return ECognitoIdpError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::MISSING_ACTION:
            return ECognitoIdpError::MISSING_ACTION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::MISSING_AUTHENTICATION_TOKEN:
            return ECognitoIdpError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::MISSING_PARAMETER:
            return ECognitoIdpError::MISSING_PARAMETER;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::OPT_IN_REQUIRED:
            return ECognitoIdpError::OPT_IN_REQUIRED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::REQUEST_EXPIRED:
            return ECognitoIdpError::REQUEST_EXPIRED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::SERVICE_UNAVAILABLE:
            return ECognitoIdpError::SERVICE_UNAVAILABLE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::THROTTLING:
            return ECognitoIdpError::THROTTLING;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::VALIDATION:
            return ECognitoIdpError::VALIDATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::ACCESS_DENIED:
            return ECognitoIdpError::ACCESS_DENIED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::RESOURCE_NOT_FOUND:
            return ECognitoIdpError::RESOURCE_NOT_FOUND;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNRECOGNIZED_CLIENT:
            return ECognitoIdpError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::MALFORMED_QUERY_STRING:
            return ECognitoIdpError::MALFORMED_QUERY_STRING;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::SLOW_DOWN:
            return ECognitoIdpError::SLOW_DOWN;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::REQUEST_TIME_TOO_SKEWED:
            return ECognitoIdpError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_SIGNATURE:
            return ECognitoIdpError::INVALID_SIGNATURE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::SIGNATURE_DOES_NOT_MATCH:
            return ECognitoIdpError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_ACCESS_KEY_ID:
            return ECognitoIdpError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::REQUEST_TIMEOUT:
            return ECognitoIdpError::REQUEST_TIMEOUT;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::NETWORK_CONNECTION:
            return ECognitoIdpError::NETWORK_CONNECTION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNKNOWN:
            return ECognitoIdpError::UNKNOWN;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::ALIAS_EXISTS:
            return ECognitoIdpError::ALIAS_EXISTS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::CODE_DELIVERY_FAILURE:
            return ECognitoIdpError::CODE_DELIVERY_FAILURE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::CODE_MISMATCH:
            return ECognitoIdpError::CODE_MISMATCH;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::CONCURRENT_MODIFICATION:
            return ECognitoIdpError::CONCURRENT_MODIFICATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::DUPLICATE_PROVIDER:
            return ECognitoIdpError::DUPLICATE_PROVIDER;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::ENABLE_SOFTWARE_TOKEN_M_F_A:
            return ECognitoIdpError::ENABLE_SOFTWARE_TOKEN_MFA;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::EXPIRED_CODE:
            return ECognitoIdpError::EXPIRED_CODE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::FORBIDDEN:
            return ECognitoIdpError::FORBIDDEN;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::GROUP_EXISTS:
            return ECognitoIdpError::GROUP_EXISTS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INTERNAL_ERROR:
            return ECognitoIdpError::INTERNAL_ERROR;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_EMAIL_ROLE_ACCESS_POLICY:
            return ECognitoIdpError::INVALID_EMAIL_ROLE_ACCESS_POLICY;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_LAMBDA_RESPONSE:
            return ECognitoIdpError::INVALID_LAMBDA_RESPONSE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_O_AUTH_FLOW:
            return ECognitoIdpError::INVALID_OAUTH_FLOW;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_PARAMETER:
            return ECognitoIdpError::INVALID_PARAMETER;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_PASSWORD:
            return ECognitoIdpError::INVALID_PASSWORD;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_SMS_ROLE_ACCESS_POLICY:
            return ECognitoIdpError::INVALID_SMS_ROLE_ACCESS_POLICY;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_SMS_ROLE_TRUST_RELATIONSHIP:
            return ECognitoIdpError::INVALID_SMS_ROLE_TRUST_RELATIONSHIP;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::INVALID_USER_POOL_CONFIGURATION:
            return ECognitoIdpError::INVALID_USER_POOL_CONFIGURATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::LIMIT_EXCEEDED:
            return ECognitoIdpError::LIMIT_EXCEEDED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::M_F_A_METHOD_NOT_FOUND:
            return ECognitoIdpError::MFA_METHOD_NOT_FOUND;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::NOT_AUTHORIZED:
            return ECognitoIdpError::NOT_AUTHORIZED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::PASSWORD_RESET_REQUIRED:
            return ECognitoIdpError::PASSWORD_RESET_REQUIRED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::PRECONDITION_NOT_MET:
            return ECognitoIdpError::PRECONDITION_NOT_MET;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::SCOPE_DOES_NOT_EXIST:
            return ECognitoIdpError::SCOPE_DOES_NOT_EXIST;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::SOFTWARE_TOKEN_M_F_A_NOT_FOUND:
            return ECognitoIdpError::SOFTWARE_TOKEN_MFA_NOT_FOUND;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::TOO_MANY_FAILED_ATTEMPTS:
            return ECognitoIdpError::TOO_MANY_FAILED_ATTEMPTS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::TOO_MANY_REQUESTS:
            return ECognitoIdpError::TOO_MANY_REQUESTS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNAUTHORIZED:
            return ECognitoIdpError::UNAUTHORIZED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNEXPECTED_LAMBDA:
            return ECognitoIdpError::UNEXPECTED_LAMBDA;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNSUPPORTED_IDENTITY_PROVIDER:
            return ECognitoIdpError::UNSUPPORTED_IDENTITY_PROVIDER;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNSUPPORTED_OPERATION:
            return ECognitoIdpError::UNSUPPORTED_OPERATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNSUPPORTED_TOKEN_TYPE:
            return ECognitoIdpError::UNSUPPORTED_TOKEN_TYPE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::UNSUPPORTED_USER_STATE:
            return ECognitoIdpError::UNSUPPORTED_USER_STATE;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USERNAME_EXISTS:
            return ECognitoIdpError::USERNAME_EXISTS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_IMPORT_IN_PROGRESS:
            return ECognitoIdpError::USER_IMPORT_IN_PROGRESS;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_LAMBDA_VALIDATION:
            return ECognitoIdpError::USER_LAMBDA_VALIDATION;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_NOT_CONFIRMED:
            return ECognitoIdpError::USER_NOT_CONFIRMED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_NOT_FOUND:
            return ECognitoIdpError::USER_NOT_FOUND;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_POOL_ADD_ON_NOT_ENABLED:
            return ECognitoIdpError::USER_POOL_ADDON_NOT_ENABLED;
            break;
        case Aws::CognitoIdentityProvider::CognitoIdentityProviderErrors::USER_POOL_TAGGING:
            return ECognitoIdpError::USER_POOL_TAGGING;
            break;
        default:
            return ECognitoIdpError::UNKNOWN;
            break;
    }
}

#endif

UCognitoIdpClientObject *UCognitoIdpClientObject::CreateCognitoIdpObject(
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    UCognitoIdpClientObject *CognitoIdpClient = NewObject<UCognitoIdpClientObject>();
    CognitoIdpClient->awsCognitoIdentityProviderClient = new Aws::CognitoIdentityProvider::CognitoIdentityProviderClient(credentials.toAWS(),
    Aws::MakeShared<Aws::CognitoIdentityProvider::CognitoIdentityProviderEndpointProvider>("unreal"),
    clientConfiguration.toAWS());
    return CognitoIdpClient;
#endif
    return nullptr;
}

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAddCustomAttributesAction : public FPendingLatentAction {
private:
    bool &success;
    FAddCustomAttributesResult &addCustomAttributesResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AddCustomAttributesOutcomeCallable callable;

public:
    FAddCustomAttributesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAddCustomAttributesRequest addCustomAttributesRequest,
        FAddCustomAttributesResult &addCustomAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), addCustomAttributesResult(addCustomAttributesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AddCustomAttributesCallable(addCustomAttributesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAddCustomAttributesOutcome = callable.get();

            success = awsAddCustomAttributesOutcome.IsSuccess();
                if (success) {
                    addCustomAttributesResult.fromAWS(awsAddCustomAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsAddCustomAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("AddCustomAttributes error: " + awsAddCustomAttributesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AddCustomAttributes Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AddCustomAttributes(
        UObject *WorldContextObject,
        bool &success,
        FAddCustomAttributesRequest addCustomAttributesRequest,
        FAddCustomAttributesResult &addCustomAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAddCustomAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAddCustomAttributesAction(this->awsCognitoIdentityProviderClient,
                success,
                addCustomAttributesRequest,
                addCustomAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminAddUserToGroupAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminAddUserToGroupOutcomeCallable callable;

public:
    FAdminAddUserToGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminAddUserToGroupRequest adminAddUserToGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminAddUserToGroupCallable(adminAddUserToGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminAddUserToGroupOutcome = callable.get();

            success = awsAdminAddUserToGroupOutcome.IsSuccess();

                errorType = fromAWS(awsAdminAddUserToGroupOutcome.GetError().GetErrorType());
                errorMessage = ("AdminAddUserToGroup error: " + awsAdminAddUserToGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminAddUserToGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminAddUserToGroup(
        UObject *WorldContextObject,
        bool &success,
        FAdminAddUserToGroupRequest adminAddUserToGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminAddUserToGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminAddUserToGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                adminAddUserToGroupRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminConfirmSignUpAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminConfirmSignUpResult &adminConfirmSignUpResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminConfirmSignUpOutcomeCallable callable;

public:
    FAdminConfirmSignUpAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminConfirmSignUpRequest adminConfirmSignUpRequest,
        FAdminConfirmSignUpResult &adminConfirmSignUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminConfirmSignUpResult(adminConfirmSignUpResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminConfirmSignUpCallable(adminConfirmSignUpRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminConfirmSignUpOutcome = callable.get();

            success = awsAdminConfirmSignUpOutcome.IsSuccess();
                if (success) {
                    adminConfirmSignUpResult.fromAWS(awsAdminConfirmSignUpOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminConfirmSignUpOutcome.GetError().GetErrorType());
                errorMessage = ("AdminConfirmSignUp error: " + awsAdminConfirmSignUpOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminConfirmSignUp Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminConfirmSignUp(
        UObject *WorldContextObject,
        bool &success,
        FAdminConfirmSignUpRequest adminConfirmSignUpRequest,
        FAdminConfirmSignUpResult &adminConfirmSignUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminConfirmSignUpAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminConfirmSignUpAction(this->awsCognitoIdentityProviderClient,
                success,
                adminConfirmSignUpRequest,
                adminConfirmSignUpResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminCreateUserAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminCreateUserResult &adminCreateUserResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminCreateUserOutcomeCallable callable;

public:
    FAdminCreateUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminCreateUserRequest adminCreateUserRequest,
        FAdminCreateUserResult &adminCreateUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminCreateUserResult(adminCreateUserResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminCreateUserCallable(adminCreateUserRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminCreateUserOutcome = callable.get();

            success = awsAdminCreateUserOutcome.IsSuccess();
                if (success) {
                    adminCreateUserResult.fromAWS(awsAdminCreateUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminCreateUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminCreateUser error: " + awsAdminCreateUserOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminCreateUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminCreateUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminCreateUserRequest adminCreateUserRequest,
        FAdminCreateUserResult &adminCreateUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminCreateUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminCreateUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminCreateUserRequest,
                adminCreateUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminDeleteUserAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminDeleteUserOutcomeCallable callable;

public:
    FAdminDeleteUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminDeleteUserRequest adminDeleteUserRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminDeleteUserCallable(adminDeleteUserRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminDeleteUserOutcome = callable.get();

            success = awsAdminDeleteUserOutcome.IsSuccess();

                errorType = fromAWS(awsAdminDeleteUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminDeleteUser error: " + awsAdminDeleteUserOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminDeleteUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminDeleteUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminDeleteUserRequest adminDeleteUserRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminDeleteUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminDeleteUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminDeleteUserRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminDeleteUserAttributesAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminDeleteUserAttributesResult &adminDeleteUserAttributesResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminDeleteUserAttributesOutcomeCallable callable;

public:
    FAdminDeleteUserAttributesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminDeleteUserAttributesRequest adminDeleteUserAttributesRequest,
        FAdminDeleteUserAttributesResult &adminDeleteUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminDeleteUserAttributesResult(adminDeleteUserAttributesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminDeleteUserAttributesCallable(adminDeleteUserAttributesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminDeleteUserAttributesOutcome = callable.get();

            success = awsAdminDeleteUserAttributesOutcome.IsSuccess();
                if (success) {
                    adminDeleteUserAttributesResult.fromAWS(awsAdminDeleteUserAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminDeleteUserAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("AdminDeleteUserAttributes error: " + awsAdminDeleteUserAttributesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminDeleteUserAttributes Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminDeleteUserAttributes(
        UObject *WorldContextObject,
        bool &success,
        FAdminDeleteUserAttributesRequest adminDeleteUserAttributesRequest,
        FAdminDeleteUserAttributesResult &adminDeleteUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminDeleteUserAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminDeleteUserAttributesAction(this->awsCognitoIdentityProviderClient,
                success,
                adminDeleteUserAttributesRequest,
                adminDeleteUserAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminDisableProviderForUserAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminDisableProviderForUserResult &adminDisableProviderForUserResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminDisableProviderForUserOutcomeCallable callable;

public:
    FAdminDisableProviderForUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminDisableProviderForUserRequest adminDisableProviderForUserRequest,
        FAdminDisableProviderForUserResult &adminDisableProviderForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminDisableProviderForUserResult(adminDisableProviderForUserResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminDisableProviderForUserCallable(adminDisableProviderForUserRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminDisableProviderForUserOutcome = callable.get();

            success = awsAdminDisableProviderForUserOutcome.IsSuccess();
                if (success) {
                    adminDisableProviderForUserResult.fromAWS(awsAdminDisableProviderForUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminDisableProviderForUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminDisableProviderForUser error: " + awsAdminDisableProviderForUserOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminDisableProviderForUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminDisableProviderForUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminDisableProviderForUserRequest adminDisableProviderForUserRequest,
        FAdminDisableProviderForUserResult &adminDisableProviderForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminDisableProviderForUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminDisableProviderForUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminDisableProviderForUserRequest,
                adminDisableProviderForUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminDisableUserAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminDisableUserResult &adminDisableUserResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminDisableUserOutcomeCallable callable;

public:
    FAdminDisableUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminDisableUserRequest adminDisableUserRequest,
        FAdminDisableUserResult &adminDisableUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminDisableUserResult(adminDisableUserResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminDisableUserCallable(adminDisableUserRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminDisableUserOutcome = callable.get();

            success = awsAdminDisableUserOutcome.IsSuccess();
                if (success) {
                    adminDisableUserResult.fromAWS(awsAdminDisableUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminDisableUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminDisableUser error: " + awsAdminDisableUserOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminDisableUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminDisableUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminDisableUserRequest adminDisableUserRequest,
        FAdminDisableUserResult &adminDisableUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminDisableUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminDisableUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminDisableUserRequest,
                adminDisableUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminEnableUserAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminEnableUserResult &adminEnableUserResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminEnableUserOutcomeCallable callable;

public:
    FAdminEnableUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminEnableUserRequest adminEnableUserRequest,
        FAdminEnableUserResult &adminEnableUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminEnableUserResult(adminEnableUserResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminEnableUserCallable(adminEnableUserRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminEnableUserOutcome = callable.get();

            success = awsAdminEnableUserOutcome.IsSuccess();
                if (success) {
                    adminEnableUserResult.fromAWS(awsAdminEnableUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminEnableUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminEnableUser error: " + awsAdminEnableUserOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminEnableUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminEnableUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminEnableUserRequest adminEnableUserRequest,
        FAdminEnableUserResult &adminEnableUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminEnableUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminEnableUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminEnableUserRequest,
                adminEnableUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminForgetDeviceAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminForgetDeviceOutcomeCallable callable;

public:
    FAdminForgetDeviceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminForgetDeviceRequest adminForgetDeviceRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminForgetDeviceCallable(adminForgetDeviceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminForgetDeviceOutcome = callable.get();

            success = awsAdminForgetDeviceOutcome.IsSuccess();

                errorType = fromAWS(awsAdminForgetDeviceOutcome.GetError().GetErrorType());
                errorMessage = ("AdminForgetDevice error: " + awsAdminForgetDeviceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminForgetDevice Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminForgetDevice(
        UObject *WorldContextObject,
        bool &success,
        FAdminForgetDeviceRequest adminForgetDeviceRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminForgetDeviceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminForgetDeviceAction(this->awsCognitoIdentityProviderClient,
                success,
                adminForgetDeviceRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminGetDeviceAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminGetDeviceResult &adminGetDeviceResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminGetDeviceOutcomeCallable callable;

public:
    FAdminGetDeviceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminGetDeviceRequest adminGetDeviceRequest,
        FAdminGetDeviceResult &adminGetDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminGetDeviceResult(adminGetDeviceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminGetDeviceCallable(adminGetDeviceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminGetDeviceOutcome = callable.get();

            success = awsAdminGetDeviceOutcome.IsSuccess();
                if (success) {
                    adminGetDeviceResult.fromAWS(awsAdminGetDeviceOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminGetDeviceOutcome.GetError().GetErrorType());
                errorMessage = ("AdminGetDevice error: " + awsAdminGetDeviceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminGetDevice Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminGetDevice(
        UObject *WorldContextObject,
        bool &success,
        FAdminGetDeviceRequest adminGetDeviceRequest,
        FAdminGetDeviceResult &adminGetDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminGetDeviceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminGetDeviceAction(this->awsCognitoIdentityProviderClient,
                success,
                adminGetDeviceRequest,
                adminGetDeviceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminGetUserAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminGetUserResult &adminGetUserResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminGetUserOutcomeCallable callable;

public:
    FAdminGetUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminGetUserRequest adminGetUserRequest,
        FAdminGetUserResult &adminGetUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminGetUserResult(adminGetUserResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminGetUserCallable(adminGetUserRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminGetUserOutcome = callable.get();

            success = awsAdminGetUserOutcome.IsSuccess();
                if (success) {
                    adminGetUserResult.fromAWS(awsAdminGetUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminGetUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminGetUser error: " + awsAdminGetUserOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminGetUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminGetUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminGetUserRequest adminGetUserRequest,
        FAdminGetUserResult &adminGetUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminGetUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminGetUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminGetUserRequest,
                adminGetUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminInitiateAuthAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminInitiateAuthResult &adminInitiateAuthResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminInitiateAuthOutcomeCallable callable;

public:
    FAdminInitiateAuthAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminInitiateAuthRequest adminInitiateAuthRequest,
        FAdminInitiateAuthResult &adminInitiateAuthResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminInitiateAuthResult(adminInitiateAuthResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminInitiateAuthCallable(adminInitiateAuthRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminInitiateAuthOutcome = callable.get();

            success = awsAdminInitiateAuthOutcome.IsSuccess();
                if (success) {
                    adminInitiateAuthResult.fromAWS(awsAdminInitiateAuthOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminInitiateAuthOutcome.GetError().GetErrorType());
                errorMessage = ("AdminInitiateAuth error: " + awsAdminInitiateAuthOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminInitiateAuth Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminInitiateAuth(
        UObject *WorldContextObject,
        bool &success,
        FAdminInitiateAuthRequest adminInitiateAuthRequest,
        FAdminInitiateAuthResult &adminInitiateAuthResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminInitiateAuthAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminInitiateAuthAction(this->awsCognitoIdentityProviderClient,
                success,
                adminInitiateAuthRequest,
                adminInitiateAuthResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminLinkProviderForUserAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminLinkProviderForUserResult &adminLinkProviderForUserResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminLinkProviderForUserOutcomeCallable callable;

public:
    FAdminLinkProviderForUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminLinkProviderForUserRequest adminLinkProviderForUserRequest,
        FAdminLinkProviderForUserResult &adminLinkProviderForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminLinkProviderForUserResult(adminLinkProviderForUserResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminLinkProviderForUserCallable(adminLinkProviderForUserRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminLinkProviderForUserOutcome = callable.get();

            success = awsAdminLinkProviderForUserOutcome.IsSuccess();
                if (success) {
                    adminLinkProviderForUserResult.fromAWS(awsAdminLinkProviderForUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminLinkProviderForUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminLinkProviderForUser error: " + awsAdminLinkProviderForUserOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminLinkProviderForUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminLinkProviderForUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminLinkProviderForUserRequest adminLinkProviderForUserRequest,
        FAdminLinkProviderForUserResult &adminLinkProviderForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminLinkProviderForUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminLinkProviderForUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminLinkProviderForUserRequest,
                adminLinkProviderForUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminListDevicesAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminListDevicesResult &adminListDevicesResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminListDevicesOutcomeCallable callable;

public:
    FAdminListDevicesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminListDevicesRequest adminListDevicesRequest,
        FAdminListDevicesResult &adminListDevicesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminListDevicesResult(adminListDevicesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminListDevicesCallable(adminListDevicesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminListDevicesOutcome = callable.get();

            success = awsAdminListDevicesOutcome.IsSuccess();
                if (success) {
                    adminListDevicesResult.fromAWS(awsAdminListDevicesOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminListDevicesOutcome.GetError().GetErrorType());
                errorMessage = ("AdminListDevices error: " + awsAdminListDevicesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminListDevices Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminListDevices(
        UObject *WorldContextObject,
        bool &success,
        FAdminListDevicesRequest adminListDevicesRequest,
        FAdminListDevicesResult &adminListDevicesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminListDevicesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminListDevicesAction(this->awsCognitoIdentityProviderClient,
                success,
                adminListDevicesRequest,
                adminListDevicesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminListGroupsForUserAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminListGroupsForUserResult &adminListGroupsForUserResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminListGroupsForUserOutcomeCallable callable;

public:
    FAdminListGroupsForUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminListGroupsForUserRequest adminListGroupsForUserRequest,
        FAdminListGroupsForUserResult &adminListGroupsForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminListGroupsForUserResult(adminListGroupsForUserResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminListGroupsForUserCallable(adminListGroupsForUserRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminListGroupsForUserOutcome = callable.get();

            success = awsAdminListGroupsForUserOutcome.IsSuccess();
                if (success) {
                    adminListGroupsForUserResult.fromAWS(awsAdminListGroupsForUserOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminListGroupsForUserOutcome.GetError().GetErrorType());
                errorMessage = ("AdminListGroupsForUser error: " + awsAdminListGroupsForUserOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminListGroupsForUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminListGroupsForUser(
        UObject *WorldContextObject,
        bool &success,
        FAdminListGroupsForUserRequest adminListGroupsForUserRequest,
        FAdminListGroupsForUserResult &adminListGroupsForUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminListGroupsForUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminListGroupsForUserAction(this->awsCognitoIdentityProviderClient,
                success,
                adminListGroupsForUserRequest,
                adminListGroupsForUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminListUserAuthEventsAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminListUserAuthEventsResult &adminListUserAuthEventsResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminListUserAuthEventsOutcomeCallable callable;

public:
    FAdminListUserAuthEventsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminListUserAuthEventsRequest adminListUserAuthEventsRequest,
        FAdminListUserAuthEventsResult &adminListUserAuthEventsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminListUserAuthEventsResult(adminListUserAuthEventsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminListUserAuthEventsCallable(adminListUserAuthEventsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminListUserAuthEventsOutcome = callable.get();

            success = awsAdminListUserAuthEventsOutcome.IsSuccess();
                if (success) {
                    adminListUserAuthEventsResult.fromAWS(awsAdminListUserAuthEventsOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminListUserAuthEventsOutcome.GetError().GetErrorType());
                errorMessage = ("AdminListUserAuthEvents error: " + awsAdminListUserAuthEventsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminListUserAuthEvents Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminListUserAuthEvents(
        UObject *WorldContextObject,
        bool &success,
        FAdminListUserAuthEventsRequest adminListUserAuthEventsRequest,
        FAdminListUserAuthEventsResult &adminListUserAuthEventsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminListUserAuthEventsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminListUserAuthEventsAction(this->awsCognitoIdentityProviderClient,
                success,
                adminListUserAuthEventsRequest,
                adminListUserAuthEventsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminRemoveUserFromGroupAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminRemoveUserFromGroupOutcomeCallable callable;

public:
    FAdminRemoveUserFromGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminRemoveUserFromGroupRequest adminRemoveUserFromGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminRemoveUserFromGroupCallable(adminRemoveUserFromGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminRemoveUserFromGroupOutcome = callable.get();

            success = awsAdminRemoveUserFromGroupOutcome.IsSuccess();

                errorType = fromAWS(awsAdminRemoveUserFromGroupOutcome.GetError().GetErrorType());
                errorMessage = ("AdminRemoveUserFromGroup error: " + awsAdminRemoveUserFromGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminRemoveUserFromGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminRemoveUserFromGroup(
        UObject *WorldContextObject,
        bool &success,
        FAdminRemoveUserFromGroupRequest adminRemoveUserFromGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminRemoveUserFromGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminRemoveUserFromGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                adminRemoveUserFromGroupRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminResetUserPasswordAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminResetUserPasswordResult &adminResetUserPasswordResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminResetUserPasswordOutcomeCallable callable;

public:
    FAdminResetUserPasswordAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminResetUserPasswordRequest adminResetUserPasswordRequest,
        FAdminResetUserPasswordResult &adminResetUserPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminResetUserPasswordResult(adminResetUserPasswordResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminResetUserPasswordCallable(adminResetUserPasswordRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminResetUserPasswordOutcome = callable.get();

            success = awsAdminResetUserPasswordOutcome.IsSuccess();
                if (success) {
                    adminResetUserPasswordResult.fromAWS(awsAdminResetUserPasswordOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminResetUserPasswordOutcome.GetError().GetErrorType());
                errorMessage = ("AdminResetUserPassword error: " + awsAdminResetUserPasswordOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminResetUserPassword Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminResetUserPassword(
        UObject *WorldContextObject,
        bool &success,
        FAdminResetUserPasswordRequest adminResetUserPasswordRequest,
        FAdminResetUserPasswordResult &adminResetUserPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminResetUserPasswordAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminResetUserPasswordAction(this->awsCognitoIdentityProviderClient,
                success,
                adminResetUserPasswordRequest,
                adminResetUserPasswordResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminRespondToAuthChallengeAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminRespondToAuthChallengeResult &adminRespondToAuthChallengeResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminRespondToAuthChallengeOutcomeCallable callable;

public:
    FAdminRespondToAuthChallengeAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminRespondToAuthChallengeRequest adminRespondToAuthChallengeRequest,
        FAdminRespondToAuthChallengeResult &adminRespondToAuthChallengeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminRespondToAuthChallengeResult(adminRespondToAuthChallengeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminRespondToAuthChallengeCallable(adminRespondToAuthChallengeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminRespondToAuthChallengeOutcome = callable.get();

            success = awsAdminRespondToAuthChallengeOutcome.IsSuccess();
                if (success) {
                    adminRespondToAuthChallengeResult.fromAWS(awsAdminRespondToAuthChallengeOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminRespondToAuthChallengeOutcome.GetError().GetErrorType());
                errorMessage = ("AdminRespondToAuthChallenge error: " + awsAdminRespondToAuthChallengeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminRespondToAuthChallenge Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminRespondToAuthChallenge(
        UObject *WorldContextObject,
        bool &success,
        FAdminRespondToAuthChallengeRequest adminRespondToAuthChallengeRequest,
        FAdminRespondToAuthChallengeResult &adminRespondToAuthChallengeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminRespondToAuthChallengeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminRespondToAuthChallengeAction(this->awsCognitoIdentityProviderClient,
                success,
                adminRespondToAuthChallengeRequest,
                adminRespondToAuthChallengeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminSetUserMFAPreferenceAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminSetUserMFAPreferenceResult &adminSetUserMFAPreferenceResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminSetUserMFAPreferenceOutcomeCallable callable;

public:
    FAdminSetUserMFAPreferenceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminSetUserMFAPreferenceRequest adminSetUserMFAPreferenceRequest,
        FAdminSetUserMFAPreferenceResult &adminSetUserMFAPreferenceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminSetUserMFAPreferenceResult(adminSetUserMFAPreferenceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminSetUserMFAPreferenceCallable(adminSetUserMFAPreferenceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminSetUserMFAPreferenceOutcome = callable.get();

            success = awsAdminSetUserMFAPreferenceOutcome.IsSuccess();
                if (success) {
                    adminSetUserMFAPreferenceResult.fromAWS(awsAdminSetUserMFAPreferenceOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminSetUserMFAPreferenceOutcome.GetError().GetErrorType());
                errorMessage = ("AdminSetUserMFAPreference error: " + awsAdminSetUserMFAPreferenceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminSetUserMFAPreference Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminSetUserMFAPreference(
        UObject *WorldContextObject,
        bool &success,
        FAdminSetUserMFAPreferenceRequest adminSetUserMFAPreferenceRequest,
        FAdminSetUserMFAPreferenceResult &adminSetUserMFAPreferenceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminSetUserMFAPreferenceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminSetUserMFAPreferenceAction(this->awsCognitoIdentityProviderClient,
                success,
                adminSetUserMFAPreferenceRequest,
                adminSetUserMFAPreferenceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminSetUserPasswordAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminSetUserPasswordResult &adminSetUserPasswordResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminSetUserPasswordOutcomeCallable callable;

public:
    FAdminSetUserPasswordAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminSetUserPasswordRequest adminSetUserPasswordRequest,
        FAdminSetUserPasswordResult &adminSetUserPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminSetUserPasswordResult(adminSetUserPasswordResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminSetUserPasswordCallable(adminSetUserPasswordRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminSetUserPasswordOutcome = callable.get();

            success = awsAdminSetUserPasswordOutcome.IsSuccess();
                if (success) {
                    adminSetUserPasswordResult.fromAWS(awsAdminSetUserPasswordOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminSetUserPasswordOutcome.GetError().GetErrorType());
                errorMessage = ("AdminSetUserPassword error: " + awsAdminSetUserPasswordOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminSetUserPassword Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminSetUserPassword(
        UObject *WorldContextObject,
        bool &success,
        FAdminSetUserPasswordRequest adminSetUserPasswordRequest,
        FAdminSetUserPasswordResult &adminSetUserPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminSetUserPasswordAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminSetUserPasswordAction(this->awsCognitoIdentityProviderClient,
                success,
                adminSetUserPasswordRequest,
                adminSetUserPasswordResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminSetUserSettingsAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminSetUserSettingsResult &adminSetUserSettingsResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminSetUserSettingsOutcomeCallable callable;

public:
    FAdminSetUserSettingsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminSetUserSettingsRequest adminSetUserSettingsRequest,
        FAdminSetUserSettingsResult &adminSetUserSettingsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminSetUserSettingsResult(adminSetUserSettingsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminSetUserSettingsCallable(adminSetUserSettingsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminSetUserSettingsOutcome = callable.get();

            success = awsAdminSetUserSettingsOutcome.IsSuccess();
                if (success) {
                    adminSetUserSettingsResult.fromAWS(awsAdminSetUserSettingsOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminSetUserSettingsOutcome.GetError().GetErrorType());
                errorMessage = ("AdminSetUserSettings error: " + awsAdminSetUserSettingsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminSetUserSettings Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminSetUserSettings(
        UObject *WorldContextObject,
        bool &success,
        FAdminSetUserSettingsRequest adminSetUserSettingsRequest,
        FAdminSetUserSettingsResult &adminSetUserSettingsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminSetUserSettingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminSetUserSettingsAction(this->awsCognitoIdentityProviderClient,
                success,
                adminSetUserSettingsRequest,
                adminSetUserSettingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminUpdateAuthEventFeedbackAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminUpdateAuthEventFeedbackResult &adminUpdateAuthEventFeedbackResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminUpdateAuthEventFeedbackOutcomeCallable callable;

public:
    FAdminUpdateAuthEventFeedbackAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminUpdateAuthEventFeedbackRequest adminUpdateAuthEventFeedbackRequest,
        FAdminUpdateAuthEventFeedbackResult &adminUpdateAuthEventFeedbackResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminUpdateAuthEventFeedbackResult(adminUpdateAuthEventFeedbackResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminUpdateAuthEventFeedbackCallable(adminUpdateAuthEventFeedbackRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminUpdateAuthEventFeedbackOutcome = callable.get();

            success = awsAdminUpdateAuthEventFeedbackOutcome.IsSuccess();
                if (success) {
                    adminUpdateAuthEventFeedbackResult.fromAWS(awsAdminUpdateAuthEventFeedbackOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminUpdateAuthEventFeedbackOutcome.GetError().GetErrorType());
                errorMessage = ("AdminUpdateAuthEventFeedback error: " + awsAdminUpdateAuthEventFeedbackOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminUpdateAuthEventFeedback Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminUpdateAuthEventFeedback(
        UObject *WorldContextObject,
        bool &success,
        FAdminUpdateAuthEventFeedbackRequest adminUpdateAuthEventFeedbackRequest,
        FAdminUpdateAuthEventFeedbackResult &adminUpdateAuthEventFeedbackResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminUpdateAuthEventFeedbackAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminUpdateAuthEventFeedbackAction(this->awsCognitoIdentityProviderClient,
                success,
                adminUpdateAuthEventFeedbackRequest,
                adminUpdateAuthEventFeedbackResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminUpdateDeviceStatusAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminUpdateDeviceStatusResult &adminUpdateDeviceStatusResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminUpdateDeviceStatusOutcomeCallable callable;

public:
    FAdminUpdateDeviceStatusAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminUpdateDeviceStatusRequest adminUpdateDeviceStatusRequest,
        FAdminUpdateDeviceStatusResult &adminUpdateDeviceStatusResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminUpdateDeviceStatusResult(adminUpdateDeviceStatusResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminUpdateDeviceStatusCallable(adminUpdateDeviceStatusRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminUpdateDeviceStatusOutcome = callable.get();

            success = awsAdminUpdateDeviceStatusOutcome.IsSuccess();
                if (success) {
                    adminUpdateDeviceStatusResult.fromAWS(awsAdminUpdateDeviceStatusOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminUpdateDeviceStatusOutcome.GetError().GetErrorType());
                errorMessage = ("AdminUpdateDeviceStatus error: " + awsAdminUpdateDeviceStatusOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminUpdateDeviceStatus Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminUpdateDeviceStatus(
        UObject *WorldContextObject,
        bool &success,
        FAdminUpdateDeviceStatusRequest adminUpdateDeviceStatusRequest,
        FAdminUpdateDeviceStatusResult &adminUpdateDeviceStatusResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminUpdateDeviceStatusAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminUpdateDeviceStatusAction(this->awsCognitoIdentityProviderClient,
                success,
                adminUpdateDeviceStatusRequest,
                adminUpdateDeviceStatusResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminUpdateUserAttributesAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminUpdateUserAttributesResult &adminUpdateUserAttributesResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminUpdateUserAttributesOutcomeCallable callable;

public:
    FAdminUpdateUserAttributesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminUpdateUserAttributesRequest adminUpdateUserAttributesRequest,
        FAdminUpdateUserAttributesResult &adminUpdateUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminUpdateUserAttributesResult(adminUpdateUserAttributesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminUpdateUserAttributesCallable(adminUpdateUserAttributesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminUpdateUserAttributesOutcome = callable.get();

            success = awsAdminUpdateUserAttributesOutcome.IsSuccess();
                if (success) {
                    adminUpdateUserAttributesResult.fromAWS(awsAdminUpdateUserAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminUpdateUserAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("AdminUpdateUserAttributes error: " + awsAdminUpdateUserAttributesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminUpdateUserAttributes Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminUpdateUserAttributes(
        UObject *WorldContextObject,
        bool &success,
        FAdminUpdateUserAttributesRequest adminUpdateUserAttributesRequest,
        FAdminUpdateUserAttributesResult &adminUpdateUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminUpdateUserAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminUpdateUserAttributesAction(this->awsCognitoIdentityProviderClient,
                success,
                adminUpdateUserAttributesRequest,
                adminUpdateUserAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAdminUserGlobalSignOutAction : public FPendingLatentAction {
private:
    bool &success;
    FAdminUserGlobalSignOutResult &adminUserGlobalSignOutResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AdminUserGlobalSignOutOutcomeCallable callable;

public:
    FAdminUserGlobalSignOutAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAdminUserGlobalSignOutRequest adminUserGlobalSignOutRequest,
        FAdminUserGlobalSignOutResult &adminUserGlobalSignOutResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), adminUserGlobalSignOutResult(adminUserGlobalSignOutResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AdminUserGlobalSignOutCallable(adminUserGlobalSignOutRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAdminUserGlobalSignOutOutcome = callable.get();

            success = awsAdminUserGlobalSignOutOutcome.IsSuccess();
                if (success) {
                    adminUserGlobalSignOutResult.fromAWS(awsAdminUserGlobalSignOutOutcome.GetResult());
                }

                errorType = fromAWS(awsAdminUserGlobalSignOutOutcome.GetError().GetErrorType());
                errorMessage = ("AdminUserGlobalSignOut error: " + awsAdminUserGlobalSignOutOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AdminUserGlobalSignOut Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AdminUserGlobalSignOut(
        UObject *WorldContextObject,
        bool &success,
        FAdminUserGlobalSignOutRequest adminUserGlobalSignOutRequest,
        FAdminUserGlobalSignOutResult &adminUserGlobalSignOutResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAdminUserGlobalSignOutAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAdminUserGlobalSignOutAction(this->awsCognitoIdentityProviderClient,
                success,
                adminUserGlobalSignOutRequest,
                adminUserGlobalSignOutResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FAssociateSoftwareTokenAction : public FPendingLatentAction {
private:
    bool &success;
    FAssociateSoftwareTokenResult &associateSoftwareTokenResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::AssociateSoftwareTokenOutcomeCallable callable;

public:
    FAssociateSoftwareTokenAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAssociateSoftwareTokenRequest associateSoftwareTokenRequest,
        FAssociateSoftwareTokenResult &associateSoftwareTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), associateSoftwareTokenResult(associateSoftwareTokenResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->AssociateSoftwareTokenCallable(associateSoftwareTokenRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsAssociateSoftwareTokenOutcome = callable.get();

            success = awsAssociateSoftwareTokenOutcome.IsSuccess();
                if (success) {
                    associateSoftwareTokenResult.fromAWS(awsAssociateSoftwareTokenOutcome.GetResult());
                }

                errorType = fromAWS(awsAssociateSoftwareTokenOutcome.GetError().GetErrorType());
                errorMessage = ("AssociateSoftwareToken error: " + awsAssociateSoftwareTokenOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("AssociateSoftwareToken Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::AssociateSoftwareToken(
        UObject *WorldContextObject,
        bool &success,
        FAssociateSoftwareTokenRequest associateSoftwareTokenRequest,
        FAssociateSoftwareTokenResult &associateSoftwareTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FAssociateSoftwareTokenAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FAssociateSoftwareTokenAction(this->awsCognitoIdentityProviderClient,
                success,
                associateSoftwareTokenRequest,
                associateSoftwareTokenResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FChangePasswordAction : public FPendingLatentAction {
private:
    bool &success;
    FChangePasswordResult &changePasswordResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ChangePasswordOutcomeCallable callable;

public:
    FChangePasswordAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FChangePasswordRequest changePasswordRequest,
        FChangePasswordResult &changePasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), changePasswordResult(changePasswordResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ChangePasswordCallable(changePasswordRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsChangePasswordOutcome = callable.get();

            success = awsChangePasswordOutcome.IsSuccess();
                if (success) {
                    changePasswordResult.fromAWS(awsChangePasswordOutcome.GetResult());
                }

                errorType = fromAWS(awsChangePasswordOutcome.GetError().GetErrorType());
                errorMessage = ("ChangePassword error: " + awsChangePasswordOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ChangePassword Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ChangePassword(
        UObject *WorldContextObject,
        bool &success,
        FChangePasswordRequest changePasswordRequest,
        FChangePasswordResult &changePasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FChangePasswordAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FChangePasswordAction(this->awsCognitoIdentityProviderClient,
                success,
                changePasswordRequest,
                changePasswordResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FConfirmDeviceAction : public FPendingLatentAction {
private:
    bool &success;
    FConfirmDeviceResult &confirmDeviceResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ConfirmDeviceOutcomeCallable callable;

public:
    FConfirmDeviceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FConfirmDeviceRequest confirmDeviceRequest,
        FConfirmDeviceResult &confirmDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), confirmDeviceResult(confirmDeviceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ConfirmDeviceCallable(confirmDeviceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsConfirmDeviceOutcome = callable.get();

            success = awsConfirmDeviceOutcome.IsSuccess();
                if (success) {
                    confirmDeviceResult.fromAWS(awsConfirmDeviceOutcome.GetResult());
                }

                errorType = fromAWS(awsConfirmDeviceOutcome.GetError().GetErrorType());
                errorMessage = ("ConfirmDevice error: " + awsConfirmDeviceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ConfirmDevice Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ConfirmDevice(
        UObject *WorldContextObject,
        bool &success,
        FConfirmDeviceRequest confirmDeviceRequest,
        FConfirmDeviceResult &confirmDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FConfirmDeviceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FConfirmDeviceAction(this->awsCognitoIdentityProviderClient,
                success,
                confirmDeviceRequest,
                confirmDeviceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FConfirmForgotPasswordAction : public FPendingLatentAction {
private:
    bool &success;
    FConfirmForgotPasswordResult &confirmForgotPasswordResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ConfirmForgotPasswordOutcomeCallable callable;

public:
    FConfirmForgotPasswordAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FConfirmForgotPasswordRequest confirmForgotPasswordRequest,
        FConfirmForgotPasswordResult &confirmForgotPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), confirmForgotPasswordResult(confirmForgotPasswordResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ConfirmForgotPasswordCallable(confirmForgotPasswordRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsConfirmForgotPasswordOutcome = callable.get();

            success = awsConfirmForgotPasswordOutcome.IsSuccess();
                if (success) {
                    confirmForgotPasswordResult.fromAWS(awsConfirmForgotPasswordOutcome.GetResult());
                }

                errorType = fromAWS(awsConfirmForgotPasswordOutcome.GetError().GetErrorType());
                errorMessage = ("ConfirmForgotPassword error: " + awsConfirmForgotPasswordOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ConfirmForgotPassword Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ConfirmForgotPassword(
        UObject *WorldContextObject,
        bool &success,
        FConfirmForgotPasswordRequest confirmForgotPasswordRequest,
        FConfirmForgotPasswordResult &confirmForgotPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FConfirmForgotPasswordAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FConfirmForgotPasswordAction(this->awsCognitoIdentityProviderClient,
                success,
                confirmForgotPasswordRequest,
                confirmForgotPasswordResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FConfirmSignUpAction : public FPendingLatentAction {
private:
    bool &success;
    FConfirmSignUpResult &confirmSignUpResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ConfirmSignUpOutcomeCallable callable;

public:
    FConfirmSignUpAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FConfirmSignUpRequest confirmSignUpRequest,
        FConfirmSignUpResult &confirmSignUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), confirmSignUpResult(confirmSignUpResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ConfirmSignUpCallable(confirmSignUpRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsConfirmSignUpOutcome = callable.get();

            success = awsConfirmSignUpOutcome.IsSuccess();
                if (success) {
                    confirmSignUpResult.fromAWS(awsConfirmSignUpOutcome.GetResult());
                }

                errorType = fromAWS(awsConfirmSignUpOutcome.GetError().GetErrorType());
                errorMessage = ("ConfirmSignUp error: " + awsConfirmSignUpOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ConfirmSignUp Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ConfirmSignUp(
        UObject *WorldContextObject,
        bool &success,
        FConfirmSignUpRequest confirmSignUpRequest,
        FConfirmSignUpResult &confirmSignUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FConfirmSignUpAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FConfirmSignUpAction(this->awsCognitoIdentityProviderClient,
                success,
                confirmSignUpRequest,
                confirmSignUpResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FCreateGroupAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateGroupResult &createGroupResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::CreateGroupOutcomeCallable callable;

public:
    FCreateGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateGroupRequest createGroupRequest,
        FCreateGroupResult &createGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createGroupResult(createGroupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->CreateGroupCallable(createGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateGroupOutcome = callable.get();

            success = awsCreateGroupOutcome.IsSuccess();
                if (success) {
                    createGroupResult.fromAWS(awsCreateGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateGroupOutcome.GetError().GetErrorType());
                errorMessage = ("CreateGroup error: " + awsCreateGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateGroup(
        UObject *WorldContextObject,
        bool &success,
        FCreateGroupRequest createGroupRequest,
        FCreateGroupResult &createGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                createGroupRequest,
                createGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FCreateIdentityProviderAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateIdentityProviderResult &createIdentityProviderResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::CreateIdentityProviderOutcomeCallable callable;

public:
    FCreateIdentityProviderAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateIdentityProviderRequest createIdentityProviderRequest,
        FCreateIdentityProviderResult &createIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createIdentityProviderResult(createIdentityProviderResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->CreateIdentityProviderCallable(createIdentityProviderRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateIdentityProviderOutcome = callable.get();

            success = awsCreateIdentityProviderOutcome.IsSuccess();
                if (success) {
                    createIdentityProviderResult.fromAWS(awsCreateIdentityProviderOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateIdentityProviderOutcome.GetError().GetErrorType());
                errorMessage = ("CreateIdentityProvider error: " + awsCreateIdentityProviderOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateIdentityProvider Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateIdentityProvider(
        UObject *WorldContextObject,
        bool &success,
        FCreateIdentityProviderRequest createIdentityProviderRequest,
        FCreateIdentityProviderResult &createIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateIdentityProviderAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateIdentityProviderAction(this->awsCognitoIdentityProviderClient,
                success,
                createIdentityProviderRequest,
                createIdentityProviderResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FCreateResourceServerAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateResourceServerResult &createResourceServerResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::CreateResourceServerOutcomeCallable callable;

public:
    FCreateResourceServerAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateResourceServerRequest createResourceServerRequest,
        FCreateResourceServerResult &createResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createResourceServerResult(createResourceServerResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->CreateResourceServerCallable(createResourceServerRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateResourceServerOutcome = callable.get();

            success = awsCreateResourceServerOutcome.IsSuccess();
                if (success) {
                    createResourceServerResult.fromAWS(awsCreateResourceServerOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateResourceServerOutcome.GetError().GetErrorType());
                errorMessage = ("CreateResourceServer error: " + awsCreateResourceServerOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateResourceServer Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateResourceServer(
        UObject *WorldContextObject,
        bool &success,
        FCreateResourceServerRequest createResourceServerRequest,
        FCreateResourceServerResult &createResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateResourceServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateResourceServerAction(this->awsCognitoIdentityProviderClient,
                success,
                createResourceServerRequest,
                createResourceServerResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FCreateUserImportJobAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateUserImportJobResult &createUserImportJobResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::CreateUserImportJobOutcomeCallable callable;

public:
    FCreateUserImportJobAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateUserImportJobRequest createUserImportJobRequest,
        FCreateUserImportJobResult &createUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createUserImportJobResult(createUserImportJobResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->CreateUserImportJobCallable(createUserImportJobRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateUserImportJobOutcome = callable.get();

            success = awsCreateUserImportJobOutcome.IsSuccess();
                if (success) {
                    createUserImportJobResult.fromAWS(awsCreateUserImportJobOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateUserImportJobOutcome.GetError().GetErrorType());
                errorMessage = ("CreateUserImportJob error: " + awsCreateUserImportJobOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateUserImportJob Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateUserImportJob(
        UObject *WorldContextObject,
        bool &success,
        FCreateUserImportJobRequest createUserImportJobRequest,
        FCreateUserImportJobResult &createUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateUserImportJobAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateUserImportJobAction(this->awsCognitoIdentityProviderClient,
                success,
                createUserImportJobRequest,
                createUserImportJobResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FCreateUserPoolAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateUserPoolResult &createUserPoolResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::CreateUserPoolOutcomeCallable callable;

public:
    FCreateUserPoolAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateUserPoolRequest createUserPoolRequest,
        FCreateUserPoolResult &createUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createUserPoolResult(createUserPoolResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->CreateUserPoolCallable(createUserPoolRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateUserPoolOutcome = callable.get();

            success = awsCreateUserPoolOutcome.IsSuccess();
                if (success) {
                    createUserPoolResult.fromAWS(awsCreateUserPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateUserPoolOutcome.GetError().GetErrorType());
                errorMessage = ("CreateUserPool error: " + awsCreateUserPoolOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateUserPool Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateUserPool(
        UObject *WorldContextObject,
        bool &success,
        FCreateUserPoolRequest createUserPoolRequest,
        FCreateUserPoolResult &createUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateUserPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateUserPoolAction(this->awsCognitoIdentityProviderClient,
                success,
                createUserPoolRequest,
                createUserPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FCreateUserPoolClientAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateUserPoolClientResult &createUserPoolClientResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::CreateUserPoolClientOutcomeCallable callable;

public:
    FCreateUserPoolClientAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateUserPoolClientRequest createUserPoolClientRequest,
        FCreateUserPoolClientResult &createUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createUserPoolClientResult(createUserPoolClientResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->CreateUserPoolClientCallable(createUserPoolClientRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateUserPoolClientOutcome = callable.get();

            success = awsCreateUserPoolClientOutcome.IsSuccess();
                if (success) {
                    createUserPoolClientResult.fromAWS(awsCreateUserPoolClientOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateUserPoolClientOutcome.GetError().GetErrorType());
                errorMessage = ("CreateUserPoolClient error: " + awsCreateUserPoolClientOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateUserPoolClient Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateUserPoolClient(
        UObject *WorldContextObject,
        bool &success,
        FCreateUserPoolClientRequest createUserPoolClientRequest,
        FCreateUserPoolClientResult &createUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateUserPoolClientAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateUserPoolClientAction(this->awsCognitoIdentityProviderClient,
                success,
                createUserPoolClientRequest,
                createUserPoolClientResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FCreateUserPoolDomainAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateUserPoolDomainResult &createUserPoolDomainResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::CreateUserPoolDomainOutcomeCallable callable;

public:
    FCreateUserPoolDomainAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCreateUserPoolDomainRequest createUserPoolDomainRequest,
        FCreateUserPoolDomainResult &createUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createUserPoolDomainResult(createUserPoolDomainResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->CreateUserPoolDomainCallable(createUserPoolDomainRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateUserPoolDomainOutcome = callable.get();

            success = awsCreateUserPoolDomainOutcome.IsSuccess();
                if (success) {
                    createUserPoolDomainResult.fromAWS(awsCreateUserPoolDomainOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateUserPoolDomainOutcome.GetError().GetErrorType());
                errorMessage = ("CreateUserPoolDomain error: " + awsCreateUserPoolDomainOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateUserPoolDomain Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::CreateUserPoolDomain(
        UObject *WorldContextObject,
        bool &success,
        FCreateUserPoolDomainRequest createUserPoolDomainRequest,
        FCreateUserPoolDomainResult &createUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateUserPoolDomainAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateUserPoolDomainAction(this->awsCognitoIdentityProviderClient,
                success,
                createUserPoolDomainRequest,
                createUserPoolDomainResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDeleteGroupAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DeleteGroupOutcomeCallable callable;

public:
    FDeleteGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteGroupRequest deleteGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DeleteGroupCallable(deleteGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteGroupOutcome = callable.get();

            success = awsDeleteGroupOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteGroupOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteGroup error: " + awsDeleteGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteGroup(
        UObject *WorldContextObject,
        bool &success,
        FDeleteGroupRequest deleteGroupRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteGroupRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDeleteIdentityProviderAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DeleteIdentityProviderOutcomeCallable callable;

public:
    FDeleteIdentityProviderAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteIdentityProviderRequest deleteIdentityProviderRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DeleteIdentityProviderCallable(deleteIdentityProviderRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteIdentityProviderOutcome = callable.get();

            success = awsDeleteIdentityProviderOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteIdentityProviderOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteIdentityProvider error: " + awsDeleteIdentityProviderOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteIdentityProvider Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteIdentityProvider(
        UObject *WorldContextObject,
        bool &success,
        FDeleteIdentityProviderRequest deleteIdentityProviderRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteIdentityProviderAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteIdentityProviderAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteIdentityProviderRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDeleteResourceServerAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DeleteResourceServerOutcomeCallable callable;

public:
    FDeleteResourceServerAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteResourceServerRequest deleteResourceServerRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DeleteResourceServerCallable(deleteResourceServerRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteResourceServerOutcome = callable.get();

            success = awsDeleteResourceServerOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteResourceServerOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteResourceServer error: " + awsDeleteResourceServerOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteResourceServer Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteResourceServer(
        UObject *WorldContextObject,
        bool &success,
        FDeleteResourceServerRequest deleteResourceServerRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteResourceServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteResourceServerAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteResourceServerRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDeleteUserAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DeleteUserOutcomeCallable callable;

public:
    FDeleteUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteUserRequest deleteUserRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DeleteUserCallable(deleteUserRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteUserOutcome = callable.get();

            success = awsDeleteUserOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteUserOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteUser error: " + awsDeleteUserOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteUser(
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserRequest deleteUserRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteUserAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteUserRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDeleteUserAttributesAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteUserAttributesResult &deleteUserAttributesResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DeleteUserAttributesOutcomeCallable callable;

public:
    FDeleteUserAttributesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteUserAttributesRequest deleteUserAttributesRequest,
        FDeleteUserAttributesResult &deleteUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteUserAttributesResult(deleteUserAttributesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DeleteUserAttributesCallable(deleteUserAttributesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteUserAttributesOutcome = callable.get();

            success = awsDeleteUserAttributesOutcome.IsSuccess();
                if (success) {
                    deleteUserAttributesResult.fromAWS(awsDeleteUserAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteUserAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteUserAttributes error: " + awsDeleteUserAttributesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteUserAttributes Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteUserAttributes(
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserAttributesRequest deleteUserAttributesRequest,
        FDeleteUserAttributesResult &deleteUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteUserAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteUserAttributesAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteUserAttributesRequest,
                deleteUserAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDeleteUserPoolAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DeleteUserPoolOutcomeCallable callable;

public:
    FDeleteUserPoolAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteUserPoolRequest deleteUserPoolRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DeleteUserPoolCallable(deleteUserPoolRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteUserPoolOutcome = callable.get();

            success = awsDeleteUserPoolOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteUserPoolOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteUserPool error: " + awsDeleteUserPoolOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteUserPool Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteUserPool(
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserPoolRequest deleteUserPoolRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteUserPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteUserPoolAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteUserPoolRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDeleteUserPoolClientAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DeleteUserPoolClientOutcomeCallable callable;

public:
    FDeleteUserPoolClientAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteUserPoolClientRequest deleteUserPoolClientRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DeleteUserPoolClientCallable(deleteUserPoolClientRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteUserPoolClientOutcome = callable.get();

            success = awsDeleteUserPoolClientOutcome.IsSuccess();

                errorType = fromAWS(awsDeleteUserPoolClientOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteUserPoolClient error: " + awsDeleteUserPoolClientOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteUserPoolClient Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteUserPoolClient(
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserPoolClientRequest deleteUserPoolClientRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteUserPoolClientAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteUserPoolClientAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteUserPoolClientRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDeleteUserPoolDomainAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteUserPoolDomainResult &deleteUserPoolDomainResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DeleteUserPoolDomainOutcomeCallable callable;

public:
    FDeleteUserPoolDomainAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDeleteUserPoolDomainRequest deleteUserPoolDomainRequest,
        FDeleteUserPoolDomainResult &deleteUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteUserPoolDomainResult(deleteUserPoolDomainResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DeleteUserPoolDomainCallable(deleteUserPoolDomainRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteUserPoolDomainOutcome = callable.get();

            success = awsDeleteUserPoolDomainOutcome.IsSuccess();
                if (success) {
                    deleteUserPoolDomainResult.fromAWS(awsDeleteUserPoolDomainOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteUserPoolDomainOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteUserPoolDomain error: " + awsDeleteUserPoolDomainOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteUserPoolDomain Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DeleteUserPoolDomain(
        UObject *WorldContextObject,
        bool &success,
        FDeleteUserPoolDomainRequest deleteUserPoolDomainRequest,
        FDeleteUserPoolDomainResult &deleteUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteUserPoolDomainAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteUserPoolDomainAction(this->awsCognitoIdentityProviderClient,
                success,
                deleteUserPoolDomainRequest,
                deleteUserPoolDomainResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDescribeIdentityProviderAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeIdentityProviderResult &describeIdentityProviderResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DescribeIdentityProviderOutcomeCallable callable;

public:
    FDescribeIdentityProviderAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeIdentityProviderRequest describeIdentityProviderRequest,
        FDescribeIdentityProviderResult &describeIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeIdentityProviderResult(describeIdentityProviderResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DescribeIdentityProviderCallable(describeIdentityProviderRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeIdentityProviderOutcome = callable.get();

            success = awsDescribeIdentityProviderOutcome.IsSuccess();
                if (success) {
                    describeIdentityProviderResult.fromAWS(awsDescribeIdentityProviderOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeIdentityProviderOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeIdentityProvider error: " + awsDescribeIdentityProviderOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeIdentityProvider Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeIdentityProvider(
        UObject *WorldContextObject,
        bool &success,
        FDescribeIdentityProviderRequest describeIdentityProviderRequest,
        FDescribeIdentityProviderResult &describeIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeIdentityProviderAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeIdentityProviderAction(this->awsCognitoIdentityProviderClient,
                success,
                describeIdentityProviderRequest,
                describeIdentityProviderResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDescribeResourceServerAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeResourceServerResult &describeResourceServerResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DescribeResourceServerOutcomeCallable callable;

public:
    FDescribeResourceServerAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeResourceServerRequest describeResourceServerRequest,
        FDescribeResourceServerResult &describeResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeResourceServerResult(describeResourceServerResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DescribeResourceServerCallable(describeResourceServerRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeResourceServerOutcome = callable.get();

            success = awsDescribeResourceServerOutcome.IsSuccess();
                if (success) {
                    describeResourceServerResult.fromAWS(awsDescribeResourceServerOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeResourceServerOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeResourceServer error: " + awsDescribeResourceServerOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeResourceServer Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeResourceServer(
        UObject *WorldContextObject,
        bool &success,
        FDescribeResourceServerRequest describeResourceServerRequest,
        FDescribeResourceServerResult &describeResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeResourceServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeResourceServerAction(this->awsCognitoIdentityProviderClient,
                success,
                describeResourceServerRequest,
                describeResourceServerResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDescribeRiskConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeRiskConfigurationResult &describeRiskConfigurationResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DescribeRiskConfigurationOutcomeCallable callable;

public:
    FDescribeRiskConfigurationAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeRiskConfigurationRequest describeRiskConfigurationRequest,
        FDescribeRiskConfigurationResult &describeRiskConfigurationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeRiskConfigurationResult(describeRiskConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DescribeRiskConfigurationCallable(describeRiskConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeRiskConfigurationOutcome = callable.get();

            success = awsDescribeRiskConfigurationOutcome.IsSuccess();
                if (success) {
                    describeRiskConfigurationResult.fromAWS(awsDescribeRiskConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeRiskConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeRiskConfiguration error: " + awsDescribeRiskConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeRiskConfiguration Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeRiskConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FDescribeRiskConfigurationRequest describeRiskConfigurationRequest,
        FDescribeRiskConfigurationResult &describeRiskConfigurationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeRiskConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeRiskConfigurationAction(this->awsCognitoIdentityProviderClient,
                success,
                describeRiskConfigurationRequest,
                describeRiskConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDescribeUserImportJobAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeUserImportJobResult &describeUserImportJobResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DescribeUserImportJobOutcomeCallable callable;

public:
    FDescribeUserImportJobAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeUserImportJobRequest describeUserImportJobRequest,
        FDescribeUserImportJobResult &describeUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeUserImportJobResult(describeUserImportJobResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DescribeUserImportJobCallable(describeUserImportJobRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeUserImportJobOutcome = callable.get();

            success = awsDescribeUserImportJobOutcome.IsSuccess();
                if (success) {
                    describeUserImportJobResult.fromAWS(awsDescribeUserImportJobOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeUserImportJobOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeUserImportJob error: " + awsDescribeUserImportJobOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeUserImportJob Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeUserImportJob(
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserImportJobRequest describeUserImportJobRequest,
        FDescribeUserImportJobResult &describeUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeUserImportJobAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeUserImportJobAction(this->awsCognitoIdentityProviderClient,
                success,
                describeUserImportJobRequest,
                describeUserImportJobResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDescribeUserPoolAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeUserPoolResult &describeUserPoolResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DescribeUserPoolOutcomeCallable callable;

public:
    FDescribeUserPoolAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeUserPoolRequest describeUserPoolRequest,
        FDescribeUserPoolResult &describeUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeUserPoolResult(describeUserPoolResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DescribeUserPoolCallable(describeUserPoolRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeUserPoolOutcome = callable.get();

            success = awsDescribeUserPoolOutcome.IsSuccess();
                if (success) {
                    describeUserPoolResult.fromAWS(awsDescribeUserPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeUserPoolOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeUserPool error: " + awsDescribeUserPoolOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeUserPool Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeUserPool(
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserPoolRequest describeUserPoolRequest,
        FDescribeUserPoolResult &describeUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeUserPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeUserPoolAction(this->awsCognitoIdentityProviderClient,
                success,
                describeUserPoolRequest,
                describeUserPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDescribeUserPoolClientAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeUserPoolClientResult &describeUserPoolClientResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DescribeUserPoolClientOutcomeCallable callable;

public:
    FDescribeUserPoolClientAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeUserPoolClientRequest describeUserPoolClientRequest,
        FDescribeUserPoolClientResult &describeUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeUserPoolClientResult(describeUserPoolClientResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DescribeUserPoolClientCallable(describeUserPoolClientRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeUserPoolClientOutcome = callable.get();

            success = awsDescribeUserPoolClientOutcome.IsSuccess();
                if (success) {
                    describeUserPoolClientResult.fromAWS(awsDescribeUserPoolClientOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeUserPoolClientOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeUserPoolClient error: " + awsDescribeUserPoolClientOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeUserPoolClient Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeUserPoolClient(
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserPoolClientRequest describeUserPoolClientRequest,
        FDescribeUserPoolClientResult &describeUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeUserPoolClientAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeUserPoolClientAction(this->awsCognitoIdentityProviderClient,
                success,
                describeUserPoolClientRequest,
                describeUserPoolClientResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FDescribeUserPoolDomainAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeUserPoolDomainResult &describeUserPoolDomainResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::DescribeUserPoolDomainOutcomeCallable callable;

public:
    FDescribeUserPoolDomainAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FDescribeUserPoolDomainRequest describeUserPoolDomainRequest,
        FDescribeUserPoolDomainResult &describeUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeUserPoolDomainResult(describeUserPoolDomainResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->DescribeUserPoolDomainCallable(describeUserPoolDomainRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeUserPoolDomainOutcome = callable.get();

            success = awsDescribeUserPoolDomainOutcome.IsSuccess();
                if (success) {
                    describeUserPoolDomainResult.fromAWS(awsDescribeUserPoolDomainOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeUserPoolDomainOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeUserPoolDomain error: " + awsDescribeUserPoolDomainOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeUserPoolDomain Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::DescribeUserPoolDomain(
        UObject *WorldContextObject,
        bool &success,
        FDescribeUserPoolDomainRequest describeUserPoolDomainRequest,
        FDescribeUserPoolDomainResult &describeUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeUserPoolDomainAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeUserPoolDomainAction(this->awsCognitoIdentityProviderClient,
                success,
                describeUserPoolDomainRequest,
                describeUserPoolDomainResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FForgetDeviceAction : public FPendingLatentAction {
private:
    bool &success;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ForgetDeviceOutcomeCallable callable;

public:
    FForgetDeviceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FForgetDeviceRequest forgetDeviceRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ForgetDeviceCallable(forgetDeviceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsForgetDeviceOutcome = callable.get();

            success = awsForgetDeviceOutcome.IsSuccess();

                errorType = fromAWS(awsForgetDeviceOutcome.GetError().GetErrorType());
                errorMessage = ("ForgetDevice error: " + awsForgetDeviceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ForgetDevice Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ForgetDevice(
        UObject *WorldContextObject,
        bool &success,
        FForgetDeviceRequest forgetDeviceRequest,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FForgetDeviceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FForgetDeviceAction(this->awsCognitoIdentityProviderClient,
                success,
                forgetDeviceRequest,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FForgotPasswordAction : public FPendingLatentAction {
private:
    bool &success;
    FForgotPasswordResult &forgotPasswordResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ForgotPasswordOutcomeCallable callable;

public:
    FForgotPasswordAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FForgotPasswordRequest forgotPasswordRequest,
        FForgotPasswordResult &forgotPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), forgotPasswordResult(forgotPasswordResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ForgotPasswordCallable(forgotPasswordRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsForgotPasswordOutcome = callable.get();

            success = awsForgotPasswordOutcome.IsSuccess();
                if (success) {
                    forgotPasswordResult.fromAWS(awsForgotPasswordOutcome.GetResult());
                }

                errorType = fromAWS(awsForgotPasswordOutcome.GetError().GetErrorType());
                errorMessage = ("ForgotPassword error: " + awsForgotPasswordOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ForgotPassword Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ForgotPassword(
        UObject *WorldContextObject,
        bool &success,
        FForgotPasswordRequest forgotPasswordRequest,
        FForgotPasswordResult &forgotPasswordResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FForgotPasswordAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FForgotPasswordAction(this->awsCognitoIdentityProviderClient,
                success,
                forgotPasswordRequest,
                forgotPasswordResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FGetCSVHeaderAction : public FPendingLatentAction {
private:
    bool &success;
    FGetCSVHeaderResult &getCSVHeaderResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::GetCSVHeaderOutcomeCallable callable;

public:
    FGetCSVHeaderAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetCSVHeaderRequest getCSVHeaderRequest,
        FGetCSVHeaderResult &getCSVHeaderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getCSVHeaderResult(getCSVHeaderResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->GetCSVHeaderCallable(getCSVHeaderRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetCSVHeaderOutcome = callable.get();

            success = awsGetCSVHeaderOutcome.IsSuccess();
                if (success) {
                    getCSVHeaderResult.fromAWS(awsGetCSVHeaderOutcome.GetResult());
                }

                errorType = fromAWS(awsGetCSVHeaderOutcome.GetError().GetErrorType());
                errorMessage = ("GetCSVHeader error: " + awsGetCSVHeaderOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetCSVHeader Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetCSVHeader(
        UObject *WorldContextObject,
        bool &success,
        FGetCSVHeaderRequest getCSVHeaderRequest,
        FGetCSVHeaderResult &getCSVHeaderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetCSVHeaderAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetCSVHeaderAction(this->awsCognitoIdentityProviderClient,
                success,
                getCSVHeaderRequest,
                getCSVHeaderResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FGetDeviceAction : public FPendingLatentAction {
private:
    bool &success;
    FGetDeviceResult &getDeviceResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::GetDeviceOutcomeCallable callable;

public:
    FGetDeviceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetDeviceRequest getDeviceRequest,
        FGetDeviceResult &getDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getDeviceResult(getDeviceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->GetDeviceCallable(getDeviceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetDeviceOutcome = callable.get();

            success = awsGetDeviceOutcome.IsSuccess();
                if (success) {
                    getDeviceResult.fromAWS(awsGetDeviceOutcome.GetResult());
                }

                errorType = fromAWS(awsGetDeviceOutcome.GetError().GetErrorType());
                errorMessage = ("GetDevice error: " + awsGetDeviceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetDevice Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetDevice(
        UObject *WorldContextObject,
        bool &success,
        FGetDeviceRequest getDeviceRequest,
        FGetDeviceResult &getDeviceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetDeviceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetDeviceAction(this->awsCognitoIdentityProviderClient,
                success,
                getDeviceRequest,
                getDeviceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FGetGroupAction : public FPendingLatentAction {
private:
    bool &success;
    FGetGroupResult &getGroupResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::GetGroupOutcomeCallable callable;

public:
    FGetGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetGroupRequest getGroupRequest,
        FGetGroupResult &getGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getGroupResult(getGroupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->GetGroupCallable(getGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetGroupOutcome = callable.get();

            success = awsGetGroupOutcome.IsSuccess();
                if (success) {
                    getGroupResult.fromAWS(awsGetGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsGetGroupOutcome.GetError().GetErrorType());
                errorMessage = ("GetGroup error: " + awsGetGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetGroup(
        UObject *WorldContextObject,
        bool &success,
        FGetGroupRequest getGroupRequest,
        FGetGroupResult &getGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                getGroupRequest,
                getGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FGetIdentityProviderByIdentifierAction : public FPendingLatentAction {
private:
    bool &success;
    FGetIdentityProviderByIdentifierResult &getIdentityProviderByIdentifierResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::GetIdentityProviderByIdentifierOutcomeCallable callable;

public:
    FGetIdentityProviderByIdentifierAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetIdentityProviderByIdentifierRequest getIdentityProviderByIdentifierRequest,
        FGetIdentityProviderByIdentifierResult &getIdentityProviderByIdentifierResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getIdentityProviderByIdentifierResult(getIdentityProviderByIdentifierResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->GetIdentityProviderByIdentifierCallable(getIdentityProviderByIdentifierRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetIdentityProviderByIdentifierOutcome = callable.get();

            success = awsGetIdentityProviderByIdentifierOutcome.IsSuccess();
                if (success) {
                    getIdentityProviderByIdentifierResult.fromAWS(awsGetIdentityProviderByIdentifierOutcome.GetResult());
                }

                errorType = fromAWS(awsGetIdentityProviderByIdentifierOutcome.GetError().GetErrorType());
                errorMessage = ("GetIdentityProviderByIdentifier error: " + awsGetIdentityProviderByIdentifierOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetIdentityProviderByIdentifier Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetIdentityProviderByIdentifier(
        UObject *WorldContextObject,
        bool &success,
        FGetIdentityProviderByIdentifierRequest getIdentityProviderByIdentifierRequest,
        FGetIdentityProviderByIdentifierResult &getIdentityProviderByIdentifierResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetIdentityProviderByIdentifierAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetIdentityProviderByIdentifierAction(this->awsCognitoIdentityProviderClient,
                success,
                getIdentityProviderByIdentifierRequest,
                getIdentityProviderByIdentifierResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FGetSigningCertificateAction : public FPendingLatentAction {
private:
    bool &success;
    FGetSigningCertificateResult &getSigningCertificateResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::GetSigningCertificateOutcomeCallable callable;

public:
    FGetSigningCertificateAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetSigningCertificateRequest getSigningCertificateRequest,
        FGetSigningCertificateResult &getSigningCertificateResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getSigningCertificateResult(getSigningCertificateResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->GetSigningCertificateCallable(getSigningCertificateRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetSigningCertificateOutcome = callable.get();

            success = awsGetSigningCertificateOutcome.IsSuccess();
                if (success) {
                    getSigningCertificateResult.fromAWS(awsGetSigningCertificateOutcome.GetResult());
                }

                errorType = fromAWS(awsGetSigningCertificateOutcome.GetError().GetErrorType());
                errorMessage = ("GetSigningCertificate error: " + awsGetSigningCertificateOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetSigningCertificate Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetSigningCertificate(
        UObject *WorldContextObject,
        bool &success,
        FGetSigningCertificateRequest getSigningCertificateRequest,
        FGetSigningCertificateResult &getSigningCertificateResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetSigningCertificateAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetSigningCertificateAction(this->awsCognitoIdentityProviderClient,
                success,
                getSigningCertificateRequest,
                getSigningCertificateResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FGetUICustomizationAction : public FPendingLatentAction {
private:
    bool &success;
    FGetUICustomizationResult &getUICustomizationResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::GetUICustomizationOutcomeCallable callable;

public:
    FGetUICustomizationAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetUICustomizationRequest getUICustomizationRequest,
        FGetUICustomizationResult &getUICustomizationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getUICustomizationResult(getUICustomizationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->GetUICustomizationCallable(getUICustomizationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetUICustomizationOutcome = callable.get();

            success = awsGetUICustomizationOutcome.IsSuccess();
                if (success) {
                    getUICustomizationResult.fromAWS(awsGetUICustomizationOutcome.GetResult());
                }

                errorType = fromAWS(awsGetUICustomizationOutcome.GetError().GetErrorType());
                errorMessage = ("GetUICustomization error: " + awsGetUICustomizationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetUICustomization Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetUICustomization(
        UObject *WorldContextObject,
        bool &success,
        FGetUICustomizationRequest getUICustomizationRequest,
        FGetUICustomizationResult &getUICustomizationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetUICustomizationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetUICustomizationAction(this->awsCognitoIdentityProviderClient,
                success,
                getUICustomizationRequest,
                getUICustomizationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FGetUserAction : public FPendingLatentAction {
private:
    bool &success;
    FGetUserResult &getUserResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::GetUserOutcomeCallable callable;

public:
    FGetUserAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetUserRequest getUserRequest,
        FGetUserResult &getUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getUserResult(getUserResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->GetUserCallable(getUserRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetUserOutcome = callable.get();

            success = awsGetUserOutcome.IsSuccess();
                if (success) {
                    getUserResult.fromAWS(awsGetUserOutcome.GetResult());
                }

                errorType = fromAWS(awsGetUserOutcome.GetError().GetErrorType());
                errorMessage = ("GetUser error: " + awsGetUserOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetUser Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetUser(
        UObject *WorldContextObject,
        bool &success,
        FGetUserRequest getUserRequest,
        FGetUserResult &getUserResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetUserAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetUserAction(this->awsCognitoIdentityProviderClient,
                success,
                getUserRequest,
                getUserResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FGetUserAttributeVerificationCodeAction : public FPendingLatentAction {
private:
    bool &success;
    FGetUserAttributeVerificationCodeResult &getUserAttributeVerificationCodeResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::GetUserAttributeVerificationCodeOutcomeCallable callable;

public:
    FGetUserAttributeVerificationCodeAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetUserAttributeVerificationCodeRequest getUserAttributeVerificationCodeRequest,
        FGetUserAttributeVerificationCodeResult &getUserAttributeVerificationCodeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getUserAttributeVerificationCodeResult(getUserAttributeVerificationCodeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->GetUserAttributeVerificationCodeCallable(getUserAttributeVerificationCodeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetUserAttributeVerificationCodeOutcome = callable.get();

            success = awsGetUserAttributeVerificationCodeOutcome.IsSuccess();
                if (success) {
                    getUserAttributeVerificationCodeResult.fromAWS(awsGetUserAttributeVerificationCodeOutcome.GetResult());
                }

                errorType = fromAWS(awsGetUserAttributeVerificationCodeOutcome.GetError().GetErrorType());
                errorMessage = ("GetUserAttributeVerificationCode error: " + awsGetUserAttributeVerificationCodeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetUserAttributeVerificationCode Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetUserAttributeVerificationCode(
        UObject *WorldContextObject,
        bool &success,
        FGetUserAttributeVerificationCodeRequest getUserAttributeVerificationCodeRequest,
        FGetUserAttributeVerificationCodeResult &getUserAttributeVerificationCodeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetUserAttributeVerificationCodeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetUserAttributeVerificationCodeAction(this->awsCognitoIdentityProviderClient,
                success,
                getUserAttributeVerificationCodeRequest,
                getUserAttributeVerificationCodeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FGetUserPoolMfaConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FGetUserPoolMfaConfigResult &getUserPoolMfaConfigResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::GetUserPoolMfaConfigOutcomeCallable callable;

public:
    FGetUserPoolMfaConfigAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGetUserPoolMfaConfigRequest getUserPoolMfaConfigRequest,
        FGetUserPoolMfaConfigResult &getUserPoolMfaConfigResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getUserPoolMfaConfigResult(getUserPoolMfaConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->GetUserPoolMfaConfigCallable(getUserPoolMfaConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetUserPoolMfaConfigOutcome = callable.get();

            success = awsGetUserPoolMfaConfigOutcome.IsSuccess();
                if (success) {
                    getUserPoolMfaConfigResult.fromAWS(awsGetUserPoolMfaConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsGetUserPoolMfaConfigOutcome.GetError().GetErrorType());
                errorMessage = ("GetUserPoolMfaConfig error: " + awsGetUserPoolMfaConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetUserPoolMfaConfig Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GetUserPoolMfaConfig(
        UObject *WorldContextObject,
        bool &success,
        FGetUserPoolMfaConfigRequest getUserPoolMfaConfigRequest,
        FGetUserPoolMfaConfigResult &getUserPoolMfaConfigResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetUserPoolMfaConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetUserPoolMfaConfigAction(this->awsCognitoIdentityProviderClient,
                success,
                getUserPoolMfaConfigRequest,
                getUserPoolMfaConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FGlobalSignOutAction : public FPendingLatentAction {
private:
    bool &success;
    FGlobalSignOutResult &globalSignOutResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::GlobalSignOutOutcomeCallable callable;

public:
    FGlobalSignOutAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FGlobalSignOutRequest globalSignOutRequest,
        FGlobalSignOutResult &globalSignOutResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), globalSignOutResult(globalSignOutResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->GlobalSignOutCallable(globalSignOutRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGlobalSignOutOutcome = callable.get();

            success = awsGlobalSignOutOutcome.IsSuccess();
                if (success) {
                    globalSignOutResult.fromAWS(awsGlobalSignOutOutcome.GetResult());
                }

                errorType = fromAWS(awsGlobalSignOutOutcome.GetError().GetErrorType());
                errorMessage = ("GlobalSignOut error: " + awsGlobalSignOutOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GlobalSignOut Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::GlobalSignOut(
        UObject *WorldContextObject,
        bool &success,
        FGlobalSignOutRequest globalSignOutRequest,
        FGlobalSignOutResult &globalSignOutResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGlobalSignOutAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGlobalSignOutAction(this->awsCognitoIdentityProviderClient,
                success,
                globalSignOutRequest,
                globalSignOutResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FInitiateAuthAction : public FPendingLatentAction {
private:
    bool &success;
    FInitiateAuthResult &initiateAuthResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::InitiateAuthOutcomeCallable callable;

public:
    FInitiateAuthAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FInitiateAuthRequest initiateAuthRequest,
        FInitiateAuthResult &initiateAuthResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), initiateAuthResult(initiateAuthResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->InitiateAuthCallable(initiateAuthRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsInitiateAuthOutcome = callable.get();

            success = awsInitiateAuthOutcome.IsSuccess();
            if (success) {
                initiateAuthResult.fromAWS(awsInitiateAuthOutcome.GetResult());
            }

            errorType = fromAWS(awsInitiateAuthOutcome.GetError().GetErrorType());
            errorMessage = ("InitiateAuth error: " + awsInitiateAuthOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("InitiateAuth Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::InitiateAuth(
        UObject *WorldContextObject,
        bool &success,
        FInitiateAuthRequest initiateAuthRequest,
        FInitiateAuthResult &initiateAuthResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FInitiateAuthAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FInitiateAuthAction(this->awsCognitoIdentityProviderClient,
                success,
                initiateAuthRequest,
                initiateAuthResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FListDevicesAction : public FPendingLatentAction {
private:
    bool &success;
    FListDevicesResult &listDevicesResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ListDevicesOutcomeCallable callable;

public:
    FListDevicesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListDevicesRequest listDevicesRequest,
        FListDevicesResult &listDevicesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listDevicesResult(listDevicesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ListDevicesCallable(listDevicesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListDevicesOutcome = callable.get();

            success = awsListDevicesOutcome.IsSuccess();
                if (success) {
                    listDevicesResult.fromAWS(awsListDevicesOutcome.GetResult());
                }

                errorType = fromAWS(awsListDevicesOutcome.GetError().GetErrorType());
                errorMessage = ("ListDevices error: " + awsListDevicesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListDevices Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListDevices(
        UObject *WorldContextObject,
        bool &success,
        FListDevicesRequest listDevicesRequest,
        FListDevicesResult &listDevicesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListDevicesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListDevicesAction(this->awsCognitoIdentityProviderClient,
                success,
                listDevicesRequest,
                listDevicesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FListGroupsAction : public FPendingLatentAction {
private:
    bool &success;
    FListGroupsResult &listGroupsResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ListGroupsOutcomeCallable callable;

public:
    FListGroupsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListGroupsRequest listGroupsRequest,
        FListGroupsResult &listGroupsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listGroupsResult(listGroupsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ListGroupsCallable(listGroupsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListGroupsOutcome = callable.get();

            success = awsListGroupsOutcome.IsSuccess();
                if (success) {
                    listGroupsResult.fromAWS(awsListGroupsOutcome.GetResult());
                }

                errorType = fromAWS(awsListGroupsOutcome.GetError().GetErrorType());
                errorMessage = ("ListGroups error: " + awsListGroupsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListGroups Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListGroups(
        UObject *WorldContextObject,
        bool &success,
        FListGroupsRequest listGroupsRequest,
        FListGroupsResult &listGroupsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListGroupsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListGroupsAction(this->awsCognitoIdentityProviderClient,
                success,
                listGroupsRequest,
                listGroupsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FListIdentityProvidersAction : public FPendingLatentAction {
private:
    bool &success;
    FListIdentityProvidersResult &listIdentityProvidersResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ListIdentityProvidersOutcomeCallable callable;

public:
    FListIdentityProvidersAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListIdentityProvidersRequest listIdentityProvidersRequest,
        FListIdentityProvidersResult &listIdentityProvidersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listIdentityProvidersResult(listIdentityProvidersResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ListIdentityProvidersCallable(listIdentityProvidersRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListIdentityProvidersOutcome = callable.get();

            success = awsListIdentityProvidersOutcome.IsSuccess();
                if (success) {
                    listIdentityProvidersResult.fromAWS(awsListIdentityProvidersOutcome.GetResult());
                }

                errorType = fromAWS(awsListIdentityProvidersOutcome.GetError().GetErrorType());
                errorMessage = ("ListIdentityProviders error: " + awsListIdentityProvidersOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListIdentityProviders Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListIdentityProviders(
        UObject *WorldContextObject,
        bool &success,
        FListIdentityProvidersRequest listIdentityProvidersRequest,
        FListIdentityProvidersResult &listIdentityProvidersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListIdentityProvidersAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListIdentityProvidersAction(this->awsCognitoIdentityProviderClient,
                success,
                listIdentityProvidersRequest,
                listIdentityProvidersResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FListResourceServersAction : public FPendingLatentAction {
private:
    bool &success;
    FListResourceServersResult &listResourceServersResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ListResourceServersOutcomeCallable callable;

public:
    FListResourceServersAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListResourceServersRequest listResourceServersRequest,
        FListResourceServersResult &listResourceServersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listResourceServersResult(listResourceServersResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ListResourceServersCallable(listResourceServersRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListResourceServersOutcome = callable.get();

            success = awsListResourceServersOutcome.IsSuccess();
                if (success) {
                    listResourceServersResult.fromAWS(awsListResourceServersOutcome.GetResult());
                }

                errorType = fromAWS(awsListResourceServersOutcome.GetError().GetErrorType());
                errorMessage = ("ListResourceServers error: " + awsListResourceServersOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListResourceServers Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListResourceServers(
        UObject *WorldContextObject,
        bool &success,
        FListResourceServersRequest listResourceServersRequest,
        FListResourceServersResult &listResourceServersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListResourceServersAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListResourceServersAction(this->awsCognitoIdentityProviderClient,
                success,
                listResourceServersRequest,
                listResourceServersResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FListTagsForResourceAction : public FPendingLatentAction {
private:
    bool &success;
    FCognitoIdpListTagsForResourceResult &listTagsForResourceResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ListTagsForResourceOutcomeCallable callable;

public:
    FListTagsForResourceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCognitoIdpListTagsForResourceRequest listTagsForResourceRequest,
        FCognitoIdpListTagsForResourceResult &listTagsForResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listTagsForResourceResult(listTagsForResourceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ListTagsForResourceCallable(listTagsForResourceRequest.toAWS());
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
UCognitoIdpClientObject::ListTagsForResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdpListTagsForResourceRequest listTagsForResourceRequest,
        FCognitoIdpListTagsForResourceResult &listTagsForResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListTagsForResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListTagsForResourceAction(this->awsCognitoIdentityProviderClient,
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
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FListUserImportJobsAction : public FPendingLatentAction {
private:
    bool &success;
    FListUserImportJobsResult &listUserImportJobsResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ListUserImportJobsOutcomeCallable callable;

public:
    FListUserImportJobsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListUserImportJobsRequest listUserImportJobsRequest,
        FListUserImportJobsResult &listUserImportJobsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listUserImportJobsResult(listUserImportJobsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ListUserImportJobsCallable(listUserImportJobsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListUserImportJobsOutcome = callable.get();

            success = awsListUserImportJobsOutcome.IsSuccess();
                if (success) {
                    listUserImportJobsResult.fromAWS(awsListUserImportJobsOutcome.GetResult());
                }

                errorType = fromAWS(awsListUserImportJobsOutcome.GetError().GetErrorType());
                errorMessage = ("ListUserImportJobs error: " + awsListUserImportJobsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListUserImportJobs Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListUserImportJobs(
        UObject *WorldContextObject,
        bool &success,
        FListUserImportJobsRequest listUserImportJobsRequest,
        FListUserImportJobsResult &listUserImportJobsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListUserImportJobsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListUserImportJobsAction(this->awsCognitoIdentityProviderClient,
                success,
                listUserImportJobsRequest,
                listUserImportJobsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FListUserPoolClientsAction : public FPendingLatentAction {
private:
    bool &success;
    FListUserPoolClientsResult &listUserPoolClientsResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ListUserPoolClientsOutcomeCallable callable;

public:
    FListUserPoolClientsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListUserPoolClientsRequest listUserPoolClientsRequest,
        FListUserPoolClientsResult &listUserPoolClientsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listUserPoolClientsResult(listUserPoolClientsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ListUserPoolClientsCallable(listUserPoolClientsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListUserPoolClientsOutcome = callable.get();

            success = awsListUserPoolClientsOutcome.IsSuccess();
                if (success) {
                    listUserPoolClientsResult.fromAWS(awsListUserPoolClientsOutcome.GetResult());
                }

                errorType = fromAWS(awsListUserPoolClientsOutcome.GetError().GetErrorType());
                errorMessage = ("ListUserPoolClients error: " + awsListUserPoolClientsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListUserPoolClients Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListUserPoolClients(
        UObject *WorldContextObject,
        bool &success,
        FListUserPoolClientsRequest listUserPoolClientsRequest,
        FListUserPoolClientsResult &listUserPoolClientsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListUserPoolClientsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListUserPoolClientsAction(this->awsCognitoIdentityProviderClient,
                success,
                listUserPoolClientsRequest,
                listUserPoolClientsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FListUserPoolsAction : public FPendingLatentAction {
private:
    bool &success;
    FListUserPoolsResult &listUserPoolsResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ListUserPoolsOutcomeCallable callable;

public:
    FListUserPoolsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListUserPoolsRequest listUserPoolsRequest,
        FListUserPoolsResult &listUserPoolsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listUserPoolsResult(listUserPoolsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ListUserPoolsCallable(listUserPoolsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListUserPoolsOutcome = callable.get();

            success = awsListUserPoolsOutcome.IsSuccess();
                if (success) {
                    listUserPoolsResult.fromAWS(awsListUserPoolsOutcome.GetResult());
                }

                errorType = fromAWS(awsListUserPoolsOutcome.GetError().GetErrorType());
                errorMessage = ("ListUserPools error: " + awsListUserPoolsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListUserPools Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListUserPools(
        UObject *WorldContextObject,
        bool &success,
        FListUserPoolsRequest listUserPoolsRequest,
        FListUserPoolsResult &listUserPoolsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListUserPoolsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListUserPoolsAction(this->awsCognitoIdentityProviderClient,
                success,
                listUserPoolsRequest,
                listUserPoolsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FListUsersAction : public FPendingLatentAction {
private:
    bool &success;
    FListUsersResult &listUsersResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ListUsersOutcomeCallable callable;

public:
    FListUsersAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListUsersRequest listUsersRequest,
        FListUsersResult &listUsersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listUsersResult(listUsersResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ListUsersCallable(listUsersRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListUsersOutcome = callable.get();

            success = awsListUsersOutcome.IsSuccess();
                if (success) {
                    listUsersResult.fromAWS(awsListUsersOutcome.GetResult());
                }

                errorType = fromAWS(awsListUsersOutcome.GetError().GetErrorType());
                errorMessage = ("ListUsers error: " + awsListUsersOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListUsers Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListUsers(
        UObject *WorldContextObject,
        bool &success,
        FListUsersRequest listUsersRequest,
        FListUsersResult &listUsersResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListUsersAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListUsersAction(this->awsCognitoIdentityProviderClient,
                success,
                listUsersRequest,
                listUsersResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FListUsersInGroupAction : public FPendingLatentAction {
private:
    bool &success;
    FListUsersInGroupResult &listUsersInGroupResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ListUsersInGroupOutcomeCallable callable;

public:
    FListUsersInGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FListUsersInGroupRequest listUsersInGroupRequest,
        FListUsersInGroupResult &listUsersInGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listUsersInGroupResult(listUsersInGroupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ListUsersInGroupCallable(listUsersInGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListUsersInGroupOutcome = callable.get();

            success = awsListUsersInGroupOutcome.IsSuccess();
                if (success) {
                    listUsersInGroupResult.fromAWS(awsListUsersInGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsListUsersInGroupOutcome.GetError().GetErrorType());
                errorMessage = ("ListUsersInGroup error: " + awsListUsersInGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListUsersInGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ListUsersInGroup(
        UObject *WorldContextObject,
        bool &success,
        FListUsersInGroupRequest listUsersInGroupRequest,
        FListUsersInGroupResult &listUsersInGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListUsersInGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListUsersInGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                listUsersInGroupRequest,
                listUsersInGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FResendConfirmationCodeAction : public FPendingLatentAction {
private:
    bool &success;
    FResendConfirmationCodeResult &resendConfirmationCodeResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::ResendConfirmationCodeOutcomeCallable callable;

public:
    FResendConfirmationCodeAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FResendConfirmationCodeRequest resendConfirmationCodeRequest,
        FResendConfirmationCodeResult &resendConfirmationCodeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), resendConfirmationCodeResult(resendConfirmationCodeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->ResendConfirmationCodeCallable(resendConfirmationCodeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsResendConfirmationCodeOutcome = callable.get();

            success = awsResendConfirmationCodeOutcome.IsSuccess();
                if (success) {
                    resendConfirmationCodeResult.fromAWS(awsResendConfirmationCodeOutcome.GetResult());
                }

                errorType = fromAWS(awsResendConfirmationCodeOutcome.GetError().GetErrorType());
                errorMessage = ("ResendConfirmationCode error: " + awsResendConfirmationCodeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ResendConfirmationCode Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::ResendConfirmationCode(
        UObject *WorldContextObject,
        bool &success,
        FResendConfirmationCodeRequest resendConfirmationCodeRequest,
        FResendConfirmationCodeResult &resendConfirmationCodeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FResendConfirmationCodeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FResendConfirmationCodeAction(this->awsCognitoIdentityProviderClient,
                success,
                resendConfirmationCodeRequest,
                resendConfirmationCodeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FRespondToAuthChallengeAction : public FPendingLatentAction {
private:
    bool &success;
    FRespondToAuthChallengeResult &respondToAuthChallengeResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::RespondToAuthChallengeOutcomeCallable callable;

public:
    FRespondToAuthChallengeAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FRespondToAuthChallengeRequest respondToAuthChallengeRequest,
        FRespondToAuthChallengeResult &respondToAuthChallengeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), respondToAuthChallengeResult(respondToAuthChallengeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->RespondToAuthChallengeCallable(respondToAuthChallengeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsRespondToAuthChallengeOutcome = callable.get();

            success = awsRespondToAuthChallengeOutcome.IsSuccess();
                if (success) {
                    respondToAuthChallengeResult.fromAWS(awsRespondToAuthChallengeOutcome.GetResult());
                }

                errorType = fromAWS(awsRespondToAuthChallengeOutcome.GetError().GetErrorType());
                errorMessage = ("RespondToAuthChallenge error: " + awsRespondToAuthChallengeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RespondToAuthChallenge Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::RespondToAuthChallenge(
        UObject *WorldContextObject,
        bool &success,
        FRespondToAuthChallengeRequest respondToAuthChallengeRequest,
        FRespondToAuthChallengeResult &respondToAuthChallengeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRespondToAuthChallengeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRespondToAuthChallengeAction(this->awsCognitoIdentityProviderClient,
                success,
                respondToAuthChallengeRequest,
                respondToAuthChallengeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FRevokeTokenAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSCognitoIdentityProviderRevokeTokenResult &revokeTokenResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::RevokeTokenOutcomeCallable callable;

public:
    FRevokeTokenAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FAWSCognitoIdentityProviderRevokeTokenRequest revokeTokenRequest,
        FAWSCognitoIdentityProviderRevokeTokenResult &revokeTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), revokeTokenResult(revokeTokenResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->RevokeTokenCallable(revokeTokenRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsRevokeTokenOutcome = callable.get();

            success = awsRevokeTokenOutcome.IsSuccess();
                if (success) {
                    revokeTokenResult.fromAWS(awsRevokeTokenOutcome.GetResult());
                }

                errorType = fromAWS(awsRevokeTokenOutcome.GetError().GetErrorType());
                errorMessage = ("RevokeToken error: " + awsRevokeTokenOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RevokeToken Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::RevokeToken(
    UObject *WorldContextObject,
    bool &success,
    FAWSCognitoIdentityProviderRevokeTokenRequest revokeTokenRequest,
    FAWSCognitoIdentityProviderRevokeTokenResult &revokeTokenResult,
    ECognitoIdpError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRevokeTokenAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRevokeTokenAction(this->awsCognitoIdentityProviderClient,
                success,
                revokeTokenRequest,
                revokeTokenResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FSetRiskConfigurationAction : public FPendingLatentAction {
private:
    bool &success;
    FSetRiskConfigurationResult &setRiskConfigurationResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::SetRiskConfigurationOutcomeCallable callable;

public:
    FSetRiskConfigurationAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSetRiskConfigurationRequest setRiskConfigurationRequest,
        FSetRiskConfigurationResult &setRiskConfigurationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), setRiskConfigurationResult(setRiskConfigurationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->SetRiskConfigurationCallable(setRiskConfigurationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSetRiskConfigurationOutcome = callable.get();

            success = awsSetRiskConfigurationOutcome.IsSuccess();
                if (success) {
                    setRiskConfigurationResult.fromAWS(awsSetRiskConfigurationOutcome.GetResult());
                }

                errorType = fromAWS(awsSetRiskConfigurationOutcome.GetError().GetErrorType());
                errorMessage = ("SetRiskConfiguration error: " + awsSetRiskConfigurationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetRiskConfiguration Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SetRiskConfiguration(
        UObject *WorldContextObject,
        bool &success,
        FSetRiskConfigurationRequest setRiskConfigurationRequest,
        FSetRiskConfigurationResult &setRiskConfigurationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetRiskConfigurationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetRiskConfigurationAction(this->awsCognitoIdentityProviderClient,
                success,
                setRiskConfigurationRequest,
                setRiskConfigurationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FSetUICustomizationAction : public FPendingLatentAction {
private:
    bool &success;
    FSetUICustomizationResult &setUICustomizationResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::SetUICustomizationOutcomeCallable callable;

public:
    FSetUICustomizationAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSetUICustomizationRequest setUICustomizationRequest,
        FSetUICustomizationResult &setUICustomizationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), setUICustomizationResult(setUICustomizationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->SetUICustomizationCallable(setUICustomizationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSetUICustomizationOutcome = callable.get();

            success = awsSetUICustomizationOutcome.IsSuccess();
                if (success) {
                    setUICustomizationResult.fromAWS(awsSetUICustomizationOutcome.GetResult());
                }

                errorType = fromAWS(awsSetUICustomizationOutcome.GetError().GetErrorType());
                errorMessage = ("SetUICustomization error: " + awsSetUICustomizationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetUICustomization Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SetUICustomization(
        UObject *WorldContextObject,
        bool &success,
        FSetUICustomizationRequest setUICustomizationRequest,
        FSetUICustomizationResult &setUICustomizationResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetUICustomizationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetUICustomizationAction(this->awsCognitoIdentityProviderClient,
                success,
                setUICustomizationRequest,
                setUICustomizationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FSetUserMFAPreferenceAction : public FPendingLatentAction {
private:
    bool &success;
    FSetUserMFAPreferenceResult &setUserMFAPreferenceResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::SetUserMFAPreferenceOutcomeCallable callable;

public:
    FSetUserMFAPreferenceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSetUserMFAPreferenceRequest setUserMFAPreferenceRequest,
        FSetUserMFAPreferenceResult &setUserMFAPreferenceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), setUserMFAPreferenceResult(setUserMFAPreferenceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->SetUserMFAPreferenceCallable(setUserMFAPreferenceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSetUserMFAPreferenceOutcome = callable.get();

            success = awsSetUserMFAPreferenceOutcome.IsSuccess();
                if (success) {
                    setUserMFAPreferenceResult.fromAWS(awsSetUserMFAPreferenceOutcome.GetResult());
                }

                errorType = fromAWS(awsSetUserMFAPreferenceOutcome.GetError().GetErrorType());
                errorMessage = ("SetUserMFAPreference error: " + awsSetUserMFAPreferenceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetUserMFAPreference Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SetUserMFAPreference(
        UObject *WorldContextObject,
        bool &success,
        FSetUserMFAPreferenceRequest setUserMFAPreferenceRequest,
        FSetUserMFAPreferenceResult &setUserMFAPreferenceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetUserMFAPreferenceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetUserMFAPreferenceAction(this->awsCognitoIdentityProviderClient,
                success,
                setUserMFAPreferenceRequest,
                setUserMFAPreferenceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FSetUserPoolMfaConfigAction : public FPendingLatentAction {
private:
    bool &success;
    FSetUserPoolMfaConfigResult &setUserPoolMfaConfigResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::SetUserPoolMfaConfigOutcomeCallable callable;

public:
    FSetUserPoolMfaConfigAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSetUserPoolMfaConfigRequest setUserPoolMfaConfigRequest,
        FSetUserPoolMfaConfigResult &setUserPoolMfaConfigResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), setUserPoolMfaConfigResult(setUserPoolMfaConfigResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->SetUserPoolMfaConfigCallable(setUserPoolMfaConfigRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSetUserPoolMfaConfigOutcome = callable.get();

            success = awsSetUserPoolMfaConfigOutcome.IsSuccess();
                if (success) {
                    setUserPoolMfaConfigResult.fromAWS(awsSetUserPoolMfaConfigOutcome.GetResult());
                }

                errorType = fromAWS(awsSetUserPoolMfaConfigOutcome.GetError().GetErrorType());
                errorMessage = ("SetUserPoolMfaConfig error: " + awsSetUserPoolMfaConfigOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetUserPoolMfaConfig Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SetUserPoolMfaConfig(
        UObject *WorldContextObject,
        bool &success,
        FSetUserPoolMfaConfigRequest setUserPoolMfaConfigRequest,
        FSetUserPoolMfaConfigResult &setUserPoolMfaConfigResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetUserPoolMfaConfigAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetUserPoolMfaConfigAction(this->awsCognitoIdentityProviderClient,
                success,
                setUserPoolMfaConfigRequest,
                setUserPoolMfaConfigResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FSetUserSettingsAction : public FPendingLatentAction {
private:
    bool &success;
    FSetUserSettingsResult &setUserSettingsResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::SetUserSettingsOutcomeCallable callable;

public:
    FSetUserSettingsAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSetUserSettingsRequest setUserSettingsRequest,
        FSetUserSettingsResult &setUserSettingsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), setUserSettingsResult(setUserSettingsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->SetUserSettingsCallable(setUserSettingsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSetUserSettingsOutcome = callable.get();

            success = awsSetUserSettingsOutcome.IsSuccess();
                if (success) {
                    setUserSettingsResult.fromAWS(awsSetUserSettingsOutcome.GetResult());
                }

                errorType = fromAWS(awsSetUserSettingsOutcome.GetError().GetErrorType());
                errorMessage = ("SetUserSettings error: " + awsSetUserSettingsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SetUserSettings Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SetUserSettings(
        UObject *WorldContextObject,
        bool &success,
        FSetUserSettingsRequest setUserSettingsRequest,
        FSetUserSettingsResult &setUserSettingsResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSetUserSettingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSetUserSettingsAction(this->awsCognitoIdentityProviderClient,
                success,
                setUserSettingsRequest,
                setUserSettingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FSignUpAction : public FPendingLatentAction {
private:
    bool &success;
    FSignUpResult &signUpResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::SignUpOutcomeCallable callable;

public:
    FSignUpAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FSignUpRequest signUpRequest,
        FSignUpResult &signUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), signUpResult(signUpResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->SignUpCallable(signUpRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsSignUpOutcome = callable.get();

            success = awsSignUpOutcome.IsSuccess();
                if (success) {
                    signUpResult.fromAWS(awsSignUpOutcome.GetResult());
                }

                errorType = fromAWS(awsSignUpOutcome.GetError().GetErrorType());
                errorMessage = ("SignUp error: " + awsSignUpOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("SignUp Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::SignUp(
        UObject *WorldContextObject,
        bool &success,
        FSignUpRequest signUpRequest,
        FSignUpResult &signUpResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FSignUpAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FSignUpAction(this->awsCognitoIdentityProviderClient,
                success,
                signUpRequest,
                signUpResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FStartUserImportJobAction : public FPendingLatentAction {
private:
    bool &success;
    FStartUserImportJobResult &startUserImportJobResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::StartUserImportJobOutcomeCallable callable;

public:
    FStartUserImportJobAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FStartUserImportJobRequest startUserImportJobRequest,
        FStartUserImportJobResult &startUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), startUserImportJobResult(startUserImportJobResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->StartUserImportJobCallable(startUserImportJobRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsStartUserImportJobOutcome = callable.get();

            success = awsStartUserImportJobOutcome.IsSuccess();
                if (success) {
                    startUserImportJobResult.fromAWS(awsStartUserImportJobOutcome.GetResult());
                }

                errorType = fromAWS(awsStartUserImportJobOutcome.GetError().GetErrorType());
                errorMessage = ("StartUserImportJob error: " + awsStartUserImportJobOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StartUserImportJob Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::StartUserImportJob(
        UObject *WorldContextObject,
        bool &success,
        FStartUserImportJobRequest startUserImportJobRequest,
        FStartUserImportJobResult &startUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStartUserImportJobAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStartUserImportJobAction(this->awsCognitoIdentityProviderClient,
                success,
                startUserImportJobRequest,
                startUserImportJobResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FStopUserImportJobAction : public FPendingLatentAction {
private:
    bool &success;
    FStopUserImportJobResult &stopUserImportJobResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::StopUserImportJobOutcomeCallable callable;

public:
    FStopUserImportJobAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FStopUserImportJobRequest stopUserImportJobRequest,
        FStopUserImportJobResult &stopUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), stopUserImportJobResult(stopUserImportJobResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->StopUserImportJobCallable(stopUserImportJobRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsStopUserImportJobOutcome = callable.get();

            success = awsStopUserImportJobOutcome.IsSuccess();
                if (success) {
                    stopUserImportJobResult.fromAWS(awsStopUserImportJobOutcome.GetResult());
                }

                errorType = fromAWS(awsStopUserImportJobOutcome.GetError().GetErrorType());
                errorMessage = ("StopUserImportJob error: " + awsStopUserImportJobOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("StopUserImportJob Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::StopUserImportJob(
        UObject *WorldContextObject,
        bool &success,
        FStopUserImportJobRequest stopUserImportJobRequest,
        FStopUserImportJobResult &stopUserImportJobResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FStopUserImportJobAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FStopUserImportJobAction(this->awsCognitoIdentityProviderClient,
                success,
                stopUserImportJobRequest,
                stopUserImportJobResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FTagResourceAction : public FPendingLatentAction {
private:
    bool &success;
    FCognitoIdpTagResourceResult &tagResourceResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::TagResourceOutcomeCallable callable;

public:
    FTagResourceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCognitoIdpTagResourceRequest tagResourceRequest,
        FCognitoIdpTagResourceResult &tagResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), tagResourceResult(tagResourceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->TagResourceCallable(tagResourceRequest.toAWS());
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
UCognitoIdpClientObject::TagResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdpTagResourceRequest tagResourceRequest,
        FCognitoIdpTagResourceResult &tagResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FTagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FTagResourceAction(this->awsCognitoIdentityProviderClient,
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
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FUntagResourceAction : public FPendingLatentAction {
private:
    bool &success;
    FCognitoIdpUntagResourceResult &untagResourceResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::UntagResourceOutcomeCallable callable;

public:
    FUntagResourceAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FCognitoIdpUntagResourceRequest untagResourceRequest,
        FCognitoIdpUntagResourceResult &untagResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), untagResourceResult(untagResourceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->UntagResourceCallable(untagResourceRequest.toAWS());
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
UCognitoIdpClientObject::UntagResource(
        UObject *WorldContextObject,
        bool &success,
        FCognitoIdpUntagResourceRequest untagResourceRequest,
        FCognitoIdpUntagResourceResult &untagResourceResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUntagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUntagResourceAction(this->awsCognitoIdentityProviderClient,
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
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FUpdateAuthEventFeedbackAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateAuthEventFeedbackResult &updateAuthEventFeedbackResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::UpdateAuthEventFeedbackOutcomeCallable callable;

public:
    FUpdateAuthEventFeedbackAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateAuthEventFeedbackRequest updateAuthEventFeedbackRequest,
        FUpdateAuthEventFeedbackResult &updateAuthEventFeedbackResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateAuthEventFeedbackResult(updateAuthEventFeedbackResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->UpdateAuthEventFeedbackCallable(updateAuthEventFeedbackRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateAuthEventFeedbackOutcome = callable.get();

            success = awsUpdateAuthEventFeedbackOutcome.IsSuccess();
                if (success) {
                    updateAuthEventFeedbackResult.fromAWS(awsUpdateAuthEventFeedbackOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateAuthEventFeedbackOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateAuthEventFeedback error: " + awsUpdateAuthEventFeedbackOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateAuthEventFeedback Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateAuthEventFeedback(
        UObject *WorldContextObject,
        bool &success,
        FUpdateAuthEventFeedbackRequest updateAuthEventFeedbackRequest,
        FUpdateAuthEventFeedbackResult &updateAuthEventFeedbackResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateAuthEventFeedbackAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateAuthEventFeedbackAction(this->awsCognitoIdentityProviderClient,
                success,
                updateAuthEventFeedbackRequest,
                updateAuthEventFeedbackResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FUpdateDeviceStatusAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateDeviceStatusResult &updateDeviceStatusResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::UpdateDeviceStatusOutcomeCallable callable;

public:
    FUpdateDeviceStatusAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateDeviceStatusRequest updateDeviceStatusRequest,
        FUpdateDeviceStatusResult &updateDeviceStatusResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateDeviceStatusResult(updateDeviceStatusResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->UpdateDeviceStatusCallable(updateDeviceStatusRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateDeviceStatusOutcome = callable.get();

            success = awsUpdateDeviceStatusOutcome.IsSuccess();
                if (success) {
                    updateDeviceStatusResult.fromAWS(awsUpdateDeviceStatusOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateDeviceStatusOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateDeviceStatus error: " + awsUpdateDeviceStatusOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateDeviceStatus Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateDeviceStatus(
        UObject *WorldContextObject,
        bool &success,
        FUpdateDeviceStatusRequest updateDeviceStatusRequest,
        FUpdateDeviceStatusResult &updateDeviceStatusResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateDeviceStatusAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateDeviceStatusAction(this->awsCognitoIdentityProviderClient,
                success,
                updateDeviceStatusRequest,
                updateDeviceStatusResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FUpdateGroupAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateGroupResult &updateGroupResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::UpdateGroupOutcomeCallable callable;

public:
    FUpdateGroupAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateGroupRequest updateGroupRequest,
        FUpdateGroupResult &updateGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateGroupResult(updateGroupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->UpdateGroupCallable(updateGroupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateGroupOutcome = callable.get();

            success = awsUpdateGroupOutcome.IsSuccess();
                if (success) {
                    updateGroupResult.fromAWS(awsUpdateGroupOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateGroupOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateGroup error: " + awsUpdateGroupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateGroup Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateGroup(
        UObject *WorldContextObject,
        bool &success,
        FUpdateGroupRequest updateGroupRequest,
        FUpdateGroupResult &updateGroupResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateGroupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateGroupAction(this->awsCognitoIdentityProviderClient,
                success,
                updateGroupRequest,
                updateGroupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FUpdateIdentityProviderAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateIdentityProviderResult &updateIdentityProviderResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::UpdateIdentityProviderOutcomeCallable callable;

public:
    FUpdateIdentityProviderAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateIdentityProviderRequest updateIdentityProviderRequest,
        FUpdateIdentityProviderResult &updateIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateIdentityProviderResult(updateIdentityProviderResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->UpdateIdentityProviderCallable(updateIdentityProviderRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateIdentityProviderOutcome = callable.get();

            success = awsUpdateIdentityProviderOutcome.IsSuccess();
                if (success) {
                    updateIdentityProviderResult.fromAWS(awsUpdateIdentityProviderOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateIdentityProviderOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateIdentityProvider error: " + awsUpdateIdentityProviderOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateIdentityProvider Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateIdentityProvider(
        UObject *WorldContextObject,
        bool &success,
        FUpdateIdentityProviderRequest updateIdentityProviderRequest,
        FUpdateIdentityProviderResult &updateIdentityProviderResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateIdentityProviderAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateIdentityProviderAction(this->awsCognitoIdentityProviderClient,
                success,
                updateIdentityProviderRequest,
                updateIdentityProviderResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FUpdateResourceServerAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateResourceServerResult &updateResourceServerResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::UpdateResourceServerOutcomeCallable callable;

public:
    FUpdateResourceServerAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateResourceServerRequest updateResourceServerRequest,
        FUpdateResourceServerResult &updateResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateResourceServerResult(updateResourceServerResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->UpdateResourceServerCallable(updateResourceServerRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateResourceServerOutcome = callable.get();

            success = awsUpdateResourceServerOutcome.IsSuccess();
                if (success) {
                    updateResourceServerResult.fromAWS(awsUpdateResourceServerOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateResourceServerOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateResourceServer error: " + awsUpdateResourceServerOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateResourceServer Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateResourceServer(
        UObject *WorldContextObject,
        bool &success,
        FUpdateResourceServerRequest updateResourceServerRequest,
        FUpdateResourceServerResult &updateResourceServerResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateResourceServerAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateResourceServerAction(this->awsCognitoIdentityProviderClient,
                success,
                updateResourceServerRequest,
                updateResourceServerResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FUpdateUserAttributesAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateUserAttributesResult &updateUserAttributesResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::UpdateUserAttributesOutcomeCallable callable;

public:
    FUpdateUserAttributesAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateUserAttributesRequest updateUserAttributesRequest,
        FUpdateUserAttributesResult &updateUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateUserAttributesResult(updateUserAttributesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->UpdateUserAttributesCallable(updateUserAttributesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateUserAttributesOutcome = callable.get();

            success = awsUpdateUserAttributesOutcome.IsSuccess();
                if (success) {
                    updateUserAttributesResult.fromAWS(awsUpdateUserAttributesOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateUserAttributesOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateUserAttributes error: " + awsUpdateUserAttributesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateUserAttributes Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateUserAttributes(
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserAttributesRequest updateUserAttributesRequest,
        FUpdateUserAttributesResult &updateUserAttributesResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateUserAttributesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateUserAttributesAction(this->awsCognitoIdentityProviderClient,
                success,
                updateUserAttributesRequest,
                updateUserAttributesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FUpdateUserPoolAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateUserPoolResult &updateUserPoolResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::UpdateUserPoolOutcomeCallable callable;

public:
    FUpdateUserPoolAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateUserPoolRequest updateUserPoolRequest,
        FUpdateUserPoolResult &updateUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateUserPoolResult(updateUserPoolResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->UpdateUserPoolCallable(updateUserPoolRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateUserPoolOutcome = callable.get();

            success = awsUpdateUserPoolOutcome.IsSuccess();
                if (success) {
                    updateUserPoolResult.fromAWS(awsUpdateUserPoolOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateUserPoolOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateUserPool error: " + awsUpdateUserPoolOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateUserPool Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateUserPool(
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserPoolRequest updateUserPoolRequest,
        FUpdateUserPoolResult &updateUserPoolResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateUserPoolAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateUserPoolAction(this->awsCognitoIdentityProviderClient,
                success,
                updateUserPoolRequest,
                updateUserPoolResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FUpdateUserPoolClientAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateUserPoolClientResult &updateUserPoolClientResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::UpdateUserPoolClientOutcomeCallable callable;

public:
    FUpdateUserPoolClientAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateUserPoolClientRequest updateUserPoolClientRequest,
        FUpdateUserPoolClientResult &updateUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateUserPoolClientResult(updateUserPoolClientResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->UpdateUserPoolClientCallable(updateUserPoolClientRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateUserPoolClientOutcome = callable.get();

            success = awsUpdateUserPoolClientOutcome.IsSuccess();
                if (success) {
                    updateUserPoolClientResult.fromAWS(awsUpdateUserPoolClientOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateUserPoolClientOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateUserPoolClient error: " + awsUpdateUserPoolClientOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateUserPoolClient Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateUserPoolClient(
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserPoolClientRequest updateUserPoolClientRequest,
        FUpdateUserPoolClientResult &updateUserPoolClientResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateUserPoolClientAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateUserPoolClientAction(this->awsCognitoIdentityProviderClient,
                success,
                updateUserPoolClientRequest,
                updateUserPoolClientResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FUpdateUserPoolDomainAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateUserPoolDomainResult &updateUserPoolDomainResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::UpdateUserPoolDomainOutcomeCallable callable;

public:
    FUpdateUserPoolDomainAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FUpdateUserPoolDomainRequest updateUserPoolDomainRequest,
        FUpdateUserPoolDomainResult &updateUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateUserPoolDomainResult(updateUserPoolDomainResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->UpdateUserPoolDomainCallable(updateUserPoolDomainRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateUserPoolDomainOutcome = callable.get();

            success = awsUpdateUserPoolDomainOutcome.IsSuccess();
                if (success) {
                    updateUserPoolDomainResult.fromAWS(awsUpdateUserPoolDomainOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateUserPoolDomainOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateUserPoolDomain error: " + awsUpdateUserPoolDomainOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateUserPoolDomain Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::UpdateUserPoolDomain(
        UObject *WorldContextObject,
        bool &success,
        FUpdateUserPoolDomainRequest updateUserPoolDomainRequest,
        FUpdateUserPoolDomainResult &updateUserPoolDomainResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateUserPoolDomainAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateUserPoolDomainAction(this->awsCognitoIdentityProviderClient,
                success,
                updateUserPoolDomainRequest,
                updateUserPoolDomainResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FVerifySoftwareTokenAction : public FPendingLatentAction {
private:
    bool &success;
    FVerifySoftwareTokenResult &verifySoftwareTokenResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::VerifySoftwareTokenOutcomeCallable callable;

public:
    FVerifySoftwareTokenAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FVerifySoftwareTokenRequest verifySoftwareTokenRequest,
        FVerifySoftwareTokenResult &verifySoftwareTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), verifySoftwareTokenResult(verifySoftwareTokenResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->VerifySoftwareTokenCallable(verifySoftwareTokenRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsVerifySoftwareTokenOutcome = callable.get();

            success = awsVerifySoftwareTokenOutcome.IsSuccess();
                if (success) {
                    verifySoftwareTokenResult.fromAWS(awsVerifySoftwareTokenOutcome.GetResult());
                }

                errorType = fromAWS(awsVerifySoftwareTokenOutcome.GetError().GetErrorType());
                errorMessage = ("VerifySoftwareToken error: " + awsVerifySoftwareTokenOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("VerifySoftwareToken Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::VerifySoftwareToken(
        UObject *WorldContextObject,
        bool &success,
        FVerifySoftwareTokenRequest verifySoftwareTokenRequest,
        FVerifySoftwareTokenResult &verifySoftwareTokenResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FVerifySoftwareTokenAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FVerifySoftwareTokenAction(this->awsCognitoIdentityProviderClient,
                success,
                verifySoftwareTokenRequest,
                verifySoftwareTokenResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

class FVerifyUserAttributeAction : public FPendingLatentAction {
private:
    bool &success;
    FVerifyUserAttributeResult &verifyUserAttributeResult;
    ECognitoIdpError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::CognitoIdentityProvider::Model::VerifyUserAttributeOutcomeCallable callable;

public:
    FVerifyUserAttributeAction(
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient *CognitoIdpClient,
        bool &success,
        FVerifyUserAttributeRequest verifyUserAttributeRequest,
        FVerifyUserAttributeResult &verifyUserAttributeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), verifyUserAttributeResult(verifyUserAttributeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = CognitoIdpClient->VerifyUserAttributeCallable(verifyUserAttributeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsVerifyUserAttributeOutcome = callable.get();

            success = awsVerifyUserAttributeOutcome.IsSuccess();
                if (success) {
                    verifyUserAttributeResult.fromAWS(awsVerifyUserAttributeOutcome.GetResult());
                }

                errorType = fromAWS(awsVerifyUserAttributeOutcome.GetError().GetErrorType());
                errorMessage = ("VerifyUserAttribute error: " + awsVerifyUserAttributeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("VerifyUserAttribute Request");
    }

#endif
};

#endif

void
UCognitoIdpClientObject::VerifyUserAttribute(
        UObject *WorldContextObject,
        bool &success,
        FVerifyUserAttributeRequest verifyUserAttributeRequest,
        FVerifyUserAttributeResult &verifyUserAttributeResult,
        ECognitoIdpError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FVerifyUserAttributeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FVerifyUserAttributeAction(this->awsCognitoIdentityProviderClient,
                success,
                verifyUserAttributeRequest,
                verifyUserAttributeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}