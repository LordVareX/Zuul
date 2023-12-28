/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ListDevicesRequest.h"

#endif

#include "ListDevicesRequest.generated.h"

USTRUCT(BlueprintType)
struct FListDevicesRequest {
GENERATED_BODY()

    /**
    *  <p>The access tokens for the request to list devices.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

    /**
    *  <p>The limit of the device request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int limit = 0;

    /**
    *  <p>The pagination token for the list request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString paginationToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ListDevicesRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ListDevicesRequest awsListDevicesRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsListDevicesRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        if (this->limit != 0) {
            awsListDevicesRequest.SetLimit(this->limit);
        }

        if (!(this->paginationToken.IsEmpty())) {
            awsListDevicesRequest.SetPaginationToken(TCHAR_TO_UTF8(*this->paginationToken));
        }

        return awsListDevicesRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty() && this->limit == 0 && this->paginationToken.IsEmpty();
    }
#endif
};
