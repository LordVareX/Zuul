/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#include "DynamoDBClientObject.h"
#include "DynamoDBGlobals.h"
#include "DynamoDBPrivatePCH.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "LatentActions.h"

#include "aws/core/utils/Outcome.h"
#include "aws/core/client/AWSError.h"

#endif

#if WITH_DYNAMODBCLIENTSDK

EDynamoDBError fromAWS(Aws::DynamoDB::DynamoDBErrors awsErrorType) {
    switch (awsErrorType) {
        case Aws::DynamoDB::DynamoDBErrors::INCOMPLETE_SIGNATURE:
            return EDynamoDBError::INCOMPLETE_SIGNATURE;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INTERNAL_FAILURE:
            return EDynamoDBError::INTERNAL_FAILURE;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INVALID_ACTION:
            return EDynamoDBError::INVALID_ACTION;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INVALID_CLIENT_TOKEN_ID:
            return EDynamoDBError::INVALID_CLIENT_TOKEN_ID;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INVALID_PARAMETER_COMBINATION:
            return EDynamoDBError::INVALID_PARAMETER_COMBINATION;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INVALID_QUERY_PARAMETER:
            return EDynamoDBError::INVALID_QUERY_PARAMETER;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INVALID_PARAMETER_VALUE:
            return EDynamoDBError::INVALID_PARAMETER_VALUE;
            break;
        case Aws::DynamoDB::DynamoDBErrors::MISSING_ACTION:
            return EDynamoDBError::MISSING_ACTION;
            break;
        case Aws::DynamoDB::DynamoDBErrors::MISSING_AUTHENTICATION_TOKEN:
            return EDynamoDBError::MISSING_AUTHENTICATION_TOKEN;
            break;
        case Aws::DynamoDB::DynamoDBErrors::MISSING_PARAMETER:
            return EDynamoDBError::MISSING_PARAMETER;
            break;
        case Aws::DynamoDB::DynamoDBErrors::OPT_IN_REQUIRED:
            return EDynamoDBError::OPT_IN_REQUIRED;
            break;
        case Aws::DynamoDB::DynamoDBErrors::REQUEST_EXPIRED:
            return EDynamoDBError::REQUEST_EXPIRED;
            break;
        case Aws::DynamoDB::DynamoDBErrors::SERVICE_UNAVAILABLE:
            return EDynamoDBError::SERVICE_UNAVAILABLE;
            break;
        case Aws::DynamoDB::DynamoDBErrors::THROTTLING:
            return EDynamoDBError::THROTTLING;
            break;
        case Aws::DynamoDB::DynamoDBErrors::VALIDATION:
            return EDynamoDBError::VALIDATION;
            break;
        case Aws::DynamoDB::DynamoDBErrors::ACCESS_DENIED:
            return EDynamoDBError::ACCESS_DENIED;
            break;
        case Aws::DynamoDB::DynamoDBErrors::RESOURCE_NOT_FOUND:
            return EDynamoDBError::RESOURCE_NOT_FOUND;
            break;
        case Aws::DynamoDB::DynamoDBErrors::UNRECOGNIZED_CLIENT:
            return EDynamoDBError::UNRECOGNIZED_CLIENT;
            break;
        case Aws::DynamoDB::DynamoDBErrors::MALFORMED_QUERY_STRING:
            return EDynamoDBError::MALFORMED_QUERY_STRING;
            break;
        case Aws::DynamoDB::DynamoDBErrors::SLOW_DOWN:
            return EDynamoDBError::SLOW_DOWN;
            break;
        case Aws::DynamoDB::DynamoDBErrors::REQUEST_TIME_TOO_SKEWED:
            return EDynamoDBError::REQUEST_TIME_TOO_SKEWED;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INVALID_SIGNATURE:
            return EDynamoDBError::INVALID_SIGNATURE;
            break;
        case Aws::DynamoDB::DynamoDBErrors::SIGNATURE_DOES_NOT_MATCH:
            return EDynamoDBError::SIGNATURE_DOES_NOT_MATCH;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INVALID_ACCESS_KEY_ID:
            return EDynamoDBError::INVALID_ACCESS_KEY_ID;
            break;
        case Aws::DynamoDB::DynamoDBErrors::REQUEST_TIMEOUT:
            return EDynamoDBError::REQUEST_TIMEOUT;
            break;
        case Aws::DynamoDB::DynamoDBErrors::NETWORK_CONNECTION:
            return EDynamoDBError::NETWORK_CONNECTION;
            break;
        case Aws::DynamoDB::DynamoDBErrors::UNKNOWN:
            return EDynamoDBError::UNKNOWN;
            break;
        case Aws::DynamoDB::DynamoDBErrors::BACKUP_IN_USE:
            return EDynamoDBError::BACKUP_IN_USE;
            break;
        case Aws::DynamoDB::DynamoDBErrors::BACKUP_NOT_FOUND:
            return EDynamoDBError::BACKUP_NOT_FOUND;
            break;
        case Aws::DynamoDB::DynamoDBErrors::CONDITIONAL_CHECK_FAILED:
            return EDynamoDBError::CONDITIONAL_CHECK_FAILED;
            break;
        case Aws::DynamoDB::DynamoDBErrors::CONTINUOUS_BACKUPS_UNAVAILABLE:
            return EDynamoDBError::CONTINUOUS_BACKUPS_UNAVAILABLE;
            break;
        case Aws::DynamoDB::DynamoDBErrors::DUPLICATE_ITEM:
            return EDynamoDBError::DUPLICATE_ITEM;
            break;
        case Aws::DynamoDB::DynamoDBErrors::EXPORT_CONFLICT:
            return EDynamoDBError::EXPORT_CONFLICT;
            break;
        case Aws::DynamoDB::DynamoDBErrors::EXPORT_NOT_FOUND:
            return EDynamoDBError::EXPORT_NOT_FOUND;
            break;
        case Aws::DynamoDB::DynamoDBErrors::GLOBAL_TABLE_ALREADY_EXISTS:
            return EDynamoDBError::GLOBAL_TABLE_ALREADY_EXISTS;
            break;
        case Aws::DynamoDB::DynamoDBErrors::GLOBAL_TABLE_NOT_FOUND:
            return EDynamoDBError::GLOBAL_TABLE_NOT_FOUND;
            break;
        case Aws::DynamoDB::DynamoDBErrors::IDEMPOTENT_PARAMETER_MISMATCH:
            return EDynamoDBError::IDEMPOTENT_PARAMETER_MISMATCH;
            break;
        case Aws::DynamoDB::DynamoDBErrors::IMPORT_CONFLICT:
            return EDynamoDBError::IMPORT_CONFLICT;
            break;
        case Aws::DynamoDB::DynamoDBErrors::IMPORT_NOT_FOUND:
            return EDynamoDBError::IMPORT_NOT_FOUND;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INDEX_NOT_FOUND:
            return EDynamoDBError::INDEX_NOT_FOUND;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INVALID_EXPORT_TIME:
            return EDynamoDBError::INVALID_EXPORT_TIME;
            break;
        case Aws::DynamoDB::DynamoDBErrors::INVALID_RESTORE_TIME:
            return EDynamoDBError::INVALID_RESTORE_TIME;
            break;
        case Aws::DynamoDB::DynamoDBErrors::ITEM_COLLECTION_SIZE_LIMIT_EXCEEDED:
            return EDynamoDBError::ITEM_COLLECTION_SIZE_LIMIT_EXCEEDED;
            break;
        case Aws::DynamoDB::DynamoDBErrors::LIMIT_EXCEEDED:
            return EDynamoDBError::LIMIT_EXCEEDED;
            break;
        case Aws::DynamoDB::DynamoDBErrors::POINT_IN_TIME_RECOVERY_UNAVAILABLE:
            return EDynamoDBError::POINT_IN_TIME_RECOVERY_UNAVAILABLE;
            break;
        case Aws::DynamoDB::DynamoDBErrors::PROVISIONED_THROUGHPUT_EXCEEDED:
            return EDynamoDBError::PROVISIONED_THROUGHPUT_EXCEEDED;
            break;
        case Aws::DynamoDB::DynamoDBErrors::REPLICA_ALREADY_EXISTS:
            return EDynamoDBError::REPLICA_ALREADY_EXISTS;
            break;
        case Aws::DynamoDB::DynamoDBErrors::REPLICA_NOT_FOUND:
            return EDynamoDBError::REPLICA_NOT_FOUND;
            break;
        case Aws::DynamoDB::DynamoDBErrors::REQUEST_LIMIT_EXCEEDED:
            return EDynamoDBError::REQUEST_LIMIT_EXCEEDED;
            break;
        case Aws::DynamoDB::DynamoDBErrors::RESOURCE_IN_USE:
            return EDynamoDBError::RESOURCE_IN_USE;
            break;
        case Aws::DynamoDB::DynamoDBErrors::TABLE_ALREADY_EXISTS:
            return EDynamoDBError::TABLE_ALREADY_EXISTS;
            break;
        case Aws::DynamoDB::DynamoDBErrors::TABLE_IN_USE:
            return EDynamoDBError::TABLE_IN_USE;
            break;
        case Aws::DynamoDB::DynamoDBErrors::TABLE_NOT_FOUND:
            return EDynamoDBError::TABLE_NOT_FOUND;
            break;
        case Aws::DynamoDB::DynamoDBErrors::TRANSACTION_CANCELED:
            return EDynamoDBError::TRANSACTION_CANCELED;
            break;
        case Aws::DynamoDB::DynamoDBErrors::TRANSACTION_CONFLICT:
            return EDynamoDBError::TRANSACTION_CONFLICT;
            break;
        case Aws::DynamoDB::DynamoDBErrors::TRANSACTION_IN_PROGRESS:
            return EDynamoDBError::TRANSACTION_IN_PROGRESS;
            break;
        default:
            return EDynamoDBError::UNKNOWN;
            break;
    }
}

