/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/RestoreTableFromBackupResult.h"

#endif

#include "Model/TableDescription.h"

#include "RestoreTableFromBackupResult.generated.h"

USTRUCT(BlueprintType)
struct FRestoreTableFromBackupResult {
GENERATED_BODY()

    /**
    *  <p>The description of the table created from an existing backup.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FTableDescription tableDescription;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FRestoreTableFromBackupResult &fromAWS(const Aws::DynamoDB::Model::RestoreTableFromBackupResult &awsRestoreTableFromBackupResult) {
        this->tableDescription.fromAWS(awsRestoreTableFromBackupResult.GetTableDescription());

        return *this;
    }
#endif
};
