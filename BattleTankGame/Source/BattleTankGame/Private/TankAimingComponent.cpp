// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LunchSpeed)
{
	if (!Barrel || !Turret) {return; } // Ohne diese Abfrage crasht das Game (Keine Referenzen)
	
		FVector OUT LunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("LunchSocket"));
		bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity(this, LunchVelocity, StartLocation, HitLocation, LunchSpeed, false, 0.f, 0.f, ESuggestProjVelocityTraceOption::DoNotTrace));
		
		if (bHaveAimSolution)
		{
			auto AimDirection = LunchVelocity.GetSafeNormal();

			MoveBarrel(AimDirection);
			TurnTurret(AimDirection);
		}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::TurnTurret(FVector AimDirection)
{
	FRotator TurretRotator = Turret->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - TurretRotator;

	if (FMath::Abs(DeltaRotator.Yaw) > 180.F)
	{
		DeltaRotator.Yaw *= -1.F;
	}
	
	Turret->Turn(DeltaRotator.Yaw);
}