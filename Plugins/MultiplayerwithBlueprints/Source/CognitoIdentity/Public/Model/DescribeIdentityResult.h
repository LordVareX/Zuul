/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/DescribeIdentityResult.h"

#endif


#include "DescribeIdentityResult.generated.h"

USTRUCT(BlueprintType)
struct FDescribeIdentityResult {
GENERATED_BODY()

    /**
    *  <p>A unique identifier in the format REGION:GUID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FString identityId;

    /**
    *  <p>The provider names.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    TArray<FString> logins;

    /**
    *  <p>Date on which the identity was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FDateTime creationDate;

    /**
    *  <p>Date on which the identity was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentity Client")
    FDateTime lastModifiedDate;

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE
public:
    FDescribeIdentityResult &fromAWS(const Aws::CognitoIdentity::Model::DescribeIdentityResult &awsDescribeIdentityResult) {
        this->identityId = UTF8_TO_TCHAR(awsDescribeIdentityResult.GetIdentityId().c_str());

        this->logins.Empty();
        for (const Aws::String& elem : awsDescribeIdentityResult.GetLogins()) {
            this->logins.Add(elem.c_str());
        }

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsDescribeIdentityResult.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        this->lastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsDescribeIdentityResult.GetLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
