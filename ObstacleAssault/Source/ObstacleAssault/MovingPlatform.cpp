// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	startPosition = GetActorLocation();

	FString objectName = GetName();
	UE_LOG(LogTemp, Display, TEXT("Confirmed Move Distance = %f\nConfirmed Name = %s"), moveDistance, *objectName);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		startPosition += platformVelocity.GetSafeNormal() * moveDistance;
		SetActorLocation(startPosition);
		platformVelocity *= -1;
	}
	else
	{
		FVector currentPosition = GetActorLocation();
		currentPosition += platformVelocity * DeltaTime;
		SetActorLocation(currentPosition);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator currentRotation = GetActorRotation();
	AddActorLocalRotation(platformRotateVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return FVector::Distance(GetActorLocation(), startPosition) > moveDistance;
}