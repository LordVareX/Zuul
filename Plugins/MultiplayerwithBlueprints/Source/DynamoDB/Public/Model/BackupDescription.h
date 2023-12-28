/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BackupDescription.h"

#endif

#include "Model/BackupDetails.h"
#include "Model/SourceTableDetails.h"
#include "Model/SourceTableFeatureDetails.h"

#include "BackupDescription.generated.h"

USTRUCT(BlueprintType)
struct FBackupDescription {
GENERATED_BODY()

    /**
    *  <p>Contains the details of the backup created for the table. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FBackupDetails backupDetails;

    /**
    *  <p>Contains the details of the table when the backup was created. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FSourceTableDetails sourceTableDetails;

    /**
    *  <p>Contains the details of the features enabled on the table when the backup was created. For example, LSIs, GSIs, streams, TTL.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FSourceTableFeatureDetails sourceTableFeatureDetails;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FBackupDescription &fromAWS(const Aws::DynamoDB::Model::BackupDescription &awsBackupDescription) {
        this->backupDetails.fromAWS(awsBackupDescription.GetBackupDetails());

        this->sourceTableDetails.fromAWS(awsBackupDescription.GetSourceTableDetails());

        this->sourceTableFeatureDetails.fromAWS(awsBackupDescription.GetSourceTableFeatureDetails());

        return *this;
    }
#endif
};
