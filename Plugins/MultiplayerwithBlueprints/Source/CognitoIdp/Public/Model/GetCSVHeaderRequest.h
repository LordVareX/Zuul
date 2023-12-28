/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetCSVHeaderRequest.h"

#endif

#include "GetCSVHeaderRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetCSVHeaderRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool that the users are to be imported into.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::GetCSVHeaderRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::GetCSVHeaderRequest awsGetCSVHeaderRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsGetCSVHeaderRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        return awsGetCSVHeaderRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty();
    }
#endif
};
