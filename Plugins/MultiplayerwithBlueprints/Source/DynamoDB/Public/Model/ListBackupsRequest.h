/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListBackupsRequest.h"

#endif

#include "Model/BackupTypeFilter.h"

#include "ListBackupsRequest.generated.h"

USTRUCT(BlueprintType)
struct FListBackupsRequest {
GENERATED_BODY()

    /**
    *  <p>The backups from the table specified by <code>TableName</code> are listed. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>Maximum number of backups to return at once.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int limit = 0;

    /**
    *  <p>Only backups created after this time are listed. <code>TimeRangeLowerBound</code> is inclusive.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime timeRangeLowerBound;

    /**
    *  <p>Only backups created before this time are listed. <code>TimeRangeUpperBound</code> is exclusive. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime timeRangeUpperBound;

    /**
    *  <p> <code>LastEvaluatedBackupArn</code> is the Amazon Resource Name (ARN) of the backup last evaluated when the current page of results was returned, inclusive of the current page of results. This value may be specified as the <code>ExclusiveStartBackupArn</code> of a new <code>ListBackups</code> operation in order to fetch the next page of results. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString exclusiveStartBackupArn;

    /**
    *  <p>The backups from the table specified by <code>BackupType</code> are listed.</p> <p>Where <code>BackupType</code> can be:</p> <ul> <li> <p> <code>USER</code> - On-demand backup created by you.</p> </li> <li> <p> <code>SYSTEM</code> - On-demand backup automatically created by DynamoDB.</p> </li> <li> <p> <code>ALL</code> - All types of on-demand backups (USER and SYSTEM).</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBackupTypeFilter backupType = EAWSBackupTypeFilter::NOT_SET;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::ListBackupsRequest toAWS() const {
        Aws::DynamoDB::Model::ListBackupsRequest awsListBackupsRequest;

		if (!(this->tableName.IsEmpty())) {
            awsListBackupsRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

        if (this->limit != 0) {
            awsListBackupsRequest.SetLimit(this->limit);
        }

        awsListBackupsRequest.SetTimeRangeLowerBound(Aws::Utils::DateTime((int64_t)((this->timeRangeLowerBound - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));

        awsListBackupsRequest.SetTimeRangeUpperBound(Aws::Utils::DateTime((int64_t)((this->timeRangeUpperBound - FDateTime(1970, 1, 1)).GetTicks() / ETimespan::TicksPerMillisecond)));

		if (!(this->exclusiveStartBackupArn.IsEmpty())) {
            awsListBackupsRequest.SetExclusiveStartBackupArn(TCHAR_TO_UTF8(*this->exclusiveStartBackupArn));
        }

        switch(this->backupType) {
            case EAWSBackupTypeFilter::USER:
                awsListBackupsRequest.SetBackupType(Aws::DynamoDB::Model::BackupTypeFilter::USER);
                break;
            case EAWSBackupTypeFilter::SYSTEM:
                awsListBackupsRequest.SetBackupType(Aws::DynamoDB::Model::BackupTypeFilter::SYSTEM);
                break;
            case EAWSBackupTypeFilter::AWS_BACKUP:
                awsListBackupsRequest.SetBackupType(Aws::DynamoDB::Model::BackupTypeFilter::AWS_BACKUP);
                break;
            case EAWSBackupTypeFilter::ALL:
                awsListBackupsRequest.SetBackupType(Aws::DynamoDB::Model::BackupTypeFilter::ALL);
                break;
            default:
                break;
            }

        return awsListBackupsRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->limit == 0 && false && false && this->exclusiveStartBackupArn.IsEmpty() && this->backupType == EAWSBackupTypeFilter::NOT_SET;
    }
#endif
};
