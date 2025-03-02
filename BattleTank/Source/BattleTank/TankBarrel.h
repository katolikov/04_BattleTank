// Copyright Games by Mark0f.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "UnrealMathUtility.h"
#include "TankBarrel.generated.h"


// Component of our Barrel with properties
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)) //, hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, and +1 is max up movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSecond = 10; // Sensible value

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesElevation = 40; // Sensible value

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MinDegreesElevation = 0; // Sensible value
};
