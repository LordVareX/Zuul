/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/ConfirmSignUpRequest.h"

#endif

#include "Model/AnalyticsMetadataType.h"
#include "Model/UserContextDataType.h"

#include "ConfirmSignUpRequest.generated.h"

USTRUCT(BlueprintType)
struct FConfirmSignUpRequest {
GENERATED_BODY()

    /**
    *  <p>The ID of the app client associated with the user pool.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString clientId;

    /**
    *  <p>A keyed-hash message authentication code (HMAC) calculated using the secret key of a user pool client and username plus the client ID in the message.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString secretHash;

    /**
    *  <p>The user name of the user whose registration you wish to confirm.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>The confirmation code sent by a user's request to confirm registration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString confirmationCode;

    /**
    *  <p>Boolean to be specified to force user confirmation irrespective of existing alias. By default set to <code>False</code>. If this parameter is set to <code>True</code> and the phone number/email used for sign up confirmation already exists as an alias with a different user, the API call will migrate the alias from the previous user to the newly created user being confirmed. If set to <code>False</code>, the API will throw an <b>AliasExistsException</b> error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool forceAliasCreation = false;

    /**
    *  <p>The Amazon Pinpoint analytics metadata for collecting metrics for <code>ConfirmSignUp</code> calls.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAnalyticsMetadataType analyticsMetadata;

    /**
    *  <p>Contextual data such as the user's device fingerprint, IP address, or location used for evaluating the risk of an unexpected event by Amazon Cognito advanced security.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserContextDataType userContextData;

    /**
    *  <p>A map of custom key-value pairs that you can provide as input for any custom workflows that this action triggers. </p> <p>You create custom workflows by assigning AWS Lambda functions to user pool triggers. When you use the ConfirmSignUp API action, Amazon Cognito invokes the function that is assigned to the <i>post confirmation</i> trigger. When Amazon Cognito invokes this function, it passes a JSON payload, which the function receives as input. This payload contains a <code>clientMetadata</code> attribute, which provides the data that you assigned to the ClientMetadata parameter in your ConfirmSignUp request. In your function code in AWS Lambda, you can process the <code>clientMetadata</code> value to enhance your workflow for your specific needs.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-identity-pools-working-with-aws-lambda-triggers.html">Customizing User Pool Workflows with Lambda Triggers</a> in the <i>Amazon Cognito Developer Guide</i>.</p> <note> <p>Take the following limitations into consideration when you use the ClientMetadata parameter:</p> <ul> <li> <p>Amazon Cognito does not store the ClientMetadata value. This data is available only to AWS Lambda triggers that are assigned to a user pool to support custom workflows. If your user pool configuration does not include triggers, the ClientMetadata parameter serves no purpose.</p> </li> <li> <p>Amazon Cognito does not validate the ClientMetadata value.</p> </li> <li> <p>Amazon Cognito does not encrypt the the ClientMetadata value, so don't use it to provide sensitive information.</p> </li> </ul> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> clientMetadata;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::ConfirmSignUpRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::ConfirmSignUpRequest awsConfirmSignUpRequest;

        if (!(this->clientId.IsEmpty())) {
            awsConfirmSignUpRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        if (!(this->secretHash.IsEmpty())) {
            awsConfirmSignUpRequest.SetSecretHash(TCHAR_TO_UTF8(*this->secretHash));
        }

        if (!(this->username.IsEmpty())) {
            awsConfirmSignUpRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->confirmationCode.IsEmpty())) {
            awsConfirmSignUpRequest.SetConfirmationCode(TCHAR_TO_UTF8(*this->confirmationCode));
        }

        if (!(false)) {
            awsConfirmSignUpRequest.SetForceAliasCreation(this->forceAliasCreation);
        }

        if (!(this->analyticsMetadata.IsEmpty())) {
            awsConfirmSignUpRequest.SetAnalyticsMetadata(this->analyticsMetadata.toAWS());
        }

        if (!(this->userContextData.IsEmpty())) {
            awsConfirmSignUpRequest.SetUserContextData(this->userContextData.toAWS());
        }

        for (const TPair<FString, FString>& elem : this->clientMetadata) {
            awsConfirmSignUpRequest.AddClientMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsConfirmSignUpRequest;
    }

    bool IsEmpty() const {
        return this->clientId.IsEmpty() && this->secretHash.IsEmpty() && this->username.IsEmpty() && this->confirmationCode.IsEmpty() && false && this->analyticsMetadata.IsEmpty() && this->userContextData.IsEmpty() && this->clientMetadata.Num() == 0;
    }
#endif
};
