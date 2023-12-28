/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/DeleteResourceServerRequest.h"

#endif

#include "DeleteResourceServerRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteResourceServerRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool that hosts the resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The identifier for the resource server.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString identifier;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::DeleteResourceServerRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::DeleteResourceServerRequest awsDeleteResourceServerRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsDeleteResourceServerRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->identifier.IsEmpty())) {
            awsDeleteResourceServerRequest.SetIdentifier(TCHAR_TO_UTF8(*this->identifier));
        }

        return awsDeleteResourceServerRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->identifier.IsEmpty();
    }
#endif
};
