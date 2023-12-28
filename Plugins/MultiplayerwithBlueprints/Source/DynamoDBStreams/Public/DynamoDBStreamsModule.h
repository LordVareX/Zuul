/* Copyright (C) Siqi.Wu - All Rights Reserved

 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "Modules/ModuleManager.h"

class FDynamoDBStreamsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:

#if WITH_EDITOR
	static void* DynamoDBStreamsLibraryHandle;
	static bool LoadDependency(const FString& Dir, const FString& Name, void*& Handle);
	static void FreeDependency(void*& Handle);
#endif
};