/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/MFAOptionType.h"

#endif

#include "Model/DeliveryMediumType.h"

#include "MFAOptionType.generated.h"

USTRUCT(BlueprintType)
struct FMFAOptionType {
GENERATED_BODY()

    /**
    *  <p>The delivery medium (email message or SMS message) to send the MFA code.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EDeliveryMediumType deliveryMedium = EDeliveryMediumType::NOT_SET;

    /**
    *  <p>The attribute name of the MFA option type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString attributeName;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::MFAOptionType toAWS() const {
        Aws::CognitoIdentityProvider::Model::MFAOptionType awsMFAOptionType;

        switch(this->deliveryMedium) {
            case EDeliveryMediumType::SMS:
                awsMFAOptionType.SetDeliveryMedium(Aws::CognitoIdentityProvider::Model::DeliveryMediumType::SMS);
                break;
            case EDeliveryMediumType::EMAIL:
                awsMFAOptionType.SetDeliveryMedium(Aws::CognitoIdentityProvider::Model::DeliveryMediumType::EMAIL);
                break;
            default:
                break;
        }

        if (!(this->attributeName.IsEmpty())) {
            awsMFAOptionType.SetAttributeName(TCHAR_TO_UTF8(*this->attributeName));
        }

        return awsMFAOptionType;
    }

    bool IsEmpty() const {
        return this->deliveryMedium == EDeliveryMediumType::NOT_SET && this->attributeName.IsEmpty();
    }

    FMFAOptionType &fromAWS(const Aws::CognitoIdentityProvider::Model::MFAOptionType &awsMFAOptionType) {
        switch(awsMFAOptionType.GetDeliveryMedium()) {
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

        this->attributeName = UTF8_TO_TCHAR(awsMFAOptionType.GetAttributeName().c_str());

        return *this;
    }
#endif
};
