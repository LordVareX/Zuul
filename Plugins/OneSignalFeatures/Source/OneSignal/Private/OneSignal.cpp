// Copyright Pandores Marketplace 2023. All Rights Reserved.

#include "OneSignal.h"

#define LOCTEXT_NAMESPACE "FOneSignalModule"

void FOneSignalModule::StartupModule()
{
	UOneSignalLibrary::Initialize();
}

void FOneSignalModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOneSignalModule, OneSignal)