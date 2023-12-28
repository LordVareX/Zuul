/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UICustomizationType.h"

#endif

#include "UICustomizationType.generated.h"

USTRUCT(BlueprintType)
struct FUICustomizationType {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The client ID for the client app.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>The logo image for the UI customization.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString imageUrl;

    /**
    *  <p>The CSS values in the UI customization.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString CSS;

    /**
    *  <p>The CSS version number.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString CSSVersion;

    /**
    *  <p>The last-modified date for the UI customization.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime lastModifiedDate;

    /**
    *  <p>The creation date for the UI customization.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime creationDate;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUICustomizationType &fromAWS(const Aws::CognitoIdentityProvider::Model::UICustomizationType &awsUICustomizationType) {
        this->userPoolId = UTF8_TO_TCHAR(awsUICustomizationType.GetUserPoolId().c_str());

        this->clientId = UTF8_TO_TCHAR(awsUICustomizationType.GetClientId().c_str());

        this->imageUrl = UTF8_TO_TCHAR(awsUICustomizationType.GetImageUrl().c_str());

        this->CSS = UTF8_TO_TCHAR(awsUICustomizationType.GetCSS().c_str());

        this->CSSVersion = UTF8_TO_TCHAR(awsUICustomizationType.GetCSSVersion().c_str());

        this->lastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsUICustomizationType.GetLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsUICustomizationType.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
