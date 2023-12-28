/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/DeleteEventSourceMappingRequest.h"

#endif

#include "DeleteEventSourceMappingRequest.generated.h"

USTRUCT(BlueprintType)
struct FDeleteEventSourceMappingRequest {
GENERATED_BODY()

    /**
    *  <p>The identifier of the event source mapping.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString UUID;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::DeleteEventSourceMappingRequest toAWS() const {
        Aws::Lambda::Model::DeleteEventSourceMappingRequest awsDeleteEventSourceMappingRequest;

		if (!(this->UUID.IsEmpty())) {
            awsDeleteEventSourceMappingRequest.SetUUID(TCHAR_TO_UTF8(*this->UUID));
        }

        return awsDeleteEventSourceMappingRequest;
    }

    bool IsEmpty() const {
        return this->UUID.IsEmpty();
    }
#endif
};
