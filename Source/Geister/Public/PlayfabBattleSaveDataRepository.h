// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleSaveDataRepository.h"
#include "PlayfabBattleSaveDataRepository.generated.h"

USTRUCT()
struct FPlayfabBattleRepositoryInitializeData : public FBattleRepositoryInitializeData
{
    GENERATED_BODY()
public:
    FPlayfabBattleRepositoryInitializeData()
    {
        
    }

    FPlayfabBattleRepositoryInitializeData(PlayFabClientPtr clientPtr)
    {
        this->clientPtr = clientPtr;
    }

    PlayFabClientPtr clientPtr;
};

/**
 * 
 */
UCLASS()
class GEISTER_API APlayfabBattleSaveDataRepository : public ABattleSaveDataRepository
{
	GENERATED_BODY()
private:
protected:
    void BeginPlay() override;
public:
    void SaveBattleRate(uint8 newScore) override;
    void Initialize(PlayFabClientPtr clientApi) override;
    void OnSuccessedSaveBattleRate(const PlayFab::ClientModels::FUpdateUserDataResult& result) override;
    void OnFailedSaveBattleRate(const PlayFab::FPlayFabCppError& error) override;
    void SetInitializeData(FPlayfabBattleRepositoryInitializeData data) {initializeData = data;}
    FPlayfabBattleRepositoryInitializeData initializeData;
};
