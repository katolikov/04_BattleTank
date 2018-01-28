// Copyright Games by Mark0f.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


void UTankAimingComponent::BeginPlay()
{
	// So that first fire is after initial reload
	LastFireTime = FPlatformTime::Seconds();
}


void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
	{
		FireStatus = EFiringStatus::Reloading;
	}
	else if (IsBarrelMove())
	{
		FireStatus = EFiringStatus::Aiming;
	}
	else
	{
		FireStatus = EFiringStatus::Locked;
	}
}


void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}


void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	if (!ensure (Barrel && Turret)) { return; }
	// Difference between current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = (AimAsRotator - BarrelRotator);

	Barrel->Elevate(DeltaRotator.Pitch);

	// Always yaw the shortest way
	if (DeltaRotator.Yaw < 180)
	{
		Turret->Rotate(DeltaRotator.Yaw);
	}
	else
	{
		Turret->Rotate(-DeltaRotator.Yaw);
	}
}


bool UTankAimingComponent::IsBarrelMove()
{
	if (!ensure(Barrel)) { return false; }

	auto BarrelForwardVector = Barrel->GetForwardVector();
	return !BarrelForwardVector.Equals(AimDirection, 0.01); // comparison of vectors
}


void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure (Barrel))
	{
		return;
	}

	OUT FVector LaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate OUT LaunchVelocity (out param)
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, LaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace); // last parameter must be present to prevent bug
	if (bHaveAimSolution)
	{
		AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
	// else do nothing
}


void UTankAimingComponent::Fire()
{
	if (FireStatus != EFiringStatus::Reloading)
	{
		if (!ensure(Barrel)) { return; }
		if (!ensure(ProjectileBP)) { return; }

		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBP, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));

		// Launch our projectile
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}


EFiringStatus UTankAimingComponent::GetFiringStatus() const
{
	return FireStatus;
}




