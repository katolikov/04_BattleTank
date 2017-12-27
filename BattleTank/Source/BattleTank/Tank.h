// Copyright Games by Mark0f

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "Tank.generated.h" // must be the last


// Forward Declarations
class UTankAimingComponent;
class UTankBarrel; 
class UTankTurret;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* TankAimingComponent = nullptr;

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBP;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds =3.f;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO Remove

	double LastFireTime = 0;
};
