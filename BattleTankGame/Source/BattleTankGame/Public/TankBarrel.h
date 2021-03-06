// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	
private:
	// Geschwindigkeit des Rohres
	UPROPERTY(EditDefaultsOnly, category = Attribute)
		float MaxDegreesPerSecond = 10.f;
	// Max hoehe in degrees, die sich das Rohr heben kann
	UPROPERTY(EditDefaultsOnly, category = Attribute)
		float MaxElevationDegrees = 40.f;
	// Min hoehe in degrees, die sich das Rohr heben kann
	UPROPERTY(EditDefaultsOnly, category = Attribute)
		float MinElevationDegrees = 0.f;
};
