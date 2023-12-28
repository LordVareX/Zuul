/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateUserPoolResult.h"

#endif

#include "Model/UserPoolType.h"

#include "CreateUserPoolResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateUserPoolResult {
GENERATED_BODY()

    /**
    *  <p>A container for the user pool details.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolType userPool;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCreateUserPoolResult &fromAWS(const Aws::CognitoIdentityProvider::Model::CreateUserPoolResult &awsCreateUserPoolResult) {
        this->userPool.fromAWS(awsCreateUserPoolResult.GetUserPool());

        return *this;
    }
#endif
};
