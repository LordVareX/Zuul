/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListDevicesResult.h"

#endif

#include "Model/DeviceType.h"

#include "ListDevicesResult.generated.h"

USTRUCT(BlueprintType)
struct FListDevicesResult {
GENERATED_BODY()

    /**
    *  <p>The devices returned in the list devices response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FDeviceType> devices;

    /**
    *  <p>The pagination token for the list device response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString paginationToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FListDevicesResult &fromAWS(const Aws::CognitoIdentityProvider::Model::ListDevicesResult &awsListDevicesResult) {
        this->devices.Empty();
        for (const Aws::CognitoIdentityProvider::Model::DeviceType& elem : awsListDevicesResult.GetDevices()) {
            this->devices.Add(FDeviceType().fromAWS(elem));
        }

        this->paginationToken = UTF8_TO_TCHAR(awsListDevicesResult.GetPaginationToken().c_str());

        return *this;
    }
#endif
};
