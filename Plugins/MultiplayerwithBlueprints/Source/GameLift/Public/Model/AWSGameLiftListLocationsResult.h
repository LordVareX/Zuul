/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListLocationsResult.h"

#endif

#include "Model/AWSGameLiftLocationModel.h"

#include "AWSGameLiftListLocationsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftListLocationsResult {
GENERATED_BODY()

    /**
    *  <p>A collection of locations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSGameLiftLocationModel> locations;

    /**
    *  <p>A token that indicates where to resume retrieving results on the next call to this operation. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftListLocationsResult &fromAWS(const Aws::GameLift::Model::ListLocationsResult &awsListLocationsResult) {
        this->locations.Empty();
        for (const Aws::GameLift::Model::LocationModel& elem : awsListLocationsResult.GetLocations()) {
            this->locations.Add(FAWSGameLiftLocationModel().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListLocationsResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
