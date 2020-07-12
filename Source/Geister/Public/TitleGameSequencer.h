// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSequencer.h"
#include "RootGameSequencer.h"
#include "TitleGameSequencer.generated.h"

/**
 * 
 */
UCLASS()
class GEISTER_API ATitleGameSequencer : public AGameSequencer
{
	GENERATED_BODY()


public:
	void StartSequence() override;
	void EndSequence() override;
	GameSequencerType GetSelfSequencerType() override;
};
