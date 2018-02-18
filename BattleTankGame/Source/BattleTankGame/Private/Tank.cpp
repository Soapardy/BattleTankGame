// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTankGame.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Tank.h"


void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	AimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
	
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	AimingComponent->SetTurretReference(TurretToSet);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName ("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	AimingComponent->AimAt(HitLocation, LunchSpeed);
}

void ATank::Fire()
{
	// Check if it is reloaded
	bool bIsReloaded = ((FPlatformTime::Seconds() - LastFireTime) > ReloadTime);


	if (Barrel && bIsReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("LunchSocket")), Barrel->GetSocketRotation(FName("LunchSocket")));
		
		Projectile->LunchProjectile(LunchSpeed);

		// Start reload
		LastFireTime = FPlatformTime::Seconds();
	}
}