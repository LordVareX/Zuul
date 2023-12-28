/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/EC2UnexpectedException.h"

#endif

#include "EC2UnexpectedException.generated.h"

USTRUCT(BlueprintType)
struct FEC2UnexpectedException {
GENERATED_BODY()

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString type;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString message;

    /**
    *
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString ec2ErrorCode;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
#endif
};
