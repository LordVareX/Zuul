/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK

#include "aws/cognito-idp/CognitoIdentityProviderErrors.h"

#endif

#include "CognitoIdpError.generated.h"

UENUM(BlueprintType)
enum class ECognitoIdpError : uint8 {
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

    ALIAS_EXISTS UMETA(DisplayName = "Alias Exists"),
    CODE_DELIVERY_FAILURE UMETA(DisplayName = "Code Delivery Failure"),
    CODE_MISMATCH UMETA(DisplayName = "Code Mismatch"),
    CONCURRENT_MODIFICATION UMETA(DisplayName = "Concurrent Modification"),
    DUPLICATE_PROVIDER UMETA(DisplayName = "Duplicate Provider"),
    ENABLE_SOFTWARE_TOKEN_MFA UMETA(DisplayName = "Enable Software Token MFA"),
    EXPIRED_CODE UMETA(DisplayName = "Expired Code"),
    FORBIDDEN UMETA(DisplayName = "Forbidden"),
    GROUP_EXISTS UMETA(DisplayName = "Group Exists"),
    INTERNAL_ERROR UMETA(DisplayName = "Internal Error"),
    INVALID_EMAIL_ROLE_ACCESS_POLICY UMETA(DisplayName = "Invalid Email Role Access Policy"),
    INVALID_LAMBDA_RESPONSE UMETA(DisplayName = "Invalid Lambda Response"),
    INVALID_OAUTH_FLOW UMETA(DisplayName = "Invalid OAuth Flow"),
    INVALID_PARAMETER UMETA(DisplayName = "Invalid Parameter"),
    INVALID_PASSWORD UMETA(DisplayName = "Invalid Password"),
    INVALID_SMS_ROLE_ACCESS_POLICY UMETA(DisplayName = "Invalid SMS Role Access Policy"),
    INVALID_SMS_ROLE_TRUST_RELATIONSHIP UMETA(DisplayName = "Invalid SMS Role Trust Relationship"),
    INVALID_USER_POOL_CONFIGURATION UMETA(DisplayName = "Invalid User Pool Configuration"),
    LIMIT_EXCEEDED UMETA(DisplayName = "Limit Exceeded"),
    MFA_METHOD_NOT_FOUND UMETA(DisplayName = "MFA Method Not Found"),
    NOT_AUTHORIZED UMETA(DisplayName = "Not Authorized"),
    PASSWORD_RESET_REQUIRED UMETA(DisplayName = "Password Reset Required"),
    PRECONDITION_NOT_MET UMETA(DisplayName = "Precondition Not Met"),
    SCOPE_DOES_NOT_EXIST UMETA(DisplayName = "Scope Does Not Exist"),
    SOFTWARE_TOKEN_MFA_NOT_FOUND UMETA(DisplayName = "Software Token MFA Not Found"),
    TOO_MANY_FAILED_ATTEMPTS UMETA(DisplayName = "Too Many Failed Attempts"),
    TOO_MANY_REQUESTS UMETA(DisplayName = "Too Many Requests"),
    UNAUTHORIZED UMETA(DisplayName = "Unauthorized"),
    UNEXPECTED_LAMBDA UMETA(DisplayName = "Unexpected Lambda"),
    UNSUPPORTED_IDENTITY_PROVIDER UMETA(DisplayName = "Unsupported Identity Provider"),
    UNSUPPORTED_OPERATION UMETA(DisplayName = "Unsupported Operation"),
    UNSUPPORTED_TOKEN_TYPE UMETA(DisplayName = "Unsupported token type"),
    UNSUPPORTED_USER_STATE UMETA(DisplayName = "Unsupported User State"),
    USERNAME_EXISTS UMETA(DisplayName = "Username Exists"),
    USER_IMPORT_IN_PROGRESS UMETA(DisplayName = "User Import In Progress"),
    USER_LAMBDA_VALIDATION UMETA(DisplayName = "User Lambda Validation"),
    USER_NOT_CONFIRMED UMETA(DisplayName = "User Not Confirmed"),
    USER_NOT_FOUND UMETA(DisplayName = "User Not Found"),
    USER_POOL_ADDON_NOT_ENABLED UMETA(DisplayName = "User Pool AddOn Not Enabled"),
    USER_POOL_TAGGING UMETA(DisplayName = "User Pool Tagging"),
};
