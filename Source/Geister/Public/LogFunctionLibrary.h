// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LogFunctionLibrary.generated.h"

UENUM()
enum class ELogType : uint8
{
	Success,
	Error,
	Warning,
};

/**
 * 
 */
UCLASS()
class GEISTER_API ULogFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
private:
	static FColor GetLogColor(ELogType logType)
	{
		TMap<ELogType, FColor> map = {
			{ELogType::Success, FColor::Green},
			{ ELogType::Warning,FColor::Yellow},
			{ ELogType::Error,FColor::Red }
		};

		auto color = map.Find(logType);
		if (color == nullptr)
		{
			return FColor::White;
		}
		return *color;
	}
public:
	static void DisplayLog(ELogType logType,FString message)
	{
		GEngine->AddOnScreenDebugMessage(-1, 9999, GetLogColor(logType), message);
	}
};
