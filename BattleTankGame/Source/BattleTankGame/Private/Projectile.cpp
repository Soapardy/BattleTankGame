// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Component"));
	MovementComponent->bAutoActivate = false;

}

void AProjectile::LunchProjectile(float LunchSpeed)
{
	MovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * LunchSpeed);
	MovementComponent->Activate();
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

