// Replicated Texture MeoPlay Copyright (C) 2023 MeoPlay <contact@meoplay.com> All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture.h"
#include "Engine/World.h"
#include "Engine/Texture2D.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "TextureResource.h"

#include "TimerManager.h"
#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"

#include "Kismet/BlueprintAsyncActionBase.h"
#include "Kismet/BlueprintFunctionLibrary.h" 

// third party
#include "jpeg_decoder.h"

#include "AsyncDecompressTexture.generated.h"

// forward declaration
class FDecompressThread;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDecompressTextureComplete, UTexture2D*, decompressedTexture);

UCLASS()
class RUNTIMETEXTURECOMPRESSION_API UAsyncDecompressTexture : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(BlueprintAssignable)
		FDecompressTextureComplete delegateDecompressTextureComplete;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "RuntimeTextureCompression")
		static UAsyncDecompressTexture* DecompressTexture(const UObject* WorldContextObject, TArray<uint8> inputRGBDataJPEG, TextureCompressionSettings textureCompressionSettings, bool textureSettingSRGB, bool exportToDisk, FString pathExportToDisk);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
	//~UBlueprintAsyncActionBase interface

private:
	const UObject* WorldContextObject;

	FDecompressThread* DecompressThread;
	FTimerHandle timerPollDecompressThread;

	UPROPERTY()
		TArray<uint8> inputRGBDataJPEG;

	UPROPERTY()
		UTexture2D* textureJpegResult;

	TextureCompressionSettings textureCompressionSettings;
	ETextureMipLoadOptions textureMipLoadOptions;
	TextureGroup textureLODGroup;

	bool textureSettingSRGB;

	FTimerHandle timerLaunchExportFile;
	bool exportToDisk = false;
	FString pathExportToDisk = "";


private:
	UFUNCTION()
		void LaunchDecompressThread();

	UFUNCTION()
		void PollDecompressThread();

	UFUNCTION()
		void LaunchExportFile();

	UFUNCTION()
		void checkExportResult(bool success);
};


class FDecompressThread : public FRunnable
{
public:
	/** Thread to run the worker FRunnable on */
	FRunnableThread* Thread;

	//Constructor / Destructor
	FDecompressThread(TArray<uint8>* _rgbDataToDecode);
	virtual ~FDecompressThread();

	// Begin FRunnable interface.
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	// End FRunnable interface

	TArray<uint8>* rgbDataToDecode;

	int32 decodedWidth;
	int32 decodedHeight;
	bool isFinished = false;

	Jpeg::Decoder* decoder;
};

