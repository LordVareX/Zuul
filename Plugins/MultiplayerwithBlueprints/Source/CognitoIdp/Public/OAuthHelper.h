/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, July 2021
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/LatentActionManager.h"
#include "OAuthHelper.generated.h"

/**
 * 
 */
UCLASS()
class COGNITOIDP_API UOAuthHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "CognitoIdentityProvider Client")
    static void GetToken(
            UObject *WorldContextObject,
            bool &success,
            FString cognitoDomain,
            FString scope,
            FString redirectUri,
            FString ClientId,
            FString ClientSecret,
            FString code,
            FString &accessToken,
            FString &idToken,
            FString &refreshToken,
            int32 &responseCode,
            FString &errors,
            struct FLatentActionInfo LatentInfo
            );
};
