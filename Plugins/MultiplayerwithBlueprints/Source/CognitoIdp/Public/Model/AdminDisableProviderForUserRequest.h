/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminDisableProviderForUserRequest.h"

#endif

#include "Model/ProviderUserIdentifierType.h"

#include "AdminDisableProviderForUserRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminDisableProviderForUserRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user to be disabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FProviderUserIdentifierType user;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminDisableProviderForUserRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminDisableProviderForUserRequest awsAdminDisableProviderForUserRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminDisableProviderForUserRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->user.IsEmpty())) {
            awsAdminDisableProviderForUserRequest.SetUser(this->user.toAWS());
        }

        return awsAdminDisableProviderForUserRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->user.IsEmpty();
    }
#endif
};
