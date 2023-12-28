/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDENTITYCLIENTSDK && WITH_CORE

#include "aws/cognito-identity/model/IdentityDescription.h"

#endif


#include "IdentityDescription.generated.h"

USTRUCT(BlueprintType)
struct FIdentityDescription {
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
    FIdentityDescription &fromAWS(const Aws::CognitoIdentity::Model::IdentityDescription &awsIdentityDescription) {
        this->identityId = UTF8_TO_TCHAR(awsIdentityDescription.GetIdentityId().c_str());

        this->logins.Empty();
        for (const Aws::String& elem : awsIdentityDescription.GetLogins()) {
            this->logins.Add(elem.c_str());
        }

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsIdentityDescription.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        this->lastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsIdentityDescription.GetLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
