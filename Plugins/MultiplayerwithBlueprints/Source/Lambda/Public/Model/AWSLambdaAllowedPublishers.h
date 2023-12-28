/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/AllowedPublishers.h"

#endif

#include "AWSLambdaAllowedPublishers.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaAllowedPublishers {
GENERATED_BODY()

    /**
    *  <p>The Amazon Resource Name (ARN) for each of the signing profiles. A signing profile defines a trusted user who can sign a code package. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FString> signingProfileVersionArns;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::AllowedPublishers toAWS() const {
        Aws::Lambda::Model::AllowedPublishers awsAllowedPublishers;

        for (const FString& elem : this->signingProfileVersionArns) {
            awsAllowedPublishers.AddSigningProfileVersionArns(TCHAR_TO_UTF8(*elem));
        }
        return awsAllowedPublishers;
    }

    bool IsEmpty() const {
        return this->signingProfileVersionArns.Num() == 0;
    }

    FAWSLambdaAllowedPublishers &fromAWS(const Aws::Lambda::Model::AllowedPublishers &awsAllowedPublishers) {
        this->signingProfileVersionArns.Empty();
        for (const Aws::String& elem : awsAllowedPublishers.GetSigningProfileVersionArns()) {
            this->signingProfileVersionArns.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        return *this;
    }
#endif
};
