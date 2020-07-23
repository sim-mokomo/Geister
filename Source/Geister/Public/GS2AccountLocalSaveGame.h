// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GS2AccountLocalSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class GEISTER_API UGS2AccountLocalSaveGame : public USaveGame
{
	GENERATED_BODY()
private:
	UPROPERTY()
		FString userId;
	UPROPERTY()
		FString userPassword;
public:
	UGS2AccountLocalSaveGame();

	UFUNCTION()
		void Setting(FString _userId, FString _userPassword);
	UFUNCTION()
		FString GetUserId() { return userId; }
	UFUNCTION()
		FString GetUserPassword() { return userPassword; }
};
