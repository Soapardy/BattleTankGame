// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LunchSpeed)
{
	if (!Barrel) { UE_LOG(LogTemp, Error, TEXT("Kein Barrel")); return; }
	
		FVector OUT LunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("LunchSocket"));
		bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity(this, LunchVelocity, StartLocation, HitLocation, LunchSpeed, false, 0.f, 0.f, ESuggestProjVelocityTraceOption::DoNotTrace));
		
		if (bHaveAimSolution)
		{
			auto AimDirection = LunchVelocity.GetSafeNormal();

			MoveBarrel(AimDirection);
		}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5);
}