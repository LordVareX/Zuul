/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserPoolAddOnsType.h"

#endif

#include "Model/AdvancedSecurityModeType.h"

#include "UserPoolAddOnsType.generated.h"

USTRUCT(BlueprintType)
struct FUserPoolAddOnsType {
GENERATED_BODY()

    /**
    *  <p>The advanced security mode.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAdvancedSecurityModeType advancedSecurityMode = EAdvancedSecurityModeType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UserPoolAddOnsType toAWS() const {
        Aws::CognitoIdentityProvider::Model::UserPoolAddOnsType awsUserPoolAddOnsType;

        switch(this->advancedSecurityMode) {
            case EAdvancedSecurityModeType::OFF:
                awsUserPoolAddOnsType.SetAdvancedSecurityMode(Aws::CognitoIdentityProvider::Model::AdvancedSecurityModeType::OFF);
                break;
            case EAdvancedSecurityModeType::AUDIT:
                awsUserPoolAddOnsType.SetAdvancedSecurityMode(Aws::CognitoIdentityProvider::Model::AdvancedSecurityModeType::AUDIT);
                break;
            case EAdvancedSecurityModeType::ENFORCED:
                awsUserPoolAddOnsType.SetAdvancedSecurityMode(Aws::CognitoIdentityProvider::Model::AdvancedSecurityModeType::ENFORCED);
                break;
            default:
                break;
        }

        return awsUserPoolAddOnsType;
    }

    bool IsEmpty() const {
        return this->advancedSecurityMode == EAdvancedSecurityModeType::NOT_SET;
    }

    FUserPoolAddOnsType &fromAWS(const Aws::CognitoIdentityProvider::Model::UserPoolAddOnsType &awsUserPoolAddOnsType) {
        switch(awsUserPoolAddOnsType.GetAdvancedSecurityMode()) {
            case Aws::CognitoIdentityProvider::Model::AdvancedSecurityModeType::NOT_SET:
                this->advancedSecurityMode = EAdvancedSecurityModeType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::AdvancedSecurityModeType::OFF:
                this->advancedSecurityMode = EAdvancedSecurityModeType::OFF;
                break;
            case Aws::CognitoIdentityProvider::Model::AdvancedSecurityModeType::AUDIT:
                this->advancedSecurityMode = EAdvancedSecurityModeType::AUDIT;
                break;
            case Aws::CognitoIdentityProvider::Model::AdvancedSecurityModeType::ENFORCED:
                this->advancedSecurityMode = EAdvancedSecurityModeType::ENFORCED;
                break;
            default:
                this->advancedSecurityMode = EAdvancedSecurityModeType::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
