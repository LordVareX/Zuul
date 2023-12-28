/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/RecoveryOptionType.h"

#endif

#include "Model/RecoveryOptionNameType.h"

#include "RecoveryOptionType.generated.h"

USTRUCT(BlueprintType)
struct FRecoveryOptionType {
GENERATED_BODY()

    /**
    *  <p>A positive integer specifying priority of a method with 1 being the highest priority.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int priority = 0;

    /**
    *  <p>Specifies the recovery method for a user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSRecoveryOptionNameType name = EAWSRecoveryOptionNameType::NOT_SET;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::RecoveryOptionType toAWS() const {
        Aws::CognitoIdentityProvider::Model::RecoveryOptionType awsRecoveryOptionType;

        if (!(this->priority == 0)) {
            awsRecoveryOptionType.SetPriority(this->priority);
        }

        switch(this->name) {
            case EAWSRecoveryOptionNameType::verified_email:
                awsRecoveryOptionType.SetName(Aws::CognitoIdentityProvider::Model::RecoveryOptionNameType::verified_email);
                break;
            case EAWSRecoveryOptionNameType::verified_phone_number:
                awsRecoveryOptionType.SetName(Aws::CognitoIdentityProvider::Model::RecoveryOptionNameType::verified_phone_number);
                break;
            case EAWSRecoveryOptionNameType::admin_only:
                awsRecoveryOptionType.SetName(Aws::CognitoIdentityProvider::Model::RecoveryOptionNameType::admin_only);
                break;
            default:
                break;
            }

        return awsRecoveryOptionType;
    }

    bool IsEmpty() const {
        return this->priority == 0 && name == EAWSRecoveryOptionNameType::NOT_SET;
    }

    FRecoveryOptionType &fromAWS(const Aws::CognitoIdentityProvider::Model::RecoveryOptionType &awsRecoveryOptionType) {
// @TODO: check
		this->priority = awsRecoveryOptionType.GetPriority();

// @TODO: check
        switch(awsRecoveryOptionType.GetName()) {
            case Aws::CognitoIdentityProvider::Model::RecoveryOptionNameType::NOT_SET:
                this->name = EAWSRecoveryOptionNameType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::RecoveryOptionNameType::verified_email:
                this->name = EAWSRecoveryOptionNameType::verified_email;
                break;
            case Aws::CognitoIdentityProvider::Model::RecoveryOptionNameType::verified_phone_number:
                this->name = EAWSRecoveryOptionNameType::verified_phone_number;
                break;
            case Aws::CognitoIdentityProvider::Model::RecoveryOptionNameType::admin_only:
                this->name = EAWSRecoveryOptionNameType::admin_only;
                break;
            default:
                // @TODO: unimplemented
                this->name = EAWSRecoveryOptionNameType::NOT_SET;
                break;
            }

        return *this;
    }
#endif
};
