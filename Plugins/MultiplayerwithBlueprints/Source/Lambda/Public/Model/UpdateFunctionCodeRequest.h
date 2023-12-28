/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "HAL/UnrealMemory.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/UpdateFunctionCodeRequest.h"

#endif

#include "Model/AWSLambdaArchitecture.h"

#include "UpdateFunctionCodeRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateFunctionCodeRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> – <code>my-function</code>.</p> </li> <li> <p> <b>Function ARN</b> – <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> – <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>The base64-encoded contents of the deployment package. Amazon Web Services SDK and CLI clients handle the encoding for you. Use only with a function defined with a .zip file archive deployment package.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString zipFile;

    /**
    *  <p>An Amazon S3 bucket in the same Amazon Web Services Region as your function. The bucket can be in a different Amazon Web Services account. Use only with a function defined with a .zip file archive deployment package.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString s3Bucket;

    /**
    *  <p>The Amazon S3 key of the deployment package. Use only with a function defined with a .zip file archive deployment package.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString s3Key;

    /**
    *  <p>For versioned objects, the version of the deployment package object to use.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString s3ObjectVersion;

    /**
    *  <p>URI of a container image in the Amazon ECR registry. Do not use for a function defined with a .zip file archive.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString imageUri;

    /**
    *  <p>Set to true to publish a new version of the function after updating the code. This has the same effect as calling <a>PublishVersion</a> separately.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool publish = false;

    /**
    *  <p>Set to true to validate the request parameters and access permissions without modifying the function code.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    bool dryRun = false;

    /**
    *  <p>Update the function only if the revision ID matches the ID that's specified. Use this option to avoid modifying a function that has changed since you last read it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString revisionId;

    /**
    *  <p>The instruction set architecture that the function supports. Enter a string array with one of the valid values (arm64 or x86_64). The default value is <code>x86_64</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<EAWSLambdaArchitecture> architectures;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::UpdateFunctionCodeRequest toAWS() const {
        Aws::Lambda::Model::UpdateFunctionCodeRequest awsUpdateFunctionCodeRequest;

		if (!(this->functionName.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

        if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->zipFile)) {
            IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

            IFileHandle* FileHandle = PlatformFile.OpenRead(*this->zipFile);
            if(FileHandle) {
                uint8* ByteBuffer = (uint8*)FMemory::Malloc(FPlatformFileManager::Get().GetPlatformFile().FileSize(*this->zipFile));

                FileHandle->Read(ByteBuffer, sizeof(ByteBuffer));

                awsUpdateFunctionCodeRequest.SetZipFile(Aws::Utils::CryptoBuffer(Aws::Utils::ByteBuffer(ByteBuffer, sizeof(ByteBuffer))));

                delete FileHandle;
                FMemory::Free(ByteBuffer);
            }
        }

		if (!(this->s3Bucket.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetS3Bucket(TCHAR_TO_UTF8(*this->s3Bucket));
        }

		if (!(this->s3Key.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetS3Key(TCHAR_TO_UTF8(*this->s3Key));
        }

		if (!(this->s3ObjectVersion.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetS3ObjectVersion(TCHAR_TO_UTF8(*this->s3ObjectVersion));
        }

		if (!(this->imageUri.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetImageUri(TCHAR_TO_UTF8(*this->imageUri));
        }

		awsUpdateFunctionCodeRequest.SetPublish(this->publish);

		awsUpdateFunctionCodeRequest.SetDryRun(this->dryRun);

		if (!(this->revisionId.IsEmpty())) {
            awsUpdateFunctionCodeRequest.SetRevisionId(TCHAR_TO_UTF8(*this->revisionId));
        }

        for (const EAWSLambdaArchitecture& elem : this->architectures) {
		    switch(elem) {
                case EAWSLambdaArchitecture::x86_64:
                    awsUpdateFunctionCodeRequest.AddArchitectures(Aws::Lambda::Model::Architecture::x86_64);
                    break;
            case EAWSLambdaArchitecture::arm64:
                    awsUpdateFunctionCodeRequest.AddArchitectures(Aws::Lambda::Model::Architecture::arm64);
                    break;
            default:
                break;
            };
        }

        return awsUpdateFunctionCodeRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && !FPlatformFileManager::Get().GetPlatformFile().FileExists(*this->zipFile) && this->s3Bucket.IsEmpty() && this->s3Key.IsEmpty() && this->s3ObjectVersion.IsEmpty() && this->imageUri.IsEmpty() && false && false && this->revisionId.IsEmpty() && this->architectures.Num() == 0;
    }
#endif
};
