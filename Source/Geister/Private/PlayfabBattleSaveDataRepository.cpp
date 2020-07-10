// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayfabBattleSaveDataRepository.h"

void APlayfabBattleSaveDataRepository::OnSuccessedSaveBattleRate(
    const PlayFab::ClientModels::FUpdateUserDataResult& result)
{
    Super::OnSuccessedSaveBattleRate(result);
    OnSuccessDelegate.Broadcast();
}

void APlayfabBattleSaveDataRepository::OnFailedSaveBattleRate(const PlayFab::FPlayFabCppError& error)
{
    Super::OnFailedSaveBattleRate(error);
    OnErrorDelegate.Broadcast();
}

void APlayfabBattleSaveDataRepository::BeginPlay()
{
    Super::BeginPlay();
    this->clientPtr = initializeData.clientPtr;
}

void APlayfabBattleSaveDataRepository::SaveBattleRate(uint8 newScore)
{
    Super::SaveBattleRate(newScore);
    
    PlayFab::ClientModels::FUpdateUserDataRequest request; 
    request.Data  = {
			    {"battleRate",FString::FromInt(newScore)},
            };

    clientPtr->UpdateUserData(request,
        PlayFab::UPlayFabClientAPI::FUpdateUserDataDelegate::CreateUObject(this,&ABattleSaveDataRepository::OnSuccessedSaveBattleRate),
        PlayFab::FPlayFabErrorDelegate::CreateUObject(this,&ABattleSaveDataRepository::OnFailedSaveBattleRate));
}

void APlayfabBattleSaveDataRepository::Initialize(PlayFabClientPtr clientApi)
{
    Super::Initialize(clientApi);
}
