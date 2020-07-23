// Fill out your copyright notice in the Description page of Project Settings.


#include "RootGameSequencer.h"
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
	ULogFunctionLibrary::DisplayLog(ELogType::Success, "successed login");
}

void ARootGameSequencer::FailedLoggedin()
{
	ULogFunctionLibrary::DisplayLog(ELogType::Error, "failed login");
}

void ARootGameSequencer::SuccessedSavingBattleRate()
{
	ULogFunctionLibrary::DisplayLog(ELogType::Success, "successed save battle rate");
}

void ARootGameSequencer::FailedSavingBattleRate()
{
	ULogFunctionLibrary::DisplayLog(ELogType::Error, "failed save battle rate");
}