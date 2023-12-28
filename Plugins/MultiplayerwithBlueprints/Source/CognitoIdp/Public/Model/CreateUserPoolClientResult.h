/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateUserPoolClientResult.h"

#endif

#include "Model/UserPoolClientType.h"

#include "CreateUserPoolClientResult.generated.h"

USTRUCT(BlueprintType)
struct FCreateUserPoolClientResult {
GENERATED_BODY()

    /**
    *  <p>The user pool client that was just created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolClientType userPoolClient;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCreateUserPoolClientResult &fromAWS(const Aws::CognitoIdentityProvider::Model::CreateUserPoolClientResult &awsCreateUserPoolClientResult) {
        this->userPoolClient.fromAWS(awsCreateUserPoolClientResult.GetUserPoolClient());

        return *this;
    }
#endif
};
