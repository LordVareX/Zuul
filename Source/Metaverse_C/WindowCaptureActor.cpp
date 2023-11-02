

#include "WindowCaptureActor.h"
#include "Engine/Texture2D.h"
#include "Net/UnrealNetwork.h"
#include "Materials/MaterialInstanceDynamic.h"


AWindowCaptureActor::AWindowCaptureActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = SceneComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
}

void AWindowCaptureActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (CaptureMachine)
	{
		CaptureMachine->Stop();
	}

	Super::EndPlay(EndPlayReason);
}

void AWindowCaptureActor::BeginDestroy()
{
	Super::BeginDestroy();

	if (CaptureMachine)
	{
		CaptureMachine->Dispose();
		CaptureMachine = nullptr;
	}
}

UTexture2D* AWindowCaptureActor::Start()
{
	if (CaptureMachine)
	{
		CaptureMachine->Stop();
		CaptureMachine->Dispose();
	}

	CaptureMachine = NewObject<UCaptureMachine>(this);

	CaptureMachine->Properties = Properties;

	CaptureMachine->ChangeTexture.AddDynamic(this, &AWindowCaptureActor::OnChangeTexture);
	CaptureMachine->Start();

	return CaptureMachine->CreateTexture();
}

void AWindowCaptureActor::Stop()
{
	if (CaptureMachine)
	{
		CaptureMachine->Stop();
		CaptureMachine->Dispose();
	}
}


void AWindowCaptureActor::OnChangeTexture(UTexture2D* _NewTexture)
{
	ChangeTexture.Broadcast(_NewTexture);

	if (HasAuthority()) // Only on the server
	{
		TextureTarget = _NewTexture;
		TextureTarget->SetFlags(RF_Public); // Ensure the texture is marked as public

		// Replicate the change to clients
		OnRep_TextureTarget();
	}
}

void AWindowCaptureActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWindowCaptureActor, Properties);
	DOREPLIFETIME(AWindowCaptureActor, TextureTarget);
}

void AWindowCaptureActor::OnRep_TextureTarget()
{
	// Handle the TextureTarget change event here, and update the dynamic material instance as mentioned in the previous response
	if (TextureTarget)
	{
		UMaterialInstanceDynamic* DynamicMaterialInstance = UMaterialInstanceDynamic::Create(MeshComponent->GetMaterial(0), this);
		MeshComponent->SetMaterial(0, DynamicMaterialInstance);
		// Update the dynamic material instance on the mesh with the new texture
		DynamicMaterialInstance->SetTextureParameterValue("Tex", TextureTarget);
	}
}