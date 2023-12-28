/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminSetUserPasswordRequest.h"

#endif

#include "AdminSetUserPasswordRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminSetUserPasswordRequest {
GENERATED_BODY()

    /**
     * <p>The user pool ID for the user pool where you want to set the user's password.</p>
     **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    * <p>The user name of the user whose password you wish to set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    * <p>The password for the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString password;

    /**
    * <p> <code>True</code> if the password is permanent, <code>False</code> if it is temporary.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool permanent = false;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminSetUserPasswordRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminSetUserPasswordRequest awsAdminSetUserPasswordRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminSetUserPasswordRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminSetUserPasswordRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->password.IsEmpty())) {
            awsAdminSetUserPasswordRequest.SetPassword(TCHAR_TO_UTF8(*this->password));
        }

        if (!(false)) {
            awsAdminSetUserPasswordRequest.SetPermanent(this->permanent);
        }

        return awsAdminSetUserPasswordRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->password.IsEmpty() && false;
    }
#endif
};
