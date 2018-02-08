// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LunchSpeed)
{
	if (!Barrel){return;}
	
		FVector OUT LunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("LunchSocket"));
	
		if (UGameplayStatics::SuggestProjectileVelocity // Errechnet LunchVelocity und gibt ein Bool zurueck
		(
			this, LunchVelocity, StartLocation, HitLocation, LunchSpeed, false, 20.f)
		)
		{
			UE_LOG(LogTemp, Warning, TEXT("Velocity : "),*LunchVelocity.SafeNormal().ToString())
		}
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}
