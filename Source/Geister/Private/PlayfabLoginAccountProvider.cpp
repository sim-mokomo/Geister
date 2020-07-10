// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayfabLoginAccountProvider.h"

// Sets default values
APlayfabLoginAccountProvider::APlayfabLoginAccountProvider()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayfabLoginAccountProvider::BeginPlay()
{
	Super::BeginPlay();

	SetActorLabel("PlayfabLoginAccountProvider");

	clientApi = initializeData.clientApi;
}

// Called every frame
void APlayfabLoginAccountProvider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayfabLoginAccountProvider::Login()
{
	PlayFab::ClientModels::FLoginWithCustomIDRequest request;
	request.CustomId = TEXT("TestUser");
	request.CreateAccount = true;

	clientApi->LoginWithCustomID(request,
		PlayFab::UPlayFabClientAPI::FLoginWithCustomIDDelegate::CreateUObject(this, &APlayfabLoginAccountProvider::OnSuccess),
			PlayFab::FPlayFabErrorDelegate::CreateUObject(this,&APlayfabLoginAccountProvider::OnError));
}

void APlayfabLoginAccountProvider::Logout()
{
	
}

void APlayfabLoginAccountProvider::OnSuccess(const PlayFab::ClientModels::FLoginResult& LoggedinResult)
{	
	this->loggedinResult = LoggedinResult;
	OnSuccessDelegate.Broadcast();
}

void APlayfabLoginAccountProvider::OnError(const PlayFab::FPlayFabCppError& errorResult)
{
	this->loggedInErrorResult = errorResult;
	OnErrorDelegate.Broadcast();
}
