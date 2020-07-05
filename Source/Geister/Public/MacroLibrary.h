// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Engine.h"
#include "MacroLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GEISTER_API UMacroLibrary : public UObject
{
	GENERATED_BODY()
};

#define UE_SUCCESS_LOG(message) \
{\
	GEngine->AddOnScreenDebugMessage(-1,9999,FColor::Green,message); \
}

#define UE_ERROR_LOG(message) \
{\
	GEngine->AddOnScreenDebugMessage(-1,9999,FColor::Red,message); \
}

#define UE_WARNING_LOG(message) \
{\
	GEngine->AddOnScreenDebugMessage(-1,9999,FColor::Yellow,message); \
}
