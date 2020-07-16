// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGameSequencer.h"

#include "TitleScreenPresenter.h"


void ATitleGameSequencer::StartSequence()
{
    auto ScreenManager = GetRootGameSequnecer(GetWorld())->GetScreenManager();
    ScreenManager->AddScreen(ATitleScreenPresenter::StaticClass());
}

void ATitleGameSequencer::EndSequence()
{
}

GameSequencerType ATitleGameSequencer::GetSelfSequencerType()
{
    return GameSequencer_Title;
}
