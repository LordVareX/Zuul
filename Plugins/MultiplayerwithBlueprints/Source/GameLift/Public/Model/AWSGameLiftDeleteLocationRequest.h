/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DeleteLocationRequest.h"

#endif

#include "AWSGameLiftDeleteLocationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDeleteLocationRequest {
GENERATED_BODY()

    /**
    *  <p>The location name of the custom location to be deleted.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString locationName;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::DeleteLocationRequest toAWS() const {
        Aws::GameLift::Model::DeleteLocationRequest awsDeleteLocationRequest;

        if (!(this->locationName.IsEmpty())) {
            awsDeleteLocationRequest.SetLocationName(TCHAR_TO_UTF8(*this->locationName));
        }

        return awsDeleteLocationRequest;
    }

    bool IsEmpty() const {
        return this->locationName.IsEmpty();
    }
#endif
};
