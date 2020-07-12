// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleSaveDataRepository.h"
#include "CoreMinimal.h"
#include "GameSequenceSelector.h"
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
#include "Kismet/GameplayStatics.h"

#include "RootGameSequencer.generated.h"

UCLASS()
class GEISTER_API ARootGameSequencer : public AActor
{
	GENERATED_BODY()
private:
	
public:	
	// Sets default values for this actor's properties
	ARootGameSequencer();

	UPROPERTY()
	ALoginAccountProvider* LoginAccountProvider;
	UPROPERTY()
	ABattleSaveDataRepository* BattleSaveDataRepository;
	PlayFabClientPtr ClientApi;
	UPROPERTY(EditAnywhere)
	AGameSequenceSelector* GameSequenceSelector;
	UPROPERTY(EditAnywhere)
	AScreenManager* ScreenManager;

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
};

static ARootGameSequencer* GetRootGameSequnecer(const UObject* WorldContextObject) 
{
	auto RootGameSequencerActor = UGameplayStatics::GetActorOfClass(WorldContextObject,ARootGameSequencer::StaticClass());
	auto RootGameSequencer = Cast<ARootGameSequencer>(RootGameSequencerActor);\
	return RootGameSequencer;
}
