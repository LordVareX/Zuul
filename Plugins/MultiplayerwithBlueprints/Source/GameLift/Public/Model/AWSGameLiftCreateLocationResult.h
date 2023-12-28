/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateLocationResult.h"

#endif

#include "Model/AWSGameLiftLocationModel.h"

#include "AWSGameLiftCreateLocationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftCreateLocationResult {
GENERATED_BODY()

    /**
    *  <p>The details of the custom location you created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameLiftLocationModel location;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftCreateLocationResult &fromAWS(const Aws::GameLift::Model::CreateLocationResult &awsCreateLocationResult) {
        this->location.fromAWS(awsCreateLocationResult.GetLocation());

        return *this;
    }
#endif
};
