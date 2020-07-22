// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LogMacroLibrary.h"
#if UE_SERVER
#include "gsdk.h"
#include "string.h"
#endif

class FGeisterGameModuleImpl : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool IsGameModule() const override
	{
		return true;
	}
#if UE_SERVER
private:
	void ConnectToPlayfabAgent();
	void LogInfo(FString message);
	void LogError(FString message);
#endif
};