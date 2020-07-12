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
public:
	void OnAddedToScreen() override;
	ScreenPresenterType GetSelfScreenPresenterType() override;
private:
	GENERATED_BODY()
};
