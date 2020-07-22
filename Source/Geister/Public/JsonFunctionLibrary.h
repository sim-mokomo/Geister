// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Paths.h"
#include "FileHelper.h"
#include "JsonUtilities.h"
#include "LogFunctionLibrary.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JsonFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GEISTER_API UJsonFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	template<typename OutStructType>
	static bool CreateUStructFromJsonPath(FString fullPath, OutStructType* outStruct, int checkFlags, int skipFlags)
	{
		if (!FPaths::FileExists(fullPath))
		{
			ULogFunctionLibrary::DisplayLog(ELogType::Error, fullPath + "is not exist");
			return false;
		}

		FString jsonRawString;
		if (!FFileHelper::LoadFileToString(jsonRawString, *fullPath))
		{
			ULogFunctionLibrary::DisplayLog(ELogType::Error, fullPath + "failed reading file");
			return false;
		}

		if (!FJsonObjectConverter::JsonObjectStringToUStruct(jsonRawString, outStruct, checkFlags, skipFlags))
		{
			ULogFunctionLibrary::DisplayLog(ELogType::Error, fullPath + "failed deserialize");
			return false;
		}

		return true;
	}
};
