// Copyright (c) 2022 King Wai Mark
#pragma once

#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
#pragma comment(lib,"advapi32.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"crypt32.lib")
#pragma comment(lib,"rpcrt4.lib")
#pragma comment(lib,"ole32.lib")
#pragma comment(lib,"shell32.lib")
#pragma comment(lib,"iphlpapi.lib")
#pragma comment(lib,"psapi.lib")
#pragma comment(lib,"userenv.lib")
#endif

#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
	#if !defined(_WIN32)
		#define _WIN32 1
	#endif
#elif defined(PLATFORM_ANDROID) && PLATFORM_ANDROID
	#if !defined(__ANDROID__)
		#define __ANDROID__ 1
	#endif
	#include "Android/AndroidApplication.h"
	#include "Android/AndroidJNI.h"
#elif defined(PLATFORM_MAC) && PLATFORM_MAC
	#if !defined(TARGET_OS_OSX)
		#define TARGET_OS_OSX 1
	#endif
#elif defined(PLATFORM_IOS) && PLATFORM_IOS
	#if !defined(TARGET_OS_IOS)
		#define TARGET_OS_IOS 1
	#endif
#endif

#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
	#if !defined(_WIN32_WINNT_WIN10_TH2)
		#define _WIN32_WINNT_WIN10_TH2 1
	#endif
	#if !defined(_WIN32_WINNT_WIN10_RS1)
		#define _WIN32_WINNT_WIN10_RS1 1
	#endif

	#if !defined(_WIN32_WINNT_WIN10_RS2)
		#define _WIN32_WINNT_WIN10_RS2 1
	#endif

	#if !defined(_WIN32_WINNT_WIN10_RS3)
		#define _WIN32_WINNT_WIN10_RS3 1
	#endif

	#if !defined(_WIN32_WINNT_WIN10_RS4)
		#define _WIN32_WINNT_WIN10_RS4 1
	#endif

	#if !defined(_WIN32_WINNT_WIN10_RS5)
		#define _WIN32_WINNT_WIN10_RS5 1
	#endif
#endif

#define INTERNAL_EXPERIMENTAL 0


#if (defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS) || (defined(PLATFORM_MAC) && PLATFORM_MAC) || (defined(PLATFORM_ANDROID) && PLATFORM_ANDROID)
	#include "firebase/app.h"
#elif defined(PLATFORM_IOS) && PLATFORM_IOS
	#import "Firebase.h"
	#include "firebase/app.h"
#endif

#include "FBPFileUtilities.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBPApp.generated.h"

/**
 *	Data object that represents a Firebase App object.
 *	
 *	@author  King Wai Mark
 */
USTRUCT(BlueprintType)
struct FBPAppData
{
	GENERATED_BODY()

public:

	
	UPROPERTY(BlueprintReadOnly, Category = "App - Firebase Plugin by KWM")
	FString ApiKey;

	UPROPERTY(BlueprintReadOnly, Category = "App - Firebase Plugin by KWM")
	FString AppId;

	UPROPERTY(BlueprintReadOnly, Category = "App - Firebase Plugin by KWM")
	FString DatabaseUrl;

	UPROPERTY(BlueprintReadOnly, Category = "App - Firebase Plugin by KWM")
	FString ProjectId;

	UPROPERTY(BlueprintReadOnly, Category = "App - Firebase Plugin by KWM")
	FString StorageBucket;
	
	UPROPERTY(BlueprintReadOnly, Category = "App - Firebase Plugin by KWM")
	FString MessagingSenderId;

	UPROPERTY(BlueprintReadOnly, Category = "App - Firebase Plugin by KWM")
	FString ClientId;
};


/**
 *	@author King Wai Mark
 */
UCLASS()
class FBP_API UFBPApp : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	const FString CATEGORY_FOR_UFUNCTION = "Firebase App - Firebase Plugin By KWM";
	
public:

	static firebase::App* FBPGet();
	/**
	 * Checks to see if the Google Services JSON file contains a value for Firebase URL. 
	 */
	static bool HaveDatabaseInfo(FString Msg);
	/**
	 *	Connects to Firebase.
	 *	Grabs info from a google-services.json or GoogleService-info file depending on the platform you are running on.
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Connect to Firebase", Keywords = "Connect to Firebase"), Category = "Firebase App - Firebase Plugin By KWM")
	static bool FBPConnectToFirebase();
	
	/**
	 *	Returns an App Data object that contains information about the Firebase App.
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get App Info", Keywords = "Get App Info"), Category = "Firebase App - Firebase Plugin By KWM")
	static FBPAppData FBPGetAppInfo();


};


