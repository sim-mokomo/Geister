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
	
}

// Called every frame
void APlayfabLoginAccountProvider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayfabLoginAccountProvider::Login()
{
	UE_SUCCESS_LOG("successed login");
}

void APlayfabLoginAccountProvider::Logout()
{
	UE_SUCCESS_LOG("sucessed logout");
}

