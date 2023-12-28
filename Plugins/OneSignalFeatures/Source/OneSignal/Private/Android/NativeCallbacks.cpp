// Copyright Pandores Marketplace 2023. All Rights Reserved. 

#include "CoreMinimal.h"
#include "OneSignal/OneSignalLibrary.h"
#include "Async/Async.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Launch/Resources/Version.h"

#if PLATFORM_ANDROID
#	include "jni.h"
#	include "Android/AndroidJavaEnv.h"
#	include "Android/AndroidJNI.h"
#	include "Android/AndroidApplication.h"
#else // For intellisense
#   define JNIEXPORT
#   define JNICALL
    using JNIEnv = void*;
    using jobject = void*;
    using jclass = void*;
    using jmethodID = int32;
    using jstring = jobject;
    using jboolean = bool;
    using jint = int32;
    using jlong = int64;
    using jfloat = float;
    using jobjectArray = void*;
#endif

#if ENGINE_MAJOR_VERSION >= 5
#   define DECLARE_ACTIVITY_NATIVE_METHOD(name) \
        Java_com_epicgames_unreal_GameActivity_ ## name
#else
#   define DECLARE_ACTIVITY_NATIVE_METHOD(name) \
        Java_com_epicgames_ue4_GameActivity_ ## name
#endif


#define CALL_ACTIVITY_METHOD_LOCAL_ENV(Name, Signature, Type, Default, ...)													\
	[&]()																													\
	{																														\
		static jmethodID jMethod = env->GetMethodID(GetGameActivityClass(), Name, Signature);								\
																															\
		if (env->ExceptionCheck())																							\
		{																													\
			env->ExceptionDescribe();																						\
			env->ExceptionClear();																							\
			return Default;																									\
		}																													\
																															\
		return env->Call ## Type ## Method(AndroidJavaEnv::GetGameActivityThis(), jMethod, ## __VA_ARGS__);					\
	}()

extern jclass GetGameActivityClass();

extern "C"
JNIEXPORT void JNICALL
DECLARE_ACTIVITY_NATIVE_METHOD(OneSignalNativeExecuteSuccessCallback)
(JNIEnv * env, jobject thiz, jboolean bExecute, jlong Data)
{
    if (!Data)
    {
        return;
    }

    FOneSignalSuccessCallback* Callback = (FOneSignalSuccessCallback*)Data;

    if (bExecute && Callback->IsBound())
    {
        AsyncTask(ENamedThreads::GameThread, [Callback]() -> void
        {
            Callback->ExecuteIfBound();
            delete Callback;
        });
    }
    else
    {
        delete Callback;
    }
}

extern "C"
JNIEXPORT void JNICALL
DECLARE_ACTIVITY_NATIVE_METHOD(OneSignalNativeExecuteFailureCallback)
(JNIEnv * env, jobject thiz, jboolean bExecute, jlong Data, jint Code, jstring Message)
{
    if (!Data)
    {
        return;
    }
    
    FOneSignalFailureCallback* Callback = (FOneSignalFailureCallback*)Data;

    if (bExecute && Callback->IsBound())
    {
        AsyncTask(ENamedThreads::GameThread, [Callback, Code = (int32)Code, Message = FJavaHelper::FStringFromParam(env, Message)]() mutable -> void
        {
            Callback->ExecuteIfBound(Code, MoveTemp(Message));
            delete Callback;
        });
    }
    else
    {
        delete Callback;
    }
}

extern "C"
JNIEXPORT void JNICALL
DECLARE_ACTIVITY_NATIVE_METHOD(OneSignalNativeExecuteTagsSuccessCallback)
(JNIEnv * env, jobject thiz, jboolean bExecute, jlong Data, jstring StrData)
{
    if (!Data)
    {
        return;
    }

    FOneSignalTagsCallback* Callback = (FOneSignalTagsCallback*)Data;

    if (bExecute && Callback->IsBound())
    {
        FString JsonData = FJavaHelper::FStringFromParam(env, StrData);

        TMap<FString, FString> Tags;

        TSharedPtr<FJsonObject> JsonParsed;
        TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonData);
        if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
        {
            Tags.Reserve(JsonParsed->Values.Num());

            for (const auto& Value : JsonParsed->Values)
            {
                if (Value.Value->Type == EJson::String)
                {
                    Tags.Add(Value.Key, Value.Value->AsString());
                }
                else if (Value.Value->Type == EJson::Number)
                {
                    Tags.Add(Value.Key, FString::SanitizeFloat(Value.Value->AsNumber()));
                }
                else
                {
                    Tags.Add(Value.Key, TEXT("[UnknownObject]"));
                }
            }
        }

        AsyncTask(ENamedThreads::GameThread, [Callback, Tags = MoveTemp(Tags)]() mutable -> void
        {
            Callback->ExecuteIfBound(MoveTemp(Tags));
            delete Callback;
        });
    }
    else
    {
        delete Callback;
    }
}


