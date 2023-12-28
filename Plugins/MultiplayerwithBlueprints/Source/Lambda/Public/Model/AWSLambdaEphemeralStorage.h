/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/EphemeralStorage.h"

#endif

#include "AWSLambdaEphemeralStorage.generated.h"

USTRUCT(BlueprintType)
struct FAWSLambdaEphemeralStorage {
GENERATED_BODY()

    /**
    *  <p>The size of the function's <code>/tmp</code> directory.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    int size = 0;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::EphemeralStorage toAWS() const {
        Aws::Lambda::Model::EphemeralStorage awsEphemeralStorage;

        if (!(this->size == 0)) {
            awsEphemeralStorage.SetSize(this->size);
        }

        return awsEphemeralStorage;
    }

    bool IsEmpty() const {
        return this->size == 0;
    }

    FAWSLambdaEphemeralStorage &fromAWS(const Aws::Lambda::Model::EphemeralStorage &awsEphemeralStorage) {
		this->size = awsEphemeralStorage.GetSize();

        return *this;
    }
#endif
};
