// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController is not possessing a Tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s !"), *(GetControlledTank()->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

