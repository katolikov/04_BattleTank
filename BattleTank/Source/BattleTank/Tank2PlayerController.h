// Copyright Games by Mark0f

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank2PlayerController.generated.h" // Must be the last include

class ATank;
class UTankAimingComponent;


// Responsible for helping player aim
UCLASS()
class BATTLETANK_API ATank2PlayerController : public APlayerController
{
	GENERATED_BODY()
	

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);


private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// aim towards Crosshair and define where shot would interact with world
	void AimTowardsCrosshair();

	// define location of shot using crosshair and rayCast (return true, if it hits landscape)
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	// Find something that we hit via linetrace
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
