// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank2PlayerController.h"

ATank* ATank2PlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


