// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnlitShadedViewMode.h"

#define LOCTEXT_NAMESPACE "FUnlitShadedViewModeModule"

void FUnlitShadedViewModeModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	// Write a config line that will be read by the engine to add the UnlitShaded view mode to the list of view modes.
	// This sort of config doesn't seem to work when specified in the plugin's DefaultUnlitShadedViewMode.ini file, so we do it in code here.
	GConfig->SetString(TEXT("Engine.BufferVisualizationMaterials"), TEXT("UnlitShaded"), TEXT(R"((Material="/UnlitShadedViewMode/UnlitShaded.UnlitShaded", Name=LOCTEXT("UnlitShaderMat", "Unlit Shaded")))"), GEngineIni);
}

void FUnlitShadedViewModeModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUnlitShadedViewModeModule, UnlitShadedViewMode)