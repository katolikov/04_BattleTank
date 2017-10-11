// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank2PlayerController.h"
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
	ATank* Owner = GetControlledTank();
	if (!Owner) { return; }
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Owner is %s"), *Owner->GetName());
	}
}

ATank* ATank2PlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATank2PlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	OUT FVector HitLocation; // out param
	if (GetSightRayHitLocation(OUT HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation is %s"), *HitLocation.ToString());

		// GetWorldLocation Through the linetrace
		// TODO turn barrel to it
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
	if (GetLookDirection(ScreenLocation,OUT LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Crosshair in %s"), *LookDirection.ToString());
	}

	// Line Trace along LookDirection

	return true;
}

bool ATank2PlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; // to be discarded

	return  DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);

}
