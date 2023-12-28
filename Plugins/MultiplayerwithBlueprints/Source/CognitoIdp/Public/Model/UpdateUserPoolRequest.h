/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UpdateUserPoolRequest.h"

#endif

#include "Model/UserPoolPolicyType.h"
#include "Model/AWSCognitoIdentityProviderDeletionProtectionType.h"
#include "Model/LambdaConfigType.h"
#include "Model/VerifiedAttributeType.h"
#include "Model/VerificationMessageTemplateType.h"
#include "Model/AWSCognitoIdentityProviderUserAttributeUpdateSettingsType.h"
#include "Model/UserPoolMfaType.h"
#include "Model/DeviceConfigurationType.h"
#include "Model/EmailConfigurationType.h"
#include "Model/SmsConfigurationType.h"
#include "Model/AdminCreateUserConfigType.h"
#include "Model/UserPoolAddOnsType.h"
#include "Model/AccountRecoverySettingType.h"

#include "UpdateUserPoolRequest.generated.h"

USTRUCT(BlueprintType)
struct FUpdateUserPoolRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool you want to update.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>A container with the policies you wish to update in a user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolPolicyType policies;

    /**
    *  <p>When active, <code>DeletionProtection</code> prevents accidental deletion of your user pool. Before you can delete a user pool that you have protected against deletion, you must deactivate this feature.</p> <p>When you try to delete a protected user pool in a <code>DeleteUserPool</code> API request, Amazon Cognito returns an <code>InvalidParameterException</code> error. To delete a protected user pool, send a new <code>DeleteUserPool</code> request after you deactivate deletion protection in an <code>UpdateUserPool</code> API request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSCognitoIdentityProviderDeletionProtectionType deletionProtection = EAWSCognitoIdentityProviderDeletionProtectionType::NOT_SET;

    /**
    *  <p>The Lambda configuration information from the request to update the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FLambdaConfigType lambdaConfig;

    /**
    *  <p>The attributes that are automatically verified when Amazon Cognito requests to update user pools.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EVerifiedAttributeType> autoVerifiedAttributes;

    /**
    *  <p>This parameter is no longer used. See <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_VerificationMessageTemplateType.html">VerificationMessageTemplateType</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString smsVerificationMessage;

    /**
    *  <p>This parameter is no longer used. See <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_VerificationMessageTemplateType.html">VerificationMessageTemplateType</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailVerificationMessage;

    /**
    *  <p>This parameter is no longer used. See <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_VerificationMessageTemplateType.html">VerificationMessageTemplateType</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailVerificationSubject;

    /**
    *  <p>The template for verification messages.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FVerificationMessageTemplateType verificationMessageTemplate;

    /**
    *  <p>The contents of the SMS authentication message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString smsAuthenticationMessage;

    /**
    *  <p>The settings for updates to user attributes. These settings include the property <code>AttributesRequireVerificationBeforeUpdate</code>, a user-pool setting that tells Amazon Cognito how to handle changes to the value of your users' email address and phone number attributes. For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/user-pool-settings-email-phone-verification.html#user-pool-settings-verifications-verify-attribute-updates"> Verifying updates to email addresses and phone numbers</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAWSCognitoIdentityProviderUserAttributeUpdateSettingsType userAttributeUpdateSettings;

    /**
    *  <p>Possible values include:</p> <ul> <li> <p> <code>OFF</code> - MFA tokens aren't required and can't be specified during user registration.</p> </li> <li> <p> <code>ON</code> - MFA tokens are required for all user registrations. You can only specify ON when you're initially creating a user pool. You can use the <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_SetUserPoolMfaConfig.html">SetUserPoolMfaConfig</a> API operation to turn MFA "ON" for existing user pools. </p> </li> <li> <p> <code>OPTIONAL</code> - Users have the option when registering to create an MFA token.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EUserPoolMfaType mfaConfiguration = EUserPoolMfaType::NOT_SET;

    /**
    *  <p>The device-remembering configuration for a user pool. A null value indicates that you have deactivated device remembering in your user pool.</p>  <p>When you provide a value for any <code>DeviceConfiguration</code> field, you activate the Amazon Cognito device-remembering feature.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDeviceConfigurationType deviceConfiguration;

    /**
    *  <p>The email configuration of your user pool. The email configuration type sets your preferred sending method, Amazon Web Services Region, and sender for email invitation and verification messages from your user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FEmailConfigurationType emailConfiguration;

    /**
    *  <p>The SMS configuration with the settings that your Amazon Cognito user pool must use to send an SMS message from your Amazon Web Services account through Amazon Simple Notification Service. To send SMS messages with Amazon SNS in the Amazon Web Services Region that you want, the Amazon Cognito user pool uses an Identity and Access Management (IAM) role in your Amazon Web Services account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSmsConfigurationType smsConfiguration;

    /**
    *  <p>The tag keys and values to assign to the user pool. A tag is a label that you can use to categorize and manage user pools in different ways, such as by purpose, owner, environment, or other criteria.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> userPoolTags;

    /**
    *  <p>The configuration for <code>AdminCreateUser</code> requests.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAdminCreateUserConfigType adminCreateUserConfig;

    /**
    *  <p>Enables advanced security risk detection. Set the key <code>AdvancedSecurityMode</code> to the value "AUDIT".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolAddOnsType userPoolAddOns;

    /**
    *  <p>The available verified method a user can use to recover their password when they call <code>ForgotPassword</code>. You can use this setting to define a preferred method when a user has more than one method available. With this setting, SMS doesn't qualify for a valid password recovery mechanism if the user also has SMS multi-factor authentication (MFA) activated. In the absence of this setting, Amazon Cognito uses the legacy behavior to determine the recovery method where SMS is preferred through email.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAccountRecoverySettingType accountRecoverySetting;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UpdateUserPoolRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::UpdateUserPoolRequest awsUpdateUserPoolRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsUpdateUserPoolRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->policies.IsEmpty())) {
            awsUpdateUserPoolRequest.SetPolicies(this->policies.toAWS());
        }

        switch(this->deletionProtection) {
            case EAWSCognitoIdentityProviderDeletionProtectionType::ACTIVE:
                awsUpdateUserPoolRequest.SetDeletionProtection(Aws::CognitoIdentityProvider::Model::DeletionProtectionType::ACTIVE);
                break;
            case EAWSCognitoIdentityProviderDeletionProtectionType::INACTIVE:
                awsUpdateUserPoolRequest.SetDeletionProtection(Aws::CognitoIdentityProvider::Model::DeletionProtectionType::INACTIVE);
                break;
            default:
                break;
        }

        if (!(this->lambdaConfig.IsEmpty())) {
            awsUpdateUserPoolRequest.SetLambdaConfig(this->lambdaConfig.toAWS());
        }

        for (const EVerifiedAttributeType& elem : this->autoVerifiedAttributes) {
            switch(elem) {
                case EVerifiedAttributeType::phone_number:
                    awsUpdateUserPoolRequest.AddAutoVerifiedAttributes(Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::phone_number);
                    break;
                case EVerifiedAttributeType::email:
                    awsUpdateUserPoolRequest.AddAutoVerifiedAttributes(Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::email);
                    break;
                default:
                    break;
            };
        }

        if (!(this->smsVerificationMessage.IsEmpty())) {
            awsUpdateUserPoolRequest.SetSmsVerificationMessage(TCHAR_TO_UTF8(*this->smsVerificationMessage));
        }

        if (!(this->emailVerificationMessage.IsEmpty())) {
            awsUpdateUserPoolRequest.SetEmailVerificationMessage(TCHAR_TO_UTF8(*this->emailVerificationMessage));
        }

        if (!(this->emailVerificationSubject.IsEmpty())) {
            awsUpdateUserPoolRequest.SetEmailVerificationSubject(TCHAR_TO_UTF8(*this->emailVerificationSubject));
        }

        if (!(this->verificationMessageTemplate.IsEmpty())) {
            awsUpdateUserPoolRequest.SetVerificationMessageTemplate(this->verificationMessageTemplate.toAWS());
        }

        if (!(this->smsAuthenticationMessage.IsEmpty())) {
            awsUpdateUserPoolRequest.SetSmsAuthenticationMessage(TCHAR_TO_UTF8(*this->smsAuthenticationMessage));
        }

        if (!(this->userAttributeUpdateSettings.IsEmpty())) {
            awsUpdateUserPoolRequest.SetUserAttributeUpdateSettings(this->userAttributeUpdateSettings.toAWS());
        }

        switch(this->mfaConfiguration) {
            case EUserPoolMfaType::OFF:
                awsUpdateUserPoolRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OFF);
                break;
            case EUserPoolMfaType::ON:
                awsUpdateUserPoolRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::ON);
                break;
            case EUserPoolMfaType::OPTIONAL_:
                awsUpdateUserPoolRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OPTIONAL_);
                break;
            default:
                break;
        }

        if (!(this->deviceConfiguration.IsEmpty())) {
            awsUpdateUserPoolRequest.SetDeviceConfiguration(this->deviceConfiguration.toAWS());
        }

        if (!(this->emailConfiguration.IsEmpty())) {
            awsUpdateUserPoolRequest.SetEmailConfiguration(this->emailConfiguration.toAWS());
        }

        if (!(this->smsConfiguration.IsEmpty())) {
            awsUpdateUserPoolRequest.SetSmsConfiguration(this->smsConfiguration.toAWS());
        }

        for (const TPair<FString, FString>& elem : this->userPoolTags) {
            awsUpdateUserPoolRequest.AddUserPoolTags(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        if (!(this->adminCreateUserConfig.IsEmpty())) {
            awsUpdateUserPoolRequest.SetAdminCreateUserConfig(this->adminCreateUserConfig.toAWS());
        }

        if (!(this->userPoolAddOns.IsEmpty())) {
            awsUpdateUserPoolRequest.SetUserPoolAddOns(this->userPoolAddOns.toAWS());
        }

        if (!(this->accountRecoverySetting.IsEmpty())) {
            awsUpdateUserPoolRequest.SetAccountRecoverySetting(this->accountRecoverySetting.toAWS());
        }

        return awsUpdateUserPoolRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->policies.IsEmpty() && deletionProtection == EAWSCognitoIdentityProviderDeletionProtectionType::NOT_SET && this->lambdaConfig.IsEmpty() && this->autoVerifiedAttributes.Num() == 0 && this->smsVerificationMessage.IsEmpty() && this->emailVerificationMessage.IsEmpty() && this->emailVerificationSubject.IsEmpty() && this->verificationMessageTemplate.IsEmpty() && this->smsAuthenticationMessage.IsEmpty() && this->userAttributeUpdateSettings.IsEmpty() && this->mfaConfiguration == EUserPoolMfaType::NOT_SET && this->deviceConfiguration.IsEmpty() && this->emailConfiguration.IsEmpty() && this->smsConfiguration.IsEmpty() && this->userPoolTags.Num() == 0 && this->adminCreateUserConfig.IsEmpty() && this->userPoolAddOns.IsEmpty() && this->accountRecoverySetting.IsEmpty();
    }
#endif
};
