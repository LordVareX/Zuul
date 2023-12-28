/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminCreateUserResult.h"

#endif

#include "Model/UserType.h"

#include "AdminCreateUserResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminCreateUserResult {
GENERATED_BODY()

    /**
    *  <p>The newly created user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserType user;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminCreateUserResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminCreateUserResult &awsAdminCreateUserResult) {
        this->user.fromAWS(awsAdminCreateUserResult.GetUser());

        return *this;
    }
#endif
};
