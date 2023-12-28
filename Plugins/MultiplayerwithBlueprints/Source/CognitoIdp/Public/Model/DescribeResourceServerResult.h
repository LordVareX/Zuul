/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeResourceServerResult.h"

#endif

#include "Model/ResourceServerType.h"

#include "DescribeResourceServerResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeResourceServerResult {
GENERATED_BODY()

    /**
    *  <p>The resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FResourceServerType resourceServer;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FDescribeResourceServerResult &fromAWS(const Aws::CognitoIdentityProvider::Model::DescribeResourceServerResult &awsDescribeResourceServerResult) {
        this->resourceServer.fromAWS(awsDescribeResourceServerResult.GetResourceServer());

        return *this;
    }
#endif
};
