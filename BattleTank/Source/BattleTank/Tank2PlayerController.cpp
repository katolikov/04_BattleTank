// Copyright Games by Mark0f.

#include "Tank2PlayerController.h"
#include "TankAimingComponent.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Engine/World.h"

#define OUT


void ATank2PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


void ATank2PlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}


void ATank2PlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; } // e.g. if not possessing

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	OUT FVector HitLocation; // out param
	if (GetSightRayHitLocation(OUT HitLocation))
	{
		AimingComponent->AimAt(HitLocation);
	}
}


// GetWorldLocation Through the linetrace, true if hits linetrace
bool ATank2PlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(CrossHairXLocation * ViewportSizeX, CrossHairYLocation * ViewportSizeY);
	
	// "De-project" the screen position of the crosshair to a world direction
	OUT FVector LookDirection; // out param
	if (GetLookDirection(ScreenLocation, OUT LookDirection))
	{
		// Line Trace along LookDirection
		GetLookVectorHitLocation(LookDirection, OUT HitLocation);
	}
	
	return true;
}


bool ATank2PlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; // to be discarded

	return  DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}


bool ATank2PlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult Hit;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel( Hit, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = Hit.Location;

		return true;
	}

	HitLocation = FVector(0);

	return false;
}
