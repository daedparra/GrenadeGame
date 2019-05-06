// Fill out your copyright notice in the Description page of Project Settings.

#include "MyUserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "GrenadeGameCharacter.h"

bool UMyUserWidget::Initialize()
{
	bool bResult = Super::Initialize();
	if (!bResult)
	{
		return false;
	}
	UTextBlock* Widget = Cast<UTextBlock>(GetWidgetFromName("TextBlock_42"));
	if (Widget != nullptr)
	{
		Widget->SetText(FText::FromString("YO MAMA"));
	}
	return true;
}
//static int myValue = 0;

void UMyUserWidget::NativeTick(const FGeometry & MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	NetMulticastNum();
}


//This function will call it via server so it can change the value of grenades in the player...
void UMyUserWidget::NetMulticastNum_Implementation() {
	AController* playerCont = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	APawn * playerPawn = playerCont->GetPawn();
	AGrenadeGameCharacter* Player = Cast<AGrenadeGameCharacter>(playerPawn);

	FString Value = FString::Printf(TEXT("Grenades: %d"), Player->numGrenades);
	UTextBlock * Widget = Cast<UTextBlock>(GetWidgetFromName("TextBlock_42"));
	if (Widget != nullptr)
	{
		Widget->SetText(FText::FromString(Value));
	}
}
