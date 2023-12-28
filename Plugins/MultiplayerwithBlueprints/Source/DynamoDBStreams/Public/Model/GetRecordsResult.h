/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/model/GetRecordsResult.h"

#endif

#include "Model/DynamoDBStreamsRecord.h"

#include "GetRecordsResult.generated.h"

USTRUCT(BlueprintType)
struct FGetRecordsResult {
GENERATED_BODY()

    /**
    *  <p>The stream records from the shard, which were retrieved using the shard iterator.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    TArray<FDynamoDBStreamsRecord> records;

    /**
    *  <p>The next position in the shard from which to start sequentially reading stream records. If set to <code>null</code>, the shard has been closed and the requested iterator will not return any more data.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDBStreams Client")
    FString nextShardIterator;

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
public:
    FGetRecordsResult &fromAWS(const Aws::DynamoDBStreams::Model::GetRecordsResult &awsGetRecordsResult) {
        this->records.Empty();
        for (const Aws::DynamoDBStreams::Model::Record& elem : awsGetRecordsResult.GetRecords()) {
            this->records.Add(FDynamoDBStreamsRecord().fromAWS(elem));
        }

        this->nextShardIterator = UTF8_TO_TCHAR(awsGetRecordsResult.GetNextShardIterator().c_str());

        return *this;
    }
#endif
};
