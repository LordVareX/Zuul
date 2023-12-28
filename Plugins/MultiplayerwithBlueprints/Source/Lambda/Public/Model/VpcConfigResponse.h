/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/VpcConfigResponse.h"

#endif

#include "VpcConfigResponse.generated.h"

USTRUCT(BlueprintType)
struct FVpcConfigResponse {
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

    /**
    *  <p>The ID of the VPC.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString vpcId;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FVpcConfigResponse &fromAWS(const Aws::Lambda::Model::VpcConfigResponse &awsVpcConfigResponse) {
        this->subnetIds.Empty();
        for (const Aws::String& elem : awsVpcConfigResponse.GetSubnetIds()) {
            this->subnetIds.Add(elem.c_str());
        }

        this->securityGroupIds.Empty();
        for (const Aws::String& elem : awsVpcConfigResponse.GetSecurityGroupIds()) {
            this->securityGroupIds.Add(elem.c_str());
        }

        this->vpcId = UTF8_TO_TCHAR(awsVpcConfigResponse.GetVpcId().c_str());

        return *this;
    }
#endif
};
