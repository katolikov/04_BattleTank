// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank2PlayerController.h"

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
		UE_LOG(LogTemp, Warning, TEXT("Owner is %s"), *Owner->GetName());
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

	// GetWorldLocation Through the linetrace
	   // if it hits something
	      // turn barrel to it
}

