// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <memory>
#include "UObject/Interface.h"
#include "Geister/Public/AccountLoginDTO.h"
#include "AccountServiceInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAccountServiceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GEISTER_API IAccountServiceInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Initialize();
	virtual void Login(UAccountLoginDTO* loginDTO);
	virtual void CreateAccount();
	virtual void Logout();
};
