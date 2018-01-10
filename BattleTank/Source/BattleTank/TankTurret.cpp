// Copyright Games by Mark0f.

#include "TankTurret.h"


void  UTankTurret::Rotate(float RelativeSpeed)
{
	auto LimitSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0, 1.0);
	auto RotationChange = LimitSpeed * MaxDegreesRotationPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}


