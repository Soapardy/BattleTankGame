// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKGAME_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

protected:

public:	

	void AimAt(FVector HitLocation, float LunchSpeed);

private:
	// Das Barrel (Rohr) des Tanks
	UStaticMeshComponent * Barrel = nullptr;

	void MoveBarrel(FVector AimDirection);
};