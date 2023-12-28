/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserType.h"

#endif

#include "Model/AttributeType.h"
#include "Model/UserStatusType.h"
#include "Model/MFAOptionType.h"

#include "UserType.generated.h"

USTRUCT(BlueprintType)
struct FUserType {
GENERATED_BODY()

    /**
    *  <p>The user name of the user you wish to describe.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>A container with information about the user type attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FAttributeType> attributes;

    /**
    *  <p>The creation date of the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime userCreateDate;

    /**
    *  <p>The last modified date of the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime userLastModifiedDate;

    /**
    *  <p>Specifies whether the user is enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool enabled = false;

    /**
    *  <p>The user status. Can be one of the following:</p> <ul> <li> <p>UNCONFIRMED - User has been created but not confirmed.</p> </li> <li> <p>CONFIRMED - User has been confirmed.</p> </li> <li> <p>ARCHIVED - User is no longer active.</p> </li> <li> <p>COMPROMISED - User is disabled due to a potential security threat.</p> </li> <li> <p>UNKNOWN - User status is not known.</p> </li> <li> <p>RESET_REQUIRED - User is confirmed, but the user must request a code and reset his or her password before he or she can sign in.</p> </li> <li> <p>FORCE_CHANGE_PASSWORD - The user is confirmed and the user can sign in using a temporary password, but on first sign-in, the user must change his or her password to a new value before doing anything else. </p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EUserStatusType userStatus = EUserStatusType::NOT_SET;

    /**
    *  <p>The MFA options for the user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FMFAOptionType> MFAOptions;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUserType &fromAWS(const Aws::CognitoIdentityProvider::Model::UserType &awsUserType) {
        this->username = UTF8_TO_TCHAR(awsUserType.GetUsername().c_str());

        this->attributes.Empty();
        for (const Aws::CognitoIdentityProvider::Model::AttributeType& elem : awsUserType.GetAttributes()) {
            this->attributes.Add(FAttributeType().fromAWS(elem));
        }

        this->userCreateDate = FDateTime(1970, 1, 1) + FTimespan(awsUserType.GetUserCreateDate().Millis() * ETimespan::TicksPerMillisecond);

        this->userLastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsUserType.GetUserLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        this->enabled = awsUserType.GetEnabled();

        switch(awsUserType.GetUserStatus()) {
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
        for (const Aws::CognitoIdentityProvider::Model::MFAOptionType& elem : awsUserType.GetMFAOptions()) {
            this->MFAOptions.Add(FMFAOptionType().fromAWS(elem));
        }

        return *this;
    }
#endif
};
