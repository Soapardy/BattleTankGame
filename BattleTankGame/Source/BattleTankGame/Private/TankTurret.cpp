// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGame.h"
#include "TankTurret.h"


void UTankTurret::Turn(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto TurnChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	auto Turn = RelativeRotation.Yaw + TurnChange;

	SetRelativeRotation(FRotator(0, Turn, 0));

}

