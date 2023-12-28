/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/AliasRoutingConfiguration.h"

#endif

#include "AliasRoutingConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAliasRoutingConfiguration {
GENERATED_BODY()

    /**
    *  <p>The name of the second alias, and the percentage of traffic that's routed to it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TMap<FString, float> additionalVersionWeights;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::AliasRoutingConfiguration toAWS() const {
        Aws::Lambda::Model::AliasRoutingConfiguration awsAliasRoutingConfiguration;

        for (const TPair<FString, float>& elem : this->additionalVersionWeights) {
            awsAliasRoutingConfiguration.AddAdditionalVersionWeights(TCHAR_TO_UTF8(*elem.Key), elem.Value);
        }

        return awsAliasRoutingConfiguration;
    }

    bool IsEmpty() const {
        return this->additionalVersionWeights.Num() == 0;
    }

    FAliasRoutingConfiguration &fromAWS(const Aws::Lambda::Model::AliasRoutingConfiguration &awsAliasRoutingConfiguration) {
        this->additionalVersionWeights.Empty();
        for (const auto& elem : awsAliasRoutingConfiguration.GetAdditionalVersionWeights()) {
            this->additionalVersionWeights.Add(elem.first.c_str(), (float)elem.second);
        }

        return *this;
    }
#endif
};
