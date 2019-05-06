// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrenadeBase.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;
class UParticleSystem;
class AParticleSpawner;
UCLASS()
class GRENADEGAME_API AGrenadeBase : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AGrenadeBase();


	UPROPERTY(EditAnywhere)
		USphereComponent* SphereComponet;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComponent;
	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* ProjectileMovementComponent;
	//UPROPERTY(Replicated)
	UParticleSystem* ParticleFX1;
	UFUNCTION()
	void OnExplode();

	UFUNCTION(Reliable, NetMulticast)
	void NetMulticastExplode();
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FTimerHandle	TimerHandle_Fuse;
	float FuseTime;
};
