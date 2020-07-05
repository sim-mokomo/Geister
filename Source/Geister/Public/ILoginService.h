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
	UPROPERTY(EditAnywhere,Category="Geister|Account")
		FString ClientId;
	UPROPERTY(EditAnywhere, Category = "Geister|Account")
		FString ClientSecret;
	UPROPERTY(EditAnywhere, Category = "Geister|Account")
		FString AccountNamespaceName;
	UPROPERTY(EditAnywhere, Category = "Geister|Account")
		FString AccountEncryptionKeyId;

	UPROPERTY(BlueprintAssignable, Category = "Geister|Account")
		FCompleteInitializedProfile CompleteInitializeProfileDelegate;
	UPROPERTY(BlueprintAssignable, Category = "Geister|Account")
		FCompleteCreatedProfile CompleteCreatedProfileDelegate;
	UPROPERTY(BlueprintAssignable, Category = "Geister|Account")
		FCompleteLoggedIn CompleteLoggedInDelegate;
	UPROPERTY(BlueprintAssignable, Category = "Geister|Account")
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

	UFUNCTION(BlueprintCallable, Category = "Geister|Account")
	void Initialize();
	UFUNCTION(BlueprintCallable, Category = "Geister|Account")
	void CreateAccount();
	UFUNCTION(BlueprintCallable, Category = "Geister|Account")
	void Login(FString UserId,FString Password);
	UFUNCTION(BlueprintCallable, Category = "Geister|Account")
	void Finalize();
	UFUNCTION(BlueprintPure, Category = "Geister|Account")
	FString GetLoggedInUserId();
	UFUNCTION(BlueprintPure, Category = "Geister|Account")
	FString GetLoggedInUserPassword();
};