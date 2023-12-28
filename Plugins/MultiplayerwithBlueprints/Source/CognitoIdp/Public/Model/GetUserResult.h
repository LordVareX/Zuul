/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/GetUserResult.h"

#endif

#include "Model/AttributeType.h"
#include "Model/MFAOptionType.h"

#include "GetUserResult.generated.h"

USTRUCT(BlueprintType)
struct FGetUserResult {
GENERATED_BODY()

    /**
    *  <p>The user name of the user you wish to retrieve from the get user request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>An array of name-value pairs representing user attributes.</p> <p>For custom attributes, you must prepend the <code>custom:</code> prefix to the attribute name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FAttributeType> userAttributes;

    /**
    *  <p>Specifies the options for MFA (e.g., email or phone number).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FMFAOptionType> MFAOptions;

    /**
    *  <p>The user's preferred MFA setting.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString preferredMfaSetting;

    /**
    *  <p>The list of the user's MFA settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> userMFASettingList;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FGetUserResult &fromAWS(const Aws::CognitoIdentityProvider::Model::GetUserResult &awsGetUserResult) {
        this->username = UTF8_TO_TCHAR(awsGetUserResult.GetUsername().c_str());

        this->userAttributes.Empty();
        for (const Aws::CognitoIdentityProvider::Model::AttributeType& elem : awsGetUserResult.GetUserAttributes()) {
            this->userAttributes.Add(FAttributeType().fromAWS(elem));
        }

        this->MFAOptions.Empty();
        for (const Aws::CognitoIdentityProvider::Model::MFAOptionType& elem : awsGetUserResult.GetMFAOptions()) {
            this->MFAOptions.Add(FMFAOptionType().fromAWS(elem));
        }

        this->preferredMfaSetting = UTF8_TO_TCHAR(awsGetUserResult.GetPreferredMfaSetting().c_str());

        this->userMFASettingList.Empty();
        for (const Aws::String& elem : awsGetUserResult.GetUserMFASettingList()) {
            this->userMFASettingList.Add(elem.c_str());
        }

        return *this;
    }
#endif
};
