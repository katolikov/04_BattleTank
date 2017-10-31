// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void  UTankTurret::Rotate(float RelativeSpeed)
{
	auto LimitSpeed = FMath::Clamp<float>(RelativeSpeed, -2.0, 2.0);
	auto RotationChange = LimitSpeed * MaxDegreesRotationPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(RawNewRotation), 0, 0);
}


