/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/DeleteBackupRequest.h"

#endif

#include "DeleteBackupRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteBackupRequest {
GENERATED_BODY()

    /**
    *  <p>The ARN associated with the backup.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString backupArn;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    Aws::DynamoDB::Model::DeleteBackupRequest toAWS() const {
        Aws::DynamoDB::Model::DeleteBackupRequest awsDeleteBackupRequest;

		if (!(this->backupArn.IsEmpty())) {
            awsDeleteBackupRequest.SetBackupArn(TCHAR_TO_UTF8(*this->backupArn));
        }

        return awsDeleteBackupRequest;
    }

    bool IsEmpty() const {
        return this->backupArn.IsEmpty();
    }
#endif
};
