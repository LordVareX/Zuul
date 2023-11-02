// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CaptureMachineProperties.h"
#include "CaptureMachine.h"
#include "WindowCaptureActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWindowCaptureActorChangeTexture, UTexture2D*, NewTexture);

UCLASS(BlueprintType, Blueprintable)
class METAVERSE_C_API AWindowCaptureActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWindowCaptureActor();

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

protected:
	UFUNCTION(BlueprintCallable, Category = WindowCapture2D)
	UTexture2D* Start();

	UFUNCTION(BlueprintCallable, Category = WindowCapture2D)
	void Stop();

	UFUNCTION()
	void OnChangeTexture(UTexture2D* NewTexture);

public:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void BeginDestroy() override;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = WindowCapture2D)
	FCaptureMachineProperties Properties;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = SceneCapture)
	class UTexture2D* TextureTarget;

	UPROPERTY(BlueprintAssignable, Category = SceneCapture)
	FWindowCaptureActorChangeTexture ChangeTexture;

	UFUNCTION()
	void OnRep_TextureTarget(); // Replication function

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;

protected:
	UPROPERTY(Transient)
	UCaptureMachine* CaptureMachine = nullptr;


};
