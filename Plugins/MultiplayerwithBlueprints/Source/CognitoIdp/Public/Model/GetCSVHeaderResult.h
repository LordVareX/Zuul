/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetCSVHeaderResult.h"

#endif

#include "GetCSVHeaderResult.generated.h"

USTRUCT(BlueprintType)
struct FGetCSVHeaderResult {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool that the users are to be imported into.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The header information for the .csv file for the user import job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> CSVHeader;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FGetCSVHeaderResult &fromAWS(const Aws::CognitoIdentityProvider::Model::GetCSVHeaderResult &awsGetCSVHeaderResult) {
        this->userPoolId = UTF8_TO_TCHAR(awsGetCSVHeaderResult.GetUserPoolId().c_str());

        this->CSVHeader.Empty();
        for (const Aws::String& elem : awsGetCSVHeaderResult.GetCSVHeader()) {
            this->CSVHeader.Add(elem.c_str());
        }

        return *this;
    }
#endif
};
