// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTankGame.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank *PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank *ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// Auf den Spieler Zielen
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
	
	
}