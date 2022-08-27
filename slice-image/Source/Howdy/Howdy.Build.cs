// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Howdy : ModuleRules
{
    public Howdy(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnforceIWYU = true;
        bEnableExceptions = true;
        bLegacyPublicIncludePaths = true;
        ShadowVariableWarningLevel = WarningLevel.Warning;

        PrivateIncludePaths.AddRange(
            new[]
            {
                "Howdy/Private"
            }
        );

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "RHI", "MoviePlayer", "Paper2D" });

        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "UMG" });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}