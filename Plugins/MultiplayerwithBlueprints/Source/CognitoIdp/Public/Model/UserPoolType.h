/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserPoolType.h"

#endif

#include "Model/UserPoolPolicyType.h"
#include "Model/AWSCognitoIdentityProviderDeletionProtectionType.h"
#include "Model/LambdaConfigType.h"
#include "Model/StatusType.h"
#include "Model/SchemaAttributeType.h"
#include "Model/VerifiedAttributeType.h"
#include "Model/AliasAttributeType.h"
#include "Model/UsernameAttributeType.h"
#include "Model/VerificationMessageTemplateType.h"
#include "Model/AWSCognitoIdentityProviderUserAttributeUpdateSettingsType.h"
#include "Model/UserPoolMfaType.h"
#include "Model/DeviceConfigurationType.h"
#include "Model/EmailConfigurationType.h"
#include "Model/SmsConfigurationType.h"
#include "Model/AdminCreateUserConfigType.h"
#include "Model/UserPoolAddOnsType.h"
#include "Model/UsernameConfigurationType.h"
#include "Model/AccountRecoverySettingType.h"

#include "UserPoolType.generated.h"

USTRUCT(BlueprintType)
struct FUserPoolType {
GENERATED_BODY()

    /**
    *  <p>The ID of the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString id;

    /**
    *  <p>The name of the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString name;

    /**
    *  <p>The policies associated with the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolPolicyType policies;

    /**
    *  <p>When active, <code>DeletionProtection</code> prevents accidental deletion of your user pool. Before you can delete a user pool that you have protected against deletion, you must deactivate this feature.</p> <p>When you try to delete a protected user pool in a <code>DeleteUserPool</code> API request, Amazon Cognito returns an <code>InvalidParameterException</code> error. To delete a protected user pool, send a new <code>DeleteUserPool</code> request after you deactivate deletion protection in an <code>UpdateUserPool</code> API request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSCognitoIdentityProviderDeletionProtectionType deletionProtection = EAWSCognitoIdentityProviderDeletionProtectionType::NOT_SET;

    /**
    *  <p>The Lambda triggers associated with the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FLambdaConfigType lambdaConfig;

    /**
    *  <p>The status of a user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EStatusType status = EStatusType::NOT_SET;

    /**
    *  <p>The date the user pool was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime lastModifiedDate;

    /**
    *  <p>The date the user pool was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime creationDate;

    /**
    *  <p>A container with the schema attributes of a user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FSchemaAttributeType> schemaAttributes;

    /**
    *  <p>The attributes that are auto-verified in a user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EVerifiedAttributeType> autoVerifiedAttributes;

    /**
    *  <p>The attributes that are aliased in a user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EAliasAttributeType> aliasAttributes;

    /**
    *  <p>Specifies whether email addresses or phone numbers can be specified as usernames when a user signs up.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EUsernameAttributeType> usernameAttributes;

    /**
    *  <p>This parameter is no longer used. See <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_VerificationMessageTemplateType.html">VerificationMessageTemplateType</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString smsVerificationMessage;

    /**
    *  <p>The contents of the email verification message.</p>
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
    *  <p>Can be one of the following values:</p> <ul> <li> <p> <code>OFF</code> - MFA tokens are not required and cannot be specified during user registration.</p> </li> <li> <p> <code>ON</code> - MFA tokens are required for all user registrations. You can only specify required when you are initially creating a user pool.</p> </li> <li> <p> <code>OPTIONAL</code> - Users have the option when registering to create an MFA token.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EUserPoolMfaType mfaConfiguration = EUserPoolMfaType::NOT_SET;

    /**
    *  <p>The device-remembering configuration for a user pool. A null value indicates that you have deactivated device remembering in your user pool.</p>  <p>When you provide a value for any <code>DeviceConfiguration</code> field, you activate the Amazon Cognito device-remembering feature.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDeviceConfigurationType deviceConfiguration;

    /**
    *  <p>A number estimating the size of the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int estimatedNumberOfUsers = 0;

    /**
    *  <p>The email configuration of your user pool. The email configuration type sets your preferred sending method, Amazon Web Services Region, and sender for messages tfrom your user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FEmailConfigurationType emailConfiguration;

    /**
    *  <p>The SMS configuration with the settings that your Amazon Cognito user pool must use to send an SMS message from your Amazon Web Services account through Amazon Simple Notification Service. To send SMS messages with Amazon SNS in the Amazon Web Services Region that you want, the Amazon Cognito user pool uses an Identity and Access Management (IAM) role in your Amazon Web Services account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FSmsConfigurationType smsConfiguration;

    /**
    *  <p>The tags that are assigned to the user pool. A tag is a label that you can apply to user pools to categorize and manage them in different ways, such as by purpose, owner, environment, or other criteria.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> userPoolTags;

    /**
    *  <p>The reason why the SMS configuration can't send the messages to your users.</p> <p>This message might include comma-separated values to describe why your SMS configuration can't send messages to user pool end users.</p> <dl> <dt>InvalidSmsRoleAccessPolicyException</dt> <dd> <p>The Identity and Access Management role that Amazon Cognito uses to send SMS messages isn't properly configured. For more information, see <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_SmsConfigurationType.html">SmsConfigurationType</a>.</p> </dd> <dt>SNSSandbox</dt> <dd> <p>The Amazon Web Services account is in the SNS SMS Sandbox and messages will only reach verified end users. This parameter won’t get populated with SNSSandbox if the IAM user creating the user pool doesn’t have SNS permissions. To learn how to move your Amazon Web Services account out of the sandbox, see <a href="https://docs.aws.amazon.com/sns/latest/dg/sns-sms-sandbox-moving-to-production.html">Moving out of the SMS sandbox</a>.</p> </dd> </dl>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString smsConfigurationFailure;

    /**
    *  <p>Deprecated. Review error codes from API requests with <code>EventSource:cognito-idp.amazonaws.com</code> in CloudTrail for information about problems with user pool email configuration.</p>
    **/
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
//    FString emailConfigurationFailure;

