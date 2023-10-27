// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PermissionManagerPC.generated.h"

/**
 * 
 */
UCLASS()
class METAVERSE_C_API APermissionManagerPC : public APlayerController
{
	GENERATED_BODY()

public:
    // Function to request camera permission
    UFUNCTION(BlueprintCallable, Category = "Permissions")
    static void RequestCameraPermission();

    // Function to request microphone permission
    UFUNCTION(BlueprintCallable, Category = "Permissions")
    static void RequestMicrophonePermission();
	
};
