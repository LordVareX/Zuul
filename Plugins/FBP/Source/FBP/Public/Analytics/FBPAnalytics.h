// Copyright (c) 2022 King Wai Mark

#pragma once

#include "FBPApp.h"

#if PLATFORM_WINDOWS || PLATFORM_MAC || PLATFORM_ANDROID || PLATFORM_IOS
	#include "firebase/analytics.h"
#endif


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBPAnalytics.generated.h"

/**
 *	@author King Wai Mark
 * 
 */
USTRUCT(BlueprintType)
struct FBP_API FAnalyticsParameter
{
	GENERATED_BODY()

	enum EType
	{
		String,
		Integer,
		Float
	};
	FString Name;
	EType Type;
	FString Str;
	float FloatVal;
	int IntVal;
	TArray<FAnalyticsParameter> ArrayVal;

};



/**
 * @author King Wai Mark
 *
 * This class contains functions for Firebase(Google) Analytics.
 */
UCLASS()
class FBP_API UFBPAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	/**
	 *	Begin the Analytics Parameters chain. Used in conjunction with AddStringParameter, AddIntParameter, AddFloatParameter, and LogEventWithMultipleParameters.
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Begin Add Analytics Parameters", Keywords = "Begin Add Analytics Parameters"), Category="Analytics - Firebase Plugin by KWM")
	static TArray<FAnalyticsParameter> FBPBeginAddAnalyticsParameters();

	/**
	 *	Adds a String parameter to the parameter chain.
	 *
	 *	@param Parameters Parameter chain
	 *	@param ParameterName Name of the parameter
	 *	@param Str String value
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Add String Parameter", Keywords = "Add String Parameter"), Category="Analytics - Firebase Plugin by KWM")
	static TArray<FAnalyticsParameter> FBPAddStringParameter(TArray<FAnalyticsParameter> Parameters, const FString ParameterName, const FString Str);
	
	/**
	 *	Adds a Integer parameter to the parameter chain.
	 *	
	 *	@param Parameters Parameter chain
	 *	@param ParameterName Name of the parameter
	 *	@param Integer Integer value
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Add Integer Parameter", Keywords = "Add Integer Parameter"), Category="Analytics - Firebase Plugin by KWM")
	static TArray<FAnalyticsParameter> FBPAddIntegerParameter(TArray<FAnalyticsParameter> Parameters, const FString ParameterName, const int Integer);

	/**
	 *	Adds a Float parameter to the parameter chain.
	 *	
	 *	@param Parameters Parameter chain
	 *	@param ParameterName Name of the parameter
	 *	@param Float Float value
	 *	
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Add Float Parameter", Keywords = "Add Float Parameter"), Category="Analytics - Firebase Plugin by KWM")
	static TArray<FAnalyticsParameter> FBPAddFloatParameter(TArray<FAnalyticsParameter> Parameters, const FString ParameterName, const float Float);

	/**
	 *	Logs an event with multiple parameters.
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Log Event With Multiple Parameters", Keywords = "Log Event With Multiple Parameters"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPLogEventWithMultipleParameters(const FString EventName, const TArray<FAnalyticsParameter> Parameters);
	
	/**
	 *	Starts Firebase Analytics
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Initialize Analytics", Keywords = "Initialize Analytics"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPInitializeAnalytics();

	/**
	 *	Logs an event with a String parameter.
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Log Event With String Parameter", Keywords = "Log Event With String Parameter"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPLogEventWithStringParameter(const FString EventName, const FString ParameterName, const FString ParameterValue);
	/**
	 *	Logs an event with a Int parameter.
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Log Event With Int Parameter", Keywords = "Log Event With Int Parameter"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPLogEventWithIntParameter(const FString EventName, const FString ParameterName, const int ParameterValue);
	/**
	 *	Logs an event with a Float parameter.
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Log Event With Float Parameter", Keywords = "Log Event With Float Parameter"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPLogEventWithFloatParameter(const FString EventName, const FString ParameterName, const float ParameterValue);

	/**
	 *	Add the user id to the Analytics log events.
	 *
	 *	@param Id User id
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Set User Id", Keywords = "Set User Id"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPSetUserId(const FString Id);

	/**
	 *	Add the User Property to the Analytics log events.
	 *
	 *	@param Name	Name 
	 *	@param Property Property
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Set User Property", Keywords = "Set User Property"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPSetUserProperty(const FString Name, const FString Property);

	/**
	 *	Enables analytics collection.
	 *
	 *	@param Enable 
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Set Analytics Collection Enabled", Keywords = "Set Analytics Collection Enabled"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPSetAnalyticsCollectionEnabled(const bool Enable);

	/**
	 *	Set the timeout duration of when the session will end.
	 *
	 *	@param Seconds
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Set Session Timeout Duration", Keywords = "Set Session Timeout Duration"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPSetSessionTimeoutDuration(const float Seconds);
	/**
	 *	Reset Analytics Data.
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Reset Analytics Data", Keywords = "Reset Analytics Data"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPResetAnalyticsData();

	/**
	 *	Terminates the Analytics data.
	 *
	 *	@author King Wai Mark
	 */
	UFUNCTION(BlueprintCallable, meta=(DisplayName = "Terminate", Keywords = "Terminate"), Category="Analytics - Firebase Plugin by KWM")
	static void FBPTerminate();

};
