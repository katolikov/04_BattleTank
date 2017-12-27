// Copyright Games by Mark0f

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"


// new-style enum class for aiming states
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};


// Forward Declaration
class UTankBarrel;
class UTankTurret;


// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void AimAt(FVector HitLocation, float LaunchSpeed);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringStatus FireStatus = EFiringStatus::Locked;

	
private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	void MoveBarrel(FVector AimDirection);
};
