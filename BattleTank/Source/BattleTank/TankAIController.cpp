// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* Owner = GetPlayerTank();
	if (!Owner) { return; }
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIOwner find a %s"), *Owner->GetName());
	}
}

ATank* ATankAIController::GetControlledAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


