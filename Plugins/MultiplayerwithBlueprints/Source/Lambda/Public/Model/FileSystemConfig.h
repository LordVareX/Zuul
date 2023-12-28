/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/FileSystemConfig.h"

#endif

#include "FileSystemConfig.generated.h"

USTRUCT(BlueprintType)
struct FFileSystemConfig {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) of the Amazon EFS access point that provides access to the file system.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString arn;

    /**
    *  <p>The path where the function can access the file system, starting with <code>/mnt/</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString localMountPath;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::FileSystemConfig toAWS() const {
        Aws::Lambda::Model::FileSystemConfig awsFileSystemConfig;

		if (!(this->arn.IsEmpty())) {
            awsFileSystemConfig.SetArn(TCHAR_TO_UTF8(*this->arn));
        }

		if (!(this->localMountPath.IsEmpty())) {
            awsFileSystemConfig.SetLocalMountPath(TCHAR_TO_UTF8(*this->localMountPath));
        }

        return awsFileSystemConfig;
    }

    bool IsEmpty() const {
        return this->arn.IsEmpty() && this->localMountPath.IsEmpty();
    }

    FFileSystemConfig &fromAWS(const Aws::Lambda::Model::FileSystemConfig &awsFileSystemConfig) {
        this->arn = UTF8_TO_TCHAR(awsFileSystemConfig.GetArn().c_str());

        this->localMountPath = UTF8_TO_TCHAR(awsFileSystemConfig.GetLocalMountPath().c_str());

        return *this;
    }
#endif
};
