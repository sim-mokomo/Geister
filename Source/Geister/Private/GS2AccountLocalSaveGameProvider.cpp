// Fill out your copyright notice in the Description page of Project Settings.


#include "GS2AccountLocalSaveGameProvider.h"
#include "LogFunctionLibrary.h"

// Sets default values
AGS2AccountLocalSaveGameProvider::AGS2AccountLocalSaveGameProvider()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	saveSlotName = "localLoginAccountSaveGame";
	saveSlotIndex = 0;
}

// Called when the game starts or when spawned
void AGS2AccountLocalSaveGameProvider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGS2AccountLocalSaveGameProvider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGS2AccountLocalSaveGameProvider::ExistsSaveGame()
{
	return UGameplayStatics::DoesSaveGameExist(saveSlotName, saveSlotIndex);
}

UGS2AccountLocalSaveGame* AGS2AccountLocalSaveGameProvider::GetSaveGame()
{
	auto gs2SaveGameInstance = Cast<UGS2AccountLocalSaveGame>(
		UGameplayStatics::LoadGameFromSlot(saveSlotName, saveSlotIndex));
	return gs2SaveGameInstance;
}

bool AGS2AccountLocalSaveGameProvider::Save(FString userId, FString userPassword)
{
	auto saveGameInstance = Cast<UGS2AccountLocalSaveGame>(UGameplayStatics::CreateSaveGameObject(UGS2AccountLocalSaveGame::StaticClass()));
	if (saveGameInstance == nullptr)
	{
		return false;
	}

	saveGameInstance->Setting(userId, userPassword);
	auto successedSave = UGameplayStatics::SaveGameToSlot(saveGameInstance, saveSlotName, saveSlotIndex);
	if (!successedSave)
	{
		return false;
	}

	return true;
}

