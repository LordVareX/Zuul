/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/LocationModel.h"

#endif


#include "AWSGameLiftLocationModel.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftLocationModel {
GENERATED_BODY()

    /**
    *  <p>The location's name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString locationName;
    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift location resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::location/location-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString locationArn;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:

    FAWSGameLiftLocationModel &fromAWS(const Aws::GameLift::Model::LocationModel &awsLocationModel) {
// @TODO: check
        this->locationName = UTF8_TO_TCHAR(awsLocationModel.GetLocationName().c_str());

// @TODO: check
        this->locationArn = UTF8_TO_TCHAR(awsLocationModel.GetLocationArn().c_str());

        return *this;
    }
#endif
};
