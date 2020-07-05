// Fill out your copyright notice in the Description page of Project Settings.


#include "ISaveService.h"

// Sets default values
AISaveService::AISaveService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SaveSlotName = "GeisterLoginAccountSaveData";
	SaveUserIndex = 0;
}

// Called when the game starts or when spawned
void AISaveService::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AISaveService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AISaveService::SaveLoginData(FString UserId, FString Password)
{
	UE_LOG(LogTemp, Display, TEXT("start save account data"));
	auto saveGameInstance = Cast<UGeiserSaveData>(UGameplayStatics::CreateSaveGameObject(UGeiserSaveData::StaticClass()));
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

bool AISaveService::ExistLoginSaveData()
{
	return UGameplayStatics::DoesSaveGameExist(this->SaveSlotName, this->SaveUserIndex);
}

void AISaveService::GetLoginSaveData(FString& UserId, FString& Password)
{
	auto saveData = UGameplayStatics::LoadGameFromSlot(this->SaveSlotName, this->SaveUserIndex);
	auto geisterSaveData = Cast<UGeiserSaveData>(saveData);
	UserId = geisterSaveData->GetUserId();
	Password = geisterSaveData->GetPassword();
}

