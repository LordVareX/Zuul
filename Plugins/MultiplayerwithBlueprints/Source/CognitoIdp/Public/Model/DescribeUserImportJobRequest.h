/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeUserImportJobRequest.h"

#endif

#include "DescribeUserImportJobRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeUserImportJobRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool that the users are being imported into.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The job ID for the user import job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString jobId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DescribeUserImportJobRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DescribeUserImportJobRequest awsDescribeUserImportJobRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsDescribeUserImportJobRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->jobId.IsEmpty())) {
            awsDescribeUserImportJobRequest.SetJobId(TCHAR_TO_UTF8(*this->jobId));
        }

        return awsDescribeUserImportJobRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->jobId.IsEmpty();
    }
#endif
};
