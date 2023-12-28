/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/CreateUserPoolRequest.h"

#endif

#include "Model/UserPoolPolicyType.h"
#include "Model/AWSCognitoIdentityProviderDeletionProtectionType.h"
#include "Model/LambdaConfigType.h"
#include "Model/VerifiedAttributeType.h"
#include "Model/AliasAttributeType.h"
#include "Model/UsernameAttributeType.h"
#include "Model/VerificationMessageTemplateType.h"
#include "Model/UserPoolMfaType.h"
#include "Model/AWSCognitoIdentityProviderUserAttributeUpdateSettingsType.h"
#include "Model/DeviceConfigurationType.h"
#include "Model/EmailConfigurationType.h"
#include "Model/SmsConfigurationType.h"
#include "Model/AdminCreateUserConfigType.h"
#include "Model/SchemaAttributeType.h"
#include "Model/UserPoolAddOnsType.h"
#include "Model/UsernameConfigurationType.h"
#include "Model/AccountRecoverySettingType.h"

#include "CreateUserPoolRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateUserPoolRequest {
GENERATED_BODY()

    /**
    *  <p>A string used to name the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString poolName;

    /**
    *  <p>The policies associated with the new user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolPolicyType policies;

    /**
    *  <p>When active, <code>DeletionProtection</code> prevents accidental deletion of your user pool. Before you can delete a user pool that you have protected against deletion, you must deactivate this feature.</p> <p>When you try to delete a protected user pool in a <code>DeleteUserPool</code> API request, Amazon Cognito returns an <code>InvalidParameterException</code> error. To delete a protected user pool, send a new <code>DeleteUserPool</code> request after you deactivate deletion protection in an <code>UpdateUserPool</code> API request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAWSCognitoIdentityProviderDeletionProtectionType deletionProtection = EAWSCognitoIdentityProviderDeletionProtectionType::NOT_SET;

    /**
    *  <p>The Lambda trigger configuration information for the new user pool.</p>  <p>In a push model, event sources (such as Amazon S3 and custom applications) need permission to invoke a function. So you must make an extra call to add permission for these event sources to invoke your Lambda function.</p> <p/> <p>For more information on using the Lambda API to add permission, see<a href="https://docs.aws.amazon.com/lambda/latest/dg/API_AddPermission.html"> AddPermission </a>. </p> <p>For adding permission using the CLI, see<a href="https://docs.aws.amazon.com/cli/latest/reference/lambda/add-permission.html"> add-permission </a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FLambdaConfigType lambdaConfig;

    /**
    *  <p>The attributes to be auto-verified. Possible values: <b>email</b>, <b>phone_number</b>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EVerifiedAttributeType> autoVerifiedAttributes;

    /**
    *  <p>Attributes supported as an alias for this user pool. Possible values: <b>phone_number</b>, <b>email</b>, or <b>preferred_username</b>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EAliasAttributeType> aliasAttributes;

    /**
    *  <p>Specifies whether a user can use an email address or phone number as a username when they sign up.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EUsernameAttributeType> usernameAttributes;

    /**
    *  <p>This parameter is no longer used. See <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_VerificationMessageTemplateType.html">VerificationMessageTemplateType</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString smsVerificationMessage;

    /**
    *  <p>A string representing the email verification message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailVerificationMessage;

    /**
    *  <p>A string representing the email verification subject.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString emailVerificationSubject;

    /**
    *  <p>The template for the verification message that the user sees when the app requests permission to access the user's information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FVerificationMessageTemplateType verificationMessageTemplate;

    /**
    *  <p>A string representing the SMS authentication message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString smsAuthenticationMessage;

    /**
    *  <p>Specifies MFA configuration details.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EUserPoolMfaType mfaConfiguration = EUserPoolMfaType::NOT_SET;

    /**
    *  <p>The settings for updates to user attributes. These settings include the property <code>AttributesRequireVerificationBeforeUpdate</code>, a user-pool setting that tells Amazon Cognito how to handle changes to the value of your users' email address and phone number attributes. For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/user-pool-settings-email-phone-verification.html#user-pool-settings-verifications-verify-attribute-updates"> Verifying updates to email addresses and phone numbers</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAWSCognitoIdentityProviderUserAttributeUpdateSettingsType userAttributeUpdateSettings;

    /**
    *  <p>The device configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDeviceConfigurationType deviceConfiguration;

    /**
    *  <p>The email configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FEmailConfigurationType emailConfiguration;

    /**
    *  <p>The SMS configuration.</p>
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
    *  <p>An array of schema attributes for the new user pool. These attributes can be standard or custom attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FSchemaAttributeType> schema;

    /**
    *  <p>Used to enable advanced security risk detection. Set the key <code>AdvancedSecurityMode</code> to the value "AUDIT".</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserPoolAddOnsType userPoolAddOns;

    /**
    *  <p>You can choose to set case sensitivity on the username input for the selected sign-in option. For example, when this is set to <code>False</code>, users will be able to sign in using either "username" or "Username". This configuration is immutable once it has been set. For more information, see .</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUsernameConfigurationType usernameConfiguration;

    /**
    *  <p>Use this setting to define which verified available method a user can use to recover their password when they call <code>ForgotPassword</code>. It allows you to define a preferred method when a user has more than one method available. With this setting, SMS does not qualify for a valid password recovery mechanism if the user also has SMS MFA enabled. In the absence of this setting, Cognito uses the legacy behavior to determine the recovery method where SMS is preferred over email.</p> <note> <p>Starting February 1, 2020, the value of <code>AccountRecoverySetting</code> will default to <code>verified_email</code> first and <code>verified_phone_number</code> as the second option for newly created user pools if no value is provided.</p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAccountRecoverySettingType accountRecoverySetting;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::CreateUserPoolRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::CreateUserPoolRequest awsCreateUserPoolRequest;

        if (!(this->poolName.IsEmpty())) {
            awsCreateUserPoolRequest.SetPoolName(TCHAR_TO_UTF8(*this->poolName));
        }

        if (!(this->policies.IsEmpty())) {
            awsCreateUserPoolRequest.SetPolicies(this->policies.toAWS());
        }

        switch(this->deletionProtection) {
            case EAWSCognitoIdentityProviderDeletionProtectionType::ACTIVE:
                awsCreateUserPoolRequest.SetDeletionProtection(Aws::CognitoIdentityProvider::Model::DeletionProtectionType::ACTIVE);
                break;
            case EAWSCognitoIdentityProviderDeletionProtectionType::INACTIVE:
                awsCreateUserPoolRequest.SetDeletionProtection(Aws::CognitoIdentityProvider::Model::DeletionProtectionType::INACTIVE);
                break;
            default:
                break;
        }

        if (!(this->lambdaConfig.IsEmpty())) {
            awsCreateUserPoolRequest.SetLambdaConfig(this->lambdaConfig.toAWS());
        }

        for (const EVerifiedAttributeType& elem : this->autoVerifiedAttributes) {
            switch(elem) {
                case EVerifiedAttributeType::phone_number:
                    awsCreateUserPoolRequest.AddAutoVerifiedAttributes(Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::phone_number);
                    break;
                case EVerifiedAttributeType::email:
                    awsCreateUserPoolRequest.AddAutoVerifiedAttributes(Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::email);
                    break;
                default:
                    break;
            };
        }

        for (const EAliasAttributeType& elem : this->aliasAttributes) {
            switch(elem) {
                case EAliasAttributeType::phone_number:
                    awsCreateUserPoolRequest.AddAliasAttributes(Aws::CognitoIdentityProvider::Model::AliasAttributeType::phone_number);
                    break;
                case EAliasAttributeType::email:
                    awsCreateUserPoolRequest.AddAliasAttributes(Aws::CognitoIdentityProvider::Model::AliasAttributeType::email);
                    break;
                case EAliasAttributeType::preferred_username:
                    awsCreateUserPoolRequest.AddAliasAttributes(Aws::CognitoIdentityProvider::Model::AliasAttributeType::preferred_username);
                    break;
                default:
                    break;
            };
        }

        for (const EUsernameAttributeType& elem : this->usernameAttributes) {
            switch(elem) {
                case EUsernameAttributeType::phone_number:
                    awsCreateUserPoolRequest.AddUsernameAttributes(Aws::CognitoIdentityProvider::Model::UsernameAttributeType::phone_number);
                    break;
                case EUsernameAttributeType::email:
                    awsCreateUserPoolRequest.AddUsernameAttributes(Aws::CognitoIdentityProvider::Model::UsernameAttributeType::email);
                    break;
                default:
                    break;
            };
        }

        if (!(this->smsVerificationMessage.IsEmpty())) {
            awsCreateUserPoolRequest.SetSmsVerificationMessage(TCHAR_TO_UTF8(*this->smsVerificationMessage));
        }

        if (!(this->emailVerificationMessage.IsEmpty())) {
            awsCreateUserPoolRequest.SetEmailVerificationMessage(TCHAR_TO_UTF8(*this->emailVerificationMessage));
        }

        if (!(this->emailVerificationSubject.IsEmpty())) {
            awsCreateUserPoolRequest.SetEmailVerificationSubject(TCHAR_TO_UTF8(*this->emailVerificationSubject));
        }

        if (!(this->verificationMessageTemplate.IsEmpty())) {
            awsCreateUserPoolRequest.SetVerificationMessageTemplate(this->verificationMessageTemplate.toAWS());
        }

        if (!(this->smsAuthenticationMessage.IsEmpty())) {
            awsCreateUserPoolRequest.SetSmsAuthenticationMessage(TCHAR_TO_UTF8(*this->smsAuthenticationMessage));
        }

        switch(this->mfaConfiguration) {
            case EUserPoolMfaType::OFF:
                awsCreateUserPoolRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OFF);
                break;
            case EUserPoolMfaType::ON:
                awsCreateUserPoolRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::ON);
                break;
            case EUserPoolMfaType::OPTIONAL_:
                awsCreateUserPoolRequest.SetMfaConfiguration(Aws::CognitoIdentityProvider::Model::UserPoolMfaType::OPTIONAL_);
                break;
            default:
                break;
        }

        if (!(this->userAttributeUpdateSettings.IsEmpty())) {
            awsCreateUserPoolRequest.SetUserAttributeUpdateSettings(this->userAttributeUpdateSettings.toAWS());
        }

        if (!(this->deviceConfiguration.IsEmpty())) {
            awsCreateUserPoolRequest.SetDeviceConfiguration(this->deviceConfiguration.toAWS());
        }

        if (!(this->emailConfiguration.IsEmpty())) {
            awsCreateUserPoolRequest.SetEmailConfiguration(this->emailConfiguration.toAWS());
        }

        if (!(this->smsConfiguration.IsEmpty())) {
            awsCreateUserPoolRequest.SetSmsConfiguration(this->smsConfiguration.toAWS());
        }

        for (const TPair<FString, FString>& elem : this->userPoolTags) {
            awsCreateUserPoolRequest.AddUserPoolTags(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        if (!(this->adminCreateUserConfig.IsEmpty())) {
            awsCreateUserPoolRequest.SetAdminCreateUserConfig(this->adminCreateUserConfig.toAWS());
        }

        for (const FSchemaAttributeType& elem : this->schema) {
            awsCreateUserPoolRequest.AddSchema(elem.toAWS());
        }

        if (!(this->userPoolAddOns.IsEmpty())) {
            awsCreateUserPoolRequest.SetUserPoolAddOns(this->userPoolAddOns.toAWS());
        }

        if (!(this->usernameConfiguration.IsEmpty())) {
            awsCreateUserPoolRequest.SetUsernameConfiguration(this->usernameConfiguration.toAWS());
        }

        if (!(this->accountRecoverySetting.IsEmpty())) {
            awsCreateUserPoolRequest.SetAccountRecoverySetting(this->accountRecoverySetting.toAWS());
        }

        return awsCreateUserPoolRequest;
    }

    bool IsEmpty() const {
        return this->poolName.IsEmpty() && this->policies.IsEmpty() && deletionProtection == EAWSCognitoIdentityProviderDeletionProtectionType::NOT_SET && this->lambdaConfig.IsEmpty() && this->autoVerifiedAttributes.Num() == 0 && this->aliasAttributes.Num() == 0 && this->usernameAttributes.Num() == 0 && this->smsVerificationMessage.IsEmpty() && this->emailVerificationMessage.IsEmpty() && this->emailVerificationSubject.IsEmpty() && this->verificationMessageTemplate.IsEmpty() && this->smsAuthenticationMessage.IsEmpty() && this->mfaConfiguration == EUserPoolMfaType::NOT_SET && this->userAttributeUpdateSettings.IsEmpty() && this->deviceConfiguration.IsEmpty() && this->emailConfiguration.IsEmpty() && this->smsConfiguration.IsEmpty() && this->userPoolTags.Num() == 0 && this->adminCreateUserConfig.IsEmpty() && this->schema.Num() == 0 && this->userPoolAddOns.IsEmpty() && this->usernameConfiguration.IsEmpty() && this->accountRecoverySetting.IsEmpty();
    }
#endif
};
