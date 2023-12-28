/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CodeDeliveryDetailsType.h"

#endif

#include "Model/DeliveryMediumType.h"

#include "CodeDeliveryDetailsType.generated.h"

USTRUCT(BlueprintType)
struct FCodeDeliveryDetailsType {
GENERATED_BODY()

    /**
    *  <p>The destination for the code delivery details.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString destination;

    /**
    *  <p>The delivery medium (email message or phone number).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EDeliveryMediumType deliveryMedium = EDeliveryMediumType::NOT_SET;

    /**
    *  <p>The attribute name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString attributeName;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FCodeDeliveryDetailsType &fromAWS(const Aws::CognitoIdentityProvider::Model::CodeDeliveryDetailsType &awsCodeDeliveryDetailsType) {
        this->destination = UTF8_TO_TCHAR(awsCodeDeliveryDetailsType.GetDestination().c_str());

        switch(awsCodeDeliveryDetailsType.GetDeliveryMedium()) {
            case Aws::CognitoIdentityProvider::Model::DeliveryMediumType::NOT_SET:
                this->deliveryMedium = EDeliveryMediumType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::DeliveryMediumType::SMS:
                this->deliveryMedium = EDeliveryMediumType::SMS;
                break;
            case Aws::CognitoIdentityProvider::Model::DeliveryMediumType::EMAIL:
                this->deliveryMedium = EDeliveryMediumType::EMAIL;
                break;
            default:
                this->deliveryMedium = EDeliveryMediumType::NOT_SET;
                break;
        }

        this->attributeName = UTF8_TO_TCHAR(awsCodeDeliveryDetailsType.GetAttributeName().c_str());

        return *this;
    }
#endif
};
