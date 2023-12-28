/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateFleetResult.h"

#endif

#include "Model/FleetAttributes.h"
#include "Model/AWSGameLiftLocationState.h"

#include "CreateFleetResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateFleetResult {
GENERATED_BODY()

    /**
    *  <p>Properties for the newly created fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FFleetAttributes fleetAttributes;

    /**
    *  <p>The fleet's locations and life-cycle status of each location. For new fleets, the status of all locations is set to <code>NEW</code>. During fleet creation, GameLift updates each location status as instances are deployed there and prepared for game hosting. This list includes an entry for the fleet's home Region. For fleets with no remote locations, only one entry, representing the home Region, is returned.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSGameLiftLocationState> locationStates;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FCreateFleetResult &fromAWS(const Aws::GameLift::Model::CreateFleetResult &awsCreateFleetResult) {
        this->fleetAttributes.fromAWS(awsCreateFleetResult.GetFleetAttributes());

        this->locationStates.Empty();
        for (const Aws::GameLift::Model::LocationState& elem : awsCreateFleetResult.GetLocationStates()) {
            this->locationStates.Add(FAWSGameLiftLocationState().fromAWS(elem));
        }

        return *this;
    }
#endif
};
