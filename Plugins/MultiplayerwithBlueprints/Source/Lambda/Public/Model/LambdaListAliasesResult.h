/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/ListAliasesResult.h"

#endif

#include "Model/AliasConfiguration.h"

#include "LambdaListAliasesResult.generated.h"

USTRUCT(BlueprintType)
struct FLambdaListAliasesResult {
GENERATED_BODY()

    /**
    *  <p>The pagination token that's included if more results are available.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString nextMarker;

    /**
    *  <p>A list of aliases.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    TArray<FAliasConfiguration> aliases;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    FLambdaListAliasesResult &fromAWS(const Aws::Lambda::Model::ListAliasesResult &awsListAliasesResult) {
        this->nextMarker = UTF8_TO_TCHAR(awsListAliasesResult.GetNextMarker().c_str());

        this->aliases.Empty();
        for (const Aws::Lambda::Model::AliasConfiguration& elem : awsListAliasesResult.GetAliases()) {
            this->aliases.Add(FAliasConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
