/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/ListComputeResult.h"

#endif

#include "Model/AWSGameLiftCompute.h"

#include "AWSGameLiftListComputeResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftListComputeResult {
GENERATED_BODY()

    /**
    *  <p>A list of compute resources registered to the fleet you specified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FAWSGameLiftCompute> computeList;

    /**
    *  <p>A token that indicates where to resume retrieving results on the next call to this operation. If no token is returned, these results represent the end of the list.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString nextToken;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftListComputeResult &fromAWS(const Aws::GameLift::Model::ListComputeResult &awsListComputeResult) {
        this->computeList.Empty();
        for (const Aws::GameLift::Model::Compute& elem : awsListComputeResult.GetComputeList()) {
            this->computeList.Add(FAWSGameLiftCompute().fromAWS(elem));
        }

        this->nextToken = UTF8_TO_TCHAR(awsListComputeResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
