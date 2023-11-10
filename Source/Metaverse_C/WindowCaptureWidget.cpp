// Copyright 2019 ayumax. All Rights Reserved.

#include "WindowCaptureWidget.h"
#include "Engine/Texture2D.h"
#include "Net/UnrealNetwork.h"
#include "Engine/NetDriver.h"
#include <Windows.h>
#define TRUE 1
#define FALSE 0

UWindowCaptureWidget::UWindowCaptureWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UWindowCaptureWidget::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UWindowCaptureWidget, Properties);
	DOREPLIFETIME(UWindowCaptureWidget, TextureTarget);
}

void UWindowCaptureWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	FlushRenderingCommands();

	if (CaptureMachine)
	{
		CaptureMachine->Stop();
	}

	Super::ReleaseSlateResources(bReleaseChildren);
}


void UWindowCaptureWidget::BeginDestroy()
{
	Super::BeginDestroy();

	if (CaptureMachine)
	{
		CaptureMachine->Dispose();
		CaptureMachine = nullptr;
	}
}


UTexture2D* UWindowCaptureWidget::Start()
{
	if (CaptureMachine)
	{
		CaptureMachine->Stop();
		CaptureMachine->Dispose();
	}

	CaptureMachine = NewObject<UCaptureMachine>(this);

	CaptureMachine->Properties = Properties;

	CaptureMachine->ChangeTexture.AddDynamic(this, &UWindowCaptureWidget::Server_ChangeTexture);
	CaptureMachine->Start();


	return CaptureMachine->CreateTexture();
}

void UWindowCaptureWidget::Stop()
{
	if (CaptureMachine)
	{
		CaptureMachine->Stop();
		CaptureMachine->Dispose();
	}
}

void UWindowCaptureWidget::StartCapture()
{
	if (CaptureMachine)
	{
		CaptureMachine->Stop();
		CaptureMachine->Dispose();
	}

	CaptureMachine = NewObject<UCaptureMachine>(this);
	CaptureMachine->Properties = Properties;

	CaptureMachine->ChangeTexture.AddDynamic(this, &UWindowCaptureWidget::OnChangeTexture);
	CaptureMachine->Start();

	// Notify the UI that the capture has started
	ChangeTexture.Broadcast(nullptr);
}

void UWindowCaptureWidget::SelectWindow(int32 Index)
{
	if (CaptureMachine && Index >= 0 && Index < AvailableWindows.Num())
	{
		// Set the selected window title in CaptureMachine
		CaptureMachine->Properties.CaptureTargetTitle = AvailableWindows[Index];
	}
}

TArray<FString> UWindowCaptureWidget::GetAvailableWindows()
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

void UWindowCaptureWidget::OnChangeTexture(UTexture2D* _NewTexture)
{
	ChangeTexture.Broadcast(_NewTexture);
}

void UWindowCaptureWidget::Server_ChangeTexture_Implementation(UTexture2D* NewTexture)
{
	OnChangeTexture(NewTexture);
	ChangeTexture.Broadcast(NewTexture);
}

bool UWindowCaptureWidget::Server_ChangeTexture_Validate(UTexture2D* NewTexture)
{
	return true;
}