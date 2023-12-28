/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateUserPoolClientResult.h"

#endif

#include "Model/UserPoolClientType.h"

#include "UpdateUserPoolClientResult.generated.h"

USTRUCT(BlueprintType)
struct FUpdateUserPoolClientResult {
GENERATED_BODY()

    /**
    *  <p>The user pool client value from the response from the server when an update user pool client request is made.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolClientType userPoolClient;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUpdateUserPoolClientResult &fromAWS(const Aws::CognitoIdentityProvider::Model::UpdateUserPoolClientResult &awsUpdateUserPoolClientResult) {
        this->userPoolClient.fromAWS(awsUpdateUserPoolClientResult.GetUserPoolClient());

        return *this;
    }
#endif
};
