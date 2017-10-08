// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank2PlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATank2PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// aim towards Crosshair and define where shot would interact with world
	void AimTowardsCrosshair();
	
	
};
