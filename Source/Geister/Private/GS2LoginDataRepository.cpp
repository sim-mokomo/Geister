// Fill out your copyright notice in the Description page of Project Settings.


#include "GS2LoginDataRepository.h"

// Sets default values
AGS2LoginDataRepository::AGS2LoginDataRepository()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGS2LoginDataRepository::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGS2LoginDataRepository::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGS2LoginDataRepository::Save(FString UserId,FString Password)
{
	UE_LOG(LogTemp, Display, TEXT("start save account data"));
	auto saveGameInstance = Cast<UGS2LoginSaveData>(UGameplayStatics::CreateSaveGameObject(UGS2LoginSaveData::StaticClass()));
	if (saveGameInstance == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("failed create save instance"));
		return;
	}

	saveGameInstance->SetBuildDatas(UserId, Password);
	auto successedSave = UGameplayStatics::SaveGameToSlot(saveGameInstance, this->SaveSlotName, this->SaveUserIndex);
	if (!successedSave)
	{
		UE_LOG(LogTemp, Error, TEXT("failed save to slot"));
		return;
	}

	UE_LOG(LogTemp, Display, TEXT("successed save login data"));
}

bool AGS2LoginDataRepository::ExistSaveData()
{
	return UGameplayStatics::DoesSaveGameExist(this->SaveSlotName, this->SaveUserIndex);
}

UGS2LoginSaveData* AGS2LoginDataRepository::Load()
{
	auto saveData = UGameplayStatics::LoadGameFromSlot(this->SaveSlotName, this->SaveUserIndex);
	auto geisterSaveData = Cast<UGS2LoginSaveData>(saveData);
	return geisterSaveData;
}