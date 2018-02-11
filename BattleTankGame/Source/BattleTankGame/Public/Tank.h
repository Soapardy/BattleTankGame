// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	//
	void AimAt(FVector HitLocation);

	// Setzt die Referenz fuer Das Barrel / Rohr des Tanks
	UFUNCTION(BlueprintCallable)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

protected:

	UTankAimingComponent * AimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// StartGeschwindigkeit des Projektiles (Default 1000m/s)
	UPROPERTY(EditAnywhere, Category = Firing)
		float LunchSpeed = 100000;

	
	
};
