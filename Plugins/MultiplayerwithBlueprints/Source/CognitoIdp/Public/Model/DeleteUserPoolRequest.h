/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeleteUserPoolRequest.h"

#endif

#include "DeleteUserPoolRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteUserPoolRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool you want to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DeleteUserPoolRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DeleteUserPoolRequest awsDeleteUserPoolRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsDeleteUserPoolRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        return awsDeleteUserPoolRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty();
    }
#endif
};
