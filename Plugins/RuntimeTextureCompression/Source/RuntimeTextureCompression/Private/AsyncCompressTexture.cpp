// Replicated Texture MeoPlay Copyright (C) 2023 MeoPlay <contact@meoplay.com> All Rights Reserved.

#include "AsyncCompressTexture.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Kismet/KismetMaterialLibrary.h"

DEFINE_LOG_CATEGORY(LogReplicatedTexture);

UAsyncCompressTexture::UAsyncCompressTexture(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer), WorldContextObject(nullptr), textureToCompress(nullptr)
{

}

UAsyncCompressTexture* UAsyncCompressTexture::CompressTexture(UObject* WorldContextObject, UTexture* textureToCompress = nullptr, int32 quality = 90, UMaterialInterface* MaterialRT = nullptr, bool exportCompressedTextureToDisk = false, FString pathExportCompressedTextureToDisk = "")
{
    UAsyncCompressTexture* BlueprintNode = NewObject<UAsyncCompressTexture>();
    BlueprintNode->WorldContextObject = WorldContextObject;

    UTexture2D* tryTexture2D = Cast<UTexture2D>(textureToCompress);
    if (tryTexture2D)
    {
        BlueprintNode->textureToCompress = Cast<UTexture2D>(tryTexture2D);
    }
    else
    {
        UTextureRenderTarget2D* tryTextureRT2D = Cast<UTextureRenderTarget2D>(textureToCompress);
        TArray<FColor> OutSamples;
        bool resReadRT = UKismetRenderingLibrary::ReadRenderTarget(WorldContextObject, tryTextureRT2D, OutSamples, true);

        int32 widthRT = tryTextureRT2D->SizeX;
        int32 heightRT = tryTextureRT2D->SizeY;
        UTexture2D* texture2DFromRT = UTexture2D::CreateTransient(widthRT, heightRT);

        if (texture2DFromRT)
        {
            texture2DFromRT->CompressionSettings = tryTextureRT2D->CompressionSettings;
            texture2DFromRT->SRGB = true;
            texture2DFromRT->UpdateResource();
            int32 nbBytesArrayRBGA = sizeof(uint8) * widthRT * heightRT * 4;
            uint8* PixelsDraw = (uint8*)malloc(nbBytesArrayRBGA);

            for (int32 y = 0; y < heightRT; y++)
            {
                for (int32 x = 0; x < widthRT; x++)
                {
                    //Get the current pixel
                    int32 CurrentPixelIndex = ((y * widthRT) + x);
                    int32 CurrentPixelIndexRGB = 3 * CurrentPixelIndex;
                    int32 CurrentPixelIndexRGBA = 4 * CurrentPixelIndex;
                    PixelsDraw[CurrentPixelIndexRGBA] = OutSamples[CurrentPixelIndex].B;
                    PixelsDraw[CurrentPixelIndexRGBA + 1] = OutSamples[CurrentPixelIndex].G;
                    PixelsDraw[CurrentPixelIndexRGBA + 2] = OutSamples[CurrentPixelIndex].R;
                    PixelsDraw[CurrentPixelIndexRGBA + 3] = OutSamples[CurrentPixelIndex].A;
                }
            }

            //Lock the mipmap data so it can be modified
            texture2DFromRT->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
            uint8* TextureData = (uint8*)texture2DFromRT->GetPlatformData()->Mips[0].BulkData.Realloc(widthRT * heightRT * 4);
            //Copy the pixel data into the Texture data
            FMemory::Memcpy(TextureData, PixelsDraw, sizeof(uint8) * widthRT * heightRT * 4);
            texture2DFromRT->GetPlatformData()->Mips[0].BulkData.Unlock();
            texture2DFromRT->UpdateResource();

            BlueprintNode->textureToCompress = texture2DFromRT;
        }
        else {
            BlueprintNode->textureToCompress = nullptr;
        }
    }

    BlueprintNode->quality = quality;
    BlueprintNode->exportCompressedTextureToDisk = exportCompressedTextureToDisk;
    BlueprintNode->pathExportCompressedTextureToDisk = pathExportCompressedTextureToDisk;
    BlueprintNode->MaterialRT = MaterialRT;

    return BlueprintNode;
}

