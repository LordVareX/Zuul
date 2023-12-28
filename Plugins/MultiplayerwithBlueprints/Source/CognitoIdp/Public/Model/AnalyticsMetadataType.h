/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AnalyticsMetadataType.h"

#endif

#include "AnalyticsMetadataType.generated.h"

USTRUCT(BlueprintType)
struct FAnalyticsMetadataType {
GENERATED_BODY()

    /**
    *  <p>The endpoint ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString analyticsEndpointId;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AnalyticsMetadataType toAWS() const {
        Aws::CognitoIdentityProvider::Model::AnalyticsMetadataType awsAnalyticsMetadataType;

        if (!(this->analyticsEndpointId.IsEmpty())) {
            awsAnalyticsMetadataType.SetAnalyticsEndpointId(TCHAR_TO_UTF8(*this->analyticsEndpointId));
        }

        return awsAnalyticsMetadataType;
    }

    bool IsEmpty() const {
        return this->analyticsEndpointId.IsEmpty();
    }
#endif
};
