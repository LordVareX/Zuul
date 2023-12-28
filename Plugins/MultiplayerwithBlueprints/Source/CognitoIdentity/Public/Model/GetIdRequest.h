/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/GetIdRequest.h"

#endif

#include "GetIdRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetIdRequest {
GENERATED_BODY()

    /**
    *  <p>A standard AWS account ID (9+ digits).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString accountId;

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>A set of optional name-value pairs that map provider names to provider tokens. The available provider names for <code>Logins</code> are as follows:</p> <ul> <li> <p>Facebook: <code>graph.facebook.com</code> </p> </li> <li> <p>Amazon Cognito user pool: <code>cognito-idp.&lt;region&gt;.amazonaws.com/&lt;YOUR_USER_POOL_ID&gt;</code>, for example, <code>cognito-idp.us-east-1.amazonaws.com/us-east-1_123456789</code>. </p> </li> <li> <p>Google: <code>accounts.google.com</code> </p> </li> <li> <p>Amazon: <code>www.amazon.com</code> </p> </li> <li> <p>Twitter: <code>api.twitter.com</code> </p> </li> <li> <p>Digits: <code>www.digits.com</code> </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TMap<FString, FString> logins;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::GetIdRequest toAWS() const {
        Aws::CognitoIdentity::Model::GetIdRequest awsGetIdRequest;

        if (!(this->accountId.IsEmpty())) {
            awsGetIdRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(this->identityPoolId.IsEmpty())) {
            awsGetIdRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        for (const TPair<FString, FString>& elem : this->logins) {
            awsGetIdRequest.AddLogins(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsGetIdRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->identityPoolId.IsEmpty() && this->logins.Num() == 0;
    }
#endif
};
