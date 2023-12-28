// Replicated Texture MeoPlay Copyright (C) 2023 MeoPlay <contact@meoplay.com> All Rights Reserved.

#include "AsyncDecompressTexture.h"
#include "ImageWriteBlueprintLibrary.h"


UAsyncDecompressTexture::UAsyncDecompressTexture(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer), WorldContextObject(nullptr)
{

}

UAsyncDecompressTexture* UAsyncDecompressTexture::DecompressTexture(const UObject* WorldContextObject,
    TArray<uint8> inputRGBDataJPEG,
    TextureCompressionSettings textureCompressionSettings = TextureCompressionSettings::TC_Default,
    bool textureSettingSRGB = false, bool exportToDisk = false, FString pathExportToDisk = "")
{
    UAsyncDecompressTexture* BlueprintNode = NewObject<UAsyncDecompressTexture>();
    BlueprintNode->WorldContextObject = WorldContextObject;
    BlueprintNode->inputRGBDataJPEG = inputRGBDataJPEG;
    BlueprintNode->exportToDisk = exportToDisk;
    BlueprintNode->pathExportToDisk = pathExportToDisk;
    BlueprintNode->textureCompressionSettings = textureCompressionSettings;
    BlueprintNode->textureSettingSRGB = textureSettingSRGB;
    return BlueprintNode;
}

void UAsyncDecompressTexture::Activate()
{
    if (WorldContextObject == nullptr)
    {
        FFrame::KismetExecutionMessage(TEXT("Invalid WorldContextObject. Cannot execute MiniTimer."), ELogVerbosity::Error);
        return;
    }

    WorldContextObject->GetWorld()->GetTimerManager().SetTimerForNextTick(this, &UAsyncDecompressTexture::LaunchDecompressThread);

    WorldContextObject->GetWorld()->GetTimerManager().SetTimer(timerPollDecompressThread, this, &UAsyncDecompressTexture::PollDecompressThread, 0.200f, true);
}

void UAsyncDecompressTexture::LaunchDecompressThread()
{
    UE_LOG(LogReplicatedTexture, Warning, TEXT("UAsyncCompressTexture::LaunchDecompressThread"));

    DecompressThread = new FDecompressThread(&inputRGBDataJPEG);
    return;
}

void UAsyncDecompressTexture::checkExportResult(bool success) {
    UE_LOG(LogReplicatedTexture, Warning, TEXT("checkExportResult success %d "), success);
}

void UAsyncDecompressTexture::PollDecompressThread() {
    if (DecompressThread->isFinished) {
        UE_LOG(LogReplicatedTexture, Warning, TEXT("PollDecompressThread finished, starting creating Unreal texture2D"));
        WorldContextObject->GetWorld()->GetTimerManager().ClearTimer(timerPollDecompressThread);
        timerPollDecompressThread.Invalidate();


        int32 widthDecoded = DecompressThread->decodedWidth;
        int32 heightDecoded = DecompressThread->decodedHeight;
        UE_LOG(LogReplicatedTexture, Warning, TEXT("textureJpegResult CreateTransient %d %d"), widthDecoded, heightDecoded);

        textureJpegResult = UTexture2D::CreateTransient(widthDecoded, heightDecoded);

        if (textureJpegResult)
        {
            textureJpegResult->CompressionSettings = textureCompressionSettings;
            textureJpegResult->SRGB = textureSettingSRGB;
            textureJpegResult->UpdateResource();
            int32 nbBytesArrayRBGA = sizeof(uint8) * widthDecoded * heightDecoded * 4;
            uint8* PixelsDraw = (uint8*)malloc(nbBytesArrayRBGA);

            //UE_LOG(LogReplicatedTexture, Warning, TEXT("textureJpegResult PixelsDraw size %d decoderimage size %d"), nbBytesArrayRBGA, decoder.GetImageSize());

            for (int32 y = 0; y < heightDecoded; y++)
            {
                for (int32 x = 0; x < widthDecoded; x++)
                {
                    //Get the current pixel
                    int32 CurrentPixelIndex = ((y * widthDecoded) + x);
                    int32 CurrentPixelIndexRGB = 3 * CurrentPixelIndex;
                    int32 CurrentPixelIndexRGBA = 4 * CurrentPixelIndex;
                    PixelsDraw[CurrentPixelIndexRGBA] = DecompressThread->decoder->GetImage()[CurrentPixelIndexRGB + 2]; //b
                    PixelsDraw[CurrentPixelIndexRGBA + 1] = DecompressThread->decoder->GetImage()[CurrentPixelIndexRGB + 1]; //g
                    PixelsDraw[CurrentPixelIndexRGBA + 2] = DecompressThread->decoder->GetImage()[CurrentPixelIndexRGB]; //r
                    PixelsDraw[CurrentPixelIndexRGBA + 3] = 255; //set A channel always to maximum
                }
            }

            //Lock the mipmap data so it can be modified
            textureJpegResult->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
            uint8* TextureData = (uint8*)textureJpegResult->GetPlatformData()->Mips[0].BulkData.Realloc(widthDecoded * heightDecoded * 4);
            //Copy the pixel data into the Texture data
            FMemory::Memcpy(TextureData, PixelsDraw, sizeof(uint8) * widthDecoded * heightDecoded * 4);
            textureJpegResult->GetPlatformData()->Mips[0].BulkData.Unlock();
            textureJpegResult->UpdateResource();


            UE_LOG(LogReplicatedTexture, Warning, TEXT("textureJpegResult %d || !textureJpegResult->GetResource() %d || !textureJpegResult->GetResource()->TextureRHI %d "),
                textureJpegResult != nullptr,
                textureJpegResult != nullptr && textureJpegResult->GetResource() != nullptr,
                textureJpegResult != nullptr && textureJpegResult->GetResource() != nullptr && textureJpegResult->GetResource()->TextureRHI != nullptr);

            if (exportToDisk) {
                WorldContextObject->GetWorld()->GetTimerManager().SetTimer(timerLaunchExportFile, this, &UAsyncDecompressTexture::LaunchExportFile, 1.0f, false);
            }

            UE_LOG(LogReplicatedTexture, Warning, TEXT("textureJpegResult end update %d %d "), textureJpegResult->GetSizeX(), textureJpegResult->GetSizeY());
        }

        if (!exportToDisk) {
            delegateDecompressTextureComplete.Broadcast(textureJpegResult);
        }
    }
}

