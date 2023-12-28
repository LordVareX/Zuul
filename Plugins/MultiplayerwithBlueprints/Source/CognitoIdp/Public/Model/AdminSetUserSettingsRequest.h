/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminSetUserSettingsRequest.h"

#endif

#include "Model/MFAOptionType.h"

#include "AdminSetUserSettingsRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminSetUserSettingsRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to set the user's settings, such as MFA options.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name of the user for whom you wish to set user settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>You can use this parameter only to set an SMS configuration that uses SMS for delivery.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FMFAOptionType> MFAOptions;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminSetUserSettingsRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminSetUserSettingsRequest awsAdminSetUserSettingsRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminSetUserSettingsRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminSetUserSettingsRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        for (const FMFAOptionType& elem : this->MFAOptions) {
            awsAdminSetUserSettingsRequest.AddMFAOptions(elem.toAWS());
        }

        return awsAdminSetUserSettingsRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->MFAOptions.Num() == 0;
    }
#endif
};
