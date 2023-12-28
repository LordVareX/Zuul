// Copyright (c) 2022 King Wai Mark

#pragma once

#include "XmlFile.h"
#include "Runtime/Engine/Public/UnrealEngine.h"
#include "Json/Public/Dom/JsonObject.h"
#include "Json/Public/Serialization/JsonSerializer.h"
#include "Json/Public/Serialization/JsonReader.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatform.h"
#include "Runtime/Core/Public/HAL/PlatformFilemanager.h"

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FBPFileUtilities.generated.h"

/**
 *	@author King Wai Mark
 */
UCLASS()
class FBP_API UFBPFileUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	static bool HasGoogleFile;
	
	static FString ReadGoogleServicesJSONFile(FString FileName);
	static TMap<FString, FString> ReadGoogleServicesPLISTFile(FString FileName);
	static TSharedPtr<FJsonObject> FStringToJSON(FString Str);


};
