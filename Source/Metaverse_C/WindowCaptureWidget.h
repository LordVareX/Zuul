// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CaptureMachineProperties.h"
#include "CaptureMachine.h"
#include "WindowCaptureWidget.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWindowCaptureWidgetChangeTexture, UTexture2D*, NewTexture);

UCLASS(BlueprintType, Blueprintable)
class METAVERSE_C_API UWindowCaptureWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UWindowCaptureWidget(const FObjectInitializer& ObjectInitializer);

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Category = WindowCapture2D)
	void StartCapture();

	UFUNCTION(BlueprintCallable, Category = WindowCapture2D)
	void SelectWindow(int32 Index);

	UFUNCTION(BlueprintPure, Category = WindowCapture2D)
	TArray<FString> GetAvailableWindows();

	UFUNCTION(Server, Reliable)
	void Server_ChangeTexture(UTexture2D* NewTexture);
	void Server_ChangeTexture_Implementation(UTexture2D* NewTexture);
	bool Server_ChangeTexture_Validate(UTexture2D* NewTexture);

protected:
	UFUNCTION(BlueprintCallable, Category = WindowCapture2D)
	UTexture2D* Start();

	UFUNCTION(BlueprintCallable, Category = WindowCapture2D)
	void Stop();

	UFUNCTION()
	void OnChangeTexture(UTexture2D* NewTexture);

public:
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	virtual void BeginDestroy() override;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = WindowCapture2D)
	FCaptureMachineProperties Properties;

	UPROPERTY(Replicated, BlueprintReadWrite, Category = SceneCapture)
	class UTexture2D* TextureTarget;

	UPROPERTY(BlueprintAssignable, Category = SceneCapture)
	FWindowCaptureWidgetChangeTexture ChangeTexture;

protected:
	UPROPERTY(Transient)
	UCaptureMachine* CaptureMachine = nullptr;

	TArray<FString> AvailableWindows;
	
};
