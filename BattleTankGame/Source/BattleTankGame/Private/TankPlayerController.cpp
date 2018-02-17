// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTankGame.h"
#include "Tank.h"
#include "TankPlayerController.h"

	/*# GeterFunktionen #
	  ###################*/

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


	/*# BeginPlay #
	  #############*/

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// Self BeginPlay
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController is not possessing a Tank!"));
	}
	AimToCWS();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimToCWS();
}

void ATankPlayerController::AimToCWS()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetCWSHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetCWSHitLocation(FVector& OUT HitLocation) const
{
	// Finde die CrosshairPosition in Pixel Coordinates
	int32 ScreenSizeX, ScreenSizeY;
	GetViewportSize(ScreenSizeX, ScreenSizeY);
	auto ScreenLocation = FVector2D{ ScreenSizeX * CrossHairXLocation, ScreenSizeY * CrossHairYLocation };

	// Uebertraegt die ScreenPosition des Crosshairs in WorldDirection
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{	// LineTrace in LookDirection und LineTraceRange, wenn was getroffen wird HitLocaton zurueck gegeben
		GetLookHitLocation(LookDirection, HitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OUT LookDirection) const
{
	FVector CameraWorldLocation; // Kann hierfuer verworfen werden (muss aber in die Funktion)
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookHitLocation(FVector LookDirection, FVector& OUT HitLocation) const
{	//Variablen fuer den LineTrace
	FHitResult HitResult;
	FVector LineTraceStart = PlayerCameraManager->GetCameraLocation();
	FVector LineTraceEnd = LineTraceStart + (LookDirection * LineTraceRange);
	
	if (GetWorld()->LineTraceSingleByChannel(HitResult, LineTraceStart, LineTraceEnd, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