extern "C"
JNIEXPORT void JNICALL
DECLARE_ACTIVITY_NATIVE_METHOD(OneSignalNativeExecuteOutcomeCallback)
(JNIEnv* env, jobject thiz, jlong Data, jobject OutcomeEvent)
{
    if (!Data)
    {
        return;
    }

    FOneSignalOutcomeSuccessCallback* Callback = (FOneSignalOutcomeSuccessCallback*)Data;

    if (Callback->IsBound())
    {
        FOneSignalOutcomeEvent Outcome;

        if (OutcomeEvent)
        {
            Outcome.Name = FJavaHelper::FStringFromLocalRef(env, (jstring)
                CALL_ACTIVITY_METHOD_LOCAL_ENV("AndroidThunk_OSOutcomeEvent_getName", "(Ljava/lang/Object;)Ljava/lang/String;",
                    Object, (jobject)NULL, OutcomeEvent));
            Outcome.Session = (EOneSignalInfluenceType)
                CALL_ACTIVITY_METHOD_LOCAL_ENV("AndroidThunk_OSOutcomeEvent_getSession", "(Ljava/lang/Object;)I", Int, (jint)0, OutcomeEvent);
            Outcome.Timestamp = (int64)
                CALL_ACTIVITY_METHOD_LOCAL_ENV("AndroidThunk_OSOutcomeEvent_getTimestamp", "(Ljava/lang/Object;)J", Long, (jlong)0, OutcomeEvent);
            Outcome.Weight = (float)
                CALL_ACTIVITY_METHOD_LOCAL_ENV("AndroidThunk_OSOutcomeEvent_getWeight", "(Ljava/lang/Object;)F", Float, (jfloat)0., OutcomeEvent);

            jobjectArray NotificationIds = (jobjectArray)
                CALL_ACTIVITY_METHOD_LOCAL_ENV("AndroidThunk_OSOutcomeEvent_getNotificationIds", "(Ljava/lang/Object;)[Ljava/lang/String;", Object, (jobject)NULL, OutcomeEvent);

            if (NotificationIds)
            {
                const int32 NotificationIdsCount = env->GetArrayLength(NotificationIds);

                Outcome.NotificationIDs.Reserve(NotificationIdsCount);

                for (int32 i = 0; i < NotificationIdsCount; ++i)
                {
                    Outcome.NotificationIDs.Emplace(
                        FJavaHelper::FStringFromLocalRef(env, (jstring)env->GetObjectArrayElement(NotificationIds, i)));
                }

                env->DeleteLocalRef(NotificationIds);
            }
        }


        AsyncTask(ENamedThreads::GameThread, [Event = MoveTemp(Outcome), Callback]() mutable-> void
        {
            Callback->ExecuteIfBound(MoveTemp(Event));
            delete Callback;
        });
    }
    else
    {
        delete Callback;
    }
}

static TSharedPtr<FJsonObject> DeserializeState(JNIEnv* Env, jobject JsonString)
{
    TSharedPtr<FJsonObject> JsonParsed;
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(FJavaHelper::FStringFromParam(Env, (jstring)JsonString));
    FJsonSerializer::Deserialize(JsonReader, JsonParsed);
    return JsonParsed;
}

static FOneSignalPermissionState ConvertPermissionState(const TSharedPtr<FJsonObject>& Object)
{
    FOneSignalPermissionState State;

    if (Object)
    {
        State.bAreNotificationsEnabled = Object->GetBoolField(TEXT("areNotificationsEnabled"));
    }

    return State;
}

extern "C"
JNIEXPORT void JNICALL
DECLARE_ACTIVITY_NATIVE_METHOD(OneSignalNativePermissionObserver)
(JNIEnv * env, jobject thiz, jobject state)
{
    FOneSignalPermissionStateChanges Changes;

    TSharedPtr<FJsonObject> StateChanges = DeserializeState(env, state);

    if (StateChanges)
    {
        Changes.From = ConvertPermissionState(StateChanges->GetObjectField(TEXT("from")));
        Changes.To   = ConvertPermissionState(StateChanges->GetObjectField(TEXT("to")));
    }

    AsyncTask(ENamedThreads::GameThread, [Changes = MoveTemp(Changes)]() mutable -> void
    {
        UOneSignalLibrary::OnPermissionChanged().Broadcast(MoveTemp(Changes));
    });
}

