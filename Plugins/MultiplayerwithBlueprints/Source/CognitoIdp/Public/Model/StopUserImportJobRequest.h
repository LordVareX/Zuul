/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/StopUserImportJobRequest.h"

#endif

#include "StopUserImportJobRequest.generated.h"

USTRUCT(BlueprintType)
struct FStopUserImportJobRequest {
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
    Aws::CognitoIdentityProvider::Model::StopUserImportJobRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::StopUserImportJobRequest awsStopUserImportJobRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsStopUserImportJobRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->jobId.IsEmpty())) {
            awsStopUserImportJobRequest.SetJobId(TCHAR_TO_UTF8(*this->jobId));
        }

        return awsStopUserImportJobRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->jobId.IsEmpty();
    }
#endif
};
