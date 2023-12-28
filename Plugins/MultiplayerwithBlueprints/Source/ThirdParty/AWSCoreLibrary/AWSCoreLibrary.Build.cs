/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

using UnrealBuildTool;
using System.IO;

public class AWSCoreLibrary : ModuleRules
{
    public AWSCoreLibrary(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        PublicDefinitions.Add("AWS_DEEP_CHECKS=1");
        PublicDefinitions.Add("AWS_USE_IO_COMPLETION_PORTS=0");

        PublicIncludePaths.Add(ModuleDirectory);

        string ThirdPartyPath = System.IO.Path.Combine(ModuleDirectory, Target.Platform.ToString());

        if (Target.Type != TargetRules.TargetType.Server)
        {
            if (Target.Platform == UnrealTargetPlatform.Linux || Target.Platform == UnrealTargetPlatform.LinuxArm64)
            {
                PublicDefinitions.Add("_FILE_OFFSET_BITS=64");

                AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenSSL");
                AddEngineThirdPartyPrivateStaticDependencies(Target, "zlib");
                AddEngineThirdPartyPrivateStaticDependencies(Target, "nghttp2");
                AddEngineThirdPartyPrivateStaticDependencies(Target, "libcurl");

                if (Target.Platform == UnrealTargetPlatform.LinuxArm64) {
                    ThirdPartyPath = System.IO.Path.Combine(ThirdPartyPath, "aarch64-unknown-linux-gnu");
                } else if (Target.Platform == UnrealTargetPlatform.Linux) {
                    ThirdPartyPath = System.IO.Path.Combine(ThirdPartyPath, "x86_64-unknown-linux-gnu");
                }

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libs2n.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-auth.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-cal.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-compression.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-http.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-io.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-mqtt.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-s3.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-common.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-checksums.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-event-stream.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-sdkutils.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-crt-cpp.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-cpp-sdk-core.a"));
            }
            else if (Target.Platform == UnrealTargetPlatform.Android)
            {
        		PublicDefinitions.Add("_FILE_OFFSET_BITS=64");

                AdditionalPropertiesForReceipt.Add("AndroidPlugin", System.IO.Path.Combine(ModuleDirectory, "AWSCoreSDK_UPL.xml"));

        		PublicDefinitions.Add("_GLIBCXX_FULLY_DYNAMIC_STRING=1");

                AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenSSL");
                AddEngineThirdPartyPrivateStaticDependencies(Target, "zlib");
                AddEngineThirdPartyPrivateStaticDependencies(Target, "libcurl");

                {
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libs2n.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-c-auth.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-c-cal.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-c-compression.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-c-http.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-c-io.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-c-mqtt.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-c-s3.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-c-common.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-checksums.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-c-event-stream.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-c-sdkutils.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-crt-cpp.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "arm64-v8a", "libaws-cpp-sdk-core.a"));
                }

                {
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libs2n.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-c-auth.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-c-cal.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-c-compression.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-c-http.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-c-io.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-c-mqtt.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-c-s3.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-c-common.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-checksums.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-c-event-stream.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-c-sdkutils.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-crt-cpp.a"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "x86_64", "libaws-cpp-sdk-core.a"));
                }
            }
            else if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                if (Target.Type == TargetRules.TargetType.Editor) {
                    PublicDefinitions.Add("USE_AWS_MEMORY_MANAGEMENT=ON");

                    PublicDefinitions.Add("USE_WINDOWS_DLL_SEMANTICS=1");

                    PublicDefinitions.Add("USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_AUTH_USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_CAL_USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_CHECKSUMS_USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_COMMON_USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_COMPRESSION_USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_EVENT_STREAM_USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_HTTP_USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_IO_USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_MQTT_USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_S3_USE_IMPORT_EXPORT=1");
                    PublicDefinitions.Add("AWS_CRT_CPP_USE_IMPORT_EXPORT=1");

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-cpp-sdk-core.lib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-auth.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-cal.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-compression.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-http.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-io.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-mqtt.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-s3.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-common.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-checksums.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-event-stream.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-sdkutils.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-crt-cpp.lib"));

                    // PublicDelayLoadDLLs.Add("aws-c-auth.dll");
                    // PublicDelayLoadDLLs.Add("aws-c-cal.dll");
                    // PublicDelayLoadDLLs.Add("aws-c-compression.dll");
                    // PublicDelayLoadDLLs.Add("aws-c-http.dll");
                    // PublicDelayLoadDLLs.Add("aws-c-io.dll");
                    // PublicDelayLoadDLLs.Add("aws-c-mqtt.dll");
                    // PublicDelayLoadDLLs.Add("aws-c-s3.dll");
                    // PublicDelayLoadDLLs.Add("aws-c-common.dll");
                    // PublicDelayLoadDLLs.Add("aws-checksums.dll");
                    // PublicDelayLoadDLLs.Add("aws-c-event-stream.dll");
                    PublicDelayLoadDLLs.Add("aws-crt-cpp.dll");
                    PublicDelayLoadDLLs.Add("aws-cpp-sdk-core.dll");

                    string BinariesDirectory = System.IO.Path.Combine(PluginDirectory, "Binaries", Target.Platform.ToString());
                    if (!Directory.Exists(BinariesDirectory))
                    {
                        Directory.CreateDirectory(BinariesDirectory);
                    }

                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-c-auth.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-auth.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-c-auth.dll"));
                    }
                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-c-cal.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-cal.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-c-cal.dll"));
                    }
                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-c-compression.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-compression.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-c-compression.dll"));
                    }
                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-c-http.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-http.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-c-http.dll"));
                    }
                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-c-io.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-io.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-c-io.dll"));
                    }
                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-c-mqtt.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-mqtt.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-c-mqtt.dll"));
                    }
                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-c-s3.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-s3.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-c-s3.dll"));
                    }
                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-c-common.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-common.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-c-common.dll"));
                    }
                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-checksums.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-checksums.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-checksums.dll"));
                    }
                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-c-event-stream.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-event-stream.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-c-event-stream.dll"));
                    }
                    if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-c-sdkutils.dll")) == false)
                    {
                        File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-sdkutils.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-c-sdkutils.dll"));
                    }
                    // if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-crt-cpp.dll")) == false)
                    // {
                    // 	File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-crt-cpp.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-crt-cpp.dll"));
                    // }
                    // if (File.Exists(System.IO.Path.Combine(BinariesDirectory, "aws-cpp-sdk-core.dll")) == false)
                    // {
                    // 	File.Copy(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-cpp-sdk-core.dll"), System.IO.Path.Combine(BinariesDirectory, "aws-cpp-sdk-core.dll"));
                    // }

                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-c-auth.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-auth.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-c-cal.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-cal.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-c-compression.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-compression.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-c-http.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-http.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-c-io.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-io.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-c-mqtt.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-mqtt.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-c-s3.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-s3.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-c-common.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-common.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-checksums.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-checksums.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-c-event-stream.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-event-stream.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-c-sdkutils.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-c-sdkutils.dll"));
                    // RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-crt-cpp.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-crt-cpp.dll"));
                    // RuntimeDependencies.Add(System.IO.Path.Combine("$(BinaryOutputDir)", "aws-cpp-sdk-core.dll"), System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-cpp-sdk-core.dll"));

                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-crt-cpp.dll"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "aws-cpp-sdk-core.dll"));
                } else {
                    PublicAdditionalLibraries.Add("winhttp.lib");
                    PublicAdditionalLibraries.Add("bcrypt.lib");
                    PublicAdditionalLibraries.Add("Crypt32.Lib");
                    PublicAdditionalLibraries.Add("UserEnv.Lib");
                    PublicAdditionalLibraries.Add("Version.Lib");
                    PublicAdditionalLibraries.Add("ShLwApi.Lib");
                    PublicAdditionalLibraries.Add("Secur32.Lib");
                    PublicAdditionalLibraries.Add("ncrypt.Lib");

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-c-auth.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-c-cal.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-c-compression.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-c-http.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-c-io.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-c-mqtt.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-c-s3.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-c-common.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-checksums.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-c-event-stream.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-c-sdkutils.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-crt-cpp.lib"));
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "aws-cpp-sdk-core.lib"));
                }
            }
            else if (Target.Platform == UnrealTargetPlatform.Mac)
            {
        		PublicDefinitions.Add("_FILE_OFFSET_BITS=64");

        		if (Target.Type == TargetRules.TargetType.Editor) {
                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-auth.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-auth.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-cal.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-cal.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-compression.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-compression.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-http.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-http.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-io.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-io.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-mqtt.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-mqtt.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-s3.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-s3.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-common.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-common.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-checksums.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-checksums.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-event-stream.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-event-stream.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-sdkutils.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-c-sdkutils.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-crt-cpp.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-crt-cpp.dylib"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-cpp-sdk-core.dylib"));
                    RuntimeDependencies.Add(System.IO.Path.Combine(ThirdPartyPath, "Editor", "libaws-cpp-sdk-core.dylib"));
        		} else {
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenSSL");
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "zlib");
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "nghttp2");
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "libcurl");

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-c-auth.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-c-cal.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-c-compression.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-c-http.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-c-io.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-c-mqtt.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-c-s3.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-c-common.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-checksums.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-c-event-stream.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-c-sdkutils.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-crt-cpp.a"));

                    PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "Game", "libaws-cpp-sdk-core.a"));
        		}
            }
            else if (Target.Platform == UnrealTargetPlatform.IOS)
            {
        		PublicDefinitions.Add("_FILE_OFFSET_BITS=64");

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libcurl.a"));

                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-auth.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-cal.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-compression.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-http.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-io.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-mqtt.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-s3.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-common.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-checksums.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-event-stream.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-c-sdkutils.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-crt-cpp.a"));
                PublicAdditionalLibraries.Add(System.IO.Path.Combine(ThirdPartyPath, "libaws-cpp-sdk-core.a"));

            }
            }
        }
    }
