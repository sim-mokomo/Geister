// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Geister : ModuleRules
{
	public Geister(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "HTTP", "WebSocket","Json" });
        PublicSystemIncludePaths.Add(System.IO.Path.Combine(ModuleDirectory, "gs2-unreal-engine-sdk/src/"));
     
    }
}
