/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/SchemaAttributeType.h"

#endif

#include "Model/AttributeDataType.h"
#include "Model/NumberAttributeConstraintsType.h"
#include "Model/StringAttributeConstraintsType.h"

#include "SchemaAttributeType.generated.h"

USTRUCT(BlueprintType)
struct FSchemaAttributeType {
GENERATED_BODY()

    /**
    *  <p>A schema attribute of the name type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString name;

    /**
    *  <p>The attribute data type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EAttributeDataType attributeDataType = EAttributeDataType::NOT_SET;

    /**
    *  <p>Specifies whether the attribute type is developer only.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool developerOnlyAttribute = false;

    /**
    *  <p>Specifies whether the value of the attribute can be changed.</p> <p>For any user pool attribute that's mapped to an identity provider attribute, you must set this parameter to <code>true</code>. Amazon Cognito updates mapped attributes when users sign in to your application through an identity provider. If an attribute is immutable, Amazon Cognito throws an error when it attempts to update the attribute. For more information, see <a href="https://docs.aws.amazon.com/cognito/latest/developerguide/cognito-user-pools-specifying-attribute-mapping.html">Specifying Identity Provider Attribute Mappings for Your User Pool</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool bIsMutable = false;

    /**
    *  <p>Specifies whether a user pool attribute is required. If the attribute is required and the user does not provide a value, registration or sign-in will fail.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    bool required = false;

    /**
    *  <p>Specifies the constraints for an attribute of the number type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FNumberAttributeConstraintsType numberAttributeConstraints;

    /**
    *  <p>Specifies the constraints for an attribute of the string type.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FStringAttributeConstraintsType stringAttributeConstraints;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    Aws::CognitoIdentityProvider::Model::SchemaAttributeType toAWS() const {
        Aws::CognitoIdentityProvider::Model::SchemaAttributeType awsSchemaAttributeType;

        if (!(this->name.IsEmpty())) {
            awsSchemaAttributeType.SetName(TCHAR_TO_UTF8(*this->name));
        }

        switch(this->attributeDataType) {
            case EAttributeDataType::String:
                awsSchemaAttributeType.SetAttributeDataType(Aws::CognitoIdentityProvider::Model::AttributeDataType::String);
                break;
            case EAttributeDataType::Number:
                awsSchemaAttributeType.SetAttributeDataType(Aws::CognitoIdentityProvider::Model::AttributeDataType::Number);
                break;
            case EAttributeDataType::DateTime:
                awsSchemaAttributeType.SetAttributeDataType(Aws::CognitoIdentityProvider::Model::AttributeDataType::DateTime);
                break;
            case EAttributeDataType::Boolean:
                awsSchemaAttributeType.SetAttributeDataType(Aws::CognitoIdentityProvider::Model::AttributeDataType::Boolean);
                break;
            default:
                break;
        }

        if (!(false)) {
            awsSchemaAttributeType.SetDeveloperOnlyAttribute(this->developerOnlyAttribute);
        }

        if (!(false)) {
            awsSchemaAttributeType.SetMutable(this->bIsMutable);
        }

        if (!(false)) {
            awsSchemaAttributeType.SetRequired(this->required);
        }

        if (!(this->numberAttributeConstraints.IsEmpty())) {
            awsSchemaAttributeType.SetNumberAttributeConstraints(this->numberAttributeConstraints.toAWS());
        }

        if (!(this->stringAttributeConstraints.IsEmpty())) {
            awsSchemaAttributeType.SetStringAttributeConstraints(this->stringAttributeConstraints.toAWS());
        }

        return awsSchemaAttributeType;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->attributeDataType == EAttributeDataType::NOT_SET && false && false && false && this->numberAttributeConstraints.IsEmpty() && this->stringAttributeConstraints.IsEmpty();
    }

    FSchemaAttributeType &fromAWS(const Aws::CognitoIdentityProvider::Model::SchemaAttributeType &awsSchemaAttributeType) {
        this->name = UTF8_TO_TCHAR(awsSchemaAttributeType.GetName().c_str());

        switch(awsSchemaAttributeType.GetAttributeDataType()) {
            case Aws::CognitoIdentityProvider::Model::AttributeDataType::NOT_SET:
                this->attributeDataType = EAttributeDataType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::AttributeDataType::String:
                this->attributeDataType = EAttributeDataType::String;
                break;
            case Aws::CognitoIdentityProvider::Model::AttributeDataType::Number:
                this->attributeDataType = EAttributeDataType::Number;
                break;
            case Aws::CognitoIdentityProvider::Model::AttributeDataType::DateTime:
                this->attributeDataType = EAttributeDataType::DateTime;
                break;
            case Aws::CognitoIdentityProvider::Model::AttributeDataType::Boolean:
                this->attributeDataType = EAttributeDataType::Boolean;
                break;
            default:
                this->attributeDataType = EAttributeDataType::NOT_SET;
                break;
        }

        this->developerOnlyAttribute = awsSchemaAttributeType.GetDeveloperOnlyAttribute();

        this->bIsMutable = awsSchemaAttributeType.GetMutable();

        this->required = awsSchemaAttributeType.GetRequired();

        this->numberAttributeConstraints.fromAWS(awsSchemaAttributeType.GetNumberAttributeConstraints());

        this->stringAttributeConstraints.fromAWS(awsSchemaAttributeType.GetStringAttributeConstraints());

        return *this;
    }
#endif
};
