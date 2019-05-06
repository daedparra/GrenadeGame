// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUpBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "GrenadeGameCharacter.h"
// Sets default values
APickUpBase::APickUpBase()
{
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	RootComponent = CollisionComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->AttachTo(RootComponent);

	TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextComponent"));
	TextComponent->AttachTo(RootComponent);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickUpBase::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &APickUpBase::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &APickUpBase::OnOverlapEnd);
}

void APickUpBase::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)
{
	AGrenadeGameCharacter* Player = Cast<AGrenadeGameCharacter>(OtherActor);
	if (Player->numGrenades < 5) 
	{
		Player->numGrenades = 5;
		FString NewnumGrenades;
		NewnumGrenades = FString::Printf(TEXT("%d%"), Player->numGrenades);
		Player->TextComponent->SetText(FText::FromString(NewnumGrenades));
	}
}

void APickUpBase::OnOverlapEnd(AActor * OverlappedActor, AActor * OtherActor)
{

}

// Called every frame
void APickUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

