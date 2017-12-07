// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"


void  ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!(Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn())))
	{
		UE_LOG(LogTemp, Warning, TEXT("No aim"));
	}
	else
	{
		// TODO move towards to the player
		MoveToActor(Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()), AcceptanceRadius);

		// Aim towards the player
		ATank* Owner = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (!(Cast<ATank>(GetPawn())))
		{
			UE_LOG(LogTemp, Warning, TEXT("No AI tank"));
		}
		else
		{
			(Cast<ATank>(GetPawn()))->AimAt(Owner->GetActorLocation());
		}

		(Cast<ATank>(GetPawn()))->Fire(); // Don't fire every frame
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

