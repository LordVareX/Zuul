/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/UnlinkDeveloperIdentityRequest.h"

#endif

#include "UnlinkDeveloperIdentityRequest.generated.h"

USTRUCT(BlueprintType)
struct FUnlinkDeveloperIdentityRequest {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>The "domain" by which Cognito will refer to your users.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString developerProviderName;

    /**
    *  <p>A unique ID used by your backend authentication process to identify a user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString developerUserIdentifier;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::UnlinkDeveloperIdentityRequest toAWS() const {
        Aws::CognitoIdentity::Model::UnlinkDeveloperIdentityRequest awsUnlinkDeveloperIdentityRequest;

        if (!(this->identityId.IsEmpty())) {
            awsUnlinkDeveloperIdentityRequest.SetIdentityId(TCHAR_TO_UTF8(*this->identityId));
        }

        if (!(this->identityPoolId.IsEmpty())) {
            awsUnlinkDeveloperIdentityRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        if (!(this->developerProviderName.IsEmpty())) {
            awsUnlinkDeveloperIdentityRequest.SetDeveloperProviderName(TCHAR_TO_UTF8(*this->developerProviderName));
        }

        if (!(this->developerUserIdentifier.IsEmpty())) {
            awsUnlinkDeveloperIdentityRequest.SetDeveloperUserIdentifier(TCHAR_TO_UTF8(*this->developerUserIdentifier));
        }

        return awsUnlinkDeveloperIdentityRequest;
    }

    bool IsEmpty() const {
        return this->identityId.IsEmpty() && this->identityPoolId.IsEmpty() && this->developerProviderName.IsEmpty() && this->developerUserIdentifier.IsEmpty();
    }
#endif
};
