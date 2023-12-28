/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListEventSourceMappingsResult.h"

#endif

#include "Model/EventSourceMappingConfiguration.h"

#include "ListEventSourceMappingsResult.generated.h"

USTRUCT(BlueprintType)
struct FListEventSourceMappingsResult {
GENERATED_BODY()

    /**
    *  <p>A pagination token that's returned when the response doesn't contain all event source mappings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

    /**
    *  <p>A list of event source mappings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FEventSourceMappingConfiguration> eventSourceMappings;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FListEventSourceMappingsResult &fromAWS(const Aws::Lambda::Model::ListEventSourceMappingsResult &awsListEventSourceMappingsResult) {
        this->nextMarker = UTF8_TO_TCHAR(awsListEventSourceMappingsResult.GetNextMarker().c_str());

        this->eventSourceMappings.Empty();
        for (const Aws::Lambda::Model::EventSourceMappingConfiguration& elem : awsListEventSourceMappingsResult.GetEventSourceMappings()) {
            this->eventSourceMappings.Add(FEventSourceMappingConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
