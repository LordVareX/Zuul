/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ForgotPasswordRequest.h"

#endif

#include "Model/UserContextDataType.h"
#include "Model/AnalyticsMetadataType.h"

#include "ForgotPasswordRequest.generated.h"

USTRUCT(BlueprintType)
struct FForgotPasswordRequest {
GENERATED_BODY()

    /**
    *  <p>The ID of the client associated with the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>A keyed-hash message authentication code (HMAC) calculated using the secret key of a user pool client and username plus the client ID in the message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString secretHash;

    /**
    *  <p>Contextual data such as the user's device fingerprint, IP address, or location used for evaluating the risk of an unexpected event by Amazon Cognito advanced security.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserContextDataType userContextData;

    /**
    *  <p>The user name of the user for whom you want to enter a code to reset a forgotten password.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>The Amazon Pinpoint analytics metadata for collecting metrics for <code>ForgotPassword</code> calls.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAnalyticsMetadataType analyticsMetadata;

    /**
    *  <p>A map of custom key-value pairs that you can provide as input for any custom workflows that this action triggers. </p> <p>You create custom workflows by assigning AWS Lambda functions to user pool triggers. When you use the ForgotPassword API action, Amazon Cognito invokes any functions that are assigned to the following triggers: <i>pre sign-up</i>, <i>custom message</i>, and <i>user migration</i>. When Amazon Cognito invokes any of these functions, it passes a JSON payload, which the function receives as input. This payload contains a <code>clientMetadata</code> attribute, which provides the data that you assigned to the ClientMetadata parameter in your ForgotPassword request. In your function code in AWS Lambda, you can process the <code>clientMetadata</code> value to enhance your workflow for your specific needs.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-identity-pools-working-with-aws-lambda-triggers.html">Customizing User Pool Workflows with Lambda Triggers</a> in the <i>Amazon Cognito Developer Guide</i>.</p> <note> <p>Take the following limitations into consideration when you use the ClientMetadata parameter:</p> <ul> <li> <p>Amazon Cognito does not store the ClientMetadata value. This data is available only to AWS Lambda triggers that are assigned to a user pool to support custom workflows. If your user pool configuration does not include triggers, the ClientMetadata parameter serves no purpose.</p> </li> <li> <p>Amazon Cognito does not validate the ClientMetadata value.</p> </li> <li> <p>Amazon Cognito does not encrypt the the ClientMetadata value, so don't use it to provide sensitive information.</p> </li> </ul> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> clientMetadata;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ForgotPasswordRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ForgotPasswordRequest awsForgotPasswordRequest;

        if (!(this->clientId.IsEmpty())) {
            awsForgotPasswordRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        if (!(this->secretHash.IsEmpty())) {
            awsForgotPasswordRequest.SetSecretHash(TCHAR_TO_UTF8(*this->secretHash));
        }

        if (!(this->userContextData.IsEmpty())) {
            awsForgotPasswordRequest.SetUserContextData(this->userContextData.toAWS());
        }

        if (!(this->username.IsEmpty())) {
            awsForgotPasswordRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->analyticsMetadata.IsEmpty())) {
            awsForgotPasswordRequest.SetAnalyticsMetadata(this->analyticsMetadata.toAWS());
        }

        for (const TPair<FString, FString>& elem : this->clientMetadata) {
            awsForgotPasswordRequest.AddClientMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsForgotPasswordRequest;
    }

    bool IsEmpty() const {
        return this->clientId.IsEmpty() && this->secretHash.IsEmpty() && this->userContextData.IsEmpty() && this->username.IsEmpty() && this->analyticsMetadata.IsEmpty() && this->clientMetadata.Num() == 0;
    }
#endif
};
