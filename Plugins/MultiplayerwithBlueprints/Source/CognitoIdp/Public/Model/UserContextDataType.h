/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserContextDataType.h"

#endif

#include "UserContextDataType.generated.h"

USTRUCT(BlueprintType)
struct FUserContextDataType {
GENERATED_BODY()

    /**
    *  <p>The source IP address of your user's device.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString ipAddress;

    /**
    *  <p>Contextual data such as the user's device fingerprint, IP address, or location used for evaluating the risk of an unexpected event by Amazon Cognito advanced security.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString encodedData;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UserContextDataType toAWS() const {
        Aws::CognitoIdentityProvider::Model::UserContextDataType awsUserContextDataType;

		if (!(this->ipAddress.IsEmpty())) {
            awsUserContextDataType.SetIpAddress(TCHAR_TO_UTF8(*this->ipAddress));
        }

        if (!(this->encodedData.IsEmpty())) {
            awsUserContextDataType.SetEncodedData(TCHAR_TO_UTF8(*this->encodedData));
        }

        return awsUserContextDataType;
    }

    bool IsEmpty() const {
        return this->ipAddress.IsEmpty() && this->encodedData.IsEmpty();
    }
#endif
};