#endif

UDynamoDBClientObject *UDynamoDBClientObject::CreateDynamoDBObject(
        const FAWSCredentials &credentials,
        const FAWSClientConfiguration &clientConfiguration
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    UDynamoDBClientObject *DynamoDBClient = NewObject<UDynamoDBClientObject>();
    DynamoDBClient->awsDynamoDBClient = new Aws::DynamoDB::DynamoDBClient(credentials.toAWS(),
    Aws::MakeShared<Aws::DynamoDB::DynamoDBEndpointProvider>("unreal"),
    clientConfiguration.toAWS());
    return DynamoDBClient;
#endif
    return nullptr;
}

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FBatchExecuteStatementAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBBatchExecuteStatementResult &batchExecuteStatementResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::BatchExecuteStatementOutcomeCallable callable;

public:
    FBatchExecuteStatementAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBBatchExecuteStatementRequest batchExecuteStatementRequest,
        FAWSDynamoDBBatchExecuteStatementResult &batchExecuteStatementResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), batchExecuteStatementResult(batchExecuteStatementResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->BatchExecuteStatementCallable(batchExecuteStatementRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsBatchExecuteStatementOutcome = callable.get();

            success = awsBatchExecuteStatementOutcome.IsSuccess();
                if (success) {
                    batchExecuteStatementResult.fromAWS(awsBatchExecuteStatementOutcome.GetResult());
                }

                errorType = fromAWS(awsBatchExecuteStatementOutcome.GetError().GetErrorType());
                errorMessage = ("BatchExecuteStatement error: " + awsBatchExecuteStatementOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("BatchExecuteStatement Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::BatchExecuteStatement(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBBatchExecuteStatementRequest batchExecuteStatementRequest,
    FAWSDynamoDBBatchExecuteStatementResult &batchExecuteStatementResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FBatchExecuteStatementAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FBatchExecuteStatementAction(this->awsDynamoDBClient,
                success,
                batchExecuteStatementRequest,
                batchExecuteStatementResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FBatchGetItemAction : public FPendingLatentAction {
private:
    bool &success;
    FBatchGetItemResult &batchGetItemResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::BatchGetItemOutcomeCallable callable;

public:
    FBatchGetItemAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FBatchGetItemRequest batchGetItemRequest,
        FBatchGetItemResult &batchGetItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), batchGetItemResult(batchGetItemResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->BatchGetItemCallable(batchGetItemRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsBatchGetItemOutcome = callable.get();

            success = awsBatchGetItemOutcome.IsSuccess();
                if (success) {
                    batchGetItemResult.fromAWS(awsBatchGetItemOutcome.GetResult());
                }

                errorType = fromAWS(awsBatchGetItemOutcome.GetError().GetErrorType());
                errorMessage = ("BatchGetItem error: " + awsBatchGetItemOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("BatchGetItem Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::BatchGetItem(
        UObject *WorldContextObject,
        bool &success,
        FBatchGetItemRequest batchGetItemRequest,
        FBatchGetItemResult &batchGetItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FBatchGetItemAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FBatchGetItemAction(this->awsDynamoDBClient,
                success,
                batchGetItemRequest,
                batchGetItemResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FBatchWriteItemAction : public FPendingLatentAction {
private:
    bool &success;
    FBatchWriteItemResult &batchWriteItemResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::BatchWriteItemOutcomeCallable callable;

public:
    FBatchWriteItemAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FBatchWriteItemRequest batchWriteItemRequest,
        FBatchWriteItemResult &batchWriteItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), batchWriteItemResult(batchWriteItemResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->BatchWriteItemCallable(batchWriteItemRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsBatchWriteItemOutcome = callable.get();

            success = awsBatchWriteItemOutcome.IsSuccess();
                if (success) {
                    batchWriteItemResult.fromAWS(awsBatchWriteItemOutcome.GetResult());
                }

                errorType = fromAWS(awsBatchWriteItemOutcome.GetError().GetErrorType());
                errorMessage = ("BatchWriteItem error: " + awsBatchWriteItemOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("BatchWriteItem Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::BatchWriteItem(
        UObject *WorldContextObject,
        bool &success,
        FBatchWriteItemRequest batchWriteItemRequest,
        FBatchWriteItemResult &batchWriteItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FBatchWriteItemAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FBatchWriteItemAction(this->awsDynamoDBClient,
                success,
                batchWriteItemRequest,
                batchWriteItemResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FCreateBackupAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateBackupResult &createBackupResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::CreateBackupOutcomeCallable callable;

public:
    FCreateBackupAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FCreateBackupRequest createBackupRequest,
        FCreateBackupResult &createBackupResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createBackupResult(createBackupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->CreateBackupCallable(createBackupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateBackupOutcome = callable.get();

            success = awsCreateBackupOutcome.IsSuccess();
                if (success) {
                    createBackupResult.fromAWS(awsCreateBackupOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateBackupOutcome.GetError().GetErrorType());
                errorMessage = ("CreateBackup error: " + awsCreateBackupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateBackup Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::CreateBackup(
        UObject *WorldContextObject,
        bool &success,
        FCreateBackupRequest createBackupRequest,
        FCreateBackupResult &createBackupResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateBackupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateBackupAction(this->awsDynamoDBClient,
                success,
                createBackupRequest,
                createBackupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FCreateGlobalTableAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateGlobalTableResult &createGlobalTableResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::CreateGlobalTableOutcomeCallable callable;

public:
    FCreateGlobalTableAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FCreateGlobalTableRequest createGlobalTableRequest,
        FCreateGlobalTableResult &createGlobalTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createGlobalTableResult(createGlobalTableResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->CreateGlobalTableCallable(createGlobalTableRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateGlobalTableOutcome = callable.get();

            success = awsCreateGlobalTableOutcome.IsSuccess();
                if (success) {
                    createGlobalTableResult.fromAWS(awsCreateGlobalTableOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateGlobalTableOutcome.GetError().GetErrorType());
                errorMessage = ("CreateGlobalTable error: " + awsCreateGlobalTableOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateGlobalTable Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::CreateGlobalTable(
        UObject *WorldContextObject,
        bool &success,
        FCreateGlobalTableRequest createGlobalTableRequest,
        FCreateGlobalTableResult &createGlobalTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateGlobalTableAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateGlobalTableAction(this->awsDynamoDBClient,
                success,
                createGlobalTableRequest,
                createGlobalTableResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FCreateTableAction : public FPendingLatentAction {
private:
    bool &success;
    FCreateTableResult &createTableResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::CreateTableOutcomeCallable callable;

public:
    FCreateTableAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FCreateTableRequest createTableRequest,
        FCreateTableResult &createTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), createTableResult(createTableResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->CreateTableCallable(createTableRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsCreateTableOutcome = callable.get();

            success = awsCreateTableOutcome.IsSuccess();
                if (success) {
                    createTableResult.fromAWS(awsCreateTableOutcome.GetResult());
                }

                errorType = fromAWS(awsCreateTableOutcome.GetError().GetErrorType());
                errorMessage = ("CreateTable error: " + awsCreateTableOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("CreateTable Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::CreateTable(
        UObject *WorldContextObject,
        bool &success,
        FCreateTableRequest createTableRequest,
        FCreateTableResult &createTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FCreateTableAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FCreateTableAction(this->awsDynamoDBClient,
                success,
                createTableRequest,
                createTableResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDeleteBackupAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteBackupResult &deleteBackupResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DeleteBackupOutcomeCallable callable;

public:
    FDeleteBackupAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDeleteBackupRequest deleteBackupRequest,
        FDeleteBackupResult &deleteBackupResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteBackupResult(deleteBackupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DeleteBackupCallable(deleteBackupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteBackupOutcome = callable.get();

            success = awsDeleteBackupOutcome.IsSuccess();
                if (success) {
                    deleteBackupResult.fromAWS(awsDeleteBackupOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteBackupOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteBackup error: " + awsDeleteBackupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteBackup Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DeleteBackup(
        UObject *WorldContextObject,
        bool &success,
        FDeleteBackupRequest deleteBackupRequest,
        FDeleteBackupResult &deleteBackupResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteBackupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteBackupAction(this->awsDynamoDBClient,
                success,
                deleteBackupRequest,
                deleteBackupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDeleteItemAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteItemResult &deleteItemResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DeleteItemOutcomeCallable callable;

public:
    FDeleteItemAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDeleteItemRequest deleteItemRequest,
        FDeleteItemResult &deleteItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteItemResult(deleteItemResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DeleteItemCallable(deleteItemRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteItemOutcome = callable.get();

            success = awsDeleteItemOutcome.IsSuccess();
                if (success) {
                    deleteItemResult.fromAWS(awsDeleteItemOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteItemOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteItem error: " + awsDeleteItemOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteItem Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DeleteItem(
        UObject *WorldContextObject,
        bool &success,
        FDeleteItemRequest deleteItemRequest,
        FDeleteItemResult &deleteItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteItemAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteItemAction(this->awsDynamoDBClient,
                success,
                deleteItemRequest,
                deleteItemResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDeleteTableAction : public FPendingLatentAction {
private:
    bool &success;
    FDeleteTableResult &deleteTableResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DeleteTableOutcomeCallable callable;

public:
    FDeleteTableAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDeleteTableRequest deleteTableRequest,
        FDeleteTableResult &deleteTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), deleteTableResult(deleteTableResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DeleteTableCallable(deleteTableRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDeleteTableOutcome = callable.get();

            success = awsDeleteTableOutcome.IsSuccess();
                if (success) {
                    deleteTableResult.fromAWS(awsDeleteTableOutcome.GetResult());
                }

                errorType = fromAWS(awsDeleteTableOutcome.GetError().GetErrorType());
                errorMessage = ("DeleteTable error: " + awsDeleteTableOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DeleteTable Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DeleteTable(
        UObject *WorldContextObject,
        bool &success,
        FDeleteTableRequest deleteTableRequest,
        FDeleteTableResult &deleteTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDeleteTableAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDeleteTableAction(this->awsDynamoDBClient,
                success,
                deleteTableRequest,
                deleteTableResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeBackupAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeBackupResult &describeBackupResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeBackupOutcomeCallable callable;

public:
    FDescribeBackupAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDescribeBackupRequest describeBackupRequest,
        FDescribeBackupResult &describeBackupResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeBackupResult(describeBackupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeBackupCallable(describeBackupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeBackupOutcome = callable.get();

            success = awsDescribeBackupOutcome.IsSuccess();
                if (success) {
                    describeBackupResult.fromAWS(awsDescribeBackupOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeBackupOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeBackup error: " + awsDescribeBackupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeBackup Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeBackup(
        UObject *WorldContextObject,
        bool &success,
        FDescribeBackupRequest describeBackupRequest,
        FDescribeBackupResult &describeBackupResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeBackupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeBackupAction(this->awsDynamoDBClient,
                success,
                describeBackupRequest,
                describeBackupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeContinuousBackupsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeContinuousBackupsResult &describeContinuousBackupsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeContinuousBackupsOutcomeCallable callable;

public:
    FDescribeContinuousBackupsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDescribeContinuousBackupsRequest describeContinuousBackupsRequest,
        FDescribeContinuousBackupsResult &describeContinuousBackupsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeContinuousBackupsResult(describeContinuousBackupsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeContinuousBackupsCallable(describeContinuousBackupsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeContinuousBackupsOutcome = callable.get();

            success = awsDescribeContinuousBackupsOutcome.IsSuccess();
                if (success) {
                    describeContinuousBackupsResult.fromAWS(awsDescribeContinuousBackupsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeContinuousBackupsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeContinuousBackups error: " + awsDescribeContinuousBackupsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeContinuousBackups Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeContinuousBackups(
        UObject *WorldContextObject,
        bool &success,
        FDescribeContinuousBackupsRequest describeContinuousBackupsRequest,
        FDescribeContinuousBackupsResult &describeContinuousBackupsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeContinuousBackupsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeContinuousBackupsAction(this->awsDynamoDBClient,
                success,
                describeContinuousBackupsRequest,
                describeContinuousBackupsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeContributorInsightsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeContributorInsightsResult &describeContributorInsightsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeContributorInsightsOutcomeCallable callable;

public:
    FDescribeContributorInsightsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDescribeContributorInsightsRequest describeContributorInsightsRequest,
        FDescribeContributorInsightsResult &describeContributorInsightsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeContributorInsightsResult(describeContributorInsightsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeContributorInsightsCallable(describeContributorInsightsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeContributorInsightsOutcome = callable.get();

            success = awsDescribeContributorInsightsOutcome.IsSuccess();
                if (success) {
                    describeContributorInsightsResult.fromAWS(awsDescribeContributorInsightsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeContributorInsightsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeContributorInsights error: " + awsDescribeContributorInsightsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeContributorInsights Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeContributorInsights(
        UObject *WorldContextObject,
        bool &success,
        FDescribeContributorInsightsRequest describeContributorInsightsRequest,
        FDescribeContributorInsightsResult &describeContributorInsightsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeContributorInsightsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeContributorInsightsAction(this->awsDynamoDBClient,
                success,
                describeContributorInsightsRequest,
                describeContributorInsightsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeEndpointsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeEndpointsResult &describeEndpointsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeEndpointsOutcomeCallable callable;

public:
    FDescribeEndpointsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDescribeEndpointsRequest describeEndpointsRequest,
        FDescribeEndpointsResult &describeEndpointsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeEndpointsResult(describeEndpointsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeEndpointsCallable(describeEndpointsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeEndpointsOutcome = callable.get();

            success = awsDescribeEndpointsOutcome.IsSuccess();
                if (success) {
                    describeEndpointsResult.fromAWS(awsDescribeEndpointsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeEndpointsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeEndpoints error: " + awsDescribeEndpointsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeEndpoints Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeEndpoints(
        UObject *WorldContextObject,
        bool &success,
        FDescribeEndpointsRequest describeEndpointsRequest,
        FDescribeEndpointsResult &describeEndpointsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeEndpointsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeEndpointsAction(this->awsDynamoDBClient,
                success,
                describeEndpointsRequest,
                describeEndpointsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeExportAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBDescribeExportResult &describeExportResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeExportOutcomeCallable callable;

public:
    FDescribeExportAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBDescribeExportRequest describeExportRequest,
        FAWSDynamoDBDescribeExportResult &describeExportResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeExportResult(describeExportResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeExportCallable(describeExportRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeExportOutcome = callable.get();

            success = awsDescribeExportOutcome.IsSuccess();
                if (success) {
                    describeExportResult.fromAWS(awsDescribeExportOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeExportOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeExport error: " + awsDescribeExportOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeExport Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeExport(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBDescribeExportRequest describeExportRequest,
    FAWSDynamoDBDescribeExportResult &describeExportResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeExportAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeExportAction(this->awsDynamoDBClient,
                success,
                describeExportRequest,
                describeExportResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeGlobalTableAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeGlobalTableResult &describeGlobalTableResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeGlobalTableOutcomeCallable callable;

public:
    FDescribeGlobalTableAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDescribeGlobalTableRequest describeGlobalTableRequest,
        FDescribeGlobalTableResult &describeGlobalTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeGlobalTableResult(describeGlobalTableResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeGlobalTableCallable(describeGlobalTableRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeGlobalTableOutcome = callable.get();

            success = awsDescribeGlobalTableOutcome.IsSuccess();
                if (success) {
                    describeGlobalTableResult.fromAWS(awsDescribeGlobalTableOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeGlobalTableOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeGlobalTable error: " + awsDescribeGlobalTableOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeGlobalTable Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeGlobalTable(
        UObject *WorldContextObject,
        bool &success,
        FDescribeGlobalTableRequest describeGlobalTableRequest,
        FDescribeGlobalTableResult &describeGlobalTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeGlobalTableAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeGlobalTableAction(this->awsDynamoDBClient,
                success,
                describeGlobalTableRequest,
                describeGlobalTableResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeGlobalTableSettingsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeGlobalTableSettingsResult &describeGlobalTableSettingsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeGlobalTableSettingsOutcomeCallable callable;

public:
    FDescribeGlobalTableSettingsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDescribeGlobalTableSettingsRequest describeGlobalTableSettingsRequest,
        FDescribeGlobalTableSettingsResult &describeGlobalTableSettingsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeGlobalTableSettingsResult(describeGlobalTableSettingsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeGlobalTableSettingsCallable(describeGlobalTableSettingsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeGlobalTableSettingsOutcome = callable.get();

            success = awsDescribeGlobalTableSettingsOutcome.IsSuccess();
                if (success) {
                    describeGlobalTableSettingsResult.fromAWS(awsDescribeGlobalTableSettingsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeGlobalTableSettingsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeGlobalTableSettings error: " + awsDescribeGlobalTableSettingsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeGlobalTableSettings Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeGlobalTableSettings(
        UObject *WorldContextObject,
        bool &success,
        FDescribeGlobalTableSettingsRequest describeGlobalTableSettingsRequest,
        FDescribeGlobalTableSettingsResult &describeGlobalTableSettingsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeGlobalTableSettingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeGlobalTableSettingsAction(this->awsDynamoDBClient,
                success,
                describeGlobalTableSettingsRequest,
                describeGlobalTableSettingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeImportAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBDescribeImportResult &describeImportResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeImportOutcomeCallable callable;

public:
    FDescribeImportAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBDescribeImportRequest describeImportRequest,
        FAWSDynamoDBDescribeImportResult &describeImportResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeImportResult(describeImportResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeImportCallable(describeImportRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeImportOutcome = callable.get();

            success = awsDescribeImportOutcome.IsSuccess();
                if (success) {
                    describeImportResult.fromAWS(awsDescribeImportOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeImportOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeImport error: " + awsDescribeImportOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeImport Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeImport(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBDescribeImportRequest describeImportRequest,
    FAWSDynamoDBDescribeImportResult &describeImportResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeImportAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeImportAction(this->awsDynamoDBClient,
                success,
                describeImportRequest,
                describeImportResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeKinesisStreamingDestinationAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBDescribeKinesisStreamingDestinationResult &describeKinesisStreamingDestinationResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeKinesisStreamingDestinationOutcomeCallable callable;

public:
    FDescribeKinesisStreamingDestinationAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBDescribeKinesisStreamingDestinationRequest describeKinesisStreamingDestinationRequest,
        FAWSDynamoDBDescribeKinesisStreamingDestinationResult &describeKinesisStreamingDestinationResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeKinesisStreamingDestinationResult(describeKinesisStreamingDestinationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeKinesisStreamingDestinationCallable(describeKinesisStreamingDestinationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeKinesisStreamingDestinationOutcome = callable.get();

            success = awsDescribeKinesisStreamingDestinationOutcome.IsSuccess();
                if (success) {
                    describeKinesisStreamingDestinationResult.fromAWS(awsDescribeKinesisStreamingDestinationOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeKinesisStreamingDestinationOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeKinesisStreamingDestination error: " + awsDescribeKinesisStreamingDestinationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeKinesisStreamingDestination Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeKinesisStreamingDestination(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBDescribeKinesisStreamingDestinationRequest describeKinesisStreamingDestinationRequest,
    FAWSDynamoDBDescribeKinesisStreamingDestinationResult &describeKinesisStreamingDestinationResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeKinesisStreamingDestinationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeKinesisStreamingDestinationAction(this->awsDynamoDBClient,
                success,
                describeKinesisStreamingDestinationRequest,
                describeKinesisStreamingDestinationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeLimitsAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeLimitsResult &describeLimitsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeLimitsOutcomeCallable callable;

public:
    FDescribeLimitsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDescribeLimitsRequest describeLimitsRequest,
        FDescribeLimitsResult &describeLimitsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeLimitsResult(describeLimitsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeLimitsCallable(describeLimitsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeLimitsOutcome = callable.get();

            success = awsDescribeLimitsOutcome.IsSuccess();
                if (success) {
                    describeLimitsResult.fromAWS(awsDescribeLimitsOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeLimitsOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeLimits error: " + awsDescribeLimitsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeLimits Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeLimits(
        UObject *WorldContextObject,
        bool &success,
        FDescribeLimitsRequest describeLimitsRequest,
        FDescribeLimitsResult &describeLimitsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeLimitsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeLimitsAction(this->awsDynamoDBClient,
                success,
                describeLimitsRequest,
                describeLimitsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeTableAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeTableResult &describeTableResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeTableOutcomeCallable callable;

public:
    FDescribeTableAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDescribeTableRequest describeTableRequest,
        FDescribeTableResult &describeTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeTableResult(describeTableResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeTableCallable(describeTableRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeTableOutcome = callable.get();

            success = awsDescribeTableOutcome.IsSuccess();
                if (success) {
                    describeTableResult.fromAWS(awsDescribeTableOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeTableOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeTable error: " + awsDescribeTableOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeTable Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeTable(
        UObject *WorldContextObject,
        bool &success,
        FDescribeTableRequest describeTableRequest,
        FDescribeTableResult &describeTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeTableAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeTableAction(this->awsDynamoDBClient,
                success,
                describeTableRequest,
                describeTableResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeTableReplicaAutoScalingAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeTableReplicaAutoScalingResult &describeTableReplicaAutoScalingResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeTableReplicaAutoScalingOutcomeCallable callable;

public:
    FDescribeTableReplicaAutoScalingAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDescribeTableReplicaAutoScalingRequest describeTableReplicaAutoScalingRequest,
        FDescribeTableReplicaAutoScalingResult &describeTableReplicaAutoScalingResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeTableReplicaAutoScalingResult(describeTableReplicaAutoScalingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeTableReplicaAutoScalingCallable(describeTableReplicaAutoScalingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeTableReplicaAutoScalingOutcome = callable.get();

            success = awsDescribeTableReplicaAutoScalingOutcome.IsSuccess();
                if (success) {
                    describeTableReplicaAutoScalingResult.fromAWS(awsDescribeTableReplicaAutoScalingOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeTableReplicaAutoScalingOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeTableReplicaAutoScaling error: " + awsDescribeTableReplicaAutoScalingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeTableReplicaAutoScaling Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeTableReplicaAutoScaling(
        UObject *WorldContextObject,
        bool &success,
        FDescribeTableReplicaAutoScalingRequest describeTableReplicaAutoScalingRequest,
        FDescribeTableReplicaAutoScalingResult &describeTableReplicaAutoScalingResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeTableReplicaAutoScalingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeTableReplicaAutoScalingAction(this->awsDynamoDBClient,
                success,
                describeTableReplicaAutoScalingRequest,
                describeTableReplicaAutoScalingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDescribeTimeToLiveAction : public FPendingLatentAction {
private:
    bool &success;
    FDescribeTimeToLiveResult &describeTimeToLiveResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DescribeTimeToLiveOutcomeCallable callable;

public:
    FDescribeTimeToLiveAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDescribeTimeToLiveRequest describeTimeToLiveRequest,
        FDescribeTimeToLiveResult &describeTimeToLiveResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), describeTimeToLiveResult(describeTimeToLiveResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DescribeTimeToLiveCallable(describeTimeToLiveRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDescribeTimeToLiveOutcome = callable.get();

            success = awsDescribeTimeToLiveOutcome.IsSuccess();
                if (success) {
                    describeTimeToLiveResult.fromAWS(awsDescribeTimeToLiveOutcome.GetResult());
                }

                errorType = fromAWS(awsDescribeTimeToLiveOutcome.GetError().GetErrorType());
                errorMessage = ("DescribeTimeToLive error: " + awsDescribeTimeToLiveOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DescribeTimeToLive Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DescribeTimeToLive(
        UObject *WorldContextObject,
        bool &success,
        FDescribeTimeToLiveRequest describeTimeToLiveRequest,
        FDescribeTimeToLiveResult &describeTimeToLiveResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDescribeTimeToLiveAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDescribeTimeToLiveAction(this->awsDynamoDBClient,
                success,
                describeTimeToLiveRequest,
                describeTimeToLiveResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FDisableKinesisStreamingDestinationAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBDisableKinesisStreamingDestinationResult &disableKinesisStreamingDestinationResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::DisableKinesisStreamingDestinationOutcomeCallable callable;

public:
    FDisableKinesisStreamingDestinationAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBDisableKinesisStreamingDestinationRequest disableKinesisStreamingDestinationRequest,
        FAWSDynamoDBDisableKinesisStreamingDestinationResult &disableKinesisStreamingDestinationResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), disableKinesisStreamingDestinationResult(disableKinesisStreamingDestinationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->DisableKinesisStreamingDestinationCallable(disableKinesisStreamingDestinationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsDisableKinesisStreamingDestinationOutcome = callable.get();

            success = awsDisableKinesisStreamingDestinationOutcome.IsSuccess();
                if (success) {
                    disableKinesisStreamingDestinationResult.fromAWS(awsDisableKinesisStreamingDestinationOutcome.GetResult());
                }

                errorType = fromAWS(awsDisableKinesisStreamingDestinationOutcome.GetError().GetErrorType());
                errorMessage = ("DisableKinesisStreamingDestination error: " + awsDisableKinesisStreamingDestinationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("DisableKinesisStreamingDestination Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::DisableKinesisStreamingDestination(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBDisableKinesisStreamingDestinationRequest disableKinesisStreamingDestinationRequest,
    FAWSDynamoDBDisableKinesisStreamingDestinationResult &disableKinesisStreamingDestinationResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FDisableKinesisStreamingDestinationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FDisableKinesisStreamingDestinationAction(this->awsDynamoDBClient,
                success,
                disableKinesisStreamingDestinationRequest,
                disableKinesisStreamingDestinationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FEnableKinesisStreamingDestinationAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBEnableKinesisStreamingDestinationResult &enableKinesisStreamingDestinationResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::EnableKinesisStreamingDestinationOutcomeCallable callable;

public:
    FEnableKinesisStreamingDestinationAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBEnableKinesisStreamingDestinationRequest enableKinesisStreamingDestinationRequest,
        FAWSDynamoDBEnableKinesisStreamingDestinationResult &enableKinesisStreamingDestinationResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), enableKinesisStreamingDestinationResult(enableKinesisStreamingDestinationResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->EnableKinesisStreamingDestinationCallable(enableKinesisStreamingDestinationRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsEnableKinesisStreamingDestinationOutcome = callable.get();

            success = awsEnableKinesisStreamingDestinationOutcome.IsSuccess();
                if (success) {
                    enableKinesisStreamingDestinationResult.fromAWS(awsEnableKinesisStreamingDestinationOutcome.GetResult());
                }

                errorType = fromAWS(awsEnableKinesisStreamingDestinationOutcome.GetError().GetErrorType());
                errorMessage = ("EnableKinesisStreamingDestination error: " + awsEnableKinesisStreamingDestinationOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("EnableKinesisStreamingDestination Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::EnableKinesisStreamingDestination(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBEnableKinesisStreamingDestinationRequest enableKinesisStreamingDestinationRequest,
    FAWSDynamoDBEnableKinesisStreamingDestinationResult &enableKinesisStreamingDestinationResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FEnableKinesisStreamingDestinationAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FEnableKinesisStreamingDestinationAction(this->awsDynamoDBClient,
                success,
                enableKinesisStreamingDestinationRequest,
                enableKinesisStreamingDestinationResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FExecuteStatementAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBExecuteStatementResult &executeStatementResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ExecuteStatementOutcomeCallable callable;

public:
    FExecuteStatementAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBExecuteStatementRequest executeStatementRequest,
        FAWSDynamoDBExecuteStatementResult &executeStatementResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), executeStatementResult(executeStatementResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ExecuteStatementCallable(executeStatementRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsExecuteStatementOutcome = callable.get();

            success = awsExecuteStatementOutcome.IsSuccess();
                if (success) {
                    executeStatementResult.fromAWS(awsExecuteStatementOutcome.GetResult());
                }

                errorType = fromAWS(awsExecuteStatementOutcome.GetError().GetErrorType());
                errorMessage = ("ExecuteStatement error: " + awsExecuteStatementOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ExecuteStatement Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ExecuteStatement(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBExecuteStatementRequest executeStatementRequest,
    FAWSDynamoDBExecuteStatementResult &executeStatementResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FExecuteStatementAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FExecuteStatementAction(this->awsDynamoDBClient,
                success,
                executeStatementRequest,
                executeStatementResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FExecuteTransactionAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBExecuteTransactionResult &executeTransactionResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ExecuteTransactionOutcomeCallable callable;

public:
    FExecuteTransactionAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBExecuteTransactionRequest executeTransactionRequest,
        FAWSDynamoDBExecuteTransactionResult &executeTransactionResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), executeTransactionResult(executeTransactionResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ExecuteTransactionCallable(executeTransactionRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsExecuteTransactionOutcome = callable.get();

            success = awsExecuteTransactionOutcome.IsSuccess();
                if (success) {
                    executeTransactionResult.fromAWS(awsExecuteTransactionOutcome.GetResult());
                }

                errorType = fromAWS(awsExecuteTransactionOutcome.GetError().GetErrorType());
                errorMessage = ("ExecuteTransaction error: " + awsExecuteTransactionOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ExecuteTransaction Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ExecuteTransaction(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBExecuteTransactionRequest executeTransactionRequest,
    FAWSDynamoDBExecuteTransactionResult &executeTransactionResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FExecuteTransactionAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FExecuteTransactionAction(this->awsDynamoDBClient,
                success,
                executeTransactionRequest,
                executeTransactionResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FExportTableToPointInTimeAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBExportTableToPointInTimeResult &exportTableToPointInTimeResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ExportTableToPointInTimeOutcomeCallable callable;

public:
    FExportTableToPointInTimeAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBExportTableToPointInTimeRequest exportTableToPointInTimeRequest,
        FAWSDynamoDBExportTableToPointInTimeResult &exportTableToPointInTimeResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), exportTableToPointInTimeResult(exportTableToPointInTimeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ExportTableToPointInTimeCallable(exportTableToPointInTimeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsExportTableToPointInTimeOutcome = callable.get();

            success = awsExportTableToPointInTimeOutcome.IsSuccess();
                if (success) {
                    exportTableToPointInTimeResult.fromAWS(awsExportTableToPointInTimeOutcome.GetResult());
                }

                errorType = fromAWS(awsExportTableToPointInTimeOutcome.GetError().GetErrorType());
                errorMessage = ("ExportTableToPointInTime error: " + awsExportTableToPointInTimeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ExportTableToPointInTime Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ExportTableToPointInTime(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBExportTableToPointInTimeRequest exportTableToPointInTimeRequest,
    FAWSDynamoDBExportTableToPointInTimeResult &exportTableToPointInTimeResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FExportTableToPointInTimeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FExportTableToPointInTimeAction(this->awsDynamoDBClient,
                success,
                exportTableToPointInTimeRequest,
                exportTableToPointInTimeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FGetItemAction : public FPendingLatentAction {
private:
    bool &success;
    FGetItemResult &getItemResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::GetItemOutcomeCallable callable;

public:
    FGetItemAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FGetItemRequest getItemRequest,
        FGetItemResult &getItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), getItemResult(getItemResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->GetItemCallable(getItemRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsGetItemOutcome = callable.get();

            success = awsGetItemOutcome.IsSuccess();
                if (success) {
                    getItemResult.fromAWS(awsGetItemOutcome.GetResult());
                }

                errorType = fromAWS(awsGetItemOutcome.GetError().GetErrorType());
                errorMessage = ("GetItem error: " + awsGetItemOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("GetItem Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::GetItem(
        UObject *WorldContextObject,
        bool &success,
        FGetItemRequest getItemRequest,
        FGetItemResult &getItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FGetItemAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FGetItemAction(this->awsDynamoDBClient,
                success,
                getItemRequest,
                getItemResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FImportTableAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBImportTableResult &importTableResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ImportTableOutcomeCallable callable;

public:
    FImportTableAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBImportTableRequest importTableRequest,
        FAWSDynamoDBImportTableResult &importTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), importTableResult(importTableResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ImportTableCallable(importTableRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsImportTableOutcome = callable.get();

            success = awsImportTableOutcome.IsSuccess();
                if (success) {
                    importTableResult.fromAWS(awsImportTableOutcome.GetResult());
                }

                errorType = fromAWS(awsImportTableOutcome.GetError().GetErrorType());
                errorMessage = ("ImportTable error: " + awsImportTableOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ImportTable Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ImportTable(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBImportTableRequest importTableRequest,
    FAWSDynamoDBImportTableResult &importTableResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FImportTableAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FImportTableAction(this->awsDynamoDBClient,
                success,
                importTableRequest,
                importTableResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FListBackupsAction : public FPendingLatentAction {
private:
    bool &success;
    FListBackupsResult &listBackupsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ListBackupsOutcomeCallable callable;

public:
    FListBackupsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FListBackupsRequest listBackupsRequest,
        FListBackupsResult &listBackupsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listBackupsResult(listBackupsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ListBackupsCallable(listBackupsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListBackupsOutcome = callable.get();

            success = awsListBackupsOutcome.IsSuccess();
                if (success) {
                    listBackupsResult.fromAWS(awsListBackupsOutcome.GetResult());
                }

                errorType = fromAWS(awsListBackupsOutcome.GetError().GetErrorType());
                errorMessage = ("ListBackups error: " + awsListBackupsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListBackups Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ListBackups(
        UObject *WorldContextObject,
        bool &success,
        FListBackupsRequest listBackupsRequest,
        FListBackupsResult &listBackupsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListBackupsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListBackupsAction(this->awsDynamoDBClient,
                success,
                listBackupsRequest,
                listBackupsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FListContributorInsightsAction : public FPendingLatentAction {
private:
    bool &success;
    FListContributorInsightsResult &listContributorInsightsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ListContributorInsightsOutcomeCallable callable;

public:
    FListContributorInsightsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FListContributorInsightsRequest listContributorInsightsRequest,
        FListContributorInsightsResult &listContributorInsightsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listContributorInsightsResult(listContributorInsightsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ListContributorInsightsCallable(listContributorInsightsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListContributorInsightsOutcome = callable.get();

            success = awsListContributorInsightsOutcome.IsSuccess();
                if (success) {
                    listContributorInsightsResult.fromAWS(awsListContributorInsightsOutcome.GetResult());
                }

                errorType = fromAWS(awsListContributorInsightsOutcome.GetError().GetErrorType());
                errorMessage = ("ListContributorInsights error: " + awsListContributorInsightsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListContributorInsights Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ListContributorInsights(
        UObject *WorldContextObject,
        bool &success,
        FListContributorInsightsRequest listContributorInsightsRequest,
        FListContributorInsightsResult &listContributorInsightsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListContributorInsightsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListContributorInsightsAction(this->awsDynamoDBClient,
                success,
                listContributorInsightsRequest,
                listContributorInsightsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FListExportsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBListExportsResult &listExportsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ListExportsOutcomeCallable callable;

public:
    FListExportsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBListExportsRequest listExportsRequest,
        FAWSDynamoDBListExportsResult &listExportsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listExportsResult(listExportsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ListExportsCallable(listExportsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListExportsOutcome = callable.get();

            success = awsListExportsOutcome.IsSuccess();
                if (success) {
                    listExportsResult.fromAWS(awsListExportsOutcome.GetResult());
                }

                errorType = fromAWS(awsListExportsOutcome.GetError().GetErrorType());
                errorMessage = ("ListExports error: " + awsListExportsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListExports Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ListExports(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBListExportsRequest listExportsRequest,
    FAWSDynamoDBListExportsResult &listExportsResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListExportsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListExportsAction(this->awsDynamoDBClient,
                success,
                listExportsRequest,
                listExportsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FListGlobalTablesAction : public FPendingLatentAction {
private:
    bool &success;
    FListGlobalTablesResult &listGlobalTablesResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ListGlobalTablesOutcomeCallable callable;

public:
    FListGlobalTablesAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FListGlobalTablesRequest listGlobalTablesRequest,
        FListGlobalTablesResult &listGlobalTablesResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listGlobalTablesResult(listGlobalTablesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ListGlobalTablesCallable(listGlobalTablesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListGlobalTablesOutcome = callable.get();

            success = awsListGlobalTablesOutcome.IsSuccess();
                if (success) {
                    listGlobalTablesResult.fromAWS(awsListGlobalTablesOutcome.GetResult());
                }

                errorType = fromAWS(awsListGlobalTablesOutcome.GetError().GetErrorType());
                errorMessage = ("ListGlobalTables error: " + awsListGlobalTablesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListGlobalTables Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ListGlobalTables(
        UObject *WorldContextObject,
        bool &success,
        FListGlobalTablesRequest listGlobalTablesRequest,
        FListGlobalTablesResult &listGlobalTablesResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListGlobalTablesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListGlobalTablesAction(this->awsDynamoDBClient,
                success,
                listGlobalTablesRequest,
                listGlobalTablesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FListImportsAction : public FPendingLatentAction {
private:
    bool &success;
    FAWSDynamoDBListImportsResult &listImportsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ListImportsOutcomeCallable callable;

public:
    FListImportsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FAWSDynamoDBListImportsRequest listImportsRequest,
        FAWSDynamoDBListImportsResult &listImportsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listImportsResult(listImportsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ListImportsCallable(listImportsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListImportsOutcome = callable.get();

            success = awsListImportsOutcome.IsSuccess();
                if (success) {
                    listImportsResult.fromAWS(awsListImportsOutcome.GetResult());
                }

                errorType = fromAWS(awsListImportsOutcome.GetError().GetErrorType());
                errorMessage = ("ListImports error: " + awsListImportsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListImports Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ListImports(
    UObject *WorldContextObject,
    bool &success,
    FAWSDynamoDBListImportsRequest listImportsRequest,
    FAWSDynamoDBListImportsResult &listImportsResult,
    EDynamoDBError &errorType,
    FString &errorMessage,
    struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListImportsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListImportsAction(this->awsDynamoDBClient,
                success,
                listImportsRequest,
                listImportsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FListTablesAction : public FPendingLatentAction {
private:
    bool &success;
    FListTablesResult &listTablesResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ListTablesOutcomeCallable callable;

public:
    FListTablesAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FListTablesRequest listTablesRequest,
        FListTablesResult &listTablesResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listTablesResult(listTablesResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ListTablesCallable(listTablesRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListTablesOutcome = callable.get();

            success = awsListTablesOutcome.IsSuccess();
                if (success) {
                    listTablesResult.fromAWS(awsListTablesOutcome.GetResult());
                }

                errorType = fromAWS(awsListTablesOutcome.GetError().GetErrorType());
                errorMessage = ("ListTables error: " + awsListTablesOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListTables Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ListTables(
        UObject *WorldContextObject,
        bool &success,
        FListTablesRequest listTablesRequest,
        FListTablesResult &listTablesResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListTablesAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListTablesAction(this->awsDynamoDBClient,
                success,
                listTablesRequest,
                listTablesResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FListTagsOfResourceAction : public FPendingLatentAction {
private:
    bool &success;
    FListTagsOfResourceResult &listTagsOfResourceResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ListTagsOfResourceOutcomeCallable callable;

public:
    FListTagsOfResourceAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FListTagsOfResourceRequest listTagsOfResourceRequest,
        FListTagsOfResourceResult &listTagsOfResourceResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), listTagsOfResourceResult(listTagsOfResourceResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ListTagsOfResourceCallable(listTagsOfResourceRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsListTagsOfResourceOutcome = callable.get();

            success = awsListTagsOfResourceOutcome.IsSuccess();
                if (success) {
                    listTagsOfResourceResult.fromAWS(awsListTagsOfResourceOutcome.GetResult());
                }

                errorType = fromAWS(awsListTagsOfResourceOutcome.GetError().GetErrorType());
                errorMessage = ("ListTagsOfResource error: " + awsListTagsOfResourceOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("ListTagsOfResource Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::ListTagsOfResource(
        UObject *WorldContextObject,
        bool &success,
        FListTagsOfResourceRequest listTagsOfResourceRequest,
        FListTagsOfResourceResult &listTagsOfResourceResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FListTagsOfResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FListTagsOfResourceAction(this->awsDynamoDBClient,
                success,
                listTagsOfResourceRequest,
                listTagsOfResourceResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FPutItemAction : public FPendingLatentAction {
private:
    bool &success;
    FPutItemResult &putItemResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::PutItemOutcomeCallable callable;

public:
    FPutItemAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FPutItemRequest putItemRequest,
        FPutItemResult &putItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), putItemResult(putItemResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->PutItemCallable(putItemRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsPutItemOutcome = callable.get();

            success = awsPutItemOutcome.IsSuccess();
                if (success) {
                    putItemResult.fromAWS(awsPutItemOutcome.GetResult());
                }

                errorType = fromAWS(awsPutItemOutcome.GetError().GetErrorType());
                errorMessage = ("PutItem error: " + awsPutItemOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("PutItem Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::PutItem(
        UObject *WorldContextObject,
        bool &success,
        FPutItemRequest putItemRequest,
        FPutItemResult &putItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FPutItemAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FPutItemAction(this->awsDynamoDBClient,
                success,
                putItemRequest,
                putItemResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FQueryAction : public FPendingLatentAction {
private:
    bool &success;
    FQueryResult &queryResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::QueryOutcomeCallable callable;

public:
    FQueryAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FQueryRequest queryRequest,
        FQueryResult &queryResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), queryResult(queryResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->QueryCallable(queryRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsQueryOutcome = callable.get();

            success = awsQueryOutcome.IsSuccess();
                if (success) {
                    queryResult.fromAWS(awsQueryOutcome.GetResult());
                }

                errorType = fromAWS(awsQueryOutcome.GetError().GetErrorType());
                errorMessage = ("Query error: " + awsQueryOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("Query Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::Query(
        UObject *WorldContextObject,
        bool &success,
        FQueryRequest queryRequest,
        FQueryResult &queryResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FQueryAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FQueryAction(this->awsDynamoDBClient,
                success,
                queryRequest,
                queryResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FRestoreTableFromBackupAction : public FPendingLatentAction {
private:
    bool &success;
    FRestoreTableFromBackupResult &restoreTableFromBackupResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::RestoreTableFromBackupOutcomeCallable callable;

public:
    FRestoreTableFromBackupAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FRestoreTableFromBackupRequest restoreTableFromBackupRequest,
        FRestoreTableFromBackupResult &restoreTableFromBackupResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), restoreTableFromBackupResult(restoreTableFromBackupResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->RestoreTableFromBackupCallable(restoreTableFromBackupRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsRestoreTableFromBackupOutcome = callable.get();

            success = awsRestoreTableFromBackupOutcome.IsSuccess();
                if (success) {
                    restoreTableFromBackupResult.fromAWS(awsRestoreTableFromBackupOutcome.GetResult());
                }

                errorType = fromAWS(awsRestoreTableFromBackupOutcome.GetError().GetErrorType());
                errorMessage = ("RestoreTableFromBackup error: " + awsRestoreTableFromBackupOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RestoreTableFromBackup Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::RestoreTableFromBackup(
        UObject *WorldContextObject,
        bool &success,
        FRestoreTableFromBackupRequest restoreTableFromBackupRequest,
        FRestoreTableFromBackupResult &restoreTableFromBackupResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRestoreTableFromBackupAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRestoreTableFromBackupAction(this->awsDynamoDBClient,
                success,
                restoreTableFromBackupRequest,
                restoreTableFromBackupResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FRestoreTableToPointInTimeAction : public FPendingLatentAction {
private:
    bool &success;
    FRestoreTableToPointInTimeResult &restoreTableToPointInTimeResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::RestoreTableToPointInTimeOutcomeCallable callable;

public:
    FRestoreTableToPointInTimeAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FRestoreTableToPointInTimeRequest restoreTableToPointInTimeRequest,
        FRestoreTableToPointInTimeResult &restoreTableToPointInTimeResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), restoreTableToPointInTimeResult(restoreTableToPointInTimeResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->RestoreTableToPointInTimeCallable(restoreTableToPointInTimeRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsRestoreTableToPointInTimeOutcome = callable.get();

            success = awsRestoreTableToPointInTimeOutcome.IsSuccess();
                if (success) {
                    restoreTableToPointInTimeResult.fromAWS(awsRestoreTableToPointInTimeOutcome.GetResult());
                }

                errorType = fromAWS(awsRestoreTableToPointInTimeOutcome.GetError().GetErrorType());
                errorMessage = ("RestoreTableToPointInTime error: " + awsRestoreTableToPointInTimeOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("RestoreTableToPointInTime Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::RestoreTableToPointInTime(
        UObject *WorldContextObject,
        bool &success,
        FRestoreTableToPointInTimeRequest restoreTableToPointInTimeRequest,
        FRestoreTableToPointInTimeResult &restoreTableToPointInTimeResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FRestoreTableToPointInTimeAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FRestoreTableToPointInTimeAction(this->awsDynamoDBClient,
                success,
                restoreTableToPointInTimeRequest,
                restoreTableToPointInTimeResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FScanAction : public FPendingLatentAction {
private:
    bool &success;
    FScanResult &scanResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::ScanOutcomeCallable callable;

public:
    FScanAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FScanRequest scanRequest,
        FScanResult &scanResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), scanResult(scanResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->ScanCallable(scanRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsScanOutcome = callable.get();

            success = awsScanOutcome.IsSuccess();
                if (success) {
                    scanResult.fromAWS(awsScanOutcome.GetResult());
                }

                errorType = fromAWS(awsScanOutcome.GetError().GetErrorType());
                errorMessage = ("Scan error: " + awsScanOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("Scan Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::Scan(
        UObject *WorldContextObject,
        bool &success,
        FScanRequest scanRequest,
        FScanResult &scanResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FScanAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FScanAction(this->awsDynamoDBClient,
                success,
                scanRequest,
                scanResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FTagResourceAction : public FPendingLatentAction {
private:
    bool &success;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::TagResourceOutcomeCallable callable;

public:
    FTagResourceAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDynamoDBTagResourceRequest tagResourceRequest,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->TagResourceCallable(tagResourceRequest.toAWS());
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
UDynamoDBClientObject::TagResource(
        UObject *WorldContextObject,
        bool &success,
        FDynamoDBTagResourceRequest tagResourceRequest,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FTagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FTagResourceAction(this->awsDynamoDBClient,
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
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FTransactGetItemsAction : public FPendingLatentAction {
private:
    bool &success;
    FTransactGetItemsResult &transactGetItemsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::TransactGetItemsOutcomeCallable callable;

public:
    FTransactGetItemsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FTransactGetItemsRequest transactGetItemsRequest,
        FTransactGetItemsResult &transactGetItemsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), transactGetItemsResult(transactGetItemsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->TransactGetItemsCallable(transactGetItemsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsTransactGetItemsOutcome = callable.get();

            success = awsTransactGetItemsOutcome.IsSuccess();
                if (success) {
                    transactGetItemsResult.fromAWS(awsTransactGetItemsOutcome.GetResult());
                }

                errorType = fromAWS(awsTransactGetItemsOutcome.GetError().GetErrorType());
                errorMessage = ("TransactGetItems error: " + awsTransactGetItemsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("TransactGetItems Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::TransactGetItems(
        UObject *WorldContextObject,
        bool &success,
        FTransactGetItemsRequest transactGetItemsRequest,
        FTransactGetItemsResult &transactGetItemsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FTransactGetItemsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FTransactGetItemsAction(this->awsDynamoDBClient,
                success,
                transactGetItemsRequest,
                transactGetItemsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FTransactWriteItemsAction : public FPendingLatentAction {
private:
    bool &success;
    FTransactWriteItemsResult &transactWriteItemsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::TransactWriteItemsOutcomeCallable callable;

public:
    FTransactWriteItemsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FTransactWriteItemsRequest transactWriteItemsRequest,
        FTransactWriteItemsResult &transactWriteItemsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), transactWriteItemsResult(transactWriteItemsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->TransactWriteItemsCallable(transactWriteItemsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsTransactWriteItemsOutcome = callable.get();

            success = awsTransactWriteItemsOutcome.IsSuccess();
                if (success) {
                    transactWriteItemsResult.fromAWS(awsTransactWriteItemsOutcome.GetResult());
                }

                errorType = fromAWS(awsTransactWriteItemsOutcome.GetError().GetErrorType());
                errorMessage = ("TransactWriteItems error: " + awsTransactWriteItemsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("TransactWriteItems Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::TransactWriteItems(
        UObject *WorldContextObject,
        bool &success,
        FTransactWriteItemsRequest transactWriteItemsRequest,
        FTransactWriteItemsResult &transactWriteItemsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FTransactWriteItemsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FTransactWriteItemsAction(this->awsDynamoDBClient,
                success,
                transactWriteItemsRequest,
                transactWriteItemsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FUntagResourceAction : public FPendingLatentAction {
private:
    bool &success;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::UntagResourceOutcomeCallable callable;

public:
    FUntagResourceAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FDynamoDBUntagResourceRequest untagResourceRequest,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->UntagResourceCallable(untagResourceRequest.toAWS());
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
UDynamoDBClientObject::UntagResource(
        UObject *WorldContextObject,
        bool &success,
        FDynamoDBUntagResourceRequest untagResourceRequest,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUntagResourceAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUntagResourceAction(this->awsDynamoDBClient,
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
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FUpdateContinuousBackupsAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateContinuousBackupsResult &updateContinuousBackupsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::UpdateContinuousBackupsOutcomeCallable callable;

public:
    FUpdateContinuousBackupsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FUpdateContinuousBackupsRequest updateContinuousBackupsRequest,
        FUpdateContinuousBackupsResult &updateContinuousBackupsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateContinuousBackupsResult(updateContinuousBackupsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->UpdateContinuousBackupsCallable(updateContinuousBackupsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateContinuousBackupsOutcome = callable.get();

            success = awsUpdateContinuousBackupsOutcome.IsSuccess();
                if (success) {
                    updateContinuousBackupsResult.fromAWS(awsUpdateContinuousBackupsOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateContinuousBackupsOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateContinuousBackups error: " + awsUpdateContinuousBackupsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateContinuousBackups Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::UpdateContinuousBackups(
        UObject *WorldContextObject,
        bool &success,
        FUpdateContinuousBackupsRequest updateContinuousBackupsRequest,
        FUpdateContinuousBackupsResult &updateContinuousBackupsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateContinuousBackupsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateContinuousBackupsAction(this->awsDynamoDBClient,
                success,
                updateContinuousBackupsRequest,
                updateContinuousBackupsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FUpdateContributorInsightsAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateContributorInsightsResult &updateContributorInsightsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::UpdateContributorInsightsOutcomeCallable callable;

public:
    FUpdateContributorInsightsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FUpdateContributorInsightsRequest updateContributorInsightsRequest,
        FUpdateContributorInsightsResult &updateContributorInsightsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateContributorInsightsResult(updateContributorInsightsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->UpdateContributorInsightsCallable(updateContributorInsightsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateContributorInsightsOutcome = callable.get();

            success = awsUpdateContributorInsightsOutcome.IsSuccess();
                if (success) {
                    updateContributorInsightsResult.fromAWS(awsUpdateContributorInsightsOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateContributorInsightsOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateContributorInsights error: " + awsUpdateContributorInsightsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateContributorInsights Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::UpdateContributorInsights(
        UObject *WorldContextObject,
        bool &success,
        FUpdateContributorInsightsRequest updateContributorInsightsRequest,
        FUpdateContributorInsightsResult &updateContributorInsightsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateContributorInsightsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateContributorInsightsAction(this->awsDynamoDBClient,
                success,
                updateContributorInsightsRequest,
                updateContributorInsightsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FUpdateGlobalTableAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateGlobalTableResult &updateGlobalTableResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::UpdateGlobalTableOutcomeCallable callable;

public:
    FUpdateGlobalTableAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FUpdateGlobalTableRequest updateGlobalTableRequest,
        FUpdateGlobalTableResult &updateGlobalTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateGlobalTableResult(updateGlobalTableResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->UpdateGlobalTableCallable(updateGlobalTableRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateGlobalTableOutcome = callable.get();

            success = awsUpdateGlobalTableOutcome.IsSuccess();
                if (success) {
                    updateGlobalTableResult.fromAWS(awsUpdateGlobalTableOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateGlobalTableOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateGlobalTable error: " + awsUpdateGlobalTableOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateGlobalTable Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::UpdateGlobalTable(
        UObject *WorldContextObject,
        bool &success,
        FUpdateGlobalTableRequest updateGlobalTableRequest,
        FUpdateGlobalTableResult &updateGlobalTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateGlobalTableAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateGlobalTableAction(this->awsDynamoDBClient,
                success,
                updateGlobalTableRequest,
                updateGlobalTableResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FUpdateGlobalTableSettingsAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateGlobalTableSettingsResult &updateGlobalTableSettingsResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::UpdateGlobalTableSettingsOutcomeCallable callable;

public:
    FUpdateGlobalTableSettingsAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FUpdateGlobalTableSettingsRequest updateGlobalTableSettingsRequest,
        FUpdateGlobalTableSettingsResult &updateGlobalTableSettingsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateGlobalTableSettingsResult(updateGlobalTableSettingsResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->UpdateGlobalTableSettingsCallable(updateGlobalTableSettingsRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateGlobalTableSettingsOutcome = callable.get();

            success = awsUpdateGlobalTableSettingsOutcome.IsSuccess();
                if (success) {
                    updateGlobalTableSettingsResult.fromAWS(awsUpdateGlobalTableSettingsOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateGlobalTableSettingsOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateGlobalTableSettings error: " + awsUpdateGlobalTableSettingsOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateGlobalTableSettings Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::UpdateGlobalTableSettings(
        UObject *WorldContextObject,
        bool &success,
        FUpdateGlobalTableSettingsRequest updateGlobalTableSettingsRequest,
        FUpdateGlobalTableSettingsResult &updateGlobalTableSettingsResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateGlobalTableSettingsAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateGlobalTableSettingsAction(this->awsDynamoDBClient,
                success,
                updateGlobalTableSettingsRequest,
                updateGlobalTableSettingsResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FUpdateItemAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateItemResult &updateItemResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::UpdateItemOutcomeCallable callable;

public:
    FUpdateItemAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FUpdateItemRequest updateItemRequest,
        FUpdateItemResult &updateItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateItemResult(updateItemResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->UpdateItemCallable(updateItemRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateItemOutcome = callable.get();

            success = awsUpdateItemOutcome.IsSuccess();
                if (success) {
                    updateItemResult.fromAWS(awsUpdateItemOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateItemOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateItem error: " + awsUpdateItemOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateItem Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::UpdateItem(
        UObject *WorldContextObject,
        bool &success,
        FUpdateItemRequest updateItemRequest,
        FUpdateItemResult &updateItemResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateItemAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateItemAction(this->awsDynamoDBClient,
                success,
                updateItemRequest,
                updateItemResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FUpdateTableAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateTableResult &updateTableResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::UpdateTableOutcomeCallable callable;

public:
    FUpdateTableAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FUpdateTableRequest updateTableRequest,
        FUpdateTableResult &updateTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateTableResult(updateTableResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->UpdateTableCallable(updateTableRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateTableOutcome = callable.get();

            success = awsUpdateTableOutcome.IsSuccess();
                if (success) {
                    updateTableResult.fromAWS(awsUpdateTableOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateTableOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateTable error: " + awsUpdateTableOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateTable Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::UpdateTable(
        UObject *WorldContextObject,
        bool &success,
        FUpdateTableRequest updateTableRequest,
        FUpdateTableResult &updateTableResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateTableAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateTableAction(this->awsDynamoDBClient,
                success,
                updateTableRequest,
                updateTableResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FUpdateTableReplicaAutoScalingAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateTableReplicaAutoScalingResult &updateTableReplicaAutoScalingResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::UpdateTableReplicaAutoScalingOutcomeCallable callable;

public:
    FUpdateTableReplicaAutoScalingAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FUpdateTableReplicaAutoScalingRequest updateTableReplicaAutoScalingRequest,
        FUpdateTableReplicaAutoScalingResult &updateTableReplicaAutoScalingResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateTableReplicaAutoScalingResult(updateTableReplicaAutoScalingResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->UpdateTableReplicaAutoScalingCallable(updateTableReplicaAutoScalingRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateTableReplicaAutoScalingOutcome = callable.get();

            success = awsUpdateTableReplicaAutoScalingOutcome.IsSuccess();
                if (success) {
                    updateTableReplicaAutoScalingResult.fromAWS(awsUpdateTableReplicaAutoScalingOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateTableReplicaAutoScalingOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateTableReplicaAutoScaling error: " + awsUpdateTableReplicaAutoScalingOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateTableReplicaAutoScaling Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::UpdateTableReplicaAutoScaling(
        UObject *WorldContextObject,
        bool &success,
        FUpdateTableReplicaAutoScalingRequest updateTableReplicaAutoScalingRequest,
        FUpdateTableReplicaAutoScalingResult &updateTableReplicaAutoScalingResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateTableReplicaAutoScalingAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateTableReplicaAutoScalingAction(this->awsDynamoDBClient,
                success,
                updateTableReplicaAutoScalingRequest,
                updateTableReplicaAutoScalingResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

class FUpdateTimeToLiveAction : public FPendingLatentAction {
private:
    bool &success;
    FUpdateTimeToLiveResult &updateTimeToLiveResult;
    EDynamoDBError &errorType;
    FString &errorMessage;
    FName ExecutionFunction;
    int32 OutputLink;
    FWeakObjectPtr CallbackTarget;

    Aws::DynamoDB::Model::UpdateTimeToLiveOutcomeCallable callable;

public:
    FUpdateTimeToLiveAction(
        Aws::DynamoDB::DynamoDBClient *DynamoDBClient,
        bool &success,
        FUpdateTimeToLiveRequest updateTimeToLiveRequest,
        FUpdateTimeToLiveResult &updateTimeToLiveResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        const FLatentActionInfo &LatentInfo
    )
    : success(success), updateTimeToLiveResult(updateTimeToLiveResult), errorType(errorType), errorMessage(errorMessage),
    ExecutionFunction(LatentInfo.ExecutionFunction),
    OutputLink(LatentInfo.Linkage), CallbackTarget(LatentInfo.CallbackTarget) {

        callable = DynamoDBClient->UpdateTimeToLiveCallable(updateTimeToLiveRequest.toAWS());
    }

    void UpdateOperation(FLatentResponse &Response) override {
        if (callable.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
            auto awsUpdateTimeToLiveOutcome = callable.get();

            success = awsUpdateTimeToLiveOutcome.IsSuccess();
                if (success) {
                    updateTimeToLiveResult.fromAWS(awsUpdateTimeToLiveOutcome.GetResult());
                }

                errorType = fromAWS(awsUpdateTimeToLiveOutcome.GetError().GetErrorType());
                errorMessage = ("UpdateTimeToLive error: " + awsUpdateTimeToLiveOutcome.GetError().GetMessage()).c_str();

            Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
        } else {
            Response.FinishAndTriggerIf(false, ExecutionFunction, OutputLink, CallbackTarget);
        }
    }

#if WITH_EDITOR

    // Returns a human readable description of the latent operation's current state
    FString GetDescription() const override {
        return FString("UpdateTimeToLive Request");
    }

#endif
};

#endif

void
UDynamoDBClientObject::UpdateTimeToLive(
        UObject *WorldContextObject,
        bool &success,
        FUpdateTimeToLiveRequest updateTimeToLiveRequest,
        FUpdateTimeToLiveResult &updateTimeToLiveResult,
        EDynamoDBError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
) {
#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
    // Prepare latent action
    if (UWorld *World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::Assert)) {
        FLatentActionManager &LatentActionManager = World->GetLatentActionManager();
        if (LatentActionManager.FindExistingAction<FUpdateTimeToLiveAction>(LatentInfo.CallbackTarget, LatentInfo.UUID) == NULL) {
            LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
                new FUpdateTimeToLiveAction(this->awsDynamoDBClient,
                success,
                updateTimeToLiveRequest,
                updateTimeToLiveResult,
                errorType,
                errorMessage,
                LatentInfo));
        }
    }
    return;
#endif
    return;
}