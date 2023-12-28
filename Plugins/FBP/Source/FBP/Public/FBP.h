// Copyright (c) 2022 King Wai Mark

#pragma once

#include "Modules/ModuleManager.h"

class FFBPModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
