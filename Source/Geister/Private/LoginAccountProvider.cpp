// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginAccountProvider.h"

// Sets default values
ALoginAccountProvider::ALoginAccountProvider()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALoginAccountProvider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALoginAccountProvider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALoginAccountProvider::Login()
{
}

void ALoginAccountProvider::Logout()
{
}

