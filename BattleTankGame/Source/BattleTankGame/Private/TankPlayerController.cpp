// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	// Self BeginPlay
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController is not possessing a Tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s !"), *(GetControlledTank()->GetName()));
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
	GetCWSHitLocation(HitLocation);
}

bool ATankPlayerController::GetCWSHitLocation(FVector& OUT HitLocation) const
{
	// Finde die CrosshairPosition in Pixel Coordinates
	int32 ScreenSizeX, ScreenSizeY;
	GetViewportSize(ScreenSizeX, ScreenSizeY);
	auto ScreenLocation = FVector2D{ ScreenSizeX * CrossHairXLocation, ScreenSizeY * CrossHairYLocation };

	return true;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

