/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListLocationsRequest.h"

#endif

#include "Model/AWSGameLiftLocationFilter.h"

#include "AWSGameLiftListLocationsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftListLocationsRequest {
GENERATED_BODY()

    /**
    *  <p>Filters the list for <code>AWS</code> or <code>CUSTOM</code> locations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<EAWSGameLiftLocationFilter> filters;

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
    Aws::GameLift::Model::ListLocationsRequest toAWS() const {
        Aws::GameLift::Model::ListLocationsRequest awsListLocationsRequest;

        for (const EAWSGameLiftLocationFilter& elem : this->filters) {
		    switch(elem) {
                case EAWSGameLiftLocationFilter::AWS:
                    awsListLocationsRequest.AddFilters(Aws::GameLift::Model::LocationFilter::AWS);
                    break;
                case EAWSGameLiftLocationFilter::CUSTOM:
                    awsListLocationsRequest.AddFilters(Aws::GameLift::Model::LocationFilter::CUSTOM);
                    break;
                default:
                    break;
            };
        }

        if (!(this->limit == 0)) {
            awsListLocationsRequest.SetLimit(this->limit);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsListLocationsRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsListLocationsRequest;
    }

    bool IsEmpty() const {
        return this->filters.Num() == 0 && this->limit == 0 && this->nextToken.IsEmpty();
    }
#endif
};
