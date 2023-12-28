/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/NewDeviceMetadataType.h"

#endif

#include "NewDeviceMetadataType.generated.h"

USTRUCT(BlueprintType)
struct FNewDeviceMetadataType {
GENERATED_BODY()

    /**
    *  <p>The device key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString deviceKey;

    /**
    *  <p>The device group key.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString deviceGroupKey;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FNewDeviceMetadataType &fromAWS(const Aws::CognitoIdentityProvider::Model::NewDeviceMetadataType &awsNewDeviceMetadataType) {
        this->deviceKey = UTF8_TO_TCHAR(awsNewDeviceMetadataType.GetDeviceKey().c_str());

        this->deviceGroupKey = UTF8_TO_TCHAR(awsNewDeviceMetadataType.GetDeviceGroupKey().c_str());

        return *this;
    }
#endif
};
