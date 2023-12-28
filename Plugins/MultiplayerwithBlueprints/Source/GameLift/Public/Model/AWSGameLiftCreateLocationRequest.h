/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE

#include "aws/gamelift/model/CreateLocationRequest.h"

#endif

#include "Model/GameLiftTag.h"

#include "AWSGameLiftCreateLocationRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSGameLiftCreateLocationRequest {
GENERATED_BODY()

    /**
    *  <p>A descriptive name for the custom location.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    FString locationName;

    /**
    *  <p>A list of labels to assign to the new matchmaking configuration resource. Tags are developer-defined key-value pairs. Tagging Amazon Web Services resources are useful for resource management, access management and cost allocation. For more information, see <a href="https://docs.aws.amazon.com/general/latest/gr/aws_tagging.html"> Tagging Amazon Web Services Resources</a> in the <i>Amazon Web Services General Rareference</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLift Client")
    TArray<FGameLiftTag> tags;

#if WITH_GAMELIFTCLIENTSDK && WITH_CORE
public:
    Aws::GameLift::Model::CreateLocationRequest toAWS() const {
        Aws::GameLift::Model::CreateLocationRequest awsCreateLocationRequest;

        if (!(this->locationName.IsEmpty())) {
            awsCreateLocationRequest.SetLocationName(TCHAR_TO_UTF8(*this->locationName));
        }

        for (const FGameLiftTag& elem : this->tags) {
            awsCreateLocationRequest.AddTags(elem.toAWS());
        }

        return awsCreateLocationRequest;
    }

    bool IsEmpty() const {
        return this->locationName.IsEmpty() && this->tags.Num() == 0;
    }
#endif
};
