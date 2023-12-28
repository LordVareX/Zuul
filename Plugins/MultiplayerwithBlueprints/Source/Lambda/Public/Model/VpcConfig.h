/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/VpcConfig.h"

#endif

#include "VpcConfig.generated.h"

USTRUCT(BlueprintType)
struct FVpcConfig {
GENERATED_BODY()

    /**
    *  <p>A list of VPC subnet IDs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> subnetIds;

    /**
    *  <p>A list of VPC security groups IDs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> securityGroupIds;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::VpcConfig toAWS() const {
        Aws::Lambda::Model::VpcConfig awsVpcConfig;

        for (const FString& elem : this->subnetIds) {
            awsVpcConfig.AddSubnetIds(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->securityGroupIds) {
            awsVpcConfig.AddSecurityGroupIds(TCHAR_TO_UTF8(*elem));
        }

        return awsVpcConfig;
    }

    bool IsEmpty() const {
        return this->subnetIds.Num() == 0 && this->securityGroupIds.Num() == 0;
    }
#endif
};
