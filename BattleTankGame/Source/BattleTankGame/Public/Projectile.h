// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANKGAME_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	void LunchProjectile(float LunchSpeed);

protected:
	virtual void BeginPlay() override;

private:
	// MovementComponent 
	UProjectileMovementComponent *MovementComponent = nullptr;




	
	
};
