/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/MergeDeveloperIdentitiesRequest.h"

#endif


#include "MergeDeveloperIdentitiesRequest.generated.h"

USTRUCT(BlueprintType)
struct FMergeDeveloperIdentitiesRequest {
GENERATED_BODY()

    /**
    *  <p>User identifier for the source user. The value should be a <code>DeveloperUserIdentifier</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString sourceUserIdentifier;

    /**
    *  <p>User identifier for the destination user. The value should be a <code>DeveloperUserIdentifier</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString destinationUserIdentifier;

    /**
    *  <p>The "domain" by which Cognito will refer to your users. This is a (pseudo) domain name that you provide while creating an identity pool. This name acts as a placeholder that allows your backend and the Cognito service to communicate about the developer provider. For the <code>DeveloperProviderName</code>, you can use letters as well as period (.), underscore (_), and dash (-).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString developerProviderName;

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::MergeDeveloperIdentitiesRequest toAWS() const {
        Aws::CognitoIdentity::Model::MergeDeveloperIdentitiesRequest awsMergeDeveloperIdentitiesRequest;

        if (!(this->sourceUserIdentifier.IsEmpty())) {
            awsMergeDeveloperIdentitiesRequest.SetSourceUserIdentifier(TCHAR_TO_UTF8(*this->sourceUserIdentifier));
        }

        if (!(this->destinationUserIdentifier.IsEmpty())) {
            awsMergeDeveloperIdentitiesRequest.SetDestinationUserIdentifier(TCHAR_TO_UTF8(*this->destinationUserIdentifier));
        }

        if (!(this->developerProviderName.IsEmpty())) {
            awsMergeDeveloperIdentitiesRequest.SetDeveloperProviderName(TCHAR_TO_UTF8(*this->developerProviderName));
        }

        if (!(this->identityPoolId.IsEmpty())) {
            awsMergeDeveloperIdentitiesRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        return awsMergeDeveloperIdentitiesRequest;
    }

    bool IsEmpty() const {
        return this->sourceUserIdentifier.IsEmpty() && this->destinationUserIdentifier.IsEmpty() && this->developerProviderName.IsEmpty() && this->identityPoolId.IsEmpty();
    }
#endif
};
