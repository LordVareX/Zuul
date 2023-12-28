/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SetUserSettingsRequest.h"

#endif

#include "Model/MFAOptionType.h"

#include "SetUserSettingsRequest.generated.h"

USTRUCT(BlueprintType)
struct FSetUserSettingsRequest {
GENERATED_BODY()

    /**
    *  <p>The access token for the set user settings request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString accessToken;

    /**
    *  <p>Specifies the options for MFA (e.g., email or phone number).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FMFAOptionType> mFAOptions;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SetUserSettingsRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::SetUserSettingsRequest awsSetUserSettingsRequest;

        if (!(this->accessToken.IsEmpty())) {
            awsSetUserSettingsRequest.SetAccessToken(TCHAR_TO_UTF8(*this->accessToken));
        }

        for (const FMFAOptionType& elem : this->mFAOptions) {
            awsSetUserSettingsRequest.AddMFAOptions(elem.toAWS());
        }

        return awsSetUserSettingsRequest;
    }

    bool IsEmpty() const {
        return this->accessToken.IsEmpty() && this->mFAOptions.Num() == 0;
    }
#endif
};
