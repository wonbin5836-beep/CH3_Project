#include "RotatingPlatform.h"

ARotatingPlatform::ARotatingPlatform()
{
	PrimaryActorTick.bCanEverTick = false;	
	RotationSpeed = 360.0f;
}

void ARotatingPlatform::BeginPlay()
{
	
	Super::BeginPlay();
	
}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