void UAsyncCompressTexture::Activate()
{
    if (WorldContextObject == nullptr)
    {
        FFrame::KismetExecutionMessage(TEXT("Invalid WorldContextObject. Cannot execute MiniTimer."), ELogVerbosity::Error);
        return;
    }

    UE_LOG(LogReplicatedTexture, Warning, TEXT("UAsyncCompressTexture::Activate"));


    WorldContextObject->GetWorld()->GetTimerManager().SetTimerForNextTick(this, &UAsyncCompressTexture::GetTextureToCompressRGBData);

    WorldContextObject->GetWorld()->GetTimerManager().SetTimer(timerPollCompressThread, this, &UAsyncCompressTexture::PollCompressThread, 0.200f, true);
}

void UAsyncCompressTexture::GetTextureToCompressRGBData()
{
    UE_LOG(LogReplicatedTexture, Warning, TEXT("UAsyncCompressTexture::GetTextureToCompressRGBData"));

    if (textureToCompress != nullptr) {

        UTextureRenderTarget2D* renderTarget = UKismetRenderingLibrary::CreateRenderTarget2D(WorldContextObject,
            textureToCompress->GetSizeX(), textureToCompress->GetSizeY());
        UE_LOG(LogReplicatedTexture, Warning, TEXT("renderTarget null ? %d "), renderTarget == nullptr);

        UMaterialInstanceDynamic* dynamicMat = UKismetMaterialLibrary::CreateDynamicMaterialInstance(WorldContextObject, MaterialRT);
        dynamicMat->SetTextureParameterValue("TextureParam", textureToCompress);
        UE_LOG(LogReplicatedTexture, Warning, TEXT("dynamicMat null ? %d "), dynamicMat == nullptr);


        UKismetRenderingLibrary::DrawMaterialToRenderTarget(WorldContextObject, renderTarget, dynamicMat);

        TArray<FColor> PixelData;
        bool resReadRT = UKismetRenderingLibrary::ReadRenderTarget(WorldContextObject, renderTarget, PixelData);
        UE_LOG(LogReplicatedTexture, Warning, TEXT("ReadRenderTarget %d "), resReadRT);

        uint32 TextureWidth = textureToCompress->GetSizeX();
        uint32 TextureHeight = textureToCompress->GetSizeY();
        FColor PixelColor;

        UE_LOG(LogReplicatedTexture, Warning, TEXT("textureToCompress TextureWidth %d TextureHeight %d size fcolor %d "), TextureWidth, TextureHeight, sizeof(FColor));

        // 3 bytes per pixel RGB
        int numRGBBytes = 3 * TextureWidth * TextureHeight;
        uint8* rgbData = (uint8*)malloc(numRGBBytes);

        for (uint32 i = 0; i < TextureHeight; i++) {
            for (uint32 j = 0; j < TextureWidth; j++) {
                int32 toAccess = i * TextureWidth + j;
                PixelColor = PixelData[toAccess];
                int32 bytesPerPixel = 3;
                int32 offset = (i * TextureWidth + j) * bytesPerPixel;
                rgbData[offset] = PixelColor.R;
                rgbData[offset + 1] = PixelColor.G;
                rgbData[offset + 2] = PixelColor.B;
            }
            //UE_LOG(LogReplicatedTexture, Warning, TEXT("for i * TextureWidth %d sizeof(FColor) %d"), i * TextureWidth, sizeof(FColor));
            /*UE_LOG(LogReplicatedTexture, Warning, TEXT("for i * TextureWidth %d sizeof(FColor) %d GetBulkDataSize %d"), i * TextureWidth, sizeof(FColor), RawImageData->GetBulkDataSize());*/
        }

        UE_LOG(LogReplicatedTexture, Warning, TEXT("begin writeJpeg %d %d"), TextureWidth, TextureHeight);

        CompressThread = new FCompressThread(rgbData, &RGBDataJPEG, quality, TextureWidth, TextureHeight);
        return;
    }
}

