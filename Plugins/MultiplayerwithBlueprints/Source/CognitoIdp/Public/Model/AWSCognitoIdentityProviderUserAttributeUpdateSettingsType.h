/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, December 2022
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserAttributeUpdateSettingsType.h"

#endif

#include "Model/VerifiedAttributeType.h"

#include "AWSCognitoIdentityProviderUserAttributeUpdateSettingsType.generated.h"

USTRUCT(BlueprintType)
struct FAWSCognitoIdentityProviderUserAttributeUpdateSettingsType {
GENERATED_BODY()

    /**
    *  <p>Requires that your user verifies their email address, phone number, or both before Amazon Cognito updates the value of that attribute. When you update a user attribute that has this option activated, Amazon Cognito sends a verification message to the new phone number or email address. Amazon Cognito doesn’t change the value of the attribute until your user responds to the verification message and confirms the new value.</p> <p>You can verify an updated email address or phone number with a <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_VerifyUserAttribute.html">VerifyUserAttribute</a> API request. You can also call the <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_UpdateUserAttributes.html">UpdateUserAttributes</a> or <a href="https://docs.aws.amazon.com/cognito-user-identity-pools/latest/APIReference/API_AdminUpdateUserAttributes.html">AdminUpdateUserAttributes</a> API and set <code>email_verified</code> or <code>phone_number_verified</code> to true.</p> <p>When <code>AttributesRequireVerificationBeforeUpdate</code> is false, your user pool doesn't require that your users verify attribute changes before Amazon Cognito updates them. In a user pool where <code>AttributesRequireVerificationBeforeUpdate</code> is false, API operations that change attribute values can immediately update a user’s <code>email</code> or <code>phone_number</code> attribute.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    TArray<EVerifiedAttributeType> attributesRequireVerificationBeforeUpdate;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::UserAttributeUpdateSettingsType toAWS() const {
        Aws::CognitoIdentityProvider::Model::UserAttributeUpdateSettingsType awsUserAttributeUpdateSettingsType;

        for (const EVerifiedAttributeType& elem : this->attributesRequireVerificationBeforeUpdate) {
		    switch(elem) {
                case EVerifiedAttributeType::phone_number:
                    awsUserAttributeUpdateSettingsType.AddAttributesRequireVerificationBeforeUpdate(Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::phone_number);
                    break;
                case EVerifiedAttributeType::email:
                    awsUserAttributeUpdateSettingsType.AddAttributesRequireVerificationBeforeUpdate(Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::email);
                    break;
                default:
                    break;
            };
        }
        return awsUserAttributeUpdateSettingsType;
    }

    bool IsEmpty() const {
        return this->attributesRequireVerificationBeforeUpdate.Num() == 0;
    }

    FAWSCognitoIdentityProviderUserAttributeUpdateSettingsType &fromAWS(const Aws::CognitoIdentityProvider::Model::UserAttributeUpdateSettingsType &awsUserAttributeUpdateSettingsType) {
        this->attributesRequireVerificationBeforeUpdate.Empty();
        for (const Aws::CognitoIdentityProvider::Model::VerifiedAttributeType& elem : awsUserAttributeUpdateSettingsType.GetAttributesRequireVerificationBeforeUpdate()) {
            switch(elem) {
                case Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::NOT_SET:
                    this->attributesRequireVerificationBeforeUpdate.Add(EVerifiedAttributeType::NOT_SET);
                    break;
                case Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::phone_number:
                    this->attributesRequireVerificationBeforeUpdate.Add(EVerifiedAttributeType::phone_number);
                    break;
                case Aws::CognitoIdentityProvider::Model::VerifiedAttributeType::email:
                    this->attributesRequireVerificationBeforeUpdate.Add(EVerifiedAttributeType::email);
                    break;
                default:
                    break;
		    };
        }

        return *this;
    }
#endif
};
