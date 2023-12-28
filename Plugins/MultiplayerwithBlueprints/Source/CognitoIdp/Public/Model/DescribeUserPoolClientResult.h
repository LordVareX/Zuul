/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DescribeUserPoolClientResult.h"

#endif

#include "Model/UserPoolClientType.h"

#include "DescribeUserPoolClientResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeUserPoolClientResult {
GENERATED_BODY()

    /**
    *  <p>The user pool client from a server response to describe the user pool client.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolClientType userPoolClient;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FDescribeUserPoolClientResult &fromAWS(const Aws::CognitoIdentityProvider::Model::DescribeUserPoolClientResult &awsDescribeUserPoolClientResult) {
        this->userPoolClient.fromAWS(awsDescribeUserPoolClientResult.GetUserPoolClient());

        return *this;
    }
#endif
};
