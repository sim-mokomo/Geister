// Fill out your copyright notice in the Description page of Project Settings.


#include "RootGameSequencer.h"
#include "JsonFunctionLibrary.h"
// #include "TitleScreenPresenter.h"

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

	const FTransform spawnTransform = FTransform::Identity;
	// auto playfabBattleSaveRepository = GetWorld()->SpawnActorDeferred<APlayfabBattleSaveDataRepository>(APlayfabBattleSaveDataRepository::StaticClass(),spawnTransform);
	// FPlayfabBattleRepositoryInitializeData PlayfabBattleRepositoryInitializeData(ClientApi);
	// playfabBattleSaveRepository->SetInitializeData(PlayfabBattleRepositoryInitializeData);
	// playfabBattleSaveRepository->FinishSpawning(spawnTransform);
	// BattleSaveDataRepository =playfabBattleSaveRepository;
	// BattleSaveDataRepository->OnSuccessDelegate.AddDynamic(this,&ARootGameSequencer::SuccessedSavingBattleRate);
	// BattleSaveDataRepository->OnErrorDelegate.AddDynamic(this,&ARootGameSequencer::FailedSavingBattleRate);

	FString jsonFullPath = FPaths::ProjectDir().Append("SecretLoginConfiguration").Append(TEXT(".json"));
	FSecretLoginConfiguration secretLoginConfiguration;
	UJsonFunctionLibrary::CreateUStructFromJsonPath<FSecretLoginConfiguration>(jsonFullPath, &secretLoginConfiguration, 0, 0);
	
	auto gs2LoginAccountProvider = GetWorld()->SpawnActorDeferred<AGS2LoginAccountProvider>(AGS2LoginAccountProvider::StaticClass(),spawnTransform);
	FGS2LoginAccountInitializeData gs2LoginAccountInitializeData(
		secretLoginConfiguration.clientId,
		secretLoginConfiguration.clientSecretId,
		secretLoginConfiguration.accountNamespaceName,
		secretLoginConfiguration.accountEncryptionKey);
	gs2LoginAccountProvider->SetInitializeConfig(gs2LoginAccountInitializeData);
	gs2LoginAccountProvider->FinishSpawning(spawnTransform);
	LoginAccountProvider = gs2LoginAccountProvider;
	LoginAccountProvider->OnSuccessDelegate.AddDynamic(this,&ARootGameSequencer::SuccessedLoggedin);
	LoginAccountProvider->OnErrorDelegate.AddDynamic(this,&ARootGameSequencer::FailedLoggedin);
	LoginAccountProvider->Login();
	
	GameSequenceSelector->ChangeGameSequencer(GameSequencer_Title);
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
}

void ARootGameSequencer::FailedLoggedin()
{
	UE_SUCCESS_LOG("failed login");
}

void ARootGameSequencer::SuccessedSavingBattleRate()
{
	UE_SUCCESS_LOG("successed save battle rate");
}

void ARootGameSequencer::FailedSavingBattleRate()
{
	UE_ERROR_LOG("failed save battle rate");
}