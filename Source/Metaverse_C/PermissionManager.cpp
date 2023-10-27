// Fill out your copyright notice in the Description page of Project Settings.


//#include "PermissionManager.h"
//
//#if PLATFORM_IOS
//#import "PermissionManagerOC.h"
//#endif
//
//UPermissionManager::UPermissionManager()
//{
//    // Default constructor
//}
//
//void UPermissionManager::RequestCameraAndMicrophonePermissions(bool& CameraPermissionGranted, bool& MicrophonePermissionGranted)
//{
//#if PLATFORM_IOS
//    ObjectiveCWrapper::requestCameraAndMicrophonePermissions([&](BOOL cameraGranted, BOOL microphoneGranted) {
//        CameraPermissionGranted = cameraGranted;
//        MicrophonePermissionGranted = microphoneGranted;
//});
//#else
//    // Provide a message for non-iOS platforms or handle differently as needed.
//    CameraPermissionGranted = false;
//    MicrophonePermissionGranted = false;
//#endif
//}