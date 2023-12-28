/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SignUpRequest.h"

#endif

#include "Model/AttributeType.h"
#include "Model/AttributeType.h"
#include "Model/AnalyticsMetadataType.h"
#include "Model/UserContextDataType.h"

#include "SignUpRequest.generated.h"

USTRUCT(BlueprintType)
struct FSignUpRequest {
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
    *  <p>The user name of the user you wish to register.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>The password of the user you wish to register.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString password;

    /**
    *  <p>An array of name-value pairs representing user attributes.</p> <p>For custom attributes, you must prepend the <code>custom:</code> prefix to the attribute name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FAttributeType> userAttributes;

    /**
    *  <p>The validation data in the request to register a user.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FAttributeType> validationData;

    /**
    *  <p>The Amazon Pinpoint analytics metadata for collecting metrics for <code>SignUp</code> calls.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FAnalyticsMetadataType analyticsMetadata;

    /**
    *  <p>Contextual data such as the user's device fingerprint, IP address, or location used for evaluating the risk of an unexpected event by Amazon Cognito advanced security.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FUserContextDataType userContextData;

    /**
    *  <p>A map of custom key-value pairs that you can provide as input for any custom workflows that this action triggers. </p> <p>You create custom workflows by assigning AWS Lambda functions to user pool triggers. When you use the SignUp API action, Amazon Cognito invokes any functions that are assigned to the following triggers: <i>pre sign-up</i>, <i>custom message</i>, and <i>post confirmation</i>. When Amazon Cognito invokes any of these functions, it passes a JSON payload, which the function receives as input. This payload contains a <code>clientMetadata</code> attribute, which provides the data that you assigned to the ClientMetadata parameter in your SignUp request. In your function code in AWS Lambda, you can process the <code>clientMetadata</code> value to enhance your workflow for your specific needs.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-identity-pools-working-with-aws-lambda-triggers.html">Customizing User Pool Workflows with Lambda Triggers</a> in the <i>Amazon Cognito Developer Guide</i>.</p> <note> <p>Take the following limitations into consideration when you use the ClientMetadata parameter:</p> <ul> <li> <p>Amazon Cognito does not store the ClientMetadata value. This data is available only to AWS Lambda triggers that are assigned to a user pool to support custom workflows. If your user pool configuration does not include triggers, the ClientMetadata parameter serves no purpose.</p> </li> <li> <p>Amazon Cognito does not validate the ClientMetadata value.</p> </li> <li> <p>Amazon Cognito does not encrypt the the ClientMetadata value, so don't use it to provide sensitive information.</p> </li> </ul> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> clientMetadata;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SignUpRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::SignUpRequest awsSignUpRequest;

        if (!(this->clientId.IsEmpty())) {
            awsSignUpRequest.SetClientId(TCHAR_TO_UTF8(*this->clientId));
        }

        if (!(this->secretHash.IsEmpty())) {
            awsSignUpRequest.SetSecretHash(TCHAR_TO_UTF8(*this->secretHash));
        }

        if (!(this->username.IsEmpty())) {
            awsSignUpRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        if (!(this->password.IsEmpty())) {
            awsSignUpRequest.SetPassword(TCHAR_TO_UTF8(*this->password));
        }

        for (const FAttributeType& elem : this->userAttributes) {
            awsSignUpRequest.AddUserAttributes(elem.toAWS());
        }

        for (const FAttributeType& elem : this->validationData) {
            awsSignUpRequest.AddValidationData(elem.toAWS());
        }

        if (!(this->analyticsMetadata.IsEmpty())) {
            awsSignUpRequest.SetAnalyticsMetadata(this->analyticsMetadata.toAWS());
        }

        if (!(this->userContextData.IsEmpty())) {
            awsSignUpRequest.SetUserContextData(this->userContextData.toAWS());
        }

        for (const TPair<FString, FString>& elem : this->clientMetadata) {
            awsSignUpRequest.AddClientMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsSignUpRequest;
    }

    bool IsEmpty() const {
        return this->clientId.IsEmpty() && this->secretHash.IsEmpty() && this->username.IsEmpty() && this->password.IsEmpty() && this->userAttributes.Num() == 0 && this->validationData.Num() == 0 && this->analyticsMetadata.IsEmpty() && this->userContextData.IsEmpty() && this->clientMetadata.Num() == 0;
    }
#endif
};
