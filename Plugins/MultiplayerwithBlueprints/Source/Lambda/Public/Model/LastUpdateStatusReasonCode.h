/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "LastUpdateStatusReasonCode.generated.h"

UENUM(BlueprintType)
enum class EAWSLastUpdateStatusReasonCode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    EniLimitExceeded        UMETA(DisplayName = "enilimitexceeded"),
    InsufficientRolePermissions        UMETA(DisplayName = "insufficientrolepermissions"),
    InvalidConfiguration        UMETA(DisplayName = "invalidconfiguration"),
    InternalError        UMETA(DisplayName = "internalerror"),
    SubnetOutOfIPAddresses        UMETA(DisplayName = "subnetoutofipaddresses"),
    InvalidSubnet        UMETA(DisplayName = "invalidsubnet"),
    InvalidSecurityGroup        UMETA(DisplayName = "invalidsecuritygroup"),
    ImageDeleted        UMETA(DisplayName = "imagedeleted"),
    ImageAccessDenied        UMETA(DisplayName = "imageaccessdenied"),
    InvalidImage        UMETA(DisplayName = "invalidimage"),
    KMSKeyAccessDenied        UMETA(DisplayName = "kmskeyaccessdenied"),
    KMSKeyNotFound        UMETA(DisplayName = "kmskeynotfound"),
    InvalidStateKMSKey        UMETA(DisplayName = "invalidstatekmskey"),
    DisabledKMSKey        UMETA(DisplayName = "disabledkmskey"),
    EFSIOError        UMETA(DisplayName = "efsioerror"),
    EFSMountConnectivityError        UMETA(DisplayName = "efsmountconnectivityerror"),
    EFSMountFailure        UMETA(DisplayName = "efsmountfailure"),
    EFSMountTimeout        UMETA(DisplayName = "efsmounttimeout"),
    InvalidRuntime        UMETA(DisplayName = "invalidruntime"),
    InvalidZipFileException        UMETA(DisplayName = "invalidzipfileexception"),
    FunctionError        UMETA(DisplayName = "functionerror"),
};
