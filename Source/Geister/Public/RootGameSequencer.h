// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleSaveDataRepository.h"
#include "CoreMinimal.h"
#include "GS2LoginAccountProvider.h"
#include "GameSequenceSelector.h"
#include "LoginAccountProvider.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "LogMacroLibrary.h"
#include "SecretConfiguration.h"
#include "ScreenManager.h"
#include "UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "RootGameSequencer.generated.h"

USTRUCT()
struct FSecretLoginConfiguration
{
	GENERATED_BODY()
public:
	FSecretLoginConfiguration()
	{

	};

	UPROPERTY()
	FString clientId;
	UPROPERTY()
	FString clientSecretId;
	UPROPERTY()
	FString accountNamespaceName;
	UPROPERTY()
	FString accountEncryptionKey;
};

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
	UFUNCTION()
	AScreenManager* GetScreenManager() const {return ScreenManager;}
	
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
	TArray<AActor*> rootGameSequnecers;
	UGameplayStatics::GetAllActorsOfClass(WorldContextObject, ARootGameSequencer::StaticClass(), rootGameSequnecers);
	auto RootGameSequencerActor = rootGameSequnecers[0];
	auto RootGameSequencer = Cast<ARootGameSequencer>(RootGameSequencerActor);
	return RootGameSequencer;
}