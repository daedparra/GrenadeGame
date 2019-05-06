// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GrenadeGameGameMode.h"
#include "GrenadeGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGrenadeGameGameMode::AGrenadeGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonPlayerController"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	if (PlayerControllerBPClass.Class != NULL) 
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}
