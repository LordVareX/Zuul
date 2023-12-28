/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserImportJobType.h"

#endif

#include "Model/UserImportJobStatusType.h"

#include "UserImportJobType.generated.h"

USTRUCT(BlueprintType)
struct FUserImportJobType {
GENERATED_BODY()

    /**
    *  <p>The job name for the user import job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString jobName;

    /**
    *  <p>The job ID for the user import job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString jobId;

    /**
    *  <p>The user pool ID for the user pool that the users are being imported into.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The pre-signed URL to be used to upload the <code>.csv</code> file.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString preSignedUrl;

    /**
    *  <p>The date the user import job was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime creationDate;

    /**
    *  <p>The date when the user import job was started.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime startDate;

    /**
    *  <p>The date when the user import job was completed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime completionDate;

    /**
    *  <p>The status of the user import job. One of the following:</p> <ul> <li> <p> <code>Created</code> - The job was created but not started.</p> </li> <li> <p> <code>Pending</code> - A transition state. You have started the job, but it has not begun importing users yet.</p> </li> <li> <p> <code>InProgress</code> - The job has started, and users are being imported.</p> </li> <li> <p> <code>Stopping</code> - You have stopped the job, but the job has not stopped importing users yet.</p> </li> <li> <p> <code>Stopped</code> - You have stopped the job, and the job has stopped importing users.</p> </li> <li> <p> <code>Succeeded</code> - The job has completed successfully.</p> </li> <li> <p> <code>Failed</code> - The job has stopped due to an error.</p> </li> <li> <p> <code>Expired</code> - You created a job, but did not start the job within 24-48 hours. All data associated with the job was deleted, and the job cannot be started.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EUserImportJobStatusType status = EUserImportJobStatusType::NOT_SET;

    /**
    *  <p>The role ARN for the Amazon CloudWatch Logging role for the user import job. For more information, see "Creating the CloudWatch Logs IAM Role" in the Amazon Cognito Developer Guide.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString cloudWatchLogsRoleArn;

    /**
    *  <p>The number of users that were successfully imported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int64 importedUsers = 0;

    /**
    *  <p>The number of users that were skipped.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int64 skippedUsers = 0;

    /**
    *  <p>The number of users that could not be imported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int64 failedUsers = 0;

    /**
    *  <p>The message returned when the user import job is completed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString completionMessage;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUserImportJobType &fromAWS(const Aws::CognitoIdentityProvider::Model::UserImportJobType &awsUserImportJobType) {
        this->jobName = UTF8_TO_TCHAR(awsUserImportJobType.GetJobName().c_str());

        this->jobId = UTF8_TO_TCHAR(awsUserImportJobType.GetJobId().c_str());

        this->userPoolId = UTF8_TO_TCHAR(awsUserImportJobType.GetUserPoolId().c_str());

        this->preSignedUrl = UTF8_TO_TCHAR(awsUserImportJobType.GetPreSignedUrl().c_str());

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsUserImportJobType.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        this->startDate = FDateTime(1970, 1, 1) + FTimespan(awsUserImportJobType.GetStartDate().Millis() * ETimespan::TicksPerMillisecond);

        this->completionDate = FDateTime(1970, 1, 1) + FTimespan(awsUserImportJobType.GetCompletionDate().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsUserImportJobType.GetStatus()) {
            case Aws::CognitoIdentityProvider::Model::UserImportJobStatusType::NOT_SET:
                this->status = EUserImportJobStatusType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::UserImportJobStatusType::Created:
                this->status = EUserImportJobStatusType::Created;
                break;
            case Aws::CognitoIdentityProvider::Model::UserImportJobStatusType::Pending:
                this->status = EUserImportJobStatusType::Pending;
                break;
            case Aws::CognitoIdentityProvider::Model::UserImportJobStatusType::InProgress:
                this->status = EUserImportJobStatusType::InProgress;
                break;
            case Aws::CognitoIdentityProvider::Model::UserImportJobStatusType::Stopping:
                this->status = EUserImportJobStatusType::Stopping;
                break;
            case Aws::CognitoIdentityProvider::Model::UserImportJobStatusType::Expired:
                this->status = EUserImportJobStatusType::Expired;
                break;
            case Aws::CognitoIdentityProvider::Model::UserImportJobStatusType::Stopped:
                this->status = EUserImportJobStatusType::Stopped;
                break;
            case Aws::CognitoIdentityProvider::Model::UserImportJobStatusType::Failed:
                this->status = EUserImportJobStatusType::Failed;
                break;
            case Aws::CognitoIdentityProvider::Model::UserImportJobStatusType::Succeeded:
                this->status = EUserImportJobStatusType::Succeeded;
                break;
            default:
                this->status = EUserImportJobStatusType::NOT_SET;
                break;
        }

        this->cloudWatchLogsRoleArn = UTF8_TO_TCHAR(awsUserImportJobType.GetCloudWatchLogsRoleArn().c_str());

        this->importedUsers = (int64)awsUserImportJobType.GetImportedUsers();

        this->skippedUsers = (int64)awsUserImportJobType.GetSkippedUsers();

        this->failedUsers = (int64)awsUserImportJobType.GetFailedUsers();

        this->completionMessage = UTF8_TO_TCHAR(awsUserImportJobType.GetCompletionMessage().c_str());

        return *this;
    }
#endif
};
