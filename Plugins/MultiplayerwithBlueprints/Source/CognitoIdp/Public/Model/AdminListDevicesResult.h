/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminListDevicesResult.h"

#endif

#include "Model/DeviceType.h"

#include "AdminListDevicesResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminListDevicesResult {
GENERATED_BODY()

    /**
    *  <p>The devices in the list of devices response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FDeviceType> devices;

    /**
    *  <p>The pagination token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString paginationToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminListDevicesResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminListDevicesResult &awsAdminListDevicesResult) {
        this->devices.Empty();
        for (const Aws::CognitoIdentityProvider::Model::DeviceType& elem : awsAdminListDevicesResult.GetDevices()) {
            this->devices.Add(FDeviceType().fromAWS(elem));
        }

        this->paginationToken = UTF8_TO_TCHAR(awsAdminListDevicesResult.GetPaginationToken().c_str());

        return *this;
    }
#endif
};
