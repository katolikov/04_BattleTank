// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* Owner = GetControlledAITank();
	if (!Owner) { return; }
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIOwner is %s"), *Owner->GetName());
	}
}

ATank* ATankAIController::GetControlledAITank() const
{
	return Cast<ATank>(GetPawn());
}



