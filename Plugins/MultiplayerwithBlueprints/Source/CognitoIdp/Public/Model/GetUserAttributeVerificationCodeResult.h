/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetUserAttributeVerificationCodeResult.h"

#endif

#include "Model/CodeDeliveryDetailsType.h"

#include "GetUserAttributeVerificationCodeResult.generated.h"

USTRUCT(BlueprintType)
struct FGetUserAttributeVerificationCodeResult {
GENERATED_BODY()

    /**
    *  <p>The code delivery details returned by the server in response to the request to get the user attribute verification code.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FCodeDeliveryDetailsType codeDeliveryDetails;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FGetUserAttributeVerificationCodeResult &fromAWS(const Aws::CognitoIdentityProvider::Model::GetUserAttributeVerificationCodeResult &awsGetUserAttributeVerificationCodeResult) {
        this->codeDeliveryDetails.fromAWS(awsGetUserAttributeVerificationCodeResult.GetCodeDeliveryDetails());

        return *this;
    }
#endif
};
