/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminDeleteUserAttributesRequest.h"

#endif

#include "AdminDeleteUserAttributesRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminDeleteUserAttributesRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to delete user attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name of the user from which you would like to delete attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>An array of strings representing the user attribute names you wish to delete.</p> <p>For custom attributes, you must prepend the <code>custom:</code> prefix to the attribute name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> userAttributeNames;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminDeleteUserAttributesRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminDeleteUserAttributesRequest awsAdminDeleteUserAttributesRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminDeleteUserAttributesRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminDeleteUserAttributesRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        for (const FString& elem : this->userAttributeNames) {
            awsAdminDeleteUserAttributesRequest.AddUserAttributeNames(TCHAR_TO_UTF8(*elem));
        }

        return awsAdminDeleteUserAttributesRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->userAttributeNames.Num() == 0;
    }
#endif
};
