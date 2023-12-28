/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "HAL/UnrealMemory.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/LayerVersionContentInput.h"

#endif

#include "LayerVersionContentInput.generated.h"

USTRUCT(BlueprintType)
struct FLayerVersionContentInput {
GENERATED_BODY()

    /**
    *  <p>The Amazon S3 bucket of the layer archive.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString s3Bucket;

    /**
    *  <p>The Amazon S3 key of the layer archive.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString s3Key;

    /**
    *  <p>For versioned objects, the version of the layer archive object to use.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString s3ObjectVersion;

    /**
     * Indicate the zip file path. Absolute File Path
    *  <p>The base64-encoded contents of the layer archive. AWS SDK and AWS CLI clients handle the encoding for you.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString zipFile;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::LayerVersionContentInput toAWS() const {
        Aws::Lambda::Model::LayerVersionContentInput awsLayerVersionContentInput;

		if (!(this->s3Bucket.IsEmpty())) {
            awsLayerVersionContentInput.SetS3Bucket(TCHAR_TO_UTF8(*this->s3Bucket));
        }

		if (!(this->s3Key.IsEmpty())) {
            awsLayerVersionContentInput.SetS3Key(TCHAR_TO_UTF8(*this->s3Key));
        }

		if (!(this->s3ObjectVersion.IsEmpty())) {
            awsLayerVersionContentInput.SetS3ObjectVersion(TCHAR_TO_UTF8(*this->s3ObjectVersion));
        }

        if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->zipFile)) {
            IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

            IFileHandle* FileHandle = PlatformFile.OpenRead(*this->zipFile);
            if(FileHandle) {
                uint8* ByteBuffer = (uint8*)FMemory::Malloc(FPlatformFileManager::Get().GetPlatformFile().FileSize(*this->zipFile));

                FileHandle->Read(ByteBuffer, sizeof(ByteBuffer));

                awsLayerVersionContentInput.SetZipFile(Aws::Utils::CryptoBuffer(Aws::Utils::ByteBuffer(ByteBuffer, sizeof(ByteBuffer))));

                delete FileHandle;
                FMemory::Free(ByteBuffer);
            }
        }

        return awsLayerVersionContentInput;
    }

    bool IsEmpty() const {
        return this->s3Bucket.IsEmpty() && this->s3Key.IsEmpty() && this->s3ObjectVersion.IsEmpty() && !FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->zipFile);
    }
#endif
};
