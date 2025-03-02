// Copyright Games by Mark0f.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TankTrack.generated.h"


// Component of our Tracks with properties
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

	UTankTrack();

	void ApplySidewaysForce();

	void DriveTrack();

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	float CurrentThrottle = 0;
	
public:
	// Set throttle between -1 and 1
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);

	// Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float TrackMaxDrivingForce = 40000000; // Assume 4000 tonne tank , and 1g acceleration
};
