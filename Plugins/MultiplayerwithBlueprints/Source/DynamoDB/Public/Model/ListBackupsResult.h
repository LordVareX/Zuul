/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListBackupsResult.h"

#endif

#include "Model/BackupSummary.h"

#include "ListBackupsResult.generated.h"

USTRUCT(BlueprintType)
struct FListBackupsResult {
GENERATED_BODY()

    /**
    *  <p>List of <code>BackupSummary</code> objects.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FBackupSummary> backupSummaries;

    /**
    *  <p> The ARN of the backup last evaluated when the current page of results was returned, inclusive of the current page of results. This value may be specified as the <code>ExclusiveStartBackupArn</code> of a new <code>ListBackups</code> operation in order to fetch the next page of results. </p> <p> If <code>LastEvaluatedBackupArn</code> is empty, then the last page of results has been processed and there are no more results to be retrieved. </p> <p> If <code>LastEvaluatedBackupArn</code> is not empty, this may or may not indicate that there is more data to be returned. All results are guaranteed to have been returned if and only if no value for <code>LastEvaluatedBackupArn</code> is returned. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString lastEvaluatedBackupArn;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FListBackupsResult &fromAWS(const Aws::DynamoDB::Model::ListBackupsResult &awsListBackupsResult) {
        this->backupSummaries.Empty();
        for (const Aws::DynamoDB::Model::BackupSummary& elem : awsListBackupsResult.GetBackupSummaries()) {
            this->backupSummaries.Add(FBackupSummary().fromAWS(elem));
        }

        this->lastEvaluatedBackupArn = UTF8_TO_TCHAR(awsListBackupsResult.GetLastEvaluatedBackupArn().c_str());

        return *this;
    }
#endif
};
