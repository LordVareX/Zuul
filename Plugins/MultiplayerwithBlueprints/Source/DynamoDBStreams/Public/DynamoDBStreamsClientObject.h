/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, November 2019
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"

#include "Auth/AWSCoreCredentials.h"
#include "Client/AWSClientConfiguration.h"

#include "DynamoDBStreamsError.h"

#include "Model/DescribeStreamRequest.h"
#include "Model/GetRecordsRequest.h"
#include "Model/GetShardIteratorRequest.h"
#include "Model/ListStreamsRequest.h"

#include "Model/DescribeStreamResult.h"
#include "Model/GetRecordsResult.h"
#include "Model/GetShardIteratorResult.h"
#include "Model/ListStreamsResult.h"

#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE

#include "aws/dynamodbstreams/DynamoDBStreamsClient.h"

#endif

#include "DynamoDBStreamsClientObject.generated.h"

/**
*  <fullname>Amazon DynamoDB</fullname> <p>Amazon DynamoDB Streams provides API actions for accessing streams and processing stream records. To learn more about application development with Streams, see <a href="https://docs.aws.amazon.com/amazondynamodb/latest/developerguide/Streams.html">Capturing Table Activity with DynamoDB Streams</a> in the Amazon DynamoDB Developer Guide.</p>
**/
UCLASS(BlueprintType)
class DYNAMODBSTREAMS_API UDynamoDBStreamsClientObject : public UObject {
    GENERATED_BODY()

public:
#if WITH_DYNAMODBSTREAMSCLIENTSDK && WITH_CORE
    Aws::DynamoDBStreams::DynamoDBStreamsClient *awsDynamoDBStreamsClient;
#endif

    /**
    * public static UDynamoDBStreamsClientObject::CreateDynamoDBStreamsObject
    * Creates a DynamoDBStreamsClientObject. This function must be called first before accessing any DynamoDB Streams client functions.
    * @param credentials [FAWSCredentials] .
    * @param clientConfiguration [FClientConfiguration] .
    * @return [UDynamoDBStreamsClient*] Returns UDynamoDBStreamsClient*.
    **/
    UFUNCTION(BlueprintCallable, Category = "DynamoDBStreams Client")
    static UDynamoDBStreamsClientObject *
    CreateDynamoDBStreamsObject(const FAWSCredentials &credentials, const FAWSClientConfiguration &clientConfiguration);

    /**
    * <p>Returns information about a stream, including the current status of the stream, its Amazon Resource Name (ARN), the composition of its shards, and its corresponding DynamoDB table.</p> <note> <p>You can call <code>DescribeStream</code> at a maximum rate of 10 times per second.</p> </note> <p>Each shard in the stream has a <code>SequenceNumberRange</code> associated with it. If the <code>SequenceNumberRange</code> has a <code>StartingSequenceNumber</code> but no <code>EndingSequenceNumber</code>, then the shard is still open (able to receive more stream records). If both <code>StartingSequenceNumber</code> and <code>EndingSequenceNumber</code> are present, then that shard is closed and can no longer receive more data.</p>
    * @param
    * @param describeStreamRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "DynamoDBStreams Client")
    void DescribeStream (
        UObject *WorldContextObject,
        bool &success,
        FDescribeStreamRequest describeStreamRequest,
        FDescribeStreamResult &describeStreamResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Retrieves the stream records from a given shard.</p> <p>Specify a shard iterator using the <code>ShardIterator</code> parameter. The shard iterator specifies the position in the shard from which you want to start reading stream records sequentially. If there are no stream records available in the portion of the shard that the iterator points to, <code>GetRecords</code> returns an empty list. Note that it might take multiple calls to get to a portion of the shard that contains stream records.</p> <note> <p> <code>GetRecords</code> can retrieve a maximum of 1 MB of data or 1000 stream records, whichever comes first.</p> </note>
    * @param
    * @param getRecordsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "DynamoDBStreams Client")
    void GetRecords (
        UObject *WorldContextObject,
        bool &success,
        FGetRecordsRequest getRecordsRequest,
        FGetRecordsResult &getRecordsResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns a shard iterator. A shard iterator provides information about how to retrieve the stream records from within a shard. Use the shard iterator in a subsequent <code>GetRecords</code> request to read the stream records from the shard.</p> <note> <p>A shard iterator expires 15 minutes after it is returned to the requester.</p> </note>
    * @param
    * @param getShardIteratorRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "DynamoDBStreams Client")
    void GetShardIterator (
        UObject *WorldContextObject,
        bool &success,
        FGetShardIteratorRequest getShardIteratorRequest,
        FGetShardIteratorResult &getShardIteratorResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns an array of stream ARNs associated with the current account and endpoint. If the <code>TableName</code> parameter is present, then <code>ListStreams</code> will return only the streams ARNs for that table.</p> <note> <p>You can call <code>ListStreams</code> at a maximum rate of 5 times per second.</p> </note>
    * @param
    * @param listStreamsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "DynamoDBStreams Client")
    void ListStreams (
        UObject *WorldContextObject,
        bool &success,
        FListStreamsRequest listStreamsRequest,
        FListStreamsResult &listStreamsResult,
        EDynamoDBStreamsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
};
