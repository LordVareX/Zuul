// Replicated Texture MeoPlay Copyright (C) 2023 MeoPlay <contact@meoplay.com> All Rights Reserved.

#include "RuntimeTextureCompression.h"
#include "Interfaces/IPluginManager.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FRuntimeTextureCompressionModule"

void FRuntimeTextureCompressionModule::StartupModule()
{
	
}



void FRuntimeTextureCompressionModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRuntimeTextureCompressionModule, RuntimeTextureCompression)