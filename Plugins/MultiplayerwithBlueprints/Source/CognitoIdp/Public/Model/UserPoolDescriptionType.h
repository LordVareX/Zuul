/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE

#include "aws/cognito-idp/model/UserPoolDescriptionType.h"

#endif

#include "Model/LambdaConfigType.h"
#include "Model/StatusType.h"

#include "UserPoolDescriptionType.generated.h"

USTRUCT(BlueprintType)
struct FUserPoolDescriptionType {
GENERATED_BODY()

    /**
    *  <p>The ID in a user pool description.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString id;

    /**
    *  <p>The name in a user pool description.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FString name;

    /**
    *  <p>The AWS Lambda configuration information in a user pool description.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FLambdaConfigType lambdaConfig;

    /**
    *  <p>The user pool status in a user pool description.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    EStatusType status = EStatusType::NOT_SET;

    /**
    *  <p>The date the user pool description was last modified.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime lastModifiedDate;

    /**
    *  <p>The date the user pool description was created.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CognitoIdentityProvider Client")
    FDateTime creationDate;

#if WITH_COGNITOIDPCLIENTSDK && WITH_CORE
public:
    FUserPoolDescriptionType &fromAWS(const Aws::CognitoIdentityProvider::Model::UserPoolDescriptionType &awsUserPoolDescriptionType) {
        this->id = UTF8_TO_TCHAR(awsUserPoolDescriptionType.GetId().c_str());

        this->name = UTF8_TO_TCHAR(awsUserPoolDescriptionType.GetName().c_str());

        this->lambdaConfig.fromAWS(awsUserPoolDescriptionType.GetLambdaConfig());

        switch(awsUserPoolDescriptionType.GetStatus()) {
            case Aws::CognitoIdentityProvider::Model::StatusType::NOT_SET:
                this->status = EStatusType::NOT_SET;
                break;
            case Aws::CognitoIdentityProvider::Model::StatusType::Enabled:
                this->status = EStatusType::Enabled;
                break;
            case Aws::CognitoIdentityProvider::Model::StatusType::Disabled:
                this->status = EStatusType::Disabled;
                break;
            default:
                this->status = EStatusType::NOT_SET;
                break;
        }

        this->lastModifiedDate = FDateTime(1970, 1, 1) + FTimespan(awsUserPoolDescriptionType.GetLastModifiedDate().Millis() * ETimespan::TicksPerMillisecond);

        this->creationDate = FDateTime(1970, 1, 1) + FTimespan(awsUserPoolDescriptionType.GetCreationDate().Millis() * ETimespan::TicksPerMillisecond);

        return *this;
    }
#endif
};
