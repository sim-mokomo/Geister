// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <gs2-unreal-engine-sdk/src/gs2/ez/Gs2Ez.hpp>
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LogFunctionLibrary.h"
#include "GS2FunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GEISTER_API UGS2FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static gs2::StringHolder* CreateStringHolderFromFString(FString content)
	{
		gs2::StringHolder* stringHolder = new gs2::StringHolder(TCHAR_TO_UTF8(*content));
		return stringHolder;
	}

	static void DisplayGS2Error(gs2::Gs2ClientException exception)
	{
		auto errors = exception.getErrors();
		for (auto i = 0; i < errors.getCount(); i++)
		{
			auto error = errors[i];
			auto message = FString(error.getMessage().value().getCString());
			ULogFunctionLibrary::DisplayLog(ELogType::Error, message);
		}
	}
};
