// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GeiserSaveData.generated.h"

/**
 * 
 */
UCLASS()
class GEISTER_API UGeiserSaveData : public USaveGame
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category = "GeisterSaveData")
	FString UserId;

	UPROPERTY(VisibleAnywhere, Category = "GeisterSaveData")
		FString Password;
public:
	UGeiserSaveData();
	void SetBuildDatas(FString UserId, FString Password);
};
