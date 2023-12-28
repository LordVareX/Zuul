/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetUserRequest.h"

#endif

#include "GetUserRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetUserRequest {
GENERATED_BODY()

    /**
    *  <p>The access token returned by the server response to get information about the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::GetUserRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::GetUserRequest awsGetUserRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsGetUserRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        return awsGetUserRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty();
    }
#endif
};
