// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void Turn(float RelativeSpeed);

private:
	// Geschwindigkeit des Turrets
	UPROPERTY(EditDefaultsOnly, category = Attribute)
	float MaxDegreesPerSecond = 15.f;

	
	
};