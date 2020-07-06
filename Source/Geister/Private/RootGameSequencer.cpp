// Fill out your copyright notice in the Description page of Project Settings.


#include "RootGameSequencer.h"

void ARootGameSequencer::OnCompleteInitializedProfile()
{
	if (this->loginDataRepository->ExistSaveData())
	{
		auto saveData = loginDataRepository->Load();
		this->loginService->Login(saveData->GetUserId(),saveData->GetPassword());
	}
	else
	{
		loginService->CreateAccount();
	}
}

void ARootGameSequencer::OnCompleteCreatedAccount()
{
	auto userId = this->loginService->GetLoggedInUserId();
	auto userPassword = this->loginService->GetLoggedInUserPassword();
	this->loginDataRepository->Save(userId, userPassword);
	this->loginService->Login(userId,userPassword);
}

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
	
	// ローカルにログインデータを保存、使いまわしができるように
	// GS2 SDK初期化
	this->loginService->CompleteInitializeProfileDelegate.AddDynamic(this, &ARootGameSequencer::OnCompleteInitializedProfile);
	this->loginService->CompleteCreatedProfileDelegate.AddDynamic(this, &ARootGameSequencer::OnCompleteCreatedAccount);
	this->loginService->Initialize();
}

// Called every frame
void ARootGameSequencer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AGS2AccountService* ARootGameSequencer::GetAccountService()
{
	return this->loginService;
}

AGS2LoginDataRepository* ARootGameSequencer::GetAccountSaveService()
{
	return this->loginDataRepository;
}

