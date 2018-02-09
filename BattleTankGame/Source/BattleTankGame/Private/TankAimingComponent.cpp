// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}



void UTankAimingComponent::AimAt(FVector HitLocation, float LunchSpeed)
{
	if (!Barrel) { UE_LOG(LogTemp, Warning, TEXT("Kein Barrel")); return; }
	
		FVector OUT LunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("LunchSocket"));
		bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity(this, LunchVelocity, StartLocation, HitLocation, LunchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace));
		
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
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
	UE_LOG(LogTemp, Warning, TEXT("TAC : %s"), *Barrel->GetName())
}
