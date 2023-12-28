/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateUserImportJobRequest.h"

#endif

#include "CreateUserImportJobRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateUserImportJobRequest {
GENERATED_BODY()

    /**
    *  <p>The job name for the user import job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString jobName;

    /**
    *  <p>The user pool ID for the user pool that the users are being imported into.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The role ARN for the Amazon CloudWatch Logging role for the user import job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString cloudWatchLogsRoleArn;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CreateUserImportJobRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::CreateUserImportJobRequest awsCreateUserImportJobRequest;

        if (!(this->jobName.IsEmpty())) {
            awsCreateUserImportJobRequest.SetJobName(TCHAR_TO_UTF8(*this->jobName));
        }

        if (!(this->userPoolId.IsEmpty())) {
            awsCreateUserImportJobRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->cloudWatchLogsRoleArn.IsEmpty())) {
            awsCreateUserImportJobRequest.SetCloudWatchLogsRoleArn(TCHAR_TO_UTF8(*this->cloudWatchLogsRoleArn));
        }

        return awsCreateUserImportJobRequest;
    }

    bool IsEmpty() const {
        return this->jobName.IsEmpty() && this->userPoolId.IsEmpty() && this->cloudWatchLogsRoleArn.IsEmpty();
    }
#endif
};
