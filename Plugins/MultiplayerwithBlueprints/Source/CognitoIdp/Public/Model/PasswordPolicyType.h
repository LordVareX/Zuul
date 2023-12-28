/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/PasswordPolicyType.h"

#endif

#include "PasswordPolicyType.generated.h"

USTRUCT(BlueprintType)
struct FPasswordPolicyType {
GENERATED_BODY()

    /**
    *  <p>The minimum length of the password policy that you have set. Cannot be less than 6.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int minimumLength = 0;

    /**
    *  <p>In the password policy that you have set, refers to whether you have required users to use at least one uppercase letter in their password.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool requireUppercase = false;

    /**
    *  <p>In the password policy that you have set, refers to whether you have required users to use at least one lowercase letter in their password.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool requireLowercase = false;

    /**
    *  <p>In the password policy that you have set, refers to whether you have required users to use at least one number in their password.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool requireNumbers = false;

    /**
    *  <p>In the password policy that you have set, refers to whether you have required users to use at least one symbol in their password.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool requireSymbols = false;

    /**
    *  <p>In the password policy you have set, refers to the number of days a temporary password is valid. If the user does not sign-in during this time, their password will need to be reset by an administrator.</p> <note> <p>When you set <code>TemporaryPasswordValidityDays</code> for a user pool, you will no longer be able to set the deprecated <code>UnusedAccountValidityDays</code> value for that user pool.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int temporaryPasswordValidityDays = 0;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::PasswordPolicyType toAWS() const {
        Aws::CognitoIdentityProvider::Model::PasswordPolicyType awsPasswordPolicyType;

        if (this->minimumLength != 0) {
            awsPasswordPolicyType.SetMinimumLength(this->minimumLength);
        }

        if (!(false)) {
            awsPasswordPolicyType.SetRequireUppercase(this->requireUppercase);
        }

        if (!(false)) {
            awsPasswordPolicyType.SetRequireLowercase(this->requireLowercase);
        }

        if (!(false)) {
            awsPasswordPolicyType.SetRequireNumbers(this->requireNumbers);
        }

        if (!(false)) {
            awsPasswordPolicyType.SetRequireSymbols(this->requireSymbols);
        }

        if (this->temporaryPasswordValidityDays != 0) {
            awsPasswordPolicyType.SetTemporaryPasswordValidityDays(this->temporaryPasswordValidityDays);
        }

        return awsPasswordPolicyType;
    }

    bool IsEmpty() const {
        return this->minimumLength == 0 && false && false && false && false && this->temporaryPasswordValidityDays == 0;
    }

    FPasswordPolicyType &fromAWS(const Aws::CognitoIdentityProvider::Model::PasswordPolicyType &awsPasswordPolicyType) {
        this->minimumLength = awsPasswordPolicyType.GetMinimumLength();

        this->requireUppercase = awsPasswordPolicyType.GetRequireUppercase();

        this->requireLowercase = awsPasswordPolicyType.GetRequireLowercase();

        this->requireNumbers = awsPasswordPolicyType.GetRequireNumbers();

        this->requireSymbols = awsPasswordPolicyType.GetRequireSymbols();

        this->temporaryPasswordValidityDays = awsPasswordPolicyType.GetTemporaryPasswordValidityDays();

        return *this;
    }
#endif
};
