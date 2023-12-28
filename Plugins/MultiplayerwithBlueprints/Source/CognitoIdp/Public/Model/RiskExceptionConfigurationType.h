/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/RiskExceptionConfigurationType.h"

#endif

#include "RiskExceptionConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FRiskExceptionConfigurationType {
    GENERATED_BODY()

    /**
    *  <p>Overrides the risk decision to always block the pre-authentication requests. The IP range is in CIDR notation: a compact representation of an IP address and its associated routing prefix.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> blockedIPRangeList;

    /**
    *  <p>Risk detection is not performed on the IP addresses in the range list. The IP range is in CIDR notation.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> skippedIPRangeList;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::RiskExceptionConfigurationType toAWS() const {
        Aws::CognitoIdentityProvider::Model::RiskExceptionConfigurationType awsRiskExceptionConfigurationType;

        for (const FString& elem : this->blockedIPRangeList) {
            awsRiskExceptionConfigurationType.AddBlockedIPRangeList(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->skippedIPRangeList) {
            awsRiskExceptionConfigurationType.AddSkippedIPRangeList(TCHAR_TO_UTF8(*elem));
        }

        return awsRiskExceptionConfigurationType;
    }

    bool IsEmpty() const {
        return this->blockedIPRangeList.Num() == 0 && this->skippedIPRangeList.Num() == 0;
    }

    FRiskExceptionConfigurationType &fromAWS(const Aws::CognitoIdentityProvider::Model::RiskExceptionConfigurationType &awsRiskExceptionConfigurationType) {
        this->blockedIPRangeList.Empty();
        for (const Aws::String& elem : awsRiskExceptionConfigurationType.GetBlockedIPRangeList()) {
            this->blockedIPRangeList.Add(elem.c_str());
        }

        this->skippedIPRangeList.Empty();
        for (const Aws::String& elem : awsRiskExceptionConfigurationType.GetSkippedIPRangeList()) {
            this->skippedIPRangeList.Add(elem.c_str());
        }

        return *this;
    }
#endif
};
