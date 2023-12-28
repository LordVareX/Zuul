/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, October 2019
*/

#pragma once

#include "CoreMinimal.h"

#include "Runtime.generated.h"

UENUM(BlueprintType)
enum class EAWSRuntime : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    nodejs        UMETA(DisplayName = "nodejs"),
    nodejs4_3        UMETA(DisplayName = "nodejs4.3"),
    nodejs6_10        UMETA(DisplayName = "nodejs6.10"),
    nodejs8_10        UMETA(DisplayName = "nodejs8.10"),
    nodejs10_x        UMETA(DisplayName = "nodejs10.x"),
    nodejs12_x        UMETA(DisplayName = "nodejs12.x"),
    nodejs14_x        UMETA(DisplayName = "nodejs14.x"),
    nodejs16_x        UMETA(DisplayName = "nodejs16.x"),
    java8        UMETA(DisplayName = "java8"),
    java8_al2        UMETA(DisplayName = "java8 al2"),
    java11        UMETA(DisplayName = "java11"),
    python2_7        UMETA(DisplayName = "python2.7"),
    python3_6        UMETA(DisplayName = "python3.6"),
    python3_7        UMETA(DisplayName = "python3.7"),
    python3_8        UMETA(DisplayName = "python3.8"),
    python3_9        UMETA(DisplayName = "python3.9"),
    dotnetcore1_0        UMETA(DisplayName = "dotnetcore1.0"),
    dotnetcore2_0        UMETA(DisplayName = "dotnetcore2.0"),
    dotnetcore2_1        UMETA(DisplayName = "dotnetcore2.1"),
    dotnetcore3_1        UMETA(DisplayName = "dotnetcore3.1"),
    dotnet6        UMETA(DisplayName = "dotnet6"),
    nodejs4_3_edge        UMETA(DisplayName = "nodejs4.3-edge"),
    go1_x        UMETA(DisplayName = "go1.x"),
    ruby2_5        UMETA(DisplayName = "ruby2.5"),
    ruby2_7        UMETA(DisplayName = "ruby2.7"),
    provided        UMETA(DisplayName = "provided"),
    provided_al2        UMETA(DisplayName = "provided al2"),
    nodejs18_x        UMETA(DisplayName = "nodejs18.x"),
};
