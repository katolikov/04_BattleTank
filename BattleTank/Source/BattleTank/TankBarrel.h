// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

// Component of our Barrel with properties
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20; // Sensible value

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesElevation = 40; // Sensible value

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegreesElevation = 0; // Sensible value
};
