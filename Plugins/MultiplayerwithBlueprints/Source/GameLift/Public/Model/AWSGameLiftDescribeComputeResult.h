/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/DescribeComputeResult.h"

#endif

#include "Model/AWSGameLiftCompute.h"

#include "AWSGameLiftDescribeComputeResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftDescribeComputeResult {
GENERATED_BODY()

    /**
    *  <p>The details of the compute resource you registered to the specified fleet.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FAWSGameLiftCompute compute;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    FAWSGameLiftDescribeComputeResult &fromAWS(const Aws::GameLift::Model::DescribeComputeResult &awsDescribeComputeResult) {
        this->compute.fromAWS(awsDescribeComputeResult.GetCompute());

        return *this;
    }
#endif
};
