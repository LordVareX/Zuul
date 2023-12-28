/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DescribeBackupRequest.h"

#endif

#include "DescribeBackupRequest.generated.h"

USTRUCT(BlueprintType)
struct FDescribeBackupRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) associated with the backup.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString backupArn;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DescribeBackupRequest toAWS() const {
        Aws::DynamoDB::Model::DescribeBackupRequest awsDescribeBackupRequest;

		if (!(this->backupArn.IsEmpty())) {
            awsDescribeBackupRequest.SetBackupArn(TCHAR_TO_UTF8(*this->backupArn));
        }

        return awsDescribeBackupRequest;
    }

    bool IsEmpty() const {
        return this->backupArn.IsEmpty();
    }
#endif
};
