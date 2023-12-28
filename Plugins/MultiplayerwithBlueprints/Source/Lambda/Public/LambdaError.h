/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK

#include "aws/lambda/LambdaErrors.h"

#endif

#include "LambdaError.generated.h"

UENUM(BlueprintType)
enum class ELambdaError : uint8 {
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

    CODE_SIGNING_CONFIG_NOT_FOUND UMETA(DisplayName = "Code Signing Config Not Found"),
    CODE_STORAGE_EXCEEDED UMETA(DisplayName = "Code Storage Exceeded"),
    CODE_VERIFICATION_FAILED UMETA(DisplayName = "Code Verification Failed"),
    EC2_ACCESS_DENIED UMETA(DisplayName = "EC2 Access Denied"),
    EC2_THROTTLED UMETA(DisplayName = "EC2 Throttled"),
    EC2_UNEXPECTED UMETA(DisplayName = "EC2 Unexpected"),
    EFS_IO UMETA(DisplayName = "EFS IO"),
    EFS_MOUNT_CONNECTIVITY UMETA(DisplayName = "EFS Mount Connectivity"),
    EFS_MOUNT_FAILURE UMETA(DisplayName = "EFS Mount Failure"),
    EFS_MOUNT_TIMEOUT UMETA(DisplayName = "EFS Mount Timeout"),
    ENI_LIMIT_REACHED UMETA(DisplayName = "ENI Limit Reached"),
    INVALID_CODE_SIGNATURE UMETA(DisplayName = "Invalid Code Signature"),
    INVALID_REQUEST_CONTENT UMETA(DisplayName = "Invalid Request Content"),
    INVALID_RUNTIME UMETA(DisplayName = "Invalid Runtime"),
    INVALID_SECURITY_GROUP_ID UMETA(DisplayName = "Invalid Security Group ID"),
    INVALID_SUBNET_ID UMETA(DisplayName = "Invalid Subnet Id"),
    INVALID_ZIP_FILE UMETA(DisplayName = "Invalid ZIP File"),
    KMS_ACCESS_DENIED UMETA(DisplayName = "KMS Access Denied"),
    KMS_DISABLED UMETA(DisplayName = "KMS Disabled"),
    KMS_INVALID_STATE UMETA(DisplayName = "KMS Invalid State"),
    KMS_NOT_FOUND UMETA(DisplayName = "KMS Not Found"),
    POLICY_LENGTH_EXCEEDED UMETA(DisplayName = "Policy Length Exceeded"),
    PRECONDITION_FAILED UMETA(DisplayName = "Precondition Failed"),
    PROVISIONED_CONCURRENCY_CONFIG_NOT_FOUND UMETA(DisplayName = "Provisioned Concurrency Config Not Found"),
    REQUEST_TOO_LARGE UMETA(DisplayName = "Request Too Large"),
    RESOURCE_CONFLICT UMETA(DisplayName = "Resource Conflict"),
    RESOURCE_IN_USE UMETA(DisplayName = "Resource In Use"),
    RESOURCE_NOT_READY UMETA(DisplayName = "Resource Not Ready"),
    SERVICE UMETA(DisplayName = "Service"),
    SNAP_START UMETA(DisplayName = "Snap Start"),
    SNAP_START_NOT_READY UMETA(DisplayName = "Snap Start Not Ready"),
    SNAP_START_TIMEOUT UMETA(DisplayName = "Snap Start Timeout"),
    SUBNET_IP_ADDRESS_LIMIT_REACHED UMETA(DisplayName = "Subnet IP Address Limit Reached"),
    TOO_MANY_REQUESTS UMETA(DisplayName = "Too Many Requests"),
    UNSUPPORTED_MEDIA_TYPE UMETA(DisplayName = "Unsupported Media Type"),
};