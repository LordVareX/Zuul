/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/AdminUpdateUserAttributesRequest.h"

#endif

#include "Model/AttributeType.h"

#include "AdminUpdateUserAttributesRequest.generated.h"

USTRUCT(BlueprintType)
struct FAdminUpdateUserAttributesRequest {
GENERATED_BODY()

    /**
    *  <p>The user pool ID for the user pool where you want to update user attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString userPoolId;

    /**
    *  <p>The user name of the user for whom you want to update user attributes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString username;

    /**
    *  <p>An array of name-value pairs representing user attributes.</p> <p>For custom attributes, you must prepend the <code>custom:</code> prefix to the attribute name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<FAttributeType> userAttributes;

    /**
    *  <p>A map of custom key-value pairs that you can provide as input for any custom workflows that this action triggers. </p> <p>You create custom workflows by assigning AWS Lambda functions to user pool triggers. When you use the AdminUpdateUserAttributes API action, Amazon Cognito invokes the function that is assigned to the <i>custom message</i> trigger. When Amazon Cognito invokes this function, it passes a JSON payload, which the function receives as input. This payload contains a <code>clientMetadata</code> attribute, which provides the data that you assigned to the ClientMetadata parameter in your AdminUpdateUserAttributes request. In your function code in AWS Lambda, you can process the <code>clientMetadata</code> value to enhance your workflow for your specific needs.</p> <p>For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-identity-pools-working-with-aws-lambda-triggers.html">Customizing User Pool Workflows with Lambda Triggers</a> in the <i>Amazon Cognito Developer Guide</i>.</p> <note> <p>Take the following limitations into consideration when you use the ClientMetadata parameter:</p> <ul> <li> <p>Amazon Cognito does not store the ClientMetadata value. This data is available only to AWS Lambda triggers that are assigned to a user pool to support custom workflows. If your user pool configuration does not include triggers, the ClientMetadata parameter serves no purpose.</p> </li> <li> <p>Amazon Cognito does not validate the ClientMetadata value.</p> </li> <li> <p>Amazon Cognito does not encrypt the the ClientMetadata value, so don't use it to provide sensitive information.</p> </li> </ul> </note>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TMap<FString, FString> clientMetadata;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::AdminUpdateUserAttributesRequest toAWS() const {
        Aws::CognitoIdentityProvider::Model::AdminUpdateUserAttributesRequest awsAdminUpdateUserAttributesRequest;

        if (!(this->userPoolId.IsEmpty())) {
            awsAdminUpdateUserAttributesRequest.SetUserPoolId(TCHAR_TO_UTF8(*this->userPoolId));
        }

        if (!(this->username.IsEmpty())) {
            awsAdminUpdateUserAttributesRequest.SetUsername(TCHAR_TO_UTF8(*this->username));
        }

        for (const FAttributeType& elem : this->userAttributes) {
            awsAdminUpdateUserAttributesRequest.AddUserAttributes(elem.toAWS());
        }

        for (const TPair<FString, FString>& elem : this->clientMetadata) {
            awsAdminUpdateUserAttributesRequest.AddClientMetadata(TCHAR_TO_UTF8(*elem.Key), TCHAR_TO_UTF8(*elem.Value));
        }

        return awsAdminUpdateUserAttributesRequest;
    }

    bool IsEmpty() const {
        return this->userPoolId.IsEmpty() && this->username.IsEmpty() && this->userAttributes.Num() == 0 && this->clientMetadata.Num() == 0;
    }
#endif
};
