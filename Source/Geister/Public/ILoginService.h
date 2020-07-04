// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <gs2/ez/Gs2Ez.hpp>
#include <memory>
#include "DelegateCombinations.h"
#include "ILoginService.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCompleteInitializedProfile);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCompleteCreatedProfile);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCompleteLoggedIn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCompleteLoggedOut);

UCLASS()
class GEISTER_API AILoginService : public AActor
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere,Category="GS2")
		FString clientId;
	UPROPERTY(EditAnywhere, Category = "GS2")
		FString clientSecret;
	UPROPERTY(EditAnywhere, Category = "GS2")
		FString accountNamespaceName;
	UPROPERTY(EditAnywhere, Category = "GS2")
		FString accountEncryptionKeyId;

	UPROPERTY(BlueprintAssignable, Category = "GS2")
		FCompleteInitializedProfile CompleteInitializeProfileDelegate;
	UPROPERTY(BlueprintAssignable, Category = "GS2")
		FCompleteCreatedProfile CompleteCreatedProfileDelegate;
	UPROPERTY(BlueprintAssignable, Category = "GS2")
		FCompleteLoggedIn CompleteLoggedInDelegate;
	UPROPERTY(BlueprintAssignable, Category = "GS2")
		FCompleteLoggedOut CompleteLoggedOutDelegate;

	// Sets default values for this actor's properties
	AILoginService();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	std::shared_ptr<gs2::ez::Profile> ProfilePtr;
	std::shared_ptr<gs2::ez::Client> ClientPtr;

	gs2::ez::GameSession GameSession;
	gs2::ez::account::EzAccount EzAccount;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "GS2")
	void InitializeProfile();
	UFUNCTION(BlueprintCallable, Category = "GS2")
	void CreateAccount();
	UFUNCTION(BlueprintCallable, Category = "GS2")
	void LoginByProfile();
	UFUNCTION(BlueprintCallable, Category = "GS2")
	void FinalizeProfile();
	UFUNCTION(BlueprintPure, Category = "GS2")
	FString GetLoggedInUserId();
	UFUNCTION(BlueprintPure, Category = "GS2")
	FString GetLoggedInUserPassword();
};