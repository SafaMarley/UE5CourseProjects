// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Components/SceneComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*
	FRotator Rotation = GetComponentRotation();
	UE_LOG(LogTemp, Display, TEXT("Component rotation: %s"), *Rotation.ToCompactString());

	UWorld* MyWorld = GetWorld();
	float TimeElapsed = MyWorld->TimeSeconds;
	UE_LOG(LogTemp, Display, TEXT("Time: %f"), TimeElapsed);
	*/

	
}

void UGrabber::Grab()
{
	FVector Start = GetOwner()->GetActorLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult, 
		Start, End, 
		FQuat::Identity, 
		ECC_GameTraceChannel2, 
		Sphere
	);

	if (HasHit)
	{
		UE_LOG(LogTemp, Display, TEXT("Hit on object: %s"), *HitResult.GetActor()->GetActorNameOrLabel());
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("No hit on any object"));
	}
}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Display, TEXT("Release Toggle"));
}