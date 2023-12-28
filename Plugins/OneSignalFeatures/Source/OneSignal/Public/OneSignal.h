// Copyright Pandores Marketplace 2023. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OneSignal/OneSignalLibrary.h"
#include "Modules/ModuleManager.h"

class FOneSignalModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
