/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DeleteBackupResult.h"

#endif

#include "Model/BackupDescription.h"

#include "DeleteBackupResult.generated.h"

USTRUCT(BlueprintType)
struct FDeleteBackupResult {
GENERATED_BODY()

    /**
    *  <p>Contains the description of the backup created for the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FBackupDescription backupDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDeleteBackupResult &fromAWS(const Aws::DynamoDB::Model::DeleteBackupResult &awsDeleteBackupResult) {
        this->backupDescription.fromAWS(awsDeleteBackupResult.GetBackupDescription());

        return *this;
    }
#endif
};
