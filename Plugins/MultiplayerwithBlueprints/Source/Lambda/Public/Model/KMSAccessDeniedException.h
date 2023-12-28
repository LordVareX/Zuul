/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/KMSAccessDeniedException.h"

#endif

#include "KMSAccessDeniedException.generated.h"

USTRUCT(BlueprintType)
struct FKMSAccessDeniedException {
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
