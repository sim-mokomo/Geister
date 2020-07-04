// Fill out your copyright notice in the Description page of Project Settings.


#include "ISaveService.h"

// Sets default values
AISaveService::AISaveService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

void AISaveService::Save(FString UserId, FString Password)
{
	auto saveGameInstance = Cast<UGeiserSaveData>(UGameplayStatics::CreateSaveGameObject(UGeiserSaveData::StaticClass()));
	if (saveGameInstance == nullptr)
	{
		return;
	}

	saveGameInstance->SetBuildDatas(UserId, Password);
	auto successedSave = UGameplayStatics::SaveGameToSlot(saveGameInstance, this->SaveSlotName, this->SaveUserIndex);
	if (!successedSave)
	{
		return;
	}
}

