/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BackupDetails.h"

#endif

#include "Model/BackupStatus.h"
#include "Model/BackupType.h"

#include "BackupDetails.generated.h"

USTRUCT(BlueprintType)
struct FBackupDetails {
GENERATED_BODY()

    /**
    *  <p>ARN associated with the backup.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString backupArn;

    /**
    *  <p>Name of the requested backup.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString backupName;

    /**
    *  <p>Size of the backup in bytes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    int64 backupSizeBytes = 0;

    /**
    *  <p>Backup can be in one of the following states: CREATING, ACTIVE, DELETED. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBackupStatus backupStatus = EAWSBackupStatus::NOT_SET;

    /**
    *  <p>BackupType:</p> <ul> <li> <p> <code>USER</code> - You create and manage these using the on-demand backup feature.</p> </li> <li> <p> <code>SYSTEM</code> - If you delete a table with point-in-time recovery enabled, a <code>SYSTEM</code> backup is automatically created and is retained for 35 days (at no additional cost). System backups allow you to restore the deleted table to the state it was in just before the point of deletion. </p> </li> <li> <p> <code>AWS_BACKUP</code> - On-demand backup created by you from AWS Backup service.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    EAWSBackupType backupType = EAWSBackupType::NOT_SET;

    /**
    *  <p>Time at which the backup was created. This is the request time of the backup. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime backupCreationDateTime;

    /**
    *  <p>Time at which the automatic on-demand backup created by DynamoDB will expire. This <code>SYSTEM</code> on-demand backup expires automatically 35 days after its creation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime backupExpiryDateTime;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FBackupDetails &fromAWS(const Aws::DynamoDB::Model::BackupDetails &awsBackupDetails) {
        this->backupArn = UTF8_TO_TCHAR(awsBackupDetails.GetBackupArn().c_str());

        this->backupName = UTF8_TO_TCHAR(awsBackupDetails.GetBackupName().c_str());

        this->backupSizeBytes = (int64)awsBackupDetails.GetBackupSizeBytes();

        switch(awsBackupDetails.GetBackupStatus()) {
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

        switch(awsBackupDetails.GetBackupType()) {
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

        this->backupCreationDateTime = FDateTime(1970, 1, 1) + FTimespan(awsBackupDetails.GetBackupCreationDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->backupExpiryDateTime = FDateTime(1970, 1, 1) + FTimespan(awsBackupDetails.GetBackupExpiryDateTime().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
