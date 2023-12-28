/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ForgotPasswordResult.h"

#endif

#include "Model/CodeDeliveryDetailsType.h"

#include "ForgotPasswordResult.generated.h"

USTRUCT(BlueprintType)
struct FForgotPasswordResult {
GENERATED_BODY()

    /**
    *  <p>The code delivery details returned by the server in response to the request to reset a password.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FCodeDeliveryDetailsType codeDeliveryDetails;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FForgotPasswordResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ForgotPasswordResult &awsForgotPasswordResult) {
        this->codeDeliveryDetails.fromAWS(awsForgotPasswordResult.GetCodeDeliveryDetails());

        return *this;
    }
#endif
};
