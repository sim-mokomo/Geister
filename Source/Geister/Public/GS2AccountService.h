// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <gs2/ez/Gs2Ez.hpp>
#include <memory>
#include "Engine/Engine.h"
#include "Geister/Public/MacroLibrary.h"
#include "DelegateCombinations.h"
#include "Geister/Public/AccountServiceInterface.h"
#include "Geister/Public/GS2AccountLoginDTO.h"
#include "GS2AccountService.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCompleteInitializedProfile);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCompleteCreatedProfile);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCompleteLoggedIn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCompleteLoggedOut);

UCLASS()
class GEISTER_API AGS2AccountService : public AActor, public IAccountServiceInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Geister|Account")
		FString ClientId;
	UPROPERTY(EditAnywhere, Category = "Geister|Account")
		FString ClientSecret;
	UPROPERTY(EditAnywhere, Category = "Geister|Account")
		FString AccountNamespaceName;
	UPROPERTY(EditAnywhere, Category = "Geister|Account")
		FString AccountEncryptionKeyId;

	FCompleteInitializedProfile CompleteInitializeProfileDelegate;
	FCompleteCreatedProfile CompleteCreatedProfileDelegate;
	FCompleteLoggedIn CompleteLoggedInDelegate;
	FCompleteLoggedOut CompleteLoggedOutDelegate;

	// Sets default values for this actor's properties
	AGS2AccountService();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	std::shared_ptr<gs2::ez::Profile> ProfilePtr;
	std::shared_ptr<gs2::ez::Client> ClientPtr;

	gs2::ez::GameSession GameSession;
	gs2::ez::account::EzAccount EzAccount;

	void InitializeProfile();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void Initialize() override;
	UFUNCTION()
		virtual void CreateAccount() override;
		virtual void Login(UAccountLoginDTO* loginDTO) override;
	UFUNCTION()
		virtual void Logout() override;
	UFUNCTION()
		FString GetLoggedInUserId();
	UFUNCTION()
		FString GetLoggedInUserPassword();
};