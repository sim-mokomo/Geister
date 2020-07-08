// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LogMacroLibrary.h"
#include "LoginAccountProvider.h"
#include "PlayFab.h"
#include "Core/PlayFabError.h"
#include "Core/PlayFabClientDataModels.h"
#include "Core/PlayFabClientAPI.h"
#include "SecretConfiguration.h"
#include "PlayfabLoginAccountProvider.generated.h"

UCLASS()
class GEISTER_API APlayfabLoginAccountProvider : public ALoginAccountProvider
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayfabLoginAccountProvider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void Login() override;
	UFUNCTION(BlueprintCallable)
	virtual void Logout() override;
	UFUNCTION(BlueprintCallable)
	virtual void Initialize() override;
	
	void OnSuccess(const PlayFab::ClientModels::FLoginResult& LoggedinResult);
	void OnError(const PlayFab::FPlayFabCppError& errorResult);
	PlayFab::ClientModels::FLoginResult GetLoggedinResult() {return loggedinResult;}
	PlayFab::FPlayFabCppError GetLoggedinError() {return loggedInErrorResult;}
	
	private:
	PlayFabClientPtr clientApi;
	PlayFab::ClientModels::FLoginResult loggedinResult;
	PlayFab::FPlayFabCppError loggedInErrorResult;
};
