/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/AddPermissionResult.h"

#endif

#include "AddPermissionResult.generated.h"

USTRUCT(BlueprintType)
struct FAddPermissionResult {
GENERATED_BODY()

    /**
    *  <p>The permission statement that's added to the function policy.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString statement;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FAddPermissionResult &fromAWS(const Aws::Lambda::Model::AddPermissionResult &awsAddPermissionResult) {
        this->statement = UTF8_TO_TCHAR(awsAddPermissionResult.GetStatement().c_str());

        return *this;
    }
#endif
};
