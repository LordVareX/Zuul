/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetOpenIdTokenRequest.h"

#endif

#include "GetOpenIdTokenRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetOpenIdTokenRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>A set of optional name-value pairs that map provider names to provider tokens. When using graph.facebook.com and www.amazon.com, supply the access_token returned from the provider's authflow. For accounts.google.com, an Amazon Cognito user pool provider, or any other OpenId Connect provider, always include the <code>id_token</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> logins;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::GetOpenIdTokenRequest toAWS() const {
        Aws::CognitoIdentity::Model::GetOpenIdTokenRequest awsGetOpenIdTokenRequest;

        if (!(this->identityId.IsEmpty())) {
            awsGetOpenIdTokenRequest.SetIdentityId(TCHAR_TO_UTF8(*this->identityId));
        }

        for (const TPair<FString, FString>& elem : this->logins) {
            awsGetOpenIdTokenRequest.AddLogins(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetOpenIdTokenRequest;
    }

    bool IsEmpty() const {
        return this->identityId.IsEmpty() && this->logins.Num() == 0;
    }
#endif
};
