// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
		
private:

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333f;

	ATank * GetControlledTank() const;
	
	// Richtet den Tank und das Rohr so aus, dass es die Welt dort trifft, wo das Crosshair hinzielt
	// CWS = CrossHairWorldSpace
	void AimToCWS();

	bool GetCWSHitLocation(FVector& OUT HitLocation) const;

};