    /**
    *  <p>Holds the domain prefix if the user pool has a domain associated with it.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString domain;

    /**
    *  <p>A custom domain name that you provide to Amazon Cognito. This parameter applies only if you use a custom domain to host the sign-up and sign-in pages for your application. An example of a custom domain name might be <code>auth.example.com</code>.</p> <p>For more information about adding a custom domain to your user pool, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-pools-add-custom-domain.html">Using Your Own Domain for the Hosted UI</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString customDomain;

    /**
    *  <p>The configuration for <code>AdminCreateUser</code> requests.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAdminCreateUserConfigType adminCreateUserConfig;

    /**
    *  <p>The user pool add-ons.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolAddOnsType userPoolAddOns;

    /**
    *  <p>Case sensitivity of the username input for the selected sign-in option. For example, when case sensitivity is set to <code>False</code>, users can sign in using either "username" or "Username". This configuration is immutable once it has been set. For more information, see <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_UsernameConfigurationType.html">UsernameConfigurationType</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUsernameConfigurationType usernameConfiguration;

    /**
    *  <p>The Amazon Resource Name (ARN) for the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString arn;

    /**
    *  <p>The available verified method a user can use to recover their password when they call <code>ForgotPassword</code>. You can use this setting to define a preferred method when a user has more than one method available. With this setting, SMS doesn't qualify for a valid password recovery mechanism if the user also has SMS multi-factor authentication (MFA) activated. In the absence of this setting, Amazon Cognito uses the legacy behavior to determine the recovery method where SMS is preferred through email.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAccountRecoverySettingType accountRecoverySetting;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUserPoolType &fromAWS(const Aws::CognitoIdentityProvider::Model::UserPoolType &awsUserPoolType) {
        this->id = UTF8_TO_TCHAR(awsUserPoolType.GetId().c_str());

        this->name = UTF8_TO_TCHAR(awsUserPoolType.GetName().c_str());

        this->policies.fromAWS(awsUserPoolType.GetPolicies());

        switch(awsUserPoolType.GetDeletionProtection()) {
            case Aws::CognitoIdentityProvider::Model::DeletionProtectionType::NOT_SET:
                this->deletionProtection = EAWSCognitoIdentityProviderDeletionProtectionType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::DeletionProtectionType::ACTIVE:
                this->deletionProtection = EAWSCognitoIdentityProviderDeletionProtectionType::ACTIVE;
                break;
            case Aws::CognitoIdentityProvider::Model::DeletionProtectionType::INACTIVE:
                this->deletionProtection = EAWSCognitoIdentityProviderDeletionProtectionType::INACTIVE;
                break;
            default:
                this->deletionProtection = EAWSCognitoIdentityProviderDeletionProtectionType::NOT_SET;
                break;
        }

        this->lambdaConfig.fromAWS(awsUserPoolType.GetLambdaConfig());

        switch(awsUserPoolType.GetStatus()) {
            case Aws::CognitoIdentityProvider::Model::StatusType::NOT_SET:
                this->status = EStatusType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::StatusType::Enabled:
                this->status = EStatusType::Enabled;
                break;
            case Aws::CognitoIdentityProvider::Model::StatusType::Disabled:
                this->status = EStatusType::Disabled;
                break;
            default:
                this->status = EStatusType::NOT_SET;
                break;
        }

        this->lastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsUserPoolType.GetLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsUserPoolType.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        this->schemaAttributes.Empty();
        for (const Aws::CognitoIdentityProvider::Model::SchemaAttributeType& elem : awsUserPoolType.GetSchemaAttributes()) {
            this->schemaAttributes.Add(FSchemaAttributeType().fromAWS(elem));
        }

        this->autoVerifiedAttributes.Empty();
        for (const Aws::CognitoIdentityProvider::Model::VerifiedAttributeType& elem : awsUserPoolType.GetAutoVerifiedAttributes()) {
            switch(elem) {
                case Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::NOT_SET:
                    this->autoVerifiedAttributes.Add(EVerifiedAttributeType::NOT_SET);
                    break;
                case Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::phone_number:
                    this->autoVerifiedAttributes.Add(EVerifiedAttributeType::phone_number);
                    break;
                case Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::email:
                    this->autoVerifiedAttributes.Add(EVerifiedAttributeType::email);
                    break;
                default:
                    this->autoVerifiedAttributes.Add(EVerifiedAttributeType::NOT_SET);
                    break;
            };
        }

        this->aliasAttributes.Empty();
        for (const Aws::CognitoIdentityProvider::Model::AliasAttributeType& elem : awsUserPoolType.GetAliasAttributes()) {
            switch(elem) {
                case Aws::CognitoIdentityProvider::Model::AliasAttributeType::NOT_SET:
                    this->aliasAttributes.Add(EAliasAttributeType::NOT_SET);
                    break;
                case Aws::CognitoIdentityProvider::Model::AliasAttributeType::phone_number:
                    this->aliasAttributes.Add(EAliasAttributeType::phone_number);
                    break;
                case Aws::CognitoIdentityProvider::Model::AliasAttributeType::email:
                    this->aliasAttributes.Add(EAliasAttributeType::email);
                    break;
                case Aws::CognitoIdentityProvider::Model::AliasAttributeType::preferred_username:
                    this->aliasAttributes.Add(EAliasAttributeType::preferred_username);
                    break;
                default:
                    this->aliasAttributes.Add(EAliasAttributeType::NOT_SET);
                    break;
            };
        }

        this->usernameAttributes.Empty();
        for (const Aws::CognitoIdentityProvider::Model::UsernameAttributeType& elem : awsUserPoolType.GetUsernameAttributes()) {
            switch(elem) {
                case Aws::CognitoIdentityProvider::Model::UsernameAttributeType::NOT_SET:
                    this->usernameAttributes.Add(EUsernameAttributeType::NOT_SET);
                    break;
                case Aws::CognitoIdentityProvider::Model::UsernameAttributeType::phone_number:
                    this->usernameAttributes.Add(EUsernameAttributeType::phone_number);
                    break;
                case Aws::CognitoIdentityProvider::Model::UsernameAttributeType::email:
                    this->usernameAttributes.Add(EUsernameAttributeType::email);
                    break;
                default:
                    this->usernameAttributes.Add(EUsernameAttributeType::NOT_SET);
                    break;
            };
        }

        this->smsVerificationMessage = UTF8_TO_TCHAR(awsUserPoolType.GetSmsVerificationMessage().c_str());

        this->emailVerificationMessage = UTF8_TO_TCHAR(awsUserPoolType.GetEmailVerificationMessage().c_str());

        this->emailVerificationSubject = UTF8_TO_TCHAR(awsUserPoolType.GetEmailVerificationSubject().c_str());

        this->verificationMessageTemplate.fromAWS(awsUserPoolType.GetVerificationMessageTemplate());

        this->smsAuthenticationMessage = UTF8_TO_TCHAR(awsUserPoolType.GetSmsAuthenticationMessage().c_str());

        this->userAttributeUpdateSettings.fromAWS(awsUserPoolType.GetUserAttributeUpdateSettings());

        switch(awsUserPoolType.GetMfaConfiguration()) {
            case Aws::CognitoIdentityProvider::Model::UserPoolMfaType::NOT_SET:
                this->mfaConfiguration = EUserPoolMfaType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OFF:
                this->mfaConfiguration = EUserPoolMfaType::OFF;
                break;
            case Aws::CognitoIdentityProvider::Model::UserPoolMfaType::ON:
                this->mfaConfiguration = EUserPoolMfaType::ON;
                break;
            case Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OPTIONAL_:
                this->mfaConfiguration = EUserPoolMfaType::OPTIONAL_;
                break;
            default:
                this->mfaConfiguration = EUserPoolMfaType::NOT_SET;
                break;
        }

        this->deviceConfiguration.fromAWS(awsUserPoolType.GetDeviceConfiguration());

        this->estimatedNumberOfUsers = awsUserPoolType.GetEstimatedNumberOfUsers();

        this->emailConfiguration.fromAWS(awsUserPoolType.GetEmailConfiguration());

        this->smsConfiguration.fromAWS(awsUserPoolType.GetSmsConfiguration());

        this->userPoolTags.Empty();
        for (const auto& elem : awsUserPoolType.GetUserPoolTags()) {
            this->userPoolTags.Add(elem.first.c_str(), elem.second.c_str());
        }

        this->smsConfigurationFailure = UTF8_TO_TCHAR(awsUserPoolType.GetSmsConfigurationFailure().c_str());

//        this->emailConfigurationFailure = UTF8_TO_TCHAR(awsUserPoolType.GetEmailConfigurationFailure().c_str());

        this->domain = UTF8_TO_TCHAR(awsUserPoolType.GetDomain().c_str());

        this->customDomain = UTF8_TO_TCHAR(awsUserPoolType.GetCustomDomain().c_str());

        this->adminCreateUserConfig.fromAWS(awsUserPoolType.GetAdminCreateUserConfig());

        this->userPoolAddOns.fromAWS(awsUserPoolType.GetUserPoolAddOns());

        this->usernameConfiguration.fromAWS(awsUserPoolType.GetUsernameConfiguration());

        this->arn = UTF8_TO_TCHAR(awsUserPoolType.GetArn().c_str());

        this->accountRecoverySetting.fromAWS(awsUserPoolType.GetAccountRecoverySetting());

        return *this;
    }
#endif
};
