/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "SecretHashHelper.h"
#include "Misc/Base64.h"
#include "Misc/CString.h"
#include "Containers/UnrealString.h"

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
#include "openssl/sha.h"
#include "openssl/hmac.h"
#include "openssl/ossl_typ.h"
THIRD_PARTY_INCLUDES_END
#undef UI

#if PLATFORM_WINDOWS
#include "Windows/HideWindowsPlatformTypes.h"
#endif

FString USecretHashHelper::ComputeSecretHash(FString SecretKey, FString UserName, FString ClientId) {
    if (SecretKey.Len() > 0) {
        unsigned char *c_key = new unsigned char[SecretKey.Len() + 1];
        memcpy(c_key, (unsigned char *) TCHAR_TO_UTF8(*SecretKey), SecretKey.Len());

        FString msg = UserName + ClientId;
        unsigned char *c_msg = new unsigned char[msg.Len() + 1];
        memcpy(c_msg, (unsigned char *) TCHAR_TO_UTF8(*msg), msg.Len());

        // nintendo Switch
//        unsigned char digest[nn::crypto::Sha256Generator::HashSize];
//        nn::crypto::GenerateHmacSha256(digest, nn::crypto::Sha256Generator::HashSize, c_msg, msg.Len(), (unsigned char *) c_key, SecretKey.Len());

        unsigned char *digest = HMAC(EVP_sha256(), (unsigned char *) c_key, SecretKey.Len(), c_msg, msg.Len(), NULL,
                                     NULL);

        delete[] c_key;
        delete[] c_msg;

        return FBase64::Encode(digest, SHA256_DIGEST_LENGTH);
    } else {
        return FString();
    }
}
