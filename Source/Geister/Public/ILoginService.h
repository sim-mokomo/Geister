// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <gs2/ez/Gs2Ez.hpp>
#include <memory>
#include "ILoginService.generated.h"

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

	gs2::ez::Profile* profile;

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

	void InitializeProfile(std::function<void(gs2::ez::Profile::AsyncInitializeResult)> onComplete);
	void CreateAccount(std::function<void(gs2::ez::account::AsyncEzCreateResult)> onComplete);
	void LoginByProfile(std::function<void(gs2::ez::Profile::AsyncLoginResult)> onComplete);
	void FinalizeProfile(std::function<void(void)> onComplete);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,Category="GS2")
	void Login();

	UFUNCTION(BlueprintCallable,Category="GS2")
	void Logout();
};