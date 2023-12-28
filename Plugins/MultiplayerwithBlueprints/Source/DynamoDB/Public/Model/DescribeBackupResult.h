/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeBackupResult.h"

#endif

#include "Model/BackupDescription.h"

#include "DescribeBackupResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeBackupResult {
GENERATED_BODY()

    /**
    *  <p>Contains the description of the backup created for the table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FBackupDescription backupDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FDescribeBackupResult &fromAWS(const Aws::DynamoDB::Model::DescribeBackupResult &awsDescribeBackupResult) {
        this->backupDescription.fromAWS(awsDescribeBackupResult.GetBackupDescription());

        return *this;
    }
#endif
};
