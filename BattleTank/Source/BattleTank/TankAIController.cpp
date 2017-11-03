// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"


void  ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No aim"));
	}
	else
	{
		// TODO move towards to the player


		// Aim towards the player
		ATank* Owner = GetPlayerTank();
		if (!GetControlledAITank())
		{
			UE_LOG(LogTemp, Warning, TEXT("No AI tank"));
		}
		else
		{
			GetControlledAITank()->AimAt(Owner->GetActorLocation());
		}

		// Fire if ready

	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* Owner = GetPlayerTank();
	if (!Owner) { return; }
}

ATank* ATankAIController::GetControlledAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


