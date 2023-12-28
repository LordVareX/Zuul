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
#include "toojpeg.h"

#include "AsyncCompressTexture.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogReplicatedTexture, Log, All);

// forward declaration
class FCompressThread;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCompressTextureComplete, const TArray<uint8>&, JPEGBytes);

UCLASS()
class RUNTIMETEXTURECOMPRESSION_API UAsyncCompressTexture : public UBlueprintAsyncActionBase
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(BlueprintAssignable)
		FCompressTextureComplete delegateCompressTextureComplete;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "RuntimeTextureCompression")
		static UAsyncCompressTexture* CompressTexture(UObject* WorldContextObject, UTexture* textureToCompress, int32 quality, UMaterialInterface* MaterialRT, bool exportCompressedTextureToDisk, FString pathExportCompressedTextureToDisk);

	// UBlueprintAsyncActionBase interface
	virtual void Activate() override;
	//~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
		void GetTextureToCompressRGBData();

	UFUNCTION()
		void PollCompressThread();

private:
	UObject* WorldContextObject;
	UTexture2D* textureToCompress;
	int32 quality;
	bool exportCompressedTextureToDisk;
	FString pathExportCompressedTextureToDisk;
	UMaterialInterface* MaterialRT;

	UTexture2D* textureJpegResult;

	FCompressThread* CompressThread;
	FTimerHandle timerPollCompressThread;



	UPROPERTY()
		TArray<uint8> RGBDataJPEG;

	UPROPERTY()
		int32 decodedWidth;

	UPROPERTY()
		int32 decodedHeight;
};


class FCompressThread : public FRunnable
{
public:
	/** Thread to run the worker FRunnable on */
	FRunnableThread* Thread;

	//Constructor / Destructor
	FCompressThread(uint8* _rgbDataToEncode, TArray<uint8>* _rgbDataResult, int32 _quality, int32 _TextureWidth, int32 _TextureHeight);
	virtual ~FCompressThread();

	// Begin FRunnable interface.
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	// End FRunnable interface

	bool isFinished = false;

	uint8* rgbDataToCompress;
	TArray<uint8>* rgbDataResult;
	int32 quality;
	int32 TextureWidth;
	int32 TextureHeight;

	static bool isTooJPEGCompressing;

};

/* bp library */
UCLASS()
class RUNTIMETEXTURECOMPRESSION_API URuntimeTextureCompressionBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "VoiceChatUniversal")
		static void ByteArrayAppend(UPARAM(ref) TArray<uint8>& Destination, const TArray<uint8>& DataToAppend, int32 AppendStartIndex, int32 AppendEndIndex);
};