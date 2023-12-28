/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SecretHashHelper.generated.h"

/**
 * 
 */
UCLASS()
class COGNITOIDP_API USecretHashHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure,
              meta = (DisplayName = "Compute Secret Hash", CompactNodeTitle = "Secret Hash", Keywords = "Secret Hash"),
              Category = "SecretHash")
    static FString ComputeSecretHash(FString SecretKey, FString UserName, FString ClientId);
};
