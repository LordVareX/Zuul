/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminGetUserResult.h"

#endif

#include "Model/AttributeType.h"
#include "Model/UserStatusType.h"
#include "Model/MFAOptionType.h"

#include "AdminGetUserResult.generated.h"

USTRUCT(BlueprintType)
struct FAdminGetUserResult {
GENERATED_BODY()

    /**
    *  <p>The user name of the user about whom you are receiving information.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>An array of name-value pairs representing user attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FAttributeType> userAttributes;

    /**
    *  <p>The date the user was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime userCreateDate;

    /**
    *  <p>The date the user was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime userLastModifiedDate;

    /**
    *  <p>Indicates that the status is enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool enabled = false;

    /**
    *  <p>The user status. Can be one of the following:</p> <ul> <li> <p>UNCONFIRMED - User has been created but not confirmed.</p> </li> <li> <p>CONFIRMED - User has been confirmed.</p> </li> <li> <p>ARCHIVED - User is no longer active.</p> </li> <li> <p>COMPROMISED - User is disabled due to a potential security threat.</p> </li> <li> <p>UNKNOWN - User status is not known.</p> </li> <li> <p>RESET_REQUIRED - User is confirmed, but the user must request a code and reset his or her password before he or she can sign in.</p> </li> <li> <p>FORCE_CHANGE_PASSWORD - The user is confirmed and the user can sign in using a temporary password, but on first sign-in, the user must change his or her password to a new value before doing anything else. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EUserStatusType userStatus = EUserStatusType::NOT_SET;

    /**
    *  <p>Specifies the options for MFA (e.g., email or phone number).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FMFAOptionType> MFAOptions;

    /**
    *  <p>The user's preferred MFA setting.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString preferredMfaSetting;

    /**
    *  <p>The list of the user's MFA settings.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FString> userMFASettingList;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FAdminGetUserResult &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminGetUserResult &awsAdminGetUserResult) {

        this->username = UTF8_TO_TCHAR(awsAdminGetUserResult.GetUsername().c_str());

        this->userAttributes.Empty();
        for (const Aws::CognitoIdentityProvider::Model::AttributeType& elem : awsAdminGetUserResult.GetUserAttributes()) {
            this->userAttributes.Add(FAttributeType().fromAWS(elem));
        }

        this->userCreateDate = FDateTime(1970, 1, 1) + FTimespan(awsAdminGetUserResult.GetUserCreateDate().Millis() * ETimespan::TicksPerMillisecond);

        this->userLastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsAdminGetUserResult.GetUserLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        this->enabled = awsAdminGetUserResult.GetEnabled();

        switch(awsAdminGetUserResult.GetUserStatus()) {
            case Aws::CognitoIdentityProvider::Model::UserStatusType::NOT_SET:
                this->userStatus = EUserStatusType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::UserStatusType::UNCONFIRMED:
                this->userStatus = EUserStatusType::UNCONFIRMED;
                break;
            case Aws::CognitoIdentityProvider::Model::UserStatusType::CONFIRMED:
                this->userStatus = EUserStatusType::CONFIRMED;
                break;
            case Aws::CognitoIdentityProvider::Model::UserStatusType::ARCHIVED:
                this->userStatus = EUserStatusType::ARCHIVED;
                break;
            case Aws::CognitoIdentityProvider::Model::UserStatusType::COMPROMISED:
                this->userStatus = EUserStatusType::COMPROMISED;
                break;
            case Aws::CognitoIdentityProvider::Model::UserStatusType::UNKNOWN:
                this->userStatus = EUserStatusType::UNKNOWN;
                break;
            case Aws::CognitoIdentityProvider::Model::UserStatusType::RESET_REQUIRED:
                this->userStatus = EUserStatusType::RESET_REQUIRED;
                break;
            case Aws::CognitoIdentityProvider::Model::UserStatusType::FORCE_CHANGE_PASSWORD:
                this->userStatus = EUserStatusType::FORCE_CHANGE_PASSWORD;
                break;
            default:
                this->userStatus = EUserStatusType::NOT_SET;
                break;
        }

        this->MFAOptions.Empty();
        for (const Aws::CognitoIdentityProvider::Model::MFAOptionType& elem : awsAdminGetUserResult.GetMFAOptions()) {
            this->MFAOptions.Add(FMFAOptionType().fromAWS(elem));
        }

        this->preferredMfaSetting = UTF8_TO_TCHAR(awsAdminGetUserResult.GetPreferredMfaSetting().c_str());

        this->userMFASettingList.Empty();
        for (const Aws::String& elem : awsAdminGetUserResult.GetUserMFASettingList()) {
            this->userMFASettingList.Add(elem.c_str());
        }

        return *this;
    }
#endif
};
