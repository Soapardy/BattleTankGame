// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("AIController is not possessing a Tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing %s !"), *(GetControlledTank()->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}