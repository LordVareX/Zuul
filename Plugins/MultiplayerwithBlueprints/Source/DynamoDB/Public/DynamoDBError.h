/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, November 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK

#include "aws/dynamodb/DynamoDBErrors.h"

#endif

#include "DynamoDBError.generated.h"

UENUM(BlueprintType)
enum class EDynamoDBError : uint8 {
    //From Core//
    //////////////////////////////////////////////////////////////////////////////////////////
    INCOMPLETE_SIGNATURE UMETA(DisplayName = "Incomplete Signature"),
    INTERNAL_FAILURE UMETA(DisplayName = "Internal Failure"),
    INVALID_ACTION UMETA(DisplayName = "Invalid Action"),
    INVALID_CLIENT_TOKEN_ID UMETA(DisplayName = "Invalid Client Token ID"),
    INVALID_PARAMETER_COMBINATION UMETA(DisplayName = "Invalid Parameter Combination"),
    INVALID_QUERY_PARAMETER UMETA(DisplayName = "Invalid Query Parameter"),
    INVALID_PARAMETER_VALUE UMETA(DisplayName = "Invalid Parameter value"),
    MISSING_ACTION UMETA(DisplayName = "Missing Action"), // SDK should never allow
    MISSING_AUTHENTICATION_TOKEN UMETA(DisplayName = "Missing Authentication"), // SDK should never allow
    MISSING_PARAMETER UMETA(DisplayName = "Missing Parameter"), // SDK should never allow
    OPT_IN_REQUIRED UMETA(DisplayName = "Opt In Required"),
    REQUEST_EXPIRED UMETA(DisplayName = "Request Expired"),
    SERVICE_UNAVAILABLE UMETA(DisplayName = "Service Unavailable"),
    THROTTLING UMETA(DisplayName = "Throttling"),
    VALIDATION UMETA(DisplayName = "Validation"),
    ACCESS_DENIED UMETA(DisplayName = "Access Denied"),
    RESOURCE_NOT_FOUND UMETA(DisplayName = "Resource Not Found"),
    UNRECOGNIZED_CLIENT UMETA(DisplayName = "Unrecognized Client"),
    MALFORMED_QUERY_STRING UMETA(DisplayName = "Malformed Query String"),
    SLOW_DOWN UMETA(DisplayName = "Slow Down"),
    REQUEST_TIME_TOO_SKEWED UMETA(DisplayName = "Request Time Too Skewed"),
    INVALID_SIGNATURE UMETA(DisplayName = "Invalid Signature"),
    SIGNATURE_DOES_NOT_MATCH UMETA(DisplayName = "Signature Does Not Match"),
    INVALID_ACCESS_KEY_ID UMETA(DisplayName = "Invalid Access Key ID"),
    REQUEST_TIMEOUT UMETA(DisplayName = "Request Timeout"),
    NETWORK_CONNECTION UMETA(DisplayName = "Network Connection"),

    UNKNOWN UMETA(DisplayName = "Unknown"),
    ///////////////////////////////////////////////////////////////////////////////////////////

    BACKUP_IN_USE UMETA(DisplayName = "Backup In Use"),
    BACKUP_NOT_FOUND UMETA(DisplayName = "Backup Not Found"),
    CONDITIONAL_CHECK_FAILED UMETA(DisplayName = "Conditional Check Failed"),
    CONTINUOUS_BACKUPS_UNAVAILABLE UMETA(DisplayName = "Continuous Backups Unavailable"),
    DUPLICATE_ITEM UMETA(DisplayName = "Duplicate Item"),
    EXPORT_CONFLICT UMETA(DisplayName = "Export Conflict"),
    EXPORT_NOT_FOUND UMETA(DisplayName = "Export Not Found"),
    GLOBAL_TABLE_ALREADY_EXISTS UMETA(DisplayName = "Global Table Already Exists"),
    GLOBAL_TABLE_NOT_FOUND UMETA(DisplayName = "Global Table Not Found"),
    IDEMPOTENT_PARAMETER_MISMATCH UMETA(DisplayName = "Idempotent Parameter Mismatch"),
    IMPORT_CONFLICT UMETA(DisplayName = "Import Conflict"),
    IMPORT_NOT_FOUND UMETA(DisplayName = "Import Not Found"),
    INDEX_NOT_FOUND UMETA(DisplayName = "Index Not Found"),
    INVALID_EXPORT_TIME UMETA(DisplayName = "Invalid Export Time"),
    INVALID_RESTORE_TIME UMETA(DisplayName = "Invalid Restore Time"),
    ITEM_COLLECTION_SIZE_LIMIT_EXCEEDED UMETA(DisplayName = "Item Collection Size Limit Exceeded"),
    LIMIT_EXCEEDED UMETA(DisplayName = "Limit Exceeded"),
    POINT_IN_TIME_RECOVERY_UNAVAILABLE UMETA(DisplayName = "Point In Time Recovery Unavailable"),
    PROVISIONED_THROUGHPUT_EXCEEDED UMETA(DisplayName = "Provisioned Throughput Exceeded"),
    REPLICA_ALREADY_EXISTS UMETA(DisplayName = "Replica Already Exists"),
    REPLICA_NOT_FOUND UMETA(DisplayName = "Replica Not Found"),
    REQUEST_LIMIT_EXCEEDED UMETA(DisplayName = "Request Limit Exceeded"),
    RESOURCE_IN_USE UMETA(DisplayName = "Resource In Use"),
    TABLE_ALREADY_EXISTS UMETA(DisplayName = "Table Already Exists"),
    TABLE_IN_USE UMETA(DisplayName = "Table In Use"),
    TABLE_NOT_FOUND UMETA(DisplayName = "Table Not Found"),
    TRANSACTION_CANCELED UMETA(DisplayName = "Transaction Canceled"),
    TRANSACTION_CONFLICT UMETA(DisplayName = "Transaction Conflict"),
    TRANSACTION_IN_PROGRESS UMETA(DisplayName = "Transaction In Progress")
};
