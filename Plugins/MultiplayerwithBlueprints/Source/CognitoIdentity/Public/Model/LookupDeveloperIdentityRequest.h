/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/LookupDeveloperIdentityRequest.h"

#endif

#include "LookupDeveloperIdentityRequest.generated.h"

USTRUCT(BlueprintType)
struct FLookupDeveloperIdentityRequest {
GENERATED_BODY()

    /**
    *  <p>An identity pool ID in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityPoolId;

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>A unique ID used by your backend authentication process to identify a user. Typically, a developer identity provider would issue many developer user identifiers, in keeping with the number of users.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString developerUserIdentifier;

    /**
    *  <p>The maximum number of identities to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    int maxResults = 0;

    /**
    *  <p>A pagination token. The first call you make will have <code>NextToken</code> set to null. After that the service will return <code>NextToken</code> values as needed. For example, let's say you make a request with <code>MaxResults</code> set to 10, and there are 20 matches in the database. The service will return a pagination token as a part of the response. This token can be used to call the API again and get results starting from the 11th match.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString nextToken;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentity::Model::LookupDeveloperIdentityRequest toAWS() const {
        Aws::CognitoIdentity::Model::LookupDeveloperIdentityRequest awsLookupDeveloperIdentityRequest;

        if (!(this->identityPoolId.IsEmpty())) {
            awsLookupDeveloperIdentityRequest.SetIdentityPoolId(TCHAR_TO_UTF8(*this->identityPoolId));
        }

        if (!(this->identityId.IsEmpty())) {
            awsLookupDeveloperIdentityRequest.SetIdentityId(TCHAR_TO_UTF8(*this->identityId));
        }

        if (!(this->developerUserIdentifier.IsEmpty())) {
            awsLookupDeveloperIdentityRequest.SetDeveloperUserIdentifier(TCHAR_TO_UTF8(*this->developerUserIdentifier));
        }

        if (!(this->maxResults == 0)) {
            awsLookupDeveloperIdentityRequest.SetMaxResults(this->maxResults);
        }

        if (!(this->nextToken.IsEmpty())) {
            awsLookupDeveloperIdentityRequest.SetNextToken(TCHAR_TO_UTF8(*this->nextToken));
        }

        return awsLookupDeveloperIdentityRequest;
    }

    bool IsEmpty() const {
        return this->identityPoolId.IsEmpty() && this->identityId.IsEmpty() && this->developerUserIdentifier.IsEmpty() && this->maxResults == 0 && this->nextToken.IsEmpty();
    }
#endif
};
