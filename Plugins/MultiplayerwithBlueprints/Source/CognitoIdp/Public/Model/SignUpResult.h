/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SignUpResult.h"

#endif

#include "Model/CodeDeliveryDetailsType.h"

#include "SignUpResult.generated.h"

USTRUCT(BlueprintType)
struct FSignUpResult {
GENERATED_BODY()

    /**
    *  <p>A response from the server indicating that a user registration has been confirmed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool userConfirmed = false;

    /**
    *  <p>The code delivery details returned by the server response to the user registration request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FCodeDeliveryDetailsType codeDeliveryDetails;

    /**
    *  <p>The UUID of the authenticated user. This is not the same as <code>username</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userSub;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FSignUpResult &fromAWS(const Aws::CognitoIdentityProvider::Model::SignUpResult &awsSignUpResult) {
        this->userConfirmed = awsSignUpResult.GetUserConfirmed();

        this->codeDeliveryDetails.fromAWS(awsSignUpResult.GetCodeDeliveryDetails());

        this->userSub = UTF8_TO_TCHAR(awsSignUpResult.GetUserSub().c_str());

        return *this;
    }
#endif
};
