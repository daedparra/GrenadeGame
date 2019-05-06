// Fill out your copyright notice in the Description page of Project Settings.

#include "GrenadeBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

// Sets default values
AGrenadeBase::AGrenadeBase()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	SphereComponet = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

	RootComponent = SphereComponet;
	MeshComponent->AttachTo(RootComponent);
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> Particle(TEXT("/Game/StarterContent/Particles/P_Explosion.P_Explosion"));
	ParticleFX1 = Particle.Object;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FuseTime = 3.f;

	//Replicates the grenade on client
	bReplicates = true;
	bReplicateMovement = true;
}

//Calling this function in a certain time
void AGrenadeBase::OnExplode()
{
	NetMulticastExplode();

	Destroy();


	//GetWorld()->SpawnActor(Particle, &GetActorLocation(), &GetActorRotation());
}


// Called when the game starts or when spawned
void AGrenadeBase::BeginPlay()
{
	Super::BeginPlay();

	if (Role == ROLE_Authority)
	{
		UWorld* World = GetWorld();
		if (World != nullptr)
		{
			World->GetTimerManager().SetTimer(TimerHandle_Fuse, this, &AGrenadeBase::OnExplode, FuseTime);
		}
	}
}

// Called every frame
void AGrenadeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Cast the particle effect via server
void AGrenadeBase::NetMulticastExplode_Implementation()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleFX1, GetActorLocation());
}


