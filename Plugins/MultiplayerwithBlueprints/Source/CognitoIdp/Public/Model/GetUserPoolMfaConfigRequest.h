/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetUserPoolMfaConfigRequest.h"

#endif

#include "GetUserPoolMfaConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetUserPoolMfaConfigRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::GetUserPoolMfaConfigRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::GetUserPoolMfaConfigRequest awsGetUserPoolMfaConfigRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsGetUserPoolMfaConfigRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        return awsGetUserPoolMfaConfigRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty();
    }
#endif
};
