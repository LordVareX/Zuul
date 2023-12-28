/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UsernameConfigurationType.h"

#endif

#include "UsernameConfigurationType.generated.h"

USTRUCT(BlueprintType)
struct FUsernameConfigurationType {
GENERATED_BODY()

    /**
    *  <p>Specifies whether username case sensitivity will be applied for all users in the user pool through Cognito APIs.</p> <p>Valid values include:</p> <ul> <li> <p> <b> <code>True</code> </b>: Enables case sensitivity for all username input. When this option is set to <code>True</code>, users must sign in using the exact capitalization of their given username. For example, “UserName”. This is the default value.</p> </li> <li> <p> <b> <code>False</code> </b>: Enables case insensitivity for all username input. For example, when this option is set to <code>False</code>, users will be able to sign in using either "username" or "Username". This option also enables both <code>preferred_username</code> and <code>email</code> alias to be case insensitive, in addition to the <code>username</code> attribute.</p> </li> </ul>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool caseSensitive = false;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UsernameConfigurationType toAWS() const {
        Aws::CognitoIdentityProvider::Model::UsernameConfigurationType awsUsernameConfigurationType;

        if (!(false)) {
            awsUsernameConfigurationType.SetCaseSensitive(this->caseSensitive);
        }

        return awsUsernameConfigurationType;
    }

    bool IsEmpty() const {
        return false;
    }

    FUsernameConfigurationType &fromAWS(const Aws::CognitoIdentityProvider::Model::UsernameConfigurationType &awsUsernameConfigurationType) {
        this->caseSensitive = awsUsernameConfigurationType.GetCaseSensitive();

        return *this;
    }
#endif
};