static FOneSignalEmailSubscriptionState ConvertEmailSubscriptionState(const TSharedPtr<FJsonObject>& Object)
{
    FOneSignalEmailSubscriptionState State;

    if (Object)
    {
        State.bIsSubscribed = Object->GetBoolField(TEXT("isSubscribed"));
        State.EmailAddress  = Object->GetStringField(TEXT("emailAddress"));
        State.EmailUserID   = Object->GetStringField(TEXT("emailUserId"));
    }

    return State;
}

extern "C"
JNIEXPORT void JNICALL
DECLARE_ACTIVITY_NATIVE_METHOD(OneSignalNativeEmailSubscriptionObserver)(JNIEnv * env, jobject thiz, jobject state)
{
    FOneSignalEmailSubscriptionStateChanges Changes;

    TSharedPtr<FJsonObject> StateChanges = DeserializeState(env, state);

    if (StateChanges)
    {
        Changes.From = ConvertEmailSubscriptionState(StateChanges->GetObjectField(TEXT("from")));
        Changes.To =   ConvertEmailSubscriptionState(StateChanges->GetObjectField(TEXT("to")));
    }

    AsyncTask(ENamedThreads::GameThread, [Changes = MoveTemp(Changes)]() mutable -> void
    {
        UOneSignalLibrary::OnEmailSubscriptionChanged().Broadcast(MoveTemp(Changes));
    });
}

static FOneSignalSMSSubscriptionState ConvertSMSSubscriptionState(const TSharedPtr<FJsonObject>& Object)
{
    FOneSignalSMSSubscriptionState State;

    if (Object)
    {
        State.bIsSubscribed = Object->GetBoolField(TEXT("isSubscribed"));
        State.SMSNumber     = Object->GetStringField(TEXT("smsNumber"));
        State.SMSUserID     = Object->GetStringField(TEXT("smsUserId"));
    }

    return State;
}

extern "C"
JNIEXPORT void JNICALL
DECLARE_ACTIVITY_NATIVE_METHOD(OneSignalNativeSMSSubscriptionObserver)
(JNIEnv * env, jobject thiz, jobject state)
{
    FOneSignalSMSSubscriptionStateChanges Changes;

    TSharedPtr<FJsonObject> StateChanges = DeserializeState(env, state);

    if (StateChanges)
    {
        Changes.From = ConvertSMSSubscriptionState(StateChanges->GetObjectField(TEXT("from")));
        Changes.To   = ConvertSMSSubscriptionState(StateChanges->GetObjectField(TEXT("to")));
    }

    AsyncTask(ENamedThreads::GameThread, [Changes = MoveTemp(Changes)]() mutable -> void
    {
        UOneSignalLibrary::OnSMSSubscriptionChanged().Broadcast(MoveTemp(Changes));
    });
}

static FOneSignalSubscriptionState ConvertSubscriptionState(const TSharedPtr<FJsonObject>& Object)
{
    FOneSignalSubscriptionState State;

    if (Object)
    {
        State.bIsSubscribed   = Object->GetBoolField(TEXT("isSubscribed"));
        State.bIsPushDisabled = Object->GetBoolField(TEXT("isPushDisabled"));
        State.PushToken       = Object->GetStringField(TEXT("pushToken"));
        State.UserID          = Object->GetStringField(TEXT("userId"));
    }

    return State;
}

extern "C"
JNIEXPORT void JNICALL
DECLARE_ACTIVITY_NATIVE_METHOD(OneSignalNativeSubscriptionObserver)
(JNIEnv* env, jobject thiz, jobject state)
{
    FOneSignalSubscriptionStateChanges Changes;

    TSharedPtr<FJsonObject> StateChanges = DeserializeState(env, state);

    if (StateChanges)
    {
        Changes.From = ConvertSubscriptionState(StateChanges->GetObjectField(TEXT("from")));
        Changes.To   = ConvertSubscriptionState(StateChanges->GetObjectField(TEXT("to")));
    }

    AsyncTask(ENamedThreads::GameThread, [Changes = MoveTemp(Changes)]() mutable -> void
    {
        UOneSignalLibrary::OnSubscriptionChanged().Broadcast(MoveTemp(Changes));
    });
}

