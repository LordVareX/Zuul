/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/RestoreSummary.h"

#endif

#include "RestoreSummary.generated.h"

USTRUCT(BlueprintType)
struct FRestoreSummary {
GENERATED_BODY()

    /**
    *  <p>ARN of the backup from which the table was restored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString sourceBackupArn;

    /**
    *  <p>ARN of the source table of the backup that is being restored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString sourceTableArn;

    /**
    *  <p>Point in time or source backup time.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime restoreDateTime;

    /**
    *  <p>Indicates if a restore is in progress or not.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    bool restoreInProgress = false;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FRestoreSummary &fromAWS(const Aws::DynamoDB::Model::RestoreSummary &awsRestoreSummary) {
        this->sourceBackupArn = UTF8_TO_TCHAR(awsRestoreSummary.GetSourceBackupArn().c_str());

        this->sourceTableArn = UTF8_TO_TCHAR(awsRestoreSummary.GetSourceTableArn().c_str());

        this->restoreDateTime = FDateTime(1970, 1, 1) + FTimespan(awsRestoreSummary.GetRestoreDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->restoreInProgress = awsRestoreSummary.GetRestoreInProgress();

        return *this;
    }
#endif
};