void UAsyncCompressTexture::PollCompressThread() {

    if (CompressThread && CompressThread->isFinished) {

        UE_LOG(LogReplicatedTexture, Warning, TEXT("PollCompressThread finished"));

        WorldContextObject->GetWorld()->GetTimerManager().ClearTimer(timerPollCompressThread);
        timerPollCompressThread.Invalidate();

        if (exportCompressedTextureToDisk) {
            UE_LOG(LogReplicatedTexture, Warning, TEXT("PollCompressThread writing file begin"));
            FILE* filetestjpeg = fopen(TCHAR_TO_ANSI(*pathExportCompressedTextureToDisk), "wb");
            for (int i = 0; i < RGBDataJPEG.Num(); i++) {
                fputc(RGBDataJPEG[i], filetestjpeg);
            }
            fclose(filetestjpeg);
            UE_LOG(LogReplicatedTexture, Warning, TEXT("PollCompressThread writing file close"));
        }

        delegateCompressTextureComplete.Broadcast(RGBDataJPEG);
    }
}

/////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// FCompressThread ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

bool FCompressThread::isTooJPEGCompressing = false;

FCompressThread::FCompressThread(uint8* _rgbDataToEncode, TArray<uint8>* _rgbDataResult, int32 _quality, int32 _TextureWidth, int32 _TextureHeight) :
    rgbDataToCompress(_rgbDataToEncode), rgbDataResult(_rgbDataResult), quality(_quality), TextureWidth(_TextureWidth), TextureHeight(_TextureHeight)
{
    Thread = FRunnableThread::Create(this, TEXT("FCompressThread"), 0, TPri_BelowNormal); //windows default = 8mb for thread, could specify more
    isFinished = false;
}

FCompressThread::~FCompressThread()
{
    free(rgbDataToCompress);
    delete Thread;
    Thread = NULL;
}

bool FCompressThread::Init()
{
    return true;
}

uint32 FCompressThread::Run()
{
    UE_LOG(LogReplicatedTexture, Warning, TEXT("FCompressThread::Run begin"));

    bool hasCompressed = false;
    int maxRetry = 15;
    int retry = 0;

    while (!hasCompressed && retry++ < maxRetry) {
        if (!isTooJPEGCompressing) {
            isTooJPEGCompressing = true;
            TooJpeg::writeJpeg(
                [](unsigned char byte, void* data) -> void {
                    TArray<uint8>& dest = *reinterpret_cast<TArray<uint8>*>(data);
                    dest.Add(byte);
                    if (dest.Num() % 1000000 == 0) { // sleep thread to avoid consuming all CPU ressource
                        FPlatformProcess::Sleep(0.033f);
                    }
                },
                [](bool res) -> void {
                    
                },
                rgbDataResult,
                    rgbDataToCompress, TextureWidth, TextureHeight, true, quality, false, nullptr, &hasCompressed);
           
        }
        else {
            FPlatformProcess::Sleep(1.0f);
        }
        isTooJPEGCompressing = false;
    }
    

    UE_LOG(LogReplicatedTexture, Warning, TEXT("FCompressThread::Run end %d %d %d"), rgbDataResult->Num(), TextureWidth, TextureHeight);

    isFinished = true;

    return 0;
}

void FCompressThread::Stop()
{

}

void URuntimeTextureCompressionBPLib::ByteArrayAppend(UPARAM(ref) TArray<uint8>& Destination, const TArray<uint8>& DataToAppend, int32 AppendStartIndex, int32 AppendEndIndex) {
    for (int i = AppendStartIndex; i <= AppendEndIndex; i++) {
        Destination.Add(DataToAppend[i]);
    }
}
