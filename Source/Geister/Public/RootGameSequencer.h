// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleSaveDataRepository.h"
#include "CoreMinimal.h"
#include "LoginAccountProvider.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "LogMacroLibrary.h"
#include "SecretConfiguration.h"
#include "ScreenManager.h"
#include "PlayfabBattleSaveDataRepository.h"
#include "PlayfabLoginAccountProvider.h"
#include "UserWidget.h"
#include "RootGameSequencer.generated.h"

UCLASS()
class GEISTER_API ARootGameSequencer : public AActor
{
	GENERATED_BODY()
private:
	
public:	
	// Sets default values for this actor's properties
	ARootGameSequencer();
	
	ALoginAccountProvider* LoginAccountProvider;
	ABattleSaveDataRepository* BattleSaveDataRepository;
	PlayFabClientPtr ClientApi;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UFUNCTION()
	void SuccessedLoggedin();
	UFUNCTION()
	void FailedLoggedin();
	UFUNCTION()
	void SuccessedSavingBattleRate();
	UFUNCTION()
	void FailedSavingBattleRate();

	UPROPERTY(EditAnywhere)
	AScreenManager* ScreenManager;
};
