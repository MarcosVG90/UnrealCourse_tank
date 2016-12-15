// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle) 
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("  %f  " ), Time);
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	// we go up the class hierarchy for the component(the primitive)
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	// we apply the force
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}