// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	// Self BeginPlay
	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Error, TEXT("AIController cant find a PlayerTank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController find %s !"), *(GetPlayerTank()->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>((GetWorld()->GetFirstPlayerController()->GetPawn()));
}