void UAsyncDecompressTexture::LaunchExportFile()
{
    FOnImageWriteComplete OnCompleteExport;
    OnCompleteExport.BindDynamic(this, &UAsyncDecompressTexture::checkExportResult);
    FImageWriteOptions exportOptions;
    exportOptions.bAsync = true;
    exportOptions.bOverwriteFile = true;
    exportOptions.CompressionQuality = 100;
    exportOptions.Format = EDesiredImageFormat::JPG;
    exportOptions.OnComplete = OnCompleteExport;
    UImageWriteBlueprintLibrary::ExportToDisk(textureJpegResult, pathExportToDisk, exportOptions);

    delegateDecompressTextureComplete.Broadcast(textureJpegResult);
}



/////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// FDecompressThread ////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
FDecompressThread::FDecompressThread(TArray<uint8>* _rgbDataToDecode)
    : rgbDataToDecode(_rgbDataToDecode)
{
    Thread = FRunnableThread::Create(this, TEXT("FDecompressThread"), 0, TPri_BelowNormal); //windows default = 8mb for thread, could specify more
    isFinished = false;
}

FDecompressThread::~FDecompressThread()
{
    delete Thread;
    Thread = NULL;
}

bool FDecompressThread::Init()
{
    return true;
}

uint32 FDecompressThread::Run()
{
    UE_LOG(LogReplicatedTexture, Warning, TEXT("FDecompressThread::Run begin"));

    ////////////////// debut decompression ////////////////////
    size_t size = rgbDataToDecode->Num();
    unsigned char* buf = rgbDataToDecode->GetData();

    decoder = new Jpeg::Decoder(buf, size);

    if (decoder->GetResult() != Jpeg::Decoder::OK)
    {
        UE_LOG(LogReplicatedTexture, Warning, TEXT("Error decoding the input file"));
        return 1;
    }

    decodedWidth = decoder->GetWidth();
    decodedHeight = decoder->GetHeight();

    UE_LOG(LogReplicatedTexture, Warning, TEXT("decoder.GetImageSize w %d h %d GetImageSize %d iscolor %d"),
        decoder->GetWidth(), decoder->GetHeight(), decoder->GetImageSize(), decoder->IsColor());

    ////////////////// fin decompression ////////////////////

    UE_LOG(LogReplicatedTexture, Warning, TEXT("FDecompressThread::Run end"));

    isFinished = true;

    return 0;
}

void FDecompressThread::Stop()
{

}