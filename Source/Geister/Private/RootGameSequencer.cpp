// Fill out your copyright notice in the Description page of Project Settings.


#include "RootGameSequencer.h"

#include "TitleScreenPresenter.h"

// Sets default values
ARootGameSequencer::ARootGameSequencer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARootGameSequencer::BeginPlay()
{
	Super::BeginPlay();

	ClientApi = IPlayFabModuleInterface::Get().GetClientAPI();
	ClientApi->SetTitleId(TEXT(TITLEID));

	const FTransform spawnTransform = FTransform::Identity;
	auto playfabBattleSaveRepository = GetWorld()->SpawnActorDeferred<APlayfabBattleSaveDataRepository>(APlayfabBattleSaveDataRepository::StaticClass(),spawnTransform);
	FPlayfabBattleRepositoryInitializeData PlayfabBattleRepositoryInitializeData(ClientApi);
	playfabBattleSaveRepository->SetInitializeData(PlayfabBattleRepositoryInitializeData);
	playfabBattleSaveRepository->FinishSpawning(spawnTransform);
	BattleSaveDataRepository =playfabBattleSaveRepository;
	BattleSaveDataRepository->OnSuccessDelegate.AddDynamic(this,&ARootGameSequencer::SuccessedSavingBattleRate);
	BattleSaveDataRepository->OnErrorDelegate.AddDynamic(this,&ARootGameSequencer::FailedSavingBattleRate);
		
	auto playfabLoginAccountProvider = GetWorld()->SpawnActorDeferred<APlayfabLoginAccountProvider>(APlayfabLoginAccountProvider::StaticClass(),spawnTransform);
	FPlayfabLoginAccountInitializeData playfabLoginAccountInitializeData(ClientApi);
	playfabLoginAccountProvider->SetInitializeData(playfabLoginAccountInitializeData);
	playfabLoginAccountProvider->FinishSpawning(spawnTransform);
	
	LoginAccountProvider = playfabLoginAccountProvider;
	LoginAccountProvider->OnSuccessDelegate.AddDynamic(this,&ARootGameSequencer::SuccessedLoggedin);
	LoginAccountProvider->OnErrorDelegate.AddDynamic(this,&ARootGameSequencer::FailedLoggedin);
	LoginAccountProvider->Login();
	
	ATitleScreenPresenter* TitleScreenPresenter;
	ScreenManager->DefinedScreenPresenterTable.FindItemByClass<ATitleScreenPresenter>(&TitleScreenPresenter);
	ScreenManager->AddScreen(TitleScreenPresenter);
}

// Called every frame
void ARootGameSequencer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ScreenManager->Tick(DeltaTime);
}

void ARootGameSequencer::SuccessedLoggedin()
{
	UE_SUCCESS_LOG("sucessed login");	
	BattleSaveDataRepository->SaveBattleRate(100);
}

void ARootGameSequencer::FailedLoggedin()
{
	UE_SUCCESS_LOG("sucessed logout");
}

void ARootGameSequencer::SuccessedSavingBattleRate()
{
	UE_SUCCESS_LOG("successed save battle rate");
}

void ARootGameSequencer::FailedSavingBattleRate()
{
	UE_ERROR_LOG("failed save battle rate");
}
