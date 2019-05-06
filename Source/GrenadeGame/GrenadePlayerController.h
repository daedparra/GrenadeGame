// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GrenadePlayerController.generated.h"

/**
 * 
 */
class UMyUserWidget;
UCLASS()
class GRENADEGAME_API AGrenadePlayerController : public APlayerController
{
	GENERATED_BODY()
	
		virtual void BeginPlay() override;
	UPROPERTY()
		UMyUserWidget* GameInfoWidget;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UMyUserWidget> GameInfoBP;

};
