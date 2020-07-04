// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "gs2/ez/Profile.hpp"
#include "gs2/ez/Gs2BasicReopener.hpp"
#include "gs2/core/util/StringHolder.hpp"
#include "gs2/core/network/Gs2WebSocketSession.hpp"
#include "gs2/ez/account/Client.hpp"
#include "gs2/ez/account/model/EzAccount.hpp"
#include "gs2/ez/Gs2AccountAuthenticator.hpp"
#include "ILoginService.generated.h"

UCLASS()
class GEISTER_API AILoginService : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
		FString clientId;
	UPROPERTY(EditAnywhere)
		FString clientSecret;
	UPROPERTY(EditAnywhere)
		FString accountNamespaceName;
	UPROPERTY(EditAnywhere)
		FString accountEncryptionKeyId;

	// Sets default values for this actor's properties
	AILoginService();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Login();
};