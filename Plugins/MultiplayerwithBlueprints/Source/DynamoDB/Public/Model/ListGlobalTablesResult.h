/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListGlobalTablesResult.h"

#endif

#include "Model/GlobalTable.h"

#include "ListGlobalTablesResult.generated.h"

USTRUCT(BlueprintType)
struct FListGlobalTablesResult {
GENERATED_BODY()

    /**
    *  <p>List of global table names.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FGlobalTable> globalTables;

    /**
    *  <p>Last evaluated global table name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString lastEvaluatedGlobalTableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FListGlobalTablesResult &fromAWS(const Aws::DynamoDB::Model::ListGlobalTablesResult &awsListGlobalTablesResult) {
        this->globalTables.Empty();
        for (const Aws::DynamoDB::Model::GlobalTable& elem : awsListGlobalTablesResult.GetGlobalTables()) {
            this->globalTables.Add(FGlobalTable().fromAWS(elem));
        }

        this->lastEvaluatedGlobalTableName = UTF8_TO_TCHAR(awsListGlobalTablesResult.GetLastEvaluatedGlobalTableName().c_str());

        return *this;
    }
#endif
};
