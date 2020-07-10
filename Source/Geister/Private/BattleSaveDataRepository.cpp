// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleSaveDataRepository.h"

#include "PlayFabClientDataModels.h"

// Sets default values
ABattleSaveDataRepository::ABattleSaveDataRepository()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABattleSaveDataRepository::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleSaveDataRepository::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABattleSaveDataRepository::SaveBattleRate(uint8 newScore)
{

}

void ABattleSaveDataRepository::Initialize(PlayFabClientPtr clientApi)
{
	this->clientPtr = clientPtr;
}

void ABattleSaveDataRepository::OnSuccessedSaveBattleRate(const PlayFab::ClientModels::FUpdateUserDataResult& result)
{
	
}

void ABattleSaveDataRepository::OnFailedSaveBattleRate(const PlayFab::FPlayFabCppError& error)
{
	
}

