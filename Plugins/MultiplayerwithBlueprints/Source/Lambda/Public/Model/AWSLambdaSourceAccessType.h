/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSLambdaSourceAccessType.generated.h"

UENUM(BlueprintType)
enum class EAWSLambdaSourceAccessType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    BASIC_AUTH        UMETA(DisplayName = "basic auth"),
    VPC_SUBNET        UMETA(DisplayName = "vpc subnet"),
    VPC_SECURITY_GROUP        UMETA(DisplayName = "vpc security group"),
    SASL_SCRAM_512_AUTH        UMETA(DisplayName = "sasl scram 512 auth"),
    SASL_SCRAM_256_AUTH        UMETA(DisplayName = "sasl scram 256 auth"),
    VIRTUAL_HOST        UMETA(DisplayName = "virtual host"),
    CLIENT_CERTIFICATE_TLS_AUTH        UMETA(DisplayName = "client certificate tls auth"),
    SERVER_ROOT_CA_CERTIFICATE        UMETA(DisplayName = "server root ca certificate"),
};
