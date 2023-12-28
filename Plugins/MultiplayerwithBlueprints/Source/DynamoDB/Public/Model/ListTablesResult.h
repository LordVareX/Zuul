/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/ListTablesResult.h"

#endif

#include "ListTablesResult.generated.h"

USTRUCT(BlueprintType)
struct FListTablesResult {
GENERATED_BODY()

    /**
    *  <p>The names of the tables associated with the current account at the current endpoint. The maximum size of this array is 100.</p> <p>If <code>LastEvaluatedTableName</code> also appears in the output, you can use this value as the <code>ExclusiveStartTableName</code> parameter in a subsequent <code>ListTables</code> request and obtain the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FString> tableNames;

    /**
    *  <p>The name of the last table in the current page of results. Use this value as the <code>ExclusiveStartTableName</code> in a new request to obtain the next page of results, until all the table names are returned.</p> <p>If you do not receive a <code>LastEvaluatedTableName</code> value in the response, this means that there are no more table names to be retrieved.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    FString lastEvaluatedTableName;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FListTablesResult &fromAWS(const Aws::DynamoDB::Model::ListTablesResult &awsListTablesResult) {
        this->tableNames.Empty();
        for (const Aws::String& elem : awsListTablesResult.GetTableNames()) {
            this->tableNames.Add(elem.c_str());
        }

        this->lastEvaluatedTableName = UTF8_TO_TCHAR(awsListTablesResult.GetLastEvaluatedTableName().c_str());

        return *this;
    }
#endif
};
