/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GlobalSignOutRequest.h"

#endif

#include "GlobalSignOutRequest.generated.h"

USTRUCT(BlueprintType)
struct FGlobalSignOutRequest {
GENERATED_BODY()

    /**
    *  <p>The access token.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::GlobalSignOutRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::GlobalSignOutRequest awsGlobalSignOutRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsGlobalSignOutRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        return awsGlobalSignOutRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty();
    }
#endif
};
