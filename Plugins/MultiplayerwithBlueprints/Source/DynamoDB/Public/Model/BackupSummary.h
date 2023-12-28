/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BackupSummary.h"

#endif

#include "Model/BackupStatus.h"
#include "Model/BackupType.h"

#include "BackupSummary.generated.h"

USTRUCT(BlueprintType)
struct FBackupSummary {
GENERATED_BODY()

    /**
    *  <p>Name of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>Unique identifier for the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableId;

    /**
    *  <p>ARN associated with the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableArn;

    /**
    *  <p>ARN associated with the backup.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString backupArn;

    /**
    *  <p>Name of the specified backup.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString backupName;

    /**
    *  <p>Time at which the backup was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime backupCreationDateTime;

    /**
    *  <p>Time at which the automatic on-demand backup created by DynamoDB will expire. This <code>SYSTEM</code> on-demand backup expires automatically 35 days after its creation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime backupExpiryDateTime;

    /**
    *  <p>Backup can be in one of the following states: CREATING, ACTIVE, DELETED.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBackupStatus backupStatus = EAWSBackupStatus::NOT_SET;

    /**
    *  <p>BackupType:</p> <ul> <li> <p> <code>USER</code> - You create and manage these using the on-demand backup feature.</p> </li> <li> <p> <code>SYSTEM</code> - If you delete a table with point-in-time recovery enabled, a <code>SYSTEM</code> backup is automatically created and is retained for 35 days (at no additional cost). System backups allow you to restore the deleted table to the state it was in just before the point of deletion. </p> </li> <li> <p> <code>AWS_BACKUP</code> - On-demand backup created by you from AWS Backup service.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBackupType backupType = EAWSBackupType::NOT_SET;

    /**
    *  <p>Size of the backup in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 backupSizeBytes = 0;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FBackupSummary &fromAWS(const Aws::DynamoDB::Model::BackupSummary &awsBackupSummary) {
        this->tableName = UTF8_TO_TCHAR(awsBackupSummary.GetTableName().c_str());

        this->tableId = UTF8_TO_TCHAR(awsBackupSummary.GetTableId().c_str());

        this->tableArn = UTF8_TO_TCHAR(awsBackupSummary.GetTableArn().c_str());

        this->backupArn = UTF8_TO_TCHAR(awsBackupSummary.GetBackupArn().c_str());

        this->backupName = UTF8_TO_TCHAR(awsBackupSummary.GetBackupName().c_str());

        this->backupCreationDateTime = FDateTime(1970, 1, 1) + FTimespan(awsBackupSummary.GetBackupCreationDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->backupExpiryDateTime = FDateTime(1970, 1, 1) + FTimespan(awsBackupSummary.GetBackupExpiryDateTime().Millis() * ETimespan::TicksPerMillisecond);

        switch(awsBackupSummary.GetBackupStatus()) {
            case Aws::DynamoDB::Model::BackupStatus::NOT_SET:
                this->backupStatus = EAWSBackupStatus::NOT_SET;
                break;
            case Aws::DynamoDB::Model::BackupStatus::CREATING:
                this->backupStatus = EAWSBackupStatus::CREATING;
                break;
            case Aws::DynamoDB::Model::BackupStatus::DELETED:
                this->backupStatus = EAWSBackupStatus::DELETED;
                break;
            case Aws::DynamoDB::Model::BackupStatus::AVAILABLE:
                this->backupStatus = EAWSBackupStatus::AVAILABLE;
                break;
            default:
                this->backupStatus = EAWSBackupStatus::NOT_SET;
                break;
            }

        switch(awsBackupSummary.GetBackupType()) {
            case Aws::DynamoDB::Model::BackupType::NOT_SET:
                this->backupType = EAWSBackupType::NOT_SET;
                break;
            case Aws::DynamoDB::Model::BackupType::USER:
                this->backupType = EAWSBackupType::USER;
                break;
            case Aws::DynamoDB::Model::BackupType::SYSTEM:
                this->backupType = EAWSBackupType::SYSTEM;
                break;
            case Aws::DynamoDB::Model::BackupType::AWS_BACKUP:
                this->backupType = EAWSBackupType::AWS_BACKUP;
                break;
            default:
                this->backupType = EAWSBackupType::NOT_SET;
                break;
            }

        this->backupSizeBytes = (int64)awsBackupSummary.GetBackupSizeBytes();

        return *this;
    }
#endif
};
