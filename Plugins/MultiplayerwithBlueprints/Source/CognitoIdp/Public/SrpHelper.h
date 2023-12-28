/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, July 2021
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

#if PLATFORM_WINDOWS
#include "Windows/WindowsPlatformCompilerPreSetup.h"
#include "Windows/WindowsHWrapper.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#endif

#if PLATFORM_ANDROID
#include "Android/AndroidPlatformCompilerPreSetup.h"
#endif

#if PLATFORM_IOS
#include "IOS/IOSPlatformCompilerPreSetup.h"
#endif

#if PLATFORM_MAC
#include "Mac/MacPlatformCompilerPreSetup.h"
#endif

#if PLATFORM_APPLE
#include "Apple/ApplePlatformCompilerPreSetup.h"
#endif

#if PLATFORM_LINUX
#include "Linux/LinuxPlatformCompilerPreSetup.h"
#endif

#if PLATFORM_UNIX
#include "Unix/UnixPlatformCompilerPreSetup.h"
#endif

#define UI UI_ST
THIRD_PARTY_INCLUDES_START
#include "openssl/bn.h"
#include <string>
#include <sstream>
THIRD_PARTY_INCLUDES_END
#undef UI

#if PLATFORM_WINDOWS
#include "Windows/HideWindowsPlatformTypes.h"
#endif

#include "SrpHelper.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class COGNITOIDP_API USrpHelper : public UObject {
    GENERATED_BODY()
    
private:
    BIGNUM * bn_N_;
    BIGNUM * bn_g_;
    BIGNUM * bn_k_;
    
    BIGNUM * bn_a_;
    BIGNUM * bn_A_;

    BIGNUM * bn_random_password;

    std::string srp_A_string_;

public:
    USrpHelper();
    ~USrpHelper();
    
    UFUNCTION(BlueprintCallable, Category = "srp")
    FString ComputeSRP_A();
    
    UFUNCTION(BlueprintCallable, Category = "srp")
    FString ComputePasswordVerifier(FString &SALT, FString &RandomPassword, FString DeviceGroupKey, FString DeviceKey);

    UFUNCTION(BlueprintCallable, Category = "srp")
    FString GetRandomPassword();
    
    UFUNCTION(BlueprintCallable, Category = "srp")
    FString ComputePasswordClaimSignature(FString SECRET_BLOCK, FString SALT, FString SRP_B, FDateTime time, FString &timestamp, FString GroupKey, FString Key, FString password);
};
