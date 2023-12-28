/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeleteUserAttributesRequest.h"

#endif

#include "DeleteUserAttributesRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteUserAttributesRequest {
GENERATED_BODY()

    /**
    *  <p>An array of strings representing the user attribute names you wish to delete.</p> <p>For custom attributes, you must prepend the <code>custom:</code> prefix to the attribute name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> userAttributeNames;

    /**
    *  <p>The access token used in the request to delete user attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DeleteUserAttributesRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DeleteUserAttributesRequest awsDeleteUserAttributesRequest;

        for (const FString& elem : this->userAttributeNames) {
            awsDeleteUserAttributesRequest.AddUserAttributeNames(TCHAR_TO_UTF8(*elem));
        }

        if (!(this->accessToken.IsEmpty())) {
            awsDeleteUserAttributesRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        return awsDeleteUserAttributesRequest;
    }

    bool IsEmpty() const {
        return this->userAttributeNames.Num() == 0 && this->accessToken.IsEmpty();
    }
#endif
};
