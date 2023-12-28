/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GetComputeAuthTokenResult.h"

#endif

#include "AWSGameLiftGetComputeAuthTokenResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftGetComputeAuthTokenResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet that the compute is registered to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p>The name of the compute resource you are requesting the authorization token for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeName;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift compute resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::compute/compute-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeArn;

    /**
    *  <p>The authorization token that your game server uses to authenticate with GameLift.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString authToken;

    /**
    *  <p>The amount of time until the authorization token is no longer valid. To continue using the compute resource for game server hosting, renew the authorization token by using this operation again.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FDateTime expirationTimestamp;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftGetComputeAuthTokenResult &fromAWS(const Aws::GameLift::Model::GetComputeAuthTokenResult &awsGetComputeAuthTokenResult) {
        this->fleetId = UTF8_TO_TCHAR(awsGetComputeAuthTokenResult.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsGetComputeAuthTokenResult.GetFleetArn().c_str());

        this->computeName = UTF8_TO_TCHAR(awsGetComputeAuthTokenResult.GetComputeName().c_str());

        this->computeArn = UTF8_TO_TCHAR(awsGetComputeAuthTokenResult.GetComputeArn().c_str());

        this->authToken = UTF8_TO_TCHAR(awsGetComputeAuthTokenResult.GetAuthToken().c_str());

        this->expirationTimestamp = FDateTime(1970, 1, 1) + FTimespan(awsGetComputeAuthTokenResult.GetExpirationTimestamp().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
