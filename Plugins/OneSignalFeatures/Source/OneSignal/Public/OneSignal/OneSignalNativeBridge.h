// Copyright Pandores Marketplace 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Launch/Resources/Version.h"

#if PLATFORM_IOS

@class OSNotificationAction;
@class OSDeviceState;
@class OSNotification;

#define ONESIGNAL_NATIVE_OBJECT_DEFAULT_CTOR(ClassName)													\
	inline static UOneSignal ## ClassName* FromNative(OS ## ClassName* InNative)						\
	{																									\
		ThisClass* const Wrapper = NewObject<ThisClass>();												\
		Wrapper->Native = [InNative retain];															\
		return Wrapper;																					\
	}
#define ONESIGNAL_DESTRUCTOR(ClassName)																	\
	UOneSignal ## ClassName::~UOneSignal ## ClassName()													\
	{																									\
		[Native release];																				\
		Native = nullptr;																				\
	}

#elif PLATFORM_ANDROID

#include <jni.h>
#include "Android/AndroidJavaEnv.h"

using OSNotificationAction = _jobject;
using OSDeviceState = _jobject;
using OSNotification = _jobject;

#define ONESIGNAL_NATIVE_OBJECT_DEFAULT_CTOR(ClassName)													\
	inline static UOneSignal ## ClassName* FromNative(JNIEnv* Env, OS ## ClassName* InNative)			\
	{																									\
		ThisClass* const Wrapper = NewObject<ThisClass>();												\
		Wrapper->Native = Env->NewGlobalRef(InNative);													\
		return Wrapper;																					\
	}
#define ONESIGNAL_DESTRUCTOR(ClassName)																	\
	UOneSignal ## ClassName::~UOneSignal ## ClassName()													\
	{																									\
		AndroidJavaEnv::GetJavaEnv()->DeleteGlobalRef(Native);											\
		Native = nullptr;																				\
	}
	

#else

using OSNotificationAction = void*;
using OSDeviceState = void*;
using OSNotification = void*;

#define ONESIGNAL_DESTRUCTOR(ClassName) UOneSignal ## ClassName::~UOneSignal ## ClassName() {}

#if ENGINE_MAJOR_VERSION > 5 || (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 1) // UE 5.1+
#define ONESIGNAL_NATIVE_OBJECT_DEFAULT_CTOR(ClassName)													\
	inline static UOneSignal ## ClassName* FromNative(OS ## ClassName* InNative)						\
	{																									\
		ThisClass* const Wrapper = NewObject<ThisClass>();												\
		Wrapper->Native = InNative;																		\
		return Wrapper;																					\
	}
#else
#define ONESIGNAL_NATIVE_OBJECT_DEFAULT_CTOR(ClassName)													\
	inline static UOneSignal ## ClassName* FromNative(OS ## ClassName* InNative)						\
	{																									\
		ThisClass* const Wrapper = NewObject<ThisClass>();												\
		Wrapper->Native = InNative;																		\
		return Wrapper;																					\
	}
#endif
#endif

