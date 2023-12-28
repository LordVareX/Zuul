/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "StateReasonCode.generated.h"

UENUM(BlueprintType)
enum class EAWSStateReasonCode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Idle        UMETA(DisplayName = "idle"),
    Creating        UMETA(DisplayName = "creating"),
    Restoring        UMETA(DisplayName = "restoring"),
    EniLimitExceeded        UMETA(DisplayName = "enilimit exceeded"),
    InsufficientRolePermissions        UMETA(DisplayName = "insufficient role permissions"),
    InvalidConfiguration        UMETA(DisplayName = "invalid configuration"),
    InternalError        UMETA(DisplayName = "internal error"),
    SubnetOutOfIPAddresses        UMETA(DisplayName = "subnet out of ip addresses"),
    InvalidSubnet        UMETA(DisplayName = "invalid subnet"),
    InvalidSecurityGroup        UMETA(DisplayName = "invalid security group"),
    ImageDeleted        UMETA(DisplayName = "image deleted"),
    ImageAccessDenied        UMETA(DisplayName = "image access denied"),
    InvalidImage        UMETA(DisplayName = "invalid image"),
    KMSKeyAccessDenied        UMETA(DisplayName = "kms key access denied"),
    KMSKeyNotFound        UMETA(DisplayName = "kms key not found"),
    InvalidStateKMSKey        UMETA(DisplayName = "invalid state kms key"),
    DisabledKMSKey        UMETA(DisplayName = "disabled kms key"),
    EFSIOError        UMETA(DisplayName = "efs io error"),
    EFSMountConnectivityError        UMETA(DisplayName = "efs mount connectivity error"),
    EFSMountFailure        UMETA(DisplayName = "efs mount failure"),
    EFSMountTimeout        UMETA(DisplayName = "efs mount timeout"),
    InvalidRuntime        UMETA(DisplayName = "invalid runtime"),
    InvalidZipFileException        UMETA(DisplayName = "invalid zip file exception"),
    FunctionError        UMETA(DisplayName = "function error"),
};
