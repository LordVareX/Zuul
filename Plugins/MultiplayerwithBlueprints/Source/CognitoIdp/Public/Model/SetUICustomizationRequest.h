/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "ImageUtils.h"
#include "Serialization/BufferArchive.h"
#include "CoreMinimal.h"
#include "Engine/Texture2D.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SetUICustomizationRequest.h"

#endif

#include "SetUICustomizationRequest.generated.h"

USTRUCT(BlueprintType)
struct FSetUICustomizationRequest {
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
    *  <p>The CSS values in the UI customization.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString cSS;

    /**
    *  <p>The uploaded logo image for the UI customization.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    UTexture2D* imageFile = nullptr;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SetUICustomizationRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::SetUICustomizationRequest awsSetUICustomizationRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsSetUICustomizationRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->clientId.IsEmpty())) {
            awsSetUICustomizationRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        if (!(this->cSS.IsEmpty())) {
            awsSetUICustomizationRequest.SetCSS(TCHAR_TO_UTF8(*this->cSS));
        }

        if (this->imageFile) {
            FBufferArchive Buffer;
            bool bSuccess = FImageUtils::ExportTexture2DAsHDR(imageFile, Buffer);
            if (bSuccess) {
                awsSetUICustomizationRequest.SetImageFile(Aws::Utils::ByteBuffer(const_cast<unsigned char*>(Buffer.GetData()), Buffer.Num()));
            }
        }

        return awsSetUICustomizationRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->clientId.IsEmpty() && this->cSS.IsEmpty() && !(this->imageFile);
    }
#endif
};
