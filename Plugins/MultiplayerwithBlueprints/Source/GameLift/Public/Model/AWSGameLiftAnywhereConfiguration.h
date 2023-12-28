/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/AnywhereConfiguration.h"

#endif

#include "AWSGameLiftAnywhereConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftAnywhereConfiguration {
GENERATED_BODY()

    /**
    *  <p>The cost to run your fleet per hour. GameLift uses the provided cost of your fleet to balance usage in queues. For more information about queues, see <a href="https://docs.aws.amazon.com/gamelift/latest/developerguide/queues-intro.html">Setting up queues</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString cost;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::AnywhereConfiguration toAWS() const {
        Aws::GameLift::Model::AnywhereConfiguration awsAnywhereConfiguration;

        if (!(this->cost.IsEmpty())) {
            awsAnywhereConfiguration.SetCost(TCHAR_TO_UTF8(*this->cost));
        }

        return awsAnywhereConfiguration;
    }

    bool IsEmpty() const {
        return this->cost.IsEmpty();
    }

    FAWSGameLiftAnywhereConfiguration &fromAWS(const Aws::GameLift::Model::AnywhereConfiguration &awsAnywhereConfiguration) {
        this->cost = UTF8_TO_TCHAR(awsAnywhereConfiguration.GetCost().c_str());

        return *this;
    }
#endif
};
