// Fill out your copyright notice in the Description page of Project Settings.

#include "GrenadePlayerController.h"

#include "MyUserWidget.h"

void AGrenadePlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GameInfoBP != nullptr && IsLocalController()) 
	{
		GameInfoWidget = CreateWidget<UMyUserWidget>(this, GameInfoBP);
		GameInfoWidget->AddToViewport();
	}
}
