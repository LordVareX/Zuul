/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminListDevicesRequest.h"

#endif

#include "AdminListDevicesRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminListDevicesRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>The limit of the devices request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int limit = 0;

    /**
    *  <p>The pagination token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString paginationToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminListDevicesRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminListDevicesRequest awsAdminListDevicesRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminListDevicesRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminListDevicesRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (this->limit != 0) {
            awsAdminListDevicesRequest.SetLimit(this->limit);
        }

        if (!(this->paginationToken.IsEmpty())) {
            awsAdminListDevicesRequest.SetPaginationToken(TCHAR_TO_UTF8(*this->paginationToken));
        }

        return awsAdminListDevicesRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->limit == 0 && this->paginationToken.IsEmpty();
    }
#endif
};
