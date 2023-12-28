/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ResendConfirmationCodeResult.h"

#endif

#include "Model/CodeDeliveryDetailsType.h"

#include "ResendConfirmationCodeResult.generated.h"

USTRUCT(BlueprintType)
struct FResendConfirmationCodeResult {
GENERATED_BODY()

    /**
    *  <p>The code delivery details returned by the server in response to the request to resend the confirmation code.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FCodeDeliveryDetailsType codeDeliveryDetails;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FResendConfirmationCodeResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ResendConfirmationCodeResult &awsResendConfirmationCodeResult) {
        this->codeDeliveryDetails.fromAWS(awsResendConfirmationCodeResult.GetCodeDeliveryDetails());

        return *this;
    }
#endif
};
