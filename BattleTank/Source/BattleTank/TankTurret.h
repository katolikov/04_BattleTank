// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "UnrealMathUtility.h"
#include "TankTurret.generated.h"

// Component of our Turret with properties
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)) //, hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, and +1 is max up movement
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesRotationPerSecond = 25;
};
