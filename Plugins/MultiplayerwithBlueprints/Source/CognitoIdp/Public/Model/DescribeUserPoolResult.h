/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeUserPoolResult.h"

#endif

#include "Model/UserPoolType.h"

#include "DescribeUserPoolResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeUserPoolResult {
GENERATED_BODY()

    /**
    *  <p>The container of metadata returned by the server to describe the pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolType userPool;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FDescribeUserPoolResult &fromAWS(const Aws::CognitoIdentityProvider::Model::DescribeUserPoolResult &awsDescribeUserPoolResult) {
        this->userPool.fromAWS(awsDescribeUserPoolResult.GetUserPool());

        return *this;
    }
#endif
};
