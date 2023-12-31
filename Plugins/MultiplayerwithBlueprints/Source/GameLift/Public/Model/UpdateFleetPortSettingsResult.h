/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/UpdateFleetPortSettingsResult.h"

#endif

#include "UpdateFleetPortSettingsResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateFleetPortSettingsResult {
GENERATED_BODY()

    /**
    *  <p>Unique identifier for a fleet that was updated.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The Amazon Resource Name (<a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/s3-arn-format.html">ARN</a>) that is assigned to a GameLift fleet resource and uniquely identifies it. ARNs are unique across all Regions. Format is <code>arn:aws:gamelift:&lt;region&gt;::fleet/fleet-a1234567-b8c9-0d1e-2fa3-b45c6d7e8912</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetArn;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FUpdateFleetPortSettingsResult &fromAWS(const Aws::GameLift::Model::UpdateFleetPortSettingsResult &awsUpdateFleetPortSettingsResult) {
        this->fleetId = UTF8_TO_TCHAR(awsUpdateFleetPortSettingsResult.GetFleetId().c_str());

        this->fleetArn = UTF8_TO_TCHAR(awsUpdateFleetPortSettingsResult.GetFleetArn().c_str());

        return *this;
    }
#endif
};
