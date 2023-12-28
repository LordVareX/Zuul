/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/CreateBackupResult.h"

#endif

#include "Model/BackupDetails.h"

#include "CreateBackupResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateBackupResult {
GENERATED_BODY()

    /**
    *  <p>Contains the details of the backup created for the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FBackupDetails backupDetails;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FCreateBackupResult &fromAWS(const Aws::DynamoDB::Model::CreateBackupResult &awsCreateBackupResult) {
        this->backupDetails.fromAWS(awsCreateBackupResult.GetBackupDetails());

        return *this;
    }
#endif
};
