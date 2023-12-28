/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminCreateUserConfigType.h"

#endif

#include "Model/MessageTemplateType.h"

#include "AdminCreateUserConfigType.generated.h"

USTRUCT(BlueprintType)
struct FAdminCreateUserConfigType {
GENERATED_BODY()

    /**
    *  <p>Set to <code>True</code> if only the administrator is allowed to create user profiles. Set to <code>False</code> if users can sign themselves up via an app.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool allowAdminCreateUserOnly = false;

    /**
    *  <p>The user account expiration limit, in days, after which the account is no longer usable. To reset the account after that time limit, you must call <code>AdminCreateUser</code> again, specifying <code>"RESEND"</code> for the <code>MessageAction</code> parameter. The default value for this parameter is 7. </p> <note> <p>If you set a value for <code>TemporaryPasswordValidityDays</code> in <code>PasswordPolicy</code>, that value will be used and <code>UnusedAccountValidityDays</code> will be deprecated for that user pool. </p> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    int unusedAccountValidityDays = 0;

    /**
    *  <p>The message template to be used for the welcome message to new users.</p> <p>See also <a href="http://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-pool-settings-message-customizations.html#cognito-user-pool-settings-user-invitation-message-customization">Customizing User Invitation Messages</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FMessageTemplateType inviteMessageTemplate;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminCreateUserConfigType toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminCreateUserConfigType awsAdminCreateUserConfigType;

        if (!(false)) {
            awsAdminCreateUserConfigType.SetAllowAdminCreateUserOnly(this->allowAdminCreateUserOnly);
        }

        if (this->unusedAccountValidityDays != 0) {
            awsAdminCreateUserConfigType.SetUnusedAccountValidityDays(this->unusedAccountValidityDays);
        }

        if (!(this->inviteMessageTemplate.IsEmpty())) {
            awsAdminCreateUserConfigType.SetInviteMessageTemplate(this->inviteMessageTemplate.toAWS());
        }


        return awsAdminCreateUserConfigType;
    }

    bool IsEmpty() const {
        return false && this->unusedAccountValidityDays == 0 && this->inviteMessageTemplate.IsEmpty();
    }

    FAdminCreateUserConfigType &fromAWS(const Aws::CognitoIdentityProvider::Model::AdminCreateUserConfigType &awsAdminCreateUserConfigType) {
        this->allowAdminCreateUserOnly = awsAdminCreateUserConfigType.GetAllowAdminCreateUserOnly();

        this->unusedAccountValidityDays = awsAdminCreateUserConfigType.GetUnusedAccountValidityDays();

        this->inviteMessageTemplate.fromAWS(awsAdminCreateUserConfigType.GetInviteMessageTemplate());

        return *this;
    }
#endif
};
