// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <gs2-unreal-engine-sdk/src/gs2/ez/Gs2Ez.hpp>
#include "LoginAccountProvider.h"
#include "Engine/World.h"
#include "GS2AccountLocalSaveGameProvider.h"
#include "GS2LoginAccountProvider.generated.h"

USTRUCT()
struct FGS2LoginAccountInitializeData : public FLoginAccountInitializeData
{
	GENERATED_BODY()
public:
	FGS2LoginAccountInitializeData()
	{

	}
	FGS2LoginAccountInitializeData(
		FString clientId,
		FString clientSecretId,
		FString accountNameSpaceNameKey,
		FString authAccountEncryptionKeyId)
	{
		ClientId = clientId;
		ClientSecretId = clientSecretId;
		AccountNameSpaceName = accountNameSpaceNameKey;
		AuthAccountEncryptionKeyId = authAccountEncryptionKeyId;
	};

	UPROPERTY()
		FString ClientId;
	UPROPERTY()
		FString ClientSecretId;
	UPROPERTY()
		FString AccountNameSpaceName;
	UPROPERTY()
		FString AuthAccountEncryptionKeyId;
};

/**
 * 
 */
UCLASS()
class GEISTER_API AGS2LoginAccountProvider : public ALoginAccountProvider
{
	GENERATED_BODY()
private:
	std::shared_ptr<gs2::ez::account::Client> Client;
	std::shared_ptr<gs2::ez::Profile> Profile;
	gs2::ez::account::EzAccount Account;
	gs2::ez::GameSession GameSession;
	UPROPERTY()
		FGS2LoginAccountInitializeData initializeConfig;
	UPROPERTY()
		AGS2AccountLocalSaveGameProvider* AccountLocalSaveGameProvider;
	void LoginByAccount(gs2::ez::account::EzAccount account);
protected:
	void BeginPlay() override;
public:
	AGS2LoginAccountProvider();

	UFUNCTION()
		void Login() override;
	UFUNCTION()
		void Logout() override;
	UFUNCTION()
		void SetInitializeConfig(FGS2LoginAccountInitializeData& config);

	gs2::ez::account::EzAccount GetAccount() const { return Account; }
	gs2::ez::account::Client* GetClient() const { return Client.get(); }
	gs2::ez::GameSession GetGameSession() const { return GameSession; }
};
