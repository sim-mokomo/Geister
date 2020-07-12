// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGameSequencer.h"


void ATitleGameSequencer::StartSequence()
{
    auto Root = GetRootGameSequnecer(GetWorld());
    auto ScreenManager = Root->ScreenManager;
    auto TitlePresenter = ScreenManager->GetPresenter(ScreenPresenterType_Title);
    ScreenManager->AddScreen(TitlePresenter);
}

void ATitleGameSequencer::EndSequence()
{
}

GameSequencerType ATitleGameSequencer::GetSelfSequencerType()
{
    return GameSequencer_Title;
}
