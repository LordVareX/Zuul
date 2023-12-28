/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "HAL/UnrealMemory.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/FunctionCode.h"

#endif

#include "FunctionCode.generated.h"

USTRUCT(BlueprintType)
struct FFunctionCode {
GENERATED_BODY()

    /**
    *  Indicate the zip file path. Absolute File Path
    *  <p>The base64-encoded contents of the deployment package. AWS SDK and AWS CLI clients handle the encoding for you.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString zipFile;

    /**
    *  <p>An Amazon S3 bucket in the same AWS Region as your function. The bucket can be in a different AWS account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString S3Bucket;

    /**
    *  <p>The Amazon S3 key of the deployment package.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString S3Key;

    /**
    *  <p>For versioned objects, the version of the deployment package object to use.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString S3ObjectVersion;

    /**
    *  <p>URI of a container image in the Amazon ECR registry.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString imageUri;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::FunctionCode toAWS() const {
        Aws::Lambda::Model::FunctionCode awsFunctionCode;

        if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->zipFile)) {
            IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

            IFileHandle* FileHandle = PlatformFile.OpenRead(*this->zipFile);
            if(FileHandle) {
                uint8* ByteBuffer = (uint8*)FMemory::Malloc(FPlatformFileManager::Get().GetPlatformFile().FileSize(*this->zipFile));

                FileHandle->Read(ByteBuffer, sizeof(ByteBuffer));

                awsFunctionCode.SetZipFile(Aws::Utils::CryptoBuffer(Aws::Utils::ByteBuffer(ByteBuffer, sizeof(ByteBuffer))));

                delete FileHandle;
                FMemory::Free(ByteBuffer);
            }
        }

		if (!(this->S3Bucket.IsEmpty())) {
            awsFunctionCode.SetS3Bucket(TCHAR_TO_UTF8(*this->S3Bucket));
        }

		if (!(this->S3Key.IsEmpty())) {
            awsFunctionCode.SetS3Key(TCHAR_TO_UTF8(*this->S3Key));
        }

		if (!(this->S3ObjectVersion.IsEmpty())) {
            awsFunctionCode.SetS3ObjectVersion(TCHAR_TO_UTF8(*this->S3ObjectVersion));
        }

		if (!(this->imageUri.IsEmpty())) {
            awsFunctionCode.SetImageUri(TCHAR_TO_UTF8(*this->imageUri));
        }

        return awsFunctionCode;
    }

    bool IsEmpty() const {
        return !FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->zipFile) && this->S3Bucket.IsEmpty() && this->S3Key.IsEmpty() && this->S3ObjectVersion.IsEmpty() && this->imageUri.IsEmpty();
    }
#endif
};
