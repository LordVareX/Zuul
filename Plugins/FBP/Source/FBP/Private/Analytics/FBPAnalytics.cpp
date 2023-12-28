// Copyright (c) 2022 King Wai Mark

#include "Analytics/FBPAnalytics.h"


TArray<FAnalyticsParameter> UFBPAnalytics::FBPBeginAddAnalyticsParameters()
{
	return TArray<FAnalyticsParameter>();
}

TArray<FAnalyticsParameter> UFBPAnalytics::FBPAddStringParameter(TArray<FAnalyticsParameter> Parameters, const FString ParameterName, const FString Str)
{
	FAnalyticsParameter Parameter = FAnalyticsParameter();
	Parameter.Type = FAnalyticsParameter::String;
	Parameter.Name = ParameterName;
	Parameter.Str = Str;
	Parameters.Add(Parameter);
	return Parameters;
}

TArray<FAnalyticsParameter> UFBPAnalytics::FBPAddIntegerParameter(TArray<FAnalyticsParameter> Parameters, const FString ParameterName, const int Integer)
{
	FAnalyticsParameter Parameter =  FAnalyticsParameter();
	Parameter.Type = FAnalyticsParameter::Integer;
	Parameter.Name = ParameterName;
	Parameter.IntVal = Integer;
	Parameters.Add(Parameter);
	return Parameters;
}

TArray<FAnalyticsParameter> UFBPAnalytics::FBPAddFloatParameter(TArray<FAnalyticsParameter> Parameters, const FString ParameterName, const float Float)
{
	FAnalyticsParameter Parameter = FAnalyticsParameter();
	Parameter.Type = FAnalyticsParameter::Float;
	Parameter.Name = ParameterName;
	Parameter.FloatVal = Float;
	Parameters.Add(Parameter);
	return Parameters;
}

void UFBPAnalytics::FBPLogEventWithMultipleParameters(const FString EventName, const TArray<FAnalyticsParameter> Parameters)
{

	#if PLATFORM_ANDROID || PLATFORM_IOS
	if(UFBPFileUtilities::HasGoogleFile)
	{
		if(Parameters.Num() > 0)
		{
			const int NumOfParameters = Parameters.Num();
		
			firebase::analytics::Parameter* SelectContentParameters = new firebase::analytics::Parameter[NumOfParameters];

			for(int i = 0; i < Parameters.Num(); i++)
			{
				const FString ParamName = Parameters[i].Name;
				firebase::analytics::Parameter Parameter = firebase::analytics::Parameter();
				Parameter.name = TCHAR_TO_ANSI(*ParamName);
				if(Parameters[i].Type == FAnalyticsParameter::String)
				{
					Parameter.value.set_string_value(TCHAR_TO_ANSI(*Parameters[i].Str));
					SelectContentParameters[i] = Parameter;
				} else if(Parameters[i].Type == FAnalyticsParameter::Integer)
				{
					Parameter.value.set_int64_value(Parameters[i].IntVal);
					SelectContentParameters[i] = Parameter;
				} else if(Parameters[i].Type == FAnalyticsParameter::Float)
				{
					Parameter.value.set_int64_value(Parameters[i].FloatVal);
					SelectContentParameters[i] = Parameter;
				}

			}
			firebase::analytics::LogEvent(
			  TCHAR_TO_ANSI(*EventName), SelectContentParameters,
			  NumOfParameters);
		}
	}
	#endif
}

void UFBPAnalytics::FBPInitializeAnalytics()
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	firebase::App* App = UFBPApp::FBPGet();
	if(App != nullptr)
	{
		firebase::analytics::Initialize(*App);
	}
	#endif
}


void UFBPAnalytics::FBPLogEventWithStringParameter(const FString Name, const FString ParameterName, const FString ParameterValue)
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::analytics::LogEvent(TCHAR_TO_ANSI(*Name), TCHAR_TO_ANSI(*ParameterName), TCHAR_TO_ANSI(*ParameterValue));
	}
	#endif
	
}

void UFBPAnalytics::FBPLogEventWithIntParameter(const FString Name, const FString ParameterName, const int ParameterValue)
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::analytics::LogEvent(TCHAR_TO_ANSI(*Name), TCHAR_TO_ANSI(*ParameterName), ParameterValue);
	}
	#endif
	
}

void UFBPAnalytics::FBPLogEventWithFloatParameter(const FString Name, const FString ParameterName, const float ParameterValue)
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::analytics::LogEvent(TCHAR_TO_ANSI(*Name), TCHAR_TO_ANSI(*ParameterName), ParameterValue);
	}
	#endif
}

void UFBPAnalytics::FBPSetUserId(const FString Id)
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::analytics::SetUserId(TCHAR_TO_ANSI(*Id));
	}

	#endif
	
}

void UFBPAnalytics::FBPSetUserProperty(const FString Name, const FString Property)
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::analytics::SetUserProperty(TCHAR_TO_ANSI(*Name), TCHAR_TO_ANSI(*Property));
	}
	#endif
	
}

void UFBPAnalytics::FBPSetAnalyticsCollectionEnabled(const bool Enable)
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::analytics::SetAnalyticsCollectionEnabled(Enable);
	}
	#endif
	
}

void UFBPAnalytics::FBPSetSessionTimeoutDuration(const float Seconds)
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	if(UFBPFileUtilities::HasGoogleFile)
	{
		int Duration = (Seconds * 1000);
		firebase::analytics::SetSessionTimeoutDuration(Duration);
	}
	#endif
;
}

void UFBPAnalytics::FBPResetAnalyticsData()
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::analytics::ResetAnalyticsData();
	}
	#endif
	
}

void UFBPAnalytics::FBPTerminate()
{
	#if PLATFORM_ANDROID || PLATFORM_IOS
	if(UFBPFileUtilities::HasGoogleFile)
	{
		firebase::analytics::Terminate(); 
	}
	#endif
	
}


