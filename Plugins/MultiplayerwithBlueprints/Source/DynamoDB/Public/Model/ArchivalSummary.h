/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ArchivalSummary.h"

#endif

#include "ArchivalSummary.generated.h"

USTRUCT(BlueprintType)
struct FArchivalSummary {
GENERATED_BODY()

    /**
    *  <p>The date and time when table archival was initiated by DynamoDB, in UNIX epoch time format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FDateTime archivalDateTime;

    /**
    *  <p>The reason DynamoDB archived the table. Currently, the only possible value is:</p> <ul> <li> <p> <code>INACCESSIBLE_ENCRYPTION_CREDENTIALS</code> - The table was archived due to the table's AWS KMS key being inaccessible for more than seven days. An On-Demand backup was created at the archival time.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString archivalReason;

    /**
    *  <p>The Amazon Resource Name (ARN) of the backup the table was archived to, when applicable in the archival reason. If you wish to restore this backup to the same table name, you will need to delete the original table.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString archivalBackupArn;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FArchivalSummary &fromAWS(const Aws::DynamoDB::Model::ArchivalSummary &awsArchivalSummary) {
        this->archivalDateTime = FDateTime(1970, 1, 1) + FTimespan(awsArchivalSummary.GetArchivalDateTime().Millis() * ETimespan::TicksPerMillisecond);

        this->archivalReason = UTF8_TO_TCHAR(awsArchivalSummary.GetArchivalReason().c_str());

        this->archivalBackupArn = UTF8_TO_TCHAR(awsArchivalSummary.GetArchivalBackupArn().c_str());

        return *this;
    }
#endif
};
