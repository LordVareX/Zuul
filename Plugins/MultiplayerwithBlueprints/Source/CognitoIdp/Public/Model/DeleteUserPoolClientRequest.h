/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeleteUserPoolClientRequest.h"

#endif

#include "DeleteUserPoolClientRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteUserPoolClientRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to delete the client.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The app client ID of the app associated with the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DeleteUserPoolClientRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DeleteUserPoolClientRequest awsDeleteUserPoolClientRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsDeleteUserPoolClientRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->clientId.IsEmpty())) {
            awsDeleteUserPoolClientRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        return awsDeleteUserPoolClientRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->clientId.IsEmpty();
    }
#endif
};
