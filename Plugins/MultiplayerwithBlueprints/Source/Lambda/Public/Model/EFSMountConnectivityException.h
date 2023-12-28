/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/EFSMountConnectivityException.h"

#endif

#include "EFSMountConnectivityException.generated.h"

USTRUCT(BlueprintType)
struct FEFSMountConnectivityException {
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

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
#endif
};
