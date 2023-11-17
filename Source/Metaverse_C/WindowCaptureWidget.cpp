// Copyright 2019 ayumax. All Rights Reserved.

#include "WindowCaptureWidget.h"
#include "Engine/Texture2D.h"
#include "Net/UnrealNetwork.h"
#include "Engine/NetDriver.h"
#include <Windows.h>
#define TRUE 1
#define FALSE 0
#include <Psapi.h>
#pragma comment(lib, "Psapi.lib")

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

//TArray<FString> UWindowCaptureWidget::GetAvailableWindows()
//{
//	AvailableWindows.Empty(); // Clear the existing window list
//
//	// Callback function to receive window titles
//	auto EnumWindowsProc = [](HWND hwnd, LPARAM lParam) -> BOOL {
//		TCHAR title[256];
//		GetWindowText(hwnd, title, ARRAYSIZE(title));
//		FString windowTitle = title;
//		if (!windowTitle.IsEmpty()) {
//			// Add the window title to the AvailableWindows array
//			((TArray<FString>*)lParam)->Add(windowTitle);
//		}
//		return TRUE;
//		};
//
//	// Enumerate all open windows and collect their titles
//	if (EnumWindows(EnumWindowsProc, (LPARAM)&AvailableWindows)) {
//		return AvailableWindows;
//	}
//
//	return AvailableWindows; // Return the list of window titles
//
//}

//BOOL CALLBACK EnumWindowsCallback(HWND hwnd, LPARAM lParam) {
//	auto* windowList = reinterpret_cast<TArray<FString>*>(lParam);
//	if (windowList != nullptr) {
//		TCHAR title[256];
//		GetWindowText(hwnd, title, ARRAYSIZE(title));
//		FString windowTitle = title;
//
//		if (!windowTitle.IsEmpty() && IsWindowVisible(hwnd)) {
//			windowList->Add(windowTitle);
//		}
//	}
//	return TRUE;
//}
//
//TArray<FString> UWindowCaptureWidget::GetAvailableWindows()
//{
//	AvailableWindows.Empty(); // Clear the existing window list
//
//	// Enumerate all open windows and collect their titles
//	if (!EnumWindows(&EnumWindowsCallback, reinterpret_cast<LPARAM>(&AvailableWindows))) {
//		// Handle enumeration failure here if necessary
//	}
//
//	return AvailableWindows; // Return the list of window titles
//}

//TArray<FString> UWindowCaptureWidget::GetAvailableWindows()
//{
//	AvailableWindows.Empty(); // Clear the existing window list
//
//	// Callback function to receive window titles
//	auto EnumWindowsProc = [](HWND hwnd, LPARAM lParam) -> BOOL {
//		auto* windowList = reinterpret_cast<TArray<FString>*>(lParam);
//		if (windowList != nullptr) {
//			TCHAR title[256];
//			GetWindowText(hwnd, title, ARRAYSIZE(title));
//			FString windowTitle = title;
//
//			if (!windowTitle.IsEmpty() && IsWindowVisible(hwnd)) {
//				DWORD processId;
//				GetWindowThreadProcessId(hwnd, &processId);
//				HANDLE processHandle = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);
//				if (processHandle != NULL) {
//					TCHAR executablePath[MAX_PATH];
//					if (GetModuleFileNameEx(processHandle, NULL, executablePath, MAX_PATH) > 0) {
//						FString appName = executablePath;
//						// Extract the app name from the path
//						int32 LastIndex;
//						if (appName.FindLastChar('\\', LastIndex)) {
//							appName = appName.RightChop(LastIndex + 1);
//						}
//						windowList->Add(appName);
//					}
//					CloseHandle(processHandle);
//				}
//			}
//		}
//		return TRUE;
//		};
//
//	// Enumerate all open windows and collect their titles
//	if (!EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&AvailableWindows))) {
//		// Handle enumeration failure here if necessary
//	}
//
//	return AvailableWindows; // Return the list of application names
//}

TArray<FString> UWindowCaptureWidget::GetAvailableWindows()
{
	AvailableWindows.Empty(); // Clear the existing window list

	// Callback function to receive window titles
	auto EnumWindowsProc = [](HWND hwnd, LPARAM lParam) -> BOOL {
		if (IsWindowVisible(hwnd) && GetAncestor(hwnd, GA_ROOT) == hwnd) {
			TCHAR title[256];
			GetWindowText(hwnd, title, ARRAYSIZE(title));
			FString windowTitle = title;

			if (!windowTitle.IsEmpty()) {
				((TArray<FString>*)lParam)->Add(windowTitle);
			}
		}
		return TRUE;
		};

	// Enumerate all open windows and collect their titles
	EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&AvailableWindows));

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