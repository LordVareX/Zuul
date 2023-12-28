/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/CreateBackupRequest.h"

#endif

#include "CreateBackupRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateBackupRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString tableName;

    /**
    *  <p>Specified name for the backup.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString backupName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::CreateBackupRequest toAWS() const {
        Aws::DynamoDB::Model::CreateBackupRequest awsCreateBackupRequest;

		if (!(this->tableName.IsEmpty())) {
            awsCreateBackupRequest.SetTableName(TCHAR_TO_UTF8(*this->tableName));
        }

		if (!(this->backupName.IsEmpty())) {
            awsCreateBackupRequest.SetBackupName(TCHAR_TO_UTF8(*this->backupName));
        }

        return awsCreateBackupRequest;
    }

    bool IsEmpty() const {
        return this->tableName.IsEmpty() && this->backupName.IsEmpty();
    }
#endif
};
