// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScreenPresenter.h"
#include "TitleScreenPresenter.generated.h"

/**
 * 
 */
UCLASS()
class GEISTER_API ATitleScreenPresenter : public AScreenPresenter
{
private:
	GENERATED_BODY()

protected:
	void BeginPlay() override;
public:
	void Tick(float DeltaTime) override;
	void Setup() override;
	void Dispose() override;
};
