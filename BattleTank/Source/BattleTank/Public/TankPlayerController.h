// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	// return an out parameter, true if hit landscape
	bool GetSightRayLocation(FVector& HitLocation) const;
	
	UPROPERTY(EditAnywhere)
	float CrosshairXPosition = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYPosition = 0.3333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
};
