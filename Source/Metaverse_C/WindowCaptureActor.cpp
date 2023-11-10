

#include "WindowCaptureActor.h"
#include "Engine/Texture2D.h"
#include "Net/UnrealNetwork.h"
#include "Materials/MaterialInstanceDynamic.h"
#include <Windows.h>
#define TRUE 1
#define FALSE 0

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

void AWindowCaptureActor::SelectWindow(int32 Index)
{
	if (CaptureMachine && Index >= 0 && Index < AvailableWindows.Num())
	{
		// Set the selected window title in CaptureMachine
		CaptureMachine->Properties.CaptureTargetTitle = AvailableWindows[Index];
	}
}

TArray<FString> AWindowCaptureActor::GetAvailableWindows()
{
	AvailableWindows.Empty(); // Clear the existing window list

	// Callback function to receive window titles
	auto EnumWindowsProc = [](HWND hwnd, LPARAM lParam) -> BOOL {
		TCHAR title[256];
		GetWindowText(hwnd, title, ARRAYSIZE(title));
		FString windowTitle = title;
		if (!windowTitle.IsEmpty()) {
			// Add the window title to the AvailableWindows array
			((TArray<FString>*)lParam)->Add(windowTitle);
		}
		return TRUE;
		};

	// Enumerate all open windows and collect their titles
	if (EnumWindows(EnumWindowsProc, (LPARAM)&AvailableWindows)) {
		return AvailableWindows;
	}

	return AvailableWindows; // Return the list of window titles

}