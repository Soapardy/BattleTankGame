// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	// Setzt die Referenz fuer Das Barrel / Rohr des Tanks
	UFUNCTION(BlueprintCallable)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable)
	void SetTurretReference(UTankTurret* TurretToSet);

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
		float LunchSpeed = 5000;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	// Local Barrel Referenz for projectile
	UTankBarrel *Barrel = nullptr;

	// ReloadTime in Seconds
	UPROPERTY(EditAnywhere, Category = Firing)
		float ReloadTime = 3;

	double LastFireTime = 0;
	
};
