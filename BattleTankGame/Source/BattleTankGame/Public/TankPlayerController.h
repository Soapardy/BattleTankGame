// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
		

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.3333f;

	ATank * GetControlledTank() const;
	
	// Richtet den Tank und das Rohr so aus, dass es die Welt dort trifft, wo das Crosshair hinzielt
	// CWS = CrossHairWorldSpace
	void AimToCWS();

	// Gibt die Hitlocation und ob etwas getroffenw erden kann wieder
	bool GetCWSHitLocation(FVector& OUT HitLocation) const;

	// Uebertraegt die Location und Direction des Crosshairs
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OUT LookDirection) const;

	// LineTrace Out in LookDirection
	bool GetLookHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
