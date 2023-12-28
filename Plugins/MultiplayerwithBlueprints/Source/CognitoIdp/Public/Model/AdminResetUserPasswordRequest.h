/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminResetUserPasswordRequest.h"

#endif

#include "AdminResetUserPasswordRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminResetUserPasswordRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to reset the user's password.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name of the user whose password you wish to reset.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>A map of custom key-value pairs that you can provide as input for any custom workflows that this action triggers. </p> <p>You create custom workflows by assigning AWS Lambda functions to user pool triggers. When you use the AdminResetUserPassword API action, Amazon Cognito invokes the function that is assigned to the <i>custom message</i> trigger. When Amazon Cognito invokes this function, it passes a JSON payload, which the function receives as input. This payload contains a <code>clientMetadata</code> attribute, which provides the data that you assigned to the ClientMetadata parameter in your AdminResetUserPassword request. In your function code in AWS Lambda, you can process the <code>clientMetadata</code> value to enhance your workflow for your specific needs.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-identity-pools-working-with-aws-lambda-triggers.html">Customizing User Pool Workflows with Lambda Triggers</a> in the <i>Amazon Cognito Developer Guide</i>.</p> <note> <p>Take the following limitations into consideration when you use the ClientMetadata parameter:</p> <ul> <li> <p>Amazon Cognito does not store the ClientMetadata value. This data is available only to AWS Lambda triggers that are assigned to a user pool to support custom workflows. If your user pool configuration does not include triggers, the ClientMetadata parameter serves no purpose.</p> </li> <li> <p>Amazon Cognito does not validate the ClientMetadata value.</p> </li> <li> <p>Amazon Cognito does not encrypt the the ClientMetadata value, so don't use it to provide sensitive information.</p> </li> </ul> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> clientMetadata;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminResetUserPasswordRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminResetUserPasswordRequest awsAdminResetUserPasswordRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminResetUserPasswordRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminResetUserPasswordRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        for (const TPair<FString, FString>& elem : this->clientMetadata) {
            awsAdminResetUserPasswordRequest.AddClientMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsAdminResetUserPasswordRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->clientMetadata.Num() == 0;
    }
#endif
};
