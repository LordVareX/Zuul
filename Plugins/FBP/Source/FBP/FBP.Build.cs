// Copyright (c) 2022 King Wai Mark

using UnrealBuildTool;
using System.IO;


public class FBP : ModuleRules
{
	
	
	public FBP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				Path.Combine(ModuleDirectory, "Public")
			}
		);
			
		
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Json", 
				"JsonUtilities",
				"XmlParser"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

		//AddWin32Libs(Target);
		AddWin64Libs(Target);
		AddAndroidLibs(Target);
		AddMacOSLibs(Target);
		AddIOSLibs(Target);
		
	}

	private void AddWin64Libs(ReadOnlyTargetRules Target)
	{
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{

	        PublicIncludePaths.AddRange(
	            new string[] {
	                Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "windows", "x64",
				"Release", "include")
	            }
	        );

			PublicSystemLibraries.Add("advapi32.lib");
			PublicSystemLibraries.Add("ws2_32.lib");
			PublicSystemLibraries.Add("crypt32.lib");
			PublicSystemLibraries.Add("rpcrt4.lib");
			PublicSystemLibraries.Add("ole32.lib");
			PublicSystemLibraries.Add("shell32.lib");
			PublicSystemLibraries.Add("iphlpapi.lib");
			PublicSystemLibraries.Add("psapi.lib");
			PublicSystemLibraries.Add("userenv.lib");

			var LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "windows", "x64",
				"Release");
			PublicAdditionalLibraries.AddRange(
	            new string[]
	            {
	                Path.Combine(LibPath, "firebase_admob.lib"),
	                Path.Combine(LibPath, "firebase_analytics.lib"),
	                Path.Combine(LibPath, "firebase_app.lib"),
	                Path.Combine(LibPath, "firebase_auth.lib"),
	                Path.Combine(LibPath, "firebase_database.lib"),
	                Path.Combine(LibPath, "firebase_dynamic_links.lib"),
	                Path.Combine(LibPath, "firebase_firestore.lib"),
	                Path.Combine(LibPath, "firebase_functions.lib"),
	                Path.Combine(LibPath, "firebase_installations.lib"),
	                Path.Combine(LibPath, "firebase_messaging.lib"),
	                Path.Combine(LibPath, "firebase_remote_config.lib"),
	                Path.Combine(LibPath, "firebase_storage.lib")
			});
			System.Console.WriteLine("Copying Google Services File...");
			if (Target.ProjectFile  != null && File.Exists(Path.Combine(Target.ProjectFile.FullName, "..", "google-services.json")))
			{
				RuntimeDependencies.Add("$(TargetOutputDir)/google-services-desktop.json", "$(ProjectDir)/google-services.json");
				RuntimeDependencies.Add("$(TargetOutputDir)/google-services.json", "$(ProjectDir)/google-services.json");
			}
			
		}
	}
	
	private void AddAndroidLibs(ReadOnlyTargetRules Target)
	{
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
	        // Needed for JNI
			PublicDependencyModuleNames.Add("Launch");

			 PublicIncludePaths.AddRange(
	            new string[] {
	                Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "android", "include")
	            }
	        );
			
			var arch = "armeabi-v7a";
			var LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "android", arch, "c++");
			PublicAdditionalLibraries.AddRange(
			new string[]
			{
					Path.Combine(LibPath, "libfirebase_analytics.a"),
					Path.Combine(LibPath, "libfirebase_app.a"),
					Path.Combine(LibPath, "libfirebase_auth.a"),
					Path.Combine(LibPath, "libfirebase_database.a"),
					Path.Combine(LibPath, "libfirebase_firestore.a"),
					Path.Combine(LibPath, "libfirebase_storage.a")
			});

			arch = "arm64-v8a";
			LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "android", arch, "c++");
			PublicAdditionalLibraries.AddRange(
			new string[]
			{
					Path.Combine(LibPath, "libfirebase_analytics.a"),
					Path.Combine(LibPath, "libfirebase_app.a"),
					Path.Combine(LibPath, "libfirebase_auth.a"),
					Path.Combine(LibPath, "libfirebase_database.a"),
					Path.Combine(LibPath, "libfirebase_firestore.a"),
					Path.Combine(LibPath, "libfirebase_storage.a")
			});

			arch = "armeabi";
			LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "android", arch, "c++");
			PublicAdditionalLibraries.AddRange(
			new string[]
			{
					Path.Combine(LibPath, "libfirebase_analytics.a"),
					Path.Combine(LibPath, "libfirebase_app.a"),
					Path.Combine(LibPath, "libfirebase_auth.a"),
					Path.Combine(LibPath, "libfirebase_database.a"),
					Path.Combine(LibPath, "libfirebase_firestore.a"),
					Path.Combine(LibPath, "libfirebase_storage.a")
			});

			arch = "mips";
			LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "android", arch, "c++");
			PublicAdditionalLibraries.AddRange(
			new string[]
			{
					Path.Combine(LibPath, "libfirebase_analytics.a"),
					Path.Combine(LibPath, "libfirebase_app.a"),
					Path.Combine(LibPath, "libfirebase_auth.a"),
					Path.Combine(LibPath, "libfirebase_database.a"),
					Path.Combine(LibPath, "libfirebase_firestore.a"),
					Path.Combine(LibPath, "libfirebase_storage.a")
			});

			arch = "mips64";
			LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "android", arch, "c++");
			PublicAdditionalLibraries.AddRange(
			new string[]
			{
					Path.Combine(LibPath, "libfirebase_analytics.a"),
					Path.Combine(LibPath, "libfirebase_app.a"),
					Path.Combine(LibPath, "libfirebase_auth.a"),
					Path.Combine(LibPath, "libfirebase_database.a"),
					Path.Combine(LibPath, "libfirebase_firestore.a"),
					Path.Combine(LibPath, "libfirebase_storage.a")
			});

			arch = "x86";
			LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "android", arch, "c++");
			PublicAdditionalLibraries.AddRange(
			new string[]
			{
					Path.Combine(LibPath, "libfirebase_analytics.a"),
					Path.Combine(LibPath, "libfirebase_app.a"),
					Path.Combine(LibPath, "libfirebase_auth.a"),
					Path.Combine(LibPath, "libfirebase_database.a"),
					Path.Combine(LibPath, "libfirebase_firestore.a"),
					Path.Combine(LibPath, "libfirebase_storage.a")
			});

			arch = "x86_64";
			LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "android", arch, "c++");
			PublicAdditionalLibraries.AddRange(
			new string[]
			{
					Path.Combine(LibPath, "libfirebase_analytics.a"),
					Path.Combine(LibPath, "libfirebase_app.a"),
					Path.Combine(LibPath, "libfirebase_auth.a"),
					Path.Combine(LibPath, "libfirebase_database.a"),
					Path.Combine(LibPath, "libfirebase_firestore.a"),
					Path.Combine(LibPath, "libfirebase_storage.a")
			});
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(ModuleDirectory, "FBPluginAndroid_UPL.xml"));
			PublicDefinitions.Add("HAS_GOOGLE_SERVICES_FILE");

			

			


			
		}
	}
	
	private void AddMacOSLibs(ReadOnlyTargetRules Target)
	{
		if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "mac", "include")
				}
			);
			// Add the necessary OSX Frameworks
			PublicFrameworks.AddRange (
				new string[]
				{
					"CoreFoundation",
					"Foundation",
					"Security",
					"GSS",
					"SystemConfiguration",
					"Kerberos"
				}
			);
	
			PublicSystemLibraries.Add("gssapi_krb5");
			PublicSystemLibraries.Add("pthread");
			var LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "mac", "universal");

			// Add the lib files to use for the SDK
			PublicAdditionalLibraries.AddRange(
				new string[]
				{
					Path.Combine(LibPath, "libfirebase_admob.a"),
					Path.Combine(LibPath, "libfirebase_analytics.a"),
					Path.Combine(LibPath, "libfirebase_app.a"),
					Path.Combine(LibPath, "libfirebase_auth.a"),
					Path.Combine(LibPath, "libfirebase_database.a"),
					Path.Combine(LibPath, "libfirebase_dynamic_links.a"),
					Path.Combine(LibPath, "libfirebase_firestore.a"),
					Path.Combine(LibPath, "libfirebase_functions.a"),
					Path.Combine(LibPath, "libfirebase_installations.a"),
					Path.Combine(LibPath, "libfirebase_messaging.a"),
					Path.Combine(LibPath, "libfirebase_remote_config.a"),
					Path.Combine(LibPath, "libfirebase_storage.a")
				});
			if (Target.ProjectFile  != null && File.Exists(Path.Combine(Path.GetDirectoryName(Target.ProjectFile.FullName), "GoogleService-Info.plist")))
			{
				// Place the Google Services Json file to the correct place
				RuntimeDependencies.Add("$(TargetOutputDir)/GoogleService-Info.plist", "$(ProjectDir)/GoogleService-Info.plist");
				RuntimeDependencies.Add("$(ProjectDir)/GoogleService-Info.plist", StagedFileType.UFS);
			}
		}
	}
	private void AddIOSLibs(ReadOnlyTargetRules Target)
	{
		if (Target.Platform == UnrealTargetPlatform.IOS)
		{
		    PublicIncludePaths.AddRange(
				new string[] {
					Path.Combine(ModuleDirectory, "..", "ThirdParty/firebase_cpp_sdk/libs/ios"),
					Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "ios", "include")
				}
			);
			if (Target.ProjectFile  != null && File.Exists(Path.Combine(Path.GetDirectoryName(Target.ProjectFile.FullName), "GoogleService-Info.plist")))
			{
				RuntimeDependencies.Add("$(ProjectDir)/GoogleService-Info.plist", StagedFileType.UFS);

			}

			PublicFrameworks.AddRange(
				new[]
				{
				"LocalAuthentication",
				"SafariServices",
				"AuthenticationServices",
				"SystemConfiguration",
				"UserNotifications"
				}
			);
			
			// Bundle Resources
			AdditionalBundleResources.Add(new BundleResource(Path.Combine(ModuleDirectory, "ThirdParty", "firebase_cpp_sdk", "libs", "ios", "Resources", "gRPCCertificates-Cpp.bundle")));

			var LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "ios", "universal");

			// Add the lib files to use for the SDK
			PublicAdditionalLibraries.AddRange(
			new string[]
			{
				Path.Combine(LibPath, "libfirebase_analytics.a"),
				Path.Combine(LibPath, "libfirebase_app.a"),
				Path.Combine(LibPath, "libfirebase_auth.a"),
				Path.Combine(LibPath, "libfirebase_database.a"),
				Path.Combine(LibPath, "libfirebase_firestore.a"),
				Path.Combine(LibPath, "libfirebase_installations.a"),
				Path.Combine(LibPath, "libfirebase_storage.a")
			});

			LibPath = Path.Combine(ModuleDirectory, "..", "ThirdParty", "firebase_cpp_sdk", "libs", "ios");
			// Firebase SDK Framework
			PublicAdditionalFrameworks.Add(new Framework("FirebaseAnalytics", Path.Combine(LibPath, "FirebaseAnalytics.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("FirebaseCore", Path.Combine(LibPath, "FirebaseCore.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("FirebaseCoreDiagnostics", Path.Combine(LibPath, "FirebaseCoreDiagnostics.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("FirebaseInstallations", Path.Combine(LibPath, "FirebaseInstallations.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("GoogleAppMeasurement", Path.Combine(LibPath, "GoogleAppMeasurement.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("GoogleAppMeasurementIdentitySupport", Path.Combine(LibPath, "GoogleAppMeasurementIdentitySupport.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("GoogleDataTransport", Path.Combine(LibPath, "GoogleDataTransport.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("GoogleUtilities", Path.Combine(LibPath, "GoogleUtilities.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("nanopb", Path.Combine(LibPath, "nanopb.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("PromisesObjC", Path.Combine(LibPath, "PromisesObjC.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("FirebaseDatabase", Path.Combine(LibPath, "FirebaseDatabase.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("leveldb-library", Path.Combine(LibPath, "leveldb-library.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("abseil", Path.Combine(LibPath, "abseil.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("BoringSSL-GRPC", Path.Combine(LibPath, "BoringSSL-GRPC.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("gRPC-C++", Path.Combine(LibPath, "gRPC-C++.framework.zip"), "Resources/gRPCCertificates-Cpp.bundle"));
			PublicAdditionalFrameworks.Add(new Framework("gRPC-Core", Path.Combine(LibPath, "gRPC-Core.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("Libuv-gRPC", Path.Combine(LibPath, "Libuv-gRPC.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("FirebaseFirestore", Path.Combine(LibPath, "FirebaseFirestore.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("FirebaseStorage", Path.Combine(LibPath, "FirebaseStorage.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("FirebaseAuth", Path.Combine(LibPath, "FirebaseAuth.framework.zip")));
			PublicAdditionalFrameworks.Add(new Framework("GTMSessionFetcher", Path.Combine(LibPath, "GTMSessionFetcher.framework.zip")));


			PublicDependencyModuleNames.AddRange(new[] { "Launch" });
      		PrivateDependencyModuleNames.AddRange(new[] { "Launch" });

		}
	}
}
