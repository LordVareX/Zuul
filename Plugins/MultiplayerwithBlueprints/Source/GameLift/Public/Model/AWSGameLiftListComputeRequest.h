/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListComputeRequest.h"

#endif

#include "AWSGameLiftListComputeRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftListComputeRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier for the fleet the compute resources are registered to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString fleetId;

    /**
    *  <p>The name of the custom location that the compute resources are assigned to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString location;

    /**
    *  <p>The maximum number of results to return. Use this parameter with <code>NextToken</code> to get results as a set of sequential pages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    int limit = 0;

    /**
    *  <p>A token that indicates the start of the next sequential page of results. Use the token that is returned with a previous call to this operation. To start at the beginning of the result set, do not specify a value.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::ListComputeRequest toAWS() const {
        Aws::GameLift::Model::ListComputeRequest awsListComputeRequest;

        if (!(this->fleetId.IsEmpty())) {
            awsListComputeRequest.SetFleetId(TCHAR_TO_UTF8(*this->fleetId));
        }

        if (!(this->location.IsEmpty())) {
            awsListComputeRequest.SetLocation(TCHAR_TO_UTF8(*this->location));
        }

        if (!(this->limit == 0)) {
            awsListComputeRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListComputeRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListComputeRequest;
    }

    bool IsEmpty() const {
        return this->fleetId.IsEmpty() && this->location.IsEmpty() && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
