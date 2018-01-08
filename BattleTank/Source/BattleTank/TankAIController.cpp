// Copyright Games by Mark0f

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"
// Depends on movement component via pathfinding logic


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void  ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto Owner = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();
	if (!ensure(Owner && AITank)) { return; }

	// Move towards to the player
	MoveToActor(Owner, AcceptanceRadius); // TODO check AcceptanceRadius in cm

	// Aim towards the player
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	AimingComponent->AimAt(Owner->GetActorLocation());

	// TODO fix firing
	// GetPawn()->Fire(); // Don't fire every frame
}


