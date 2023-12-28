/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/GetComputeAccessResult.h"

#endif

#include "Model/GameLiftCredentials.h"

#include "AWSGameLiftGetComputeAccessResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftGetComputeAccessResult {
GENERATED_BODY()

    /**
    *  <p>The fleet ID of compute resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

    /**
    *  <p>The name of the compute resource you requested credentials for.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeName;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift compute resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::compute/compute-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString computeArn;

    /**
    *  <p>The access credentials for the compute resource.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FGameLiftCredentials credentials;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftGetComputeAccessResult &fromAWS(const Aws::GameLift::Model::GetComputeAccessResult &awsGetComputeAccessResult) {
        this->fleetId = UTF8_TO_TCHAR(awsGetComputeAccessResult.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsGetComputeAccessResult.GetFleetArn().c_str());

        this->computeName = UTF8_TO_TCHAR(awsGetComputeAccessResult.GetComputeName().c_str());

        this->computeArn = UTF8_TO_TCHAR(awsGetComputeAccessResult.GetComputeArn().c_str());

        this->credentials.fromAWS(awsGetComputeAccessResult.GetCredentials());

        return *this;
    }
#endif
};
