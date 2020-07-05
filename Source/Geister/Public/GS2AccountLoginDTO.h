// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AccountLoginDTO.h"
#include "GS2AccountLoginDTO.generated.h"

/**
 * 
 */
UCLASS()
class GEISTER_API UGS2AccountLoginDTO : public UAccountLoginDTO
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	FString UserId;
	UPROPERTY()
	FString Password;
public:
	UGS2AccountLoginDTO();

	UFUNCTION()
		void Initialize(FString saveUserId,FString savePassword);
	UFUNCTION()
	FString GetUserId();
	UFUNCTION()
	FString GetPassword();
};
