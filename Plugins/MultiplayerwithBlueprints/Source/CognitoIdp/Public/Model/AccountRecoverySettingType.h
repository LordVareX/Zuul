/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AccountRecoverySettingType.h"

#endif

#include "Model/RecoveryOptionType.h"

#include "AccountRecoverySettingType.generated.h"

USTRUCT(BlueprintType)
struct FAccountRecoverySettingType {
GENERATED_BODY()

    /**
    *  <p>The list of <code>RecoveryOptionTypes</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FRecoveryOptionType> recoveryMechanisms;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AccountRecoverySettingType toAWS() const {
        Aws::CognitoIdentityProvider::Model::AccountRecoverySettingType awsAccountRecoverySettingType;

        for (const FRecoveryOptionType& elem : this->recoveryMechanisms) {
            awsAccountRecoverySettingType.AddRecoveryMechanisms(elem.toAWS());
        }

        return awsAccountRecoverySettingType;
    }

    bool IsEmpty() const {
        return this->recoveryMechanisms.Num() == 0;
    }

    FAccountRecoverySettingType &fromAWS(const Aws::CognitoIdentityProvider::Model::AccountRecoverySettingType &awsAccountRecoverySettingType) {
        this->recoveryMechanisms.Empty();
        for (const Aws::CognitoIdentityProvider::Model::RecoveryOptionType& elem : awsAccountRecoverySettingType.GetRecoveryMechanisms()) {
            this->recoveryMechanisms.Add(FRecoveryOptionType().fromAWS(elem));
        }

        return *this;
    }
#endif
};
