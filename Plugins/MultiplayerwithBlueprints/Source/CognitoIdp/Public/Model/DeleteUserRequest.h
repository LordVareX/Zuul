/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeleteUserRequest.h"

#endif

#include "DeleteUserRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteUserRequest {
GENERATED_BODY()

    /**
    *  <p>The access token from a request to delete a user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DeleteUserRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DeleteUserRequest awsDeleteUserRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsDeleteUserRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        return awsDeleteUserRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty();
    }
#endif
};
