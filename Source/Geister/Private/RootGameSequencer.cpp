// Fill out your copyright notice in the Description page of Project Settings.


#include "RootGameSequencer.h"

void ARootGameSequencer::OnCompleteInitializedProfile()
{
	if (this->saveService->ExistLoginSaveData())
	{
		FString UserId, Password;
		saveService->GetLoginSaveData(UserId,Password);
		this->loginService->Login(UserId, Password);
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
	this->saveService->SaveLoginData(userId,userPassword);

	FString saveUserId, saveUserPassword;
	this->saveService->GetLoginSaveData(saveUserId,saveUserPassword);
	this->loginService->Login(saveUserId, saveUserPassword);
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
	this->loginService->CompleteInitializeProfileDelegate.AddDynamic(this, &ARootGameSequencer::OnCompleteInitializedProfile);
	this->loginService->CompleteCreatedProfileDelegate.AddDynamic(this, &ARootGameSequencer::OnCompleteCreatedAccount);
	// GS2 SDK初期化
	this->loginService->Initialize();
}

// Called every frame
void ARootGameSequencer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AILoginService* ARootGameSequencer::GetAccountService()
{
	return this->loginService;
}

AISaveService* ARootGameSequencer::GetAccountSaveService()
{
	return this->saveService;
}

