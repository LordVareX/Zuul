/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/LookupDeveloperIdentityResult.h"

#endif

#include "LookupDeveloperIdentityResult.generated.h"

USTRUCT(BlueprintType)
struct FLookupDeveloperIdentityResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>This is the list of developer user identifiers associated with an identity ID. Cognito supports the association of multiple developer user identifiers with an identity ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FString> developerUserIdentifierList;

    /**
    *  <p>A pagination token. The first call you make will have <code>NextToken</code> set to null. After that the service will return <code>NextToken</code> values as needed. For example, let's say you make a request with <code>MaxResults</code> set to 10, and there are 20 matches in the database. The service will return a pagination token as a part of the response. This token can be used to call the API again and get results starting from the 11th match.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString nextToken;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FLookupDeveloperIdentityResult &fromAWS(const Aws::CognitoIdentity::Model::LookupDeveloperIdentityResult &awsLookupDeveloperIdentityResult) {
        this->identityId = UTF8_TO_TCHAR(awsLookupDeveloperIdentityResult.GetIdentityId().c_str());

        this->developerUserIdentifierList.Empty();
        for (const Aws::String& elem : awsLookupDeveloperIdentityResult.GetDeveloperUserIdentifierList()) {
            this->developerUserIdentifierList.Add(elem.c_str());
        }

        this->nextToken = UTF8_TO_TCHAR(awsLookupDeveloperIdentityResult.GetNextToken().c_str());

        return *this;
    }
#endif
};
